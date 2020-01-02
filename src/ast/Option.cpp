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

#include "Option.h"

using namespace libscod;
using namespace AST;

//
//
// Option
//

Option::Option( const Node::ID id )
: Node( id )
{
}

//
//
// UnresolvedOption
//

UnresolvedOption::UnresolvedOption( void )
: Option( Node::ID::UNRESOLVED_OPTION )
{
}

void UnresolvedOption::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
//
// DecodingOption
//

DecodingOption::DecodingOption( const RecordLiteral::Ptr& value )
: Option( Node::ID::DECODING_OPTION )
, m_value( value )
{
}

const RecordLiteral::Ptr& DecodingOption::value( void ) const
{
    return m_value;
}

void DecodingOption::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
//
// SyntaxOption
//

SyntaxOption::SyntaxOption( const SetLiteral::Ptr& value )
: Option( Node::ID::SYNTAX_OPTION )
, m_value( value )
{
}

const SetLiteral::Ptr& SyntaxOption::value( void ) const
{
    return m_value;
}

void SyntaxOption::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
//
// ExpansionOption
//

ExpansionOption::ExpansionOption( const SetLiteral::Ptr& value )
: Option( Node::ID::EXPANSION_OPTION )
, m_value( value )
{
}

const SetLiteral::Ptr& ExpansionOption::value( void ) const
{
    return m_value;
}

void ExpansionOption::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
//
// StageOption
//

StageOption::StageOption( const Identifier::Ptr& identifier, const BlockStatement::Ptr& statement )
: Option( Node::ID::STAGE_OPTION )
, m_identifier( identifier )
, m_statement( statement )
{
}

const Identifier::Ptr& StageOption::identifier( void ) const
{
    return m_identifier;
}

const BlockStatement::Ptr& StageOption::statement( void ) const
{
    return m_statement;
}

void StageOption::accept( Visitor& visitor )
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
