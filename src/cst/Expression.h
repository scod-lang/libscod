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

#ifndef _LIBSCOD_CST_EXPRESSION_H_
#define _LIBSCOD_CST_EXPRESSION_H_

#include <libscod/cst/Identifier>
#include <libscod/cst/Node>
#include <libscod/cst/Token>

namespace libscod
{
    namespace CST
    {
        // class Type;
        // class Literal;
        // class Definition;
        // class Template;
        // class VariableDefinition;
        // using VariableDefinitions = NodeList< VariableDefinition >;

        class Expression : public Node
        {
          public:
            using Ptr = std::shared_ptr< Expression >;

            explicit Expression( Node::ID id );

            void setDelimiterToken( const Token::Ptr& delimiterToken );
            const Token::Ptr& delimiterToken( void ) const;

          private:
            Token::Ptr m_delimiterToken;
        };

        using Expressions = NodeList< Expression >;

        class EmbracedExpression final : public Expression
        {
          public:
            using Ptr = std::shared_ptr< EmbracedExpression >;

            explicit EmbracedExpression(
                const Token::Ptr& leftBraceToken,
                const Expression::Ptr& expression,
                const Token::Ptr& rightBraceToken );

            const Expression::Ptr& expression( void ) const;

            const Token::Ptr& leftBraceToken( void ) const;

            const Token::Ptr& rightBraceToken( void ) const;

            void accept( Visitor& visitor ) override final;

          private:
            const Expression::Ptr m_expression;
            const Token::Ptr m_leftBraceToken;
            const Token::Ptr m_rightBraceToken;
        };

        class NamedExpression final : public Expression
        {
          public:
            using Ptr = std::shared_ptr< NamedExpression >;

            explicit NamedExpression(
                const Identifier::Ptr& identifier,
                const Token::Ptr& colonToken,
                const Expression::Ptr& expression );

            const Identifier::Ptr& identifier( void ) const;

            const Expression::Ptr& expression( void ) const;

            const Token::Ptr& colonToken( void ) const;

            void accept( Visitor& visitor ) override final;

          private:
            const Identifier::Ptr m_identifier;
            const Expression::Ptr m_expression;
            const Token::Ptr m_colonToken;
        };

        using NamedExpressions = NodeList< NamedExpression >;

        class MappedExpression final : public Expression
        {
          public:
            using Ptr = std::shared_ptr< MappedExpression >;

            explicit MappedExpression(
                const Token::Ptr& leftBracketToken,
                const Expressions::Ptr& arguments,
                const Token::Ptr& rightBracketToken,
                const Token::Ptr& mapsToken,
                const Expression::Ptr& value );

            const Expressions::Ptr& arguments( void ) const;

            const Expression::Ptr& value( void ) const;

            const Token::Ptr& leftBracketToken( void ) const;

            const Token::Ptr& rightBracketToken( void ) const;

            const Token::Ptr& mapsToken( void ) const;

            void accept( Visitor& visitor ) override final;

          private:
            const Expressions::Ptr m_arguments;
            const Expression::Ptr m_value;
            const Token::Ptr m_leftBracketToken;
            const Token::Ptr m_rightBracketToken;
            const Token::Ptr m_mapsToken;
        };

        using MappedExpressions = NodeList< MappedExpression >;

        class CallExpression : public Expression
        {
          public:
            using Ptr = std::shared_ptr< CallExpression >;

            CallExpression(
                const Node::ID id,
                const Token::Ptr& leftBracketToken,
                const Expressions::Ptr& arguments,
                const Token::Ptr& rightBracketToken );

            const Expressions::Ptr& arguments( void ) const;

            const Token::Ptr& leftBracketToken( void ) const;

            const Token::Ptr& rightBracketToken( void ) const;

          private:
            const Expressions::Ptr m_arguments;
            Token::Ptr m_leftBracketToken;
            Token::Ptr m_rightBracketToken;
        };

        class DirectCallExpression final : public CallExpression
        {
          public:
            using Ptr = std::shared_ptr< DirectCallExpression >;

            DirectCallExpression(
                const IdentifierPath::Ptr& name,
                const Token::Ptr& leftBracketToken,
                const Expressions::Ptr& arguments,
                const Token::Ptr& rightBracketToken );

            const IdentifierPath::Ptr& name( void ) const;

            void accept( Visitor& visitor ) override;

          private:
            IdentifierPath::Ptr m_name;
        };

        class UnaryExpression final : public Expression
        {
          public:
            using Ptr = std::shared_ptr< UnaryExpression >;

            UnaryExpression( const Token::Ptr& operationToken, const Expression::Ptr& expression );

            const Token::Ptr& operationToken( void ) const;

            const Expression::Ptr& expression( void ) const;

            void accept( Visitor& visitor ) override final;

          private:
            const Token::Ptr m_operationToken;
            const Expression::Ptr m_expression;
        };

        class BinaryExpression final : public Expression
        {
          public:
            using Ptr = std::shared_ptr< BinaryExpression >;

            BinaryExpression(
                const Expression::Ptr& leftExpression,
                const Token::Ptr& operationToken,
                const Expression::Ptr& rightExpression );

            const Expression::Ptr& leftExpression( void ) const;

            const Token::Ptr& operationToken( void ) const;

            const Expression::Ptr& rightExpression( void ) const;

            void accept( Visitor& visitor ) override final;

          private:
            const Expression::Ptr m_leftExpression;
            const Token::Ptr m_operationToken;
            const Expression::Ptr m_rightExpression;
        };
    }
}

#endif  // _LIBSCOD_CST_EXPRESSION_H_

//
//  Local variables:
//  mode: c++
//  indent-tabs-mode: nil
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//
