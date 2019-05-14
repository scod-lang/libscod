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

#include "Definition.h"

#include "../various/GrammarToken.h"

using namespace libscod;
using namespace CST;

//
//
// Definition
//

Definition::Definition( Node::ID type, const Token::Ptr& token, const Identifier::Ptr& identifier )
: Node( type )
, m_token( token )
, m_identifier( identifier )
, m_attributes( std::make_shared< Attributes >() )
, m_delimiterToken( Token::unresolved() )
{
}

const Token::Ptr& Definition::token( void ) const
{
    return m_token;
}

const Identifier::Ptr& Definition::identifier( void ) const
{
    return m_identifier;
}

void Definition::setAttributes( const Attributes::Ptr& attributes )
{
    m_attributes = attributes;
}

const Attributes::Ptr& Definition::attributes( void ) const
{
    return m_attributes;
}

void Definition::setDelimiterToken( const Token::Ptr& delimiterToken )
{
    assert( m_delimiterToken->token() == Grammar::Token::UNRESOLVED );
    m_delimiterToken = delimiterToken;
}

const Token::Ptr& Definition::delimiterToken( void ) const
{
    return m_delimiterToken;
}

//
//
// HeaderDefinition
//

HeaderDefinition::HeaderDefinition( const Token::Ptr& headerToken )
: Definition(
      Node::ID::HEADER_DEFINITION,
      headerToken,
      CST::make< Identifier >( headerToken->sourceLocation(), headerToken->tokenString() ) )
{
}

void HeaderDefinition::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
//
// FunctionDefinition
//

FunctionDefinition::FunctionDefinition(
    const Node::ID id,
    const Token::Ptr& functionToken,
    const Identifier::Ptr& identifier,
    const Token::Ptr& colonToken,
    const Type::Ptr& mappingType )
: Definition( id, functionToken, identifier )
, m_colonToken( colonToken )
, m_mappingType( mappingType )
{
}

const Type::Ptr& FunctionDefinition::mappingType( void ) const
{
    return m_mappingType;
}

const Token::Ptr& FunctionDefinition::colonToken( void ) const
{
    return m_colonToken;
}

//
//
// MemoryDefinition
//

MemoryDefinition::MemoryDefinition(
    const Token::Ptr& memoryToken,
    const Identifier::Ptr& identifier,
    const Token::Ptr& colonToken,
    const Type::Ptr& type )
: FunctionDefinition( Node::ID::MEMORY_DEFINITION, memoryToken, identifier, colonToken, type )
{
}

void MemoryDefinition::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
//
// RegisterDefinition
//

RegisterDefinition::RegisterDefinition(
    const Token::Ptr& registerToken,
    const Identifier::Ptr& identifier,
    const Token::Ptr& colonToken,
    const Type::Ptr& type )
: FunctionDefinition( Node::ID::REGISTER_DEFINITION, registerToken, identifier, colonToken, type )
{
}

void RegisterDefinition::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
//
// FieldDefinition
//

FieldDefinition::FieldDefinition(
    const Token::Ptr& fieldToken,
    const Identifier::Ptr& identifier,
    const Token::Ptr& colonToken,
    const Type::Ptr& type )
: FunctionDefinition( Node::ID::FIELD_DEFINITION, fieldToken, identifier, colonToken, type )
{
}

void FieldDefinition::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
//
// FormatDefinition
//

FormatDefinition::FormatDefinition(
    const Token::Ptr& formatToken,
    const Identifier::Ptr& identifier,
    const Token::Ptr& colonToken,
    const Type::Ptr& type,
    const Token::Ptr& equalToken,
    const MappingLiteral::Ptr& mapping )
: FunctionDefinition( Node::ID::FORMAT_DEFINITION, formatToken, identifier, colonToken, type )
, m_equalToken( equalToken )
, m_mapping( mapping )
{
}

const Token::Ptr& FormatDefinition::equalToken( void ) const
{
    return m_equalToken;
}

const MappingLiteral::Ptr& FormatDefinition::mapping( void ) const
{
    return m_mapping;
}

void FormatDefinition::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
//
// BufferDefinition
//

BufferDefinition::BufferDefinition(
    const Token::Ptr& bufferToken,
    const Identifier::Ptr& identifier,
    const Token::Ptr& colonToken,
    const Type::Ptr& type,
    const Token::Ptr& equalToken,
    const Expression::Ptr& expression )
: FunctionDefinition( Node::ID::BUFFER_DEFINITION, bufferToken, identifier, colonToken, type )
, m_equalToken( equalToken )
, m_expression( expression )
{
}

const Token::Ptr& BufferDefinition::equalToken( void ) const
{
    return m_equalToken;
}

const Expression::Ptr& BufferDefinition::expression( void ) const
{
    return m_expression;
}

void BufferDefinition::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
//
// OptionDefinition
//

OptionDefinition::OptionDefinition(
    const ReferenceLiteral::Ptr& reference,
    const Option::Ptr& option,
    const OptionDefinition::Kind kind )
: Definition(
      Node::ID::OPTION_DEFINITION,
      Token::unresolved(),
      CST::make< Identifier >( reference->sourceLocation(), reference->target()->path() ) )
, m_reference( reference )
, m_option( option )
, m_kind( kind )
{
}

const ReferenceLiteral::Ptr& OptionDefinition::reference( void ) const
{
    return m_reference;
}

const Option::Ptr& OptionDefinition::option( void ) const
{
    return m_option;
}

const OptionDefinition::Kind OptionDefinition::kind( void ) const
{
    return m_kind;
}

void OptionDefinition::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
//
// InstructionDefinition
//

InstructionDefinition::InstructionDefinition(
    const Token::Ptr& instructionToken,
    const Identifier::Ptr& identifier,
    const Token::Ptr& colonToken,
    const Type::Ptr& type,
    const Token::Ptr& equalToken,
    const Statement::Ptr& statement,
    const Options::Ptr& options )
: FunctionDefinition(
      Node::ID::INSTRUCTION_DEFINITION, instructionToken, identifier, colonToken, type )
, m_equalToken( equalToken )
, m_statement( statement )
, m_options( options )
{
}

const Token::Ptr& InstructionDefinition::equalToken( void ) const
{
    return m_equalToken;
}

const Statement::Ptr& InstructionDefinition::statement( void ) const
{
    return m_statement;
}

const Options::Ptr& InstructionDefinition::options( void ) const
{
    return m_options;
}

void InstructionDefinition::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
//
// EnumerationDefinition
//

EnumerationDefinition::EnumerationDefinition(
    const Token::Ptr& enumerationToken,
    const Identifier::Ptr& identifier,
    const Token::Ptr& equalToken,
    const SetLiteral::Ptr& enumerators )
: Definition( Node::ID::ENUMERATION_DEFINITION, enumerationToken, identifier )
, m_equalToken( equalToken )
, m_enumerators( enumerators )
{
}

const Token::Ptr& EnumerationDefinition::equalToken( void ) const
{
    return m_equalToken;
}

const SetLiteral::Ptr& EnumerationDefinition::enumerators( void ) const
{
    return m_enumerators;
}

void EnumerationDefinition::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
//
// UsingDefinition
//

UsingDefinition::UsingDefinition(
    const Token::Ptr& usingToken,
    const Identifier::Ptr& identifier,
    const Token::Ptr& equalToken,
    const Type::Ptr& alias )
: Definition( Node::ID::USING_DEFINITION, usingToken, identifier )
, m_equalToken( equalToken )
, m_alias( alias )
{
}

const Token::Ptr& UsingDefinition::equalToken( void ) const
{
    return m_equalToken;
}

const Type::Ptr& UsingDefinition::alias( void ) const
{
    return m_alias;
}

void UsingDefinition::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
//
// VariableDefinition
//

VariableDefinition::VariableDefinition(
    const Identifier::Ptr& identifier, const Token::Ptr& colonToken, const Type::Ptr& variableType )
: Definition( Node::ID::VARIABLE_DEFINITION, Token::unresolved(), identifier )
, m_colonToken( colonToken )
, m_variableType( variableType )
{
}

const Type::Ptr& VariableDefinition::variableType( void ) const
{
    return m_variableType;
}

const Token::Ptr& VariableDefinition::colonToken( void ) const
{
    return m_colonToken;
}

void VariableDefinition::accept( Visitor& visitor )
{
    visitor.visit( *this );
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
