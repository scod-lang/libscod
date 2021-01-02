//
//  Copyright (C) 2019-2021 SCOD Organization <https://scod-lang.org>
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

#include "Visitor.h"

#include <libscod/ast/Binding>
#include <libscod/ast/Definition>
#include <libscod/ast/Identifier>
#include <libscod/ast/Literal>
#include <libscod/ast/Root>
#include <libscod/ast/Type>

using namespace libscod;
using namespace AST;

//
//
// RecursiveVisitor
//

void RecursiveVisitor::visit( Root& node )
{
    node.definitions()->accept( *this );
}

void RecursiveVisitor::visit( MemoryDefinition& node )
{
    node.identifier()->accept( *this );
    node.mappingType()->accept( *this );
}

void RecursiveVisitor::visit( RegisterDefinition& node )
{
    node.identifier()->accept( *this );
    node.mappingType()->accept( *this );
}

void RecursiveVisitor::visit( FieldDefinition& node )
{
    node.identifier()->accept( *this );
    node.mappingType()->accept( *this );
}

void RecursiveVisitor::visit( FormatDefinition& node )
{
    node.identifier()->accept( *this );
    node.mappingType()->accept( *this );
    node.mapping()->accept( *this );
}

void RecursiveVisitor::visit( BufferDefinition& node )
{
    node.identifier()->accept( *this );
    node.mappingType()->accept( *this );
    node.expression()->accept( *this );
}

void RecursiveVisitor::visit( InstructionDefinition& node )
{
    node.identifier()->accept( *this );
    node.mappingType()->accept( *this );
    node.statement()->accept( *this );
    node.options()->accept( *this );
}

void RecursiveVisitor::visit( MicroProcessorDefinition& node )
{
    node.identifier()->accept( *this );
    node.programCounter()->accept( *this );
    node.statement()->accept( *this );
    node.options()->accept( *this );
}

void RecursiveVisitor::visit( CacheDefinition& node )
{
    node.identifier()->accept( *this );
    node.mappingType()->accept( *this );
    node.connection()->accept( *this );
}

void RecursiveVisitor::visit( InterconnectDefinition& node )
{
    node.identifier()->accept( *this );
    node.mappingType()->accept( *this );
    node.connection()->accept( *this );
}

void RecursiveVisitor::visit( OptionDefinition& node )
{
    node.reference()->accept( *this );
    node.option()->accept( *this );
}

void RecursiveVisitor::visit( EnumerationDefinition& node )
{
    node.identifier()->accept( *this );
    node.enumerators()->accept( *this );
}

void RecursiveVisitor::visit( UsingDefinition& node )
{
    node.identifier()->accept( *this );
    node.alias()->accept( *this );
}

void RecursiveVisitor::visit( VariableDefinition& node )
{
    node.identifier()->accept( *this );
    node.variableType()->accept( *this );
}

void RecursiveVisitor::visit( UnresolvedOption& node )
{
}

void RecursiveVisitor::visit( DecodingOption& node )
{
    node.value()->accept( *this );
}

void RecursiveVisitor::visit( SyntaxOption& node )
{
    node.value()->accept( *this );
}

void RecursiveVisitor::visit( ExpansionOption& node )
{
    node.value()->accept( *this );
}

void RecursiveVisitor::visit( StageOption& node )
{
    node.identifier()->accept( *this );
    node.statement()->accept( *this );
}

void RecursiveVisitor::visit( SkipStatement& node )
{
}

void RecursiveVisitor::visit( BlockStatement& node )
{
    node.statements()->accept( *this );
}

void RecursiveVisitor::visit( CallStatement& node )
{
    node.target()->accept( *this );
}

void RecursiveVisitor::visit( LetStatement& node )
{
    node.variableBinding()->accept( *this );
    node.statement()->accept( *this );
}

void RecursiveVisitor::visit( AssignmentStatement& node )
{
    node.target()->accept( *this );
    node.expression()->accept( *this );
}

void RecursiveVisitor::visit( ConditionalStatement& node )
{
    node.condition()->accept( *this );
    node.thenStatement()->accept( *this );
    node.elseStatement()->accept( *this );
}

void RecursiveVisitor::visit( NamedExpression& node )
{
    node.identifier()->accept( *this );
    node.expression()->accept( *this );
}

void RecursiveVisitor::visit( MappedExpression& node )
{
    node.arguments()->accept( *this );
    node.value()->accept( *this );
}

void RecursiveVisitor::visit( LetExpression& node )
{
    node.variableBinding()->accept( *this );
    node.expression()->accept( *this );
}

void RecursiveVisitor::visit( ConditionalExpression& node )
{
    node.condition()->accept( *this );
    node.thenExpression()->accept( *this );
    node.elseExpression()->accept( *this );
}

void RecursiveVisitor::visit( DirectCallExpression& node )
{
    node.name()->accept( *this );
    node.arguments()->accept( *this );
}

void RecursiveVisitor::visit( MethodCallExpression& node )
{
    node.object()->accept( *this );
    node.method()->accept( *this );
    node.arguments()->accept( *this );
}

void RecursiveVisitor::visit( UnaryExpression& node )
{
    node.expression()->accept( *this );
}

void RecursiveVisitor::visit( BinaryExpression& node )
{
    node.leftExpression()->accept( *this );
    node.rightExpression()->accept( *this );
}

void RecursiveVisitor::visit( ValueLiteral& node )
{
}

void RecursiveVisitor::visit( SetLiteral& node )
{
    node.expressions()->accept( *this );
}

void RecursiveVisitor::visit( ListLiteral& node )
{
    node.expressions()->accept( *this );
}

void RecursiveVisitor::visit( RangeLiteral& node )
{
    node.from()->accept( *this );
    node.to()->accept( *this );
}

void RecursiveVisitor::visit( RecordLiteral& node )
{
    node.namedExpressions()->accept( *this );
}

void RecursiveVisitor::visit( MappingLiteral& node )
{
    node.mappedExpressions()->accept( *this );
}

void RecursiveVisitor::visit( ReferenceLiteral& node )
{
    node.target()->accept( *this );
}

void RecursiveVisitor::visit( GrammarLiteral& node )
{
    node.expressions()->accept( *this );
}

void RecursiveVisitor::visit( UnresolvedType& node )
{
    node.name()->accept( *this );
}

void RecursiveVisitor::visit( BasicType& node )
{
    node.name()->accept( *this );
}

void RecursiveVisitor::visit( PropertyType& node )
{
    node.name()->accept( *this );
    node.size()->accept( *this );
}

void RecursiveVisitor::visit( MappingType& node )
{
    node.argumentTypes()->accept( *this );
    node.returnType()->accept( *this );
}

void RecursiveVisitor::visit( VariableBinding& node )
{
    node.variable()->accept( *this );
    node.expression()->accept( *this );
}

void RecursiveVisitor::visit( Identifier& node )
{
}

void RecursiveVisitor::visit( IdentifierPath& node )
{
    node.identifiers()->accept( *this );
}

//
//
// EmptyVisitor
//

void EmptyVisitor::visit( Root& )
{
}

void EmptyVisitor::visit( MemoryDefinition& )
{
}

void EmptyVisitor::visit( RegisterDefinition& )
{
}

void EmptyVisitor::visit( FieldDefinition& )
{
}

void EmptyVisitor::visit( FormatDefinition& )
{
}

void EmptyVisitor::visit( BufferDefinition& )
{
}

void EmptyVisitor::visit( InstructionDefinition& )
{
}

void EmptyVisitor::visit( MicroProcessorDefinition& )
{
}

void EmptyVisitor::visit( CacheDefinition& )
{
}

void EmptyVisitor::visit( InterconnectDefinition& )
{
}

void EmptyVisitor::visit( OptionDefinition& )
{
}

void EmptyVisitor::visit( EnumerationDefinition& )
{
}

void EmptyVisitor::visit( UsingDefinition& )
{
}

void EmptyVisitor::visit( VariableDefinition& )
{
}

void EmptyVisitor::visit( UnresolvedOption& )
{
}

void EmptyVisitor::visit( DecodingOption& )
{
}

void EmptyVisitor::visit( SyntaxOption& )
{
}

void EmptyVisitor::visit( ExpansionOption& )
{
}

void EmptyVisitor::visit( StageOption& )
{
}

void EmptyVisitor::visit( SkipStatement& )
{
}

void EmptyVisitor::visit( BlockStatement& )
{
}

void EmptyVisitor::visit( CallStatement& )
{
}

void EmptyVisitor::visit( LetStatement& )
{
}

void EmptyVisitor::visit( AssignmentStatement& )
{
}

void EmptyVisitor::visit( ConditionalStatement& )
{
}

void EmptyVisitor::visit( NamedExpression& )
{
}

void EmptyVisitor::visit( MappedExpression& )
{
}

void EmptyVisitor::visit( LetExpression& )
{
}

void EmptyVisitor::visit( ConditionalExpression& )
{
}

void EmptyVisitor::visit( DirectCallExpression& )
{
}

void EmptyVisitor::visit( MethodCallExpression& )
{
}

void EmptyVisitor::visit( UnaryExpression& )
{
}

void EmptyVisitor::visit( BinaryExpression& )
{
}

void EmptyVisitor::visit( ValueLiteral& )
{
}

void EmptyVisitor::visit( SetLiteral& )
{
}

void EmptyVisitor::visit( ListLiteral& )
{
}

void EmptyVisitor::visit( RangeLiteral& )
{
}

void EmptyVisitor::visit( RecordLiteral& )
{
}

void EmptyVisitor::visit( MappingLiteral& )
{
}

void EmptyVisitor::visit( ReferenceLiteral& )
{
}

void EmptyVisitor::visit( GrammarLiteral& )
{
}

void EmptyVisitor::visit( UnresolvedType& )
{
}

void EmptyVisitor::visit( BasicType& )
{
}

void EmptyVisitor::visit( PropertyType& )
{
}

void EmptyVisitor::visit( MappingType& )
{
}

void EmptyVisitor::visit( VariableBinding& )
{
}

void EmptyVisitor::visit( Identifier& )
{
}

void EmptyVisitor::visit( IdentifierPath& )
{
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
