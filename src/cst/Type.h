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

#ifndef _LIBSCOD_CST_TYPE_H_
#define _LIBSCOD_CST_TYPE_H_

#include <libscod/cst/Expression>
#include <libscod/cst/Identifier>
#include <libscod/cst/Literal>
#include <libscod/cst/Token>

namespace libscod
{
    namespace CST
    {
        // class TypeDefinition;
        // class VariableDefinition;
        // using VariableDefinitions = NodeList< VariableDefinition >;

        class Type : public Node
        {
          public:
            using Ptr = std::shared_ptr< Type >;

            Type( const Node::ID id, const IdentifierPath::Ptr& name );

            const IdentifierPath::Ptr& name( void ) const;

            // void setTypeDefinition( const std::shared_ptr< TypeDefinition >& typeDefinition );

            // const std::shared_ptr< TypeDefinition >& typeDefinition( void ) const;

            void setDelimiterToken( const Token::Ptr& delimiterToken );

            const Token::Ptr& delimiterToken( void ) const;

            virtual std::string signature( void ) const = 0;

            IdentifierPath::Ptr signaturePath( void ) const;

          private:
            const IdentifierPath::Ptr m_name;
            // std::shared_ptr< TypeDefinition > m_typeDefinition;
            Token::Ptr m_delimiterToken;
        };

        using Types = NodeList< Type >;

        class UnresolvedType final : public Type
        {
          public:
            using Ptr = std::shared_ptr< UnresolvedType >;

            explicit UnresolvedType( void );

            std::string signature( void ) const override;

            void accept( Visitor& visitor ) override final;
        };

        class BasicType final : public Type
        {
          public:
            using Ptr = std::shared_ptr< BasicType >;

            explicit BasicType( const IdentifierPath::Ptr& identifier );

            std::string signature( void ) const override;

            void accept( Visitor& visitor ) override final;
        };

        class EmbracedType : public Type
        {
          public:
            using Ptr = std::shared_ptr< EmbracedType >;

            EmbracedType(
                const Node::ID id,
                const IdentifierPath::Ptr& name,
                const Token::Ptr& leftBraceToken,
                const Token::Ptr& rightBraceToken );

            const Token::Ptr& leftBraceToken( void ) const;

            const Token::Ptr& rightBraceToken( void ) const;

          private:
            const Token::Ptr m_leftBraceToken;
            const Token::Ptr m_rightBraceToken;
        };

        // class TupleType final : public EmbracedType
        // {
        //   public:
        //     using Ptr = std::shared_ptr< TupleType >;

        //     TupleType(
        //         const Token::Ptr& leftBraceToken,
        //         const Types::Ptr& subTypes,
        //         const Token::Ptr& rightBraceToken );

        //     const Types::Ptr& subTypes( void ) const;

        //     std::string signature( void ) const override;

        //     void accept( Visitor& visitor ) override final;

        //     Node::Ptr clone( void ) const override final;

        //   private:
        //     const Types::Ptr m_subTypes;
        // };

        // class RecordType final : public EmbracedType
        // {
        //   public:
        //     using Ptr = std::shared_ptr< RecordType >;

        //     RecordType(
        //         const Token::Ptr& leftBraceToken,
        //         const std::shared_ptr< VariableDefinitions >& namedSubTypes,
        //         const Token::Ptr& rightBraceToken );

        //     const std::shared_ptr< VariableDefinitions >& namedSubTypes( void ) const;

        //     std::string signature( void ) const override;

        //     void accept( Visitor& visitor ) override final;

        //     Node::Ptr clone( void ) const override final;

        //   private:
        //     const std::shared_ptr< VariableDefinitions > m_namedSubTypes;
        // };

        // class TemplateType final : public EmbracedType
        // {
        //   public:
        //     using Ptr = std::shared_ptr< TemplateType >;

        //     TemplateType(
        //         const IdentifierPath::Ptr& identifier,
        //         const Token::Ptr& leftBraceToken,
        //         const Types::Ptr& subTypes,
        //         const Token::Ptr& rightBraceToken );

        //     const Types::Ptr& subTypes( void ) const;

        //     void setSubTypes( const Types::Ptr& subTypes );

        //     std::string signature( void ) const override;

        //     void accept( Visitor& visitor ) override final;

        //     Node::Ptr clone( void ) const override final;

        //   private:
        //     Types::Ptr m_subTypes;
        // };

        // class RelationType final : public EmbracedType
        // {
        //   public:
        //     using Ptr = std::shared_ptr< RelationType >;

        //     RelationType(
        //         const IdentifierPath::Ptr& identifier,
        //         const Token::Ptr& leftBraceToken,
        //         const Types::Ptr& argumentTypes,
        //         const Token::Ptr& mapsToken,
        //         const Type::Ptr& returnType,
        //         const Token::Ptr& rightBraceToken );

        //     const Types::Ptr& argumentTypes( void ) const;

        //     const Type::Ptr& returnType( void ) const;

        //     const Token::Ptr& mapsToken( void ) const;

        //     std::string signature( void ) const override;

        //     void accept( Visitor& visitor ) override final;

        //   private:
        //     const Types::Ptr m_argumentTypes;
        //     const Type::Ptr m_returnType;
        //     const Token::Ptr m_mapsToken;
        // };

        class PropertyType final : public Type
        {
          public:
            using Ptr = std::shared_ptr< PropertyType >;

            PropertyType(
                const IdentifierPath::Ptr& identifier,
                const Token::Ptr& markToken,
                const ValueLiteral::Ptr& size );

            const ValueLiteral::Ptr& size( void ) const;

            const Token::Ptr& markToken( void ) const;

            std::string signature( void ) const override;

            void accept( Visitor& visitor ) override final;

          private:
            const ValueLiteral::Ptr m_size;
            const Token::Ptr m_markToken;
        };

        class MappingType final : public Type
        {
          public:
            using Ptr = std::shared_ptr< MappingType >;

            MappingType(
                const Types::Ptr& argumentTypes,
                const Token::Ptr& mapsToken,
                const Type::Ptr& returnType );

            const Types::Ptr& argumentTypes( void ) const;

            const Type::Ptr& returnType( void ) const;

            const Token::Ptr& mapsToken( void ) const;

            std::string signature( void ) const override;

            void accept( Visitor& visitor ) override final;

          private:
            const Types::Ptr m_argumentTypes;
            const Type::Ptr m_returnType;
            const Token::Ptr m_mapsToken;
        };

        // class VaradicType final : public Type
        // {
        //   public:
        //     using Ptr = std::shared_ptr< VaradicType >;

        //     VaradicType( const Identifier::Ptr& identifier, const Token::Ptr& dotdotdotToken );

        //     const Token::Ptr& dotdotdotToken( void ) const;

        //     std::string signature( void ) const override;

        //     void accept( Visitor& visitor ) override final;

        //     Node::Ptr clone( void ) const override final;

        //   private:
        //     const Token::Ptr m_dotdotdotToken;
        // };
    }
}

#endif  // _LIBSCOD_CST_TYPE_H_

//
//  Local variables:
//  mode: c++
//  indent-tabs-mode: nil
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//
