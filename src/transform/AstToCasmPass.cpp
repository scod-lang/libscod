//
//  Copyright (C) 2019-2020 SCOD Organization <https://scod-lang.org>
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

#include "AstToCasmPass.h"

#include "../various/GrammarToken.h"

#include <libscod/Logger>
#include <libscod/ast/Visitor>
#include <libscod/transform/CstToAstPass>

#include <libpass/PassRegistry>
#include <libpass/PassResult>
#include <libpass/PassUsage>

#include <libstdhl/File>

#include <fstream>
#include <iostream>
#include <stack>

using namespace libscod;
using namespace AST;

char AstToCasmPass::id = 0;

static libpass::PassRegistration< AstToCasmPass > PASS(
    "AST To CASM Pass", "transforms AST to CASM specification", "ast2casm", 0 );

namespace libscod
{
    namespace AST
    {
        class AstToCasmVisitor final : public RecursiveVisitor
        {
          public:
            AstToCasmVisitor(
                Logger& log,
                std::ostream& stream,
                const std::string& name,
                const std::string& location );

            void visit( Root& node ) override;

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

            void visit( VariableBinding& node ) override;
            void visit( Identifier& node ) override;
            void visit( IdentifierPath& node ) override;

          private:
            void dumpNode( const Node& node );

          private:
            Logger& m_log;
            std::ostream& m_stream;
            const std::string m_name;
            const std::string m_location;
            std::stack< void* > m_parentNodes; /**< holds the parent nodes of DotLink */
        };
    }
}

AstToCasmVisitor::AstToCasmVisitor(
    Logger& log, std::ostream& stream, const std::string& name, const std::string& location )
: m_log( log )
, m_stream( stream )
, m_name( name )
, m_location( location )
, m_parentNodes()
{
}

void AstToCasmVisitor::visit( Root& node )
{
    m_stream << "// source: " << m_location << "\n";
    m_stream << "\n";
    m_stream << "CASM\n";
    m_stream << "\n";

    RecursiveVisitor::visit( node );
}

void AstToCasmVisitor::visit( MemoryDefinition& node )
{
    m_stream << "function ";
    node.identifier()->accept( *this );
    m_stream << " : ";
    node.mappingType()->accept( *this );
    m_stream << "\n";
    m_stream << "\n";
}

void AstToCasmVisitor::visit( RegisterDefinition& node )
{
    m_stream << "function ";
    node.identifier()->accept( *this );
    m_stream << " : ";
    if( node.mappingType()->id() != Node::ID::MAPPING_TYPE )
    {
        m_stream << "-> ";
    }
    node.mappingType()->accept( *this );
    m_stream << "\n";
    m_stream << "\n";
}

void AstToCasmVisitor::visit( FieldDefinition& node )
{
    m_stream << "/* TODO: " << node.description() << " @ " << node.sourceLocation() << " ";
    RecursiveVisitor::visit( node );
    m_stream << " */\n";
}

void AstToCasmVisitor::visit( FormatDefinition& node )
{
    m_stream << "/* TODO: " << node.description() << " @ " << node.sourceLocation() << " ";
    RecursiveVisitor::visit( node );
    m_stream << " */\n";
}

void AstToCasmVisitor::visit( BufferDefinition& node )
{
    m_stream << "derived ";
    node.identifier()->accept( *this );
    m_stream << " -> Void /* TODO: use correct type signature */";
    m_stream << " = ";
    node.expression()->accept( *this );
    m_stream << "\n";
    m_stream << "\n";
}

void AstToCasmVisitor::visit( InstructionDefinition& node )
{
    m_stream << "rule Instruction_";
    node.identifier()->accept( *this );
    m_stream << " = ";
    node.statement()->accept( *this );
    m_stream << "\n";
    m_stream << "\n";
}

void AstToCasmVisitor::visit( MicroProcessorDefinition& node )
{
    m_stream << "rule Microprocessor_";
    node.identifier()->accept( *this );
    m_stream << " = ";
    node.statement()->accept( *this );
    m_stream << "\n";
    m_stream << "\n";
}

void AstToCasmVisitor::visit( CacheDefinition& node )
{
    m_stream << "/* TODO: " << node.description() << " @ " << node.sourceLocation() << " ";
    RecursiveVisitor::visit( node );
    m_stream << " */\n";
}

void AstToCasmVisitor::visit( InterconnectDefinition& node )
{
    m_stream << "/* TODO: " << node.description() << " @ " << node.sourceLocation() << " ";
    RecursiveVisitor::visit( node );
    m_stream << " */\n";
}

void AstToCasmVisitor::visit( OptionDefinition& node )
{
    m_stream << "/* TODO: " << node.description() << " @ " << node.sourceLocation() << " ";
    RecursiveVisitor::visit( node );
    m_stream << " */\n";
}

void AstToCasmVisitor::visit( EnumerationDefinition& node )
{
    m_stream << "enumeration ";
    node.identifier()->accept( *this );
    m_stream << " = ";
    node.enumerators()->accept( *this );
}

void AstToCasmVisitor::visit( UsingDefinition& node )
{
    dumpNode( node );

    m_stream << "using ";
    node.identifier()->accept( *this );
    m_stream << " = ";
    node.alias()->accept( *this );
    m_stream << "\n";
    m_stream << "\n";
}

void AstToCasmVisitor::visit( VariableDefinition& node )
{
    node.identifier()->accept( *this );
    if( node.variableType()->id() == Node::ID::UNRESOLVED_TYPE )
    {
        return;
    }

    m_stream << " : ";
    node.variableType()->accept( *this );
}

void AstToCasmVisitor::visit( UnresolvedOption& node )
{
    m_stream << "/* TODO: " << node.description() << " @ " << node.sourceLocation() << " ";
    RecursiveVisitor::visit( node );
    m_stream << " */\n";
}

void AstToCasmVisitor::visit( DecodingOption& node )
{
    m_stream << "/* TODO: " << node.description() << " @ " << node.sourceLocation() << " ";
    RecursiveVisitor::visit( node );
    m_stream << " */\n";
}

void AstToCasmVisitor::visit( SyntaxOption& node )
{
    m_stream << "/* TODO: " << node.description() << " @ " << node.sourceLocation() << " ";
    RecursiveVisitor::visit( node );
    m_stream << " */\n";
}

void AstToCasmVisitor::visit( ExpansionOption& node )
{
    m_stream << "/* TODO: " << node.description() << " @ " << node.sourceLocation() << " ";
    RecursiveVisitor::visit( node );
    m_stream << " */\n";
}

void AstToCasmVisitor::visit( StageOption& node )
{
    m_stream << "/* TODO: " << node.description() << " @ " << node.sourceLocation() << " ";
    RecursiveVisitor::visit( node );
    m_stream << " */\n";
}

void AstToCasmVisitor::visit( SkipStatement& node )
{
    m_stream << "skip";
    m_stream << "\n";
}

void AstToCasmVisitor::visit( BlockStatement& node )
{
    m_stream << "{|\n";
    node.statements()->accept( *this );
    m_stream << "|}\n";
}

void AstToCasmVisitor::visit( CallStatement& node )
{
    node.target()->accept( *this );
    m_stream << "\n";
}

void AstToCasmVisitor::visit( LetStatement& node )
{
    m_stream << "let ";
    node.variableBinding()->accept( *this );
    m_stream << " in ";
    node.statement()->accept( *this );
    m_stream << "\n";
}

void AstToCasmVisitor::visit( AssignmentStatement& node )
{
    node.target()->accept( *this );
    m_stream << " := ";
    node.expression()->accept( *this );
    m_stream << "\n";
}

void AstToCasmVisitor::visit( ConditionalStatement& node )
{
    m_stream << "if ";
    node.condition()->accept( *this );
    m_stream << " then\n";
    node.thenStatement()->accept( *this );
    if( node.elseStatement()->id() != Node::ID::SKIP_STATEMENT )
    {
        m_stream << "else\n";
        node.elseStatement()->accept( *this );
    }
    m_stream << "\n";
}

void AstToCasmVisitor::visit( NamedExpression& node )
{
    node.identifier()->accept( *this );
    m_stream << " : ";
    node.expression()->accept( *this );
}

void AstToCasmVisitor::visit( MappedExpression& node )
{
    m_stream << "( ";
    u1 first = true;
    for( const auto& argument : *node.arguments() )
    {
        if( not first )
        {
            m_stream << ", ";
        }
        argument->accept( *this );
        first = false;
    }
    m_stream << " ) -> ";
    node.value()->accept( *this );
}

void AstToCasmVisitor::visit( LetExpression& node )
{
    m_stream << "let ";
    node.variableBinding()->accept( *this );
    m_stream << " in ";
    node.expression()->accept( *this );
}

void AstToCasmVisitor::visit( ConditionalExpression& node )
{
    m_stream << "if ";
    node.condition()->accept( *this );
    m_stream << " then\n";
    node.thenExpression()->accept( *this );
    m_stream << "else\n";
    node.elseExpression()->accept( *this );
    m_stream << "\n";
}

void AstToCasmVisitor::visit( DirectCallExpression& node )
{
    node.name()->accept( *this );

    const auto& arguments = *node.arguments();
    if( arguments.size() == 0 )
    {
        return;
    }

    m_stream << "( ";
    u1 first = true;
    for( const auto& argument : *node.arguments() )
    {
        if( not first )
        {
            m_stream << ", ";
        }
        argument->accept( *this );
        first = false;
    }
    m_stream << " )";
}

void AstToCasmVisitor::visit( MethodCallExpression& node )
{
    node.object()->accept( *this );
    m_stream << ".";
    node.method()->accept( *this );

    const auto& arguments = *node.arguments();
    if( arguments.size() == 0 )
    {
        return;
    }

    m_stream << "( ";
    u1 first = true;
    for( const auto& argument : *node.arguments() )
    {
        if( not first )
        {
            m_stream << ", ";
        }
        argument->accept( *this );
        first = false;
    }
    m_stream << " )";
}

void AstToCasmVisitor::visit( UnaryExpression& node )
{
    m_stream << Grammar::tokenAsString( Grammar::Token::PLUS );
    node.expression()->accept( *this );
}

void AstToCasmVisitor::visit( BinaryExpression& node )
{
    node.leftExpression()->accept( *this );
    m_stream << " ";
    m_stream << Grammar::tokenAsString( Grammar::Token::PLUS );
    m_stream << " ";
    node.rightExpression()->accept( *this );
}

void AstToCasmVisitor::visit( ValueLiteral& node )
{
    m_stream << node.toString();
}

void AstToCasmVisitor::visit( SetLiteral& node )
{
    m_stream << "{ ";
    u1 first = true;
    for( const auto& expression : *node.expressions() )
    {
        if( not first )
        {
            m_stream << ", ";
        }
        expression->accept( *this );
        first = false;
    }
    m_stream << " }";
}

void AstToCasmVisitor::visit( ListLiteral& node )
{
    m_stream << "[ ";
    u1 first = true;
    for( const auto& expression : *node.expressions() )
    {
        if( not first )
        {
            m_stream << ", ";
        }
        expression->accept( *this );
        first = false;
    }
    m_stream << " ]";
}

void AstToCasmVisitor::visit( RangeLiteral& node )
{
    m_stream << "[ ";
    node.from()->accept( *this );
    m_stream << " .. ";
    node.to()->accept( *this );
    m_stream << " ]";
}

void AstToCasmVisitor::visit( RecordLiteral& node )
{
    m_stream << "{ ";
    u1 first = true;
    for( const auto& namedExpression : *node.namedExpressions() )
    {
        if( not first )
        {
            m_stream << ", ";
        }
        namedExpression->accept( *this );
        first = false;
    }
    m_stream << " }";
}

void AstToCasmVisitor::visit( MappingLiteral& node )
{
    m_stream << "{ ";
    u1 first = true;
    for( const auto& mappedExpression : *node.mappedExpressions() )
    {
        if( not first )
        {
            m_stream << ", ";
        }
        mappedExpression->accept( *this );
        first = false;
    }
    m_stream << " }";
}

void AstToCasmVisitor::visit( ReferenceLiteral& node )
{
    m_stream << "@";
    node.target()->accept( *this );
}

void AstToCasmVisitor::visit( GrammarLiteral& node )
{
    // omit
}

void AstToCasmVisitor::visit( UnresolvedType& node )
{
    m_log.error( { node.sourceLocation() }, "invalid for CASM transformation" );
}

void AstToCasmVisitor::visit( BasicType& node )
{
    node.name()->accept( *this );
}

void AstToCasmVisitor::visit( PropertyType& node )
{
    node.name()->accept( *this );
    m_stream << "'";
    node.size()->accept( *this );
}

void AstToCasmVisitor::visit( MappingType& node )
{
    const auto& argumentTypes = *node.argumentTypes();
    if( argumentTypes.size() > 0 )
    {
        u1 first = true;
        for( const auto& argumentType : argumentTypes )
        {
            if( not first )
            {
                m_stream << " * ";
            }
            argumentType->accept( *this );
            first = false;
        }
        m_stream << " ";
    }
    m_stream << "-> ";
    node.returnType()->accept( *this );
}

void AstToCasmVisitor::visit( VariableBinding& node )
{
    node.variable()->accept( *this );
    m_stream << " = ";
    node.expression()->accept( *this );
}

void AstToCasmVisitor::visit( Identifier& node )
{
    m_stream << node.name();
}

void AstToCasmVisitor::visit( IdentifierPath& node )
{
    u1 first = true;
    for( const auto& identifier : *node.identifiers() )
    {
        if( not first )
        {
            m_stream << "::";
        }
        identifier->accept( *this );
        first = false;
    }
}

void AstToCasmVisitor::dumpNode( const Node& node )
{
    m_stream << "// " << node.description() << " @ " << node.sourceLocation() << "\n";
}

void AstToCasmPass::usage( libpass::PassUsage& pu )
{
    pu.require< CstToAstPass >();
}

u1 AstToCasmPass::run( libpass::PassResult& pr )
{
    Logger log( &id, stream() );

    const auto& data = pr.output< CstToAstPass >();
    const auto& specification = data->specification();

    const auto printCasmSpecification = [ & ]( std::ostream& out ) {
        AstToCasmVisitor visitor{
            log, out, specification->name(), specification->location()->toString()
        };
        specification->ast()->accept( visitor );
    };

    if( outputPath() == "" )
    {
        log.debug( "writing CASM specification to 'stdout'" );
        printCasmSpecification( std::cout );
    }
    else
    {
        const std::string outputFile = specification->name() + ".casm";

        if( not libstdhl::File::Path::exists( outputPath() ) )
        {
            try
            {
                libstdhl::File::Path::create( outputPath() );
            }
            catch( const std::domain_error& e )
            {
                log.error( e.what() );
            }
        }

        const auto outputFilePath = outputPath() + "/" + outputFile;

        std::ofstream casmFile( outputFilePath );
        if( not casmFile.is_open() )
        {
            log.error( "could not open '" + outputFilePath + "'" );
            return false;
        }

        log.debug( "writing CASM specification to '" + outputFilePath + "'" );
        printCasmSpecification( casmFile );
    }

    return true;
}

void AstToCasmPass::setOutputPath( const std::string& outputPath )
{
    m_outputPath = outputPath;
}

const std::string& AstToCasmPass::outputPath( void ) const
{
    return m_outputPath;
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
