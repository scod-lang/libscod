#
#   Copyright (C) 2019-2020 SCOD Organization <https://scod-lang.org>
#   All rights reserved.
#
#   Developed by: Philipp Paulweber
#                 Emmanuel Pescosta
#                 <https://github.com/scod-lang/libscod>
#
#   This file is part of libscod.
#
#   libscod is free software: you can redistribute it and/or modify
#   it under the terms of the GNU General Public License as published by
#   the Free Software Foundation, either version 3 of the License, or
#   (at your option) any later version.
#
#   libscod is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
#   GNU General Public License for more details.
#
#   You should have received a copy of the GNU General Public License
#   along with libscod. If not, see <http://www.gnu.org/licenses/>.
#
#   Additional permission under GNU GPL version 3 section 7
#
#   libscod is distributed under the terms of the GNU General Public License
#   with the following clarification and special exception: Linking libscod
#   statically or dynamically with other modules is making a combined work
#   based on libscod. Thus, the terms and conditions of the GNU General
#   Public License cover the whole combination. As a special exception,
#   the copyright holders of libscod give you permission to link libscod
#   with independent modules to produce an executable, regardless of the
#   license terms of these independent modules, and to copy and distribute
#   the resulting executable under terms of your choice, provided that you
#   also meet, for each linked independent module, the terms and conditions
#   of the license of that module. An independent module is a module which
#   is not derived from or based on libscod. If you modify libscod, you
#   may extend this exception to your version of the library, but you are
#   not obliged to do so. If you do not wish to do so, delete this exception
#   statement from your version.
#

include_directories(
  ${PROJECT_BINARY_DIR}/src
  ${LIBSTDHL_INCLUDE_DIR}
  ${LIBPASS_INCLUDE_DIR}
)

add_library( ${PROJECT}-cpp OBJECT
  Exception.cpp
  Lexer.cpp
  Logger.cpp
  Namespace.cpp
  Specification.cpp

  cst/Root.cpp
  cst/Attribute.cpp
  cst/Binding.cpp
  cst/Definition.cpp
  cst/Expression.cpp
  cst/Identifier.cpp
  cst/Literal.cpp
  cst/Node.cpp
  cst/Option.cpp
  cst/Span.cpp
  cst/Statement.cpp
  cst/Token.cpp
  cst/Type.cpp
  cst/Visitor.cpp

  ast/Root.cpp
  ast/Binding.cpp
  ast/Definition.cpp
  ast/Expression.cpp
  ast/Identifier.cpp
  ast/Literal.cpp
  ast/Node.cpp
  ast/Option.cpp
  ast/Statement.cpp
  ast/Type.cpp
  ast/Visitor.cpp

#  analyze/TODO.cpp

  transform/SourceToCstPass.cpp

  transform/CstDumpPass.cpp
  transform/CstEmitPass.cpp
  transform/CstToAstPass.cpp

  transform/AstDumpPass.cpp
  transform/AstToCasmPass.cpp

  various/GrammarParser.cpp
  )


configure_file(
  Version.in.h
  ${PROJECT}/Version.h
  )
configure_file(
  Version.in
  ${PROJECT}/Version
  )
install(
  FILES
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT}/Version.h
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT}/Version
  DESTINATION
    "include/${PROJECT}"
  )


ecm_generate_headers( ${PROJECT}_HEADERS_CPP
  ORIGINAL
    CAMELCASE
  HEADER_NAMES
    libscod
    Scod
#    Codes
#    Configuration
    Exception
    Logger
    Namespace
#    Project
    Specification
#    TypeInfo
  PREFIX
    ${PROJECT}
  REQUIRED_HEADERS
    ${PROJECT}_HEADERS
  )
install(
  FILES
    ${${PROJECT}_HEADERS}
    ${${PROJECT}_HEADERS_CPP}
  DESTINATION
    "include/${PROJECT}"
  )


ecm_generate_headers( ${PROJECT}_CST_HEADERS_CPP
  ORIGINAL
    CAMELCASE
  HEADER_NAMES
    Root
    Attribute
    Binding
    Definition
    Expression
    Identifier
    Literal
    Node
    Option
    Span
    Statement
    Token
    Type
     Visitor
  PREFIX
    ${PROJECT}/cst
  RELATIVE
    cst
  REQUIRED_HEADERS
    ${PROJECT}_CST_HEADERS
  )
install(
  FILES
    ${${PROJECT}_CST_HEADERS}
    ${${PROJECT}_CST_HEADERS_CPP}
  DESTINATION
    "include/${PROJECT}/cst"
  )


ecm_generate_headers( ${PROJECT}_AST_HEADERS_CPP
  ORIGINAL
    CAMELCASE
  HEADER_NAMES
    Root
    Binding
    Definition
    Expression
    Identifier
    Literal
    Node
    Option
    Statement
    Type
    Visitor
  PREFIX
    ${PROJECT}/ast
  RELATIVE
    ast
  REQUIRED_HEADERS
    ${PROJECT}_AST_HEADERS
  )
install(
  FILES
    ${${PROJECT}_AST_HEADERS}
    ${${PROJECT}_AST_HEADERS_CPP}
  DESTINATION
    "include/${PROJECT}/ast"
  )


# ecm_generate_headers( ${PROJECT}_ANALYZE_HEADERS_CPP
#   ORIGINAL
#     CAMELCASE
#   HEADER_NAMES
#     TODO
#   PREFIX
#     ${PROJECT}/analyze
#   RELATIVE
#     analyze
#   REQUIRED_HEADERS
#     ${PROJECT}_ANALYZE_HEADERS
#   )
# install(
#   FILES
#     ${${PROJECT}_ANALYZE_HEADERS}
#     ${${PROJECT}_ANALYZE_HEADERS_CPP}
#   DESTINATION
#     "include/${PROJECT}/analyze"
#   )


ecm_generate_headers( ${PROJECT}_TRANSFORM_HEADERS_CPP
  ORIGINAL
    CAMELCASE
  HEADER_NAMES
    SourceToCstPass
    CstDumpPass
    CstEmitPass
    CstToAstPass
    AstDumpPass
    AstToCasmPass
  PREFIX
    ${PROJECT}/transform
  RELATIVE
    transform
  REQUIRED_HEADERS
    ${PROJECT}_TRANSFORM_HEADERS
  )
install(
  FILES
    ${${PROJECT}_TRANSFORM_HEADERS}
    ${${PROJECT}_TRANSFORM_HEADERS_CPP}
  DESTINATION
    "include/${PROJECT}/transform"
  )

