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

#include "../various/GrammarToken.h"

#include <libscod/cst/Attribute>
#include <libscod/cst/Binding>
#include <libscod/cst/Definition>
#include <libscod/cst/Identifier>
#include <libscod/cst/Literal>
#include <libscod/cst/Root>
#include <libscod/cst/Span>
#include <libscod/cst/Token>
#include <libscod/cst/Type>

using namespace libscod;
using namespace CST;

//
//
// RecursiveVisitor
//

void RecursiveVisitor::visit( Root& node )
{
    node.header()->accept( *this );
    node.definitions()->accept( *this );
    node.spans()->accept( *this );
}

void RecursiveVisitor::visit( HeaderDefinition& node )
{
    node.attributes()->accept( *this );
    node.token()->accept( *this );
}

void RecursiveVisitor::visit( MemoryDefinition& node )
{
    node.attributes()->accept( *this );
    node.token()->accept( *this );
    node.identifier()->accept( *this );
    node.colonToken()->accept( *this );
    node.mappingType()->accept( *this );
}

void RecursiveVisitor::visit( RegisterDefinition& node )
{
    node.attributes()->accept( *this );
    node.token()->accept( *this );
    node.identifier()->accept( *this );
    node.colonToken()->accept( *this );
    node.mappingType()->accept( *this );
}

void RecursiveVisitor::visit( FieldDefinition& node )
{
    node.attributes()->accept( *this );
    node.token()->accept( *this );
    node.identifier()->accept( *this );
    node.colonToken()->accept( *this );
    node.mappingType()->accept( *this );
}

void RecursiveVisitor::visit( FormatDefinition& node )
{
    node.attributes()->accept( *this );
    node.token()->accept( *this );
    node.identifier()->accept( *this );
    node.colonToken()->accept( *this );
    node.mappingType()->accept( *this );
    node.equalToken()->accept( *this );
    node.mapping()->accept( *this );
}

void RecursiveVisitor::visit( BufferDefinition& node )
{
    node.attributes()->accept( *this );
    node.token()->accept( *this );
    node.identifier()->accept( *this );
    node.colonToken()->accept( *this );
    node.mappingType()->accept( *this );
    node.equalToken()->accept( *this );
    node.expression()->accept( *this );
}

void RecursiveVisitor::visit( InstructionDefinition& node )
{
    node.attributes()->accept( *this );
    node.token()->accept( *this );
    node.identifier()->accept( *this );
    node.colonToken()->accept( *this );
    node.mappingType()->accept( *this );
    node.equalToken()->accept( *this );
    node.statement()->accept( *this );
    node.options()->accept( *this );
}

void RecursiveVisitor::visit( MicroProcessorDefinition& node )
{
    node.attributes()->accept( *this );
    node.token()->accept( *this );
    node.identifier()->accept( *this );
    node.colonToken()->accept( *this );
    node.programCounter()->accept( *this );
    node.equalToken()->accept( *this );
    node.statement()->accept( *this );
    node.options()->accept( *this );
}

void RecursiveVisitor::visit( CacheDefinition& node )
{
    node.attributes()->accept( *this );
    node.token()->accept( *this );
    node.identifier()->accept( *this );
    node.colonToken()->accept( *this );
    node.mappingType()->accept( *this );
    node.equalToken()->accept( *this );
    node.connection()->accept( *this );
}

void RecursiveVisitor::visit( InterconnectDefinition& node )
{
    node.attributes()->accept( *this );
    node.token()->accept( *this );
    node.identifier()->accept( *this );
    node.colonToken()->accept( *this );
    node.mappingType()->accept( *this );
    node.equalToken()->accept( *this );
    node.connection()->accept( *this );
}

void RecursiveVisitor::visit( OptionDefinition& node )
{
    node.attributes()->accept( *this );
    node.reference()->accept( *this );
    node.option()->accept( *this );
}

void RecursiveVisitor::visit( EnumerationDefinition& node )
{
    node.attributes()->accept( *this );
    node.token()->accept( *this );
    node.identifier()->accept( *this );
    node.equalToken()->accept( *this );
    node.enumerators()->accept( *this );
}

void RecursiveVisitor::visit( UsingDefinition& node )
{
    node.attributes()->accept( *this );
    node.token()->accept( *this );
    node.identifier()->accept( *this );
    node.equalToken()->accept( *this );
    node.alias()->accept( *this );
}

void RecursiveVisitor::visit( VariableDefinition& node )
{
    node.attributes()->accept( *this );
    node.token()->accept( *this );
    node.identifier()->accept( *this );
    node.colonToken()->accept( *this );
    node.variableType()->accept( *this );
}

void RecursiveVisitor::visit( UnresolvedOption& node )
{
    node.optionToken()->accept( *this );
    node.equalToken()->accept( *this );
}

void RecursiveVisitor::visit( DecodingOption& node )
{
    node.optionToken()->accept( *this );
    node.equalToken()->accept( *this );
    node.value()->accept( *this );
}

void RecursiveVisitor::visit( SyntaxOption& node )
{
    node.optionToken()->accept( *this );
    node.equalToken()->accept( *this );
    node.value()->accept( *this );
}

void RecursiveVisitor::visit( ExpansionOption& node )
{
    node.optionToken()->accept( *this );
    node.equalToken()->accept( *this );
    node.value()->accept( *this );
}

void RecursiveVisitor::visit( StageOption& node )
{
    node.optionToken()->accept( *this );
    node.identifier()->accept( *this );
    node.equalToken()->accept( *this );
    node.statement()->accept( *this );
}

void RecursiveVisitor::visit( SkipStatement& node )
{
    node.skipToken()->accept( *this );
}

void RecursiveVisitor::visit( BlockStatement& node )
{
    node.leftBraceToken()->accept( *this );
    node.statements()->accept( *this );
    node.rightBraceToken()->accept( *this );
}

void RecursiveVisitor::visit( CallStatement& node )
{
    node.target()->accept( *this );
}

void RecursiveVisitor::visit( LetStatement& node )
{
    node.letToken()->accept( *this );
    node.variableBindings()->accept( *this );
    node.inToken()->accept( *this );
    node.statement()->accept( *this );
}

void RecursiveVisitor::visit( AssignmentStatement& node )
{
    node.target()->accept( *this );
    node.assignmentToken()->accept( *this );
    node.expression()->accept( *this );
}

void RecursiveVisitor::visit( ConditionalStatement& node )
{
    node.ifToken()->accept( *this );
    node.condition()->accept( *this );
    node.thenToken()->accept( *this );
    node.thenStatement()->accept( *this );
    node.elseToken()->accept( *this );
    node.elseStatement()->accept( *this );
}

void RecursiveVisitor::visit( EmbracedExpression& node )
{
    node.delimiterToken()->accept( *this );
    node.leftBraceToken()->accept( *this );
    node.expression()->accept( *this );
    node.rightBraceToken()->accept( *this );
}

void RecursiveVisitor::visit( NamedExpression& node )
{
    node.delimiterToken()->accept( *this );
    node.identifier()->accept( *this );
    node.colonToken()->accept( *this );
    node.expression()->accept( *this );
}

void RecursiveVisitor::visit( MappedExpression& node )
{
    node.delimiterToken()->accept( *this );
    node.leftBracketToken()->accept( *this );
    node.arguments()->accept( *this );
    node.rightBracketToken()->accept( *this );
    node.mapsToken()->accept( *this );
    node.value()->accept( *this );
}

void RecursiveVisitor::visit( LetExpression& node )
{
    node.delimiterToken()->accept( *this );
    node.letToken()->accept( *this );
    node.variableBindings()->accept( *this );
    node.inToken()->accept( *this );
    node.expression()->accept( *this );
}

void RecursiveVisitor::visit( ConditionalExpression& node )
{
    node.ifToken()->accept( *this );
    node.condition()->accept( *this );
    node.thenToken()->accept( *this );
    node.thenExpression()->accept( *this );
    node.elseToken()->accept( *this );
    node.elseExpression()->accept( *this );
}

void RecursiveVisitor::visit( DirectCallExpression& node )
{
    node.delimiterToken()->accept( *this );
    node.name()->accept( *this );
    node.leftBracketToken()->accept( *this );
    node.arguments()->accept( *this );
    node.rightBracketToken()->accept( *this );
}

void RecursiveVisitor::visit( MethodCallExpression& node )
{
    node.delimiterToken()->accept( *this );
    node.object()->accept( *this );
    node.dotToken()->accept( *this );
    node.method()->accept( *this );
    node.leftBracketToken()->accept( *this );
    node.arguments()->accept( *this );
    node.rightBracketToken()->accept( *this );
}

void RecursiveVisitor::visit( UnaryExpression& node )
{
    node.delimiterToken()->accept( *this );
    node.operationToken()->accept( *this );
    node.expression()->accept( *this );
}

void RecursiveVisitor::visit( BinaryExpression& node )
{
    node.delimiterToken()->accept( *this );
    node.leftExpression()->accept( *this );
    node.operationToken()->accept( *this );
    node.rightExpression()->accept( *this );
}

void RecursiveVisitor::visit( ValueLiteral& node )
{
    node.delimiterToken()->accept( *this );
    node.spans()->accept( *this );
    node.leftBracket()->accept( *this );
    node.rightBracket()->accept( *this );
}

void RecursiveVisitor::visit( SetLiteral& node )
{
    node.delimiterToken()->accept( *this );
    node.spans()->accept( *this );
    node.leftBracket()->accept( *this );
    node.expressions()->accept( *this );
    node.rightBracket()->accept( *this );
}

void RecursiveVisitor::visit( ListLiteral& node )
{
    node.delimiterToken()->accept( *this );
    node.spans()->accept( *this );
    node.leftBracket()->accept( *this );
    node.expressions()->accept( *this );
    node.rightBracket()->accept( *this );
}

void RecursiveVisitor::visit( RangeLiteral& node )
{
    node.delimiterToken()->accept( *this );
    node.spans()->accept( *this );
    node.leftBracket()->accept( *this );
    node.from()->accept( *this );
    node.dotdotToken()->accept( *this );
    node.to()->accept( *this );
    node.rightBracket()->accept( *this );
}

void RecursiveVisitor::visit( RecordLiteral& node )
{
    node.delimiterToken()->accept( *this );
    node.spans()->accept( *this );
    node.leftBracket()->accept( *this );
    node.namedExpressions()->accept( *this );
    node.rightBracket()->accept( *this );
}

void RecursiveVisitor::visit( MappingLiteral& node )
{
    node.delimiterToken()->accept( *this );
    node.spans()->accept( *this );
    node.leftBracket()->accept( *this );
    node.mappedExpressions()->accept( *this );
    node.rightBracket()->accept( *this );
}

void RecursiveVisitor::visit( ReferenceLiteral& node )
{
    node.delimiterToken()->accept( *this );
    node.spans()->accept( *this );
    node.leftBracket()->accept( *this );
    node.atToken()->accept( *this );
    node.target()->accept( *this );
    node.rightBracket()->accept( *this );
}

void RecursiveVisitor::visit( GrammarLiteral& node )
{
    node.delimiterToken()->accept( *this );
    node.spans()->accept( *this );
    node.leftBracket()->accept( *this );
    node.expressions()->accept( *this );
    node.rightBracket()->accept( *this );
}

void RecursiveVisitor::visit( UnresolvedType& node )
{
    node.delimiterToken()->accept( *this );
    node.name()->accept( *this );
}

void RecursiveVisitor::visit( BasicType& node )
{
    node.delimiterToken()->accept( *this );
    node.name()->accept( *this );
}

void RecursiveVisitor::visit( PropertyType& node )
{
    node.delimiterToken()->accept( *this );
    node.name()->accept( *this );
    node.markToken()->accept( *this );
    node.size()->accept( *this );
}

void RecursiveVisitor::visit( MappingType& node )
{
    node.delimiterToken()->accept( *this );
    node.argumentTypes()->accept( *this );
    node.mapsToken()->accept( *this );
    node.returnType()->accept( *this );
}

void RecursiveVisitor::visit( BasicAttribute& node )
{
    node.leftBrace()->accept( *this );
    node.identifier()->accept( *this );
    node.rightBrace()->accept( *this );
}

void RecursiveVisitor::visit( ExpressionAttribute& node )
{
    node.leftBrace()->accept( *this );
    node.identifier()->accept( *this );
    node.expression()->accept( *this );
    node.rightBrace()->accept( *this );
}

void RecursiveVisitor::visit( VariableBinding& node )
{
    node.delimiterToken()->accept( *this );
    node.variable()->accept( *this );
    node.equalToken()->accept( *this );
    node.expression()->accept( *this );
}

void RecursiveVisitor::visit( Identifier& node )
{
    node.namespaceToken()->accept( *this );
    node.spans()->accept( *this );
}

void RecursiveVisitor::visit( IdentifierPath& node )
{
    node.identifiers()->accept( *this );
}

void RecursiveVisitor::visit( Token& node )
{
    node.spans()->accept( *this );
}

void RecursiveVisitor::visit( Span& node )
{
}

//
//
// EmptyVisitor
//

void EmptyVisitor::visit( Root& )
{
}

void EmptyVisitor::visit( HeaderDefinition& )
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

void EmptyVisitor::visit( EmbracedExpression& )
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

void EmptyVisitor::visit( BasicAttribute& )
{
}

void EmptyVisitor::visit( ExpressionAttribute& )
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

void EmptyVisitor::visit( Token& )
{
}

void EmptyVisitor::visit( Span& )
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
