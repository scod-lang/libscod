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

#ifndef _LIBSCOD_AST_EXPRESSION_H_
#define _LIBSCOD_AST_EXPRESSION_H_

#include <libscod/ast/Identifier>
#include <libscod/ast/Node>

#include <libscod/cst/Token>

namespace libscod
{
    namespace AST
    {
        class VariableBinding;

        class Expression : public Node
        {
          public:
            using Ptr = std::shared_ptr< Expression >;

            explicit Expression( Node::ID id );
        };

        using Expressions = NodeList< Expression >;

        class NamedExpression final : public Expression
        {
          public:
            using Ptr = std::shared_ptr< NamedExpression >;

            explicit NamedExpression(
                const Identifier::Ptr& identifier, const Expression::Ptr& expression );

            const Identifier::Ptr& identifier( void ) const;

            const Expression::Ptr& expression( void ) const;

            void accept( Visitor& visitor ) override final;

          private:
            const Identifier::Ptr m_identifier;
            const Expression::Ptr m_expression;
        };

        using NamedExpressions = NodeList< NamedExpression >;

        class MappedExpression final : public Expression
        {
          public:
            using Ptr = std::shared_ptr< MappedExpression >;

            explicit MappedExpression(
                const Expressions::Ptr& arguments, const Expression::Ptr& value );

            const Expressions::Ptr& arguments( void ) const;

            const Expression::Ptr& value( void ) const;

            void accept( Visitor& visitor ) override final;

          private:
            const Expressions::Ptr m_arguments;
            const Expression::Ptr m_value;
        };

        using MappedExpressions = NodeList< MappedExpression >;

        class LetExpression final : public Expression
        {
          public:
            using Ptr = std::shared_ptr< LetExpression >;

            explicit LetExpression(
                const std::shared_ptr< VariableBinding >& variableBinding,
                const Expression::Ptr& expression );

            const std::shared_ptr< VariableBinding >& variableBinding( void ) const;

            const Expression::Ptr& expression( void ) const;

            void accept( Visitor& visitor ) override final;

          private:
            const std::shared_ptr< VariableBinding > m_variableBinding;
            const Expression::Ptr m_expression;
        };

        class ConditionalExpression final : public Expression
        {
          public:
            using Ptr = std::shared_ptr< ConditionalExpression >;

            explicit ConditionalExpression(
                const Expression::Ptr& condition,
                const Expression::Ptr& thenExpression,
                const Expression::Ptr& elseExpression );

            const Expression::Ptr& condition( void ) const;

            const Expression::Ptr& thenExpression( void ) const;

            const Expression::Ptr& elseExpression( void ) const;

            void accept( Visitor& visitor ) override final;

          private:
            const Expression::Ptr m_condition;
            const Expression::Ptr m_thenExpression;
            const Expression::Ptr m_elseExpression;
        };

        class CallExpression : public Expression
        {
          public:
            using Ptr = std::shared_ptr< CallExpression >;

            CallExpression( const Node::ID id, const Expressions::Ptr& arguments );

            const Expressions::Ptr& arguments( void ) const;

          private:
            const Expressions::Ptr m_arguments;
        };

        class DirectCallExpression final : public CallExpression
        {
          public:
            using Ptr = std::shared_ptr< DirectCallExpression >;

            DirectCallExpression(
                const IdentifierPath::Ptr& name, const Expressions::Ptr& arguments );

            const IdentifierPath::Ptr& name( void ) const;

            void accept( Visitor& visitor ) override;

          private:
            IdentifierPath::Ptr m_name;
        };

        class MethodCallExpression final : public CallExpression
        {
          public:
            using Ptr = std::shared_ptr< MethodCallExpression >;

            MethodCallExpression(
                const Expression::Ptr& object,
                const Identifier::Ptr& method,
                const Expressions::Ptr& arguments );

            const Expression::Ptr& object( void ) const;

            const Identifier::Ptr& method( void ) const;

            void accept( Visitor& visitor ) override;

          private:
            const Expression::Ptr m_object;
            const Identifier::Ptr m_method;
        };

        class UnaryExpression final : public Expression
        {
          public:
            using Ptr = std::shared_ptr< UnaryExpression >;

            UnaryExpression( const Grammar::Token operation, const Expression::Ptr& expression );

            Grammar::Token operation( void ) const;

            const Expression::Ptr& expression( void ) const;

            void accept( Visitor& visitor ) override final;

          private:
            const Grammar::Token m_operation;
            const Expression::Ptr m_expression;
        };

        class BinaryExpression final : public Expression
        {
          public:
            using Ptr = std::shared_ptr< BinaryExpression >;

            BinaryExpression(
                const Expression::Ptr& leftExpression,
                const Grammar::Token operation,
                const Expression::Ptr& rightExpression );

            const Expression::Ptr& leftExpression( void ) const;

            const Grammar::Token operation( void ) const;

            const Expression::Ptr& rightExpression( void ) const;

            void accept( Visitor& visitor ) override final;

          private:
            const Expression::Ptr m_leftExpression;
            const Grammar::Token m_operation;
            const Expression::Ptr m_rightExpression;
        };
    }
}

#endif  // _LIBSCOD_AST_EXPRESSION_H_

//
//  Local variables:
//  mode: c++
//  indent-tabs-mode: nil
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//
