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

#ifndef _LIBSCOD_CST_DEFINITION_H_
#define _LIBSCOD_CST_DEFINITION_H_

#include <libscod/cst/Attribute>
#include <libscod/cst/Literal>
#include <libscod/cst/Node>
#include <libscod/cst/Option>
#include <libscod/cst/Statement>
#include <libscod/cst/Token>
#include <libscod/cst/Type>

namespace libscod
{
    namespace CST
    {
        class Definition : public Node
        {
          public:
            using Ptr = std::shared_ptr< Definition >;

            Definition(
                const Node::ID id, const Token::Ptr& token, const Identifier::Ptr& identifier );

            const Token::Ptr& token( void ) const;

            const Identifier::Ptr& identifier( void ) const;

            void setAttributes( const Attributes::Ptr& attributes );
            const Attributes::Ptr& attributes( void ) const;

            void setDelimiterToken( const Token::Ptr& delimiterToken );
            const Token::Ptr& delimiterToken( void ) const;

          private:
            const Token::Ptr m_token;
            const Identifier::Ptr m_identifier;
            Attributes::Ptr m_attributes;
            Token::Ptr m_delimiterToken;
        };

        using Definitions = NodeList< Definition >;

        class HeaderDefinition final : public Definition
        {
          public:
            using Ptr = std::shared_ptr< HeaderDefinition >;

            HeaderDefinition( const Token::Ptr& headerToken );

            void accept( Visitor& visitor ) override final;
        };

        class FunctionDefinition : public Definition
        {
          public:
            using Ptr = std::shared_ptr< FunctionDefinition >;

            FunctionDefinition(
                const Node::ID id,
                const Token::Ptr& functionToken,
                const Identifier::Ptr& identifier,
                const Token::Ptr& colonToken,
                const Type::Ptr& mappingType );

            const Type::Ptr& mappingType( void ) const;

            const Token::Ptr& functionToken( void ) const;

            const Token::Ptr& colonToken( void ) const;

          private:
            const Type::Ptr m_mappingType;
            const Token::Ptr m_functionToken;
            const Token::Ptr m_colonToken;
        };

        using FunctionDefinitions = NodeList< FunctionDefinition >;

        class MemoryDefinition final : public FunctionDefinition
        {
          public:
            using Ptr = std::shared_ptr< MemoryDefinition >;

            MemoryDefinition(
                const Token::Ptr& memoryToken,
                const Identifier::Ptr& identifier,
                const Token::Ptr& colonToken,
                const Type::Ptr& type );

            void accept( Visitor& visitor ) override final;
        };

        class RegisterDefinition final : public FunctionDefinition
        {
          public:
            using Ptr = std::shared_ptr< RegisterDefinition >;

            RegisterDefinition(
                const Token::Ptr& registerToken,
                const Identifier::Ptr& identifier,
                const Token::Ptr& colonToken,
                const Type::Ptr& type );

            void accept( Visitor& visitor ) override final;
        };

        class FieldDefinition final : public FunctionDefinition
        {
          public:
            using Ptr = std::shared_ptr< FieldDefinition >;

            FieldDefinition(
                const Token::Ptr& fieldToken,
                const Identifier::Ptr& identifier,
                const Token::Ptr& colonToken,
                const Type::Ptr& type );

            void accept( Visitor& visitor ) override final;
        };

        class FormatDefinition final : public FunctionDefinition
        {
          public:
            using Ptr = std::shared_ptr< FormatDefinition >;

            FormatDefinition(
                const Token::Ptr& formatToken,
                const Identifier::Ptr& identifier,
                const Token::Ptr& colonToken,
                const Type::Ptr& type,
                const Token::Ptr& equalToken,
                const MappingLiteral::Ptr& mapping );

            const Token::Ptr& equalToken( void ) const;

            const MappingLiteral::Ptr& mapping( void ) const;

            void accept( Visitor& visitor ) override final;

          private:
            const Token::Ptr m_equalToken;
            const MappingLiteral::Ptr m_mapping;
        };

        class BufferDefinition final : public FunctionDefinition
        {
          public:
            using Ptr = std::shared_ptr< BufferDefinition >;

            BufferDefinition(
                const Token::Ptr& bufferToken,
                const Identifier::Ptr& identifier,
                const Token::Ptr& colonToken,
                const Type::Ptr& type,
                const Token::Ptr& equalToken,
                const Expression::Ptr& expression );

            const Token::Ptr& equalToken( void ) const;

            const Expression::Ptr& expression( void ) const;

            void accept( Visitor& visitor ) override final;

          private:
            const Token::Ptr m_equalToken;
            const Expression::Ptr m_expression;
        };

        class OptionDefinition final : public Definition
        {
          public:
            enum class Kind
            {
                DECODING,
                SYNTAX,
                EXPANSION
            };

            using Ptr = std::shared_ptr< OptionDefinition >;

            OptionDefinition(
                const ReferenceLiteral::Ptr& reference,
                const Option::Ptr& option,
                const Kind kind );

            const ReferenceLiteral::Ptr& reference( void ) const;

            const Option::Ptr& option( void ) const;

            const Kind kind( void ) const;

            void accept( Visitor& visitor ) override final;

          private:
            const ReferenceLiteral::Ptr m_reference;
            const Option::Ptr m_option;
            const Kind m_kind;
        };

        using Options = NodeList< Option >;

        class InstructionDefinition final : public FunctionDefinition
        {
          public:
            using Ptr = std::shared_ptr< InstructionDefinition >;

            InstructionDefinition(
                const Token::Ptr& instructionToken,
                const Identifier::Ptr& identifier,
                const Token::Ptr& colonToken,
                const Type::Ptr& type,
                const Token::Ptr& equalToken,
                const Statement::Ptr& statement,
                const Options::Ptr& options );

            const Token::Ptr& equalToken( void ) const;

            const Statement::Ptr& statement( void ) const;

            const Options::Ptr& options( void ) const;

            void accept( Visitor& visitor ) override final;

          private:
            const Token::Ptr m_equalToken;
            const Statement::Ptr m_statement;
            const Options::Ptr m_options;
        };

        class MicroProcessorDefinition final : public Definition
        {
          public:
            using Ptr = std::shared_ptr< MicroProcessorDefinition >;

            MicroProcessorDefinition(
                const Token::Ptr& microProcessorToken,
                const Identifier::Ptr& identifier,
                const Token::Ptr& colonToken,
                const IdentifierPath::Ptr& programCounter,
                const Token::Ptr& equalToken,
                const Statement::Ptr& statement,
                const Options::Ptr& options );

            const Token::Ptr& colonToken( void ) const;

            const IdentifierPath::Ptr& programCounter( void ) const;

            const Token::Ptr& equalToken( void ) const;

            const Statement::Ptr& statement( void ) const;

            const Options::Ptr& options( void ) const;

            void accept( Visitor& visitor ) override final;

          private:
            const Token::Ptr m_colonToken;
            const IdentifierPath::Ptr m_programCounter;
            const Token::Ptr m_equalToken;
            const Statement::Ptr m_statement;
            const Options::Ptr m_options;
        };

        class CacheDefinition final : public FunctionDefinition
        {
          public:
            using Ptr = std::shared_ptr< CacheDefinition >;

            CacheDefinition(
                const Token::Ptr& cacheToken,
                const Identifier::Ptr& identifier,
                const Token::Ptr& colonToken,
                const Type::Ptr& type,
                const Token::Ptr& equalToken,
                const MappingLiteral::Ptr& connection );

            const Token::Ptr& equalToken( void ) const;

            const MappingLiteral::Ptr& connection( void ) const;

            void accept( Visitor& visitor ) override final;

          private:
            const Token::Ptr m_equalToken;
            const MappingLiteral::Ptr m_connection;
        };

        class InterconnectDefinition final : public FunctionDefinition
        {
          public:
            using Ptr = std::shared_ptr< InterconnectDefinition >;

            InterconnectDefinition(
                const Token::Ptr& interconnectToken,
                const Identifier::Ptr& identifier,
                const Token::Ptr& colonToken,
                const Type::Ptr& type,
                const Token::Ptr& equalToken,
                const MappingLiteral::Ptr& connection );

            const Token::Ptr& equalToken( void ) const;

            const MappingLiteral::Ptr& connection( void ) const;

            void accept( Visitor& visitor ) override final;

          private:
            const Token::Ptr m_equalToken;
            const MappingLiteral::Ptr m_connection;
        };

        class EnumerationDefinition final : public Definition
        {
          public:
            using Ptr = std::shared_ptr< EnumerationDefinition >;

            EnumerationDefinition(
                const Token::Ptr& enumerationToken,
                const Identifier::Ptr& identifier,
                const Token::Ptr& equalToken,
                const SetLiteral::Ptr& enumerators );

            const Token::Ptr& equalToken( void ) const;

            const SetLiteral::Ptr& enumerators( void ) const;

            void accept( Visitor& visitor ) override final;

          private:
            const Token::Ptr m_equalToken;
            const SetLiteral::Ptr m_enumerators;
        };

        class UsingDefinition final : public Definition
        {
          public:
            using Ptr = std::shared_ptr< UsingDefinition >;

            UsingDefinition(
                const Token::Ptr& usingToken,
                const Identifier::Ptr& identifier,
                const Token::Ptr& equalToken,
                const Type::Ptr& alias );

            const Token::Ptr& equalToken( void ) const;

            const Type::Ptr& alias( void ) const;

            void accept( Visitor& visitor ) override final;

          private:
            const Token::Ptr m_equalToken;
            const Type::Ptr m_alias;
        };

        class VariableDefinition final : public Definition
        {
          public:
            using Ptr = std::shared_ptr< VariableDefinition >;

            VariableDefinition(
                const Identifier::Ptr& identifier,
                const Token::Ptr& colonToken,
                const Type::Ptr& variableType );

            const Type::Ptr& variableType( void ) const;

            const Token::Ptr& colonToken( void ) const;

            void accept( Visitor& visitor ) override final;

          private:
            const Type::Ptr m_variableType;
            const Token::Ptr m_colonToken;
        };

        using VariableDefinitions = NodeList< VariableDefinition >;
    }
}

#endif  // _LIBSCOD_CST_DEFINITION_H_

//
//  Local variables:
//  mode: c++
//  indent-tabs-mode: nil
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//
