%{
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

// #include <libscod/Codes>
#include <libscod/Logger>
#include <libscod/cst/Span>

#include "various/GrammarToken.h"

#include <libstdhl/SourceLocation>
#include <libstdhl/Type>
#include <libstdhl/Unicode>

using namespace libscod;

#undef YY_DECL
#define YY_DECL Parser::symbol_type Lexer::nextToken()

#define yyterminate() return( Parser::make_END(m_loc) )

// Code run each time a pattern is matched.
#define YY_USER_ACTION m_loc.columns( yyleng );

// Code run each time a token is matched, see GrammarToken.hpp.
#define YY_TOKEN_ACTION( TOKEN ) \
    const auto token = CST::make< CST::Token >( m_loc, Grammar::Token:: TOKEN ); \
    token->setSpans( fetchSpansAndReset() ); \
    return Parser::make_##TOKEN( token, m_loc );

%}

%option c++
%option yyclass="Lexer"
%option prefix="libscod_"
%option noyywrap
%option nodefault
%option nounput
%option noinput
%option batch
/* %option debug */

%x YY_IDENTIFIER
%x YY_INLINE_COMMENT
%x YY_BLOCK_COMMENT
%x YY_STRING

%%
%{
    // Code run each time yylex is called.
    m_loc.step();
%}

[0-9][0-9\']*[0-9]* {
    // INTEGER
    ValueLiteral::Ptr valueLiteral = nullptr;
    try
    {
        const auto value = libstdhl::Type::createInteger( yytext, libstdhl::Type::Radix::DECIMAL );
        valueLiteral = CST::make< ValueLiteral >( m_loc, value, ValueLiteral::Kind::INTEGER );
        valueLiteral->setSpans( fetchSpansAndReset() );
    }
    catch( const std::domain_error& e )
    {
        throw Parser::syntax_error( m_loc, e.what() );
    }
    return Parser::make_INTEGER( valueLiteral, m_loc );
}

0[bB][01][01\']*[01]* {
    // BINARY
    ValueLiteral::Ptr valueLiteral = nullptr;
    try
    {
        const auto value = libstdhl::Type::createInteger( yytext + 2, libstdhl::Type::Radix::BINARY );
        valueLiteral = CST::make< ValueLiteral >( m_loc, value, ValueLiteral::Kind::BINARY );
        valueLiteral->setSpans( fetchSpansAndReset() );
    }
    catch( const std::domain_error& e )
    {
        throw Parser::syntax_error( m_loc, e.what() );
    }
    return Parser::make_BINARY( valueLiteral, m_loc );
}

0[xX][0-9a-fA-F][0-9a-fA-F\']*[0-9a-fA-F]* {
    // HEXADECIMAL
    ValueLiteral::Ptr valueLiteral = nullptr;
    try
    {
        const auto value = libstdhl::Type::createInteger( yytext + 2, libstdhl::Type::Radix::HEXADECIMAL );
        valueLiteral = CST::make< ValueLiteral >( m_loc, value, ValueLiteral::Kind::BINARY );
        valueLiteral->setSpans( fetchSpansAndReset() );
    }
    catch( const std::domain_error& e )
    {
        throw Parser::syntax_error( m_loc, e.what() );
    }
    return Parser::make_HEXADECIMAL( valueLiteral, m_loc );
}

{{grammartoken}}

[a-zA-Z_][a-zA-Z0-9_]* {
    // ASCII identifier characters START
    m_strbuf.clear();
    m_strbuf.append( yytext );

    const auto nextCharacter = yyinput();
    if( nextCharacter )
    {
        unput( nextCharacter );
    }

    if( libstdhl::Unicode::UTF8::byteSequenceLengthIndication( nextCharacter ) > 1 )
    {
        BEGIN( YY_IDENTIFIER );
    }
    else
    {
        const auto identifier = CST::make< Identifier >( m_loc, m_strbuf );
        identifier->setSpans( fetchSpansAndReset() );
        return Parser::make_IDENTIFIER( identifier, m_loc );
    }
}

[\xc0-\xdf]|[\xe0-\xef]|[\xf0-\xf7] {
    // UTF-8 identifier character START
    m_strbuf.clear();
    m_loc.columns( -yyleng );
    unput( yytext[ 0 ] );
    BEGIN( YY_IDENTIFIER );
}

<YY_IDENTIFIER>[\xc0-\xdf][\x80-\xbf]|[\xe0-\xef][\x80-\xbf][\x80-\xbf]|[\xf0-\xf7][\x80-\xbf][\x80-\xbf][\x80-\xbf] {
    // UTF-8 (byte length 2, 3, and 4) character
    m_loc.columns( -yyleng+1 );
    try
    {
        checkUTF8( yytext );
    }
    catch( const std::domain_error& e )
    {
        BEGIN( INITIAL );
        throw Parser::syntax_error( m_loc, e.what() );
    }
    m_strbuf.append( yytext );
}

<YY_IDENTIFIER>[a-zA-Z0-9_] {
    // ASCII characters
    m_strbuf.append( yytext );
}

<YY_IDENTIFIER>\n {
    const auto identifier = CST::make< Identifier >( m_loc, m_strbuf );
    identifier->setSpans( fetchSpansAndReset() );
    const auto token = Parser::make_IDENTIFIER( identifier, m_loc );
    unput( yytext[0] );
    BEGIN( INITIAL );
    return token;
}

<YY_IDENTIFIER>. {
    // invalid identifier character detected, unput and return identifier token
    m_loc.columns( -yyleng );
    unput( yytext[0] );
    BEGIN( INITIAL );
    const auto identifier = CST::make< Identifier >( m_loc, m_strbuf );
    identifier->setSpans( fetchSpansAndReset() );
    return Parser::make_IDENTIFIER( identifier, m_loc );
}

[\x20]+ { // space
    const auto span = CST::make< Span >( m_loc, Grammar::Span::SPACE, yyleng);
    m_spans->add(span);
    m_loc.step();
}

[\r]+ { // carriage return
    m_loc.step();
}

[\t]+ { // tabulator
    const auto span = CST::make< Span >( m_loc, Grammar::Span::TABULATOR, yyleng );
    m_spans->add(span);
    m_loc.step();
}

[\n]+ { // newline
    m_loc.lines( yyleng );
    const auto span = CST::make< Span >( m_loc, Grammar::Span::NEWLINE, yyleng );
    m_spans->add(span);
    m_loc.step();
}

"//" { // single-line comments
    m_strbuf.clear();
    m_strbuf.append( yytext );
    BEGIN( YY_INLINE_COMMENT );
}

<YY_INLINE_COMMENT>(\t|\r|[\x20-\xbf]) {
    // restricted extended ASCII or UTF-8 (byte length 1) character
    m_strbuf.append( yytext );
}

<YY_INLINE_COMMENT>[\xc0-\xdf][\x80-\xbf]|[\xe0-\xef][\x80-\xbf][\x80-\xbf]|[\xf0-\xf7][\x80-\xbf][\x80-\xbf][\x80-\xbf] {
    // UTF-8 (byte length 2, 3, and 4) character
    m_loc.columns( -yyleng+1 );
    m_strbuf.append( yytext );
}

<YY_INLINE_COMMENT>\n {
    m_loc.lines( yyleng );
    m_strbuf.append( yytext );
    const auto firstCharacter = yyinput();
    if( firstCharacter != '/' )
    {
        if( firstCharacter )
        {
            unput( firstCharacter );
        }

        const auto span = CST::make< Span >( m_loc, Grammar::Span::INLINE_COMMENT, m_strbuf.length() );
        m_spans->add( span );
        m_loc.step();
        BEGIN( INITIAL );
    }
    else
    {
        const auto secondCharacter = yyinput();
        if( secondCharacter != '/' )
        {
            unput( secondCharacter );
            unput( firstCharacter );
            const auto span = CST::make< Span >( m_loc, Grammar::Span::INLINE_COMMENT, m_strbuf.length() );
            m_spans->add( span );
            m_loc.step();
            BEGIN( INITIAL );
        }
        else
        {
            m_strbuf.append( std::to_string( firstCharacter ));
            m_strbuf.append( std::to_string( secondCharacter ));
        }
    }
}

<YY_INLINE_COMMENT><<EOF>> {
    const auto span = CST::make< Span >( m_loc, Grammar::Span::INLINE_COMMENT, m_strbuf.length() );
    m_spans->add(span);
    BEGIN( INITIAL );
}

"/*" { // block comments
    m_strbuf.clear();
    m_strbuf.append( yytext );
    BEGIN( YY_BLOCK_COMMENT );
}

<YY_BLOCK_COMMENT>"*/" {
    m_strbuf.append( yytext );
    const auto span = CST::make< Span >( m_loc, Grammar::Span::BLOCK_COMMENT, m_strbuf.length() );
    m_spans->add(span);
    m_loc.step();
    BEGIN( INITIAL );
}

<YY_BLOCK_COMMENT>\n {
    m_strbuf.append( yytext );
    m_loc.lines( yyleng );
}

<YY_BLOCK_COMMENT>(\t|\r|[\x20-\xbf]) {
    // restricted extended ASCII or UTF-8 (byte length 1) character
    m_strbuf.append( yytext );
}

<YY_BLOCK_COMMENT>[\xc0-\xdf][\x80-\xbf]|[\xe0-\xef][\x80-\xbf][\x80-\xbf]|[\xf0-\xf7][\x80-\xbf][\x80-\xbf][\x80-\xbf] {
    // UTF-8 (byte length 2, 3, and 4) character
    m_loc.columns( -yyleng+1 );
    m_strbuf.append( yytext );
}

<YY_BLOCK_COMMENT><<EOF>> {
    m_log.error( {m_loc}, "multiline comment not terminated" );//, Code::SyntaxErrorUnclosedComment );
    BEGIN( INITIAL );
    yyterminate();
}

\" { // strings
    m_strbuf.clear();
    BEGIN( YY_STRING );
}

<YY_STRING>\" {
    BEGIN( INITIAL );
    ValueLiteral::Ptr valueLiteral = nullptr;
    try
    {
        const auto value = libstdhl::Type::createString( m_strbuf );
        valueLiteral = CST::make< ValueLiteral >( m_loc, value, ValueLiteral::Kind::STRING );
        valueLiteral->setSpans( fetchSpansAndReset() );
    }
    catch( const std::domain_error& e )
    {
        throw Parser::syntax_error( m_loc, e.what() );
    }
    return Parser::make_STRING( valueLiteral, m_loc );
}

<YY_STRING>[\x20-\x21]|[\x23-\xbf] {
    // restricted extended ASCII or UTF-8 (byte length 1) character without '"' (0x22)
    m_strbuf.append( yytext );
}

<YY_STRING>[\xc0-\xdf][\x80-\xbf]|[\xe0-\xef][\x80-\xbf][\x80-\xbf]|[\xf0-\xf7][\x80-\xbf][\x80-\xbf][\x80-\xbf] {
    // UTF-8 (byte length 2, 3, and 4) character
    m_loc.columns( -yyleng+1 );
    m_strbuf.append( yytext );
}

<YY_STRING>\n {
    m_loc.lines( yyleng );
}

<YY_STRING>\\n {
    m_strbuf.append( "\n" );
}

<YY_STRING>\\t {
    m_strbuf.append( "\t" );
}

<YY_STRING>\\["\\] {
    m_strbuf.append( yytext + 1 );
}

<YY_STRING>\\. {
    m_log.error( {m_loc}, "unrecognized escape sequence" );//, Code::SyntaxErrorUnrecognizedCharacter );
}

<YY_STRING><<EOF>> {
    m_log.error( {m_loc}, "string not terminated" );//, Code::SyntaxErrorUnclosedString );
    BEGIN( INITIAL );
    yyterminate();
}

. {
    m_log.error( {m_loc}, "unrecognized character '" + std::string( yytext ) + "'" );//, Code::SyntaxErrorUnrecognizedCharacter );
    m_loc.step();
}

%%

//  
//  Local variables:
//  mode: c++
//  indent-tabs-mode: nil
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//  
