// A Bison parser, made by GNU Bison 3.5.4.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file GrammarParser.tab.h
 ** Define the libscod::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.

#ifndef YY_YY_GRAMMARPARSER_TAB_H_INCLUDED
# define YY_YY_GRAMMARPARSER_TAB_H_INCLUDED
// "%code requires" blocks.
#line 61 "../../obj/src/GrammarParser.y"

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

#line 76 "GrammarParser.tab.h"

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif

#include <typeinfo>
#ifndef YY_ASSERT
# include <cassert>
# define YY_ASSERT assert
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

#line 48 "../../obj/src/GrammarParser.y"
namespace libscod {
#line 211 "GrammarParser.tab.h"




  /// A Bison parser.
  class Parser
  {
  public:
#ifndef YYSTYPE
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class semantic_type
  {
  public:
    /// Type of *this.
    typedef semantic_type self_type;

    /// Empty construction.
    semantic_type () YY_NOEXCEPT
      : yybuffer_ ()
      , yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    semantic_type (YY_RVREF (T) t)
      : yytypeid_ (&typeid (T))
    {
      YY_ASSERT (sizeof (T) <= size);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

    /// Destruction, allowed only if empty.
    ~semantic_type () YY_NOEXCEPT
    {
      YY_ASSERT (!yytypeid_);
    }

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == *that.yytypeid_);
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytypeid_ = YY_NULLPTR;
    }

  private:
    /// Prohibit blind copies.
    self_type& operator= (const self_type&);
    semantic_type (const self_type&);

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // AssignmentStatement
      char dummy1[sizeof (AssignmentStatement::Ptr)];

      // Attribute
      char dummy2[sizeof (Attribute::Ptr)];

      // Attributes
      char dummy3[sizeof (Attributes::Ptr)];

      // BasicAttribute
      char dummy4[sizeof (BasicAttribute::Ptr)];

      // BlockStatement
      char dummy5[sizeof (BlockStatement::Ptr)];

      // BufferDefinition
      char dummy6[sizeof (BufferDefinition::Ptr)];

      // "SCOD"
      // "memory"
      // "register"
      // "field"
      // "format"
      // "buffer"
      // "instruction"
      // "microprocessor"
      // "cache"
      // "interconnect"
      // "decoding"
      // "syntax"
      // "expansion"
      // "stage"
      // "enumeration"
      // "using"
      // "skip"
      // "abstract"
      // "let"
      // "in"
      // "if"
      // "then"
      // "else"
      // "false"
      // "true"
      // "not"
      // "and"
      // "or"
      // "xor"
      // "implies"
      // "=>"
      // "+"
      // "(+)"
      // "-"
      // "(-)"
      // "*"
      // "<<"
      // "(<<)"
      // ">>"
      // "(>>)"
      // "="
      // "!="
      // "<"
      // "<="
      // ">"
      // ">="
      // ":="
      // "->"
      // "'"
      // ":"
      // ";"
      // "::"
      // "("
      // ")"
      // "["
      // "]"
      // "{"
      // "}"
      // "@"
      // ","
      // "."
      // ".."
      char dummy7[sizeof (CST::Token::Ptr)];

      // CacheDefinition
      char dummy8[sizeof (CacheDefinition::Ptr)];

      // CallExpression
      char dummy9[sizeof (CallExpression::Ptr)];

      // CallStatement
      char dummy10[sizeof (CallStatement::Ptr)];

      // ConditionalExpression
      char dummy11[sizeof (ConditionalExpression::Ptr)];

      // ConditionalStatement
      char dummy12[sizeof (ConditionalStatement::Ptr)];

      // DecodingOption
      char dummy13[sizeof (DecodingOption::Ptr)];

      // AttributedDefinition
      // Definition
      char dummy14[sizeof (Definition::Ptr)];

      // Definitions
      char dummy15[sizeof (Definitions::Ptr)];

      // DirectCallExpression
      char dummy16[sizeof (DirectCallExpression::Ptr)];

      // EnumerationDefinition
      char dummy17[sizeof (EnumerationDefinition::Ptr)];

      // ExpansionOption
      char dummy18[sizeof (ExpansionOption::Ptr)];

      // Term
      // Expression
      // OperatorExpression
      // Terminal
      char dummy19[sizeof (Expression::Ptr)];

      // ExpressionAttribute
      char dummy20[sizeof (ExpressionAttribute::Ptr)];

      // Terms
      // Terminals
      char dummy21[sizeof (Expressions::Ptr)];

      // FieldDefinition
      char dummy22[sizeof (FieldDefinition::Ptr)];

      // FormatDefinition
      char dummy23[sizeof (FormatDefinition::Ptr)];

      // GrammarLiteral
      char dummy24[sizeof (GrammarLiteral::Ptr)];

      // Header
      char dummy25[sizeof (HeaderDefinition::Ptr)];

      // "identifier"
      // Identifier
      char dummy26[sizeof (Identifier::Ptr)];

      // IdentifierPath
      char dummy27[sizeof (IdentifierPath::Ptr)];

      // InstructionDefinition
      char dummy28[sizeof (InstructionDefinition::Ptr)];

      // InterconnectDefinition
      char dummy29[sizeof (InterconnectDefinition::Ptr)];

      // LetExpression
      char dummy30[sizeof (LetExpression::Ptr)];

      // LetStatement
      char dummy31[sizeof (LetStatement::Ptr)];

      // ListLiteral
      char dummy32[sizeof (ListLiteral::Ptr)];

      // Literal
      char dummy33[sizeof (Literal::Ptr)];

      // Mapping
      char dummy34[sizeof (MappedExpression::Ptr)];

      // Mappings
      char dummy35[sizeof (MappedExpressions::Ptr)];

      // FormatFields
      // MappingLiteral
      char dummy36[sizeof (MappingLiteral::Ptr)];

      // MappingType
      char dummy37[sizeof (MappingType::Ptr)];

      // MemoryDefinition
      char dummy38[sizeof (MemoryDefinition::Ptr)];

      // MethodCallExpression
      char dummy39[sizeof (MethodCallExpression::Ptr)];

      // MicroProcessorDefinition
      char dummy40[sizeof (MicroProcessorDefinition::Ptr)];

      // Assignment
      char dummy41[sizeof (NamedExpression::Ptr)];

      // Assignments
      char dummy42[sizeof (NamedExpressions::Ptr)];

      // InstructionOption
      // MicroProcessorOption
      char dummy43[sizeof (Option::Ptr)];

      // OptionDefinition
      char dummy44[sizeof (OptionDefinition::Ptr)];

      // InstructionOptions
      // MicroProcessorOptions
      char dummy45[sizeof (Options::Ptr)];

      // RangeLiteral
      char dummy46[sizeof (RangeLiteral::Ptr)];

      // RecordLiteral
      char dummy47[sizeof (RecordLiteral::Ptr)];

      // ReferenceLiteral
      char dummy48[sizeof (ReferenceLiteral::Ptr)];

      // RegisterDefinition
      char dummy49[sizeof (RegisterDefinition::Ptr)];

      // Enumerators
      // SetLiteral
      char dummy50[sizeof (SetLiteral::Ptr)];

      // SkipStatement
      // AbstractStatement
      char dummy51[sizeof (SkipStatement::Ptr)];

      // Specification
      char dummy52[sizeof (Specification::Ptr)];

      // StageOption
      char dummy53[sizeof (StageOption::Ptr)];

      // Statement
      char dummy54[sizeof (Statement::Ptr)];

      // Statements
      char dummy55[sizeof (Statements::Ptr)];

      // SyntaxOption
      char dummy56[sizeof (SyntaxOption::Ptr)];

      // ArgumentTypes
      char dummy57[sizeof (Types::Ptr)];

      // UsingDefinition
      char dummy58[sizeof (UsingDefinition::Ptr)];

      // "integer"
      // "binary"
      // "hexadecimal"
      // "string"
      // BooleanLiteral
      // IntegerLiteral
      // BinaryLiteral
      // StringLiteral
      char dummy59[sizeof (ValueLiteral::Ptr)];

      // VariableBinding
      char dummy60[sizeof (VariableBinding::Ptr)];

      // VariableBindings
      char dummy61[sizeof (VariableBindings::Ptr)];

      // AttributedVariable
      // Variable
      // TypedVariable
      char dummy62[sizeof (VariableDefinition::Ptr)];

      // Type
      // BasicType
      // PropertyType
      char dummy63[sizeof (libscod::CST::Type::Ptr)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[size];
    } yybuffer_;

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };

#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef libstdhl::SourceLocation location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Tokens.
    struct token
    {
      enum yytokentype
      {
        END = 0,
        SCOD = 258,
        MEMORY = 259,
        REGISTER = 260,
        FIELD = 261,
        FORMAT = 262,
        BUFFER = 263,
        INSTRUCTION = 264,
        MICROPROCESSOR = 265,
        CACHE = 266,
        INTERCONNECT = 267,
        DECODING = 268,
        SYNTAX = 269,
        EXPANSION = 270,
        STAGE = 271,
        ENUMERATION = 272,
        USING = 273,
        SKIP = 274,
        ABSTRACT = 275,
        LET = 276,
        IN = 277,
        IF = 278,
        THEN = 279,
        ELSE = 280,
        FALSE = 281,
        TRUE = 282,
        NOT = 283,
        AND = 284,
        OR = 285,
        XOR = 286,
        IMPLIES = 287,
        ARROW = 288,
        PLUS = 289,
        CARRYPLUS = 290,
        MINUS = 291,
        CARRYMINUS = 292,
        ASTERIX = 293,
        LSHIFT = 294,
        RLSHIFT = 295,
        RSHIFT = 296,
        RRSHIFT = 297,
        EQUAL = 298,
        NEQUAL = 299,
        LESSER = 300,
        LESSEQ = 301,
        GREATER = 302,
        GREATEREQ = 303,
        ASSIGNMENT = 304,
        MAPS = 305,
        MARK = 306,
        COLON = 307,
        SEMICOLON = 308,
        NAMESPACE = 309,
        LPAREN = 310,
        RPAREN = 311,
        LSQPAREN = 312,
        RSQPAREN = 313,
        LCURPAREN = 314,
        RCURPAREN = 315,
        AT = 316,
        COMMA = 317,
        DOT = 318,
        DOTDOT = 319,
        INTEGER = 320,
        BINARY = 321,
        HEXADECIMAL = 322,
        STRING = 323,
        IDENTIFIER = 324
      };
    };

    /// (External) token type, as returned by yylex.
    typedef token::yytokentype token_type;

    /// Symbol type: an internal symbol number.
    typedef int symbol_number_type;

    /// The symbol type number to denote an empty symbol.
    enum { empty_symbol = -2 };

    /// Internal symbol number for tokens (subsumed by symbol_number_type).
    typedef signed char token_number_type;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol type
    /// via type_get ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ()
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that);
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AssignmentStatement::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AssignmentStatement::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Attribute::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Attribute::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Attributes::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Attributes::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, BasicAttribute::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const BasicAttribute::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, BlockStatement::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const BlockStatement::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, BufferDefinition::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const BufferDefinition::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, CST::Token::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const CST::Token::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, CacheDefinition::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const CacheDefinition::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, CallExpression::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const CallExpression::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, CallStatement::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const CallStatement::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ConditionalExpression::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ConditionalExpression::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ConditionalStatement::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ConditionalStatement::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, DecodingOption::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const DecodingOption::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Definition::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Definition::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Definitions::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Definitions::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, DirectCallExpression::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const DirectCallExpression::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, EnumerationDefinition::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const EnumerationDefinition::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ExpansionOption::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ExpansionOption::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Expression::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Expression::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ExpressionAttribute::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ExpressionAttribute::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Expressions::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Expressions::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, FieldDefinition::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const FieldDefinition::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, FormatDefinition::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const FormatDefinition::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, GrammarLiteral::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const GrammarLiteral::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, HeaderDefinition::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const HeaderDefinition::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Identifier::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Identifier::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, IdentifierPath::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const IdentifierPath::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, InstructionDefinition::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const InstructionDefinition::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, InterconnectDefinition::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const InterconnectDefinition::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, LetExpression::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const LetExpression::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, LetStatement::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const LetStatement::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ListLiteral::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ListLiteral::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Literal::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Literal::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, MappedExpression::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const MappedExpression::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, MappedExpressions::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const MappedExpressions::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, MappingLiteral::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const MappingLiteral::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, MappingType::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const MappingType::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, MemoryDefinition::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const MemoryDefinition::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, MethodCallExpression::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const MethodCallExpression::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, MicroProcessorDefinition::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const MicroProcessorDefinition::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, NamedExpression::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const NamedExpression::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, NamedExpressions::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const NamedExpressions::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Option::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Option::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, OptionDefinition::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const OptionDefinition::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Options::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Options::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, RangeLiteral::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const RangeLiteral::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, RecordLiteral::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const RecordLiteral::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ReferenceLiteral::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ReferenceLiteral::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, RegisterDefinition::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const RegisterDefinition::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, SetLiteral::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const SetLiteral::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, SkipStatement::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const SkipStatement::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Specification::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Specification::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, StageOption::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const StageOption::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Statement::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Statement::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Statements::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Statements::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, SyntaxOption::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const SyntaxOption::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Types::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Types::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, UsingDefinition::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const UsingDefinition::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ValueLiteral::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ValueLiteral::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, VariableBinding::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const VariableBinding::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, VariableBindings::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const VariableBindings::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, VariableDefinition::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const VariableDefinition::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, libscod::CST::Type::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const libscod::CST::Type::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }

      /// Destroy contents, and record that is empty.
      void clear ()
      {
        // User destructor.
        symbol_number_type yytype = this->type_get ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yytype)
        {
       default:
          break;
        }

        // Type destructor.
switch (yytype)
    {
      case 105: // AssignmentStatement
        value.template destroy< AssignmentStatement::Ptr > ();
        break;

      case 147: // Attribute
        value.template destroy< Attribute::Ptr > ();
        break;

      case 146: // Attributes
        value.template destroy< Attributes::Ptr > ();
        break;

      case 148: // BasicAttribute
        value.template destroy< BasicAttribute::Ptr > ();
        break;

      case 102: // BlockStatement
        value.template destroy< BlockStatement::Ptr > ();
        break;

      case 81: // BufferDefinition
        value.template destroy< BufferDefinition::Ptr > ();
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
        value.template destroy< CST::Token::Ptr > ();
        break;

      case 84: // CacheDefinition
        value.template destroy< CacheDefinition::Ptr > ();
        break;

      case 113: // CallExpression
        value.template destroy< CallExpression::Ptr > ();
        break;

      case 103: // CallStatement
        value.template destroy< CallStatement::Ptr > ();
        break;

      case 111: // ConditionalExpression
        value.template destroy< ConditionalExpression::Ptr > ();
        break;

      case 106: // ConditionalStatement
        value.template destroy< ConditionalStatement::Ptr > ();
        break;

      case 92: // DecodingOption
        value.template destroy< DecodingOption::Ptr > ();
        break;

      case 74: // AttributedDefinition
      case 75: // Definition
        value.template destroy< Definition::Ptr > ();
        break;

      case 73: // Definitions
        value.template destroy< Definitions::Ptr > ();
        break;

      case 114: // DirectCallExpression
        value.template destroy< DirectCallExpression::Ptr > ();
        break;

      case 87: // EnumerationDefinition
        value.template destroy< EnumerationDefinition::Ptr > ();
        break;

      case 94: // ExpansionOption
        value.template destroy< ExpansionOption::Ptr > ();
        break;

      case 108: // Term
      case 109: // Expression
      case 112: // OperatorExpression
      case 133: // Terminal
        value.template destroy< Expression::Ptr > ();
        break;

      case 149: // ExpressionAttribute
        value.template destroy< ExpressionAttribute::Ptr > ();
        break;

      case 107: // Terms
      case 132: // Terminals
        value.template destroy< Expressions::Ptr > ();
        break;

      case 78: // FieldDefinition
        value.template destroy< FieldDefinition::Ptr > ();
        break;

      case 79: // FormatDefinition
        value.template destroy< FormatDefinition::Ptr > ();
        break;

      case 131: // GrammarLiteral
        value.template destroy< GrammarLiteral::Ptr > ();
        break;

      case 72: // Header
        value.template destroy< HeaderDefinition::Ptr > ();
        break;

      case 69: // "identifier"
      case 144: // Identifier
        value.template destroy< Identifier::Ptr > ();
        break;

      case 145: // IdentifierPath
        value.template destroy< IdentifierPath::Ptr > ();
        break;

      case 82: // InstructionDefinition
        value.template destroy< InstructionDefinition::Ptr > ();
        break;

      case 85: // InterconnectDefinition
        value.template destroy< InterconnectDefinition::Ptr > ();
        break;

      case 110: // LetExpression
        value.template destroy< LetExpression::Ptr > ();
        break;

      case 104: // LetStatement
        value.template destroy< LetStatement::Ptr > ();
        break;

      case 122: // ListLiteral
        value.template destroy< ListLiteral::Ptr > ();
        break;

      case 116: // Literal
        value.template destroy< Literal::Ptr > ();
        break;

      case 129: // Mapping
        value.template destroy< MappedExpression::Ptr > ();
        break;

      case 128: // Mappings
        value.template destroy< MappedExpressions::Ptr > ();
        break;

      case 80: // FormatFields
      case 127: // MappingLiteral
        value.template destroy< MappingLiteral::Ptr > ();
        break;

      case 137: // MappingType
        value.template destroy< MappingType::Ptr > ();
        break;

      case 76: // MemoryDefinition
        value.template destroy< MemoryDefinition::Ptr > ();
        break;

      case 115: // MethodCallExpression
        value.template destroy< MethodCallExpression::Ptr > ();
        break;

      case 83: // MicroProcessorDefinition
        value.template destroy< MicroProcessorDefinition::Ptr > ();
        break;

      case 126: // Assignment
        value.template destroy< NamedExpression::Ptr > ();
        break;

      case 125: // Assignments
        value.template destroy< NamedExpressions::Ptr > ();
        break;

      case 91: // InstructionOption
      case 96: // MicroProcessorOption
        value.template destroy< Option::Ptr > ();
        break;

      case 86: // OptionDefinition
        value.template destroy< OptionDefinition::Ptr > ();
        break;

      case 90: // InstructionOptions
      case 95: // MicroProcessorOptions
        value.template destroy< Options::Ptr > ();
        break;

      case 123: // RangeLiteral
        value.template destroy< RangeLiteral::Ptr > ();
        break;

      case 124: // RecordLiteral
        value.template destroy< RecordLiteral::Ptr > ();
        break;

      case 130: // ReferenceLiteral
        value.template destroy< ReferenceLiteral::Ptr > ();
        break;

      case 77: // RegisterDefinition
        value.template destroy< RegisterDefinition::Ptr > ();
        break;

      case 88: // Enumerators
      case 121: // SetLiteral
        value.template destroy< SetLiteral::Ptr > ();
        break;

      case 100: // SkipStatement
      case 101: // AbstractStatement
        value.template destroy< SkipStatement::Ptr > ();
        break;

      case 71: // Specification
        value.template destroy< Specification::Ptr > ();
        break;

      case 97: // StageOption
        value.template destroy< StageOption::Ptr > ();
        break;

      case 99: // Statement
        value.template destroy< Statement::Ptr > ();
        break;

      case 98: // Statements
        value.template destroy< Statements::Ptr > ();
        break;

      case 93: // SyntaxOption
        value.template destroy< SyntaxOption::Ptr > ();
        break;

      case 138: // ArgumentTypes
        value.template destroy< Types::Ptr > ();
        break;

      case 89: // UsingDefinition
        value.template destroy< UsingDefinition::Ptr > ();
        break;

      case 65: // "integer"
      case 66: // "binary"
      case 67: // "hexadecimal"
      case 68: // "string"
      case 117: // BooleanLiteral
      case 118: // IntegerLiteral
      case 119: // BinaryLiteral
      case 120: // StringLiteral
        value.template destroy< ValueLiteral::Ptr > ();
        break;

      case 140: // VariableBinding
        value.template destroy< VariableBinding::Ptr > ();
        break;

      case 139: // VariableBindings
        value.template destroy< VariableBindings::Ptr > ();
        break;

      case 141: // AttributedVariable
      case 142: // Variable
      case 143: // TypedVariable
        value.template destroy< VariableDefinition::Ptr > ();
        break;

      case 134: // Type
      case 135: // BasicType
      case 136: // PropertyType
        value.template destroy< libscod::CST::Type::Ptr > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_type
    {
      /// Default constructor.
      by_type ();

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_type (by_type&& that);
#endif

      /// Copy constructor.
      by_type (const by_type& that);

      /// The symbol type as needed by the constructor.
      typedef token_type kind_type;

      /// Constructor from (external) token numbers.
      by_type (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_type& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_number_type type_get () const YY_NOEXCEPT;

      /// The symbol type.
      /// \a empty_symbol when empty.
      /// An int, not token_number_type, to be able to store empty_symbol.
      int type;
    };

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_type>
    {
      /// Superclass.
      typedef basic_symbol<by_type> super_type;

      /// Empty symbol.
      symbol_type () {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type(token_type (tok), std::move (l))
      {
        YY_ASSERT (tok == token::END);
      }
#else
      symbol_type (int tok, const location_type& l)
        : super_type(token_type (tok), l)
      {
        YY_ASSERT (tok == token::END);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, CST::Token::Ptr v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YY_ASSERT (tok == token::SCOD || tok == token::MEMORY || tok == token::REGISTER || tok == token::FIELD || tok == token::FORMAT || tok == token::BUFFER || tok == token::INSTRUCTION || tok == token::MICROPROCESSOR || tok == token::CACHE || tok == token::INTERCONNECT || tok == token::DECODING || tok == token::SYNTAX || tok == token::EXPANSION || tok == token::STAGE || tok == token::ENUMERATION || tok == token::USING || tok == token::SKIP || tok == token::ABSTRACT || tok == token::LET || tok == token::IN || tok == token::IF || tok == token::THEN || tok == token::ELSE || tok == token::FALSE || tok == token::TRUE || tok == token::NOT || tok == token::AND || tok == token::OR || tok == token::XOR || tok == token::IMPLIES || tok == token::ARROW || tok == token::PLUS || tok == token::CARRYPLUS || tok == token::MINUS || tok == token::CARRYMINUS || tok == token::ASTERIX || tok == token::LSHIFT || tok == token::RLSHIFT || tok == token::RSHIFT || tok == token::RRSHIFT || tok == token::EQUAL || tok == token::NEQUAL || tok == token::LESSER || tok == token::LESSEQ || tok == token::GREATER || tok == token::GREATEREQ || tok == token::ASSIGNMENT || tok == token::MAPS || tok == token::MARK || tok == token::COLON || tok == token::SEMICOLON || tok == token::NAMESPACE || tok == token::LPAREN || tok == token::RPAREN || tok == token::LSQPAREN || tok == token::RSQPAREN || tok == token::LCURPAREN || tok == token::RCURPAREN || tok == token::AT || tok == token::COMMA || tok == token::DOT || tok == token::DOTDOT);
      }
#else
      symbol_type (int tok, const CST::Token::Ptr& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YY_ASSERT (tok == token::SCOD || tok == token::MEMORY || tok == token::REGISTER || tok == token::FIELD || tok == token::FORMAT || tok == token::BUFFER || tok == token::INSTRUCTION || tok == token::MICROPROCESSOR || tok == token::CACHE || tok == token::INTERCONNECT || tok == token::DECODING || tok == token::SYNTAX || tok == token::EXPANSION || tok == token::STAGE || tok == token::ENUMERATION || tok == token::USING || tok == token::SKIP || tok == token::ABSTRACT || tok == token::LET || tok == token::IN || tok == token::IF || tok == token::THEN || tok == token::ELSE || tok == token::FALSE || tok == token::TRUE || tok == token::NOT || tok == token::AND || tok == token::OR || tok == token::XOR || tok == token::IMPLIES || tok == token::ARROW || tok == token::PLUS || tok == token::CARRYPLUS || tok == token::MINUS || tok == token::CARRYMINUS || tok == token::ASTERIX || tok == token::LSHIFT || tok == token::RLSHIFT || tok == token::RSHIFT || tok == token::RRSHIFT || tok == token::EQUAL || tok == token::NEQUAL || tok == token::LESSER || tok == token::LESSEQ || tok == token::GREATER || tok == token::GREATEREQ || tok == token::ASSIGNMENT || tok == token::MAPS || tok == token::MARK || tok == token::COLON || tok == token::SEMICOLON || tok == token::NAMESPACE || tok == token::LPAREN || tok == token::RPAREN || tok == token::LSQPAREN || tok == token::RSQPAREN || tok == token::LCURPAREN || tok == token::RCURPAREN || tok == token::AT || tok == token::COMMA || tok == token::DOT || tok == token::DOTDOT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, Identifier::Ptr v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YY_ASSERT (tok == token::IDENTIFIER);
      }
#else
      symbol_type (int tok, const Identifier::Ptr& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YY_ASSERT (tok == token::IDENTIFIER);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, ValueLiteral::Ptr v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YY_ASSERT (tok == token::INTEGER || tok == token::BINARY || tok == token::HEXADECIMAL || tok == token::STRING);
      }
#else
      symbol_type (int tok, const ValueLiteral::Ptr& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YY_ASSERT (tok == token::INTEGER || tok == token::BINARY || tok == token::HEXADECIMAL || tok == token::STRING);
      }
#endif
    };

    /// Build a parser object.
    Parser (Logger& m_log_yyarg, Lexer& m_lexer_yyarg, Specification& m_specification_yyarg);
    virtual ~Parser ();

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    // Implementation of make_symbol for each symbol type.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_END (location_type l)
      {
        return symbol_type (token::END, std::move (l));
      }
#else
      static
      symbol_type
      make_END (const location_type& l)
      {
        return symbol_type (token::END, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SCOD (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::SCOD, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_SCOD (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::SCOD, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MEMORY (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::MEMORY, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MEMORY (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::MEMORY, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REGISTER (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::REGISTER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_REGISTER (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::REGISTER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FIELD (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::FIELD, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FIELD (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::FIELD, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FORMAT (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::FORMAT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FORMAT (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::FORMAT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BUFFER (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::BUFFER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_BUFFER (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::BUFFER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INSTRUCTION (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::INSTRUCTION, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_INSTRUCTION (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::INSTRUCTION, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MICROPROCESSOR (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::MICROPROCESSOR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MICROPROCESSOR (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::MICROPROCESSOR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CACHE (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::CACHE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CACHE (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::CACHE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INTERCONNECT (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::INTERCONNECT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_INTERCONNECT (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::INTERCONNECT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DECODING (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::DECODING, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DECODING (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::DECODING, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SYNTAX (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::SYNTAX, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_SYNTAX (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::SYNTAX, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXPANSION (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::EXPANSION, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_EXPANSION (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::EXPANSION, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STAGE (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::STAGE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_STAGE (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::STAGE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ENUMERATION (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::ENUMERATION, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ENUMERATION (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::ENUMERATION, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_USING (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::USING, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_USING (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::USING, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SKIP (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::SKIP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_SKIP (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::SKIP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ABSTRACT (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::ABSTRACT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ABSTRACT (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::ABSTRACT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LET (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::LET, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LET (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::LET, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IN (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::IN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_IN (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::IN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IF (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::IF, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_IF (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::IF, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_THEN (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::THEN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_THEN (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::THEN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELSE (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::ELSE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ELSE (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::ELSE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FALSE (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::FALSE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FALSE (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::FALSE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TRUE (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::TRUE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TRUE (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::TRUE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NOT (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::NOT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NOT (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::NOT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AND (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::AND, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_AND (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::AND, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OR (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::OR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_OR (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::OR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_XOR (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::XOR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_XOR (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::XOR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IMPLIES (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::IMPLIES, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_IMPLIES (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::IMPLIES, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ARROW (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::ARROW, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ARROW (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::ARROW, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PLUS (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::PLUS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_PLUS (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::PLUS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CARRYPLUS (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::CARRYPLUS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CARRYPLUS (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::CARRYPLUS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MINUS (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::MINUS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MINUS (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::MINUS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CARRYMINUS (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::CARRYMINUS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CARRYMINUS (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::CARRYMINUS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASTERIX (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::ASTERIX, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ASTERIX (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::ASTERIX, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LSHIFT (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::LSHIFT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LSHIFT (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::LSHIFT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RLSHIFT (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::RLSHIFT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RLSHIFT (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::RLSHIFT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RSHIFT (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::RSHIFT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RSHIFT (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::RSHIFT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RRSHIFT (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::RRSHIFT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RRSHIFT (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::RRSHIFT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQUAL (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::EQUAL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_EQUAL (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::EQUAL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NEQUAL (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::NEQUAL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NEQUAL (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::NEQUAL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LESSER (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::LESSER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LESSER (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::LESSER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LESSEQ (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::LESSEQ, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LESSEQ (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::LESSEQ, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GREATER (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::GREATER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_GREATER (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::GREATER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GREATEREQ (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::GREATEREQ, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_GREATEREQ (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::GREATEREQ, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASSIGNMENT (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::ASSIGNMENT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ASSIGNMENT (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::ASSIGNMENT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAPS (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::MAPS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MAPS (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::MAPS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MARK (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::MARK, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MARK (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::MARK, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COLON (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::COLON, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_COLON (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::COLON, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SEMICOLON (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::SEMICOLON, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_SEMICOLON (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::SEMICOLON, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NAMESPACE (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::NAMESPACE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NAMESPACE (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::NAMESPACE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LPAREN (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::LPAREN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LPAREN (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::LPAREN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RPAREN (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::RPAREN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RPAREN (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::RPAREN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LSQPAREN (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::LSQPAREN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LSQPAREN (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::LSQPAREN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RSQPAREN (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::RSQPAREN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RSQPAREN (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::RSQPAREN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LCURPAREN (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::LCURPAREN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LCURPAREN (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::LCURPAREN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RCURPAREN (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::RCURPAREN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RCURPAREN (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::RCURPAREN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AT (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::AT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_AT (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::AT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMA (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::COMMA, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_COMMA (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::COMMA, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOT (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::DOT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DOT (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::DOT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOTDOT (CST::Token::Ptr v, location_type l)
      {
        return symbol_type (token::DOTDOT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DOTDOT (const CST::Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::DOTDOT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INTEGER (ValueLiteral::Ptr v, location_type l)
      {
        return symbol_type (token::INTEGER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_INTEGER (const ValueLiteral::Ptr& v, const location_type& l)
      {
        return symbol_type (token::INTEGER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BINARY (ValueLiteral::Ptr v, location_type l)
      {
        return symbol_type (token::BINARY, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_BINARY (const ValueLiteral::Ptr& v, const location_type& l)
      {
        return symbol_type (token::BINARY, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_HEXADECIMAL (ValueLiteral::Ptr v, location_type l)
      {
        return symbol_type (token::HEXADECIMAL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_HEXADECIMAL (const ValueLiteral::Ptr& v, const location_type& l)
      {
        return symbol_type (token::HEXADECIMAL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRING (ValueLiteral::Ptr v, location_type l)
      {
        return symbol_type (token::STRING, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_STRING (const ValueLiteral::Ptr& v, const location_type& l)
      {
        return symbol_type (token::STRING, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IDENTIFIER (Identifier::Ptr v, location_type l)
      {
        return symbol_type (token::IDENTIFIER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_IDENTIFIER (const Identifier::Ptr& v, const location_type& l)
      {
        return symbol_type (token::IDENTIFIER, v, l);
      }
#endif


  private:
    /// This class is not copyable.
    Parser (const Parser&);
    Parser& operator= (const Parser&);

    /// Stored state numbers (used for stacks).
    typedef short state_type;

    /// Generate an error message.
    /// \param yystate   the state where the error occurred.
    /// \param yyla      the lookahead token.
    virtual std::string yysyntax_error_ (state_type yystate,
                                         const symbol_type& yyla) const;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const short yypact_ninf_;
    static const short yytable_ninf_;

    /// Convert a scanner token number \a t to a symbol number.
    /// In theory \a t should be a token_type, but character literals
    /// are valid, yet not members of the token_type enum.
    static token_number_type yytranslate_ (int t);

    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const unsigned char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const short yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const short yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const short yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    // symbol of state STATE-NUM.
    static const unsigned char yystos_[];

    // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
    static const unsigned char yyr1_[];

    // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
    static const signed char yyr2_[];


    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *n);


    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol type, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol type as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol type from \a that.
      void move (by_state& that);

      /// The (internal) type number (corresponding to \a state).
      /// \a empty_symbol when empty.
      symbol_number_type type_get () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::reverse_iterator iterator;
      typedef typename S::const_reverse_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200)
        : seq_ (n)
      {}

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      std::ptrdiff_t
      ssize () const YY_NOEXCEPT
      {
        return std::ptrdiff_t (size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.rbegin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.rend ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range)
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
      stack (const stack&);
      stack& operator= (const stack&);
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1);

    /// Some specific tokens.
    static const token_number_type yy_error_token_ = 1;
    static const token_number_type yy_undef_token_ = 2;

    /// Constants.
    enum
    {
      yyeof_ = 0,
      yylast_ = 763,     ///< Last index in yytable_.
      yynnts_ = 80,  ///< Number of nonterminal symbols.
      yyfinal_ = 14, ///< Termination state number.
      yyntokens_ = 70  ///< Number of tokens.
    };


    // User arguments.
    Logger& m_log;
    Lexer& m_lexer;
    Specification& m_specification;
  };

  inline
  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const token_number_type
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69
    };
    const int user_token_number_max_ = 324;

    if (t <= 0)
      return yyeof_;
    else if (t <= user_token_number_max_)
      return translate_table[t];
    else
      return yy_undef_token_;
  }

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value ()
    , location (std::move (that.location))
  {
    switch (this->type_get ())
    {
      case 105: // AssignmentStatement
        value.move< AssignmentStatement::Ptr > (std::move (that.value));
        break;

      case 147: // Attribute
        value.move< Attribute::Ptr > (std::move (that.value));
        break;

      case 146: // Attributes
        value.move< Attributes::Ptr > (std::move (that.value));
        break;

      case 148: // BasicAttribute
        value.move< BasicAttribute::Ptr > (std::move (that.value));
        break;

      case 102: // BlockStatement
        value.move< BlockStatement::Ptr > (std::move (that.value));
        break;

      case 81: // BufferDefinition
        value.move< BufferDefinition::Ptr > (std::move (that.value));
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
        value.move< CST::Token::Ptr > (std::move (that.value));
        break;

      case 84: // CacheDefinition
        value.move< CacheDefinition::Ptr > (std::move (that.value));
        break;

      case 113: // CallExpression
        value.move< CallExpression::Ptr > (std::move (that.value));
        break;

      case 103: // CallStatement
        value.move< CallStatement::Ptr > (std::move (that.value));
        break;

      case 111: // ConditionalExpression
        value.move< ConditionalExpression::Ptr > (std::move (that.value));
        break;

      case 106: // ConditionalStatement
        value.move< ConditionalStatement::Ptr > (std::move (that.value));
        break;

      case 92: // DecodingOption
        value.move< DecodingOption::Ptr > (std::move (that.value));
        break;

      case 74: // AttributedDefinition
      case 75: // Definition
        value.move< Definition::Ptr > (std::move (that.value));
        break;

      case 73: // Definitions
        value.move< Definitions::Ptr > (std::move (that.value));
        break;

      case 114: // DirectCallExpression
        value.move< DirectCallExpression::Ptr > (std::move (that.value));
        break;

      case 87: // EnumerationDefinition
        value.move< EnumerationDefinition::Ptr > (std::move (that.value));
        break;

      case 94: // ExpansionOption
        value.move< ExpansionOption::Ptr > (std::move (that.value));
        break;

      case 108: // Term
      case 109: // Expression
      case 112: // OperatorExpression
      case 133: // Terminal
        value.move< Expression::Ptr > (std::move (that.value));
        break;

      case 149: // ExpressionAttribute
        value.move< ExpressionAttribute::Ptr > (std::move (that.value));
        break;

      case 107: // Terms
      case 132: // Terminals
        value.move< Expressions::Ptr > (std::move (that.value));
        break;

      case 78: // FieldDefinition
        value.move< FieldDefinition::Ptr > (std::move (that.value));
        break;

      case 79: // FormatDefinition
        value.move< FormatDefinition::Ptr > (std::move (that.value));
        break;

      case 131: // GrammarLiteral
        value.move< GrammarLiteral::Ptr > (std::move (that.value));
        break;

      case 72: // Header
        value.move< HeaderDefinition::Ptr > (std::move (that.value));
        break;

      case 69: // "identifier"
      case 144: // Identifier
        value.move< Identifier::Ptr > (std::move (that.value));
        break;

      case 145: // IdentifierPath
        value.move< IdentifierPath::Ptr > (std::move (that.value));
        break;

      case 82: // InstructionDefinition
        value.move< InstructionDefinition::Ptr > (std::move (that.value));
        break;

      case 85: // InterconnectDefinition
        value.move< InterconnectDefinition::Ptr > (std::move (that.value));
        break;

      case 110: // LetExpression
        value.move< LetExpression::Ptr > (std::move (that.value));
        break;

      case 104: // LetStatement
        value.move< LetStatement::Ptr > (std::move (that.value));
        break;

      case 122: // ListLiteral
        value.move< ListLiteral::Ptr > (std::move (that.value));
        break;

      case 116: // Literal
        value.move< Literal::Ptr > (std::move (that.value));
        break;

      case 129: // Mapping
        value.move< MappedExpression::Ptr > (std::move (that.value));
        break;

      case 128: // Mappings
        value.move< MappedExpressions::Ptr > (std::move (that.value));
        break;

      case 80: // FormatFields
      case 127: // MappingLiteral
        value.move< MappingLiteral::Ptr > (std::move (that.value));
        break;

      case 137: // MappingType
        value.move< MappingType::Ptr > (std::move (that.value));
        break;

      case 76: // MemoryDefinition
        value.move< MemoryDefinition::Ptr > (std::move (that.value));
        break;

      case 115: // MethodCallExpression
        value.move< MethodCallExpression::Ptr > (std::move (that.value));
        break;

      case 83: // MicroProcessorDefinition
        value.move< MicroProcessorDefinition::Ptr > (std::move (that.value));
        break;

      case 126: // Assignment
        value.move< NamedExpression::Ptr > (std::move (that.value));
        break;

      case 125: // Assignments
        value.move< NamedExpressions::Ptr > (std::move (that.value));
        break;

      case 91: // InstructionOption
      case 96: // MicroProcessorOption
        value.move< Option::Ptr > (std::move (that.value));
        break;

      case 86: // OptionDefinition
        value.move< OptionDefinition::Ptr > (std::move (that.value));
        break;

      case 90: // InstructionOptions
      case 95: // MicroProcessorOptions
        value.move< Options::Ptr > (std::move (that.value));
        break;

      case 123: // RangeLiteral
        value.move< RangeLiteral::Ptr > (std::move (that.value));
        break;

      case 124: // RecordLiteral
        value.move< RecordLiteral::Ptr > (std::move (that.value));
        break;

      case 130: // ReferenceLiteral
        value.move< ReferenceLiteral::Ptr > (std::move (that.value));
        break;

      case 77: // RegisterDefinition
        value.move< RegisterDefinition::Ptr > (std::move (that.value));
        break;

      case 88: // Enumerators
      case 121: // SetLiteral
        value.move< SetLiteral::Ptr > (std::move (that.value));
        break;

      case 100: // SkipStatement
      case 101: // AbstractStatement
        value.move< SkipStatement::Ptr > (std::move (that.value));
        break;

      case 71: // Specification
        value.move< Specification::Ptr > (std::move (that.value));
        break;

      case 97: // StageOption
        value.move< StageOption::Ptr > (std::move (that.value));
        break;

      case 99: // Statement
        value.move< Statement::Ptr > (std::move (that.value));
        break;

      case 98: // Statements
        value.move< Statements::Ptr > (std::move (that.value));
        break;

      case 93: // SyntaxOption
        value.move< SyntaxOption::Ptr > (std::move (that.value));
        break;

      case 138: // ArgumentTypes
        value.move< Types::Ptr > (std::move (that.value));
        break;

      case 89: // UsingDefinition
        value.move< UsingDefinition::Ptr > (std::move (that.value));
        break;

      case 65: // "integer"
      case 66: // "binary"
      case 67: // "hexadecimal"
      case 68: // "string"
      case 117: // BooleanLiteral
      case 118: // IntegerLiteral
      case 119: // BinaryLiteral
      case 120: // StringLiteral
        value.move< ValueLiteral::Ptr > (std::move (that.value));
        break;

      case 140: // VariableBinding
        value.move< VariableBinding::Ptr > (std::move (that.value));
        break;

      case 139: // VariableBindings
        value.move< VariableBindings::Ptr > (std::move (that.value));
        break;

      case 141: // AttributedVariable
      case 142: // Variable
      case 143: // TypedVariable
        value.move< VariableDefinition::Ptr > (std::move (that.value));
        break;

      case 134: // Type
      case 135: // BasicType
      case 136: // PropertyType
        value.move< libscod::CST::Type::Ptr > (std::move (that.value));
        break;

      default:
        break;
    }

  }
#endif

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->type_get ())
    {
      case 105: // AssignmentStatement
        value.copy< AssignmentStatement::Ptr > (YY_MOVE (that.value));
        break;

      case 147: // Attribute
        value.copy< Attribute::Ptr > (YY_MOVE (that.value));
        break;

      case 146: // Attributes
        value.copy< Attributes::Ptr > (YY_MOVE (that.value));
        break;

      case 148: // BasicAttribute
        value.copy< BasicAttribute::Ptr > (YY_MOVE (that.value));
        break;

      case 102: // BlockStatement
        value.copy< BlockStatement::Ptr > (YY_MOVE (that.value));
        break;

      case 81: // BufferDefinition
        value.copy< BufferDefinition::Ptr > (YY_MOVE (that.value));
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
        value.copy< CST::Token::Ptr > (YY_MOVE (that.value));
        break;

      case 84: // CacheDefinition
        value.copy< CacheDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 113: // CallExpression
        value.copy< CallExpression::Ptr > (YY_MOVE (that.value));
        break;

      case 103: // CallStatement
        value.copy< CallStatement::Ptr > (YY_MOVE (that.value));
        break;

      case 111: // ConditionalExpression
        value.copy< ConditionalExpression::Ptr > (YY_MOVE (that.value));
        break;

      case 106: // ConditionalStatement
        value.copy< ConditionalStatement::Ptr > (YY_MOVE (that.value));
        break;

      case 92: // DecodingOption
        value.copy< DecodingOption::Ptr > (YY_MOVE (that.value));
        break;

      case 74: // AttributedDefinition
      case 75: // Definition
        value.copy< Definition::Ptr > (YY_MOVE (that.value));
        break;

      case 73: // Definitions
        value.copy< Definitions::Ptr > (YY_MOVE (that.value));
        break;

      case 114: // DirectCallExpression
        value.copy< DirectCallExpression::Ptr > (YY_MOVE (that.value));
        break;

      case 87: // EnumerationDefinition
        value.copy< EnumerationDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 94: // ExpansionOption
        value.copy< ExpansionOption::Ptr > (YY_MOVE (that.value));
        break;

      case 108: // Term
      case 109: // Expression
      case 112: // OperatorExpression
      case 133: // Terminal
        value.copy< Expression::Ptr > (YY_MOVE (that.value));
        break;

      case 149: // ExpressionAttribute
        value.copy< ExpressionAttribute::Ptr > (YY_MOVE (that.value));
        break;

      case 107: // Terms
      case 132: // Terminals
        value.copy< Expressions::Ptr > (YY_MOVE (that.value));
        break;

      case 78: // FieldDefinition
        value.copy< FieldDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 79: // FormatDefinition
        value.copy< FormatDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 131: // GrammarLiteral
        value.copy< GrammarLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 72: // Header
        value.copy< HeaderDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 69: // "identifier"
      case 144: // Identifier
        value.copy< Identifier::Ptr > (YY_MOVE (that.value));
        break;

      case 145: // IdentifierPath
        value.copy< IdentifierPath::Ptr > (YY_MOVE (that.value));
        break;

      case 82: // InstructionDefinition
        value.copy< InstructionDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 85: // InterconnectDefinition
        value.copy< InterconnectDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 110: // LetExpression
        value.copy< LetExpression::Ptr > (YY_MOVE (that.value));
        break;

      case 104: // LetStatement
        value.copy< LetStatement::Ptr > (YY_MOVE (that.value));
        break;

      case 122: // ListLiteral
        value.copy< ListLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 116: // Literal
        value.copy< Literal::Ptr > (YY_MOVE (that.value));
        break;

      case 129: // Mapping
        value.copy< MappedExpression::Ptr > (YY_MOVE (that.value));
        break;

      case 128: // Mappings
        value.copy< MappedExpressions::Ptr > (YY_MOVE (that.value));
        break;

      case 80: // FormatFields
      case 127: // MappingLiteral
        value.copy< MappingLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 137: // MappingType
        value.copy< MappingType::Ptr > (YY_MOVE (that.value));
        break;

      case 76: // MemoryDefinition
        value.copy< MemoryDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 115: // MethodCallExpression
        value.copy< MethodCallExpression::Ptr > (YY_MOVE (that.value));
        break;

      case 83: // MicroProcessorDefinition
        value.copy< MicroProcessorDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 126: // Assignment
        value.copy< NamedExpression::Ptr > (YY_MOVE (that.value));
        break;

      case 125: // Assignments
        value.copy< NamedExpressions::Ptr > (YY_MOVE (that.value));
        break;

      case 91: // InstructionOption
      case 96: // MicroProcessorOption
        value.copy< Option::Ptr > (YY_MOVE (that.value));
        break;

      case 86: // OptionDefinition
        value.copy< OptionDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 90: // InstructionOptions
      case 95: // MicroProcessorOptions
        value.copy< Options::Ptr > (YY_MOVE (that.value));
        break;

      case 123: // RangeLiteral
        value.copy< RangeLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 124: // RecordLiteral
        value.copy< RecordLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 130: // ReferenceLiteral
        value.copy< ReferenceLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 77: // RegisterDefinition
        value.copy< RegisterDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 88: // Enumerators
      case 121: // SetLiteral
        value.copy< SetLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 100: // SkipStatement
      case 101: // AbstractStatement
        value.copy< SkipStatement::Ptr > (YY_MOVE (that.value));
        break;

      case 71: // Specification
        value.copy< Specification::Ptr > (YY_MOVE (that.value));
        break;

      case 97: // StageOption
        value.copy< StageOption::Ptr > (YY_MOVE (that.value));
        break;

      case 99: // Statement
        value.copy< Statement::Ptr > (YY_MOVE (that.value));
        break;

      case 98: // Statements
        value.copy< Statements::Ptr > (YY_MOVE (that.value));
        break;

      case 93: // SyntaxOption
        value.copy< SyntaxOption::Ptr > (YY_MOVE (that.value));
        break;

      case 138: // ArgumentTypes
        value.copy< Types::Ptr > (YY_MOVE (that.value));
        break;

      case 89: // UsingDefinition
        value.copy< UsingDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 65: // "integer"
      case 66: // "binary"
      case 67: // "hexadecimal"
      case 68: // "string"
      case 117: // BooleanLiteral
      case 118: // IntegerLiteral
      case 119: // BinaryLiteral
      case 120: // StringLiteral
        value.copy< ValueLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 140: // VariableBinding
        value.copy< VariableBinding::Ptr > (YY_MOVE (that.value));
        break;

      case 139: // VariableBindings
        value.copy< VariableBindings::Ptr > (YY_MOVE (that.value));
        break;

      case 141: // AttributedVariable
      case 142: // Variable
      case 143: // TypedVariable
        value.copy< VariableDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 134: // Type
      case 135: // BasicType
      case 136: // PropertyType
        value.copy< libscod::CST::Type::Ptr > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->type_get ())
    {
      case 105: // AssignmentStatement
        value.move< AssignmentStatement::Ptr > (YY_MOVE (s.value));
        break;

      case 147: // Attribute
        value.move< Attribute::Ptr > (YY_MOVE (s.value));
        break;

      case 146: // Attributes
        value.move< Attributes::Ptr > (YY_MOVE (s.value));
        break;

      case 148: // BasicAttribute
        value.move< BasicAttribute::Ptr > (YY_MOVE (s.value));
        break;

      case 102: // BlockStatement
        value.move< BlockStatement::Ptr > (YY_MOVE (s.value));
        break;

      case 81: // BufferDefinition
        value.move< BufferDefinition::Ptr > (YY_MOVE (s.value));
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
        value.move< CST::Token::Ptr > (YY_MOVE (s.value));
        break;

      case 84: // CacheDefinition
        value.move< CacheDefinition::Ptr > (YY_MOVE (s.value));
        break;

      case 113: // CallExpression
        value.move< CallExpression::Ptr > (YY_MOVE (s.value));
        break;

      case 103: // CallStatement
        value.move< CallStatement::Ptr > (YY_MOVE (s.value));
        break;

      case 111: // ConditionalExpression
        value.move< ConditionalExpression::Ptr > (YY_MOVE (s.value));
        break;

      case 106: // ConditionalStatement
        value.move< ConditionalStatement::Ptr > (YY_MOVE (s.value));
        break;

      case 92: // DecodingOption
        value.move< DecodingOption::Ptr > (YY_MOVE (s.value));
        break;

      case 74: // AttributedDefinition
      case 75: // Definition
        value.move< Definition::Ptr > (YY_MOVE (s.value));
        break;

      case 73: // Definitions
        value.move< Definitions::Ptr > (YY_MOVE (s.value));
        break;

      case 114: // DirectCallExpression
        value.move< DirectCallExpression::Ptr > (YY_MOVE (s.value));
        break;

      case 87: // EnumerationDefinition
        value.move< EnumerationDefinition::Ptr > (YY_MOVE (s.value));
        break;

      case 94: // ExpansionOption
        value.move< ExpansionOption::Ptr > (YY_MOVE (s.value));
        break;

      case 108: // Term
      case 109: // Expression
      case 112: // OperatorExpression
      case 133: // Terminal
        value.move< Expression::Ptr > (YY_MOVE (s.value));
        break;

      case 149: // ExpressionAttribute
        value.move< ExpressionAttribute::Ptr > (YY_MOVE (s.value));
        break;

      case 107: // Terms
      case 132: // Terminals
        value.move< Expressions::Ptr > (YY_MOVE (s.value));
        break;

      case 78: // FieldDefinition
        value.move< FieldDefinition::Ptr > (YY_MOVE (s.value));
        break;

      case 79: // FormatDefinition
        value.move< FormatDefinition::Ptr > (YY_MOVE (s.value));
        break;

      case 131: // GrammarLiteral
        value.move< GrammarLiteral::Ptr > (YY_MOVE (s.value));
        break;

      case 72: // Header
        value.move< HeaderDefinition::Ptr > (YY_MOVE (s.value));
        break;

      case 69: // "identifier"
      case 144: // Identifier
        value.move< Identifier::Ptr > (YY_MOVE (s.value));
        break;

      case 145: // IdentifierPath
        value.move< IdentifierPath::Ptr > (YY_MOVE (s.value));
        break;

      case 82: // InstructionDefinition
        value.move< InstructionDefinition::Ptr > (YY_MOVE (s.value));
        break;

      case 85: // InterconnectDefinition
        value.move< InterconnectDefinition::Ptr > (YY_MOVE (s.value));
        break;

      case 110: // LetExpression
        value.move< LetExpression::Ptr > (YY_MOVE (s.value));
        break;

      case 104: // LetStatement
        value.move< LetStatement::Ptr > (YY_MOVE (s.value));
        break;

      case 122: // ListLiteral
        value.move< ListLiteral::Ptr > (YY_MOVE (s.value));
        break;

      case 116: // Literal
        value.move< Literal::Ptr > (YY_MOVE (s.value));
        break;

      case 129: // Mapping
        value.move< MappedExpression::Ptr > (YY_MOVE (s.value));
        break;

      case 128: // Mappings
        value.move< MappedExpressions::Ptr > (YY_MOVE (s.value));
        break;

      case 80: // FormatFields
      case 127: // MappingLiteral
        value.move< MappingLiteral::Ptr > (YY_MOVE (s.value));
        break;

      case 137: // MappingType
        value.move< MappingType::Ptr > (YY_MOVE (s.value));
        break;

      case 76: // MemoryDefinition
        value.move< MemoryDefinition::Ptr > (YY_MOVE (s.value));
        break;

      case 115: // MethodCallExpression
        value.move< MethodCallExpression::Ptr > (YY_MOVE (s.value));
        break;

      case 83: // MicroProcessorDefinition
        value.move< MicroProcessorDefinition::Ptr > (YY_MOVE (s.value));
        break;

      case 126: // Assignment
        value.move< NamedExpression::Ptr > (YY_MOVE (s.value));
        break;

      case 125: // Assignments
        value.move< NamedExpressions::Ptr > (YY_MOVE (s.value));
        break;

      case 91: // InstructionOption
      case 96: // MicroProcessorOption
        value.move< Option::Ptr > (YY_MOVE (s.value));
        break;

      case 86: // OptionDefinition
        value.move< OptionDefinition::Ptr > (YY_MOVE (s.value));
        break;

      case 90: // InstructionOptions
      case 95: // MicroProcessorOptions
        value.move< Options::Ptr > (YY_MOVE (s.value));
        break;

      case 123: // RangeLiteral
        value.move< RangeLiteral::Ptr > (YY_MOVE (s.value));
        break;

      case 124: // RecordLiteral
        value.move< RecordLiteral::Ptr > (YY_MOVE (s.value));
        break;

      case 130: // ReferenceLiteral
        value.move< ReferenceLiteral::Ptr > (YY_MOVE (s.value));
        break;

      case 77: // RegisterDefinition
        value.move< RegisterDefinition::Ptr > (YY_MOVE (s.value));
        break;

      case 88: // Enumerators
      case 121: // SetLiteral
        value.move< SetLiteral::Ptr > (YY_MOVE (s.value));
        break;

      case 100: // SkipStatement
      case 101: // AbstractStatement
        value.move< SkipStatement::Ptr > (YY_MOVE (s.value));
        break;

      case 71: // Specification
        value.move< Specification::Ptr > (YY_MOVE (s.value));
        break;

      case 97: // StageOption
        value.move< StageOption::Ptr > (YY_MOVE (s.value));
        break;

      case 99: // Statement
        value.move< Statement::Ptr > (YY_MOVE (s.value));
        break;

      case 98: // Statements
        value.move< Statements::Ptr > (YY_MOVE (s.value));
        break;

      case 93: // SyntaxOption
        value.move< SyntaxOption::Ptr > (YY_MOVE (s.value));
        break;

      case 138: // ArgumentTypes
        value.move< Types::Ptr > (YY_MOVE (s.value));
        break;

      case 89: // UsingDefinition
        value.move< UsingDefinition::Ptr > (YY_MOVE (s.value));
        break;

      case 65: // "integer"
      case 66: // "binary"
      case 67: // "hexadecimal"
      case 68: // "string"
      case 117: // BooleanLiteral
      case 118: // IntegerLiteral
      case 119: // BinaryLiteral
      case 120: // StringLiteral
        value.move< ValueLiteral::Ptr > (YY_MOVE (s.value));
        break;

      case 140: // VariableBinding
        value.move< VariableBinding::Ptr > (YY_MOVE (s.value));
        break;

      case 139: // VariableBindings
        value.move< VariableBindings::Ptr > (YY_MOVE (s.value));
        break;

      case 141: // AttributedVariable
      case 142: // Variable
      case 143: // TypedVariable
        value.move< VariableDefinition::Ptr > (YY_MOVE (s.value));
        break;

      case 134: // Type
      case 135: // BasicType
      case 136: // PropertyType
        value.move< libscod::CST::Type::Ptr > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_type.
  inline
  Parser::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  Parser::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

  inline
  Parser::by_type::by_type (const by_type& that)
    : type (that.type)
  {}

  inline
  Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  Parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  Parser::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
  }

#line 48 "../../obj/src/GrammarParser.y"
} // libscod
#line 4693 "GrammarParser.tab.h"





#endif // !YY_YY_GRAMMARPARSER_TAB_H_INCLUDED
