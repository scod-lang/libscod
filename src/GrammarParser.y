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

%skeleton "lalr1.cc"
%require "3.2"
//%debug

%defines
%define api.namespace {libscod}
%define api.parser.class {Parser}
%define api.token.constructor
%define api.value.type variant
%define api.location.type {libstdhl::SourceLocation}

%define parse.assert
%define parse.trace
%define parse.error verbose

%locations

%code requires
{
    namespace libscod
    {
        class Lexer;
        class Logger;
    }

    #include <libscod/Specification>
    #include <libscod/cst/Root>
    #include <libscod/cst/Attribute>
    #include <libscod/cst/Identifier>
    #include <libscod/cst/Token>
    #include <libscod/cst/Option>
    #include <libscod/cst/Definition>
    #include <libscod/cst/Binding>
    #include <libscod/cst/Statement>
    #include <libscod/cst/Type>
    #include <libscod/Exception>
    #include <libscod/Logger>

    #include <libstdhl/SourceLocation>

    using namespace libscod;
    using namespace CST;

    #define YY_NULLPTR nullptr
}

%parse-param { Logger& m_log }
%parse-param { Lexer& m_lexer }
%parse-param { Specification& m_specification }

%code
{
    #include "../../src/Lexer.h"

    #include <libstdhl/Type>

    #undef yylex
    #define yylex m_lexer.nextToken

//    static ... function( ... )
}


%token
END       0 "end of file"
{{grammartoken}}

%token <ValueLiteral::Ptr> INTEGER     "integer"
%token <ValueLiteral::Ptr> BINARY      "binary"
%token <ValueLiteral::Ptr> HEXADECIMAL "hexadecimal"
%token <ValueLiteral::Ptr> STRING      "string"
%token <Identifier::Ptr>   IDENTIFIER  "identifier"

%type <Specification::Ptr> Specification

// definitions
%type <Definitions::Ptr> Definitions
%type <Definition::Ptr> Definition AttributedDefinition
%type <HeaderDefinition::Ptr> Header
%type <MemoryDefinition::Ptr> MemoryDefinition
%type <RegisterDefinition::Ptr> RegisterDefinition
%type <FieldDefinition::Ptr> FieldDefinition
%type <FormatDefinition::Ptr> FormatDefinition
%type <BufferDefinition::Ptr> BufferDefinition
%type <InstructionDefinition::Ptr> InstructionDefinition
%type <MicroProcessorDefinition::Ptr> MicroProcessorDefinition
%type <CacheDefinition::Ptr> CacheDefinition
%type <InterconnectDefinition::Ptr> InterconnectDefinition
%type <OptionDefinition::Ptr> OptionDefinition
%type <EnumerationDefinition::Ptr> EnumerationDefinition
%type <UsingDefinition::Ptr> UsingDefinition
%type <VariableDefinition::Ptr> Variable TypedVariable AttributedVariable

// options
%type <Options::Ptr> InstructionOptions
%type <Option::Ptr> InstructionOption
%type <DecodingOption::Ptr> DecodingOption
%type <SyntaxOption::Ptr> SyntaxOption
%type <ExpansionOption::Ptr> ExpansionOption
%type <Options::Ptr> MicroProcessorOptions
%type <Option::Ptr> MicroProcessorOption
%type <StageOption::Ptr> StageOption

// statements
%type <Statements::Ptr> Statements
%type <Statement::Ptr> Statement // AttributedStatement
%type <SkipStatement::Ptr> SkipStatement AbstractStatement
%type <BlockStatement::Ptr> BlockStatement
%type <CallStatement::Ptr> CallStatement
%type <LetStatement::Ptr> LetStatement
%type <AssignmentStatement::Ptr> AssignmentStatement
%type <ConditionalStatement::Ptr> ConditionalStatement

// expressions
%type <Expressions::Ptr> Terms Terminals
%type <Expression::Ptr> Term Expression OperatorExpression Terminal
%type <LetExpression::Ptr> LetExpression
%type <ConditionalExpression::Ptr> ConditionalExpression
%type <NamedExpression::Ptr> Assignment
%type <NamedExpressions::Ptr> Assignments
%type <MappedExpression::Ptr> Mapping
%type <MappedExpressions::Ptr> Mappings
%type <CallExpression::Ptr> CallExpression
%type <DirectCallExpression::Ptr> DirectCallExpression
%type <MethodCallExpression::Ptr> MethodCallExpression

// literals
%type <Literal::Ptr> Literal
%type <ValueLiteral::Ptr> BooleanLiteral IntegerLiteral BinaryLiteral StringLiteral
%type <SetLiteral::Ptr> SetLiteral Enumerators
%type <ListLiteral::Ptr> ListLiteral
%type <RangeLiteral::Ptr> RangeLiteral
%type <RecordLiteral::Ptr> RecordLiteral
%type <MappingLiteral::Ptr> MappingLiteral FormatFields
%type <ReferenceLiteral::Ptr> ReferenceLiteral
%type <GrammarLiteral::Ptr> GrammarLiteral

// types
%type <libscod::CST::Type::Ptr> Type BasicType PropertyType
%type <Types::Ptr> ArgumentTypes // Types
%type <MappingType::Ptr> MappingType

// attributes
%type <Attribute::Ptr> Attribute
%type <Attributes::Ptr> Attributes
%type <BasicAttribute::Ptr> BasicAttribute
%type <ExpressionAttribute::Ptr> ExpressionAttribute

// other
%type <VariableBinding::Ptr> VariableBinding
%type <VariableBindings::Ptr> VariableBindings


%type <Identifier::Ptr> Identifier
%type <IdentifierPath::Ptr> IdentifierPath


%start Specification

// prefer basic types over the other types
// %precedence BASIC_TYPE

%precedence IN
// %precedence DO

%precedence THEN
%precedence ELSE

// %precedence CALL
// %precedence ASSIGNMENT

%left IMPLIES ARROW
%left OR
%left XOR
%left AND

%left EQUAL NEQUAL
%left GREATEREQ LESSEQ GREATER LESSER

%left LSHIFT RSHIFT RLSHIFT RRSHIFT
%left PLUS MINUS CARRYPLUS CARRYMINUS
%left ASTERIX // SLASH // PERCENT 
// %left CARET

%precedence DOT
// %precedence UPLUS UMINUS
%precedence NOT

// prefer calls with args (starts with LPAREN) over calls without args
// %precedence CALL_WITHOUT_ARGS
// %precedence LPAREN

// prefer fixed sized types over composed types (start with LESSER) over basic types
// %precedence MARK

%%


Specification
: Header Definitions
  {
      const auto& cst = CST::make< CST::Root >(
          @$, $1, $2, m_lexer.fetchSpansAndReset() );
      m_specification.setCst( cst );
  }
;


Header
: Attributes SCOD
 {
     auto definition = CST::make< HeaderDefinition >( @$, $2 );
     definition->setAttributes( $1 );
     $$ = definition;
 }
| SCOD
  {
      $$ = CST::make< HeaderDefinition >( @$, $1 );
  }
;


Definitions
: Definitions AttributedDefinition
  {
      auto definitions = $1;
      definitions->add( $2 );
      $$ = definitions;
  }
| AttributedDefinition
  {
      auto definitions = CST::make< Definitions >( @$ );
      definitions->add( $1 );
      $$ = definitions;
  }
;


AttributedDefinition
: Attributes Definition
  {
      auto definition = $2;
      definition->setAttributes( $1 );
      $$ = definition;
  }
| Definition
  {
      $$ = $1;
  }
| error // error recovery
  {
      $$ = nullptr;
  }
;


Definition
: MemoryDefinition
  {
      $$ = $1;
  }
| RegisterDefinition
  {
      $$ = $1;
  }
| FieldDefinition
  {
      $$ = $1;
  }
| FormatDefinition
  {
      $$ = $1;
  }
| BufferDefinition
  {
      $$ = $1;
  }
| InstructionDefinition
  {
      $$ = $1;
  }
| MicroProcessorDefinition
  {
      $$ = $1;
  }
| CacheDefinition
  {
      $$ = $1;
  }
| InterconnectDefinition
  {
      $$ = $1;
  }
| OptionDefinition
  {
      $$ = $1;
  }
| EnumerationDefinition
  {
      $$ = $1;
  }
| UsingDefinition
  {
      $$ = $1;
  }
;


MemoryDefinition
: MEMORY Identifier COLON MappingType
  {
      $$ = CST::make< MemoryDefinition >( @$, $1, $2, $3, $4 );
  }
;


RegisterDefinition
: REGISTER Identifier COLON Type
  {
      $$ = CST::make< RegisterDefinition >( @$, $1, $2, $3, $4 );
  }
;


FieldDefinition
: FIELD Identifier COLON Type
  {
      $$ = CST::make< FieldDefinition >( @$, $1, $2, $3, $4 );
  }
;


FormatDefinition
: FORMAT Identifier COLON BasicType EQUAL FormatFields
  {
      $$ = CST::make< FormatDefinition >( @$, $1, $2, $3, $4, $5, $6 );
  }
;

FormatFields
: MappingLiteral
{
    // TODO: check mapping types here or later in validation
    $$ = $1;
}


BufferDefinition
: BUFFER Identifier COLON Type EQUAL Term
  {
      $$ = CST::make< BufferDefinition >( @$, $1, $2, $3, $4, $5, $6 );      
  }
;


InstructionDefinition
: INSTRUCTION Identifier COLON BasicType EQUAL Statement
  {
      const auto& options = CST::make< Options >( @$ );
      $$ = CST::make< InstructionDefinition >( @$, $1, $2, $3, $4, $5, $6, options );
  }
| INSTRUCTION Identifier COLON BasicType EQUAL Statement InstructionOptions
  {
      $$ = CST::make< InstructionDefinition >( @$, $1, $2, $3, $4, $5, $6, $7 );
  }
;


MicroProcessorDefinition
: MICROPROCESSOR Identifier COLON IdentifierPath EQUAL Statement
  {
      const auto& options = CST::make< Options >( @$ );
      $$ = CST::make< MicroProcessorDefinition >( @$, $1, $2, $3, $4, $5, $6, options );
  }
| MICROPROCESSOR Identifier COLON IdentifierPath EQUAL Statement MicroProcessorOptions
  {
      $$ = CST::make< MicroProcessorDefinition >( @$, $1, $2, $3, $4, $5, $6, $7 );
  }
;


CacheDefinition
: CACHE Identifier COLON Type EQUAL MappingLiteral
  {
      $$ = CST::make< CacheDefinition >( @$, $1, $2, $3, $4, $5, $6 );
  }
;


InterconnectDefinition
: INTERCONNECT Identifier COLON Type EQUAL MappingLiteral
  {
      $$ = CST::make< InterconnectDefinition >( @$, $1, $2, $3, $4, $5, $6 );
  }
;


OptionDefinition
: ReferenceLiteral DecodingOption
  {
      $$ = CST::make< OptionDefinition >( @$, $1, $2, OptionDefinition::Kind::DECODING );
  }
| ReferenceLiteral SyntaxOption
  {
      $$ = CST::make< OptionDefinition >( @$, $1, $2, OptionDefinition::Kind::SYNTAX );
  }
| ReferenceLiteral ExpansionOption
  {
      $$ = CST::make< OptionDefinition >( @$, $1, $2, OptionDefinition::Kind::EXPANSION );
  }
;


EnumerationDefinition
: ENUMERATION Identifier EQUAL Enumerators
  {
      $$ = CST::make< EnumerationDefinition >( @$, $1, $2, $3, $4 );
  }
;

Enumerators
: SetLiteral
  {
      // TODO: add check if identifiers here or later in validation pass
      $$ = $1;
  }
;


UsingDefinition
: USING Identifier EQUAL Type
  {
      $$ = CST::make< UsingDefinition >( @$, $1, $2, $3, $4 );
  }
;

//
//
// Options
//

InstructionOptions
: InstructionOptions InstructionOption
  {
      const auto& options = $1;
      options->add( $2 );
      $$ = options;
  }
| InstructionOption
  {
      const auto& options = CST::make< Options >( @$ );
      options->add( $1 );
      $$ = options;
  }
;


InstructionOption
: DecodingOption
  {
      $$ = $1;
  }
| SyntaxOption
  {
      $$ = $1;
  }
| ExpansionOption
  {
      $$ = $1;
  }
;


DecodingOption
: DECODING EQUAL RecordLiteral
  {
      $$ = CST::make< DecodingOption >( @$, $1, $2, $3 );      
  }
;


SyntaxOption
: SYNTAX EQUAL SetLiteral
  {
      $$ = CST::make< SyntaxOption >( @$, $1, $2, $3 );      
  }
;


ExpansionOption
: EXPANSION EQUAL SetLiteral
  {
      $$ = CST::make< ExpansionOption >( @$, $1, $2, $3 );      
  }
;


MicroProcessorOptions
: MicroProcessorOptions MicroProcessorOption
  {
      const auto& options = $1;
      options->add( $2 );
      $$ = options;
  }
| MicroProcessorOption
  {
      const auto& options = CST::make< Options >( @$ );
      options->add( $1 );
      $$ = options;
  }
;


MicroProcessorOption
: StageOption
  {
      $$ = $1;
  }
;


StageOption
: STAGE Identifier EQUAL BlockStatement
  {
      $$ = CST::make< StageOption >( @$, $1, $2, $3, $4 );
  }
;

//
//
// Statements
//

Statements
: Statements Statement
  {
      const auto& statements = $1;
      statements->add( $2 );
      $$ = statements;
  }
| Statement
  {
      const auto& statements = CST::make< Statements >( @$ );
      statements->add( $1 );
      $$ = statements;
  }
;


Statement
: SkipStatement
  {
      $$ = $1;
  }
| AbstractStatement
  {
      $$ = $1;
  }
| BlockStatement
  {
      $$ = $1;
  }
| CallStatement
  {
      $$ = $1;
  }
| LetStatement
  {
      $$ = $1;
  }
| AssignmentStatement
  {
      $$ = $1;
  }
| ConditionalStatement
  {
      $$ = $1;
  }
;


SkipStatement
: SKIP
  {
      $$ = CST::make< SkipStatement >( @$, $1 );
  }
;


AbstractStatement
: ABSTRACT
  {
      // maybe introduce exclusive CST node!
      $$ = CST::make< SkipStatement >( @$, $1 );
  }
;


BlockStatement
: LCURPAREN Statements RCURPAREN
  {
      $$ = CST::make< BlockStatement >( @$, $1, $2, $3 );
  }
| LCURPAREN error RCURPAREN // error recovery
  {
      $$ = nullptr;
      yyerrok;
  }
;


CallStatement
: DirectCallExpression
  {
      $$ = CST::make< CallStatement >( @$, $1 );
  }
;


LetStatement
: LET VariableBindings IN Statement
  {
      $$ = CST::make< LetStatement >( @$, $1, $2, $3, $4 );
  }
;


AssignmentStatement
: DirectCallExpression ASSIGNMENT Term
  {
      $$ = CST::make< AssignmentStatement >( @$, $1, $2, $3 );
  }
;


ConditionalStatement
: IF Term THEN Statement
  {
      const auto& elseStatement = CST::make< SkipStatement >( @$, Token::unresolved() );
      $$ = CST::make< ConditionalStatement >( @$, $1, $2, $3, $4, Token::unresolved(), elseStatement );
  }
| IF Term THEN Statement ELSE Statement
  {
      $$ = CST::make< ConditionalStatement >( @$, $1, $2, $3, $4, $5, $6 );
  }
;

// 
//
// Terms
//

Terms
: Terms COMMA Term
  {
      const auto& expressions = $1;
      $3->setDelimiterToken( $2 );
      expressions->add( $3 );
      $$ = expressions;
  }
| Term
  {
      const auto& expressions = CST::make< Expressions >( @$ );
      expressions->add( $1 );
      $$ = expressions;
  }
;


Term
: Expression
  {
     $$ = $1;
  }
| LetExpression
  {
      $$ = $1;
  }
| ConditionalExpression
  {
      $$ = $1;
  }
| OperatorExpression
  {
      $$ = $1;
  }
;


Expression
: LPAREN Term RPAREN
  {
      $$ = CST::make< CST::EmbracedExpression >( @$, $1, $2, $3 );
  }
| CallExpression // %prec CALL
  {
      $$ = $1;
  }
| Literal
  {
      $$ = $1;
  }
| PLUS Term // %prec UPLUS
 {
     $$ = CST::make< UnaryExpression >( @$, $1, $2 );
 }
| MINUS Term // %prec UMINUS
 {
     $$ = CST::make< UnaryExpression >( @$, $1, $2 );
 }
;


LetExpression
: LET VariableBindings IN Term
  {
      $$ = CST::make< LetExpression >( @$, $1, $2, $3, $4 );
  }
;


ConditionalExpression
: IF Term THEN Expression ELSE Expression
  {
      $$ = CST::make< ConditionalExpression >( @$, $1, $2, $3, $4, $5, $6 );
  }
;


//
// Operator Expression
//

OperatorExpression
: NOT Term
  {
      $$ = CST::make< UnaryExpression >( @$, $1, $2 );
  }
| Term AND Term
  {
      $$ = CST::make< BinaryExpression >( @$, $1, $2, $3 );
  }
| Term OR Term
  {
      $$ = CST::make< BinaryExpression >( @$, $1, $2, $3 );
  }
| Term XOR Term
  {
      $$ = CST::make< BinaryExpression >( @$, $1, $2, $3 );
  }
| Term IMPLIES Term
  {
      $$ = CST::make< BinaryExpression >( @$, $1, $2, $3 );
  }
| Term ARROW Term
  {
      // equivalent to 'implies'
      $$ = CST::make< BinaryExpression >( @$, $1, $2, $3 );
  }
| Term PLUS Term
  {
      $$ = CST::make< BinaryExpression >( @$, $1, $2, $3 );
  }
| Term CARRYPLUS Term
  {
      $$ = CST::make< BinaryExpression >( @$, $1, $2, $3 );
  }
| Term MINUS Term
  {
      $$ = CST::make< BinaryExpression >( @$, $1, $2, $3 );
  }
| Term CARRYMINUS Term
  {
      $$ = CST::make< BinaryExpression >( @$, $1, $2, $3 );
  }
| Term ASTERIX Term
  {
      $$ = CST::make< BinaryExpression >( @$, $1, $2, $3 );
  }
| Term LSHIFT Term
  {
      $$ = CST::make< BinaryExpression >( @$, $1, $2, $3 );
  }
| Term RLSHIFT Term
  {
      $$ = CST::make< BinaryExpression >( @$, $1, $2, $3 );
  }
| Term RSHIFT Term
  {
      $$ = CST::make< BinaryExpression >( @$, $1, $2, $3 );
  }
| Term RRSHIFT Term
  {
      $$ = CST::make< BinaryExpression >( @$, $1, $2, $3 );
  }
| Term EQUAL Term
  {
      $$ = CST::make< BinaryExpression >( @$, $1, $2, $3 );
  }
| Term NEQUAL Term
  {
      $$ = CST::make< BinaryExpression >( @$, $1, $2, $3 );
  }
| Term LESSER Term
  {
      $$ = CST::make< BinaryExpression >( @$, $1, $2, $3 );
  }
| Term LESSEQ Term
  {
      $$ = CST::make< BinaryExpression >( @$, $1, $2, $3 );
  }
| Term GREATER Term
  {
      $$ = CST::make< BinaryExpression >( @$, $1, $2, $3 );
  }
| Term GREATEREQ Term
  {
      $$ = CST::make< BinaryExpression >( @$, $1, $2, $3 );
  }
;


CallExpression
: DirectCallExpression
  {
      $$ = $1;
  }
| MethodCallExpression
  {
      $$ = $1;
  }
;


DirectCallExpression
: IdentifierPath // %prec CALL_WITHOUT_ARGS
  {
      const auto& arguments = CST::make< Expressions >( @$ );
      $$ = CST::make< DirectCallExpression >( @$, $1, Token::unresolved(), arguments, Token::unresolved() );
  }
| IdentifierPath LPAREN RPAREN
  {
      const auto& arguments = CST::make< Expressions >( @$ );
      $$ = CST::make< DirectCallExpression >( @$, $1, Token::unresolved(), arguments, Token::unresolved() );
  }
| IdentifierPath LPAREN Terms RPAREN
  {
      $$ = CST::make< DirectCallExpression >( @$, $1, Token::unresolved(), $3, Token::unresolved() );
  }
| IdentifierPath LPAREN error RPAREN // error recovery
  {
      $$ = nullptr;
  }
;


MethodCallExpression
: Expression DOT Identifier // %prec CALL_WITHOUT_ARGS
  {
      const auto& arguments = CST::make< Expressions >( @$ );
      $$ = CST::make< MethodCallExpression >( @$, $1, $2, $3, Token::unresolved(), arguments, Token::unresolved() );
  }
| Expression DOT Identifier LPAREN RPAREN
  {
      const auto& arguments = CST::make< Expressions >( @$ );
      $$ = CST::make< MethodCallExpression >( @$, $1, $2, $3, Token::unresolved(), arguments, Token::unresolved() );
  }
| Expression DOT Identifier LPAREN Terms RPAREN
  {
      $$ = CST::make< MethodCallExpression >( @$, $1, $2, $3, Token::unresolved(), $5, Token::unresolved() );
  }
| Expression DOT Identifier LPAREN error RPAREN // error recovery
  {
      $$ = nullptr;
  }
;

//
//
// Literals
//

Literal
: BooleanLiteral
  {
      $$ = $1;
  }
| IntegerLiteral
  {
      $$ = $1;
  }
| BinaryLiteral
  {
      $$ = $1;
  }
| StringLiteral
  {
      $$ = $1;
  }
| SetLiteral
  {
      $$ = $1;
  }
| ListLiteral
  {
      $$ = $1;
  }
| RangeLiteral
  {
      $$ = $1;
  }
| RecordLiteral
  {
      $$ = $1;
  }
| MappingLiteral
  {
      $$ = $1;
  }
| ReferenceLiteral
  {
      $$ = $1;
  }
| GrammarLiteral
  {
      $$ = $1;
  }
;


BooleanLiteral
: TRUE
  {
      const auto& value = libstdhl::Type::createBoolean( true );
      $$ = CST::make< ValueLiteral >( @$, value, ValueLiteral::Kind::BOOLEAN );
      $$->setSpans( $1->spans() );
  }
| FALSE
  {
      const auto& value = libstdhl::Type::createBoolean( false );
      $$ = CST::make< ValueLiteral >( @$, value, ValueLiteral::Kind::BOOLEAN );
      $$->setSpans( $1->spans() );
  }
;


IntegerLiteral
: INTEGER
  {
      $$ = $1;
  }
;


BinaryLiteral
: BINARY
  {
      $$ = $1;
  }
| HEXADECIMAL
  {
      $$ = $1;
  }
;


StringLiteral
: STRING
  {
      $$ = $1;
  }
;


SetLiteral
: LCURPAREN Terms RCURPAREN
  {
      $$ = CST::make< SetLiteral >( @$, $2 );
      $$->setLeftBracket( $1 );
      $$->setRightBracket( $3 );
  }
;


ListLiteral
: LSQPAREN Terms RSQPAREN
  {
      $$ = CST::make< ListLiteral >( @$, $2 );
      $$->setLeftBracket( $1 );
      $$->setRightBracket( $3 );
  }
;


RangeLiteral
: LSQPAREN Term DOTDOT Term RSQPAREN
  {
      $$ = CST::make< RangeLiteral >( @$, $2, $3, $4 );
      $$->setLeftBracket( $1 );
      $$->setRightBracket( $5 );
  }
;


RecordLiteral
: LCURPAREN Assignments RCURPAREN
  {
      $$ = CST::make< RecordLiteral >( @$, $2 );
      $$->setLeftBracket( $1 );
      $$->setRightBracket( $3 );
  }
;

Assignments
: Assignments COMMA Assignment
  {
      auto assignments = $1;
      $3->setDelimiterToken( $2 );
      assignments->add( $3 );
      $$ = assignments;
  }
| Assignment
  {
      auto assignments = CST::make< NamedExpressions >( @$ );
      assignments->add( $1 );
      $$ = assignments;
  }
;

Assignment
: Identifier COLON Term
  {
      $$ = CST::make< NamedExpression >( @$, $1, $2, $3 );
  }
;


MappingLiteral
: LCURPAREN Mappings RCURPAREN
  {
      $$ = CST::make< MappingLiteral >( @$, $2 );
      $$->setLeftBracket( $1 );
      $$->setRightBracket( $3 );
  }
;

Mappings
: Mappings COMMA Mapping
  {
      auto mappings = $1;
      $3->setDelimiterToken( $2 );
      mappings->add( $3 );
      $$ = mappings;
  }
| Mapping
  {
      auto mappings = CST::make< MappedExpressions >( @$ );
      mappings->add( $1 );
      $$ = mappings;
  }
;

Mapping
: Term MAPS Term
  {
      const auto& expressions = CST::make< Expressions >( @1 );
      expressions->add( $1 );
      $$ = CST::make< MappedExpression >( @$, Token::unresolved(), expressions, Token::unresolved(), $2, $3 );
  }
| LPAREN Terms RPAREN MAPS Term
  {
      $$ = CST::make< MappedExpression >( @$, $1, $2, $3, $4, $5 );
  }
;


ReferenceLiteral
: AT IdentifierPath
  {
      $$ = CST::make< ReferenceLiteral >( @$, $1, $2 );
  }
;


GrammarLiteral
: NAMESPACE Terminals SEMICOLON
  {
      $$ = CST::make< GrammarLiteral >( @$, $2 );
      $$->setLeftBracket( $1 );
  }
;


Terminals
: Terminals Terminal
  {
      auto terminals = $1;
      terminals->add( $2 );
      $$ = terminals;
  }
| Terminal
  {
      auto terminals = CST::make< Expressions >( @$ );
      terminals->add( $1 );
      $$ = terminals;
  }
;


Terminal
: DirectCallExpression
  {
      $$ = $1;
  }
| IntegerLiteral
  {
      $$ = $1;
  }
| BinaryLiteral
  {
      $$ = $1;
  }
| StringLiteral
  {
      $$ = $1;
  }
| ReferenceLiteral
  {
      $$ = $1;
  }
;


//
//
// Types
//

// Types
// : Types COMMA Type
//   {
//       auto types = $1;
//       $3->setDelimiterToken( $2 );
//       types->add( $3 );
//       $$ = types;
//   }
// | Type
//   {
//       auto types = CST::make< Types >( @$ );
//       types->add( $1 );
//       $$ = types;
//   }
// ;


Type
: BasicType
  {
      $$ = $1;
  }
| MappingType
  {
      $$ = $1;
  }
;


BasicType
: IdentifierPath
  {
      $$ = CST::make< BasicType >( @$, $1 );
  }
| PropertyType
  {
      $$ = $1;
  }
;


PropertyType
: IdentifierPath MARK IntegerLiteral
  {
      $$ = CST::make< PropertyType >( @$, $1, $2, $3 );
  }
;


MappingType
: ArgumentTypes MAPS BasicType
  {
      $$ = CST::make< MappingType >( @$, $1, $2, $3 );
  }
;


ArgumentTypes
: ArgumentTypes ASTERIX BasicType
  {
      auto types = $1;
      $3->setDelimiterToken( $2 );
      types->add( $3 );
      $$ = types;
  }
| Type
  {
      auto types = CST::make< Types >( @$ );
      types->add( $1 );
      $$ = types;
  }
;

//
//
// VariableBindings
//

VariableBindings
: VariableBindings COMMA VariableBinding
  {
      auto variableBindings = $1;
      $3->setDelimiterToken( $2 );
      variableBindings->add( $3 );
      $$ = variableBindings;
  }
| VariableBinding
  {
      auto variableBindings = CST::make< VariableBindings >( @$ );
      variableBindings->add( $1 );
      $$ = variableBindings;
  }
;


VariableBinding
: AttributedVariable EQUAL Term
  {
      $$ = CST::make< VariableBinding >( @$, $1, $2, $3 );
  }
;


AttributedVariable
: Attributes Variable
  {
      auto variable = $2;
      variable->setAttributes( $1 );
      $$ = variable;
  }
| Variable
  {
      $$ = $1;
  }
;


Variable
: TypedVariable
  {
      $$ = $1;
  }
| Identifier
  {
      const auto unresolvedType = CST::make< UnresolvedType >( @$ );
      $$ = CST::make< VariableDefinition >( @$, $1, Token::unresolved(), unresolvedType );
  }
;


TypedVariable
: Identifier COLON Type
  {
      auto variable = CST::make< VariableDefinition >( @$, $1, $2, $3 );
      $$ = variable;
  }
;


//
//
// Identifiers
//

Identifier
: IDENTIFIER
  {
      $$ = $1;
  }
| INSTRUCTION // allow instruction keyword as identifier
  {
      $$ = CST::make< Identifier >( @$, "instruction" );
      $$->setSpans( m_lexer.fetchSpansAndReset() );
  }
| DECODING // allow decoding keyword as identifier
  {
      $$ = CST::make< Identifier >( @$, "decoding" );
      $$->setSpans( m_lexer.fetchSpansAndReset() );
  }
;


IdentifierPath
: IdentifierPath NAMESPACE Identifier
  {
      auto path = $1;
      $3->setNamespaceToken( $2 );
      path->addIdentifier( $3 );
      $$ = path;
  }
| Identifier
  {
      $$ = CST::make< IdentifierPath >( @$, $1 );
  }
;

//
//
// Attributes
//

Attributes
: Attributes Attribute
  {
      auto attributes = $1;
      attributes->add( $2 );
      $$ = attributes;
  }
| Attribute
  {
      auto attributes = CST::make< Attributes >( @$ );
      attributes->add( $1 );
      $$ = attributes;
  }
;

Attribute
: LSQPAREN BasicAttribute RSQPAREN
  {
      auto attribute = $2;
      $2->setLeftBrace( $1 );
      $2->setRightBrace( $3 );
      $$ = attribute;
  }
| LSQPAREN ExpressionAttribute RSQPAREN
  {
      auto attribute = $2;
      $2->setLeftBrace( $1 );
      $2->setRightBrace( $3 );
      $$ = attribute;
  }
| LSQPAREN error RSQPAREN // error recovery
  {
      $$ = nullptr;
  }
;

BasicAttribute
: Identifier
  {
      $$ = CST::make< BasicAttribute >( @$, $1 );
  }
;

ExpressionAttribute
: Identifier Term
  {
      $$ = CST::make< ExpressionAttribute >( @$, $1, $2 );
  }
;

%%

void Parser::error( const libstdhl::SourceLocation& location, const std::string& message )
{
    m_log.error( {location}, message ); //, Code::SyntaxError );
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
