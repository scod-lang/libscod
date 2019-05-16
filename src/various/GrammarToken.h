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
            /*  8 */ MICROPROCESSOR,
            /*  9 */ CACHE,
            /* 10 */ INTERCONNECT,
            /* 11 */ DECODING,
            /* 12 */ SYNTAX,
            /* 13 */ EXPANSION,
            /* 14 */ STAGE,
            /* 15 */ ENUMERATION,
            /* 16 */ USING,
            /* 17 */ SKIP,
            /* 18 */ ABSTRACT,
            /* 19 */ LET,
            /* 20 */ IN,
            /* 21 */ IF,
            /* 22 */ THEN,
            /* 23 */ ELSE,
            /* 24 */ FALSE,
            /* 25 */ TRUE,
            /* 26 */ NOT,
            /* 27 */ AND,
            /* 28 */ OR,
            /* 29 */ XOR,
            /* 30 */ IMPLIES,
            /* 31 */ ARROW,
            /* 32 */ PLUS,
            /* 33 */ CARRYPLUS,
            /* 34 */ MINUS,
            /* 35 */ CARRYMINUS,
            /* 36 */ ASTERIX,
            /* 37 */ LSHIFT,
            /* 38 */ RLSHIFT,
            /* 39 */ RSHIFT,
            /* 40 */ RRSHIFT,
            /* 41 */ EQUAL,
            /* 42 */ NEQUAL,
            /* 43 */ LESSER,
            /* 44 */ LESSEQ,
            /* 45 */ GREATER,
            /* 46 */ GREATEREQ,
            /* 47 */ ASSIGNMENT,
            /* 48 */ MAPS,
            /* 49 */ MARK,
            /* 50 */ COLON,
            /* 51 */ SEMICOLON,
            /* 52 */ NAMESPACE,
            /* 53 */ LPAREN,
            /* 54 */ RPAREN,
            /* 55 */ LSQPAREN,
            /* 56 */ RSQPAREN,
            /* 57 */ LCURPAREN,
            /* 58 */ RCURPAREN,
            /* 59 */ AT,
            /* 60 */ COMMA,
            /* 61 */ DOT,
            /* 62 */ DOTDOT,
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
                case /*  8 */ Token::MICROPROCESSOR:
                {
                    return "microprocessor";
                }
                case /*  9 */ Token::CACHE:
                {
                    return "cache";
                }
                case /* 10 */ Token::INTERCONNECT:
                {
                    return "interconnect";
                }
                case /* 11 */ Token::DECODING:
                {
                    return "decoding";
                }
                case /* 12 */ Token::SYNTAX:
                {
                    return "syntax";
                }
                case /* 13 */ Token::EXPANSION:
                {
                    return "expansion";
                }
                case /* 14 */ Token::STAGE:
                {
                    return "stage";
                }
                case /* 15 */ Token::ENUMERATION:
                {
                    return "enumeration";
                }
                case /* 16 */ Token::USING:
                {
                    return "using";
                }
                case /* 17 */ Token::SKIP:
                {
                    return "skip";
                }
                case /* 18 */ Token::ABSTRACT:
                {
                    return "abstract";
                }
                case /* 19 */ Token::LET:
                {
                    return "let";
                }
                case /* 20 */ Token::IN:
                {
                    return "in";
                }
                case /* 21 */ Token::IF:
                {
                    return "if";
                }
                case /* 22 */ Token::THEN:
                {
                    return "then";
                }
                case /* 23 */ Token::ELSE:
                {
                    return "else";
                }
                case /* 24 */ Token::FALSE:
                {
                    return "false";
                }
                case /* 25 */ Token::TRUE:
                {
                    return "true";
                }
                case /* 26 */ Token::NOT:
                {
                    return "not";
                }
                case /* 27 */ Token::AND:
                {
                    return "and";
                }
                case /* 28 */ Token::OR:
                {
                    return "or";
                }
                case /* 29 */ Token::XOR:
                {
                    return "xor";
                }
                case /* 30 */ Token::IMPLIES:
                {
                    return "implies";
                }
                case /* 31 */ Token::ARROW:
                {
                    return "=>";
                }
                case /* 32 */ Token::PLUS:
                {
                    return "+";
                }
                case /* 33 */ Token::CARRYPLUS:
                {
                    return "(+)";
                }
                case /* 34 */ Token::MINUS:
                {
                    return "-";
                }
                case /* 35 */ Token::CARRYMINUS:
                {
                    return "(-)";
                }
                case /* 36 */ Token::ASTERIX:
                {
                    return "*";
                }
                case /* 37 */ Token::LSHIFT:
                {
                    return "<<";
                }
                case /* 38 */ Token::RLSHIFT:
                {
                    return "(<<)";
                }
                case /* 39 */ Token::RSHIFT:
                {
                    return ">>";
                }
                case /* 40 */ Token::RRSHIFT:
                {
                    return "(>>)";
                }
                case /* 41 */ Token::EQUAL:
                {
                    return "=";
                }
                case /* 42 */ Token::NEQUAL:
                {
                    return "!=";
                }
                case /* 43 */ Token::LESSER:
                {
                    return "<";
                }
                case /* 44 */ Token::LESSEQ:
                {
                    return "<=";
                }
                case /* 45 */ Token::GREATER:
                {
                    return ">";
                }
                case /* 46 */ Token::GREATEREQ:
                {
                    return ">=";
                }
                case /* 47 */ Token::ASSIGNMENT:
                {
                    return ":=";
                }
                case /* 48 */ Token::MAPS:
                {
                    return "->";
                }
                case /* 49 */ Token::MARK:
                {
                    return "'";
                }
                case /* 50 */ Token::COLON:
                {
                    return ":";
                }
                case /* 51 */ Token::SEMICOLON:
                {
                    return ";";
                }
                case /* 52 */ Token::NAMESPACE:
                {
                    return "::";
                }
                case /* 53 */ Token::LPAREN:
                {
                    return "(";
                }
                case /* 54 */ Token::RPAREN:
                {
                    return ")";
                }
                case /* 55 */ Token::LSQPAREN:
                {
                    return "[";
                }
                case /* 56 */ Token::RSQPAREN:
                {
                    return "]";
                }
                case /* 57 */ Token::LCURPAREN:
                {
                    return "{";
                }
                case /* 58 */ Token::RCURPAREN:
                {
                    return "}";
                }
                case /* 59 */ Token::AT:
                {
                    return "@";
                }
                case /* 60 */ Token::COMMA:
                {
                    return ",";
                }
                case /* 61 */ Token::DOT:
                {
                    return ".";
                }
                case /* 62 */ Token::DOTDOT:
                {
                    return "..";
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
