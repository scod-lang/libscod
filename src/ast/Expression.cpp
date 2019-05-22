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

#include "Expression.h"

#include <libscod/ast/Binding>
#include <libscod/ast/Literal>
#include <libscod/ast/Type>

using namespace libscod;
using namespace AST;

//
//
// Expression
//

Expression::Expression( Node::ID id )
: Node( id )
{
}

//
//
// NamedExpression
//

NamedExpression::NamedExpression(
    const Identifier::Ptr& identifier, const Expression::Ptr& expression )
: Expression( Node::ID::NAMED_EXPRESSION )
, m_identifier( identifier )
, m_expression( expression )
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

void NamedExpression::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
//
// MappedExpression
//

MappedExpression::MappedExpression(
    const Expressions::Ptr& arguments, const Expression::Ptr& value )
: Expression( Node::ID::MAPPED_EXPRESSION )
, m_arguments( arguments )
, m_value( value )
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

void MappedExpression::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
//
// LetExpression
//

LetExpression::LetExpression(
    const VariableBinding::Ptr& variableBinding, const Expression::Ptr& expression )
: Expression( Node::ID::LET_EXPRESSION )
, m_variableBinding( variableBinding )
, m_expression( expression )
{
}

const VariableBinding::Ptr& LetExpression::variableBinding( void ) const
{
    return m_variableBinding;
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
    const Expression::Ptr& condition,
    const Expression::Ptr& thenExpression,
    const Expression::Ptr& elseExpression )
: Expression( Node::ID::CONDITIONAL_EXPRESSION )
, m_condition( condition )
, m_thenExpression( thenExpression )
, m_elseExpression( elseExpression )
{
}

const Expression::Ptr& ConditionalExpression::condition( void ) const
{
    return m_condition;
}

const Expression::Ptr& ConditionalExpression::thenExpression( void ) const
{
    return m_thenExpression;
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

CallExpression::CallExpression( const Node::ID id, const Expressions::Ptr& arguments )
: Expression( id )
, m_arguments( arguments )
{
}

const Expressions::Ptr& CallExpression::arguments( void ) const
{
    return m_arguments;
}

//
//
// DirectCallExpression
//

DirectCallExpression::DirectCallExpression(
    const IdentifierPath::Ptr& name, const Expressions::Ptr& arguments )
: CallExpression( Node::ID::DIRECT_CALL_EXPRESSION, arguments )
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
    const Identifier::Ptr& method,
    const Expressions::Ptr& arguments )
: CallExpression( Node::ID::METHOD_CALL_EXPRESSION, arguments )
, m_object( object )
, m_method( method )
{
}

const Expression::Ptr& MethodCallExpression::object( void ) const
{
    return m_object;
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
    const Grammar::Token operation, const Expression::Ptr& expression )
: Expression( Node::ID::UNARY_EXPRESSION )
, m_operation( operation )
, m_expression( expression )
{
}

Grammar::Token UnaryExpression::operation( void ) const
{
    return m_operation;
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
    const Grammar::Token operation,
    const Expression::Ptr& rightExpression )
: Expression( Node::ID::BINARY_EXPRESSION )
, m_leftExpression( leftExpression )
, m_operation( operation )
, m_rightExpression( rightExpression )
{
}

const Expression::Ptr& BinaryExpression::leftExpression( void ) const
{
    return m_leftExpression;
}

const Grammar::Token BinaryExpression::operation( void ) const
{
    return m_operation;
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
