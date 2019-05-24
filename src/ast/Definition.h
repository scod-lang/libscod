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

#ifndef _LIBSCOD_AST_DEFINITION_H_
#define _LIBSCOD_AST_DEFINITION_H_

#include <libscod/cst/Definition>

#include <libscod/ast/Node>

#include <libscod/ast/Literal>
#include <libscod/ast/Option>
#include <libscod/ast/Statement>
#include <libscod/ast/Type>

namespace libscod
{
    namespace AST
    {
        class Definition : public Node
        {
          public:
            using Ptr = std::shared_ptr< Definition >;

            Definition( const Node::ID id, const Identifier::Ptr& identifier );

            const Identifier::Ptr& identifier( void ) const;

          private:
            const Identifier::Ptr m_identifier;
        };

        using Definitions = NodeList< Definition >;

        class FunctionDefinition : public Definition
        {
          public:
            using Ptr = std::shared_ptr< FunctionDefinition >;

            FunctionDefinition(
                const Node::ID id,
                const Identifier::Ptr& identifier,
                const Type::Ptr& mappingType );

            const Type::Ptr& mappingType( void ) const;

          private:
            const Type::Ptr m_mappingType;
        };

        using FunctionDefinitions = NodeList< FunctionDefinition >;

        class MemoryDefinition final : public FunctionDefinition
        {
          public:
            using Ptr = std::shared_ptr< MemoryDefinition >;

            MemoryDefinition( const Identifier::Ptr& identifier, const Type::Ptr& type );

            void accept( Visitor& visitor ) override final;
        };

        class RegisterDefinition final : public FunctionDefinition
        {
          public:
            using Ptr = std::shared_ptr< RegisterDefinition >;

            RegisterDefinition( const Identifier::Ptr& identifier, const Type::Ptr& type );

            void accept( Visitor& visitor ) override final;
        };

        class FieldDefinition final : public FunctionDefinition
        {
          public:
            using Ptr = std::shared_ptr< FieldDefinition >;

            FieldDefinition( const Identifier::Ptr& identifier, const Type::Ptr& type );

            void accept( Visitor& visitor ) override final;
        };

        class FormatDefinition final : public FunctionDefinition
        {
          public:
            using Ptr = std::shared_ptr< FormatDefinition >;

            FormatDefinition(
                const Identifier::Ptr& identifier,
                const Type::Ptr& type,
                const MappingLiteral::Ptr& mapping );

            const MappingLiteral::Ptr& mapping( void ) const;

            void accept( Visitor& visitor ) override final;

          private:
            const MappingLiteral::Ptr m_mapping;
        };

        class BufferDefinition final : public FunctionDefinition
        {
          public:
            using Ptr = std::shared_ptr< BufferDefinition >;

            BufferDefinition(
                const Identifier::Ptr& identifier,
                const Type::Ptr& type,
                const Expression::Ptr& expression );

            const Expression::Ptr& expression( void ) const;

            void accept( Visitor& visitor ) override final;

          private:
            const Expression::Ptr m_expression;
        };

        class OptionDefinition final : public Definition
        {
          public:
            using Kind = CST::OptionDefinition::Kind;

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
                const Identifier::Ptr& identifier,
                const Type::Ptr& type,
                const Statement::Ptr& statement,
                const Options::Ptr& options );

            const Statement::Ptr& statement( void ) const;

            const Options::Ptr& options( void ) const;

            void accept( Visitor& visitor ) override final;

          private:
            const Statement::Ptr m_statement;
            const Options::Ptr m_options;
        };

        class MicroProcessorDefinition final : public Definition
        {
          public:
            using Ptr = std::shared_ptr< MicroProcessorDefinition >;

            MicroProcessorDefinition(
                const Identifier::Ptr& identifier,
                const IdentifierPath::Ptr& programCounter,
                const Statement::Ptr& statement,
                const Options::Ptr& options );

            const IdentifierPath::Ptr& programCounter( void ) const;

            const Statement::Ptr& statement( void ) const;

            const Options::Ptr& options( void ) const;

            void accept( Visitor& visitor ) override final;

          private:
            const IdentifierPath::Ptr m_programCounter;
            const Statement::Ptr m_statement;
            const Options::Ptr m_options;
        };

        class CacheDefinition final : public FunctionDefinition
        {
          public:
            using Ptr = std::shared_ptr< CacheDefinition >;

            CacheDefinition(
                const Identifier::Ptr& identifier,
                const Type::Ptr& type,
                const MappingLiteral::Ptr& connection );

            const MappingLiteral::Ptr& connection( void ) const;

            void accept( Visitor& visitor ) override final;

          private:
            const MappingLiteral::Ptr m_connection;
        };

        class InterconnectDefinition final : public FunctionDefinition
        {
          public:
            using Ptr = std::shared_ptr< InterconnectDefinition >;

            InterconnectDefinition(
                const Identifier::Ptr& identifier,
                const Type::Ptr& type,
                const MappingLiteral::Ptr& connection );

            const MappingLiteral::Ptr& connection( void ) const;

            void accept( Visitor& visitor ) override final;

          private:
            const MappingLiteral::Ptr m_connection;
        };

        class EnumerationDefinition final : public Definition
        {
          public:
            using Ptr = std::shared_ptr< EnumerationDefinition >;

            EnumerationDefinition(
                const Identifier::Ptr& identifier, const SetLiteral::Ptr& enumerators );

            const SetLiteral::Ptr& enumerators( void ) const;

            void accept( Visitor& visitor ) override final;

          private:
            const SetLiteral::Ptr m_enumerators;
        };

        class UsingDefinition final : public Definition
        {
          public:
            using Ptr = std::shared_ptr< UsingDefinition >;

            UsingDefinition( const Identifier::Ptr& identifier, const Type::Ptr& alias );

            const Type::Ptr& alias( void ) const;

            void accept( Visitor& visitor ) override final;

          private:
            const Type::Ptr m_alias;
        };

        class VariableDefinition final : public Definition
        {
          public:
            using Ptr = std::shared_ptr< VariableDefinition >;

            VariableDefinition( const Identifier::Ptr& identifier, const Type::Ptr& variableType );

            const Type::Ptr& variableType( void ) const;

            void accept( Visitor& visitor ) override final;

          private:
            const Type::Ptr m_variableType;
        };

        using VariableDefinitions = NodeList< VariableDefinition >;
    }
}

#endif  // _LIBSCOD_AST_DEFINITION_H_

//
//  Local variables:
//  mode: c++
//  indent-tabs-mode: nil
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//
