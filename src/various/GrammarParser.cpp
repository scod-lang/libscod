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
#line 94 "../../obj/src/GrammarParser.y"

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

#line 48 "../../obj/src/GrammarParser.y"
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
      case 105: // AssignmentStatement
        value.YY_MOVE_OR_COPY< AssignmentStatement::Ptr > (YY_MOVE (that.value));
        break;

      case 147: // Attribute
        value.YY_MOVE_OR_COPY< Attribute::Ptr > (YY_MOVE (that.value));
        break;

      case 146: // Attributes
        value.YY_MOVE_OR_COPY< Attributes::Ptr > (YY_MOVE (that.value));
        break;

      case 148: // BasicAttribute
        value.YY_MOVE_OR_COPY< BasicAttribute::Ptr > (YY_MOVE (that.value));
        break;

      case 102: // BlockStatement
        value.YY_MOVE_OR_COPY< BlockStatement::Ptr > (YY_MOVE (that.value));
        break;

      case 81: // BufferDefinition
        value.YY_MOVE_OR_COPY< BufferDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 3: // "SCOD"
      case 4: // "memory"
      case 5: // "register"
      case 6: // "field"
      case 7: // "format"
      case 8: // "buffer"
      case 9: // "instruction"
      case 10: // "microprocessor"
      case 11: // "cache"
      case 12: // "interconnect"
      case 13: // "decoding"
      case 14: // "syntax"
      case 15: // "expansion"
      case 16: // "stage"
      case 17: // "enumeration"
      case 18: // "using"
      case 19: // "skip"
      case 20: // "abstract"
      case 21: // "let"
      case 22: // "in"
      case 23: // "if"
      case 24: // "then"
      case 25: // "else"
      case 26: // "false"
      case 27: // "true"
      case 28: // "not"
      case 29: // "and"
      case 30: // "or"
      case 31: // "xor"
      case 32: // "implies"
      case 33: // "=>"
      case 34: // "+"
      case 35: // "(+)"
      case 36: // "-"
      case 37: // "(-)"
      case 38: // "*"
      case 39: // "<<"
      case 40: // "(<<)"
      case 41: // ">>"
      case 42: // "(>>)"
      case 43: // "="
      case 44: // "!="
      case 45: // "<"
      case 46: // "<="
      case 47: // ">"
      case 48: // ">="
      case 49: // ":="
      case 50: // "->"
      case 51: // "'"
      case 52: // ":"
      case 53: // ";"
      case 54: // "::"
      case 55: // "("
      case 56: // ")"
      case 57: // "["
      case 58: // "]"
      case 59: // "{"
      case 60: // "}"
      case 61: // "@"
      case 62: // ","
      case 63: // "."
      case 64: // ".."
        value.YY_MOVE_OR_COPY< CST::Token::Ptr > (YY_MOVE (that.value));
        break;

      case 84: // CacheDefinition
        value.YY_MOVE_OR_COPY< CacheDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 113: // CallExpression
        value.YY_MOVE_OR_COPY< CallExpression::Ptr > (YY_MOVE (that.value));
        break;

      case 103: // CallStatement
        value.YY_MOVE_OR_COPY< CallStatement::Ptr > (YY_MOVE (that.value));
        break;

      case 111: // ConditionalExpression
        value.YY_MOVE_OR_COPY< ConditionalExpression::Ptr > (YY_MOVE (that.value));
        break;

      case 106: // ConditionalStatement
        value.YY_MOVE_OR_COPY< ConditionalStatement::Ptr > (YY_MOVE (that.value));
        break;

      case 92: // DecodingOption
        value.YY_MOVE_OR_COPY< DecodingOption::Ptr > (YY_MOVE (that.value));
        break;

      case 74: // AttributedDefinition
      case 75: // Definition
        value.YY_MOVE_OR_COPY< Definition::Ptr > (YY_MOVE (that.value));
        break;

      case 73: // Definitions
        value.YY_MOVE_OR_COPY< Definitions::Ptr > (YY_MOVE (that.value));
        break;

      case 114: // DirectCallExpression
        value.YY_MOVE_OR_COPY< DirectCallExpression::Ptr > (YY_MOVE (that.value));
        break;

      case 87: // EnumerationDefinition
        value.YY_MOVE_OR_COPY< EnumerationDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 94: // ExpansionOption
        value.YY_MOVE_OR_COPY< ExpansionOption::Ptr > (YY_MOVE (that.value));
        break;

      case 108: // Term
      case 109: // Expression
      case 112: // OperatorExpression
      case 133: // Terminal
        value.YY_MOVE_OR_COPY< Expression::Ptr > (YY_MOVE (that.value));
        break;

      case 149: // ExpressionAttribute
        value.YY_MOVE_OR_COPY< ExpressionAttribute::Ptr > (YY_MOVE (that.value));
        break;

      case 107: // Terms
      case 132: // Terminals
        value.YY_MOVE_OR_COPY< Expressions::Ptr > (YY_MOVE (that.value));
        break;

      case 78: // FieldDefinition
        value.YY_MOVE_OR_COPY< FieldDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 79: // FormatDefinition
        value.YY_MOVE_OR_COPY< FormatDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 131: // GrammarLiteral
        value.YY_MOVE_OR_COPY< GrammarLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 72: // Header
        value.YY_MOVE_OR_COPY< HeaderDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 69: // "identifier"
      case 144: // Identifier
        value.YY_MOVE_OR_COPY< Identifier::Ptr > (YY_MOVE (that.value));
        break;

      case 145: // IdentifierPath
        value.YY_MOVE_OR_COPY< IdentifierPath::Ptr > (YY_MOVE (that.value));
        break;

      case 82: // InstructionDefinition
        value.YY_MOVE_OR_COPY< InstructionDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 85: // InterconnectDefinition
        value.YY_MOVE_OR_COPY< InterconnectDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 110: // LetExpression
        value.YY_MOVE_OR_COPY< LetExpression::Ptr > (YY_MOVE (that.value));
        break;

      case 104: // LetStatement
        value.YY_MOVE_OR_COPY< LetStatement::Ptr > (YY_MOVE (that.value));
        break;

      case 122: // ListLiteral
        value.YY_MOVE_OR_COPY< ListLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 116: // Literal
        value.YY_MOVE_OR_COPY< Literal::Ptr > (YY_MOVE (that.value));
        break;

      case 129: // Mapping
        value.YY_MOVE_OR_COPY< MappedExpression::Ptr > (YY_MOVE (that.value));
        break;

      case 128: // Mappings
        value.YY_MOVE_OR_COPY< MappedExpressions::Ptr > (YY_MOVE (that.value));
        break;

      case 80: // FormatFields
      case 127: // MappingLiteral
        value.YY_MOVE_OR_COPY< MappingLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 137: // MappingType
        value.YY_MOVE_OR_COPY< MappingType::Ptr > (YY_MOVE (that.value));
        break;

      case 76: // MemoryDefinition
        value.YY_MOVE_OR_COPY< MemoryDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 115: // MethodCallExpression
        value.YY_MOVE_OR_COPY< MethodCallExpression::Ptr > (YY_MOVE (that.value));
        break;

      case 83: // MicroProcessorDefinition
        value.YY_MOVE_OR_COPY< MicroProcessorDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 126: // Assignment
        value.YY_MOVE_OR_COPY< NamedExpression::Ptr > (YY_MOVE (that.value));
        break;

      case 125: // Assignments
        value.YY_MOVE_OR_COPY< NamedExpressions::Ptr > (YY_MOVE (that.value));
        break;

      case 91: // InstructionOption
      case 96: // MicroProcessorOption
        value.YY_MOVE_OR_COPY< Option::Ptr > (YY_MOVE (that.value));
        break;

      case 86: // OptionDefinition
        value.YY_MOVE_OR_COPY< OptionDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 90: // InstructionOptions
      case 95: // MicroProcessorOptions
        value.YY_MOVE_OR_COPY< Options::Ptr > (YY_MOVE (that.value));
        break;

      case 123: // RangeLiteral
        value.YY_MOVE_OR_COPY< RangeLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 124: // RecordLiteral
        value.YY_MOVE_OR_COPY< RecordLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 130: // ReferenceLiteral
        value.YY_MOVE_OR_COPY< ReferenceLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 77: // RegisterDefinition
        value.YY_MOVE_OR_COPY< RegisterDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 88: // Enumerators
      case 121: // SetLiteral
        value.YY_MOVE_OR_COPY< SetLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 100: // SkipStatement
      case 101: // AbstractStatement
        value.YY_MOVE_OR_COPY< SkipStatement::Ptr > (YY_MOVE (that.value));
        break;

      case 71: // Specification
        value.YY_MOVE_OR_COPY< Specification::Ptr > (YY_MOVE (that.value));
        break;

      case 97: // StageOption
        value.YY_MOVE_OR_COPY< StageOption::Ptr > (YY_MOVE (that.value));
        break;

      case 99: // Statement
        value.YY_MOVE_OR_COPY< Statement::Ptr > (YY_MOVE (that.value));
        break;

      case 98: // Statements
        value.YY_MOVE_OR_COPY< Statements::Ptr > (YY_MOVE (that.value));
        break;

      case 93: // SyntaxOption
        value.YY_MOVE_OR_COPY< SyntaxOption::Ptr > (YY_MOVE (that.value));
        break;

      case 138: // ArgumentTypes
        value.YY_MOVE_OR_COPY< Types::Ptr > (YY_MOVE (that.value));
        break;

      case 89: // UsingDefinition
        value.YY_MOVE_OR_COPY< UsingDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 65: // "integer"
      case 66: // "binary"
      case 67: // "hexadecimal"
      case 68: // "string"
      case 117: // BooleanLiteral
      case 118: // IntegerLiteral
      case 119: // BinaryLiteral
      case 120: // StringLiteral
        value.YY_MOVE_OR_COPY< ValueLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 140: // VariableBinding
        value.YY_MOVE_OR_COPY< VariableBinding::Ptr > (YY_MOVE (that.value));
        break;

      case 139: // VariableBindings
        value.YY_MOVE_OR_COPY< VariableBindings::Ptr > (YY_MOVE (that.value));
        break;

      case 141: // AttributedVariable
      case 142: // Variable
      case 143: // TypedVariable
        value.YY_MOVE_OR_COPY< VariableDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 134: // Type
      case 135: // BasicType
      case 136: // PropertyType
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
      case 105: // AssignmentStatement
        value.move< AssignmentStatement::Ptr > (YY_MOVE (that.value));
        break;

      case 147: // Attribute
        value.move< Attribute::Ptr > (YY_MOVE (that.value));
        break;

      case 146: // Attributes
        value.move< Attributes::Ptr > (YY_MOVE (that.value));
        break;

      case 148: // BasicAttribute
        value.move< BasicAttribute::Ptr > (YY_MOVE (that.value));
        break;

      case 102: // BlockStatement
        value.move< BlockStatement::Ptr > (YY_MOVE (that.value));
        break;

      case 81: // BufferDefinition
        value.move< BufferDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 3: // "SCOD"
      case 4: // "memory"
      case 5: // "register"
      case 6: // "field"
      case 7: // "format"
      case 8: // "buffer"
      case 9: // "instruction"
      case 10: // "microprocessor"
      case 11: // "cache"
      case 12: // "interconnect"
      case 13: // "decoding"
      case 14: // "syntax"
      case 15: // "expansion"
      case 16: // "stage"
      case 17: // "enumeration"
      case 18: // "using"
      case 19: // "skip"
      case 20: // "abstract"
      case 21: // "let"
      case 22: // "in"
      case 23: // "if"
      case 24: // "then"
      case 25: // "else"
      case 26: // "false"
      case 27: // "true"
      case 28: // "not"
      case 29: // "and"
      case 30: // "or"
      case 31: // "xor"
      case 32: // "implies"
      case 33: // "=>"
      case 34: // "+"
      case 35: // "(+)"
      case 36: // "-"
      case 37: // "(-)"
      case 38: // "*"
      case 39: // "<<"
      case 40: // "(<<)"
      case 41: // ">>"
      case 42: // "(>>)"
      case 43: // "="
      case 44: // "!="
      case 45: // "<"
      case 46: // "<="
      case 47: // ">"
      case 48: // ">="
      case 49: // ":="
      case 50: // "->"
      case 51: // "'"
      case 52: // ":"
      case 53: // ";"
      case 54: // "::"
      case 55: // "("
      case 56: // ")"
      case 57: // "["
      case 58: // "]"
      case 59: // "{"
      case 60: // "}"
      case 61: // "@"
      case 62: // ","
      case 63: // "."
      case 64: // ".."
        value.move< CST::Token::Ptr > (YY_MOVE (that.value));
        break;

      case 84: // CacheDefinition
        value.move< CacheDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 113: // CallExpression
        value.move< CallExpression::Ptr > (YY_MOVE (that.value));
        break;

      case 103: // CallStatement
        value.move< CallStatement::Ptr > (YY_MOVE (that.value));
        break;

      case 111: // ConditionalExpression
        value.move< ConditionalExpression::Ptr > (YY_MOVE (that.value));
        break;

      case 106: // ConditionalStatement
        value.move< ConditionalStatement::Ptr > (YY_MOVE (that.value));
        break;

      case 92: // DecodingOption
        value.move< DecodingOption::Ptr > (YY_MOVE (that.value));
        break;

      case 74: // AttributedDefinition
      case 75: // Definition
        value.move< Definition::Ptr > (YY_MOVE (that.value));
        break;

      case 73: // Definitions
        value.move< Definitions::Ptr > (YY_MOVE (that.value));
        break;

      case 114: // DirectCallExpression
        value.move< DirectCallExpression::Ptr > (YY_MOVE (that.value));
        break;

      case 87: // EnumerationDefinition
        value.move< EnumerationDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 94: // ExpansionOption
        value.move< ExpansionOption::Ptr > (YY_MOVE (that.value));
        break;

      case 108: // Term
      case 109: // Expression
      case 112: // OperatorExpression
      case 133: // Terminal
        value.move< Expression::Ptr > (YY_MOVE (that.value));
        break;

      case 149: // ExpressionAttribute
        value.move< ExpressionAttribute::Ptr > (YY_MOVE (that.value));
        break;

      case 107: // Terms
      case 132: // Terminals
        value.move< Expressions::Ptr > (YY_MOVE (that.value));
        break;

      case 78: // FieldDefinition
        value.move< FieldDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 79: // FormatDefinition
        value.move< FormatDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 131: // GrammarLiteral
        value.move< GrammarLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 72: // Header
        value.move< HeaderDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 69: // "identifier"
      case 144: // Identifier
        value.move< Identifier::Ptr > (YY_MOVE (that.value));
        break;

      case 145: // IdentifierPath
        value.move< IdentifierPath::Ptr > (YY_MOVE (that.value));
        break;

      case 82: // InstructionDefinition
        value.move< InstructionDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 85: // InterconnectDefinition
        value.move< InterconnectDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 110: // LetExpression
        value.move< LetExpression::Ptr > (YY_MOVE (that.value));
        break;

      case 104: // LetStatement
        value.move< LetStatement::Ptr > (YY_MOVE (that.value));
        break;

      case 122: // ListLiteral
        value.move< ListLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 116: // Literal
        value.move< Literal::Ptr > (YY_MOVE (that.value));
        break;

      case 129: // Mapping
        value.move< MappedExpression::Ptr > (YY_MOVE (that.value));
        break;

      case 128: // Mappings
        value.move< MappedExpressions::Ptr > (YY_MOVE (that.value));
        break;

      case 80: // FormatFields
      case 127: // MappingLiteral
        value.move< MappingLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 137: // MappingType
        value.move< MappingType::Ptr > (YY_MOVE (that.value));
        break;

      case 76: // MemoryDefinition
        value.move< MemoryDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 115: // MethodCallExpression
        value.move< MethodCallExpression::Ptr > (YY_MOVE (that.value));
        break;

      case 83: // MicroProcessorDefinition
        value.move< MicroProcessorDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 126: // Assignment
        value.move< NamedExpression::Ptr > (YY_MOVE (that.value));
        break;

      case 125: // Assignments
        value.move< NamedExpressions::Ptr > (YY_MOVE (that.value));
        break;

      case 91: // InstructionOption
      case 96: // MicroProcessorOption
        value.move< Option::Ptr > (YY_MOVE (that.value));
        break;

      case 86: // OptionDefinition
        value.move< OptionDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 90: // InstructionOptions
      case 95: // MicroProcessorOptions
        value.move< Options::Ptr > (YY_MOVE (that.value));
        break;

      case 123: // RangeLiteral
        value.move< RangeLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 124: // RecordLiteral
        value.move< RecordLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 130: // ReferenceLiteral
        value.move< ReferenceLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 77: // RegisterDefinition
        value.move< RegisterDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 88: // Enumerators
      case 121: // SetLiteral
        value.move< SetLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 100: // SkipStatement
      case 101: // AbstractStatement
        value.move< SkipStatement::Ptr > (YY_MOVE (that.value));
        break;

      case 71: // Specification
        value.move< Specification::Ptr > (YY_MOVE (that.value));
        break;

      case 97: // StageOption
        value.move< StageOption::Ptr > (YY_MOVE (that.value));
        break;

      case 99: // Statement
        value.move< Statement::Ptr > (YY_MOVE (that.value));
        break;

      case 98: // Statements
        value.move< Statements::Ptr > (YY_MOVE (that.value));
        break;

      case 93: // SyntaxOption
        value.move< SyntaxOption::Ptr > (YY_MOVE (that.value));
        break;

      case 138: // ArgumentTypes
        value.move< Types::Ptr > (YY_MOVE (that.value));
        break;

      case 89: // UsingDefinition
        value.move< UsingDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 65: // "integer"
      case 66: // "binary"
      case 67: // "hexadecimal"
      case 68: // "string"
      case 117: // BooleanLiteral
      case 118: // IntegerLiteral
      case 119: // BinaryLiteral
      case 120: // StringLiteral
        value.move< ValueLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 140: // VariableBinding
        value.move< VariableBinding::Ptr > (YY_MOVE (that.value));
        break;

      case 139: // VariableBindings
        value.move< VariableBindings::Ptr > (YY_MOVE (that.value));
        break;

      case 141: // AttributedVariable
      case 142: // Variable
      case 143: // TypedVariable
        value.move< VariableDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 134: // Type
      case 135: // BasicType
      case 136: // PropertyType
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
      case 105: // AssignmentStatement
        value.copy< AssignmentStatement::Ptr > (that.value);
        break;

      case 147: // Attribute
        value.copy< Attribute::Ptr > (that.value);
        break;

      case 146: // Attributes
        value.copy< Attributes::Ptr > (that.value);
        break;

      case 148: // BasicAttribute
        value.copy< BasicAttribute::Ptr > (that.value);
        break;

      case 102: // BlockStatement
        value.copy< BlockStatement::Ptr > (that.value);
        break;

      case 81: // BufferDefinition
        value.copy< BufferDefinition::Ptr > (that.value);
        break;

      case 3: // "SCOD"
      case 4: // "memory"
      case 5: // "register"
      case 6: // "field"
      case 7: // "format"
      case 8: // "buffer"
      case 9: // "instruction"
      case 10: // "microprocessor"
      case 11: // "cache"
      case 12: // "interconnect"
      case 13: // "decoding"
      case 14: // "syntax"
      case 15: // "expansion"
      case 16: // "stage"
      case 17: // "enumeration"
      case 18: // "using"
      case 19: // "skip"
      case 20: // "abstract"
      case 21: // "let"
      case 22: // "in"
      case 23: // "if"
      case 24: // "then"
      case 25: // "else"
      case 26: // "false"
      case 27: // "true"
      case 28: // "not"
      case 29: // "and"
      case 30: // "or"
      case 31: // "xor"
      case 32: // "implies"
      case 33: // "=>"
      case 34: // "+"
      case 35: // "(+)"
      case 36: // "-"
      case 37: // "(-)"
      case 38: // "*"
      case 39: // "<<"
      case 40: // "(<<)"
      case 41: // ">>"
      case 42: // "(>>)"
      case 43: // "="
      case 44: // "!="
      case 45: // "<"
      case 46: // "<="
      case 47: // ">"
      case 48: // ">="
      case 49: // ":="
      case 50: // "->"
      case 51: // "'"
      case 52: // ":"
      case 53: // ";"
      case 54: // "::"
      case 55: // "("
      case 56: // ")"
      case 57: // "["
      case 58: // "]"
      case 59: // "{"
      case 60: // "}"
      case 61: // "@"
      case 62: // ","
      case 63: // "."
      case 64: // ".."
        value.copy< CST::Token::Ptr > (that.value);
        break;

      case 84: // CacheDefinition
        value.copy< CacheDefinition::Ptr > (that.value);
        break;

      case 113: // CallExpression
        value.copy< CallExpression::Ptr > (that.value);
        break;

      case 103: // CallStatement
        value.copy< CallStatement::Ptr > (that.value);
        break;

      case 111: // ConditionalExpression
        value.copy< ConditionalExpression::Ptr > (that.value);
        break;

      case 106: // ConditionalStatement
        value.copy< ConditionalStatement::Ptr > (that.value);
        break;

      case 92: // DecodingOption
        value.copy< DecodingOption::Ptr > (that.value);
        break;

      case 74: // AttributedDefinition
      case 75: // Definition
        value.copy< Definition::Ptr > (that.value);
        break;

      case 73: // Definitions
        value.copy< Definitions::Ptr > (that.value);
        break;

      case 114: // DirectCallExpression
        value.copy< DirectCallExpression::Ptr > (that.value);
        break;

      case 87: // EnumerationDefinition
        value.copy< EnumerationDefinition::Ptr > (that.value);
        break;

      case 94: // ExpansionOption
        value.copy< ExpansionOption::Ptr > (that.value);
        break;

      case 108: // Term
      case 109: // Expression
      case 112: // OperatorExpression
      case 133: // Terminal
        value.copy< Expression::Ptr > (that.value);
        break;

      case 149: // ExpressionAttribute
        value.copy< ExpressionAttribute::Ptr > (that.value);
        break;

      case 107: // Terms
      case 132: // Terminals
        value.copy< Expressions::Ptr > (that.value);
        break;

      case 78: // FieldDefinition
        value.copy< FieldDefinition::Ptr > (that.value);
        break;

      case 79: // FormatDefinition
        value.copy< FormatDefinition::Ptr > (that.value);
        break;

      case 131: // GrammarLiteral
        value.copy< GrammarLiteral::Ptr > (that.value);
        break;

      case 72: // Header
        value.copy< HeaderDefinition::Ptr > (that.value);
        break;

      case 69: // "identifier"
      case 144: // Identifier
        value.copy< Identifier::Ptr > (that.value);
        break;

      case 145: // IdentifierPath
        value.copy< IdentifierPath::Ptr > (that.value);
        break;

      case 82: // InstructionDefinition
        value.copy< InstructionDefinition::Ptr > (that.value);
        break;

      case 85: // InterconnectDefinition
        value.copy< InterconnectDefinition::Ptr > (that.value);
        break;

      case 110: // LetExpression
        value.copy< LetExpression::Ptr > (that.value);
        break;

      case 104: // LetStatement
        value.copy< LetStatement::Ptr > (that.value);
        break;

      case 122: // ListLiteral
        value.copy< ListLiteral::Ptr > (that.value);
        break;

      case 116: // Literal
        value.copy< Literal::Ptr > (that.value);
        break;

      case 129: // Mapping
        value.copy< MappedExpression::Ptr > (that.value);
        break;

      case 128: // Mappings
        value.copy< MappedExpressions::Ptr > (that.value);
        break;

      case 80: // FormatFields
      case 127: // MappingLiteral
        value.copy< MappingLiteral::Ptr > (that.value);
        break;

      case 137: // MappingType
        value.copy< MappingType::Ptr > (that.value);
        break;

      case 76: // MemoryDefinition
        value.copy< MemoryDefinition::Ptr > (that.value);
        break;

      case 115: // MethodCallExpression
        value.copy< MethodCallExpression::Ptr > (that.value);
        break;

      case 83: // MicroProcessorDefinition
        value.copy< MicroProcessorDefinition::Ptr > (that.value);
        break;

      case 126: // Assignment
        value.copy< NamedExpression::Ptr > (that.value);
        break;

      case 125: // Assignments
        value.copy< NamedExpressions::Ptr > (that.value);
        break;

      case 91: // InstructionOption
      case 96: // MicroProcessorOption
        value.copy< Option::Ptr > (that.value);
        break;

      case 86: // OptionDefinition
        value.copy< OptionDefinition::Ptr > (that.value);
        break;

      case 90: // InstructionOptions
      case 95: // MicroProcessorOptions
        value.copy< Options::Ptr > (that.value);
        break;

      case 123: // RangeLiteral
        value.copy< RangeLiteral::Ptr > (that.value);
        break;

      case 124: // RecordLiteral
        value.copy< RecordLiteral::Ptr > (that.value);
        break;

      case 130: // ReferenceLiteral
        value.copy< ReferenceLiteral::Ptr > (that.value);
        break;

      case 77: // RegisterDefinition
        value.copy< RegisterDefinition::Ptr > (that.value);
        break;

      case 88: // Enumerators
      case 121: // SetLiteral
        value.copy< SetLiteral::Ptr > (that.value);
        break;

      case 100: // SkipStatement
      case 101: // AbstractStatement
        value.copy< SkipStatement::Ptr > (that.value);
        break;

      case 71: // Specification
        value.copy< Specification::Ptr > (that.value);
        break;

      case 97: // StageOption
        value.copy< StageOption::Ptr > (that.value);
        break;

      case 99: // Statement
        value.copy< Statement::Ptr > (that.value);
        break;

      case 98: // Statements
        value.copy< Statements::Ptr > (that.value);
        break;

      case 93: // SyntaxOption
        value.copy< SyntaxOption::Ptr > (that.value);
        break;

      case 138: // ArgumentTypes
        value.copy< Types::Ptr > (that.value);
        break;

      case 89: // UsingDefinition
        value.copy< UsingDefinition::Ptr > (that.value);
        break;

      case 65: // "integer"
      case 66: // "binary"
      case 67: // "hexadecimal"
      case 68: // "string"
      case 117: // BooleanLiteral
      case 118: // IntegerLiteral
      case 119: // BinaryLiteral
      case 120: // StringLiteral
        value.copy< ValueLiteral::Ptr > (that.value);
        break;

      case 140: // VariableBinding
        value.copy< VariableBinding::Ptr > (that.value);
        break;

      case 139: // VariableBindings
        value.copy< VariableBindings::Ptr > (that.value);
        break;

      case 141: // AttributedVariable
      case 142: // Variable
      case 143: // TypedVariable
        value.copy< VariableDefinition::Ptr > (that.value);
        break;

      case 134: // Type
      case 135: // BasicType
      case 136: // PropertyType
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
      case 105: // AssignmentStatement
        value.move< AssignmentStatement::Ptr > (that.value);
        break;

      case 147: // Attribute
        value.move< Attribute::Ptr > (that.value);
        break;

      case 146: // Attributes
        value.move< Attributes::Ptr > (that.value);
        break;

      case 148: // BasicAttribute
        value.move< BasicAttribute::Ptr > (that.value);
        break;

      case 102: // BlockStatement
        value.move< BlockStatement::Ptr > (that.value);
        break;

      case 81: // BufferDefinition
        value.move< BufferDefinition::Ptr > (that.value);
        break;

      case 3: // "SCOD"
      case 4: // "memory"
      case 5: // "register"
      case 6: // "field"
      case 7: // "format"
      case 8: // "buffer"
      case 9: // "instruction"
      case 10: // "microprocessor"
      case 11: // "cache"
      case 12: // "interconnect"
      case 13: // "decoding"
      case 14: // "syntax"
      case 15: // "expansion"
      case 16: // "stage"
      case 17: // "enumeration"
      case 18: // "using"
      case 19: // "skip"
      case 20: // "abstract"
      case 21: // "let"
      case 22: // "in"
      case 23: // "if"
      case 24: // "then"
      case 25: // "else"
      case 26: // "false"
      case 27: // "true"
      case 28: // "not"
      case 29: // "and"
      case 30: // "or"
      case 31: // "xor"
      case 32: // "implies"
      case 33: // "=>"
      case 34: // "+"
      case 35: // "(+)"
      case 36: // "-"
      case 37: // "(-)"
      case 38: // "*"
      case 39: // "<<"
      case 40: // "(<<)"
      case 41: // ">>"
      case 42: // "(>>)"
      case 43: // "="
      case 44: // "!="
      case 45: // "<"
      case 46: // "<="
      case 47: // ">"
      case 48: // ">="
      case 49: // ":="
      case 50: // "->"
      case 51: // "'"
      case 52: // ":"
      case 53: // ";"
      case 54: // "::"
      case 55: // "("
      case 56: // ")"
      case 57: // "["
      case 58: // "]"
      case 59: // "{"
      case 60: // "}"
      case 61: // "@"
      case 62: // ","
      case 63: // "."
      case 64: // ".."
        value.move< CST::Token::Ptr > (that.value);
        break;

      case 84: // CacheDefinition
        value.move< CacheDefinition::Ptr > (that.value);
        break;

      case 113: // CallExpression
        value.move< CallExpression::Ptr > (that.value);
        break;

      case 103: // CallStatement
        value.move< CallStatement::Ptr > (that.value);
        break;

      case 111: // ConditionalExpression
        value.move< ConditionalExpression::Ptr > (that.value);
        break;

      case 106: // ConditionalStatement
        value.move< ConditionalStatement::Ptr > (that.value);
        break;

      case 92: // DecodingOption
        value.move< DecodingOption::Ptr > (that.value);
        break;

      case 74: // AttributedDefinition
      case 75: // Definition
        value.move< Definition::Ptr > (that.value);
        break;

      case 73: // Definitions
        value.move< Definitions::Ptr > (that.value);
        break;

      case 114: // DirectCallExpression
        value.move< DirectCallExpression::Ptr > (that.value);
        break;

      case 87: // EnumerationDefinition
        value.move< EnumerationDefinition::Ptr > (that.value);
        break;

      case 94: // ExpansionOption
        value.move< ExpansionOption::Ptr > (that.value);
        break;

      case 108: // Term
      case 109: // Expression
      case 112: // OperatorExpression
      case 133: // Terminal
        value.move< Expression::Ptr > (that.value);
        break;

      case 149: // ExpressionAttribute
        value.move< ExpressionAttribute::Ptr > (that.value);
        break;

      case 107: // Terms
      case 132: // Terminals
        value.move< Expressions::Ptr > (that.value);
        break;

      case 78: // FieldDefinition
        value.move< FieldDefinition::Ptr > (that.value);
        break;

      case 79: // FormatDefinition
        value.move< FormatDefinition::Ptr > (that.value);
        break;

      case 131: // GrammarLiteral
        value.move< GrammarLiteral::Ptr > (that.value);
        break;

      case 72: // Header
        value.move< HeaderDefinition::Ptr > (that.value);
        break;

      case 69: // "identifier"
      case 144: // Identifier
        value.move< Identifier::Ptr > (that.value);
        break;

      case 145: // IdentifierPath
        value.move< IdentifierPath::Ptr > (that.value);
        break;

      case 82: // InstructionDefinition
        value.move< InstructionDefinition::Ptr > (that.value);
        break;

      case 85: // InterconnectDefinition
        value.move< InterconnectDefinition::Ptr > (that.value);
        break;

      case 110: // LetExpression
        value.move< LetExpression::Ptr > (that.value);
        break;

      case 104: // LetStatement
        value.move< LetStatement::Ptr > (that.value);
        break;

      case 122: // ListLiteral
        value.move< ListLiteral::Ptr > (that.value);
        break;

      case 116: // Literal
        value.move< Literal::Ptr > (that.value);
        break;

      case 129: // Mapping
        value.move< MappedExpression::Ptr > (that.value);
        break;

      case 128: // Mappings
        value.move< MappedExpressions::Ptr > (that.value);
        break;

      case 80: // FormatFields
      case 127: // MappingLiteral
        value.move< MappingLiteral::Ptr > (that.value);
        break;

      case 137: // MappingType
        value.move< MappingType::Ptr > (that.value);
        break;

      case 76: // MemoryDefinition
        value.move< MemoryDefinition::Ptr > (that.value);
        break;

      case 115: // MethodCallExpression
        value.move< MethodCallExpression::Ptr > (that.value);
        break;

      case 83: // MicroProcessorDefinition
        value.move< MicroProcessorDefinition::Ptr > (that.value);
        break;

      case 126: // Assignment
        value.move< NamedExpression::Ptr > (that.value);
        break;

      case 125: // Assignments
        value.move< NamedExpressions::Ptr > (that.value);
        break;

      case 91: // InstructionOption
      case 96: // MicroProcessorOption
        value.move< Option::Ptr > (that.value);
        break;

      case 86: // OptionDefinition
        value.move< OptionDefinition::Ptr > (that.value);
        break;

      case 90: // InstructionOptions
      case 95: // MicroProcessorOptions
        value.move< Options::Ptr > (that.value);
        break;

      case 123: // RangeLiteral
        value.move< RangeLiteral::Ptr > (that.value);
        break;

      case 124: // RecordLiteral
        value.move< RecordLiteral::Ptr > (that.value);
        break;

      case 130: // ReferenceLiteral
        value.move< ReferenceLiteral::Ptr > (that.value);
        break;

      case 77: // RegisterDefinition
        value.move< RegisterDefinition::Ptr > (that.value);
        break;

      case 88: // Enumerators
      case 121: // SetLiteral
        value.move< SetLiteral::Ptr > (that.value);
        break;

      case 100: // SkipStatement
      case 101: // AbstractStatement
        value.move< SkipStatement::Ptr > (that.value);
        break;

      case 71: // Specification
        value.move< Specification::Ptr > (that.value);
        break;

      case 97: // StageOption
        value.move< StageOption::Ptr > (that.value);
        break;

      case 99: // Statement
        value.move< Statement::Ptr > (that.value);
        break;

      case 98: // Statements
        value.move< Statements::Ptr > (that.value);
        break;

      case 93: // SyntaxOption
        value.move< SyntaxOption::Ptr > (that.value);
        break;

      case 138: // ArgumentTypes
        value.move< Types::Ptr > (that.value);
        break;

      case 89: // UsingDefinition
        value.move< UsingDefinition::Ptr > (that.value);
        break;

      case 65: // "integer"
      case 66: // "binary"
      case 67: // "hexadecimal"
      case 68: // "string"
      case 117: // BooleanLiteral
      case 118: // IntegerLiteral
      case 119: // BinaryLiteral
      case 120: // StringLiteral
        value.move< ValueLiteral::Ptr > (that.value);
        break;

      case 140: // VariableBinding
        value.move< VariableBinding::Ptr > (that.value);
        break;

      case 139: // VariableBindings
        value.move< VariableBindings::Ptr > (that.value);
        break;

      case 141: // AttributedVariable
      case 142: // Variable
      case 143: // TypedVariable
        value.move< VariableDefinition::Ptr > (that.value);
        break;

      case 134: // Type
      case 135: // BasicType
      case 136: // PropertyType
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
      case 105: // AssignmentStatement
        yylhs.value.emplace< AssignmentStatement::Ptr > ();
        break;

      case 147: // Attribute
        yylhs.value.emplace< Attribute::Ptr > ();
        break;

      case 146: // Attributes
        yylhs.value.emplace< Attributes::Ptr > ();
        break;

      case 148: // BasicAttribute
        yylhs.value.emplace< BasicAttribute::Ptr > ();
        break;

      case 102: // BlockStatement
        yylhs.value.emplace< BlockStatement::Ptr > ();
        break;

      case 81: // BufferDefinition
        yylhs.value.emplace< BufferDefinition::Ptr > ();
        break;

      case 3: // "SCOD"
      case 4: // "memory"
      case 5: // "register"
      case 6: // "field"
      case 7: // "format"
      case 8: // "buffer"
      case 9: // "instruction"
      case 10: // "microprocessor"
      case 11: // "cache"
      case 12: // "interconnect"
      case 13: // "decoding"
      case 14: // "syntax"
      case 15: // "expansion"
      case 16: // "stage"
      case 17: // "enumeration"
      case 18: // "using"
      case 19: // "skip"
      case 20: // "abstract"
      case 21: // "let"
      case 22: // "in"
      case 23: // "if"
      case 24: // "then"
      case 25: // "else"
      case 26: // "false"
      case 27: // "true"
      case 28: // "not"
      case 29: // "and"
      case 30: // "or"
      case 31: // "xor"
      case 32: // "implies"
      case 33: // "=>"
      case 34: // "+"
      case 35: // "(+)"
      case 36: // "-"
      case 37: // "(-)"
      case 38: // "*"
      case 39: // "<<"
      case 40: // "(<<)"
      case 41: // ">>"
      case 42: // "(>>)"
      case 43: // "="
      case 44: // "!="
      case 45: // "<"
      case 46: // "<="
      case 47: // ">"
      case 48: // ">="
      case 49: // ":="
      case 50: // "->"
      case 51: // "'"
      case 52: // ":"
      case 53: // ";"
      case 54: // "::"
      case 55: // "("
      case 56: // ")"
      case 57: // "["
      case 58: // "]"
      case 59: // "{"
      case 60: // "}"
      case 61: // "@"
      case 62: // ","
      case 63: // "."
      case 64: // ".."
        yylhs.value.emplace< CST::Token::Ptr > ();
        break;

      case 84: // CacheDefinition
        yylhs.value.emplace< CacheDefinition::Ptr > ();
        break;

      case 113: // CallExpression
        yylhs.value.emplace< CallExpression::Ptr > ();
        break;

      case 103: // CallStatement
        yylhs.value.emplace< CallStatement::Ptr > ();
        break;

      case 111: // ConditionalExpression
        yylhs.value.emplace< ConditionalExpression::Ptr > ();
        break;

      case 106: // ConditionalStatement
        yylhs.value.emplace< ConditionalStatement::Ptr > ();
        break;

      case 92: // DecodingOption
        yylhs.value.emplace< DecodingOption::Ptr > ();
        break;

      case 74: // AttributedDefinition
      case 75: // Definition
        yylhs.value.emplace< Definition::Ptr > ();
        break;

      case 73: // Definitions
        yylhs.value.emplace< Definitions::Ptr > ();
        break;

      case 114: // DirectCallExpression
        yylhs.value.emplace< DirectCallExpression::Ptr > ();
        break;

      case 87: // EnumerationDefinition
        yylhs.value.emplace< EnumerationDefinition::Ptr > ();
        break;

      case 94: // ExpansionOption
        yylhs.value.emplace< ExpansionOption::Ptr > ();
        break;

      case 108: // Term
      case 109: // Expression
      case 112: // OperatorExpression
      case 133: // Terminal
        yylhs.value.emplace< Expression::Ptr > ();
        break;

      case 149: // ExpressionAttribute
        yylhs.value.emplace< ExpressionAttribute::Ptr > ();
        break;

      case 107: // Terms
      case 132: // Terminals
        yylhs.value.emplace< Expressions::Ptr > ();
        break;

      case 78: // FieldDefinition
        yylhs.value.emplace< FieldDefinition::Ptr > ();
        break;

      case 79: // FormatDefinition
        yylhs.value.emplace< FormatDefinition::Ptr > ();
        break;

      case 131: // GrammarLiteral
        yylhs.value.emplace< GrammarLiteral::Ptr > ();
        break;

      case 72: // Header
        yylhs.value.emplace< HeaderDefinition::Ptr > ();
        break;

      case 69: // "identifier"
      case 144: // Identifier
        yylhs.value.emplace< Identifier::Ptr > ();
        break;

      case 145: // IdentifierPath
        yylhs.value.emplace< IdentifierPath::Ptr > ();
        break;

      case 82: // InstructionDefinition
        yylhs.value.emplace< InstructionDefinition::Ptr > ();
        break;

      case 85: // InterconnectDefinition
        yylhs.value.emplace< InterconnectDefinition::Ptr > ();
        break;

      case 110: // LetExpression
        yylhs.value.emplace< LetExpression::Ptr > ();
        break;

      case 104: // LetStatement
        yylhs.value.emplace< LetStatement::Ptr > ();
        break;

      case 122: // ListLiteral
        yylhs.value.emplace< ListLiteral::Ptr > ();
        break;

      case 116: // Literal
        yylhs.value.emplace< Literal::Ptr > ();
        break;

      case 129: // Mapping
        yylhs.value.emplace< MappedExpression::Ptr > ();
        break;

      case 128: // Mappings
        yylhs.value.emplace< MappedExpressions::Ptr > ();
        break;

      case 80: // FormatFields
      case 127: // MappingLiteral
        yylhs.value.emplace< MappingLiteral::Ptr > ();
        break;

      case 137: // MappingType
        yylhs.value.emplace< MappingType::Ptr > ();
        break;

      case 76: // MemoryDefinition
        yylhs.value.emplace< MemoryDefinition::Ptr > ();
        break;

      case 115: // MethodCallExpression
        yylhs.value.emplace< MethodCallExpression::Ptr > ();
        break;

      case 83: // MicroProcessorDefinition
        yylhs.value.emplace< MicroProcessorDefinition::Ptr > ();
        break;

      case 126: // Assignment
        yylhs.value.emplace< NamedExpression::Ptr > ();
        break;

      case 125: // Assignments
        yylhs.value.emplace< NamedExpressions::Ptr > ();
        break;

      case 91: // InstructionOption
      case 96: // MicroProcessorOption
        yylhs.value.emplace< Option::Ptr > ();
        break;

      case 86: // OptionDefinition
        yylhs.value.emplace< OptionDefinition::Ptr > ();
        break;

      case 90: // InstructionOptions
      case 95: // MicroProcessorOptions
        yylhs.value.emplace< Options::Ptr > ();
        break;

      case 123: // RangeLiteral
        yylhs.value.emplace< RangeLiteral::Ptr > ();
        break;

      case 124: // RecordLiteral
        yylhs.value.emplace< RecordLiteral::Ptr > ();
        break;

      case 130: // ReferenceLiteral
        yylhs.value.emplace< ReferenceLiteral::Ptr > ();
        break;

      case 77: // RegisterDefinition
        yylhs.value.emplace< RegisterDefinition::Ptr > ();
        break;

      case 88: // Enumerators
      case 121: // SetLiteral
        yylhs.value.emplace< SetLiteral::Ptr > ();
        break;

      case 100: // SkipStatement
      case 101: // AbstractStatement
        yylhs.value.emplace< SkipStatement::Ptr > ();
        break;

      case 71: // Specification
        yylhs.value.emplace< Specification::Ptr > ();
        break;

      case 97: // StageOption
        yylhs.value.emplace< StageOption::Ptr > ();
        break;

      case 99: // Statement
        yylhs.value.emplace< Statement::Ptr > ();
        break;

      case 98: // Statements
        yylhs.value.emplace< Statements::Ptr > ();
        break;

      case 93: // SyntaxOption
        yylhs.value.emplace< SyntaxOption::Ptr > ();
        break;

      case 138: // ArgumentTypes
        yylhs.value.emplace< Types::Ptr > ();
        break;

      case 89: // UsingDefinition
        yylhs.value.emplace< UsingDefinition::Ptr > ();
        break;

      case 65: // "integer"
      case 66: // "binary"
      case 67: // "hexadecimal"
      case 68: // "string"
      case 117: // BooleanLiteral
      case 118: // IntegerLiteral
      case 119: // BinaryLiteral
      case 120: // StringLiteral
        yylhs.value.emplace< ValueLiteral::Ptr > ();
        break;

      case 140: // VariableBinding
        yylhs.value.emplace< VariableBinding::Ptr > ();
        break;

      case 139: // VariableBindings
        yylhs.value.emplace< VariableBindings::Ptr > ();
        break;

      case 141: // AttributedVariable
      case 142: // Variable
      case 143: // TypedVariable
        yylhs.value.emplace< VariableDefinition::Ptr > ();
        break;

      case 134: // Type
      case 135: // BasicType
      case 136: // PropertyType
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
#line 366 "../../obj/src/GrammarParser.y"
  {
      const auto& cst = CST::make< CST::Root >(
          yylhs.location, yystack_[1].value.as < HeaderDefinition::Ptr > (), yystack_[0].value.as < Definitions::Ptr > (), m_lexer.fetchSpansAndReset() );
      m_specification.setCst( cst );
  }
#line 2256 "GrammarParser.cpp"
    break;

  case 3:
#line 376 "../../obj/src/GrammarParser.y"
 {
     auto definition = CST::make< HeaderDefinition >( yylhs.location, yystack_[0].value.as < CST::Token::Ptr > () );
     definition->setAttributes( yystack_[1].value.as < Attributes::Ptr > () );
     yylhs.value.as < HeaderDefinition::Ptr > () = definition;
 }
#line 2266 "GrammarParser.cpp"
    break;

  case 4:
#line 382 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < HeaderDefinition::Ptr > () = CST::make< HeaderDefinition >( yylhs.location, yystack_[0].value.as < CST::Token::Ptr > () );
  }
#line 2274 "GrammarParser.cpp"
    break;

  case 5:
#line 390 "../../obj/src/GrammarParser.y"
  {
      auto definitions = yystack_[1].value.as < Definitions::Ptr > ();
      definitions->add( yystack_[0].value.as < Definition::Ptr > () );
      yylhs.value.as < Definitions::Ptr > () = definitions;
  }
#line 2284 "GrammarParser.cpp"
    break;

  case 6:
#line 396 "../../obj/src/GrammarParser.y"
  {
      auto definitions = CST::make< Definitions >( yylhs.location );
      definitions->add( yystack_[0].value.as < Definition::Ptr > () );
      yylhs.value.as < Definitions::Ptr > () = definitions;
  }
#line 2294 "GrammarParser.cpp"
    break;

  case 7:
#line 406 "../../obj/src/GrammarParser.y"
  {
      auto definition = yystack_[0].value.as < Definition::Ptr > ();
      definition->setAttributes( yystack_[1].value.as < Attributes::Ptr > () );
      yylhs.value.as < Definition::Ptr > () = definition;
  }
#line 2304 "GrammarParser.cpp"
    break;

  case 8:
#line 412 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Definition::Ptr > () = yystack_[0].value.as < Definition::Ptr > ();
  }
#line 2312 "GrammarParser.cpp"
    break;

  case 9:
#line 416 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Definition::Ptr > () = nullptr;
  }
#line 2320 "GrammarParser.cpp"
    break;

  case 10:
#line 424 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Definition::Ptr > () = yystack_[0].value.as < MemoryDefinition::Ptr > ();
  }
#line 2328 "GrammarParser.cpp"
    break;

  case 11:
#line 428 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Definition::Ptr > () = yystack_[0].value.as < RegisterDefinition::Ptr > ();
  }
#line 2336 "GrammarParser.cpp"
    break;

  case 12:
#line 432 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Definition::Ptr > () = yystack_[0].value.as < FieldDefinition::Ptr > ();
  }
#line 2344 "GrammarParser.cpp"
    break;

  case 13:
#line 436 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Definition::Ptr > () = yystack_[0].value.as < FormatDefinition::Ptr > ();
  }
#line 2352 "GrammarParser.cpp"
    break;

  case 14:
#line 440 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Definition::Ptr > () = yystack_[0].value.as < BufferDefinition::Ptr > ();
  }
#line 2360 "GrammarParser.cpp"
    break;

  case 15:
#line 444 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Definition::Ptr > () = yystack_[0].value.as < InstructionDefinition::Ptr > ();
  }
#line 2368 "GrammarParser.cpp"
    break;

  case 16:
#line 448 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Definition::Ptr > () = yystack_[0].value.as < MicroProcessorDefinition::Ptr > ();
  }
#line 2376 "GrammarParser.cpp"
    break;

  case 17:
#line 452 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Definition::Ptr > () = yystack_[0].value.as < CacheDefinition::Ptr > ();
  }
#line 2384 "GrammarParser.cpp"
    break;

  case 18:
#line 456 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Definition::Ptr > () = yystack_[0].value.as < InterconnectDefinition::Ptr > ();
  }
#line 2392 "GrammarParser.cpp"
    break;

  case 19:
#line 460 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Definition::Ptr > () = yystack_[0].value.as < OptionDefinition::Ptr > ();
  }
#line 2400 "GrammarParser.cpp"
    break;

  case 20:
#line 464 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Definition::Ptr > () = yystack_[0].value.as < EnumerationDefinition::Ptr > ();
  }
#line 2408 "GrammarParser.cpp"
    break;

  case 21:
#line 468 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Definition::Ptr > () = yystack_[0].value.as < UsingDefinition::Ptr > ();
  }
#line 2416 "GrammarParser.cpp"
    break;

  case 22:
#line 476 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < MemoryDefinition::Ptr > () = CST::make< MemoryDefinition >( yylhs.location, yystack_[3].value.as < CST::Token::Ptr > (), yystack_[2].value.as < Identifier::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < MappingType::Ptr > () );
  }
#line 2424 "GrammarParser.cpp"
    break;

  case 23:
#line 484 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < RegisterDefinition::Ptr > () = CST::make< RegisterDefinition >( yylhs.location, yystack_[3].value.as < CST::Token::Ptr > (), yystack_[2].value.as < Identifier::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < libscod::CST::Type::Ptr > () );
  }
#line 2432 "GrammarParser.cpp"
    break;

  case 24:
#line 492 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < FieldDefinition::Ptr > () = CST::make< FieldDefinition >( yylhs.location, yystack_[3].value.as < CST::Token::Ptr > (), yystack_[2].value.as < Identifier::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < libscod::CST::Type::Ptr > () );
  }
#line 2440 "GrammarParser.cpp"
    break;

  case 25:
#line 500 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < FormatDefinition::Ptr > () = CST::make< FormatDefinition >( yylhs.location, yystack_[5].value.as < CST::Token::Ptr > (), yystack_[4].value.as < Identifier::Ptr > (), yystack_[3].value.as < CST::Token::Ptr > (), yystack_[2].value.as < libscod::CST::Type::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < MappingLiteral::Ptr > () );
  }
#line 2448 "GrammarParser.cpp"
    break;

  case 26:
#line 507 "../../obj/src/GrammarParser.y"
{
    // TODO: check mapping types here or later in validation
    yylhs.value.as < MappingLiteral::Ptr > () = yystack_[0].value.as < MappingLiteral::Ptr > ();
}
#line 2457 "GrammarParser.cpp"
    break;

  case 27:
#line 515 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < BufferDefinition::Ptr > () = CST::make< BufferDefinition >( yylhs.location, yystack_[5].value.as < CST::Token::Ptr > (), yystack_[4].value.as < Identifier::Ptr > (), yystack_[3].value.as < CST::Token::Ptr > (), yystack_[2].value.as < libscod::CST::Type::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );      
  }
#line 2465 "GrammarParser.cpp"
    break;

  case 28:
#line 523 "../../obj/src/GrammarParser.y"
  {
      const auto& options = CST::make< Options >( yylhs.location );
      yylhs.value.as < InstructionDefinition::Ptr > () = CST::make< InstructionDefinition >( yylhs.location, yystack_[5].value.as < CST::Token::Ptr > (), yystack_[4].value.as < Identifier::Ptr > (), yystack_[3].value.as < CST::Token::Ptr > (), yystack_[2].value.as < libscod::CST::Type::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Statement::Ptr > (), options );
  }
#line 2474 "GrammarParser.cpp"
    break;

  case 29:
#line 528 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < InstructionDefinition::Ptr > () = CST::make< InstructionDefinition >( yylhs.location, yystack_[6].value.as < CST::Token::Ptr > (), yystack_[5].value.as < Identifier::Ptr > (), yystack_[4].value.as < CST::Token::Ptr > (), yystack_[3].value.as < libscod::CST::Type::Ptr > (), yystack_[2].value.as < CST::Token::Ptr > (), yystack_[1].value.as < Statement::Ptr > (), yystack_[0].value.as < Options::Ptr > () );
  }
#line 2482 "GrammarParser.cpp"
    break;

  case 30:
#line 536 "../../obj/src/GrammarParser.y"
  {
      const auto& options = CST::make< Options >( yylhs.location );
      yylhs.value.as < MicroProcessorDefinition::Ptr > () = CST::make< MicroProcessorDefinition >( yylhs.location, yystack_[5].value.as < CST::Token::Ptr > (), yystack_[4].value.as < Identifier::Ptr > (), yystack_[3].value.as < CST::Token::Ptr > (), yystack_[2].value.as < IdentifierPath::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Statement::Ptr > (), options );
  }
#line 2491 "GrammarParser.cpp"
    break;

  case 31:
#line 541 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < MicroProcessorDefinition::Ptr > () = CST::make< MicroProcessorDefinition >( yylhs.location, yystack_[6].value.as < CST::Token::Ptr > (), yystack_[5].value.as < Identifier::Ptr > (), yystack_[4].value.as < CST::Token::Ptr > (), yystack_[3].value.as < IdentifierPath::Ptr > (), yystack_[2].value.as < CST::Token::Ptr > (), yystack_[1].value.as < Statement::Ptr > (), yystack_[0].value.as < Options::Ptr > () );
  }
#line 2499 "GrammarParser.cpp"
    break;

  case 32:
#line 549 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < CacheDefinition::Ptr > () = CST::make< CacheDefinition >( yylhs.location, yystack_[5].value.as < CST::Token::Ptr > (), yystack_[4].value.as < Identifier::Ptr > (), yystack_[3].value.as < CST::Token::Ptr > (), yystack_[2].value.as < libscod::CST::Type::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < MappingLiteral::Ptr > () );
  }
#line 2507 "GrammarParser.cpp"
    break;

  case 33:
#line 557 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < InterconnectDefinition::Ptr > () = CST::make< InterconnectDefinition >( yylhs.location, yystack_[5].value.as < CST::Token::Ptr > (), yystack_[4].value.as < Identifier::Ptr > (), yystack_[3].value.as < CST::Token::Ptr > (), yystack_[2].value.as < libscod::CST::Type::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < MappingLiteral::Ptr > () );
  }
#line 2515 "GrammarParser.cpp"
    break;

  case 34:
#line 565 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < OptionDefinition::Ptr > () = CST::make< OptionDefinition >( yylhs.location, yystack_[1].value.as < ReferenceLiteral::Ptr > (), yystack_[0].value.as < DecodingOption::Ptr > (), OptionDefinition::Kind::DECODING );
  }
#line 2523 "GrammarParser.cpp"
    break;

  case 35:
#line 569 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < OptionDefinition::Ptr > () = CST::make< OptionDefinition >( yylhs.location, yystack_[1].value.as < ReferenceLiteral::Ptr > (), yystack_[0].value.as < SyntaxOption::Ptr > (), OptionDefinition::Kind::SYNTAX );
  }
#line 2531 "GrammarParser.cpp"
    break;

  case 36:
#line 573 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < OptionDefinition::Ptr > () = CST::make< OptionDefinition >( yylhs.location, yystack_[1].value.as < ReferenceLiteral::Ptr > (), yystack_[0].value.as < ExpansionOption::Ptr > (), OptionDefinition::Kind::EXPANSION );
  }
#line 2539 "GrammarParser.cpp"
    break;

  case 37:
#line 581 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < EnumerationDefinition::Ptr > () = CST::make< EnumerationDefinition >( yylhs.location, yystack_[3].value.as < CST::Token::Ptr > (), yystack_[2].value.as < Identifier::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < SetLiteral::Ptr > () );
  }
#line 2547 "GrammarParser.cpp"
    break;

  case 38:
#line 588 "../../obj/src/GrammarParser.y"
  {
      // TODO: add check if identifiers here or later in validation pass
      yylhs.value.as < SetLiteral::Ptr > () = yystack_[0].value.as < SetLiteral::Ptr > ();
  }
#line 2556 "GrammarParser.cpp"
    break;

  case 39:
#line 597 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < UsingDefinition::Ptr > () = CST::make< UsingDefinition >( yylhs.location, yystack_[3].value.as < CST::Token::Ptr > (), yystack_[2].value.as < Identifier::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < libscod::CST::Type::Ptr > () );
  }
#line 2564 "GrammarParser.cpp"
    break;

  case 40:
#line 609 "../../obj/src/GrammarParser.y"
  {
      const auto& options = yystack_[1].value.as < Options::Ptr > ();
      options->add( yystack_[0].value.as < Option::Ptr > () );
      yylhs.value.as < Options::Ptr > () = options;
  }
#line 2574 "GrammarParser.cpp"
    break;

  case 41:
#line 615 "../../obj/src/GrammarParser.y"
  {
      const auto& options = CST::make< Options >( yylhs.location );
      options->add( yystack_[0].value.as < Option::Ptr > () );
      yylhs.value.as < Options::Ptr > () = options;
  }
#line 2584 "GrammarParser.cpp"
    break;

  case 42:
#line 625 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Option::Ptr > () = yystack_[0].value.as < DecodingOption::Ptr > ();
  }
#line 2592 "GrammarParser.cpp"
    break;

  case 43:
#line 629 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Option::Ptr > () = yystack_[0].value.as < SyntaxOption::Ptr > ();
  }
#line 2600 "GrammarParser.cpp"
    break;

  case 44:
#line 633 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Option::Ptr > () = yystack_[0].value.as < ExpansionOption::Ptr > ();
  }
#line 2608 "GrammarParser.cpp"
    break;

  case 45:
#line 641 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < DecodingOption::Ptr > () = CST::make< DecodingOption >( yylhs.location, yystack_[2].value.as < CST::Token::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < RecordLiteral::Ptr > () );      
  }
#line 2616 "GrammarParser.cpp"
    break;

  case 46:
#line 649 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < SyntaxOption::Ptr > () = CST::make< SyntaxOption >( yylhs.location, yystack_[2].value.as < CST::Token::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < SetLiteral::Ptr > () );      
  }
#line 2624 "GrammarParser.cpp"
    break;

  case 47:
#line 657 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < ExpansionOption::Ptr > () = CST::make< ExpansionOption >( yylhs.location, yystack_[2].value.as < CST::Token::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < SetLiteral::Ptr > () );      
  }
#line 2632 "GrammarParser.cpp"
    break;

  case 48:
#line 665 "../../obj/src/GrammarParser.y"
  {
      const auto& options = yystack_[1].value.as < Options::Ptr > ();
      options->add( yystack_[0].value.as < Option::Ptr > () );
      yylhs.value.as < Options::Ptr > () = options;
  }
#line 2642 "GrammarParser.cpp"
    break;

  case 49:
#line 671 "../../obj/src/GrammarParser.y"
  {
      const auto& options = CST::make< Options >( yylhs.location );
      options->add( yystack_[0].value.as < Option::Ptr > () );
      yylhs.value.as < Options::Ptr > () = options;
  }
#line 2652 "GrammarParser.cpp"
    break;

  case 50:
#line 681 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Option::Ptr > () = yystack_[0].value.as < StageOption::Ptr > ();
  }
#line 2660 "GrammarParser.cpp"
    break;

  case 51:
#line 689 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < StageOption::Ptr > () = CST::make< StageOption >( yylhs.location, yystack_[3].value.as < CST::Token::Ptr > (), yystack_[2].value.as < Identifier::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < BlockStatement::Ptr > () );
  }
#line 2668 "GrammarParser.cpp"
    break;

  case 52:
#line 701 "../../obj/src/GrammarParser.y"
  {
      const auto& statements = yystack_[1].value.as < Statements::Ptr > ();
      statements->add( yystack_[0].value.as < Statement::Ptr > () );
      yylhs.value.as < Statements::Ptr > () = statements;
  }
#line 2678 "GrammarParser.cpp"
    break;

  case 53:
#line 707 "../../obj/src/GrammarParser.y"
  {
      const auto& statements = CST::make< Statements >( yylhs.location );
      statements->add( yystack_[0].value.as < Statement::Ptr > () );
      yylhs.value.as < Statements::Ptr > () = statements;
  }
#line 2688 "GrammarParser.cpp"
    break;

  case 54:
#line 717 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Statement::Ptr > () = yystack_[0].value.as < SkipStatement::Ptr > ();
  }
#line 2696 "GrammarParser.cpp"
    break;

  case 55:
#line 721 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Statement::Ptr > () = yystack_[0].value.as < SkipStatement::Ptr > ();
  }
#line 2704 "GrammarParser.cpp"
    break;

  case 56:
#line 725 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Statement::Ptr > () = yystack_[0].value.as < BlockStatement::Ptr > ();
  }
#line 2712 "GrammarParser.cpp"
    break;

  case 57:
#line 729 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Statement::Ptr > () = yystack_[0].value.as < CallStatement::Ptr > ();
  }
#line 2720 "GrammarParser.cpp"
    break;

  case 58:
#line 733 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Statement::Ptr > () = yystack_[0].value.as < LetStatement::Ptr > ();
  }
#line 2728 "GrammarParser.cpp"
    break;

  case 59:
#line 737 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Statement::Ptr > () = yystack_[0].value.as < AssignmentStatement::Ptr > ();
  }
#line 2736 "GrammarParser.cpp"
    break;

  case 60:
#line 741 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Statement::Ptr > () = yystack_[0].value.as < ConditionalStatement::Ptr > ();
  }
#line 2744 "GrammarParser.cpp"
    break;

  case 61:
#line 749 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < SkipStatement::Ptr > () = CST::make< SkipStatement >( yylhs.location, yystack_[0].value.as < CST::Token::Ptr > () );
  }
#line 2752 "GrammarParser.cpp"
    break;

  case 62:
#line 757 "../../obj/src/GrammarParser.y"
  {
      // maybe introduce exclusive CST node!
      yylhs.value.as < SkipStatement::Ptr > () = CST::make< SkipStatement >( yylhs.location, yystack_[0].value.as < CST::Token::Ptr > () );
  }
#line 2761 "GrammarParser.cpp"
    break;

  case 63:
#line 766 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < BlockStatement::Ptr > () = CST::make< BlockStatement >( yylhs.location, yystack_[2].value.as < CST::Token::Ptr > (), yystack_[1].value.as < Statements::Ptr > (), yystack_[0].value.as < CST::Token::Ptr > () );
  }
#line 2769 "GrammarParser.cpp"
    break;

  case 64:
#line 770 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < BlockStatement::Ptr > () = nullptr;
      yyerrok;
  }
#line 2778 "GrammarParser.cpp"
    break;

  case 65:
#line 779 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < CallStatement::Ptr > () = CST::make< CallStatement >( yylhs.location, yystack_[0].value.as < DirectCallExpression::Ptr > () );
  }
#line 2786 "GrammarParser.cpp"
    break;

  case 66:
#line 787 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < LetStatement::Ptr > () = CST::make< LetStatement >( yylhs.location, yystack_[3].value.as < CST::Token::Ptr > (), yystack_[2].value.as < VariableBindings::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Statement::Ptr > () );
  }
#line 2794 "GrammarParser.cpp"
    break;

  case 67:
#line 795 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < AssignmentStatement::Ptr > () = CST::make< AssignmentStatement >( yylhs.location, yystack_[2].value.as < DirectCallExpression::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
  }
#line 2802 "GrammarParser.cpp"
    break;

  case 68:
#line 803 "../../obj/src/GrammarParser.y"
  {
      const auto& elseStatement = CST::make< SkipStatement >( yylhs.location, Token::unresolved() );
      yylhs.value.as < ConditionalStatement::Ptr > () = CST::make< ConditionalStatement >( yylhs.location, yystack_[3].value.as < CST::Token::Ptr > (), yystack_[2].value.as < Expression::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Statement::Ptr > (), Token::unresolved(), elseStatement );
  }
#line 2811 "GrammarParser.cpp"
    break;

  case 69:
#line 808 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < ConditionalStatement::Ptr > () = CST::make< ConditionalStatement >( yylhs.location, yystack_[5].value.as < CST::Token::Ptr > (), yystack_[4].value.as < Expression::Ptr > (), yystack_[3].value.as < CST::Token::Ptr > (), yystack_[2].value.as < Statement::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Statement::Ptr > () );
  }
#line 2819 "GrammarParser.cpp"
    break;

  case 70:
#line 820 "../../obj/src/GrammarParser.y"
  {
      const auto& expressions = yystack_[2].value.as < Expressions::Ptr > ();
      yystack_[0].value.as < Expression::Ptr > ()->setDelimiterToken( yystack_[1].value.as < CST::Token::Ptr > () );
      expressions->add( yystack_[0].value.as < Expression::Ptr > () );
      yylhs.value.as < Expressions::Ptr > () = expressions;
  }
#line 2830 "GrammarParser.cpp"
    break;

  case 71:
#line 827 "../../obj/src/GrammarParser.y"
  {
      const auto& expressions = CST::make< Expressions >( yylhs.location );
      expressions->add( yystack_[0].value.as < Expression::Ptr > () );
      yylhs.value.as < Expressions::Ptr > () = expressions;
  }
#line 2840 "GrammarParser.cpp"
    break;

  case 72:
#line 837 "../../obj/src/GrammarParser.y"
  {
     yylhs.value.as < Expression::Ptr > () = yystack_[0].value.as < Expression::Ptr > ();
  }
#line 2848 "GrammarParser.cpp"
    break;

  case 73:
#line 841 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = yystack_[0].value.as < LetExpression::Ptr > ();
  }
#line 2856 "GrammarParser.cpp"
    break;

  case 74:
#line 845 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = yystack_[0].value.as < ConditionalExpression::Ptr > ();
  }
#line 2864 "GrammarParser.cpp"
    break;

  case 75:
#line 849 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = yystack_[0].value.as < Expression::Ptr > ();
  }
#line 2872 "GrammarParser.cpp"
    break;

  case 76:
#line 857 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = CST::make< CST::EmbracedExpression >( yylhs.location, yystack_[2].value.as < CST::Token::Ptr > (), yystack_[1].value.as < Expression::Ptr > (), yystack_[0].value.as < CST::Token::Ptr > () );
  }
#line 2880 "GrammarParser.cpp"
    break;

  case 77:
#line 861 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = yystack_[0].value.as < CallExpression::Ptr > ();
  }
#line 2888 "GrammarParser.cpp"
    break;

  case 78:
#line 865 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = yystack_[0].value.as < Literal::Ptr > ();
  }
#line 2896 "GrammarParser.cpp"
    break;

  case 79:
#line 869 "../../obj/src/GrammarParser.y"
 {
     yylhs.value.as < Expression::Ptr > () = CST::make< UnaryExpression >( yylhs.location, yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
 }
#line 2904 "GrammarParser.cpp"
    break;

  case 80:
#line 873 "../../obj/src/GrammarParser.y"
 {
     yylhs.value.as < Expression::Ptr > () = CST::make< UnaryExpression >( yylhs.location, yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
 }
#line 2912 "GrammarParser.cpp"
    break;

  case 81:
#line 881 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < LetExpression::Ptr > () = CST::make< LetExpression >( yylhs.location, yystack_[3].value.as < CST::Token::Ptr > (), yystack_[2].value.as < VariableBindings::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
  }
#line 2920 "GrammarParser.cpp"
    break;

  case 82:
#line 889 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < ConditionalExpression::Ptr > () = CST::make< ConditionalExpression >( yylhs.location, yystack_[5].value.as < CST::Token::Ptr > (), yystack_[4].value.as < Expression::Ptr > (), yystack_[3].value.as < CST::Token::Ptr > (), yystack_[2].value.as < Expression::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
  }
#line 2928 "GrammarParser.cpp"
    break;

  case 83:
#line 901 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = CST::make< UnaryExpression >( yylhs.location, yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
  }
#line 2936 "GrammarParser.cpp"
    break;

  case 84:
#line 905 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = CST::make< BinaryExpression >( yylhs.location, yystack_[2].value.as < Expression::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
  }
#line 2944 "GrammarParser.cpp"
    break;

  case 85:
#line 909 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = CST::make< BinaryExpression >( yylhs.location, yystack_[2].value.as < Expression::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
  }
#line 2952 "GrammarParser.cpp"
    break;

  case 86:
#line 913 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = CST::make< BinaryExpression >( yylhs.location, yystack_[2].value.as < Expression::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
  }
#line 2960 "GrammarParser.cpp"
    break;

  case 87:
#line 917 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = CST::make< BinaryExpression >( yylhs.location, yystack_[2].value.as < Expression::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
  }
#line 2968 "GrammarParser.cpp"
    break;

  case 88:
#line 921 "../../obj/src/GrammarParser.y"
  {
      // equivalent to 'implies'
      yylhs.value.as < Expression::Ptr > () = CST::make< BinaryExpression >( yylhs.location, yystack_[2].value.as < Expression::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
  }
#line 2977 "GrammarParser.cpp"
    break;

  case 89:
#line 926 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = CST::make< BinaryExpression >( yylhs.location, yystack_[2].value.as < Expression::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
  }
#line 2985 "GrammarParser.cpp"
    break;

  case 90:
#line 930 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = CST::make< BinaryExpression >( yylhs.location, yystack_[2].value.as < Expression::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
  }
#line 2993 "GrammarParser.cpp"
    break;

  case 91:
#line 934 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = CST::make< BinaryExpression >( yylhs.location, yystack_[2].value.as < Expression::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
  }
#line 3001 "GrammarParser.cpp"
    break;

  case 92:
#line 938 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = CST::make< BinaryExpression >( yylhs.location, yystack_[2].value.as < Expression::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
  }
#line 3009 "GrammarParser.cpp"
    break;

  case 93:
#line 942 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = CST::make< BinaryExpression >( yylhs.location, yystack_[2].value.as < Expression::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
  }
#line 3017 "GrammarParser.cpp"
    break;

  case 94:
#line 946 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = CST::make< BinaryExpression >( yylhs.location, yystack_[2].value.as < Expression::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
  }
#line 3025 "GrammarParser.cpp"
    break;

  case 95:
#line 950 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = CST::make< BinaryExpression >( yylhs.location, yystack_[2].value.as < Expression::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
  }
#line 3033 "GrammarParser.cpp"
    break;

  case 96:
#line 954 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = CST::make< BinaryExpression >( yylhs.location, yystack_[2].value.as < Expression::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
  }
#line 3041 "GrammarParser.cpp"
    break;

  case 97:
#line 958 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = CST::make< BinaryExpression >( yylhs.location, yystack_[2].value.as < Expression::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
  }
#line 3049 "GrammarParser.cpp"
    break;

  case 98:
#line 962 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = CST::make< BinaryExpression >( yylhs.location, yystack_[2].value.as < Expression::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
  }
#line 3057 "GrammarParser.cpp"
    break;

  case 99:
#line 966 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = CST::make< BinaryExpression >( yylhs.location, yystack_[2].value.as < Expression::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
  }
#line 3065 "GrammarParser.cpp"
    break;

  case 100:
#line 970 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = CST::make< BinaryExpression >( yylhs.location, yystack_[2].value.as < Expression::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
  }
#line 3073 "GrammarParser.cpp"
    break;

  case 101:
#line 974 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = CST::make< BinaryExpression >( yylhs.location, yystack_[2].value.as < Expression::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
  }
#line 3081 "GrammarParser.cpp"
    break;

  case 102:
#line 978 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = CST::make< BinaryExpression >( yylhs.location, yystack_[2].value.as < Expression::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
  }
#line 3089 "GrammarParser.cpp"
    break;

  case 103:
#line 982 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = CST::make< BinaryExpression >( yylhs.location, yystack_[2].value.as < Expression::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
  }
#line 3097 "GrammarParser.cpp"
    break;

  case 104:
#line 990 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < CallExpression::Ptr > () = yystack_[0].value.as < DirectCallExpression::Ptr > ();
  }
#line 3105 "GrammarParser.cpp"
    break;

  case 105:
#line 994 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < CallExpression::Ptr > () = yystack_[0].value.as < MethodCallExpression::Ptr > ();
  }
#line 3113 "GrammarParser.cpp"
    break;

  case 106:
#line 1002 "../../obj/src/GrammarParser.y"
  {
      const auto& arguments = CST::make< Expressions >( yylhs.location );
      yylhs.value.as < DirectCallExpression::Ptr > () = CST::make< DirectCallExpression >( yylhs.location, yystack_[0].value.as < IdentifierPath::Ptr > (), Token::unresolved(), arguments, Token::unresolved() );
  }
#line 3122 "GrammarParser.cpp"
    break;

  case 107:
#line 1007 "../../obj/src/GrammarParser.y"
  {
      const auto& arguments = CST::make< Expressions >( yylhs.location );
      yylhs.value.as < DirectCallExpression::Ptr > () = CST::make< DirectCallExpression >( yylhs.location, yystack_[2].value.as < IdentifierPath::Ptr > (), Token::unresolved(), arguments, Token::unresolved() );
  }
#line 3131 "GrammarParser.cpp"
    break;

  case 108:
#line 1012 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < DirectCallExpression::Ptr > () = CST::make< DirectCallExpression >( yylhs.location, yystack_[3].value.as < IdentifierPath::Ptr > (), Token::unresolved(), yystack_[1].value.as < Expressions::Ptr > (), Token::unresolved() );
  }
#line 3139 "GrammarParser.cpp"
    break;

  case 109:
#line 1016 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < DirectCallExpression::Ptr > () = nullptr;
  }
#line 3147 "GrammarParser.cpp"
    break;

  case 110:
#line 1024 "../../obj/src/GrammarParser.y"
  {
      const auto& arguments = CST::make< Expressions >( yylhs.location );
      yylhs.value.as < MethodCallExpression::Ptr > () = CST::make< MethodCallExpression >( yylhs.location, yystack_[2].value.as < Expression::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Identifier::Ptr > (), Token::unresolved(), arguments, Token::unresolved() );
  }
#line 3156 "GrammarParser.cpp"
    break;

  case 111:
#line 1029 "../../obj/src/GrammarParser.y"
  {
      const auto& arguments = CST::make< Expressions >( yylhs.location );
      yylhs.value.as < MethodCallExpression::Ptr > () = CST::make< MethodCallExpression >( yylhs.location, yystack_[4].value.as < Expression::Ptr > (), yystack_[3].value.as < CST::Token::Ptr > (), yystack_[2].value.as < Identifier::Ptr > (), Token::unresolved(), arguments, Token::unresolved() );
  }
#line 3165 "GrammarParser.cpp"
    break;

  case 112:
#line 1034 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < MethodCallExpression::Ptr > () = CST::make< MethodCallExpression >( yylhs.location, yystack_[5].value.as < Expression::Ptr > (), yystack_[4].value.as < CST::Token::Ptr > (), yystack_[3].value.as < Identifier::Ptr > (), Token::unresolved(), yystack_[1].value.as < Expressions::Ptr > (), Token::unresolved() );
  }
#line 3173 "GrammarParser.cpp"
    break;

  case 113:
#line 1038 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < MethodCallExpression::Ptr > () = nullptr;
  }
#line 3181 "GrammarParser.cpp"
    break;

  case 114:
#line 1050 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Literal::Ptr > () = yystack_[0].value.as < ValueLiteral::Ptr > ();
  }
#line 3189 "GrammarParser.cpp"
    break;

  case 115:
#line 1054 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Literal::Ptr > () = yystack_[0].value.as < ValueLiteral::Ptr > ();
  }
#line 3197 "GrammarParser.cpp"
    break;

  case 116:
#line 1058 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Literal::Ptr > () = yystack_[0].value.as < ValueLiteral::Ptr > ();
  }
#line 3205 "GrammarParser.cpp"
    break;

  case 117:
#line 1062 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Literal::Ptr > () = yystack_[0].value.as < ValueLiteral::Ptr > ();
  }
#line 3213 "GrammarParser.cpp"
    break;

  case 118:
#line 1066 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Literal::Ptr > () = yystack_[0].value.as < SetLiteral::Ptr > ();
  }
#line 3221 "GrammarParser.cpp"
    break;

  case 119:
#line 1070 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Literal::Ptr > () = yystack_[0].value.as < ListLiteral::Ptr > ();
  }
#line 3229 "GrammarParser.cpp"
    break;

  case 120:
#line 1074 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Literal::Ptr > () = yystack_[0].value.as < RangeLiteral::Ptr > ();
  }
#line 3237 "GrammarParser.cpp"
    break;

  case 121:
#line 1078 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Literal::Ptr > () = yystack_[0].value.as < RecordLiteral::Ptr > ();
  }
#line 3245 "GrammarParser.cpp"
    break;

  case 122:
#line 1082 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Literal::Ptr > () = yystack_[0].value.as < MappingLiteral::Ptr > ();
  }
#line 3253 "GrammarParser.cpp"
    break;

  case 123:
#line 1086 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Literal::Ptr > () = yystack_[0].value.as < ReferenceLiteral::Ptr > ();
  }
#line 3261 "GrammarParser.cpp"
    break;

  case 124:
#line 1090 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Literal::Ptr > () = yystack_[0].value.as < GrammarLiteral::Ptr > ();
  }
#line 3269 "GrammarParser.cpp"
    break;

  case 125:
#line 1098 "../../obj/src/GrammarParser.y"
  {
      const auto& value = libstdhl::Type::createBoolean( true );
      yylhs.value.as < ValueLiteral::Ptr > () = CST::make< ValueLiteral >( yylhs.location, value, ValueLiteral::Kind::BOOLEAN );
      yylhs.value.as < ValueLiteral::Ptr > ()->setSpans( yystack_[0].value.as < CST::Token::Ptr > ()->spans() );
  }
#line 3279 "GrammarParser.cpp"
    break;

  case 126:
#line 1104 "../../obj/src/GrammarParser.y"
  {
      const auto& value = libstdhl::Type::createBoolean( false );
      yylhs.value.as < ValueLiteral::Ptr > () = CST::make< ValueLiteral >( yylhs.location, value, ValueLiteral::Kind::BOOLEAN );
      yylhs.value.as < ValueLiteral::Ptr > ()->setSpans( yystack_[0].value.as < CST::Token::Ptr > ()->spans() );
  }
#line 3289 "GrammarParser.cpp"
    break;

  case 127:
#line 1114 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < ValueLiteral::Ptr > () = yystack_[0].value.as < ValueLiteral::Ptr > ();
  }
#line 3297 "GrammarParser.cpp"
    break;

  case 128:
#line 1122 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < ValueLiteral::Ptr > () = yystack_[0].value.as < ValueLiteral::Ptr > ();
  }
#line 3305 "GrammarParser.cpp"
    break;

  case 129:
#line 1126 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < ValueLiteral::Ptr > () = yystack_[0].value.as < ValueLiteral::Ptr > ();
  }
#line 3313 "GrammarParser.cpp"
    break;

  case 130:
#line 1134 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < ValueLiteral::Ptr > () = yystack_[0].value.as < ValueLiteral::Ptr > ();
  }
#line 3321 "GrammarParser.cpp"
    break;

  case 131:
#line 1142 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < SetLiteral::Ptr > () = CST::make< SetLiteral >( yylhs.location, yystack_[1].value.as < Expressions::Ptr > () );
      yylhs.value.as < SetLiteral::Ptr > ()->setLeftBracket( yystack_[2].value.as < CST::Token::Ptr > () );
      yylhs.value.as < SetLiteral::Ptr > ()->setRightBracket( yystack_[0].value.as < CST::Token::Ptr > () );
  }
#line 3331 "GrammarParser.cpp"
    break;

  case 132:
#line 1152 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < ListLiteral::Ptr > () = CST::make< ListLiteral >( yylhs.location, yystack_[1].value.as < Expressions::Ptr > () );
      yylhs.value.as < ListLiteral::Ptr > ()->setLeftBracket( yystack_[2].value.as < CST::Token::Ptr > () );
      yylhs.value.as < ListLiteral::Ptr > ()->setRightBracket( yystack_[0].value.as < CST::Token::Ptr > () );
  }
#line 3341 "GrammarParser.cpp"
    break;

  case 133:
#line 1162 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < RangeLiteral::Ptr > () = CST::make< RangeLiteral >( yylhs.location, yystack_[3].value.as < Expression::Ptr > (), yystack_[2].value.as < CST::Token::Ptr > (), yystack_[1].value.as < Expression::Ptr > () );
      yylhs.value.as < RangeLiteral::Ptr > ()->setLeftBracket( yystack_[4].value.as < CST::Token::Ptr > () );
      yylhs.value.as < RangeLiteral::Ptr > ()->setRightBracket( yystack_[0].value.as < CST::Token::Ptr > () );
  }
#line 3351 "GrammarParser.cpp"
    break;

  case 134:
#line 1172 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < RecordLiteral::Ptr > () = CST::make< RecordLiteral >( yylhs.location, yystack_[1].value.as < NamedExpressions::Ptr > () );
      yylhs.value.as < RecordLiteral::Ptr > ()->setLeftBracket( yystack_[2].value.as < CST::Token::Ptr > () );
      yylhs.value.as < RecordLiteral::Ptr > ()->setRightBracket( yystack_[0].value.as < CST::Token::Ptr > () );
  }
#line 3361 "GrammarParser.cpp"
    break;

  case 135:
#line 1181 "../../obj/src/GrammarParser.y"
  {
      auto assignments = yystack_[2].value.as < NamedExpressions::Ptr > ();
      yystack_[0].value.as < NamedExpression::Ptr > ()->setDelimiterToken( yystack_[1].value.as < CST::Token::Ptr > () );
      assignments->add( yystack_[0].value.as < NamedExpression::Ptr > () );
      yylhs.value.as < NamedExpressions::Ptr > () = assignments;
  }
#line 3372 "GrammarParser.cpp"
    break;

  case 136:
#line 1188 "../../obj/src/GrammarParser.y"
  {
      auto assignments = CST::make< NamedExpressions >( yylhs.location );
      assignments->add( yystack_[0].value.as < NamedExpression::Ptr > () );
      yylhs.value.as < NamedExpressions::Ptr > () = assignments;
  }
#line 3382 "GrammarParser.cpp"
    break;

  case 137:
#line 1197 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < NamedExpression::Ptr > () = CST::make< NamedExpression >( yylhs.location, yystack_[2].value.as < Identifier::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
  }
#line 3390 "GrammarParser.cpp"
    break;

  case 138:
#line 1205 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < MappingLiteral::Ptr > () = CST::make< MappingLiteral >( yylhs.location, yystack_[1].value.as < MappedExpressions::Ptr > () );
      yylhs.value.as < MappingLiteral::Ptr > ()->setLeftBracket( yystack_[2].value.as < CST::Token::Ptr > () );
      yylhs.value.as < MappingLiteral::Ptr > ()->setRightBracket( yystack_[0].value.as < CST::Token::Ptr > () );
  }
#line 3400 "GrammarParser.cpp"
    break;

  case 139:
#line 1214 "../../obj/src/GrammarParser.y"
  {
      auto mappings = yystack_[2].value.as < MappedExpressions::Ptr > ();
      yystack_[0].value.as < MappedExpression::Ptr > ()->setDelimiterToken( yystack_[1].value.as < CST::Token::Ptr > () );
      mappings->add( yystack_[0].value.as < MappedExpression::Ptr > () );
      yylhs.value.as < MappedExpressions::Ptr > () = mappings;
  }
#line 3411 "GrammarParser.cpp"
    break;

  case 140:
#line 1221 "../../obj/src/GrammarParser.y"
  {
      auto mappings = CST::make< MappedExpressions >( yylhs.location );
      mappings->add( yystack_[0].value.as < MappedExpression::Ptr > () );
      yylhs.value.as < MappedExpressions::Ptr > () = mappings;
  }
#line 3421 "GrammarParser.cpp"
    break;

  case 141:
#line 1230 "../../obj/src/GrammarParser.y"
  {
      const auto& expressions = CST::make< Expressions >( yystack_[2].location );
      expressions->add( yystack_[2].value.as < Expression::Ptr > () );
      yylhs.value.as < MappedExpression::Ptr > () = CST::make< MappedExpression >( yylhs.location, Token::unresolved(), expressions, Token::unresolved(), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
  }
#line 3431 "GrammarParser.cpp"
    break;

  case 142:
#line 1236 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < MappedExpression::Ptr > () = CST::make< MappedExpression >( yylhs.location, yystack_[4].value.as < CST::Token::Ptr > (), yystack_[3].value.as < Expressions::Ptr > (), yystack_[2].value.as < CST::Token::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
  }
#line 3439 "GrammarParser.cpp"
    break;

  case 143:
#line 1244 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < ReferenceLiteral::Ptr > () = CST::make< ReferenceLiteral >( yylhs.location, yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < IdentifierPath::Ptr > () );
  }
#line 3447 "GrammarParser.cpp"
    break;

  case 144:
#line 1252 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < GrammarLiteral::Ptr > () = CST::make< GrammarLiteral >( yylhs.location, yystack_[1].value.as < Expressions::Ptr > () );
      yylhs.value.as < GrammarLiteral::Ptr > ()->setLeftBracket( yystack_[2].value.as < CST::Token::Ptr > () );
  }
#line 3456 "GrammarParser.cpp"
    break;

  case 145:
#line 1261 "../../obj/src/GrammarParser.y"
  {
      auto terminals = yystack_[1].value.as < Expressions::Ptr > ();
      terminals->add( yystack_[0].value.as < Expression::Ptr > () );
      yylhs.value.as < Expressions::Ptr > () = terminals;
  }
#line 3466 "GrammarParser.cpp"
    break;

  case 146:
#line 1267 "../../obj/src/GrammarParser.y"
  {
      auto terminals = CST::make< Expressions >( yylhs.location );
      terminals->add( yystack_[0].value.as < Expression::Ptr > () );
      yylhs.value.as < Expressions::Ptr > () = terminals;
  }
#line 3476 "GrammarParser.cpp"
    break;

  case 147:
#line 1277 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = yystack_[0].value.as < DirectCallExpression::Ptr > ();
  }
#line 3484 "GrammarParser.cpp"
    break;

  case 148:
#line 1281 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = yystack_[0].value.as < ValueLiteral::Ptr > ();
  }
#line 3492 "GrammarParser.cpp"
    break;

  case 149:
#line 1285 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = yystack_[0].value.as < ValueLiteral::Ptr > ();
  }
#line 3500 "GrammarParser.cpp"
    break;

  case 150:
#line 1289 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = yystack_[0].value.as < ValueLiteral::Ptr > ();
  }
#line 3508 "GrammarParser.cpp"
    break;

  case 151:
#line 1293 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Expression::Ptr > () = yystack_[0].value.as < ReferenceLiteral::Ptr > ();
  }
#line 3516 "GrammarParser.cpp"
    break;

  case 152:
#line 1323 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < libscod::CST::Type::Ptr > () = yystack_[0].value.as < libscod::CST::Type::Ptr > ();
  }
#line 3524 "GrammarParser.cpp"
    break;

  case 153:
#line 1327 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < libscod::CST::Type::Ptr > () = yystack_[0].value.as < MappingType::Ptr > ();
  }
#line 3532 "GrammarParser.cpp"
    break;

  case 154:
#line 1335 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < libscod::CST::Type::Ptr > () = CST::make< BasicType >( yylhs.location, yystack_[0].value.as < IdentifierPath::Ptr > () );
  }
#line 3540 "GrammarParser.cpp"
    break;

  case 155:
#line 1339 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < libscod::CST::Type::Ptr > () = yystack_[0].value.as < libscod::CST::Type::Ptr > ();
  }
#line 3548 "GrammarParser.cpp"
    break;

  case 156:
#line 1347 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < libscod::CST::Type::Ptr > () = CST::make< PropertyType >( yylhs.location, yystack_[2].value.as < IdentifierPath::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < ValueLiteral::Ptr > () );
  }
#line 3556 "GrammarParser.cpp"
    break;

  case 157:
#line 1355 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < MappingType::Ptr > () = CST::make< MappingType >( yylhs.location, yystack_[2].value.as < Types::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < libscod::CST::Type::Ptr > () );
  }
#line 3564 "GrammarParser.cpp"
    break;

  case 158:
#line 1363 "../../obj/src/GrammarParser.y"
  {
      auto types = yystack_[2].value.as < Types::Ptr > ();
      yystack_[0].value.as < libscod::CST::Type::Ptr > ()->setDelimiterToken( yystack_[1].value.as < CST::Token::Ptr > () );
      types->add( yystack_[0].value.as < libscod::CST::Type::Ptr > () );
      yylhs.value.as < Types::Ptr > () = types;
  }
#line 3575 "GrammarParser.cpp"
    break;

  case 159:
#line 1370 "../../obj/src/GrammarParser.y"
  {
      auto types = CST::make< Types >( yylhs.location );
      types->add( yystack_[0].value.as < libscod::CST::Type::Ptr > () );
      yylhs.value.as < Types::Ptr > () = types;
  }
#line 3585 "GrammarParser.cpp"
    break;

  case 160:
#line 1384 "../../obj/src/GrammarParser.y"
  {
      auto variableBindings = yystack_[2].value.as < VariableBindings::Ptr > ();
      yystack_[0].value.as < VariableBinding::Ptr > ()->setDelimiterToken( yystack_[1].value.as < CST::Token::Ptr > () );
      variableBindings->add( yystack_[0].value.as < VariableBinding::Ptr > () );
      yylhs.value.as < VariableBindings::Ptr > () = variableBindings;
  }
#line 3596 "GrammarParser.cpp"
    break;

  case 161:
#line 1391 "../../obj/src/GrammarParser.y"
  {
      auto variableBindings = CST::make< VariableBindings >( yylhs.location );
      variableBindings->add( yystack_[0].value.as < VariableBinding::Ptr > () );
      yylhs.value.as < VariableBindings::Ptr > () = variableBindings;
  }
#line 3606 "GrammarParser.cpp"
    break;

  case 162:
#line 1401 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < VariableBinding::Ptr > () = CST::make< VariableBinding >( yylhs.location, yystack_[2].value.as < VariableDefinition::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
  }
#line 3614 "GrammarParser.cpp"
    break;

  case 163:
#line 1409 "../../obj/src/GrammarParser.y"
  {
      auto variable = yystack_[0].value.as < VariableDefinition::Ptr > ();
      variable->setAttributes( yystack_[1].value.as < Attributes::Ptr > () );
      yylhs.value.as < VariableDefinition::Ptr > () = variable;
  }
#line 3624 "GrammarParser.cpp"
    break;

  case 164:
#line 1415 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < VariableDefinition::Ptr > () = yystack_[0].value.as < VariableDefinition::Ptr > ();
  }
#line 3632 "GrammarParser.cpp"
    break;

  case 165:
#line 1423 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < VariableDefinition::Ptr > () = yystack_[0].value.as < VariableDefinition::Ptr > ();
  }
#line 3640 "GrammarParser.cpp"
    break;

  case 166:
#line 1427 "../../obj/src/GrammarParser.y"
  {
      const auto unresolvedType = CST::make< UnresolvedType >( yylhs.location );
      yylhs.value.as < VariableDefinition::Ptr > () = CST::make< VariableDefinition >( yylhs.location, yystack_[0].value.as < Identifier::Ptr > (), Token::unresolved(), unresolvedType );
  }
#line 3649 "GrammarParser.cpp"
    break;

  case 167:
#line 1436 "../../obj/src/GrammarParser.y"
  {
      auto variable = CST::make< VariableDefinition >( yylhs.location, yystack_[2].value.as < Identifier::Ptr > (), yystack_[1].value.as < CST::Token::Ptr > (), yystack_[0].value.as < libscod::CST::Type::Ptr > () );
      yylhs.value.as < VariableDefinition::Ptr > () = variable;
  }
#line 3658 "GrammarParser.cpp"
    break;

  case 168:
#line 1450 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 3666 "GrammarParser.cpp"
    break;

  case 169:
#line 1454 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Identifier::Ptr > () = CST::make< Identifier >( yylhs.location, "instruction" );
      yylhs.value.as < Identifier::Ptr > ()->setSpans( m_lexer.fetchSpansAndReset() );
  }
#line 3675 "GrammarParser.cpp"
    break;

  case 170:
#line 1459 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Identifier::Ptr > () = CST::make< Identifier >( yylhs.location, "decoding" );
      yylhs.value.as < Identifier::Ptr > ()->setSpans( m_lexer.fetchSpansAndReset() );
  }
#line 3684 "GrammarParser.cpp"
    break;

  case 171:
#line 1468 "../../obj/src/GrammarParser.y"
  {
      auto path = yystack_[2].value.as < IdentifierPath::Ptr > ();
      yystack_[0].value.as < Identifier::Ptr > ()->setNamespaceToken( yystack_[1].value.as < CST::Token::Ptr > () );
      path->addIdentifier( yystack_[0].value.as < Identifier::Ptr > () );
      yylhs.value.as < IdentifierPath::Ptr > () = path;
  }
#line 3695 "GrammarParser.cpp"
    break;

  case 172:
#line 1475 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < IdentifierPath::Ptr > () = CST::make< IdentifierPath >( yylhs.location, yystack_[0].value.as < Identifier::Ptr > () );
  }
#line 3703 "GrammarParser.cpp"
    break;

  case 173:
#line 1487 "../../obj/src/GrammarParser.y"
  {
      auto attributes = yystack_[1].value.as < Attributes::Ptr > ();
      attributes->add( yystack_[0].value.as < Attribute::Ptr > () );
      yylhs.value.as < Attributes::Ptr > () = attributes;
  }
#line 3713 "GrammarParser.cpp"
    break;

  case 174:
#line 1493 "../../obj/src/GrammarParser.y"
  {
      auto attributes = CST::make< Attributes >( yylhs.location );
      attributes->add( yystack_[0].value.as < Attribute::Ptr > () );
      yylhs.value.as < Attributes::Ptr > () = attributes;
  }
#line 3723 "GrammarParser.cpp"
    break;

  case 175:
#line 1502 "../../obj/src/GrammarParser.y"
  {
      auto attribute = yystack_[1].value.as < BasicAttribute::Ptr > ();
      yystack_[1].value.as < BasicAttribute::Ptr > ()->setLeftBrace( yystack_[2].value.as < CST::Token::Ptr > () );
      yystack_[1].value.as < BasicAttribute::Ptr > ()->setRightBrace( yystack_[0].value.as < CST::Token::Ptr > () );
      yylhs.value.as < Attribute::Ptr > () = attribute;
  }
#line 3734 "GrammarParser.cpp"
    break;

  case 176:
#line 1509 "../../obj/src/GrammarParser.y"
  {
      auto attribute = yystack_[1].value.as < ExpressionAttribute::Ptr > ();
      yystack_[1].value.as < ExpressionAttribute::Ptr > ()->setLeftBrace( yystack_[2].value.as < CST::Token::Ptr > () );
      yystack_[1].value.as < ExpressionAttribute::Ptr > ()->setRightBrace( yystack_[0].value.as < CST::Token::Ptr > () );
      yylhs.value.as < Attribute::Ptr > () = attribute;
  }
#line 3745 "GrammarParser.cpp"
    break;

  case 177:
#line 1516 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < Attribute::Ptr > () = nullptr;
  }
#line 3753 "GrammarParser.cpp"
    break;

  case 178:
#line 1523 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < BasicAttribute::Ptr > () = CST::make< BasicAttribute >( yylhs.location, yystack_[0].value.as < Identifier::Ptr > () );
  }
#line 3761 "GrammarParser.cpp"
    break;

  case 179:
#line 1530 "../../obj/src/GrammarParser.y"
  {
      yylhs.value.as < ExpressionAttribute::Ptr > () = CST::make< ExpressionAttribute >( yylhs.location, yystack_[1].value.as < Identifier::Ptr > (), yystack_[0].value.as < Expression::Ptr > () );
  }
#line 3769 "GrammarParser.cpp"
    break;


#line 3773 "GrammarParser.cpp"

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


  const short Parser::yypact_ninf_ = -173;

  const short Parser::yytable_ninf_ = -168;

  const short
  Parser::yypact_[] =
  {
       8,  -173,    25,    37,   452,    10,  -173,   -48,  -173,  -173,
    -173,   367,    16,    50,  -173,  -173,    22,    22,    22,    22,
      22,    22,    22,    22,    22,    22,    22,    22,   357,  -173,
    -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,
    -173,  -173,  -173,   250,   467,  -173,  -173,  -173,    23,   367,
    -173,  -173,   367,   367,   367,    57,   367,   367,   383,  -173,
    -173,  -173,  -173,   625,    19,  -173,  -173,  -173,  -173,  -173,
    -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,
    -173,  -173,  -173,  -173,     4,  -173,  -173,    47,   108,   113,
     118,   121,   125,   151,   157,   160,   106,   172,    29,  -173,
     173,   177,   186,  -173,  -173,  -173,  -173,    31,  -173,   189,
    -173,  -173,   183,    23,   558,  -173,   198,   198,  -173,  -173,
    -173,  -173,  -173,    20,  -173,   530,    59,   457,   367,    36,
     603,   140,  -173,   161,  -173,   187,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,    22,    22,   271,    22,
      22,    22,    22,    22,    22,    22,    22,    22,   179,    22,
     191,   179,   179,   367,    23,   367,    22,  -173,   192,  -173,
    -173,  -173,  -173,   367,   367,    45,   530,  -173,   367,  -173,
      22,  -173,   383,   367,   700,   665,   685,   645,   645,   198,
     198,   198,   198,  -173,   207,   207,   207,   207,   715,   715,
     515,   515,   515,   515,   193,  -173,   196,  -173,    53,   625,
    -173,  -173,  -173,   -11,    34,    97,    40,  -173,    40,   213,
     225,   227,   -13,   228,   230,   367,  -173,  -173,    40,    22,
    -173,  -173,  -173,   625,  -173,   625,   231,     0,   625,   500,
     229,   625,  -173,   187,   603,  -173,   625,   287,  -173,  -173,
      22,    22,   210,   218,   367,   148,   148,   218,   218,   192,
    -173,   367,   233,  -173,    94,  -173,  -173,  -173,   383,  -173,
    -173,   625,  -173,  -173,    23,   367,    41,   250,  -173,  -173,
    -173,  -173,  -173,  -173,  -173,   232,   267,  -173,  -173,    19,
     625,  -173,  -173,    33,   583,   226,    93,  -173,   250,  -173,
    -173,  -173,  -173,   367,    22,   267,  -173,  -173,   148,   148,
    -173,  -173,  -173,  -173,   625,   242,  -173,  -173,   262,   234,
     148,  -173,  -173
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       0,     4,     0,     0,     0,     0,   174,     0,   169,   170,
     168,   178,     0,     0,     1,     9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     6,
       8,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     0,     0,     3,   173,   177,     0,     0,
     126,   125,     0,     0,     0,     0,     0,     0,     0,   127,
     128,   129,   130,   179,    72,    73,    74,    75,    77,   104,
     105,    78,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   172,   106,   175,   176,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   143,     5,
       0,     0,     0,    34,    35,    36,     7,     0,   161,     0,
     164,   165,   166,     0,     0,    83,    79,    80,   147,   148,
     149,   150,   151,     0,   146,     0,     0,    71,     0,     0,
      71,     0,   136,     0,   140,   172,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   163,     0,   144,
     145,    76,   132,     0,     0,     0,    71,   131,     0,   134,
       0,   138,     0,     0,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   110,   171,     0,   107,     0,    71,
     159,   152,   155,    22,     0,   154,    23,   153,    24,     0,
     159,     0,     0,   159,   159,     0,    37,    38,    39,     0,
      45,    46,    47,    81,   160,   162,   159,     0,    70,     0,
       0,   141,   135,     0,     0,   139,   137,     0,   109,   108,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     133,     0,     0,   111,     0,   158,   157,   156,     0,    25,
      26,    27,    61,    62,     0,     0,     0,    28,    54,    55,
      56,    57,    58,    59,    60,    65,    30,    32,    33,    82,
     142,   113,   112,     0,     0,     0,     0,    53,    29,    41,
      42,    43,    44,     0,     0,    31,    49,    50,     0,     0,
      64,    63,    52,    40,    67,     0,    48,    66,    68,     0,
       0,    51,    69
  };

  const short
  Parser::yypgoto_[] =
  {
    -173,  -173,  -173,  -173,   273,   251,  -173,  -173,  -173,  -173,
    -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,
    -173,    -6,   260,   263,   266,  -173,    -4,  -173,  -173,  -108,
    -173,  -173,   -12,  -173,  -173,  -173,  -173,   -53,    -9,  -172,
    -173,  -173,  -173,  -173,   -52,  -173,  -173,  -173,   -54,   -47,
     -46,    14,  -173,  -173,   146,  -173,   128,   -87,  -173,   127,
      24,  -173,  -173,   197,    64,  -157,  -173,   163,  -173,    49,
     150,  -173,   216,  -173,    -2,    30,   159,     7,  -173,  -173
  };

  const short
  Parser::yydefgoto_[] =
  {
      -1,     3,     4,    28,    29,    30,    31,    32,    33,    34,
     279,    35,    36,    37,    38,    39,    40,    41,   236,    42,
     308,   309,   310,   311,   312,   315,   316,   317,   306,   287,
     288,   289,   290,   291,   292,   293,   294,   129,   219,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,   131,   132,    80,   133,   134,
      81,    82,   123,   124,   220,   221,   222,   227,   224,   107,
     108,   109,   110,   111,    83,    84,   113,     6,    12,    13
  };

  const short
  Parser::yytable_[] =
  {
      11,   119,    63,   118,   126,   229,   247,   231,   120,   121,
      47,     1,    46,    45,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,   269,     7,  -153,    43,     8,
     266,     8,     8,     9,     8,     9,     9,    14,     9,  -153,
     114,   157,   305,   115,   116,   117,   112,   125,   127,   130,
       8,    46,    43,   173,     9,   318,   135,    98,   157,   158,
     282,   283,   284,   156,   285,     2,     8,     2,    43,   119,
       9,   118,   260,   179,    85,   185,   120,   121,  -159,   122,
       2,    27,   156,   157,   261,    59,    60,    61,    62,    10,
    -159,    10,    10,   174,    10,   174,   187,   299,   183,   159,
     286,   250,     8,   275,   276,   218,     9,   183,    86,   259,
      10,   112,   282,   283,   284,   183,   285,   182,    27,   186,
      46,   183,    59,    60,    61,    62,    10,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   122,   262,   168,
     302,   157,   286,   321,   214,   215,   183,     8,   296,     5,
     160,     9,    10,    44,   243,   161,   245,   282,   283,   284,
     162,   285,   112,   163,   248,   249,   280,   164,   307,   251,
     297,   298,   237,   254,   256,   241,   242,    44,   253,   225,
     225,   225,   225,   225,   225,   232,   225,   225,   322,   225,
     189,     8,   190,   165,   274,     9,   225,   286,   277,   166,
     327,   328,   167,   295,   295,   169,   170,    10,    50,    51,
     171,   191,   332,   192,   226,   228,    53,   230,    54,   172,
     233,   234,   175,   238,   295,   176,   145,   253,   235,   193,
     246,   141,   142,   143,   144,   145,    55,    56,   257,    57,
     239,    58,   258,    27,   295,   281,   263,    59,    60,    61,
      62,    10,   300,   100,   101,   102,   295,   295,   264,   254,
     265,   267,   216,   268,  -167,    59,   304,   278,   295,   271,
       8,   313,   112,   314,     9,   329,   320,   330,   272,   301,
     225,   225,    48,   286,    49,   106,     8,    50,    51,    52,
       9,    99,   323,   103,   324,    53,   104,    54,    48,   105,
      49,   326,   325,    50,    51,    52,   240,   331,   252,   255,
     180,    53,   223,    54,   244,    55,    56,   217,    57,   177,
      58,     0,    27,   303,     0,     0,    59,    60,    61,    62,
      10,    55,    56,   273,    57,     0,    58,     0,    27,     0,
       0,     0,    59,    60,    61,    62,    10,    -2,    15,     0,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       0,     0,     0,     0,    25,    26,     8,     0,     0,     0,
       9,     0,     0,     0,     0,     0,     0,     0,    48,     0,
      49,     0,     8,    50,    51,    52,     9,     0,     0,     0,
       0,    53,     0,    54,    48,     0,    49,     0,     0,    50,
      51,    52,     0,     0,     2,     0,     0,    53,    27,    54,
       0,    55,    56,     0,    57,     0,    58,     0,    27,     0,
       0,     0,    59,    60,    61,    62,    10,    55,   128,     0,
      57,     0,    58,     0,    27,     0,     0,     0,    59,    60,
      61,    62,    10,    15,     0,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,     0,     0,     0,     0,    25,
      26,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       0,     0,     0,     0,    25,    26,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,     0,     0,     0,     2,
       0,     0,     0,    27,     0,     0,     0,     0,     0,     0,
       0,   184,     0,     0,     2,     0,     0,     0,    27,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   270,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,     0,
       0,     0,   178,     0,     0,     0,   181,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   319,     0,     0,
       0,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,     0,   188,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   136,   137,   138,     0,     0,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   136,     0,   138,     0,     0,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   136,     0,     0,     0,     0,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   141,
     142,   143,   144,   145,   146,   147,   148,   149,     0,     0,
     152,   153,   154,   155
  };

  const short
  Parser::yycheck_[] =
  {
       2,    55,    11,    55,    57,   162,   178,   164,    55,    55,
      58,     3,     5,     3,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    25,     1,    38,     4,     9,
      43,     9,     9,    13,     9,    13,    13,     0,    13,    50,
      49,    54,     1,    52,    53,    54,    48,    56,    57,    58,
       9,    44,    28,    22,    13,    22,    58,    27,    54,    55,
      19,    20,    21,    63,    23,    57,     9,    57,    44,   123,
      13,   123,    38,    53,    58,   128,   123,   123,    38,    55,
      57,    61,    63,    54,    50,    65,    66,    67,    68,    69,
      50,    69,    69,    62,    69,    62,    60,   269,    62,    52,
      59,    56,     9,   260,   261,   158,    13,    62,    58,    56,
      69,   113,    19,    20,    21,    62,    23,    58,    61,   128,
     113,    62,    65,    66,    67,    68,    69,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   123,    51,    43,
      56,    54,    59,    60,   156,   157,    62,     9,   266,     0,
      52,    13,    69,     4,   173,    52,   175,    19,    20,    21,
      52,    23,   174,    52,   183,   184,   263,    52,   286,   188,
     267,   268,   168,   192,   193,   171,   172,    28,   190,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   306,   169,
      60,     9,    62,    52,   257,    13,   176,    59,   262,    52,
     318,   319,    52,   265,   266,    43,    43,    69,    26,    27,
      43,    60,   330,    62,   160,   161,    34,   163,    36,    43,
     166,   167,    43,   169,   286,    52,    38,   239,    59,    52,
     176,    34,    35,    36,    37,    38,    54,    55,    55,    57,
      59,    59,    56,    61,   306,   264,    43,    65,    66,    67,
      68,    69,   271,    13,    14,    15,   318,   319,    43,   278,
      43,    43,     1,    43,    43,    65,   285,    59,   330,    50,
       9,    49,   284,    16,    13,    43,    60,    25,     1,    56,
     260,   261,    21,    59,    23,    44,     9,    26,    27,    28,
      13,    28,   308,    43,   313,    34,    43,    36,    21,    43,
      23,   315,   314,    26,    27,    28,   170,   329,   190,   192,
     123,    34,   159,    36,   174,    54,    55,    56,    57,   113,
      59,    -1,    61,   284,    -1,    -1,    65,    66,    67,    68,
      69,    54,    55,    56,    57,    -1,    59,    -1,    61,    -1,
      -1,    -1,    65,    66,    67,    68,    69,     0,     1,    -1,
      -1,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    -1,    -1,    -1,    17,    18,     9,    -1,    -1,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      23,    -1,     9,    26,    27,    28,    13,    -1,    -1,    -1,
      -1,    34,    -1,    36,    21,    -1,    23,    -1,    -1,    26,
      27,    28,    -1,    -1,    57,    -1,    -1,    34,    61,    36,
      -1,    54,    55,    -1,    57,    -1,    59,    -1,    61,    -1,
      -1,    -1,    65,    66,    67,    68,    69,    54,    55,    -1,
      57,    -1,    59,    -1,    61,    -1,    -1,    -1,    65,    66,
      67,    68,    69,     1,    -1,    -1,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    -1,    -1,    -1,    -1,    17,
      18,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    -1,    -1,    -1,    17,    18,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    -1,    -1,    57,
      -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    -1,    -1,    57,    -1,    -1,    -1,    61,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    58,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    56,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    24,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    50,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    29,    30,    31,    -1,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    29,    -1,    31,    -1,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    29,    -1,    -1,    -1,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    -1,    -1,
      45,    46,    47,    48
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,     3,    57,    71,    72,   146,   147,     1,     9,    13,
      69,   144,   148,   149,     0,     1,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    17,    18,    61,    73,    74,
      75,    76,    77,    78,    79,    81,    82,    83,    84,    85,
      86,    87,    89,   130,   146,     3,   147,    58,    21,    23,
      26,    27,    28,    34,    36,    54,    55,    57,    59,    65,
      66,    67,    68,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     127,   130,   131,   144,   145,    58,    58,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   145,    74,
      13,    14,    15,    92,    93,    94,    75,   139,   140,   141,
     142,   143,   144,   146,   108,   108,   108,   108,   114,   118,
     119,   120,   130,   132,   133,   108,   107,   108,    55,   107,
     108,   125,   126,   128,   129,   144,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    63,    54,    55,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    43,    43,
      43,    43,    43,    22,    62,    43,    52,   142,    24,    53,
     133,    56,    58,    62,    64,   107,   108,    60,    50,    60,
      62,    60,    62,    52,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   144,   144,     1,    56,   107,   108,
     134,   135,   136,   137,   138,   145,   134,   137,   134,   135,
     134,   135,   145,   134,   134,    59,    88,   121,   134,    59,
     124,   121,   121,   108,   140,   108,   134,   109,   108,   108,
      56,   108,   126,   144,   108,   129,   108,    55,    56,    56,
      38,    50,    51,    43,    43,    43,    43,    43,    43,    25,
      58,    50,     1,    56,   107,   135,   135,   118,    59,    80,
     127,   108,    19,    20,    21,    23,    59,    99,   100,   101,
     102,   103,   104,   105,   106,   114,    99,   127,   127,   109,
     108,    56,    56,   139,   108,     1,    98,    99,    90,    91,
      92,    93,    94,    49,    16,    95,    96,    97,    22,    24,
      60,    60,    99,    91,   108,   144,    96,    99,    99,    43,
      25,   102,    99
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,    70,    71,    72,    72,    73,    73,    74,    74,    74,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    76,    77,    78,    79,    80,    81,    82,    82,
      83,    83,    84,    85,    86,    86,    86,    87,    88,    89,
      90,    90,    91,    91,    91,    92,    93,    94,    95,    95,
      96,    97,    98,    98,    99,    99,    99,    99,    99,    99,
      99,   100,   101,   102,   102,   103,   104,   105,   106,   106,
     107,   107,   108,   108,   108,   108,   109,   109,   109,   109,
     109,   110,   111,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   113,   113,   114,   114,   114,   114,
     115,   115,   115,   115,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   117,   117,   118,   119,   119,
     120,   121,   122,   123,   124,   125,   125,   126,   127,   128,
     128,   129,   129,   130,   131,   132,   132,   133,   133,   133,
     133,   133,   134,   134,   135,   135,   136,   137,   138,   138,
     139,   139,   140,   141,   141,   142,   142,   143,   144,   144,
     144,   145,   145,   146,   146,   147,   147,   147,   148,   149
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     2,     2,     1,     2,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     6,     1,     6,     6,     7,
       6,     7,     6,     6,     2,     2,     2,     4,     1,     4,
       2,     1,     1,     1,     1,     3,     3,     3,     2,     1,
       1,     4,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     1,     4,     3,     4,     6,
       3,     1,     1,     1,     1,     1,     3,     1,     1,     2,
       2,     4,     6,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     3,     4,     4,
       3,     5,     6,     6,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     5,     3,     3,     1,     3,     3,     3,
       1,     3,     5,     2,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     1,
       3,     1,     3,     2,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     2,     1,     3,     3,     3,     1,     2
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"SCOD\"", "\"memory\"",
  "\"register\"", "\"field\"", "\"format\"", "\"buffer\"",
  "\"instruction\"", "\"microprocessor\"", "\"cache\"", "\"interconnect\"",
  "\"decoding\"", "\"syntax\"", "\"expansion\"", "\"stage\"",
  "\"enumeration\"", "\"using\"", "\"skip\"", "\"abstract\"", "\"let\"",
  "\"in\"", "\"if\"", "\"then\"", "\"else\"", "\"false\"", "\"true\"",
  "\"not\"", "\"and\"", "\"or\"", "\"xor\"", "\"implies\"", "\"=>\"",
  "\"+\"", "\"(+)\"", "\"-\"", "\"(-)\"", "\"*\"", "\"<<\"", "\"(<<)\"",
  "\">>\"", "\"(>>)\"", "\"=\"", "\"!=\"", "\"<\"", "\"<=\"", "\">\"",
  "\">=\"", "\":=\"", "\"->\"", "\"'\"", "\":\"", "\";\"", "\"::\"",
  "\"(\"", "\")\"", "\"[\"", "\"]\"", "\"{\"", "\"}\"", "\"@\"", "\",\"",
  "\".\"", "\"..\"", "\"integer\"", "\"binary\"", "\"hexadecimal\"",
  "\"string\"", "\"identifier\"", "$accept", "Specification", "Header",
  "Definitions", "AttributedDefinition", "Definition", "MemoryDefinition",
  "RegisterDefinition", "FieldDefinition", "FormatDefinition",
  "FormatFields", "BufferDefinition", "InstructionDefinition",
  "MicroProcessorDefinition", "CacheDefinition", "InterconnectDefinition",
  "OptionDefinition", "EnumerationDefinition", "Enumerators",
  "UsingDefinition", "InstructionOptions", "InstructionOption",
  "DecodingOption", "SyntaxOption", "ExpansionOption",
  "MicroProcessorOptions", "MicroProcessorOption", "StageOption",
  "Statements", "Statement", "SkipStatement", "AbstractStatement",
  "BlockStatement", "CallStatement", "LetStatement", "AssignmentStatement",
  "ConditionalStatement", "Terms", "Term", "Expression", "LetExpression",
  "ConditionalExpression", "OperatorExpression", "CallExpression",
  "DirectCallExpression", "MethodCallExpression", "Literal",
  "BooleanLiteral", "IntegerLiteral", "BinaryLiteral", "StringLiteral",
  "SetLiteral", "ListLiteral", "RangeLiteral", "RecordLiteral",
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
       0,   365,   365,   375,   381,   389,   395,   405,   411,   415,
     423,   427,   431,   435,   439,   443,   447,   451,   455,   459,
     463,   467,   475,   483,   491,   499,   506,   514,   522,   527,
     535,   540,   548,   556,   564,   568,   572,   580,   587,   596,
     608,   614,   624,   628,   632,   640,   648,   656,   664,   670,
     680,   688,   700,   706,   716,   720,   724,   728,   732,   736,
     740,   748,   756,   765,   769,   778,   786,   794,   802,   807,
     819,   826,   836,   840,   844,   848,   856,   860,   864,   868,
     872,   880,   888,   900,   904,   908,   912,   916,   920,   925,
     929,   933,   937,   941,   945,   949,   953,   957,   961,   965,
     969,   973,   977,   981,   989,   993,  1001,  1006,  1011,  1015,
    1023,  1028,  1033,  1037,  1049,  1053,  1057,  1061,  1065,  1069,
    1073,  1077,  1081,  1085,  1089,  1097,  1103,  1113,  1121,  1125,
    1133,  1141,  1151,  1161,  1171,  1180,  1187,  1196,  1204,  1213,
    1220,  1229,  1235,  1243,  1251,  1260,  1266,  1276,  1280,  1284,
    1288,  1292,  1322,  1326,  1334,  1338,  1346,  1354,  1362,  1369,
    1383,  1390,  1400,  1408,  1414,  1422,  1426,  1435,  1449,  1453,
    1458,  1467,  1474,  1486,  1492,  1501,  1508,  1515,  1522,  1529
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


#line 48 "../../obj/src/GrammarParser.y"
} // libscod
#line 4500 "GrammarParser.cpp"

#line 1535 "../../obj/src/GrammarParser.y"


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
