//
//  Copyright (C) 2019 SCOD Organization <https://scod-lang.org>
//  All rights reserved.
//
//  Developed by: Philipp Paulweber
//                Emmanuel Pescosta
//                <https://github.com/scod-lang/libscod>
//
//  This file is part of libscod.
//
//  libscod is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  libscod is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with libscod. If not, see <http://www.gnu.org/licenses/>.
//
//  Additional permission under GNU GPL version 3 section 7
//
//  libscod is distributed under the terms of the GNU General Public License
//  with the following clarification and special exception: Linking libscod
//  statically or dynamically with other modules is making a combined work
//  based on libscod. Thus, the terms and conditions of the GNU General
//  Public License cover the whole combination. As a special exception,
//  the copyright holders of libscod give you permission to link libscod
//  with independent modules to produce an executable, regardless of the
//  license terms of these independent modules, and to copy and distribute
//  the resulting executable under terms of your choice, provided that you
//  also meet, for each linked independent module, the terms and conditions
//  of the license of that module. An independent module is a module which
//  is not derived from or based on libscod. If you modify libscod, you
//  may extend this exception to your version of the library, but you are
//  not obliged to do so. If you do not wish to do so, delete this exception
//  statement from your version.
//

#include "CstToAstPass.h"

#include "../various/GrammarToken.h"

#include <libscod/Logger>
#include <libscod/Namespace>
#include <libscod/Specification>

#include <libscod/ast/Expression>
#include <libscod/ast/Literal>

#include <libscod/cst/Literal>
#include <libscod/cst/Visitor>

//#include <libscod/analyze/AttributionPass>
#include <libscod/transform/SourceToCstPass>

#include <libpass/PassRegistry>
#include <libpass/PassResult>
#include <libpass/PassUsage>

#include <libstdhl/File>

#include <fstream>
#include <iostream>
#include <stack>

using namespace libscod;
using namespace CST;

char CstToAstPass::id = 0;

static libpass::PassRegistration< CstToAstPass > PASS(
    "CST To AST Pass", "transforms CST to AST representation", "cst2ast", 0 );

//
//
// CstToAstVisitor
//

namespace libscod
{
    namespace CST
    {
        class CstToAstVisitor final : public Visitor
        {
          public:
            CstToAstVisitor( libscod::Logger& log );

            AST::Root::Ptr transform( const Root::Ptr& node );

            void visit( Root& node ) override;

            void visit( HeaderDefinition& node ) override;
            void visit( MemoryDefinition& node ) override;
            void visit( RegisterDefinition& node ) override;
            void visit( FieldDefinition& node ) override;
            void visit( FormatDefinition& node ) override;
            void visit( BufferDefinition& node ) override;
            void visit( InstructionDefinition& node ) override;
            void visit( MicroProcessorDefinition& node ) override;
            void visit( CacheDefinition& node ) override;
            void visit( InterconnectDefinition& node ) override;
            void visit( OptionDefinition& node ) override;
            void visit( EnumerationDefinition& node ) override;
            void visit( UsingDefinition& node ) override;
            void visit( VariableDefinition& node ) override;

            void visit( UnresolvedOption& node ) override;
            void visit( DecodingOption& node ) override;
            void visit( SyntaxOption& node ) override;
            void visit( ExpansionOption& node ) override;
            void visit( StageOption& node ) override;

            void visit( SkipStatement& node ) override;
            void visit( BlockStatement& node ) override;
            void visit( CallStatement& node ) override;
            void visit( LetStatement& node ) override;
            void visit( AssignmentStatement& node ) override;
            void visit( ConditionalStatement& node ) override;

            void visit( EmbracedExpression& node ) override;
            void visit( NamedExpression& node ) override;
            void visit( MappedExpression& node ) override;
            void visit( LetExpression& node ) override;
            void visit( ConditionalExpression& node ) override;
            void visit( DirectCallExpression& node ) override;
            void visit( MethodCallExpression& node ) override;
            void visit( UnaryExpression& node ) override;
            void visit( BinaryExpression& node ) override;

            void visit( ValueLiteral& node ) override;
            void visit( SetLiteral& node ) override;
            void visit( ListLiteral& node ) override;
            void visit( RangeLiteral& node ) override;
            void visit( RecordLiteral& node ) override;
            void visit( MappingLiteral& node ) override;
            void visit( ReferenceLiteral& node ) override;
            void visit( GrammarLiteral& node ) override;

            void visit( UnresolvedType& node ) override;
            void visit( BasicType& node ) override;
            void visit( PropertyType& node ) override;
            void visit( MappingType& node ) override;

            void visit( BasicAttribute& node ) override;
            void visit( ExpressionAttribute& node ) override;

            void visit( VariableBinding& node ) override;
            void visit( Identifier& node ) override;
            void visit( IdentifierPath& node ) override;
            void visit( Token& node ) override;
            void visit( Span& node ) override;

          private:
            template < typename T >
            typename T::Ptr fetch( const CST::Node::Ptr& node )
            {
                node->accept( *this );

                const auto search = m_ast.find( node.get() );
                if( search == m_ast.end() )
                {
                    const auto& msg = " unimplemented '" + node->description() + "'";
                    m_log.error( { node->sourceLocation() }, msg );  //, Code::Internal );
                    return nullptr;
                }

                auto result = search->second;  // save element
                m_ast.erase( search );         // erase from buffer
                if( result )
                {
                    return result->ptr< T >();  // typed return
                }
                return nullptr;
            }

            template < typename T, typename A, typename C >
            typename T::Ptr fetch( const typename CST::NodeList< C >::Ptr& node )
            {
                const auto& list = AST::make< T >( node->sourceLocation() );
                for( const auto& nodeElement : *node )
                {
                    const auto& element = fetch< A >( nodeElement );
                    if( element )
                    {
                        list->add( element );
                    }
                }

                return list;
            }

            template < typename T, typename... Args >
            typename T::Ptr store( CST::Node& node, Args&&... args )
            {
                const auto& result =
                    AST::make< T >( node.sourceLocation(), std::forward< Args >( args )... );
                set( node, result );
                return result;
            }

            void set( CST::Node& node, const AST::Node::Ptr& result )
            {
                const auto check = m_ast.emplace( &node, result );
                if( not check.second )
                {
                    const auto& msg = " already transformed '" + node.description() + "'";
                    m_log.error( { node.sourceLocation() }, msg );  //, Code::Internal );
                }
            }

          private:
            libscod::Logger& m_log;
            AST::Definitions::Ptr m_definitions;

            std::unordered_map< CST::Node*, AST::Node::Ptr > m_ast;
        };
    }
}

CstToAstVisitor::CstToAstVisitor( libscod::Logger& log )
: m_log( log )
, m_definitions()
{
}

AST::Root::Ptr CstToAstVisitor::transform( const Root::Ptr& node )
{
    node->accept( *this );
    return AST::make< AST::Root >( node->header()->sourceLocation(), m_definitions );
}

void CstToAstVisitor::visit( Root& node )
{
    const auto& definitions =
        fetch< AST::Definitions, AST::Definition, CST::Definition >( node.definitions() );
    m_definitions = definitions;
}

void CstToAstVisitor::visit( HeaderDefinition& node )
{
    assert( not " inconsistent state, invalid node to transform " );
}

void CstToAstVisitor::visit( MemoryDefinition& node )
{
    const auto& identifier = fetch< AST::Identifier >( node.identifier() );
    const auto& type = fetch< AST::Type >( node.mappingType() );
    store< AST::MemoryDefinition >( node, identifier, type );
}

void CstToAstVisitor::visit( RegisterDefinition& node )
{
    const auto& identifier = fetch< AST::Identifier >( node.identifier() );
    const auto& type = fetch< AST::Type >( node.mappingType() );
    store< AST::RegisterDefinition >( node, identifier, type );
}

void CstToAstVisitor::visit( FieldDefinition& node )
{
    const auto& identifier = fetch< AST::Identifier >( node.identifier() );
    const auto& type = fetch< AST::Type >( node.mappingType() );
    store< AST::FieldDefinition >( node, identifier, type );
}

void CstToAstVisitor::visit( FormatDefinition& node )
{
    const auto& identifier = fetch< AST::Identifier >( node.identifier() );
    const auto& type = fetch< AST::Type >( node.mappingType() );
    const auto& mapping = fetch< AST::MappingLiteral >( node.mapping() );
    store< AST::FormatDefinition >( node, identifier, type, mapping );
}

void CstToAstVisitor::visit( BufferDefinition& node )
{
    const auto& identifier = fetch< AST::Identifier >( node.identifier() );
    const auto& type = fetch< AST::Type >( node.mappingType() );
    const auto& expression = fetch< AST::Expression >( node.expression() );
    store< AST::BufferDefinition >( node, identifier, type, expression );
}

void CstToAstVisitor::visit( InstructionDefinition& node )
{
    const auto& identifier = fetch< AST::Identifier >( node.identifier() );
    const auto& type = fetch< AST::Type >( node.mappingType() );
    const auto& statement = fetch< AST::Statement >( node.statement() );
    const auto& options = fetch< AST::Options, AST::Option, CST::Option >( node.options() );
    store< AST::InstructionDefinition >( node, identifier, type, statement, options );
}

void CstToAstVisitor::visit( MicroProcessorDefinition& node )
{
    const auto& identifier = fetch< AST::Identifier >( node.identifier() );
    const auto& programCounter = fetch< AST::IdentifierPath >( node.programCounter() );
    const auto& statement = fetch< AST::Statement >( node.statement() );
    const auto& options = fetch< AST::Options, AST::Option, CST::Option >( node.options() );
    store< AST::MicroProcessorDefinition >( node, identifier, programCounter, statement, options );
}

void CstToAstVisitor::visit( CacheDefinition& node )
{
    const auto& identifier = fetch< AST::Identifier >( node.identifier() );
    const auto& type = fetch< AST::Type >( node.mappingType() );
    const auto& connection = fetch< AST::MappingLiteral >( node.connection() );
    store< AST::CacheDefinition >( node, identifier, type, connection );
}

void CstToAstVisitor::visit( InterconnectDefinition& node )
{
    const auto& identifier = fetch< AST::Identifier >( node.identifier() );
    const auto& type = fetch< AST::Type >( node.mappingType() );
    const auto& connection = fetch< AST::MappingLiteral >( node.connection() );
    store< AST::InterconnectDefinition >( node, identifier, type, connection );
}

void CstToAstVisitor::visit( OptionDefinition& node )
{
    const auto& reference = fetch< AST::ReferenceLiteral >( node.reference() );
    const auto& option = fetch< AST::Option >( node.option() );
    store< AST::OptionDefinition >( node, reference, option, node.kind() );
}

void CstToAstVisitor::visit( EnumerationDefinition& node )
{
    const auto& identifier = fetch< AST::Identifier >( node.identifier() );
    const auto& enumerators = fetch< AST::SetLiteral >( node.enumerators() );
    store< AST::EnumerationDefinition >( node, identifier, enumerators );
}

void CstToAstVisitor::visit( UsingDefinition& node )
{
    const auto& identifier = fetch< AST::Identifier >( node.identifier() );
    const auto& alias = fetch< AST::Type >( node.alias() );
    store< AST::UsingDefinition >( node, identifier, alias );
}

void CstToAstVisitor::visit( VariableDefinition& node )
{
    const auto& identifier = fetch< AST::Identifier >( node.identifier() );
    const auto& type = fetch< AST::Type >( node.variableType() );
    store< AST::VariableDefinition >( node, identifier, type );
}

void CstToAstVisitor::visit( UnresolvedOption& node )
{
    store< AST::UnresolvedOption >( node );
}

void CstToAstVisitor::visit( DecodingOption& node )
{
    const auto& value = fetch< AST::RecordLiteral >( node.value() );
    store< AST::DecodingOption >( node, value );
}

void CstToAstVisitor::visit( SyntaxOption& node )
{
    const auto& value = fetch< AST::SetLiteral >( node.value() );
    store< AST::SyntaxOption >( node, value );
}

void CstToAstVisitor::visit( ExpansionOption& node )
{
    const auto& value = fetch< AST::SetLiteral >( node.value() );
    store< AST::ExpansionOption >( node, value );
}

void CstToAstVisitor::visit( StageOption& node )
{
    const auto& identifier = fetch< AST::Identifier >( node.identifier() );
    const auto& statement = fetch< AST::BlockStatement >( node.statement() );
    store< AST::StageOption >( node, identifier, statement );
}

void CstToAstVisitor::visit( SkipStatement& node )
{
    store< AST::SkipStatement >( node );
}

void CstToAstVisitor::visit( BlockStatement& node )
{
    const auto& statements =
        fetch< AST::Statements, AST::Statement, CST::Statement >( node.statements() );
    store< AST::BlockStatement >( node, statements );
}

void CstToAstVisitor::visit( CallStatement& node )
{
    const auto& target = fetch< AST::CallExpression >( node.target() );
    store< AST::CallStatement >( node, target );
}

void CstToAstVisitor::visit( LetStatement& node )
{
    const auto& statement = fetch< AST::Statement >( node.statement() );
    AST::Statement::Ptr letStatement = statement;

    const auto& cstVariableBindings = node.variableBindings();
    for( auto i = cstVariableBindings->rbegin(); i != cstVariableBindings->rend(); ++i )
    {
        const auto& cstVariableBinding = *i;
        const auto& variableBinding = fetch< AST::VariableBinding >( cstVariableBinding );

        letStatement =
            AST::make< AST::LetStatement >( node.sourceLocation(), variableBinding, letStatement );
    }

    set( node, letStatement );
}

void CstToAstVisitor::visit( AssignmentStatement& node )
{
    const auto& target = fetch< AST::DirectCallExpression >( node.target() );
    const auto& expression = fetch< AST::Expression >( node.expression() );
    store< AST::AssignmentStatement >( node, target, expression );
}

void CstToAstVisitor::visit( ConditionalStatement& node )
{
    const auto& condition = fetch< AST::Expression >( node.condition() );
    const auto& thenStatement = fetch< AST::Statement >( node.thenStatement() );
    const auto& elseStatement = fetch< AST::Statement >( node.elseStatement() );
    store< AST::ConditionalStatement >( node, condition, thenStatement, elseStatement );
    if( node.elseToken()->token() == Grammar::Token::UNRESOLVED )
    {
        assert( elseStatement->id() == AST::Node::ID::SKIP_STATEMENT );
    }
}

void CstToAstVisitor::visit( EmbracedExpression& node )
{
    const auto& expression = fetch< AST::Expression >( node.expression() );
    set( node, expression );
}

void CstToAstVisitor::visit( NamedExpression& node )
{
    const auto& identifier = fetch< AST::Identifier >( node.identifier() );
    const auto& expression = fetch< AST::Expression >( node.expression() );
    store< AST::NamedExpression >( node, identifier, expression );
}

void CstToAstVisitor::visit( MappedExpression& node )
{
    const auto& arguments =
        fetch< AST::Expressions, AST::Expression, CST::Expression >( node.arguments() );
    const auto& value = fetch< AST::Expression >( node.value() );
    store< AST::MappedExpression >( node, arguments, value );
}

void CstToAstVisitor::visit( LetExpression& node )
{
    const auto& expression = fetch< AST::Expression >( node.expression() );
    AST::Expression::Ptr letExpression = expression;

    const auto& cstVariableBindings = node.variableBindings();
    for( auto i = cstVariableBindings->rbegin(); i != cstVariableBindings->rend(); ++i )
    {
        const auto& cstVariableBinding = *i;
        const auto& variableBinding = fetch< AST::VariableBinding >( cstVariableBinding );

        letExpression = AST::make< AST::LetExpression >(
            node.sourceLocation(), variableBinding, letExpression );
    }

    set( node, letExpression );
}

void CstToAstVisitor::visit( ConditionalExpression& node )
{
    const auto& condition = fetch< AST::Expression >( node.condition() );
    const auto& thenExpression = fetch< AST::Expression >( node.thenExpression() );
    const auto& elseExpression = fetch< AST::Expression >( node.elseExpression() );
    store< AST::ConditionalExpression >( node, condition, thenExpression, elseExpression );
}

void CstToAstVisitor::visit( DirectCallExpression& node )
{
    const auto& name = fetch< AST::IdentifierPath >( node.name() );
    const auto& arguments =
        fetch< AST::Expressions, AST::Expression, CST::Expression >( node.arguments() );
    store< AST::DirectCallExpression >( node, name, arguments );
}

void CstToAstVisitor::visit( MethodCallExpression& node )
{
    const auto& object = fetch< AST::Expression >( node.object() );
    const auto& method = fetch< AST::Identifier >( node.method() );
    const auto& arguments =
        fetch< AST::Expressions, AST::Expression, CST::Expression >( node.arguments() );
    store< AST::MethodCallExpression >( node, object, method, arguments );
}

void CstToAstVisitor::visit( UnaryExpression& node )
{
    const auto& expression = fetch< AST::Expression >( node.expression() );
    store< AST::UnaryExpression >( node, node.operationToken()->token(), expression );
}

void CstToAstVisitor::visit( BinaryExpression& node )
{
    const auto& leftExpression = fetch< AST::Expression >( node.leftExpression() );
    const auto& rightExpression = fetch< AST::Expression >( node.rightExpression() );
    store< AST::BinaryExpression >(
        node, leftExpression, node.operationToken()->token(), rightExpression );
}

void CstToAstVisitor::visit( ValueLiteral& node )
{
    store< AST::ValueLiteral >( node, node.value(), node.kind() );
}

void CstToAstVisitor::visit( SetLiteral& node )
{
    const auto& expressions =
        fetch< AST::Expressions, AST::Expression, CST::Expression >( node.expressions() );
    store< AST::SetLiteral >( node, expressions );
}

void CstToAstVisitor::visit( ListLiteral& node )
{
    const auto& expressions =
        fetch< AST::Expressions, AST::Expression, CST::Expression >( node.expressions() );
    store< AST::ListLiteral >( node, expressions );
}

void CstToAstVisitor::visit( RangeLiteral& node )
{
    const auto& from = fetch< AST::Expression >( node.from() );
    const auto& to = fetch< AST::Expression >( node.to() );
    store< AST::RangeLiteral >( node, from, to );
}

void CstToAstVisitor::visit( RecordLiteral& node )
{
    const auto& namedExpressions =
        fetch< AST::NamedExpressions, AST::NamedExpression, CST::NamedExpression >(
            node.namedExpressions() );
    store< AST::RecordLiteral >( node, namedExpressions );
}

void CstToAstVisitor::visit( MappingLiteral& node )
{
    const auto& mappedExpressions =
        fetch< AST::MappedExpressions, AST::MappedExpression, CST::MappedExpression >(
            node.mappedExpressions() );
    store< AST::MappingLiteral >( node, mappedExpressions );
}

void CstToAstVisitor::visit( ReferenceLiteral& node )
{
    const auto& target = fetch< AST::IdentifierPath >( node.target() );
    store< AST::ReferenceLiteral >( node, target );
}

void CstToAstVisitor::visit( GrammarLiteral& node )
{
    const auto& expressions =
        fetch< AST::Expressions, AST::Expression, CST::Expression >( node.expressions() );
    store< AST::GrammarLiteral >( node, expressions );
}

void CstToAstVisitor::visit( UnresolvedType& node )
{
    store< AST::UnresolvedType >( node );
}

void CstToAstVisitor::visit( BasicType& node )
{
    const auto& name = fetch< AST::IdentifierPath >( node.name() );
    store< AST::BasicType >( node, name );
}

void CstToAstVisitor::visit( PropertyType& node )
{
    const auto& identifier = fetch< AST::IdentifierPath >( node.name() );
    const auto& size = fetch< AST::ValueLiteral >( node.size() );
    store< AST::PropertyType >( node, identifier, size );
}

void CstToAstVisitor::visit( MappingType& node )
{
    const auto& argumentTypes = fetch< AST::Types, AST::Type, CST::Type >( node.argumentTypes() );
    const auto& returnType = fetch< AST::Type >( node.returnType() );
    store< AST::MappingType >( node, argumentTypes, returnType );
}

void CstToAstVisitor::visit( BasicAttribute& node )
{
    assert( not " inconsistent state, invalid node to transform " );
}

void CstToAstVisitor::visit( ExpressionAttribute& node )
{
    assert( not " inconsistent state, invalid node to transform " );
}

void CstToAstVisitor::visit( VariableBinding& node )
{
    const auto& variable = fetch< AST::VariableDefinition >( node.variable() );
    const auto& expression = fetch< AST::Expression >( node.expression() );
    store< AST::VariableBinding >( node, variable, expression );
}

void CstToAstVisitor::visit( Identifier& node )
{
    store< AST::Identifier >( node, node.name() );
}

void CstToAstVisitor::visit( IdentifierPath& node )
{
    const auto& identifiers =
        fetch< AST::Identifiers, AST::Identifier, CST::Identifier >( node.identifiers() );
    store< AST::IdentifierPath >( node, identifiers );
}

void CstToAstVisitor::visit( Token& node )
{
    assert( not " inconsistent state, invalid node to transform " );
}

void CstToAstVisitor::visit( Span& node )
{
    assert( not " inconsistent state, invalid node to transform " );
}

//
//
// CstToAstPass
//

void CstToAstPass::usage( libpass::PassUsage& pu )
{
    pu.require< SourceToCstPass >();
    //    pu.scheduleAfter< AttributionPass >();
}

u1 CstToAstPass::run( libpass::PassResult& pr )
{
    libscod::Logger log( &id, stream() );

    const auto& data = pr.output< SourceToCstPass >();
    const auto& specification = data->specification();

    CstToAstVisitor visitor{ log };
    const auto& ast = visitor.transform( specification->cst() );

    const auto errors = log.errors();
    if( errors > 0 )
    {
        // log.debug( "symbol table =\n" + specification->symboltable()->dump() );
        log.debug( "found %lu error(s) during transformation", errors );
        return false;
    }

    const auto& transformedSpecification = std::make_shared< Specification >();
    transformedSpecification->setLocation( specification->location() );
    // transformedSpecification->setSymboltable( specification->symboltable() );
    transformedSpecification->setAst( ast );

    pr.setOutput< CstToAstPass >( transformedSpecification );
    return true;
}

//
//  Local variables:
//  mode: c++
//  indent-tabs-mode: nil
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//
