//
//  Copyright (C) 2019-2022 SCOD Organization <https://scod-lang.org>
//  All rights reserved.
//
//  Developed by: Philipp Paulweber et al.
//                <https://github.com/scod-lang/libscod/graphs/contributors>
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

#include "Literal.h"

#include <libstdhl/File>
#include <libstdhl/String>

using namespace libscod;
using namespace AST;

//
//
// Literal
//

Literal::Literal( const Node::ID id )
: Expression( id )
{
}

//
//
// ValueLiteral
//

ValueLiteral::ValueLiteral( const libstdhl::Type::Data& value, const ValueLiteral::Kind kind )
: Literal( Node::ID::VALUE_LITERAL )
, m_value( value )
, m_kind( kind )
{
}

const libstdhl::Type::Data& ValueLiteral::value( void ) const
{
    return m_value;
}

ValueLiteral::Kind ValueLiteral::kind( void ) const
{
    return m_kind;
}

std::string ValueLiteral::toString( void ) const
{
    return sourceLocation().read();
}

void ValueLiteral::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
//
// SetLiteral
//

SetLiteral::SetLiteral( const Expressions::Ptr& expressions )
: Literal( Node::ID::SET_LITERAL )
, m_expressions( expressions )
{
}

const Expressions::Ptr& SetLiteral::expressions( void ) const
{
    return m_expressions;
}

void SetLiteral::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
//
// ListLiteral
//

ListLiteral::ListLiteral( const Expressions::Ptr& expressions )
: Literal( Node::ID::LIST_LITERAL )
, m_expressions( expressions )
{
}

const Expressions::Ptr& ListLiteral::expressions( void ) const
{
    return m_expressions;
}

void ListLiteral::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
//
// RangeLiteral
//

RangeLiteral::RangeLiteral( const Expression::Ptr& from, const Expression::Ptr& to )
: Literal( Node::ID::RANGE_LITERAL )
, m_from( from )
, m_to( to )
{
}

const Expression::Ptr& RangeLiteral::from( void ) const
{
    return m_from;
}

const Expression::Ptr& RangeLiteral::to( void ) const
{
    return m_to;
}

void RangeLiteral::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
//
// RecordLiteral
//

RecordLiteral::RecordLiteral( const NamedExpressions::Ptr& namedExpressions )
: Literal( Node::ID::RECORD_LITERAL )
, m_namedExpressions( namedExpressions )
{
}

const NamedExpressions::Ptr& RecordLiteral::namedExpressions( void ) const
{
    return m_namedExpressions;
}

void RecordLiteral::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
//
// MappingLiteral
//

MappingLiteral::MappingLiteral( const MappedExpressions::Ptr& mappedExpressions )
: Literal( Node::ID::MAPPING_LITERAL )
, m_mappedExpressions( mappedExpressions )
{
}

const MappedExpressions::Ptr& MappingLiteral::mappedExpressions( void ) const
{
    return m_mappedExpressions;
}

void MappingLiteral::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
//
// ReferenceLiteral
//

ReferenceLiteral::ReferenceLiteral( const IdentifierPath::Ptr& target )
: Literal( Node::ID::REFERENCE_LITERAL )
, m_target( target )
{
}

const IdentifierPath::Ptr& ReferenceLiteral::target( void ) const
{
    return m_target;
}

void ReferenceLiteral::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
//
// GrammarLiteral
//

GrammarLiteral::GrammarLiteral( const Expressions::Ptr& expressions )
: Literal( Node::ID::GRAMMAR_LITERAL )
, m_expressions( expressions )
{
}

const Expressions::Ptr& GrammarLiteral::expressions( void ) const
{
    return m_expressions;
}

void GrammarLiteral::accept( Visitor& visitor )
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
