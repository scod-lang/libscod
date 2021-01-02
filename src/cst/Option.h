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

#ifndef _LIBSCOD_CST_OPTION_H_
#define _LIBSCOD_CST_OPTION_H_

#include <libscod/cst/Literal>
#include <libscod/cst/Node>
#include <libscod/cst/Statement>
#include <libscod/cst/Token>

namespace libscod
{
    namespace CST
    {
        class Option : public Node
        {
          public:
            using Ptr = std::shared_ptr< Option >;

            Option(
                const Node::ID id, const Token::Ptr& optionToken, const Token::Ptr& equalToken );

            const Token::Ptr& optionToken( void ) const;

            const Token::Ptr& equalToken( void ) const;

          private:
            const Token::Ptr m_optionToken;
            const Token::Ptr m_equalToken;
        };

        using Options = NodeList< Option >;

        class UnresolvedOption final : public Option
        {
          public:
            using Ptr = std::shared_ptr< UnresolvedOption >;

            UnresolvedOption( void );

            void accept( Visitor& visitor ) override final;
        };

        class DecodingOption final : public Option
        {
          public:
            using Ptr = std::shared_ptr< DecodingOption >;

            DecodingOption(
                const Token::Ptr& decodingToken,
                const Token::Ptr& equalToken,
                const RecordLiteral::Ptr& value );

            const RecordLiteral::Ptr& value( void ) const;

            void accept( Visitor& visitor ) override final;

          private:
            const RecordLiteral::Ptr m_value;
        };

        class SyntaxOption final : public Option
        {
          public:
            using Ptr = std::shared_ptr< SyntaxOption >;

            SyntaxOption(
                const Token::Ptr& syntaxToken,
                const Token::Ptr& equalToken,
                const SetLiteral::Ptr& value );

            const SetLiteral::Ptr& value( void ) const;

            void accept( Visitor& visitor ) override final;

          private:
            const SetLiteral::Ptr m_value;
        };

        class ExpansionOption final : public Option
        {
          public:
            using Ptr = std::shared_ptr< ExpansionOption >;

            ExpansionOption(
                const Token::Ptr& expansionToken,
                const Token::Ptr& equalToken,
                const SetLiteral::Ptr& value );

            const SetLiteral::Ptr& value( void ) const;

            void accept( Visitor& visitor ) override final;

          private:
            const SetLiteral::Ptr m_value;
        };

        class StageOption final : public Option
        {
          public:
            using Ptr = std::shared_ptr< StageOption >;

            StageOption(
                const Token::Ptr& stageToken,
                const Identifier::Ptr& identifier,
                const Token::Ptr& equalToken,
                const BlockStatement::Ptr& statement );

            const Identifier::Ptr& identifier( void ) const;

            const BlockStatement::Ptr& statement( void ) const;

            void accept( Visitor& visitor ) override final;

          private:
            const Identifier::Ptr m_identifier;
            const BlockStatement::Ptr m_statement;
        };
    }
}

#endif  // _LIBSCOD_CST_OPTION_H_

//
//  Local variables:
//  mode: c++
//  indent-tabs-mode: nil
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//
