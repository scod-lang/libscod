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

#include "Node.h"

#include <cassert>

using namespace libscod;
using namespace AST;

//
//
// Node
//

Node::Node( Node::ID id )
: m_id( id )
, m_sourceLocation()
{
}

Node::ID Node::id( void ) const
{
    return m_id;
}

void Node::setSourceLocation( const libstdhl::SourceLocation& sourceLocation )
{
    m_sourceLocation = sourceLocation;
}

const libstdhl::SourceLocation& Node::sourceLocation( void ) const
{
    return m_sourceLocation;
}

std::string Node::description( void ) const
{
    switch( m_id )
    {
        case ID::ROOT:
        {
            return "root";
        }

        // definitions
        case ID::MEMORY_DEFINITION:
        {
            return "memory definition";
        }
        case ID::REGISTER_DEFINITION:
        {
            return "register definition";
        }
        case ID::FIELD_DEFINITION:
        {
            return "field definition";
        }
        case ID::FORMAT_DEFINITION:
        {
            return "format definition";
        }
        case ID::BUFFER_DEFINITION:
        {
            return "buffer definition";
        }
        case ID::INSTRUCTION_DEFINITION:
        {
            return "instruction definition";
        }
        case ID::MICRO_PROCESSOR_DEFINITION:
        {
            return "microprocessor definition";
        }
        case ID::CACHE_DEFINITION:
        {
            return "cache definition";
        }
        case ID::INTERCONNECT_DEFINITION:
        {
            return "interconnect definition";
        }
        case ID::OPTION_DEFINITION:
        {
            return "option definition";
        }
        case ID::ENUMERATION_DEFINITION:
        {
            return "enumeration definition";
        }
        case ID::USING_DEFINITION:
        {
            return "using definition";
        }
        case ID::VARIABLE_DEFINITION:
        {
            return "variable definition";
        }

        // options
        case ID::UNRESOLVED_OPTION:
        {
            return "unresolved option";
        }
        case ID::DECODING_OPTION:
        {
            return "decoding option";
        }
        case ID::SYNTAX_OPTION:
        {
            return "syntax option";
        }
        case ID::EXPANSION_OPTION:
        {
            return "expansion option";
        }
        case ID::STAGE_OPTION:
        {
            return "stage option";
        }

        // statements
        case ID::SKIP_STATEMENT:
        {
            return "skip statement";
        }
        case ID::BLOCK_STATEMENT:
        {
            return "block statement";
        }
        case ID::CALL_STATEMENT:
        {
            return "call statement";
        }
        case ID::LET_STATEMENT:
        {
            return "let statement";
        }
        case ID::ASSIGNMENT_STATEMENT:
        {
            return "assignment statement";
        }
        case ID::CONDITIONAL_STATEMENT:
        {
            return "conditional statement";
        }

        // expressions
        case ID::NAMED_EXPRESSION:
        {
            return "named expression";
        }
        case ID::MAPPED_EXPRESSION:
        {
            return "mapped expression";
        }
        case ID::LET_EXPRESSION:
        {
            return "let expression";
        }
        case ID::CONDITIONAL_EXPRESSION:
        {
            return "conditional expression";
        }
        case ID::DIRECT_CALL_EXPRESSION:
        {
            return "direct call expression";
        }
        case ID::METHOD_CALL_EXPRESSION:
        {
            return "method call expression";
        }
        case ID::UNARY_EXPRESSION:
        {
            return "unary expression";
        }
        case ID::BINARY_EXPRESSION:
        {
            return "binary expression";
        }

        // literals
        case ID::VALUE_LITERAL:
        {
            return "value literal";
        }
        case ID::SET_LITERAL:
        {
            return "set literal";
        }
        case ID::LIST_LITERAL:
        {
            return "list literal";
        }
        case ID::RANGE_LITERAL:
        {
            return "range literal";
        }
        case ID::RECORD_LITERAL:
        {
            return "record literal";
        }
        case ID::MAPPING_LITERAL:
        {
            return "mapping literal";
        }
        case ID::REFERENCE_LITERAL:
        {
            return "mapping literal";
        }
        case ID::GRAMMAR_LITERAL:
        {
            return "grammar literal";
        }

        // types
        case ID::UNRESOLVED_TYPE:
        {
            return "unresolved type";
        }
        case ID::BASIC_TYPE:
        {
            return "basic type";
        }
        case ID::PROPERTY_TYPE:
        {
            return "property type";
        }
        case ID::MAPPING_TYPE:
        {
            return "mapping type";
        }

        // other
        case ID::VARIABLE_BINDING:
        {
            return "variable binding";
        }
        case ID::IDENTIFIER:
        {
            return "identifier";
        }
        case ID::IDENTIFIER_PATH:
        {
            return "identifier path";
        }
        case ID::NODE_LIST:
        {
            return "node list";
        }
    }

    assert( !" internal error! " );
    return std::string();
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
