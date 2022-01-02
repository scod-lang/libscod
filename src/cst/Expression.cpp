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

#include "Expression.h"

#include <libscod/cst/Binding>
#include <libscod/cst/Literal>
#include <libscod/cst/Token>
#include <libscod/cst/Type>

#include "../various/GrammarToken.h"

using namespace libscod;
using namespace CST;

//
//
// Expression
//

Expression::Expression( Node::ID id )
: Node( id )
, m_delimiterToken( Token::unresolved() )
{
}

void Expression::setDelimiterToken( const Token::Ptr& delimiterToken )
{
    assert( m_delimiterToken->token() == Grammar::Token::UNRESOLVED );
    m_delimiterToken = delimiterToken;
}

const Token::Ptr& Expression::delimiterToken( void ) const
{
    return m_delimiterToken;
}

//
//
// EmbracedExpression
//

EmbracedExpression::EmbracedExpression(
    const Token::Ptr& leftBraceToken,
    const Expression::Ptr& expression,
    const Token::Ptr& rightBraceToken )
: Expression( Node::ID::EMBRACED_EXPRESSION )
, m_expression( expression )
, m_leftBraceToken( leftBraceToken )
, m_rightBraceToken( rightBraceToken )
{
}

const Expression::Ptr& EmbracedExpression::expression( void ) const
{
    return m_expression;
}

const Token::Ptr& EmbracedExpression::leftBraceToken( void ) const
{
    return m_leftBraceToken;
}

const Token::Ptr& EmbracedExpression::rightBraceToken( void ) const
{
    return m_rightBraceToken;
}

void EmbracedExpression::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
//
// NamedExpression
//

NamedExpression::NamedExpression(
    const Identifier::Ptr& identifier,
    const Token::Ptr& colonToken,
    const Expression::Ptr& expression )
: Expression( Node::ID::NAMED_EXPRESSION )
, m_identifier( identifier )
, m_expression( expression )
, m_colonToken( colonToken )
{
}

const Identifier::Ptr& NamedExpression::identifier( void ) const
{
    return m_identifier;
}

const Expression::Ptr& NamedExpression::expression( void ) const
{
    return m_expression;
}

const Token::Ptr& NamedExpression::colonToken( void ) const
{
    return m_colonToken;
}

void NamedExpression::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
//
// MappedExpression
//

MappedExpression::MappedExpression(
    const Token::Ptr& leftBracketToken,
    const Expressions::Ptr& arguments,
    const Token::Ptr& rightBracketToken,
    const Token::Ptr& mapsToken,
    const Expression::Ptr& value )
: Expression( Node::ID::MAPPED_EXPRESSION )
, m_arguments( arguments )
, m_value( value )
, m_leftBracketToken( leftBracketToken )
, m_rightBracketToken( rightBracketToken )
, m_mapsToken( mapsToken )
{
}

const Expressions::Ptr& MappedExpression::arguments( void ) const
{
    return m_arguments;
}

const Expression::Ptr& MappedExpression::value( void ) const
{
    return m_value;
}

const Token::Ptr& MappedExpression::leftBracketToken( void ) const
{
    return m_leftBracketToken;
}

const Token::Ptr& MappedExpression::rightBracketToken( void ) const
{
    return m_rightBracketToken;
}

const Token::Ptr& MappedExpression::mapsToken( void ) const
{
    return m_mapsToken;
}

void MappedExpression::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
//
// LetExpression
//

LetExpression::LetExpression(
    const Token::Ptr& letToken,
    const VariableBindings::Ptr& variableBindings,
    const Token::Ptr& inToken,
    const Expression::Ptr& expression )
: Expression( Node::ID::LET_EXPRESSION )
, m_letToken( letToken )
, m_variableBindings( variableBindings )
, m_inToken( inToken )
, m_expression( expression )
{
}

const Token::Ptr& LetExpression::letToken( void ) const
{
    return m_letToken;
}

const VariableBindings::Ptr& LetExpression::variableBindings( void ) const
{
    return m_variableBindings;
}

const Token::Ptr& LetExpression::inToken( void ) const
{
    return m_inToken;
}

const Expression::Ptr& LetExpression::expression( void ) const
{
    return m_expression;
}

void LetExpression::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
//
// ConditionalExpression
//

ConditionalExpression::ConditionalExpression(
    const Token::Ptr& ifToken,
    const Expression::Ptr& condition,
    const Token::Ptr& thenToken,
    const Expression::Ptr& thenExpression,
    const Token::Ptr& elseToken,
    const Expression::Ptr& elseExpression )
: Expression( Node::ID::CONDITIONAL_EXPRESSION )
, m_ifToken( ifToken )
, m_condition( condition )
, m_thenToken( thenToken )
, m_thenExpression( thenExpression )
, m_elseToken( elseToken )
, m_elseExpression( elseExpression )
{
}

const Token::Ptr& ConditionalExpression::ifToken( void ) const
{
    return m_ifToken;
}

const Expression::Ptr& ConditionalExpression::condition( void ) const
{
    return m_condition;
}

const Token::Ptr& ConditionalExpression::thenToken( void ) const
{
    return m_thenToken;
}

const Expression::Ptr& ConditionalExpression::thenExpression( void ) const
{
    return m_thenExpression;
}

const Token::Ptr& ConditionalExpression::elseToken( void ) const
{
    return m_elseToken;
}

const Expression::Ptr& ConditionalExpression::elseExpression( void ) const
{
    return m_elseExpression;
}

void ConditionalExpression::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
//
// CallExpression
//

CallExpression::CallExpression(
    const Node::ID id,
    const Token::Ptr& leftBracketToken,
    const Expressions::Ptr& arguments,
    const Token::Ptr& rightBracketToken )
: Expression( id )
, m_arguments( arguments )
, m_leftBracketToken( leftBracketToken )
, m_rightBracketToken( rightBracketToken )
{
}

const Expressions::Ptr& CallExpression::arguments( void ) const
{
    return m_arguments;
}

const Token::Ptr& CallExpression::leftBracketToken( void ) const
{
    return m_leftBracketToken;
}

const Token::Ptr& CallExpression::rightBracketToken( void ) const
{
    return m_rightBracketToken;
}

//
//
// DirectCallExpression
//

DirectCallExpression::DirectCallExpression(
    const IdentifierPath::Ptr& name,
    const Token::Ptr& leftBracketToken,
    const Expressions::Ptr& arguments,
    const Token::Ptr& rightBracketToken )
: CallExpression( Node::ID::DIRECT_CALL_EXPRESSION, leftBracketToken, arguments, rightBracketToken )
, m_name( name )
{
}

const IdentifierPath::Ptr& DirectCallExpression::name( void ) const
{
    return m_name;
}

void DirectCallExpression::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
//
// MethodCallExpression
//

MethodCallExpression::MethodCallExpression(
    const Expression::Ptr& object,
    const Token::Ptr& dotToken,
    const Identifier::Ptr& method,
    const Token::Ptr& leftBracketToken,
    const Expressions::Ptr& arguments,
    const Token::Ptr& rightBracketToken )
: CallExpression( Node::ID::METHOD_CALL_EXPRESSION, leftBracketToken, arguments, rightBracketToken )
, m_object( object )
, m_dotToken( dotToken )
, m_method( method )
{
}

const Expression::Ptr& MethodCallExpression::object( void ) const
{
    return m_object;
}

const Token::Ptr& MethodCallExpression::dotToken( void ) const
{
    return m_dotToken;
}

const Identifier::Ptr& MethodCallExpression::method( void ) const
{
    return m_method;
}

void MethodCallExpression::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
//
// UnaryExpression
//

UnaryExpression::UnaryExpression(
    const Token::Ptr& operationToken, const Expression::Ptr& expression )
: Expression( Node::ID::UNARY_EXPRESSION )
, m_operationToken( operationToken )
, m_expression( expression )
{
}

const Token::Ptr& UnaryExpression::operationToken( void ) const
{
    return m_operationToken;
}

const Expression::Ptr& UnaryExpression::expression( void ) const
{
    return m_expression;
}

void UnaryExpression::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
//
// UnaryExpression
//

BinaryExpression::BinaryExpression(
    const Expression::Ptr& leftExpression,
    const Token::Ptr& operationToken,
    const Expression::Ptr& rightExpression )
: Expression( Node::ID::BINARY_EXPRESSION )
, m_leftExpression( leftExpression )
, m_operationToken( operationToken )
, m_rightExpression( rightExpression )
{
}

const Expression::Ptr& BinaryExpression::leftExpression( void ) const
{
    return m_leftExpression;
}

const Token::Ptr& BinaryExpression::operationToken( void ) const
{
    return m_operationToken;
}

const Expression::Ptr& BinaryExpression::rightExpression( void ) const
{
    return m_rightExpression;
}

void BinaryExpression::accept( Visitor& visitor )
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
