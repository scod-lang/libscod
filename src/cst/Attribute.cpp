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

#include "Attribute.h"

#include "../various/GrammarToken.h"

#include <cassert>

using namespace libscod;
using namespace CST;

//
//
// Attribute
//

Attribute::Attribute( Node::ID type, const Identifier::Ptr& identifier )
: Node( type )
, m_identifier( identifier )
, m_leftBrace( Token::unresolved() )
, m_rightBrace( Token::unresolved() )
{
}

const Identifier::Ptr& Attribute::identifier( void ) const
{
    return m_identifier;
}

void Attribute::setLeftBrace( const Token::Ptr& leftBrace )
{
    assert( m_leftBrace->token() == Grammar::Token::UNRESOLVED );
    m_leftBrace = leftBrace;
}

const Token::Ptr& Attribute::leftBrace( void ) const
{
    return m_leftBrace;
}

void Attribute::setRightBrace( const Token::Ptr& rightBrace )
{
    assert( m_rightBrace->token() == Grammar::Token::UNRESOLVED );
    m_rightBrace = rightBrace;
}

const Token::Ptr& Attribute::rightBrace( void ) const
{
    return m_rightBrace;
}

//
//
// BasicAttribute
//

BasicAttribute::BasicAttribute( const Identifier::Ptr& identifier )
: Attribute( Node::ID::BASIC_ATTRIBUTE, identifier )
{
}

void BasicAttribute::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
//
// ExpressionAttribute
//

ExpressionAttribute::ExpressionAttribute(
    const Identifier::Ptr& identifier, const Expression::Ptr& expression )
: Attribute( Node::ID::EXPRESSION_ATTRIBUTE, identifier )
, m_expression( expression )
{
}

const Expression::Ptr& ExpressionAttribute::expression( void ) const
{
    return m_expression;
}

void ExpressionAttribute::accept( Visitor& visitor )
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
