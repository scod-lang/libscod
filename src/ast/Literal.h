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

#ifndef _LIBSCOD_AST_LITERAL_H_
#define _LIBSCOD_AST_LITERAL_H_

#include <libscod/cst/Literal>

#include <libscod/ast/Expression>

#include <libstdhl/data/type/Boolean>
#include <libstdhl/data/type/Integer>
#include <libstdhl/data/type/Natural>
#include <libstdhl/data/type/String>

namespace libscod
{
    namespace AST
    {
        class Literal : public Expression
        {
          public:
            using Ptr = std::shared_ptr< Literal >;

            explicit Literal( const Node::ID id );
        };

        using Literals = NodeList< Literal >;

        class ValueLiteral final : public Literal
        {
          public:
            using Kind = CST::ValueLiteral::Kind;

            using Ptr = std::shared_ptr< ValueLiteral >;

            explicit ValueLiteral( const libstdhl::Type::Data& value, const Kind kind );

            const libstdhl::Type::Data& value( void ) const;

            Kind kind( void ) const;

            std::string toString( void ) const;

            void accept( Visitor& visitor ) override final;

          private:
            const libstdhl::Type::Data m_value;
            const Kind m_kind;
        };

        class SetLiteral final : public Literal
        {
          public:
            using Ptr = std::shared_ptr< SetLiteral >;

            explicit SetLiteral( const Expressions::Ptr& expressions );

            const Expressions::Ptr& expressions( void ) const;

            void accept( Visitor& visitor ) override final;

          private:
            const Expressions::Ptr m_expressions;
        };

        class ListLiteral final : public Literal
        {
          public:
            using Ptr = std::shared_ptr< ListLiteral >;

            explicit ListLiteral( const Expressions::Ptr& expressions );

            const Expressions::Ptr& expressions( void ) const;

            void accept( Visitor& visitor ) override final;

          private:
            const Expressions::Ptr m_expressions;
        };

        class RangeLiteral final : public Literal
        {
          public:
            using Ptr = std::shared_ptr< RangeLiteral >;

            explicit RangeLiteral( const Expression::Ptr& from, const Expression::Ptr& to );

            const Expression::Ptr& from( void ) const;

            const Expression::Ptr& to( void ) const;

            void accept( Visitor& visitor ) override final;

          private:
            const Expression::Ptr m_from;
            const Expression::Ptr m_to;
        };

        class RecordLiteral final : public Literal
        {
          public:
            using Ptr = std::shared_ptr< RecordLiteral >;

            RecordLiteral( const NamedExpressions::Ptr& namedExpressions );

            const NamedExpressions::Ptr& namedExpressions( void ) const;

            void accept( Visitor& visitor ) override final;

          private:
            const NamedExpressions::Ptr m_namedExpressions;
        };

        class MappingLiteral final : public Literal
        {
          public:
            using Ptr = std::shared_ptr< MappingLiteral >;

            MappingLiteral( const MappedExpressions::Ptr& mappedExpressions );

            const MappedExpressions::Ptr& mappedExpressions( void ) const;

            void accept( Visitor& visitor ) override final;

          private:
            const MappedExpressions::Ptr m_mappedExpressions;
        };

        class ReferenceLiteral final : public Literal
        {
          public:
            using Ptr = std::shared_ptr< ReferenceLiteral >;

            ReferenceLiteral( const IdentifierPath::Ptr& target );

            const IdentifierPath::Ptr& target( void ) const;

            void accept( Visitor& visitor ) override final;

          private:
            const IdentifierPath::Ptr m_target;
        };

        class GrammarLiteral final : public Literal
        {
          public:
            using Ptr = std::shared_ptr< GrammarLiteral >;

            GrammarLiteral( const Expressions::Ptr& expressions );

            const Expressions::Ptr& expressions( void ) const;

            void accept( Visitor& visitor ) override final;

          private:
            const Expressions::Ptr m_expressions;
        };
    }
}

#endif  // _LIBSCOD_AST_LITERAL_H_

//
//  Local variables:
//  mode: c++
//  indent-tabs-mode: nil
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//
