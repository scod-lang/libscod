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

#include "Statement.h"

#include "../various/GrammarToken.h"

#include <libstdhl/File>
#include <libstdhl/String>

using namespace libscod;
using namespace CST;

//
//
// Statement
//

Statement::Statement( Node::ID id )
: Node( id )
{
}

//
//
// SkipStatement
//

SkipStatement::SkipStatement( const Token::Ptr& skipToken )
: Statement( Node::ID::SKIP_STATEMENT )
, m_skipToken( skipToken )
{
}

const Token::Ptr& SkipStatement::skipToken( void ) const
{
    return m_skipToken;
}

void SkipStatement::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
//
// BlockStatement
//

BlockStatement::BlockStatement(
    const Token::Ptr& leftBraceToken,
    const Statements::Ptr& statements,
    const Token::Ptr& rightBraceToken )
: Statement( Node::ID::BLOCK_STATEMENT )
, m_leftBraceToken( leftBraceToken )
, m_statements( statements )
, m_rightBraceToken( rightBraceToken )
{
}

const Statements::Ptr& BlockStatement::statements( void ) const
{
    return m_statements;
}

const Token::Ptr& BlockStatement::leftBraceToken( void ) const
{
    return m_leftBraceToken;
}

const Token::Ptr& BlockStatement::rightBraceToken( void ) const
{
    return m_rightBraceToken;
}

void BlockStatement::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
//
// CallStatement
//

CallStatement::CallStatement( const CallExpression::Ptr& target )
: Statement( Node::ID::CALL_STATEMENT )
, m_target( target )
{
}

const CallExpression::Ptr& CallStatement::target( void ) const
{
    return m_target;
}

void CallStatement::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
//
// LetStatement
//

LetStatement::LetStatement(
    const Token::Ptr& letToken,
    const VariableBindings::Ptr& variableBindings,
    const Token::Ptr& inToken,
    const Statement::Ptr& statement )
: Statement( Node::ID::LET_STATEMENT )
, m_letToken( letToken )
, m_variableBindings( variableBindings )
, m_inToken( inToken )
, m_statement( statement )
{
}

const Token::Ptr& LetStatement::letToken( void ) const
{
    return m_letToken;
}

const VariableBindings::Ptr& LetStatement::variableBindings( void ) const
{
    return m_variableBindings;
}

const Token::Ptr& LetStatement::inToken( void ) const
{
    return m_inToken;
}

const Statement::Ptr& LetStatement::statement( void ) const
{
    return m_statement;
}

void LetStatement::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
//
// AssignmentStatement
//

AssignmentStatement::AssignmentStatement(
    const DirectCallExpression::Ptr& target,
    const Token::Ptr& assignmentToken,
    const Expression::Ptr& expression )
: Statement( Node::ID::ASSIGNMENT_STATEMENT )
, m_target( target )
, m_assignmentToken( assignmentToken )
, m_expression( expression )
{
}

const DirectCallExpression::Ptr& AssignmentStatement::target( void ) const
{
    return m_target;
}

const Token::Ptr& AssignmentStatement::assignmentToken( void ) const
{
    return m_assignmentToken;
}

const Expression::Ptr& AssignmentStatement::expression( void ) const
{
    return m_expression;
}

void AssignmentStatement::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
//
// ConditionalStatement
//

ConditionalStatement::ConditionalStatement(
    const Token::Ptr& ifToken,
    const Expression::Ptr& condition,
    const Token::Ptr& thenToken,
    const Statement::Ptr& thenStatement,
    const Token::Ptr& elseToken,
    const Statement::Ptr& elseStatement )
: Statement( Node::ID::CONDITIONAL_STATEMENT )
, m_ifToken( ifToken )
, m_condition( condition )
, m_thenToken( thenToken )
, m_thenStatement( thenStatement )
, m_elseToken( elseToken )
, m_elseStatement( elseStatement )
{
}

const Token::Ptr& ConditionalStatement::ifToken( void ) const
{
    return m_ifToken;
}

const Expression::Ptr& ConditionalStatement::condition( void ) const
{
    return m_condition;
}

const Token::Ptr& ConditionalStatement::thenToken( void ) const
{
    return m_thenToken;
}

const Statement::Ptr& ConditionalStatement::thenStatement( void ) const
{
    return m_thenStatement;
}

const Token::Ptr& ConditionalStatement::elseToken( void ) const
{
    return m_elseToken;
}

const Statement::Ptr& ConditionalStatement::elseStatement( void ) const
{
    return m_elseStatement;
}

void ConditionalStatement::accept( Visitor& visitor )
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
