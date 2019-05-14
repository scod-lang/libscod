// A Bison parser, made by GNU Bison 3.5.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2019 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "GrammarParser.tab.h"


// Unqualified %code blocks.
#line 93 "../../obj/src/GrammarParser.y"

    #include "../../src/Lexer.h"

    #include <libstdhl/Type>

    #undef yylex
    #define yylex m_lexer.nextToken

//    static ... function( ... )

#line 56 "GrammarParser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 47 "../../obj/src/GrammarParser.y"
namespace libscod {
#line 148 "GrammarParser.cpp"


  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  Parser::Parser (Logger& m_log_yyarg, Lexer& m_lexer_yyarg, Specification& m_specification_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      m_log (m_log_yyarg),
      m_lexer (m_lexer_yyarg),
      m_specification (m_specification_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_number_type
  Parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 86: // AssignmentStatement
        value.YY_MOVE_OR_COPY< AssignmentStatement::Ptr > (YY_MOVE (that.value));
        break;

      case 123: // Attribute
        value.YY_MOVE_OR_COPY< Attribute::Ptr > (YY_MOVE (that.value));
        break;

      case 122: // Attributes
        value.YY_MOVE_OR_COPY< Attributes::Ptr > (YY_MOVE (that.value));
        break;

      case 124: // BasicAttribute
        value.YY_MOVE_OR_COPY< BasicAttribute::Ptr > (YY_MOVE (that.value));
        break;

      case 84: // BlockStatement
        value.YY_MOVE_OR_COPY< BlockStatement::Ptr > (YY_MOVE (that.value));
        break;

      case 69: // BufferDefinition
        value.YY_MOVE_OR_COPY< BufferDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 3: // "SCOD"
      case 4: // "memory"
      case 5: // "register"
      case 6: // "field"
      case 7: // "format"
      case 8: // "buffer"
      case 9: // "instruction"
      case 10: // "decoding"
      case 11: // "syntax"
      case 12: // "expansion"
      case 13: // "enumeration"
      case 14: // "using"
      case 15: // "skip"
      case 16: // "abstract"
      case 17: // "let"
      case 18: // "in"
      case 19: // "if"
      case 20: // "then"
      case 21: // "else"
      case 22: // "false"
      case 23: // "true"
      case 24: // "not"
      case 25: // "and"
      case 26: // "or"
      case 27: // "xor"
      case 28: // "implies"
      case 29: // "=>"
      case 30: // "+"
      case 31: // "-"
      case 32: // "*"
      case 33: // "="
      case 34: // "!="
      case 35: // "<"
      case 36: // "<="
      case 37: // ">"
      case 38: // ">="
      case 39: // ":="
      case 40: // "->"
      case 41: // "'"
      case 42: // ":"
      case 43: // ";"
      case 44: // "::"
      case 45: // "("
      case 46: // ")"
      case 47: // "["
      case 48: // "]"
      case 49: // "{"
      case 50: // "}"
      case 51: // "@"
      case 52: // ","
        value.YY_MOVE_OR_COPY< CST::Token::Ptr > (YY_MOVE (that.value));
        break;

      case 92: // CallExpression
        value.YY_MOVE_OR_COPY< CallExpression::Ptr > (YY_MOVE (that.value));
        break;

      case 87: // ConditionalStatement
        value.YY_MOVE_OR_COPY< ConditionalStatement::Ptr > (YY_MOVE (that.value));
        break;

      case 77: // DecodingOption
        value.YY_MOVE_OR_COPY< DecodingOption::Ptr > (YY_MOVE (that.value));
        break;

      case 62: // AttributedDefinition
      case 63: // Definition
        value.YY_MOVE_OR_COPY< Definition::Ptr > (YY_MOVE (that.value));
        break;

      case 61: // Definitions
        value.YY_MOVE_OR_COPY< Definitions::Ptr > (YY_MOVE (that.value));
        break;

      case 93: // DirectCallExpression
        value.YY_MOVE_OR_COPY< DirectCallExpression::Ptr > (YY_MOVE (that.value));
        break;

      case 72: // EnumerationDefinition
        value.YY_MOVE_OR_COPY< EnumerationDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 79: // ExpansionOption
        value.YY_MOVE_OR_COPY< ExpansionOption::Ptr > (YY_MOVE (that.value));
        break;

      case 89: // Term
      case 90: // Expression
      case 91: // OperatorExpression
      case 109: // Terminal
        value.YY_MOVE_OR_COPY< Expression::Ptr > (YY_MOVE (that.value));
        break;

      case 125: // ExpressionAttribute
        value.YY_MOVE_OR_COPY< ExpressionAttribute::Ptr > (YY_MOVE (that.value));
        break;

      case 88: // Terms
      case 108: // Terminals
        value.YY_MOVE_OR_COPY< Expressions::Ptr > (YY_MOVE (that.value));
        break;

      case 66: // FieldDefinition
        value.YY_MOVE_OR_COPY< FieldDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 67: // FormatDefinition
        value.YY_MOVE_OR_COPY< FormatDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 107: // GrammarLiteral
        value.YY_MOVE_OR_COPY< GrammarLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 60: // Header
        value.YY_MOVE_OR_COPY< HeaderDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 57: // "identifier"
      case 120: // Identifier
        value.YY_MOVE_OR_COPY< Identifier::Ptr > (YY_MOVE (that.value));
        break;

      case 121: // IdentifierPath
        value.YY_MOVE_OR_COPY< IdentifierPath::Ptr > (YY_MOVE (that.value));
        break;

      case 70: // InstructionDefinition
        value.YY_MOVE_OR_COPY< InstructionDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 85: // LetStatement
        value.YY_MOVE_OR_COPY< LetStatement::Ptr > (YY_MOVE (that.value));
        break;

      case 94: // Literal
        value.YY_MOVE_OR_COPY< Literal::Ptr > (YY_MOVE (that.value));
        break;

      case 105: // Mapping
        value.YY_MOVE_OR_COPY< MappedExpression::Ptr > (YY_MOVE (that.value));
        break;

      case 104: // Mappings
        value.YY_MOVE_OR_COPY< MappedExpressions::Ptr > (YY_MOVE (that.value));
        break;

      case 68: // FormatFields
      case 103: // MappingLiteral
        value.YY_MOVE_OR_COPY< MappingLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 113: // MappingType
        value.YY_MOVE_OR_COPY< MappingType::Ptr > (YY_MOVE (that.value));
        break;

      case 64: // MemoryDefinition
        value.YY_MOVE_OR_COPY< MemoryDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 102: // Assignment
        value.YY_MOVE_OR_COPY< NamedExpression::Ptr > (YY_MOVE (that.value));
        break;

      case 101: // Assignments
        value.YY_MOVE_OR_COPY< NamedExpressions::Ptr > (YY_MOVE (that.value));
        break;

      case 76: // Option
        value.YY_MOVE_OR_COPY< Option::Ptr > (YY_MOVE (that.value));
        break;

      case 71: // OptionDefinition
        value.YY_MOVE_OR_COPY< OptionDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 75: // Options
        value.YY_MOVE_OR_COPY< Options::Ptr > (YY_MOVE (that.value));
        break;

      case 100: // RecordLiteral
        value.YY_MOVE_OR_COPY< RecordLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 106: // ReferenceLiteral
        value.YY_MOVE_OR_COPY< ReferenceLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 65: // RegisterDefinition
        value.YY_MOVE_OR_COPY< RegisterDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 73: // Enumerators
      case 99: // SetLiteral
        value.YY_MOVE_OR_COPY< SetLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 82: // SkipStatement
      case 83: // AbstractStatement
        value.YY_MOVE_OR_COPY< SkipStatement::Ptr > (YY_MOVE (that.value));
        break;

      case 59: // Specification
        value.YY_MOVE_OR_COPY< Specification::Ptr > (YY_MOVE (that.value));
        break;

      case 81: // Statement
        value.YY_MOVE_OR_COPY< Statement::Ptr > (YY_MOVE (that.value));
        break;

      case 80: // Statements
        value.YY_MOVE_OR_COPY< Statements::Ptr > (YY_MOVE (that.value));
        break;

      case 78: // SyntaxOption
        value.YY_MOVE_OR_COPY< SyntaxOption::Ptr > (YY_MOVE (that.value));
        break;

      case 114: // ArgumentTypes
        value.YY_MOVE_OR_COPY< Types::Ptr > (YY_MOVE (that.value));
        break;

      case 74: // UsingDefinition
        value.YY_MOVE_OR_COPY< UsingDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 53: // "integer"
      case 54: // "binary"
      case 55: // "hexadecimal"
      case 56: // "string"
      case 95: // BooleanLiteral
      case 96: // IntegerLiteral
      case 97: // BinaryLiteral
      case 98: // StringLiteral
        value.YY_MOVE_OR_COPY< ValueLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 116: // VariableBinding
        value.YY_MOVE_OR_COPY< VariableBinding::Ptr > (YY_MOVE (that.value));
        break;

      case 115: // VariableBindings
        value.YY_MOVE_OR_COPY< VariableBindings::Ptr > (YY_MOVE (that.value));
        break;

      case 117: // AttributedVariable
      case 118: // Variable
      case 119: // TypedVariable
        value.YY_MOVE_OR_COPY< VariableDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 110: // Type
      case 111: // BasicType
      case 112: // PropertyType
        value.YY_MOVE_OR_COPY< libscod::CST::Type::Ptr > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 86: // AssignmentStatement
        value.move< AssignmentStatement::Ptr > (YY_MOVE (that.value));
        break;

      case 123: // Attribute
        value.move< Attribute::Ptr > (YY_MOVE (that.value));
        break;

      case 122: // Attributes
        value.move< Attributes::Ptr > (YY_MOVE (that.value));
        break;

      case 124: // BasicAttribute
        value.move< BasicAttribute::Ptr > (YY_MOVE (that.value));
        break;

      case 84: // BlockStatement
        value.move< BlockStatement::Ptr > (YY_MOVE (that.value));
        break;

      case 69: // BufferDefinition
        value.move< BufferDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 3: // "SCOD"
      case 4: // "memory"
      case 5: // "register"
      case 6: // "field"
      case 7: // "format"
      case 8: // "buffer"
      case 9: // "instruction"
      case 10: // "decoding"
      case 11: // "syntax"
      case 12: // "expansion"
      case 13: // "enumeration"
      case 14: // "using"
      case 15: // "skip"
      case 16: // "abstract"
      case 17: // "let"
      case 18: // "in"
      case 19: // "if"
      case 20: // "then"
      case 21: // "else"
      case 22: // "false"
      case 23: // "true"
      case 24: // "not"
      case 25: // "and"
      case 26: // "or"
      case 27: // "xor"
      case 28: // "implies"
      case 29: // "=>"
      case 30: // "+"
      case 31: // "-"
      case 32: // "*"
      case 33: // "="
      case 34: // "!="
      case 35: // "<"
      case 36: // "<="
      case 37: // ">"
      case 38: // ">="
      case 39: // ":="
      case 40: // "->"
      case 41: // "'"
      case 42: // ":"
      case 43: // ";"
      case 44: // "::"
      case 45: // "("
      case 46: // ")"
      case 47: // "["
      case 48: // "]"
      case 49: // "{"
      case 50: // "}"
      case 51: // "@"
      case 52: // ","
        value.move< CST::Token::Ptr > (YY_MOVE (that.value));
        break;

      case 92: // CallExpression
        value.move< CallExpression::Ptr > (YY_MOVE (that.value));
        break;

      case 87: // ConditionalStatement
        value.move< ConditionalStatement::Ptr > (YY_MOVE (that.value));
        break;

      case 77: // DecodingOption
        value.move< DecodingOption::Ptr > (YY_MOVE (that.value));
        break;

      case 62: // AttributedDefinition
      case 63: // Definition
        value.move< Definition::Ptr > (YY_MOVE (that.value));
        break;

      case 61: // Definitions
        value.move< Definitions::Ptr > (YY_MOVE (that.value));
        break;

      case 93: // DirectCallExpression
        value.move< DirectCallExpression::Ptr > (YY_MOVE (that.value));
        break;

      case 72: // EnumerationDefinition
        value.move< EnumerationDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 79: // ExpansionOption
        value.move< ExpansionOption::Ptr > (YY_MOVE (that.value));
        break;

      case 89: // Term
      case 90: // Expression
      case 91: // OperatorExpression
      case 109: // Terminal
        value.move< Expression::Ptr > (YY_MOVE (that.value));
        break;

      case 125: // ExpressionAttribute
        value.move< ExpressionAttribute::Ptr > (YY_MOVE (that.value));
        break;

      case 88: // Terms
      case 108: // Terminals
        value.move< Expressions::Ptr > (YY_MOVE (that.value));
        break;

      case 66: // FieldDefinition
        value.move< FieldDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 67: // FormatDefinition
        value.move< FormatDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 107: // GrammarLiteral
        value.move< GrammarLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 60: // Header
        value.move< HeaderDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 57: // "identifier"
      case 120: // Identifier
        value.move< Identifier::Ptr > (YY_MOVE (that.value));
        break;

      case 121: // IdentifierPath
        value.move< IdentifierPath::Ptr > (YY_MOVE (that.value));
        break;

      case 70: // InstructionDefinition
        value.move< InstructionDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 85: // LetStatement
        value.move< LetStatement::Ptr > (YY_MOVE (that.value));
        break;

      case 94: // Literal
        value.move< Literal::Ptr > (YY_MOVE (that.value));
        break;

      case 105: // Mapping
        value.move< MappedExpression::Ptr > (YY_MOVE (that.value));
        break;

      case 104: // Mappings
        value.move< MappedExpressions::Ptr > (YY_MOVE (that.value));
        break;

      case 68: // FormatFields
      case 103: // MappingLiteral
        value.move< MappingLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 113: // MappingType
        value.move< MappingType::Ptr > (YY_MOVE (that.value));
        break;

      case 64: // MemoryDefinition
        value.move< MemoryDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 102: // Assignment
        value.move< NamedExpression::Ptr > (YY_MOVE (that.value));
        break;

      case 101: // Assignments
        value.move< NamedExpressions::Ptr > (YY_MOVE (that.value));
        break;

      case 76: // Option
        value.move< Option::Ptr > (YY_MOVE (that.value));
        break;

      case 71: // OptionDefinition
        value.move< OptionDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 75: // Options
        value.move< Options::Ptr > (YY_MOVE (that.value));
        break;

      case 100: // RecordLiteral
        value.move< RecordLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 106: // ReferenceLiteral
        value.move< ReferenceLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 65: // RegisterDefinition
        value.move< RegisterDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 73: // Enumerators
      case 99: // SetLiteral
        value.move< SetLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 82: // SkipStatement
      case 83: // AbstractStatement
        value.move< SkipStatement::Ptr > (YY_MOVE (that.value));
        break;

      case 59: // Specification
        value.move< Specification::Ptr > (YY_MOVE (that.value));
        break;

      case 81: // Statement
        value.move< Statement::Ptr > (YY_MOVE (that.value));
        break;

      case 80: // Statements
        value.move< Statements::Ptr > (YY_MOVE (that.value));
        break;

      case 78: // SyntaxOption
        value.move< SyntaxOption::Ptr > (YY_MOVE (that.value));
        break;

      case 114: // ArgumentTypes
        value.move< Types::Ptr > (YY_MOVE (that.value));
        break;

      case 74: // UsingDefinition
        value.move< UsingDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 53: // "integer"
      case 54: // "binary"
      case 55: // "hexadecimal"
      case 56: // "string"
      case 95: // BooleanLiteral
      case 96: // IntegerLiteral
      case 97: // BinaryLiteral
      case 98: // StringLiteral
        value.move< ValueLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 116: // VariableBinding
        value.move< VariableBinding::Ptr > (YY_MOVE (that.value));
        break;

      case 115: // VariableBindings
        value.move< VariableBindings::Ptr > (YY_MOVE (that.value));
        break;

      case 117: // AttributedVariable
      case 118: // Variable
      case 119: // TypedVariable
        value.move< VariableDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 110: // Type
      case 111: // BasicType
      case 112: // PropertyType
        value.move< libscod::CST::Type::Ptr > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 86: // AssignmentStatement
        value.copy< AssignmentStatement::Ptr > (that.value);
        break;

      case 123: // Attribute
        value.copy< Attribute::Ptr > (that.value);
        break;

      case 122: // Attributes
        value.copy< Attributes::Ptr > (that.value);
        break;

      case 124: // BasicAttribute
        value.copy< BasicAttribute::Ptr > (that.value);
        break;

      case 84: // BlockStatement
        value.copy< BlockStatement::Ptr > (that.value);
        break;

      case 69: // BufferDefinition
        value.copy< BufferDefinition::Ptr > (that.value);
        break;

      case 3: // "SCOD"
      case 4: // "memory"
      case 5: // "register"
      case 6: // "field"
      case 7: // "format"
      case 8: // "buffer"
      case 9: // "instruction"
      case 10: // "decoding"
      case 11: // "syntax"
      case 12: // "expansion"
      case 13: // "enumeration"
      case 14: // "using"
      case 15: // "skip"
      case 16: // "abstract"
      case 17: // "let"
      case 18: // "in"
      case 19: // "if"
      case 20: // "then"
      case 21: // "else"
      case 22: // "false"
      case 23: // "true"
      case 24: // "not"
      case 25: // "and"
      case 26: // "or"
      case 27: // "xor"
      case 28: // "implies"
      case 29: // "=>"
      case 30: // "+"
      case 31: // "-"
      case 32: // "*"
      case 33: // "="
      case 34: // "!="
      case 35: // "<"
      case 36: // "<="
      case 37: // ">"
      case 38: // ">="
      case 39: // ":="
      case 40: // "->"
      case 41: // "'"
      case 42: // ":"
      case 43: // ";"
      case 44: // "::"
      case 45: // "("
      case 46: // ")"
      case 47: // "["
      case 48: // "]"
      case 49: // "{"
      case 50: // "}"
      case 51: // "@"
      case 52: // ","
        value.copy< CST::Token::Ptr > (that.value);
        break;

      case 92: // CallExpression
        value.copy< CallExpression::Ptr > (that.value);
        break;

      case 87: // ConditionalStatement
        value.copy< ConditionalStatement::Ptr > (that.value);
        break;

      case 77: // DecodingOption
        value.copy< DecodingOption::Ptr > (that.value);
        break;

      case 62: // AttributedDefinition
      case 63: // Definition
        value.copy< Definition::Ptr > (that.value);
        break;

      case 61: // Definitions
        value.copy< Definitions::Ptr > (that.value);
        break;

      case 93: // DirectCallExpression
        value.copy< DirectCallExpression::Ptr > (that.value);
        break;

      case 72: // EnumerationDefinition
        value.copy< EnumerationDefinition::Ptr > (that.value);
        break;

      case 79: // ExpansionOption
        value.copy< ExpansionOption::Ptr > (that.value);
        break;

      case 89: // Term
      case 90: // Expression
      case 91: // OperatorExpression
      case 109: // Terminal
        value.copy< Expression::Ptr > (that.value);
        break;

      case 125: // ExpressionAttribute
        value.copy< ExpressionAttribute::Ptr > (that.value);
        break;

      case 88: // Terms
      case 108: // Terminals
        value.copy< Expressions::Ptr > (that.value);
        break;

      case 66: // FieldDefinition
        value.copy< FieldDefinition::Ptr > (that.value);
        break;

      case 67: // FormatDefinition
        value.copy< FormatDefinition::Ptr > (that.value);
        break;

      case 107: // GrammarLiteral
        value.copy< GrammarLiteral::Ptr > (that.value);
        break;

      case 60: // Header
        value.copy< HeaderDefinition::Ptr > (that.value);
        break;

      case 57: // "identifier"
      case 120: // Identifier
        value.copy< Identifier::Ptr > (that.value);
        break;

      case 121: // IdentifierPath
        value.copy< IdentifierPath::Ptr > (that.value);
        break;

      case 70: // InstructionDefinition
        value.copy< InstructionDefinition::Ptr > (that.value);
        break;

      case 85: // LetStatement
        value.copy< LetStatement::Ptr > (that.value);
        break;

      case 94: // Literal
        value.copy< Literal::Ptr > (that.value);
        break;

      case 105: // Mapping
        value.copy< MappedExpression::Ptr > (that.value);
        break;

      case 104: // Mappings
        value.copy< MappedExpressions::Ptr > (that.value);
        break;

      case 68: // FormatFields
      case 103: // MappingLiteral
        value.copy< MappingLiteral::Ptr > (that.value);
        break;

      case 113: // MappingType
        value.copy< MappingType::Ptr > (that.value);
        break;

      case 64: // MemoryDefinition
        value.copy< MemoryDefinition::Ptr > (that.value);
        break;

      case 102: // Assignment
        value.copy< NamedExpression::Ptr > (that.value);
        break;

      case 101: // Assignments
        value.copy< NamedExpressions::Ptr > (that.value);
        break;

      case 76: // Option
        value.copy< Option::Ptr > (that.value);
        break;

      case 71: // OptionDefinition
        value.copy< OptionDefinition::Ptr > (that.value);
        break;

      case 75: // Options
        value.copy< Options::Ptr > (that.value);
        break;

      case 100: // RecordLiteral
        value.copy< RecordLiteral::Ptr > (that.value);
        break;

      case 106: // ReferenceLiteral
        value.copy< ReferenceLiteral::Ptr > (that.value);
        break;

      case 65: // RegisterDefinition
        value.copy< RegisterDefinition::Ptr > (that.value);
        break;

      case 73: // Enumerators
      case 99: // SetLiteral
        value.copy< SetLiteral::Ptr > (that.value);
        break;

      case 82: // SkipStatement
      case 83: // AbstractStatement
        value.copy< SkipStatement::Ptr > (that.value);
        break;

      case 59: // Specification
        value.copy< Specification::Ptr > (that.value);
        break;

      case 81: // Statement
        value.copy< Statement::Ptr > (that.value);
        break;

      case 80: // Statements
        value.copy< Statements::Ptr > (that.value);
        break;

      case 78: // SyntaxOption
        value.copy< SyntaxOption::Ptr > (that.value);
        break;

      case 114: // ArgumentTypes
        value.copy< Types::Ptr > (that.value);
        break;

      case 74: // UsingDefinition
        value.copy< UsingDefinition::Ptr > (that.value);
        break;

      case 53: // "integer"
      case 54: // "binary"
      case 55: // "hexadecimal"
      case 56: // "string"
      case 95: // BooleanLiteral
      case 96: // IntegerLiteral
      case 97: // BinaryLiteral
      case 98: // StringLiteral
        value.copy< ValueLiteral::Ptr > (that.value);
        break;

      case 116: // VariableBinding
        value.copy< VariableBinding::Ptr > (that.value);
        break;

      case 115: // VariableBindings
        value.copy< VariableBindings::Ptr > (that.value);
        break;

      case 117: // AttributedVariable
      case 118: // Variable
      case 119: // TypedVariable
        value.copy< VariableDefinition::Ptr > (that.value);
        break;

      case 110: // Type
      case 111: // BasicType
      case 112: // PropertyType
        value.copy< libscod::CST::Type::Ptr > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 86: // AssignmentStatement
        value.move< AssignmentStatement::Ptr > (that.value);
        break;

      case 123: // Attribute
        value.move< Attribute::Ptr > (that.value);
        break;

      case 122: // Attributes
        value.move< Attributes::Ptr > (that.value);
        break;

      case 124: // BasicAttribute
        value.move< BasicAttribute::Ptr > (that.value);
        break;

      case 84: // BlockStatement
        value.move< BlockStatement::Ptr > (that.value);
        break;

      case 69: // BufferDefinition
        value.move< BufferDefinition::Ptr > (that.value);
        break;

      case 3: // "SCOD"
      case 4: // "memory"
      case 5: // "register"
      case 6: // "field"
      case 7: // "format"
      case 8: // "buffer"
      case 9: // "instruction"
      case 10: // "decoding"
      case 11: // "syntax"
      case 12: // "expansion"
      case 13: // "enumeration"
      case 14: // "using"
      case 15: // "skip"
      case 16: // "abstract"
      case 17: // "let"
      case 18: // "in"
      case 19: // "if"
      case 20: // "then"
      case 21: // "else"
      case 22: // "false"
      case 23: // "true"
      case 24: // "not"
      case 25: // "and"
      case 26: // "or"
      case 27: // "xor"
      case 28: // "implies"
      case 29: // "=>"
      case 30: // "+"
      case 31: // "-"
      case 32: // "*"
      case 33: // "="
      case 34: // "!="
      case 35: // "<"
      case 36: // "<="
      case 37: // ">"
      case 38: // ">="
      case 39: // ":="
      case 40: // "->"
      case 41: // "'"
      case 42: // ":"
      case 43: // ";"
      case 44: // "::"
      case 45: // "("
      case 46: // ")"
      case 47: // "["
      case 48: // "]"
      case 49: // "{"
      case 50: // "}"
      case 51: // "@"
      case 52: // ","
        value.move< CST::Token::Ptr > (that.value);
        break;

      case 92: // CallExpression
        value.move< CallExpression::Ptr > (that.value);
        break;

      case 87: // ConditionalStatement
        value.move< ConditionalStatement::Ptr > (that.value);
        break;

      case 77: // DecodingOption
        value.move< DecodingOption::Ptr > (that.value);
        break;

      case 62: // AttributedDefinition
      case 63: // Definition
        value.move< Definition::Ptr > (that.value);
        break;

      case 61: // Definitions
        value.move< Definitions::Ptr > (that.value);
        break;

      case 93: // DirectCallExpression
        value.move< DirectCallExpression::Ptr > (that.value);
        break;

      case 72: // EnumerationDefinition
        value.move< EnumerationDefinition::Ptr > (that.value);
        break;

      case 79: // ExpansionOption
        value.move< ExpansionOption::Ptr > (that.value);
        break;

      case 89: // Term
      case 90: // Expression
      case 91: // OperatorExpression
      case 109: // Terminal
        value.move< Expression::Ptr > (that.value);
        break;

      case 125: // ExpressionAttribute
        value.move< ExpressionAttribute::Ptr > (that.value);
        break;

      case 88: // Terms
      case 108: // Terminals
        value.move< Expressions::Ptr > (that.value);
        break;

      case 66: // FieldDefinition
        value.move< FieldDefinition::Ptr > (that.value);
        break;

      case 67: // FormatDefinition
        value.move< FormatDefinition::Ptr > (that.value);
        break;

      case 107: // GrammarLiteral
        value.move< GrammarLiteral::Ptr > (that.value);
        break;

      case 60: // Header
        value.move< HeaderDefinition::Ptr > (that.value);
        break;

      case 57: // "identifier"
      case 120: // Identifier
        value.move< Identifier::Ptr > (that.value);
        break;

      case 121: // IdentifierPath
        value.move< IdentifierPath::Ptr > (that.value);
        break;

      case 70: // InstructionDefinition
        value.move< InstructionDefinition::Ptr > (that.value);
        break;

      case 85: // LetStatement
        value.move< LetStatement::Ptr > (that.value);
        break;

      case 94: // Literal
        value.move< Literal::Ptr > (that.value);
        break;

      case 105: // Mapping
        value.move< MappedExpression::Ptr > (that.value);
        break;

      case 104: // Mappings
        value.move< MappedExpressions::Ptr > (that.value);
        break;

      case 68: // FormatFields
      case 103: // MappingLiteral
        value.move< MappingLiteral::Ptr > (that.value);
        break;

      case 113: // MappingType
        value.move< MappingType::Ptr > (that.value);
        break;

      case 64: // MemoryDefinition
        value.move< MemoryDefinition::Ptr > (that.value);
        break;

      case 102: // Assignment
        value.move< NamedExpression::Ptr > (that.value);
        break;

      case 101: // Assignments
        value.move< NamedExpressions::Ptr > (that.value);
        break;

      case 76: // Option
        value.move< Option::Ptr > (that.value);
        break;

      case 71: // OptionDefinition
        value.move< OptionDefinition::Ptr > (that.value);
        break;

      case 75: // Options
        value.move< Options::Ptr > (that.value);
        break;

      case 100: // RecordLiteral
        value.move< RecordLiteral::Ptr > (that.value);
        break;

      case 106: // ReferenceLiteral
        value.move< ReferenceLiteral::Ptr > (that.value);
        break;

      case 65: // RegisterDefinition
        value.move< RegisterDefinition::Ptr > (that.value);
        break;

      case 73: // Enumerators
      case 99: // SetLiteral
        value.move< SetLiteral::Ptr > (that.value);
        break;

      case 82: // SkipStatement
      case 83: // AbstractStatement
        value.move< SkipStatement::Ptr > (that.value);
        break;

      case 59: // Specification
        value.move< Specification::Ptr > (that.value);
        break;

      case 81: // Statement
        value.move< Statement::Ptr > (that.value);
        break;

      case 80: // Statements
        value.move< Statements::Ptr > (that.value);
        break;

      case 78: // SyntaxOption
        value.move< SyntaxOption::Ptr > (that.value);
        break;

      case 114: // ArgumentTypes
        value.move< Types::Ptr > (that.value);
        break;

      case 74: // UsingDefinition
        value.move< UsingDefinition::Ptr > (that.value);
        break;

      case 53: // "integer"
      case 54: // "binary"
      case 55: // "hexadecimal"
      case 56: // "string"
      case 95: // BooleanLiteral
      case 96: // IntegerLiteral
      case 97: // BinaryLiteral
      case 98: // StringLiteral
        value.move< ValueLiteral::Ptr > (that.value);
        break;

      case 116: // VariableBinding
        value.move< VariableBinding::Ptr > (that.value);
        break;

      case 115: // VariableBindings
        value.move< VariableBindings::Ptr > (that.value);
        break;

      case 117: // AttributedVariable
      case 118: // Variable
      case 119: // TypedVariable
        value.move< VariableDefinition::Ptr > (that.value);
        break;

      case 110: // Type
      case 111: // BasicType
      case 112: // PropertyType
        value.move< libscod::CST::Type::Ptr > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 86: // AssignmentStatement
        yylhs.value.emplace< AssignmentStatement::Ptr > ();
        break;

      case 123: // Attribute
        yylhs.value.emplace< Attribute::Ptr > ();
        break;

      case 122: // Attributes
        yylhs.value.emplace< Attributes::Ptr > ();
        break;

      case 124: // BasicAttribute
        yylhs.value.emplace< BasicAttribute::Ptr > ();
        break;

      case 84: // BlockStatement
        yylhs.value.emplace< BlockStatement::Ptr > ();
        break;

      case 69: // BufferDefinition
        yylhs.value.emplace< BufferDefinition::Ptr > ();
        break;

      case 3: // "SCOD"
      case 4: // "memory"
      case 5: // "register"
      case 6: // "field"
      case 7: // "format"
      case 8: // "buffer"
      case 9: // "instruction"
      case 10: // "decoding"
      case 11: // "syntax"
      case 12: // "expansion"
      case 13: // "enumeration"
      case 14: // "using"
      case 15: // "skip"
      case 16: // "abstract"
      case 17: // "let"
      case 18: // "in"
      case 19: // "if"
      case 20: // "then"
      case 21: // "else"
      case 22: // "false"
      case 23: // "true"
      case 24: // "not"
      case 25: // "and"
      case 26: // "or"
      case 27: // "xor"
      case 28: // "implies"
      case 29: // "=>"
      case 30: // "+"
      case 31: // "-"
      case 32: // "*"
      case 33: // "="
      case 34: // "!="
      case 35: // "<"
      case 36: // "<="
      case 37: // ">"
      case 38: // ">="
      case 39: // ":="
      case 40: // "->"
      case 41: // "'"
      case 42: // ":"
      case 43: // ";"
      case 44: // "::"
      case 45: // "("
      case 46: // ")"
      case 47: // "["
      case 48: // "]"
      case 49: // "{"
      case 50: // "}"
      case 51: // "@"
      case 52: // ","
        yylhs.value.emplace< CST::Token::Ptr > ();
        break;

      case 92: // CallExpression
        yylhs.value.emplace< CallExpression::Ptr > ();
        break;

      case 87: // ConditionalStatement
        yylhs.value.emplace< ConditionalStatement::Ptr > ();
        break;

      case 77: // DecodingOption
        yylhs.value.emplace< DecodingOption::Ptr > ();
        break;

      case 62: // AttributedDefinition
      case 63: // Definition
        yylhs.value.emplace< Definition::Ptr > ();
        break;

      case 61: // Definitions
        yylhs.value.emplace< Definitions::Ptr > ();
        break;

      case 93: // DirectCallExpression
        yylhs.value.emplace< DirectCallExpression::Ptr > ();
        break;

      case 72: // EnumerationDefinition
        yylhs.value.emplace< EnumerationDefinition::Ptr > ();
        break;

      case 79: // ExpansionOption
        yylhs.value.emplace< ExpansionOption::Ptr > ();
        break;

      case 89: // Term
      case 90: // Expression
      case 91: // OperatorExpression
      case 109: // Terminal
        yylhs.value.emplace< Expression::Ptr > ();
        break;

      case 125: // ExpressionAttribute
        yylhs.value.emplace< ExpressionAttribute::Ptr > ();
        break;

      case 88: // Terms
      case 108: // Terminals
        yylhs.value.emplace< Expressions::Ptr > ();
        break;

      case 66: // FieldDefinition
        yylhs.value.emplace< FieldDefinition::Ptr > ();
        break;

      case 67: // FormatDefinition
        yylhs.value.emplace< FormatDefinition::Ptr > ();
        break;

      case 107: // GrammarLiteral
        yylhs.value.emplace< GrammarLiteral::Ptr > ();
        break;

      case 60: // Header
        yylhs.value.emplace< HeaderDefinition::Ptr > ();
        break;

      case 57: // "identifier"
      case 120: // Identifier
        yylhs.value.emplace< Identifier::Ptr > ();
        break;

      case 121: // IdentifierPath
        yylhs.value.emplace< IdentifierPath::Ptr > ();
        break;

      case 70: // InstructionDefinition
        yylhs.value.emplace< InstructionDefinition::Ptr > ();
        break;

      case 85: // LetStatement
        yylhs.value.emplace< LetStatement::Ptr > ();
        break;

      case 94: // Literal
        yylhs.value.emplace< Literal::Ptr > ();
        break;

      case 105: // Mapping
        yylhs.value.emplace< MappedExpression::Ptr > ();
        break;

      case 104: // Mappings
        yylhs.value.emplace< MappedExpressions::Ptr > ();
        break;

      case 68: // FormatFields
      case 103: // MappingLiteral
        yylhs.value.emplace< MappingLiteral::Ptr > ();
        break;

      case 113: // MappingType
        yylhs.value.emplace< MappingType::Ptr > ();
        break;

      case 64: // MemoryDefinition
        yylhs.value.emplace< MemoryDefinition::Ptr > ();
        break;

      case 102: // Assignment
        yylhs.value.emplace< NamedExpression::Ptr > ();
        break;

      case 101: // Assignments
        yylhs.value.emplace< NamedExpressions::Ptr > ();
        break;

      case 76: // Option
        yylhs.value.emplace< Option::Ptr > ();
        break;

      case 71: // OptionDefinition
        yylhs.value.emplace< OptionDefinition::Ptr > ();
        break;

      case 75: // Options
        yylhs.value.emplace< Options::Ptr > ();
        break;

      case 100: // RecordLiteral
        yylhs.value.emplace< RecordLiteral::Ptr > ();
        break;

      case 106: // ReferenceLiteral
        yylhs.value.emplace< ReferenceLiteral::Ptr > ();
        break;

      case 65: // RegisterDefinition
        yylhs.value.emplace< RegisterDefinition::Ptr > ();
        break;

      case 73: // Enumerators
      case 99: // SetLiteral
        yylhs.value.emplace< SetLiteral::Ptr > ();
        break;

      case 82: // SkipStatement
      case 83: // AbstractStatement
        yylhs.value.emplace< SkipStatement::Ptr > ();
        break;

      case 59: // Specification
        yylhs.value.emplace< Specification::Ptr > ();
        break;

      case 81: // Statement
        yylhs.value.emplace< Statement::Ptr > ();
        break;

      case 80: // Statements
        yylhs.value.emplace< Statements::Ptr > ();
        break;

      case 78: // SyntaxOption
        yylhs.value.emplace< SyntaxOption::Ptr > ();
        break;

      case 114: // ArgumentTypes
        yylhs.value.emplace< Types::Ptr > ();
        break;

      case 74: // UsingDefinition
        yylhs.value.emplace< UsingDefinition::Ptr > ();
        break;

      case 53: // "integer"
      case 54: // "binary"
      case 55: // "hexadecimal"
      case 56: // "string"
      case 95: // BooleanLiteral
      case 96: // IntegerLiteral
      case 97: // BinaryLiteral
      case 98: // StringLiteral
        yylhs.value.emplace< ValueLiteral::Ptr > ();
        break;

      case 116: // VariableBinding
        yylhs.value.emplace< VariableBinding::Ptr > ();
        break;

      case 115: // VariableBindings
        yylhs.value.emplace< VariableBindings::Ptr > ();
        break;

      case 117: // AttributedVariable
      case 118: // Variable
      case 119: // TypedVariable
        yylhs.value.emplace< VariableDefinition::Ptr > ();
        break;

      case 110: // Type
      case 111: // BasicType
      case 112: // PropertyType
        yylhs.value.emplace< libscod::CST::Type::Ptr > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 331 "../../obj/src/GrammarParser.y"
  {
      const auto& cst = CST::make< CST::Root >(
          yylhs.location, yystack_[1].value.as < HeaderDefinition::Ptr > (), yystack_[0].value.as < Definitions::Ptr > (), m_lexer.fetchSpansAndReset() );
      m_specification.setCst( cst );
  }
#line 1986 "GrammarParser.cpp"
    break;

  case 3:
#line 341 "../../obj/src/GrammarParser.y"
 {
     auto definition = CST::make< HeaderDefinition >( yylhs.location, yystack_[0].value.as < CST::Token::Ptr > () );
     definition->setAttributes( yystack_[1].value.as < Attributes::Ptr > () );
     yylhs.value.as < HeaderDefinition::Ptr > () = definition;
 }
#line 1996 "GrammarParser.cpp"
    break;

  case 4:
#line 347 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < HeaderDefinition::Ptr > () = CST::make< HeaderDefinition >( yylhs.location, yystack_[0].value.as < CST::Token::Ptr > () );
  }
#line 2004 "GrammarParser.cpp"
    break;

  case 5:
#line 355 "../../obj/src/GrammarParser.y"
  {
      auto definitions = yystack_[1].value.as < Definitions::Ptr > ();
      definitions->add( yystack_[0].value.as < Definition::Ptr > () );
      yylhs.value.as < Definitions::Ptr > () = definitions;
  }
#line 2014 "GrammarParser.cpp"
    break;

  case 6:
#line 361 "../../obj/src/GrammarParser.y"
  {
      auto definitions = CST::make< Definitions >( yylhs.location );
      definitions->add( yystack_[0].value.as < Definition::Ptr > () );
      yylhs.value.as < Definitions::Ptr > () = definitions;
  }
#line 2024 "GrammarParser.cpp"
    break;

  case 7:
#line 371 "../../obj/src/GrammarParser.y"
  {
      auto definition = yystack_[0].value.as < Definition::Ptr > ();
      definition->setAttributes( yystack_[1].value.as < Attributes::Ptr > () );
      yylhs.value.as < Definition::Ptr > () = definition;
  }
#line 2034 "GrammarParser.cpp"
    break;

  case 8:
#line 377 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Definition::Ptr > () = yystack_[0].value.as < Definition::Ptr > ();
  }
#line 2042 "GrammarParser.cpp"
    break;

  case 9:
#line 381 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Definition::Ptr > () = nullptr;
  }
#line 2050 "GrammarParser.cpp"
    break;

  case 10:
#line 389 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Definition::Ptr > () = yystack_[0].value.as < MemoryDefinition::Ptr > ();
  }
#line 2058 "GrammarParser.cpp"
    break;

  case 11:
#line 393 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Definition::Ptr > () = yystack_[0].value.as < RegisterDefinition::Ptr > ();
  }
#line 2066 "GrammarParser.cpp"
    break;

  case 12:
#line 397 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Definition::Ptr > () = yystack_[0].value.as < FieldDefinition::Ptr > ();
  }
#line 2074 "GrammarParser.cpp"
    break;

  case 13:
#line 401 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Definition::Ptr > () = yystack_[0].value.as < FormatDefinition::Ptr > ();
  }
#line 2082 "GrammarParser.cpp"
    break;

  case 14:
#line 405 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Definition::Ptr > () = yystack_[0].value.as < BufferDefinition::Ptr > ();
  }
#line 2090 "GrammarParser.cpp"
    break;

  case 15:
#line 409 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Definition::Ptr > () = yystack_[0].value.as < InstructionDefinition::Ptr > ();
  }
#line 2098 "GrammarParser.cpp"
    break;

  case 16:
#line 413 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Definition::Ptr > () = yystack_[0].value.as < OptionDefinition::Ptr > ();
  }
#line 2106 "GrammarParser.cpp"
    break;

  case 17:
#line 417 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Definition::Ptr > () = yystack_[0].value.as < EnumerationDefinition::Ptr > ();
  }
#line 2114 "GrammarParser.cpp"
    break;

  case 18:
#line 421 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Definition::Ptr > () = yystack_[0].value.as < UsingDefinition::Ptr > ();
  }
#line 2122 "GrammarParser.cpp"
    break;

  case 19:
#line 429 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < MemoryDefinition::Ptr > () = CST::make< MemoryDefinition >( yylhs.location, yystack_[3].value.as < CST::Token::Ptr > (), yystack_[2].value.as < Identifier::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < MappingType::Ptr > () );
  }
#line 2130 "GrammarParser.cpp"
    break;

  case 20:
#line 437 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < RegisterDefinition::Ptr > () = CST::make< RegisterDefinition >( yylhs.location, yystack_[3].value.as < CST::Token::Ptr > (), yystack_[2].value.as < Identifier::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < libscod::CST::Type::Ptr > () );
  }
#line 2138 "GrammarParser.cpp"
    break;

  case 21:
#line 449 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < FieldDefinition::Ptr > () = CST::make< FieldDefinition >( yylhs.location, yystack_[3].value.as < CST::Token::Ptr > (), yystack_[2].value.as < Identifier::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < libscod::CST::Type::Ptr > () );
  }
#line 2146 "GrammarParser.cpp"
    break;

  case 22:
#line 457 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < FormatDefinition::Ptr > () = CST::make< FormatDefinition >( yylhs.location, yystack_[5].value.as < CST::Token::Ptr > (), yystack_[4].value.as < Identifier::Ptr > (), yystack_[3].value.as < CST::Token::Ptr > (), yystack_[2].value.as < libscod::CST::Type::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < MappingLiteral::Ptr > () );
  }
#line 2154 "GrammarParser.cpp"
    break;

  case 23:
#line 464 "../../obj/src/GrammarParser.y"
{
    // TODO: check mapping types here or later in validation
    yylhs.value.as < MappingLiteral::Ptr > () = yystack_[0].value.as < MappingLiteral::Ptr > ();
}
#line 2163 "GrammarParser.cpp"
    break;

  case 24:
#line 472 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < BufferDefinition::Ptr > () = CST::make< BufferDefinition >( yylhs.location, yystack_[5].value.as < CST::Token::Ptr > (), yystack_[4].value.as < Identifier::Ptr > (), yystack_[3].value.as < CST::Token::Ptr > (), yystack_[2].value.as < libscod::CST::Type::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );      
  }
#line 2171 "GrammarParser.cpp"
    break;

  case 25:
#line 480 "../../obj/src/GrammarParser.y"
  {
      const auto& options = CST::make< Options >( yylhs.location );
      yylhs.value.as < InstructionDefinition::Ptr > () = CST::make< InstructionDefinition >( yylhs.location, yystack_[5].value.as < CST::Token::Ptr > (), yystack_[4].value.as < Identifier::Ptr > (), yystack_[3].value.as < CST::Token::Ptr > (), yystack_[2].value.as < libscod::CST::Type::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Statement::Ptr > (), options );
  }
#line 2180 "GrammarParser.cpp"
    break;

  case 26:
#line 485 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < InstructionDefinition::Ptr > () = CST::make< InstructionDefinition >( yylhs.location, yystack_[6].value.as < CST::Token::Ptr > (), yystack_[5].value.as < Identifier::Ptr > (), yystack_[4].value.as < CST::Token::Ptr > (), yystack_[3].value.as < libscod::CST::Type::Ptr > (), yystack_[2].value.as < CST::Token::Ptr > (), yystack_[1].value.as < Statement::Ptr > (), yystack_[0].value.as < Options::Ptr > () );
  }
#line 2188 "GrammarParser.cpp"
    break;

  case 27:
#line 493 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < OptionDefinition::Ptr > () = CST::make< OptionDefinition >( yylhs.location, yystack_[1].value.as < ReferenceLiteral::Ptr > (), yystack_[0].value.as < DecodingOption::Ptr > (), OptionDefinition::Kind::DECODING );
  }
#line 2196 "GrammarParser.cpp"
    break;

  case 28:
#line 497 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < OptionDefinition::Ptr > () = CST::make< OptionDefinition >( yylhs.location, yystack_[1].value.as < ReferenceLiteral::Ptr > (), yystack_[0].value.as < SyntaxOption::Ptr > (), OptionDefinition::Kind::SYNTAX );
  }
#line 2204 "GrammarParser.cpp"
    break;

  case 29:
#line 501 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < OptionDefinition::Ptr > () = CST::make< OptionDefinition >( yylhs.location, yystack_[1].value.as < ReferenceLiteral::Ptr > (), yystack_[0].value.as < ExpansionOption::Ptr > (), OptionDefinition::Kind::EXPANSION );
  }
#line 2212 "GrammarParser.cpp"
    break;

  case 30:
#line 509 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < EnumerationDefinition::Ptr > () = CST::make< EnumerationDefinition >( yylhs.location, yystack_[3].value.as < CST::Token::Ptr > (), yystack_[2].value.as < Identifier::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < SetLiteral::Ptr > () );
  }
#line 2220 "GrammarParser.cpp"
    break;

  case 31:
#line 516 "../../obj/src/GrammarParser.y"
  {
      // TODO: add check if identifiers here or later in validation pass
      yylhs.value.as < SetLiteral::Ptr > () = yystack_[0].value.as < SetLiteral::Ptr > ();
  }
#line 2229 "GrammarParser.cpp"
    break;

  case 32:
#line 525 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < UsingDefinition::Ptr > () = CST::make< UsingDefinition >( yylhs.location, yystack_[3].value.as < CST::Token::Ptr > (), yystack_[2].value.as < Identifier::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < libscod::CST::Type::Ptr > () );
  }
#line 2237 "GrammarParser.cpp"
    break;

  case 33:
#line 537 "../../obj/src/GrammarParser.y"
  {
      const auto& options = yystack_[1].value.as < Options::Ptr > ();
      options->add( yystack_[0].value.as < Option::Ptr > () );
      yylhs.value.as < Options::Ptr > () = options;
  }
#line 2247 "GrammarParser.cpp"
    break;

  case 34:
#line 543 "../../obj/src/GrammarParser.y"
  {
      const auto& options = CST::make< Options >( yylhs.location );
      options->add( yystack_[0].value.as < Option::Ptr > () );
      yylhs.value.as < Options::Ptr > () = options;
  }
#line 2257 "GrammarParser.cpp"
    break;

  case 35:
#line 558 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Option::Ptr > () = yystack_[0].value.as < DecodingOption::Ptr > ();
  }
#line 2265 "GrammarParser.cpp"
    break;

  case 36:
#line 562 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Option::Ptr > () = yystack_[0].value.as < SyntaxOption::Ptr > ();
  }
#line 2273 "GrammarParser.cpp"
    break;

  case 37:
#line 566 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Option::Ptr > () = yystack_[0].value.as < ExpansionOption::Ptr > ();
  }
#line 2281 "GrammarParser.cpp"
    break;

  case 38:
#line 574 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < DecodingOption::Ptr > () = CST::make< DecodingOption >( yylhs.location, yystack_[2].value.as < CST::Token::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < RecordLiteral::Ptr > () );      
  }
#line 2289 "GrammarParser.cpp"
    break;

  case 39:
#line 582 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < SyntaxOption::Ptr > () = CST::make< SyntaxOption >( yylhs.location, yystack_[2].value.as < CST::Token::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < SetLiteral::Ptr > () );      
  }
#line 2297 "GrammarParser.cpp"
    break;

  case 40:
#line 590 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < ExpansionOption::Ptr > () = CST::make< ExpansionOption >( yylhs.location, yystack_[2].value.as < CST::Token::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < SetLiteral::Ptr > () );      
  }
#line 2305 "GrammarParser.cpp"
    break;

  case 41:
#line 602 "../../obj/src/GrammarParser.y"
  {
      const auto& statements = yystack_[1].value.as < Statements::Ptr > ();
      statements->add( yystack_[0].value.as < Statement::Ptr > () );
      yylhs.value.as < Statements::Ptr > () = statements;
  }
#line 2315 "GrammarParser.cpp"
    break;

  case 42:
#line 608 "../../obj/src/GrammarParser.y"
  {
      const auto& statements = CST::make< Statements >( yylhs.location );
      statements->add( yystack_[0].value.as < Statement::Ptr > () );
      yylhs.value.as < Statements::Ptr > () = statements;
  }
#line 2325 "GrammarParser.cpp"
    break;

  case 43:
#line 618 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Statement::Ptr > () = yystack_[0].value.as < SkipStatement::Ptr > ();
  }
#line 2333 "GrammarParser.cpp"
    break;

  case 44:
#line 622 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Statement::Ptr > () = yystack_[0].value.as < SkipStatement::Ptr > ();
  }
#line 2341 "GrammarParser.cpp"
    break;

  case 45:
#line 626 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Statement::Ptr > () = yystack_[0].value.as < BlockStatement::Ptr > ();
  }
#line 2349 "GrammarParser.cpp"
    break;

  case 46:
#line 630 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Statement::Ptr > () = yystack_[0].value.as < LetStatement::Ptr > ();
  }
#line 2357 "GrammarParser.cpp"
    break;

  case 47:
#line 634 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Statement::Ptr > () = yystack_[0].value.as < AssignmentStatement::Ptr > ();
  }
#line 2365 "GrammarParser.cpp"
    break;

  case 48:
#line 638 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Statement::Ptr > () = yystack_[0].value.as < ConditionalStatement::Ptr > ();
  }
#line 2373 "GrammarParser.cpp"
    break;

  case 49:
#line 646 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < SkipStatement::Ptr > () = CST::make< SkipStatement >( yylhs.location, yystack_[0].value.as < CST::Token::Ptr > () );
  }
#line 2381 "GrammarParser.cpp"
    break;

  case 50:
#line 654 "../../obj/src/GrammarParser.y"
  {
      // maybe introduce exclusive CST node!
      yylhs.value.as < SkipStatement::Ptr > () = CST::make< SkipStatement >( yylhs.location, yystack_[0].value.as < CST::Token::Ptr > () );
  }
#line 2390 "GrammarParser.cpp"
    break;

  case 51:
#line 663 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < BlockStatement::Ptr > () = CST::make< BlockStatement >( yylhs.location, yystack_[2].value.as < CST::Token::Ptr > (), yystack_[1].value.as < Statements::Ptr > (), yystack_[0].value.as < CST::Token::Ptr > () );
  }
#line 2398 "GrammarParser.cpp"
    break;

  case 52:
#line 667 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < BlockStatement::Ptr > () = nullptr;
      yyerrok;
  }
#line 2407 "GrammarParser.cpp"
    break;

  case 53:
#line 676 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < LetStatement::Ptr > () = CST::make< LetStatement >( yylhs.location, yystack_[3].value.as < CST::Token::Ptr > (), yystack_[2].value.as < VariableBindings::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Statement::Ptr > () );
  }
#line 2415 "GrammarParser.cpp"
    break;

  case 54:
#line 684 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < AssignmentStatement::Ptr > () = CST::make< AssignmentStatement >( yylhs.location, yystack_[2].value.as < DirectCallExpression::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
  }
#line 2423 "GrammarParser.cpp"
    break;

  case 55:
#line 692 "../../obj/src/GrammarParser.y"
  {
      const auto& elseStatement = CST::make< SkipStatement >( yylhs.location, Token::unresolved() );
      yylhs.value.as < ConditionalStatement::Ptr > () = CST::make< ConditionalStatement >( yylhs.location, yystack_[3].value.as < CST::Token::Ptr > (), yystack_[2].value.as < Expression::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Statement::Ptr > (), Token::unresolved(), elseStatement );
  }
#line 2432 "GrammarParser.cpp"
    break;

  case 56:
#line 697 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < ConditionalStatement::Ptr > () = CST::make< ConditionalStatement >( yylhs.location, yystack_[5].value.as < CST::Token::Ptr > (), yystack_[4].value.as < Expression::Ptr > (), yystack_[3].value.as < CST::Token::Ptr > (), yystack_[2].value.as < Statement::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Statement::Ptr > () );
  }
#line 2440 "GrammarParser.cpp"
    break;

  case 57:
#line 709 "../../obj/src/GrammarParser.y"
  {
      const auto& expressions = yystack_[2].value.as < Expressions::Ptr > ();
      yystack_[0].value.as < Expression::Ptr > ()->setDelimiterToken( yystack_[1].value.as < CST::Token::Ptr > () );
      expressions->add( yystack_[0].value.as < Expression::Ptr > () );
      yylhs.value.as < Expressions::Ptr > () = expressions;
  }
#line 2451 "GrammarParser.cpp"
    break;

  case 58:
#line 716 "../../obj/src/GrammarParser.y"
  {
      const auto& expressions = CST::make< Expressions >( yylhs.location );
      expressions->add( yystack_[0].value.as < Expression::Ptr > () );
      yylhs.value.as < Expressions::Ptr > () = expressions;
  }
#line 2461 "GrammarParser.cpp"
    break;

  case 59:
#line 726 "../../obj/src/GrammarParser.y"
  {
     yylhs.value.as < Expression::Ptr > () = yystack_[0].value.as < Expression::Ptr > ();
  }
#line 2469 "GrammarParser.cpp"
    break;

  case 60:
#line 730 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = yystack_[0].value.as < Expression::Ptr > ();
  }
#line 2477 "GrammarParser.cpp"
    break;

  case 61:
#line 738 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = CST::make< CST::EmbracedExpression >( yylhs.location, yystack_[2].value.as < CST::Token::Ptr > (), yystack_[1].value.as < Expression::Ptr > (), yystack_[0].value.as < CST::Token::Ptr > () );
  }
#line 2485 "GrammarParser.cpp"
    break;

  case 62:
#line 742 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = yystack_[0].value.as < CallExpression::Ptr > ();
  }
#line 2493 "GrammarParser.cpp"
    break;

  case 63:
#line 746 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = yystack_[0].value.as < Literal::Ptr > ();
  }
#line 2501 "GrammarParser.cpp"
    break;

  case 64:
#line 750 "../../obj/src/GrammarParser.y"
 {
     yylhs.value.as < Expression::Ptr > () = CST::make< UnaryExpression >( yylhs.location, yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
 }
#line 2509 "GrammarParser.cpp"
    break;

  case 65:
#line 754 "../../obj/src/GrammarParser.y"
 {
     yylhs.value.as < Expression::Ptr > () = CST::make< UnaryExpression >( yylhs.location, yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
 }
#line 2517 "GrammarParser.cpp"
    break;

  case 66:
#line 766 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = CST::make< UnaryExpression >( yylhs.location, yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
  }
#line 2525 "GrammarParser.cpp"
    break;

  case 67:
#line 770 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = CST::make< BinaryExpression >( yylhs.location, yystack_[2].value.as < Expression::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
  }
#line 2533 "GrammarParser.cpp"
    break;

  case 68:
#line 774 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = CST::make< BinaryExpression >( yylhs.location, yystack_[2].value.as < Expression::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
  }
#line 2541 "GrammarParser.cpp"
    break;

  case 69:
#line 778 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = CST::make< BinaryExpression >( yylhs.location, yystack_[2].value.as < Expression::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
  }
#line 2549 "GrammarParser.cpp"
    break;

  case 70:
#line 782 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = CST::make< BinaryExpression >( yylhs.location, yystack_[2].value.as < Expression::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
  }
#line 2557 "GrammarParser.cpp"
    break;

  case 71:
#line 786 "../../obj/src/GrammarParser.y"
  {
      // equivalent to 'implies'
      yylhs.value.as < Expression::Ptr > () = CST::make< BinaryExpression >( yylhs.location, yystack_[2].value.as < Expression::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
  }
#line 2566 "GrammarParser.cpp"
    break;

  case 72:
#line 791 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = CST::make< BinaryExpression >( yylhs.location, yystack_[2].value.as < Expression::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
  }
#line 2574 "GrammarParser.cpp"
    break;

  case 73:
#line 799 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = CST::make< BinaryExpression >( yylhs.location, yystack_[2].value.as < Expression::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
  }
#line 2582 "GrammarParser.cpp"
    break;

  case 74:
#line 807 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = CST::make< BinaryExpression >( yylhs.location, yystack_[2].value.as < Expression::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
  }
#line 2590 "GrammarParser.cpp"
    break;

  case 75:
#line 811 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = CST::make< BinaryExpression >( yylhs.location, yystack_[2].value.as < Expression::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
  }
#line 2598 "GrammarParser.cpp"
    break;

  case 76:
#line 815 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = CST::make< BinaryExpression >( yylhs.location, yystack_[2].value.as < Expression::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
  }
#line 2606 "GrammarParser.cpp"
    break;

  case 77:
#line 819 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = CST::make< BinaryExpression >( yylhs.location, yystack_[2].value.as < Expression::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
  }
#line 2614 "GrammarParser.cpp"
    break;

  case 78:
#line 823 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = CST::make< BinaryExpression >( yylhs.location, yystack_[2].value.as < Expression::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
  }
#line 2622 "GrammarParser.cpp"
    break;

  case 79:
#line 827 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = CST::make< BinaryExpression >( yylhs.location, yystack_[2].value.as < Expression::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
  }
#line 2630 "GrammarParser.cpp"
    break;

  case 80:
#line 831 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = CST::make< BinaryExpression >( yylhs.location, yystack_[2].value.as < Expression::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
  }
#line 2638 "GrammarParser.cpp"
    break;

  case 81:
#line 839 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < CallExpression::Ptr > () = yystack_[0].value.as < DirectCallExpression::Ptr > ();
  }
#line 2646 "GrammarParser.cpp"
    break;

  case 82:
#line 847 "../../obj/src/GrammarParser.y"
  {
      const auto& arguments = CST::make< Expressions >( yylhs.location );
      yylhs.value.as < DirectCallExpression::Ptr > () = CST::make< DirectCallExpression >( yylhs.location, yystack_[0].value.as < IdentifierPath::Ptr > (), Token::unresolved(), arguments, Token::unresolved() );
  }
#line 2655 "GrammarParser.cpp"
    break;

  case 83:
#line 852 "../../obj/src/GrammarParser.y"
  {
      const auto& arguments = CST::make< Expressions >( yylhs.location );
      yylhs.value.as < DirectCallExpression::Ptr > () = CST::make< DirectCallExpression >( yylhs.location, yystack_[2].value.as < IdentifierPath::Ptr > (), Token::unresolved(), arguments, Token::unresolved() );
  }
#line 2664 "GrammarParser.cpp"
    break;

  case 84:
#line 857 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < DirectCallExpression::Ptr > () = CST::make< DirectCallExpression >( yylhs.location, yystack_[3].value.as < IdentifierPath::Ptr > (), Token::unresolved(), yystack_[1].value.as < Expressions::Ptr > (), Token::unresolved() );
  }
#line 2672 "GrammarParser.cpp"
    break;

  case 85:
#line 861 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < DirectCallExpression::Ptr > () = nullptr;
  }
#line 2680 "GrammarParser.cpp"
    break;

  case 86:
#line 953 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Literal::Ptr > () = yystack_[0].value.as < ValueLiteral::Ptr > ();
  }
#line 2688 "GrammarParser.cpp"
    break;

  case 87:
#line 957 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Literal::Ptr > () = yystack_[0].value.as < ValueLiteral::Ptr > ();
  }
#line 2696 "GrammarParser.cpp"
    break;

  case 88:
#line 961 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Literal::Ptr > () = yystack_[0].value.as < ValueLiteral::Ptr > ();
  }
#line 2704 "GrammarParser.cpp"
    break;

  case 89:
#line 965 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Literal::Ptr > () = yystack_[0].value.as < ValueLiteral::Ptr > ();
  }
#line 2712 "GrammarParser.cpp"
    break;

  case 90:
#line 969 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Literal::Ptr > () = yystack_[0].value.as < SetLiteral::Ptr > ();
  }
#line 2720 "GrammarParser.cpp"
    break;

  case 91:
#line 973 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Literal::Ptr > () = yystack_[0].value.as < RecordLiteral::Ptr > ();
  }
#line 2728 "GrammarParser.cpp"
    break;

  case 92:
#line 977 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Literal::Ptr > () = yystack_[0].value.as < MappingLiteral::Ptr > ();
  }
#line 2736 "GrammarParser.cpp"
    break;

  case 93:
#line 981 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Literal::Ptr > () = yystack_[0].value.as < ReferenceLiteral::Ptr > ();
  }
#line 2744 "GrammarParser.cpp"
    break;

  case 94:
#line 985 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Literal::Ptr > () = yystack_[0].value.as < GrammarLiteral::Ptr > ();
  }
#line 2752 "GrammarParser.cpp"
    break;

  case 95:
#line 993 "../../obj/src/GrammarParser.y"
  {
      const auto& value = libstdhl::Type::createBoolean( true );
      yylhs.value.as < ValueLiteral::Ptr > () = CST::make< ValueLiteral >( yylhs.location, value, ValueLiteral::Kind::BOOLEAN );
      yylhs.value.as < ValueLiteral::Ptr > ()->setSpans( yystack_[0].value.as < CST::Token::Ptr > ()->spans() );
  }
#line 2762 "GrammarParser.cpp"
    break;

  case 96:
#line 999 "../../obj/src/GrammarParser.y"
  {
      const auto& value = libstdhl::Type::createBoolean( false );
      yylhs.value.as < ValueLiteral::Ptr > () = CST::make< ValueLiteral >( yylhs.location, value, ValueLiteral::Kind::BOOLEAN );
      yylhs.value.as < ValueLiteral::Ptr > ()->setSpans( yystack_[0].value.as < CST::Token::Ptr > ()->spans() );
  }
#line 2772 "GrammarParser.cpp"
    break;

  case 97:
#line 1009 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < ValueLiteral::Ptr > () = yystack_[0].value.as < ValueLiteral::Ptr > ();
  }
#line 2780 "GrammarParser.cpp"
    break;

  case 98:
#line 1017 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < ValueLiteral::Ptr > () = yystack_[0].value.as < ValueLiteral::Ptr > ();
  }
#line 2788 "GrammarParser.cpp"
    break;

  case 99:
#line 1021 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < ValueLiteral::Ptr > () = yystack_[0].value.as < ValueLiteral::Ptr > ();
  }
#line 2796 "GrammarParser.cpp"
    break;

  case 100:
#line 1029 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < ValueLiteral::Ptr > () = yystack_[0].value.as < ValueLiteral::Ptr > ();
  }
#line 2804 "GrammarParser.cpp"
    break;

  case 101:
#line 1037 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < SetLiteral::Ptr > () = CST::make< SetLiteral >( yylhs.location, yystack_[1].value.as < Expressions::Ptr > () );
      yylhs.value.as < SetLiteral::Ptr > ()->setLeftBracket( yystack_[2].value.as < CST::Token::Ptr > () );
      yylhs.value.as < SetLiteral::Ptr > ()->setRightBracket( yystack_[0].value.as < CST::Token::Ptr > () );
  }
#line 2814 "GrammarParser.cpp"
    break;

  case 102:
#line 1047 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < RecordLiteral::Ptr > () = CST::make< RecordLiteral >( yylhs.location, yystack_[1].value.as < NamedExpressions::Ptr > () );
      yylhs.value.as < RecordLiteral::Ptr > ()->setLeftBracket( yystack_[2].value.as < CST::Token::Ptr > () );
      yylhs.value.as < RecordLiteral::Ptr > ()->setRightBracket( yystack_[0].value.as < CST::Token::Ptr > () );
  }
#line 2824 "GrammarParser.cpp"
    break;

  case 103:
#line 1056 "../../obj/src/GrammarParser.y"
  {
      auto assignments = yystack_[2].value.as < NamedExpressions::Ptr > ();
      yystack_[0].value.as < NamedExpression::Ptr > ()->setDelimiterToken( yystack_[1].value.as < CST::Token::Ptr > () );
      assignments->add( yystack_[0].value.as < NamedExpression::Ptr > () );
      yylhs.value.as < NamedExpressions::Ptr > () = assignments;
  }
#line 2835 "GrammarParser.cpp"
    break;

  case 104:
#line 1063 "../../obj/src/GrammarParser.y"
  {
      auto assignments = CST::make< NamedExpressions >( yylhs.location );
      assignments->add( yystack_[0].value.as < NamedExpression::Ptr > () );
      yylhs.value.as < NamedExpressions::Ptr > () = assignments;
  }
#line 2845 "GrammarParser.cpp"
    break;

  case 105:
#line 1072 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < NamedExpression::Ptr > () = CST::make< NamedExpression >( yylhs.location, yystack_[2].value.as < Identifier::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
  }
#line 2853 "GrammarParser.cpp"
    break;

  case 106:
#line 1080 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < MappingLiteral::Ptr > () = CST::make< MappingLiteral >( yylhs.location, yystack_[1].value.as < MappedExpressions::Ptr > () );
      yylhs.value.as < MappingLiteral::Ptr > ()->setLeftBracket( yystack_[2].value.as < CST::Token::Ptr > () );
      yylhs.value.as < MappingLiteral::Ptr > ()->setRightBracket( yystack_[0].value.as < CST::Token::Ptr > () );
  }
#line 2863 "GrammarParser.cpp"
    break;

  case 107:
#line 1089 "../../obj/src/GrammarParser.y"
  {
      auto mappings = yystack_[2].value.as < MappedExpressions::Ptr > ();
      yystack_[0].value.as < MappedExpression::Ptr > ()->setDelimiterToken( yystack_[1].value.as < CST::Token::Ptr > () );
      mappings->add( yystack_[0].value.as < MappedExpression::Ptr > () );
      yylhs.value.as < MappedExpressions::Ptr > () = mappings;
  }
#line 2874 "GrammarParser.cpp"
    break;

  case 108:
#line 1096 "../../obj/src/GrammarParser.y"
  {
      auto mappings = CST::make< MappedExpressions >( yylhs.location );
      mappings->add( yystack_[0].value.as < MappedExpression::Ptr > () );
      yylhs.value.as < MappedExpressions::Ptr > () = mappings;
  }
#line 2884 "GrammarParser.cpp"
    break;

  case 109:
#line 1105 "../../obj/src/GrammarParser.y"
  {
      const auto& expressions = CST::make< Expressions >( yystack_[2].location );
      expressions->add( yystack_[2].value.as < Expression::Ptr > () );
      yylhs.value.as < MappedExpression::Ptr > () = CST::make< MappedExpression >( yylhs.location, Token::unresolved(), expressions, Token::unresolved(), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
  }
#line 2894 "GrammarParser.cpp"
    break;

  case 110:
#line 1111 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < MappedExpression::Ptr > () = CST::make< MappedExpression >( yylhs.location, yystack_[4].value.as < CST::Token::Ptr > (), yystack_[3].value.as < Expressions::Ptr > (), yystack_[2].value.as < CST::Token::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
  }
#line 2902 "GrammarParser.cpp"
    break;

  case 111:
#line 1119 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < ReferenceLiteral::Ptr > () = CST::make< ReferenceLiteral >( yylhs.location, yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < IdentifierPath::Ptr > () );
  }
#line 2910 "GrammarParser.cpp"
    break;

  case 112:
#line 1127 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < GrammarLiteral::Ptr > () = CST::make< GrammarLiteral >( yylhs.location, yystack_[1].value.as < Expressions::Ptr > () );
      yylhs.value.as < GrammarLiteral::Ptr > ()->setLeftBracket( yystack_[2].value.as < CST::Token::Ptr > () );
  }
#line 2919 "GrammarParser.cpp"
    break;

  case 113:
#line 1136 "../../obj/src/GrammarParser.y"
  {
      auto terminals = yystack_[1].value.as < Expressions::Ptr > ();
      terminals->add( yystack_[0].value.as < Expression::Ptr > () );
      yylhs.value.as < Expressions::Ptr > () = terminals;
  }
#line 2929 "GrammarParser.cpp"
    break;

  case 114:
#line 1142 "../../obj/src/GrammarParser.y"
  {
      auto terminals = CST::make< Expressions >( yylhs.location );
      terminals->add( yystack_[0].value.as < Expression::Ptr > () );
      yylhs.value.as < Expressions::Ptr > () = terminals;
  }
#line 2939 "GrammarParser.cpp"
    break;

  case 115:
#line 1152 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = yystack_[0].value.as < DirectCallExpression::Ptr > ();
  }
#line 2947 "GrammarParser.cpp"
    break;

  case 116:
#line 1156 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = yystack_[0].value.as < ValueLiteral::Ptr > ();
  }
#line 2955 "GrammarParser.cpp"
    break;

  case 117:
#line 1160 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = yystack_[0].value.as < ValueLiteral::Ptr > ();
  }
#line 2963 "GrammarParser.cpp"
    break;

  case 118:
#line 1164 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = yystack_[0].value.as < ValueLiteral::Ptr > ();
  }
#line 2971 "GrammarParser.cpp"
    break;

  case 119:
#line 1168 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = yystack_[0].value.as < ReferenceLiteral::Ptr > ();
  }
#line 2979 "GrammarParser.cpp"
    break;

  case 120:
#line 1198 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < libscod::CST::Type::Ptr > () = yystack_[0].value.as < libscod::CST::Type::Ptr > ();
  }
#line 2987 "GrammarParser.cpp"
    break;

  case 121:
#line 1202 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < libscod::CST::Type::Ptr > () = yystack_[0].value.as < MappingType::Ptr > ();
  }
#line 2995 "GrammarParser.cpp"
    break;

  case 122:
#line 1210 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < libscod::CST::Type::Ptr > () = CST::make< BasicType >( yylhs.location, yystack_[0].value.as < IdentifierPath::Ptr > () );
  }
#line 3003 "GrammarParser.cpp"
    break;

  case 123:
#line 1214 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < libscod::CST::Type::Ptr > () = yystack_[0].value.as < libscod::CST::Type::Ptr > ();
  }
#line 3011 "GrammarParser.cpp"
    break;

  case 124:
#line 1222 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < libscod::CST::Type::Ptr > () = CST::make< PropertyType >( yylhs.location, yystack_[2].value.as < IdentifierPath::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < ValueLiteral::Ptr > () );
  }
#line 3019 "GrammarParser.cpp"
    break;

  case 125:
#line 1230 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < MappingType::Ptr > () = CST::make< MappingType >( yylhs.location, yystack_[2].value.as < Types::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < libscod::CST::Type::Ptr > () );
  }
#line 3027 "GrammarParser.cpp"
    break;

  case 126:
#line 1238 "../../obj/src/GrammarParser.y"
  {
      auto types = yystack_[2].value.as < Types::Ptr > ();
      yystack_[0].value.as < libscod::CST::Type::Ptr > ()->setDelimiterToken( yystack_[1].value.as < CST::Token::Ptr > () );
      types->add( yystack_[0].value.as < libscod::CST::Type::Ptr > () );
      yylhs.value.as < Types::Ptr > () = types;
  }
#line 3038 "GrammarParser.cpp"
    break;

  case 127:
#line 1245 "../../obj/src/GrammarParser.y"
  {
      auto types = CST::make< Types >( yylhs.location );
      types->add( yystack_[0].value.as < libscod::CST::Type::Ptr > () );
      yylhs.value.as < Types::Ptr > () = types;
  }
#line 3048 "GrammarParser.cpp"
    break;

  case 128:
#line 1259 "../../obj/src/GrammarParser.y"
  {
      auto variableBindings = yystack_[2].value.as < VariableBindings::Ptr > ();
      yystack_[0].value.as < VariableBinding::Ptr > ()->setDelimiterToken( yystack_[1].value.as < CST::Token::Ptr > () );
      variableBindings->add( yystack_[0].value.as < VariableBinding::Ptr > () );
      yylhs.value.as < VariableBindings::Ptr > () = variableBindings;
  }
#line 3059 "GrammarParser.cpp"
    break;

  case 129:
#line 1266 "../../obj/src/GrammarParser.y"
  {
      auto variableBindings = CST::make< VariableBindings >( yylhs.location );
      variableBindings->add( yystack_[0].value.as < VariableBinding::Ptr > () );
      yylhs.value.as < VariableBindings::Ptr > () = variableBindings;
  }
#line 3069 "GrammarParser.cpp"
    break;

  case 130:
#line 1276 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < VariableBinding::Ptr > () = CST::make< VariableBinding >( yylhs.location, yystack_[2].value.as < VariableDefinition::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
  }
#line 3077 "GrammarParser.cpp"
    break;

  case 131:
#line 1284 "../../obj/src/GrammarParser.y"
  {
      auto variable = yystack_[0].value.as < VariableDefinition::Ptr > ();
      variable->setAttributes( yystack_[1].value.as < Attributes::Ptr > () );
      yylhs.value.as < VariableDefinition::Ptr > () = variable;
  }
#line 3087 "GrammarParser.cpp"
    break;

  case 132:
#line 1290 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < VariableDefinition::Ptr > () = yystack_[0].value.as < VariableDefinition::Ptr > ();
  }
#line 3095 "GrammarParser.cpp"
    break;

  case 133:
#line 1298 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < VariableDefinition::Ptr > () = yystack_[0].value.as < VariableDefinition::Ptr > ();
  }
#line 3103 "GrammarParser.cpp"
    break;

  case 134:
#line 1302 "../../obj/src/GrammarParser.y"
  {
      const auto unresolvedType = CST::make< UnresolvedType >( yylhs.location );
      yylhs.value.as < VariableDefinition::Ptr > () = CST::make< VariableDefinition >( yylhs.location, yystack_[0].value.as < Identifier::Ptr > (), Token::unresolved(), unresolvedType );
  }
#line 3112 "GrammarParser.cpp"
    break;

  case 135:
#line 1311 "../../obj/src/GrammarParser.y"
  {
      auto variable = CST::make< VariableDefinition >( yylhs.location, yystack_[2].value.as < Identifier::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < libscod::CST::Type::Ptr > () );
      yylhs.value.as < VariableDefinition::Ptr > () = variable;
  }
#line 3121 "GrammarParser.cpp"
    break;

  case 136:
#line 1325 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 3129 "GrammarParser.cpp"
    break;

  case 137:
#line 1329 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Identifier::Ptr > () = CST::make< Identifier >( yylhs.location, "in" );
      yylhs.value.as < Identifier::Ptr > ()->setSpans( m_lexer.fetchSpansAndReset() );
  }
#line 3138 "GrammarParser.cpp"
    break;

  case 138:
#line 1338 "../../obj/src/GrammarParser.y"
  {
      auto path = yystack_[2].value.as < IdentifierPath::Ptr > ();
      yystack_[0].value.as < Identifier::Ptr > ()->setNamespaceToken( yystack_[1].value.as < CST::Token::Ptr > () );
      path->addIdentifier( yystack_[0].value.as < Identifier::Ptr > () );
      yylhs.value.as < IdentifierPath::Ptr > () = path;
  }
#line 3149 "GrammarParser.cpp"
    break;

  case 139:
#line 1345 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < IdentifierPath::Ptr > () = CST::make< IdentifierPath >( yylhs.location, yystack_[0].value.as < Identifier::Ptr > () );
  }
#line 3157 "GrammarParser.cpp"
    break;

  case 140:
#line 1357 "../../obj/src/GrammarParser.y"
  {
      auto attributes = yystack_[1].value.as < Attributes::Ptr > ();
      attributes->add( yystack_[0].value.as < Attribute::Ptr > () );
      yylhs.value.as < Attributes::Ptr > () = attributes;
  }
#line 3167 "GrammarParser.cpp"
    break;

  case 141:
#line 1363 "../../obj/src/GrammarParser.y"
  {
      auto attributes = CST::make< Attributes >( yylhs.location );
      attributes->add( yystack_[0].value.as < Attribute::Ptr > () );
      yylhs.value.as < Attributes::Ptr > () = attributes;
  }
#line 3177 "GrammarParser.cpp"
    break;

  case 142:
#line 1372 "../../obj/src/GrammarParser.y"
  {
      auto attribute = yystack_[1].value.as < BasicAttribute::Ptr > ();
      yystack_[1].value.as < BasicAttribute::Ptr > ()->setLeftBrace( yystack_[2].value.as < CST::Token::Ptr > () );
      yystack_[1].value.as < BasicAttribute::Ptr > ()->setRightBrace( yystack_[0].value.as < CST::Token::Ptr > () );
      yylhs.value.as < Attribute::Ptr > () = attribute;
  }
#line 3188 "GrammarParser.cpp"
    break;

  case 143:
#line 1379 "../../obj/src/GrammarParser.y"
  {
      auto attribute = yystack_[1].value.as < ExpressionAttribute::Ptr > ();
      yystack_[1].value.as < ExpressionAttribute::Ptr > ()->setLeftBrace( yystack_[2].value.as < CST::Token::Ptr > () );
      yystack_[1].value.as < ExpressionAttribute::Ptr > ()->setRightBrace( yystack_[0].value.as < CST::Token::Ptr > () );
      yylhs.value.as < Attribute::Ptr > () = attribute;
  }
#line 3199 "GrammarParser.cpp"
    break;

  case 144:
#line 1386 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Attribute::Ptr > () = nullptr;
  }
#line 3207 "GrammarParser.cpp"
    break;

  case 145:
#line 1393 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < BasicAttribute::Ptr > () = CST::make< BasicAttribute >( yylhs.location, yystack_[0].value.as < Identifier::Ptr > () );
  }
#line 3215 "GrammarParser.cpp"
    break;

  case 146:
#line 1400 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < ExpressionAttribute::Ptr > () = CST::make< ExpressionAttribute >( yylhs.location, yystack_[1].value.as < Identifier::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
  }
#line 3223 "GrammarParser.cpp"
    break;


#line 3227 "GrammarParser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    std::ptrdiff_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */
    if (!yyla.empty ())
      {
        symbol_number_type yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];

        int yyn = yypact_[+yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yy_error_token_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char Parser::yypact_ninf_ = -125;

  const short Parser::yytable_ninf_ = -136;

  const short
  Parser::yypact_[] =
  {
       6,  -125,    23,    65,    80,    29,  -125,    47,  -125,  -125,
     263,    51,    77,  -125,  -125,    13,    13,    13,    13,    13,
      13,    13,    13,    13,   158,  -125,  -125,  -125,  -125,  -125,
    -125,  -125,  -125,  -125,  -125,  -125,    67,   251,  -125,  -125,
    -125,  -125,  -125,   263,   263,   263,   172,   263,   303,  -125,
    -125,  -125,  -125,   388,  -125,  -125,  -125,  -125,  -125,  -125,
    -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,    70,
    -125,  -125,    84,    90,    94,    95,   118,   126,   137,   140,
     132,  -125,   144,   155,   156,  -125,  -125,  -125,  -125,  -125,
     159,   159,  -125,  -125,  -125,  -125,  -125,    99,  -125,   336,
     263,    -6,   372,     9,  -125,    46,  -125,   145,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,    13,   223,    13,    13,    13,    13,    13,    13,
     143,    13,   146,   143,   143,  -125,  -125,  -125,    89,   336,
    -125,   263,   263,  -125,    13,  -125,   303,   263,   425,   402,
     416,   305,   305,   159,   159,  -125,   434,   434,   154,   154,
     154,   154,  -125,   151,  -125,   123,   388,  -125,  -125,  -125,
       2,    31,    25,    32,  -125,    32,   165,    25,   166,   169,
     263,  -125,  -125,    32,    13,  -125,  -125,  -125,   164,   388,
     388,  -125,   145,   372,  -125,   388,  -125,  -125,    13,    13,
     150,   161,   263,   163,   263,  -125,  -125,  -125,   303,  -125,
    -125,   388,  -125,  -125,    73,   263,    11,    67,  -125,  -125,
    -125,  -125,  -125,  -125,   176,   388,     5,  -125,   175,  -125,
    -125,   174,    73,   358,   171,    33,  -125,    67,  -125,  -125,
    -125,  -125,   263,   163,    73,   263,    13,  -125,   163,  -125,
    -125,  -125,  -125,   388,  -125,  -125,   388,   178,   201,   163,
    -125
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       0,     4,     0,     0,     0,     0,   141,     0,   137,   136,
     145,     0,     0,     1,     9,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     6,     8,    10,    11,    12,
      13,    14,    15,    16,    17,    18,     0,     0,     3,   140,
     144,    96,    95,     0,     0,     0,     0,     0,     0,    97,
      98,    99,   100,   146,    59,    60,    62,    81,    63,    86,
      87,    88,    89,    90,    91,    92,    93,    94,   139,    82,
     142,   143,     0,     0,     0,     0,     0,     0,     0,     0,
     111,     5,     0,     0,     0,    27,    28,    29,     7,    66,
      64,    65,   115,   116,   117,   118,   119,     0,   114,     0,
       0,     0,    58,     0,   104,     0,   108,   139,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   112,   113,    61,     0,    58,
     101,     0,     0,   102,     0,   106,     0,     0,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,   138,     0,    83,     0,    58,   127,   120,   123,
      19,     0,   122,    20,   121,    21,     0,     0,   127,     0,
       0,    30,    31,    32,     0,    38,    39,    40,     0,    57,
     109,   103,     0,     0,   107,   105,    85,    84,     0,     0,
       0,     0,     0,     0,     0,   126,   125,   124,     0,    22,
      23,    24,    49,    50,     0,     0,     0,    25,    43,    44,
      45,    46,    47,    48,     0,   110,     0,   129,     0,   132,
     133,   134,     0,     0,     0,     0,    42,    26,    34,    35,
      36,    37,     0,     0,     0,     0,     0,   131,     0,    52,
      51,    41,    33,    54,    53,   128,   130,   127,    55,     0,
      56
  };

  const short
  Parser::yypgoto_[] =
  {
    -125,  -125,  -125,  -125,   206,   195,  -125,  -125,  -125,  -125,
    -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,    -2,   200,
     202,   203,  -125,  -119,  -125,  -125,  -125,  -125,  -125,  -125,
     -67,    -8,  -125,  -125,  -125,   -42,  -125,  -125,   -43,   -35,
     -24,   -11,   108,  -125,    98,    48,  -125,   102,    21,  -125,
    -125,   153,  -118,  -124,   124,   128,  -125,  -125,    17,  -125,
      30,  -125,    -1,    20,     0,     1,  -125,  -125
  };

  const short
  Parser::yydefgoto_[] =
  {
      -1,     3,     4,    24,    25,    26,    27,    28,    29,    30,
     209,    31,    32,    33,    34,   181,    35,   237,   238,   239,
     240,   241,   235,   217,   218,   219,   220,   221,   222,   223,
     101,   166,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,   103,   104,    65,   105,   106,    66,    67,
      97,    98,   167,   168,   169,   174,   171,   226,   227,   228,
     229,   230,    68,    69,    37,     6,    11,    12
  };

  const short
  Parser::yytable_[] =
  {
       5,    10,    53,    93,    92,   179,    39,   173,   175,     1,
     178,    94,   234,   183,    72,    73,    74,    75,    76,    77,
      78,    79,    95,   243,     7,    36,   212,   213,   214,     8,
     215,     8,    38,   138,  -121,    89,    90,    91,    39,    99,
     102,     8,  -121,    80,   140,    36,   141,   107,   212,   213,
     214,     8,   215,     2,    93,    92,   165,   244,    36,   143,
     216,   144,    94,   198,  -127,    13,   200,    96,     9,   122,
       9,   199,  -127,    95,   205,   206,     2,    82,    83,    84,
       9,    14,   216,   250,    15,    16,    17,    18,    19,    20,
       9,     8,   139,    21,    22,    40,   145,   236,   146,    70,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   122,   123,   251,     8,    96,   182,
       2,   162,   186,   187,   254,    71,   124,     2,   257,   258,
       9,    23,   125,   189,   190,   188,   126,   127,   193,   195,
     260,   141,   135,   192,   172,   172,   172,   177,   172,   172,
      23,   172,    49,    50,    51,    52,     9,   207,    -2,    14,
     128,   224,    15,    16,    17,    18,    19,    20,   129,   197,
     130,    21,    22,   131,   224,   141,   122,   132,   212,   213,
     214,     8,   215,   192,   113,   114,   115,   147,   133,   134,
       8,   115,   180,   224,   211,   184,   225,   196,   201,   202,
     193,   224,   203,    49,   204,     2,   224,   233,   245,    23,
     208,  -135,   216,   231,   232,   242,   246,   224,   172,   172,
       9,   249,   259,    23,   163,    49,    50,    51,    52,     9,
      81,   231,    88,    39,   253,   252,    85,   256,    86,    87,
     185,     8,   191,   231,   232,    41,    42,    43,   194,   210,
     136,   176,   170,    44,    45,    15,    16,    17,    18,    19,
      20,   255,   247,     0,    21,    22,   172,    46,    47,   164,
       0,     0,    48,     0,    23,     0,    49,    50,    51,    52,
       9,     8,     0,     0,     0,    41,    42,    43,     0,     0,
       0,     0,     0,    44,    45,     0,     0,     0,     2,     0,
       0,     0,    23,     0,     0,     0,     0,    46,    47,     0,
       0,     0,    48,     0,    23,     0,    49,    50,    51,    52,
       9,     8,     0,     0,     0,    41,    42,    43,     0,     0,
     108,   109,   110,    44,    45,   113,   114,   115,   116,   117,
     118,   119,   120,   121,     0,     0,     0,    46,   100,     0,
       0,     0,    48,     0,    23,     0,    49,    50,    51,    52,
       9,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,     0,     0,     0,   248,     0,
       0,     0,   137,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,     0,   142,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   108,     0,   110,
       0,     0,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   108,     0,     0,     0,     0,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   113,   114,   115,     0,     0,   118,
     119,   120,   121
  };

  const short
  Parser::yycheck_[] =
  {
       0,     2,    10,    46,    46,   129,     5,   125,   126,     3,
     128,    46,     1,   131,    15,    16,    17,    18,    19,    20,
      21,    22,    46,    18,     1,     4,    15,    16,    17,    18,
      19,    18,     3,   100,    32,    43,    44,    45,    37,    47,
      48,    18,    40,    23,    50,    24,    52,    48,    15,    16,
      17,    18,    19,    47,    97,    97,   123,    52,    37,    50,
      49,    52,    97,    32,    32,     0,    41,    46,    57,    44,
      57,    40,    40,    97,   198,   199,    47,    10,    11,    12,
      57,     1,    49,    50,     4,     5,     6,     7,     8,     9,
      57,    18,   100,    13,    14,    48,    50,   216,    52,    48,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,    44,    45,   235,    18,    97,   130,
      47,   122,   133,   134,   243,    48,    42,    47,   246,   248,
      57,    51,    42,   141,   142,    46,    42,    42,   146,   147,
     259,    52,    43,   144,   124,   125,   126,   127,   128,   129,
      51,   131,    53,    54,    55,    56,    57,   200,     0,     1,
      42,   203,     4,     5,     6,     7,     8,     9,    42,    46,
      33,    13,    14,    33,   216,    52,    44,    33,    15,    16,
      17,    18,    19,   184,    30,    31,    32,    42,    33,    33,
      18,    32,    49,   235,   202,    49,   204,    46,    33,    33,
     208,   243,    33,    53,    40,    47,   248,   215,    33,    51,
      49,    33,    49,   214,   214,    39,    42,   259,   198,   199,
      57,    50,    21,    51,     1,    53,    54,    55,    56,    57,
      24,   232,    37,   232,   242,   237,    36,   245,    36,    36,
     132,    18,   144,   244,   244,    22,    23,    24,   146,   201,
      97,   127,   124,    30,    31,     4,     5,     6,     7,     8,
       9,   244,   232,    -1,    13,    14,   246,    44,    45,    46,
      -1,    -1,    49,    -1,    51,    -1,    53,    54,    55,    56,
      57,    18,    -1,    -1,    -1,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    47,    -1,
      -1,    -1,    51,    -1,    -1,    -1,    -1,    44,    45,    -1,
      -1,    -1,    49,    -1,    51,    -1,    53,    54,    55,    56,
      57,    18,    -1,    -1,    -1,    22,    23,    24,    -1,    -1,
      25,    26,    27,    30,    31,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    44,    45,    -1,
      -1,    -1,    49,    -1,    51,    -1,    53,    54,    55,    56,
      57,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    20,    -1,
      -1,    -1,    46,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    40,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    25,    -1,    27,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    25,    -1,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    30,    31,    32,    -1,    -1,    35,
      36,    37,    38
  };

  const signed char
  Parser::yystos_[] =
  {
       0,     3,    47,    59,    60,   122,   123,     1,    18,    57,
     120,   124,   125,     0,     1,     4,     5,     6,     7,     8,
       9,    13,    14,    51,    61,    62,    63,    64,    65,    66,
      67,    69,    70,    71,    72,    74,   106,   122,     3,   123,
      48,    22,    23,    24,    30,    31,    44,    45,    49,    53,
      54,    55,    56,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   103,   106,   107,   120,   121,
      48,    48,   120,   120,   120,   120,   120,   120,   120,   120,
     121,    62,    10,    11,    12,    77,    78,    79,    63,    89,
      89,    89,    93,    96,    97,    98,   106,   108,   109,    89,
      45,    88,    89,   101,   102,   104,   105,   120,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    44,    45,    42,    42,    42,    42,    42,    42,
      33,    33,    33,    33,    33,    43,   109,    46,    88,    89,
      50,    52,    40,    50,    52,    50,    52,    42,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,   120,     1,    46,    88,    89,   110,   111,   112,
     113,   114,   121,   110,   113,   110,   112,   121,   110,   111,
      49,    73,    99,   110,    49,   100,    99,    99,    46,    89,
      89,   102,   120,    89,   105,    89,    46,    46,    32,    40,
      41,    33,    33,    33,    40,   111,   111,    96,    49,    68,
     103,    89,    15,    16,    17,    19,    49,    81,    82,    83,
      84,    85,    86,    87,    93,    89,   115,   116,   117,   118,
     119,   120,   122,    89,     1,    80,    81,    75,    76,    77,
      78,    79,    39,    18,    52,    33,    42,   118,    20,    50,
      50,    81,    76,    89,    81,   116,    89,   110,    81,    21,
      81
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    58,    59,    60,    60,    61,    61,    62,    62,    62,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    64,
      65,    66,    67,    68,    69,    70,    70,    71,    71,    71,
      72,    73,    74,    75,    75,    76,    76,    76,    77,    78,
      79,    80,    80,    81,    81,    81,    81,    81,    81,    82,
      83,    84,    84,    85,    86,    87,    87,    88,    88,    89,
      89,    90,    90,    90,    90,    90,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    92,    93,    93,    93,    93,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    95,    95,    96,    97,    97,
      98,    99,   100,   101,   101,   102,   103,   104,   104,   105,
     105,   106,   107,   108,   108,   109,   109,   109,   109,   109,
     110,   110,   111,   111,   112,   113,   114,   114,   115,   115,
     116,   117,   117,   118,   118,   119,   120,   120,   121,   121,
     122,   122,   123,   123,   123,   124,   125
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     2,     2,     1,     2,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     6,     1,     6,     6,     7,     2,     2,     2,
       4,     1,     4,     2,     1,     1,     1,     1,     3,     3,
       3,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     4,     3,     4,     6,     3,     1,     1,
       1,     3,     1,     1,     2,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     3,     4,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     1,     3,     3,     3,     1,     3,
       5,     2,     3,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     1,     3,     1,
       3,     2,     1,     1,     1,     3,     1,     1,     3,     1,
       2,     1,     3,     3,     3,     1,     2
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"SCOD\"", "\"memory\"",
  "\"register\"", "\"field\"", "\"format\"", "\"buffer\"",
  "\"instruction\"", "\"decoding\"", "\"syntax\"", "\"expansion\"",
  "\"enumeration\"", "\"using\"", "\"skip\"", "\"abstract\"", "\"let\"",
  "\"in\"", "\"if\"", "\"then\"", "\"else\"", "\"false\"", "\"true\"",
  "\"not\"", "\"and\"", "\"or\"", "\"xor\"", "\"implies\"", "\"=>\"",
  "\"+\"", "\"-\"", "\"*\"", "\"=\"", "\"!=\"", "\"<\"", "\"<=\"", "\">\"",
  "\">=\"", "\":=\"", "\"->\"", "\"'\"", "\":\"", "\";\"", "\"::\"",
  "\"(\"", "\")\"", "\"[\"", "\"]\"", "\"{\"", "\"}\"", "\"@\"", "\",\"",
  "\"integer\"", "\"binary\"", "\"hexadecimal\"", "\"string\"",
  "\"identifier\"", "$accept", "Specification", "Header", "Definitions",
  "AttributedDefinition", "Definition", "MemoryDefinition",
  "RegisterDefinition", "FieldDefinition", "FormatDefinition",
  "FormatFields", "BufferDefinition", "InstructionDefinition",
  "OptionDefinition", "EnumerationDefinition", "Enumerators",
  "UsingDefinition", "Options", "Option", "DecodingOption", "SyntaxOption",
  "ExpansionOption", "Statements", "Statement", "SkipStatement",
  "AbstractStatement", "BlockStatement", "LetStatement",
  "AssignmentStatement", "ConditionalStatement", "Terms", "Term",
  "Expression", "OperatorExpression", "CallExpression",
  "DirectCallExpression", "Literal", "BooleanLiteral", "IntegerLiteral",
  "BinaryLiteral", "StringLiteral", "SetLiteral", "RecordLiteral",
  "Assignments", "Assignment", "MappingLiteral", "Mappings", "Mapping",
  "ReferenceLiteral", "GrammarLiteral", "Terminals", "Terminal", "Type",
  "BasicType", "PropertyType", "MappingType", "ArgumentTypes",
  "VariableBindings", "VariableBinding", "AttributedVariable", "Variable",
  "TypedVariable", "Identifier", "IdentifierPath", "Attributes",
  "Attribute", "BasicAttribute", "ExpressionAttribute", YY_NULLPTR
  };

#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   330,   330,   340,   346,   354,   360,   370,   376,   380,
     388,   392,   396,   400,   404,   408,   412,   416,   420,   428,
     436,   448,   456,   463,   471,   479,   484,   492,   496,   500,
     508,   515,   524,   536,   542,   557,   561,   565,   573,   581,
     589,   601,   607,   617,   621,   625,   629,   633,   637,   645,
     653,   662,   666,   675,   683,   691,   696,   708,   715,   725,
     729,   737,   741,   745,   749,   753,   765,   769,   773,   777,
     781,   785,   790,   798,   806,   810,   814,   818,   822,   826,
     830,   838,   846,   851,   856,   860,   952,   956,   960,   964,
     968,   972,   976,   980,   984,   992,   998,  1008,  1016,  1020,
    1028,  1036,  1046,  1055,  1062,  1071,  1079,  1088,  1095,  1104,
    1110,  1118,  1126,  1135,  1141,  1151,  1155,  1159,  1163,  1167,
    1197,  1201,  1209,  1213,  1221,  1229,  1237,  1244,  1258,  1265,
    1275,  1283,  1289,  1297,  1301,  1310,  1324,  1328,  1337,  1344,
    1356,  1362,  1371,  1378,  1385,  1392,  1399
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


#line 47 "../../obj/src/GrammarParser.y"
} // libscod
#line 3858 "GrammarParser.cpp"

#line 1405 "../../obj/src/GrammarParser.y"


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
