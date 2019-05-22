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

using namespace libscod;
using namespace AST;

//
//
// Definition
//

Definition::Definition( Node::ID type, const Identifier::Ptr& identifier )
: Node( type )
, m_identifier( identifier )
{
}

const Identifier::Ptr& Definition::identifier( void ) const
{
    return m_identifier;
}

//
//
// FunctionDefinition
//

FunctionDefinition::FunctionDefinition(
    const Node::ID id, const Identifier::Ptr& identifier, const Type::Ptr& mappingType )
: Definition( id, identifier )
, m_mappingType( mappingType )
{
}

const Type::Ptr& FunctionDefinition::mappingType( void ) const
{
    return m_mappingType;
}

//
//
// MemoryDefinition
//

MemoryDefinition::MemoryDefinition( const Identifier::Ptr& identifier, const Type::Ptr& type )
: FunctionDefinition( Node::ID::MEMORY_DEFINITION, identifier, type )
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

RegisterDefinition::RegisterDefinition( const Identifier::Ptr& identifier, const Type::Ptr& type )
: FunctionDefinition( Node::ID::REGISTER_DEFINITION, identifier, type )
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

FieldDefinition::FieldDefinition( const Identifier::Ptr& identifier, const Type::Ptr& type )
: FunctionDefinition( Node::ID::FIELD_DEFINITION, identifier, type )
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
    const Identifier::Ptr& identifier, const Type::Ptr& type, const MappingLiteral::Ptr& mapping )
: FunctionDefinition( Node::ID::FORMAT_DEFINITION, identifier, type )
, m_mapping( mapping )
{
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
    const Identifier::Ptr& identifier, const Type::Ptr& type, const Expression::Ptr& expression )
: FunctionDefinition( Node::ID::BUFFER_DEFINITION, identifier, type )
, m_expression( expression )
{
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
      AST::make< Identifier >( reference->sourceLocation(), reference->target()->path() ) )
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
    const Identifier::Ptr& identifier,
    const Type::Ptr& type,
    const Statement::Ptr& statement,
    const Options::Ptr& options )
: FunctionDefinition( Node::ID::INSTRUCTION_DEFINITION, identifier, type )
, m_statement( statement )
, m_options( options )
{
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
// MicroProcessorDefinition
//

MicroProcessorDefinition::MicroProcessorDefinition(
    const Identifier::Ptr& identifier,
    const IdentifierPath::Ptr& programCounter,
    const Statement::Ptr& statement,
    const Options::Ptr& options )
: Definition( Node::ID::MICRO_PROCESSOR_DEFINITION, identifier )
, m_programCounter( programCounter )
, m_statement( statement )
, m_options( options )
{
}

const IdentifierPath::Ptr& MicroProcessorDefinition::programCounter( void ) const
{
    return m_programCounter;
}

const Statement::Ptr& MicroProcessorDefinition::statement( void ) const
{
    return m_statement;
}

const Options::Ptr& MicroProcessorDefinition::options( void ) const
{
    return m_options;
}

void MicroProcessorDefinition::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
//
// CacheDefinition
//

CacheDefinition::CacheDefinition(
    const Identifier::Ptr& identifier,
    const Type::Ptr& type,
    const MappingLiteral::Ptr& connection )
: FunctionDefinition( Node::ID::CACHE_DEFINITION, identifier, type )
, m_connection( connection )
{
}

const MappingLiteral::Ptr& CacheDefinition::connection( void ) const
{
    return m_connection;
}

void CacheDefinition::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
//
// InterconnectDefinition
//

InterconnectDefinition::InterconnectDefinition(
    const Identifier::Ptr& identifier,
    const Type::Ptr& type,
    const MappingLiteral::Ptr& connection )
: FunctionDefinition( Node::ID::INTERCONNECT_DEFINITION, identifier, type )
, m_connection( connection )
{
}

const MappingLiteral::Ptr& InterconnectDefinition::connection( void ) const
{
    return m_connection;
}

void InterconnectDefinition::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
//
// EnumerationDefinition
//

EnumerationDefinition::EnumerationDefinition(
    const Identifier::Ptr& identifier, const SetLiteral::Ptr& enumerators )
: Definition( Node::ID::ENUMERATION_DEFINITION, identifier )
, m_enumerators( enumerators )
{
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

UsingDefinition::UsingDefinition( const Identifier::Ptr& identifier, const Type::Ptr& alias )
: Definition( Node::ID::USING_DEFINITION, identifier )
, m_alias( alias )
{
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
    const Identifier::Ptr& identifier, const Type::Ptr& variableType )
: Definition( Node::ID::VARIABLE_DEFINITION, identifier )
, m_variableType( variableType )
{
}

const Type::Ptr& VariableDefinition::variableType( void ) const
{
    return m_variableType;
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
