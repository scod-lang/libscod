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

#ifndef _LIBSCOD_NODE_H_
#define _LIBSCOD_NODE_H_

#include <libscod/Scod>
#include <libscod/cst/Visitor>

#include <libstdhl/List>
#include <libstdhl/SourceLocation>

namespace libscod
{
    namespace CST
    {
        /**
         * @extends Scod
         */
        class Node : public std::enable_shared_from_this< Node >
        {
          public:
            enum class ID
            {
                ROOT,

                // definitions
                HEADER_DEFINITION,
                MEMORY_DEFINITION,
                REGISTER_DEFINITION,
                FIELD_DEFINITION,
                FORMAT_DEFINITION,
                BUFFER_DEFINITION,
                INSTRUCTION_DEFINITION,
                OPTION_DEFINITION,
                ENUMERATION_DEFINITION,
                USING_DEFINITION,
                VARIABLE_DEFINITION,

                // options
                UNRESOLVED_OPTION,
                DECODING_OPTION,
                SYNTAX_OPTION,
                EXPANSION_OPTION,

                // statements
                SKIP_STATEMENT,
                BLOCK_STATEMENT,
                LET_STATEMENT,
                ASSIGNMENT_STATEMENT,
                CONDITIONAL_STATEMENT,

                // expressions
                EMBRACED_EXPRESSION,
                NAMED_EXPRESSION,
                MAPPED_EXPRESSION,
                DIRECT_CALL_EXPRESSION,
                UNARY_EXPRESSION,
                BINARY_EXPRESSION,

                // types
                UNRESOLVED_TYPE,
                BASIC_TYPE,
                PROPERTY_TYPE,
                MAPPING_TYPE,

                // literals
                VALUE_LITERAL,
                SET_LITERAL,
                RECORD_LITERAL,
                MAPPING_LITERAL,
                REFERENCE_LITERAL,
                GRAMMAR_LITERAL,

                // attributes
                BASIC_ATTRIBUTE,
                EXPRESSION_ATTRIBUTE,

                // others
                VARIABLE_BINDING,
                IDENTIFIER,
                IDENTIFIER_PATH,
                TOKEN,
                SPAN,
                NODE_LIST,
            };

          public:
            using Ptr = std::shared_ptr< Node >;

            explicit Node( const ID id );
            virtual ~Node( void ) = default;

            ID id( void ) const;

            void setSourceLocation( const libstdhl::SourceLocation& sourceLocation );
            const libstdhl::SourceLocation& sourceLocation( void ) const;

            virtual std::string description( void ) const final;

            template < typename T >
            typename T::Ptr ptr( void )
            {
                return std::static_pointer_cast< T >( shared_from_this() );
            }

            virtual void accept( Visitor& visitor ) = 0;

          private:
            const ID m_id;
            libstdhl::SourceLocation m_sourceLocation;
        };

        template < typename T >
        class NodeList final
        : public Node
        , public libstdhl::List< T >
        {
          public:
            using Ptr = std::shared_ptr< NodeList >;

            explicit NodeList( void )
            : Node( Node::ID::NODE_LIST )
            {
            }

            explicit NodeList( const std::vector< typename T::Ptr >& elements )
            : Node( Node::ID::NODE_LIST )
            , libstdhl::List< T >( elements )
            {
            }

            void accept( Visitor& visitor ) override final
            {
                for( auto& node : *this )
                {
                    node->accept( visitor );
                }
            }
        };

        template < typename T, typename... Args >
        typename T::Ptr make( const libstdhl::SourceLocation& sourceLocation, Args&&... args )
        {
            auto node = std::make_shared< T >( std::forward< Args >( args )... );
            node->setSourceLocation( sourceLocation );
            return node;
        }
    }
}

#endif  // _LIBSCOD_NODE_H_

//
//  Local variables:
//  mode: c++
//  indent-tabs-mode: nil
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//
