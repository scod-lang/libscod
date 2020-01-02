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

#ifndef _LIBSCOD_CST_STATEMENT_H_
#define _LIBSCOD_CST_STATEMENT_H_

#include <libscod/cst/Binding>
#include <libscod/cst/Node>
#include <libscod/cst/Token>

namespace libscod
{
    namespace CST
    {
        class Statement : public Node
        {
          public:
            using Ptr = std::shared_ptr< Statement >;

            explicit Statement( Node::ID id );
        };

        using Statements = NodeList< Statement >;

        class SkipStatement final : public Statement
        {
          public:
            using Ptr = std::shared_ptr< SkipStatement >;

            explicit SkipStatement( const Token::Ptr& skipToken );

            const Token::Ptr& skipToken( void ) const;

            void accept( Visitor& visitor ) override final;

          private:
            const Token::Ptr m_skipToken;
        };

        class BlockStatement final : public Statement
        {
          public:
            using Ptr = std::shared_ptr< BlockStatement >;

            explicit BlockStatement(
                const Token::Ptr& leftBraceToken,
                const Statements::Ptr& statements,
                const Token::Ptr& rightBraceToken );

            const Statements::Ptr& statements( void ) const;

            const Token::Ptr& leftBraceToken( void ) const;

            const Token::Ptr& rightBraceToken( void ) const;

            void accept( Visitor& visitor ) override final;

          private:
            const Statements::Ptr m_statements;
            const Token::Ptr m_leftBraceToken;
            const Token::Ptr m_rightBraceToken;
        };

        class CallStatement final : public Statement
        {
          public:
            using Ptr = std::shared_ptr< CallStatement >;

            explicit CallStatement( const CallExpression::Ptr& target );

            const CallExpression::Ptr& target( void ) const;

            void accept( Visitor& visitor ) override final;

          private:
            const CallExpression::Ptr m_target;
        };

        class LetStatement final : public Statement
        {
          public:
            using Ptr = std::shared_ptr< LetStatement >;

            explicit LetStatement(
                const Token::Ptr& letToken,
                const VariableBindings::Ptr& variableBindings,
                const Token::Ptr& inToken,
                const Statement::Ptr& statement );

            const Token::Ptr& letToken( void ) const;

            const VariableBindings::Ptr& variableBindings( void ) const;

            const Token::Ptr& inToken( void ) const;

            const Statement::Ptr& statement( void ) const;

            void accept( Visitor& visitor ) override final;

          private:
            const Token::Ptr m_letToken;
            const VariableBindings::Ptr m_variableBindings;
            const Token::Ptr m_inToken;
            const Statement::Ptr m_statement;
        };

        class AssignmentStatement final : public Statement
        {
          public:
            using Ptr = std::shared_ptr< AssignmentStatement >;

            explicit AssignmentStatement(
                const DirectCallExpression::Ptr& target,
                const Token::Ptr& assignmentToken,
                const Expression::Ptr& expression );

            const DirectCallExpression::Ptr& target( void ) const;

            const Token::Ptr& assignmentToken( void ) const;

            const Expression::Ptr& expression( void ) const;

            void accept( Visitor& visitor ) override final;

          private:
            const DirectCallExpression::Ptr m_target;
            const Token::Ptr m_assignmentToken;
            const Expression::Ptr m_expression;
        };

        class ConditionalStatement final : public Statement
        {
          public:
            using Ptr = std::shared_ptr< ConditionalStatement >;

            explicit ConditionalStatement(
                const Token::Ptr& ifToken,
                const Expression::Ptr& condition,
                const Token::Ptr& thenToken,
                const Statement::Ptr& thenStatement,
                const Token::Ptr& elseToken,
                const Statement::Ptr& elseStatement );

            const Token::Ptr& ifToken( void ) const;

            const Expression::Ptr& condition( void ) const;

            const Token::Ptr& thenToken( void ) const;

            const Statement::Ptr& thenStatement( void ) const;

            const Token::Ptr& elseToken( void ) const;

            const Statement::Ptr& elseStatement( void ) const;

            void accept( Visitor& visitor ) override final;

          private:
            const Token::Ptr m_ifToken;
            const Expression::Ptr m_condition;
            const Token::Ptr m_thenToken;
            const Statement::Ptr m_thenStatement;
            const Token::Ptr m_elseToken;
            const Statement::Ptr m_elseStatement;
        };
    }
}

#endif  // _LIBSCOD_CST_STATEMENT_H_

//
//  Local variables:
//  mode: c++
//  indent-tabs-mode: nil
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//
