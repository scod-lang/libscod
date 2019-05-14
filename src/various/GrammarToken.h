//  
//  Copyright (C) 2019 SCOD Organization <https://scod-lang.org>
//  All rights reserved.
//  
//  Developed by: Philipp Paulweber
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

#ifndef _LIBSCOD_GRAMMAR_TOKEN_H_
#define _LIBSCOD_GRAMMAR_TOKEN_H_

#include <libscod/Scod>

#include <cassert>

namespace libscod
{
    namespace Grammar
    {
        enum class Token : u8
        {
            /*  0 */ UNRESOLVED,
            /*  1 */ SCOD,
            /*  2 */ MEMORY,
            /*  3 */ REGISTER,
            /*  4 */ FIELD,
            /*  5 */ FORMAT,
            /*  6 */ BUFFER,
            /*  7 */ INSTRUCTION,
            /*  8 */ DECODING,
            /*  9 */ SYNTAX,
            /* 10 */ EXPANSION,
            /* 11 */ ENUMERATION,
            /* 12 */ USING,
            /* 13 */ SKIP,
            /* 14 */ ABSTRACT,
            /* 15 */ LET,
            /* 16 */ IN,
            /* 17 */ IF,
            /* 18 */ THEN,
            /* 19 */ ELSE,
            /* 20 */ FALSE,
            /* 21 */ TRUE,
            /* 22 */ NOT,
            /* 23 */ AND,
            /* 24 */ OR,
            /* 25 */ XOR,
            /* 26 */ IMPLIES,
            /* 27 */ ARROW,
            /* 28 */ PLUS,
            /* 29 */ MINUS,
            /* 30 */ ASTERIX,
            /* 31 */ EQUAL,
            /* 32 */ NEQUAL,
            /* 33 */ LESSER,
            /* 34 */ LESSEQ,
            /* 35 */ GREATER,
            /* 36 */ GREATEREQ,
            /* 37 */ ASSIGNMENT,
            /* 38 */ MAPS,
            /* 39 */ MARK,
            /* 40 */ COLON,
            /* 41 */ SEMICOLON,
            /* 42 */ NAMESPACE,
            /* 43 */ LPAREN,
            /* 44 */ RPAREN,
            /* 45 */ LSQPAREN,
            /* 46 */ RSQPAREN,
            /* 47 */ LCURPAREN,
            /* 48 */ RCURPAREN,
            /* 49 */ AT,
            /* 50 */ COMMA,
        };
        
        static std::string tokenAsString( const Token token )
        {
            switch( token )
            {
                case /*  0 */ Token::UNRESOLVED:
                {
                    return "$unresolved$";
                }
                case /*  1 */ Token::SCOD:
                {
                    return "SCOD";
                }
                case /*  2 */ Token::MEMORY:
                {
                    return "memory";
                }
                case /*  3 */ Token::REGISTER:
                {
                    return "register";
                }
                case /*  4 */ Token::FIELD:
                {
                    return "field";
                }
                case /*  5 */ Token::FORMAT:
                {
                    return "format";
                }
                case /*  6 */ Token::BUFFER:
                {
                    return "buffer";
                }
                case /*  7 */ Token::INSTRUCTION:
                {
                    return "instruction";
                }
                case /*  8 */ Token::DECODING:
                {
                    return "decoding";
                }
                case /*  9 */ Token::SYNTAX:
                {
                    return "syntax";
                }
                case /* 10 */ Token::EXPANSION:
                {
                    return "expansion";
                }
                case /* 11 */ Token::ENUMERATION:
                {
                    return "enumeration";
                }
                case /* 12 */ Token::USING:
                {
                    return "using";
                }
                case /* 13 */ Token::SKIP:
                {
                    return "skip";
                }
                case /* 14 */ Token::ABSTRACT:
                {
                    return "abstract";
                }
                case /* 15 */ Token::LET:
                {
                    return "let";
                }
                case /* 16 */ Token::IN:
                {
                    return "in";
                }
                case /* 17 */ Token::IF:
                {
                    return "if";
                }
                case /* 18 */ Token::THEN:
                {
                    return "then";
                }
                case /* 19 */ Token::ELSE:
                {
                    return "else";
                }
                case /* 20 */ Token::FALSE:
                {
                    return "false";
                }
                case /* 21 */ Token::TRUE:
                {
                    return "true";
                }
                case /* 22 */ Token::NOT:
                {
                    return "not";
                }
                case /* 23 */ Token::AND:
                {
                    return "and";
                }
                case /* 24 */ Token::OR:
                {
                    return "or";
                }
                case /* 25 */ Token::XOR:
                {
                    return "xor";
                }
                case /* 26 */ Token::IMPLIES:
                {
                    return "implies";
                }
                case /* 27 */ Token::ARROW:
                {
                    return "=>";
                }
                case /* 28 */ Token::PLUS:
                {
                    return "+";
                }
                case /* 29 */ Token::MINUS:
                {
                    return "-";
                }
                case /* 30 */ Token::ASTERIX:
                {
                    return "*";
                }
                case /* 31 */ Token::EQUAL:
                {
                    return "=";
                }
                case /* 32 */ Token::NEQUAL:
                {
                    return "!=";
                }
                case /* 33 */ Token::LESSER:
                {
                    return "<";
                }
                case /* 34 */ Token::LESSEQ:
                {
                    return "<=";
                }
                case /* 35 */ Token::GREATER:
                {
                    return ">";
                }
                case /* 36 */ Token::GREATEREQ:
                {
                    return ">=";
                }
                case /* 37 */ Token::ASSIGNMENT:
                {
                    return ":=";
                }
                case /* 38 */ Token::MAPS:
                {
                    return "->";
                }
                case /* 39 */ Token::MARK:
                {
                    return "'";
                }
                case /* 40 */ Token::COLON:
                {
                    return ":";
                }
                case /* 41 */ Token::SEMICOLON:
                {
                    return ";";
                }
                case /* 42 */ Token::NAMESPACE:
                {
                    return "::";
                }
                case /* 43 */ Token::LPAREN:
                {
                    return "(";
                }
                case /* 44 */ Token::RPAREN:
                {
                    return ")";
                }
                case /* 45 */ Token::LSQPAREN:
                {
                    return "[";
                }
                case /* 46 */ Token::RSQPAREN:
                {
                    return "]";
                }
                case /* 47 */ Token::LCURPAREN:
                {
                    return "{";
                }
                case /* 48 */ Token::RCURPAREN:
                {
                    return "}";
                }
                case /* 49 */ Token::AT:
                {
                    return "@";
                }
                case /* 50 */ Token::COMMA:
                {
                    return ",";
                }
            }
            assert( !"internal error" );
            return std::string();
        }
    };
}

#endif  // _LIBSCOD_GRAMMAR_TOKEN_H_

//
//  Local variables:
//  mode: c++
//  indent-tabs-mode: nil
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//
