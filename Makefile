#
#   Copyright (C) 2019 SCOD Organization <https://scod-lang.org>
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

TARGET = libscod

FORMAT  = src
FORMAT += src/analyze
FORMAT += src/cst
FORMAT += src/transform
FORMAT += etc
FORMAT += etc/*
FORMAT += etc/*/*
FORMAT += etc/*/*/*

CONFIG  = ../stdhl
ifeq ($(wildcard $(CONFIG)/.cmake/.*),)
  CONFIG = lib/stdhl
  ifeq ($(wildcard $(CONFIG)/.cmake/.*),)
    $(shell git submodule update --init $(CONFIG) && git -C $(CONFIG) checkout master)
  endif
endif

INCLUDE = $(CONFIG)/.cmake/config.mk
include $(INCLUDE)


LX  = flex -8
YC  = bison
YF  = -Wall -v -g -x

GRAMMAR  = $(OBJ)/src/various/GrammarParser.cpp
GRAMMAR += $(OBJ)/src/various/GrammarLexer.cpp
GRAMMAR += $(OBJ)/src/various/GrammarToken.h
GRAMMAR += src/various/Grammar.org

grammar: $(GRAMMAR)
.PHONY: grammar src/various/Grammar.org


%/src/various/GrammarLexer.cpp: src/various/GrammarLexer.cpp
	mkdir -p "`dirname $@`"
	cp -f $< $@

src/various/GrammarLexer.cpp: src/GrammarLexer.l src/GrammarToken.hpp
	etc/script.sh generate-lexer "`pwd`/$<" "`pwd`/obj/$< $(filter %.hpp,$^)"
	$(LX) $(LFLAGS) -o $@ obj/$<
	sed -i "s/#include <FlexLexer\.h>//g" $@


%/src/various/GrammarParser.cpp: src/various/GrammarParser.cpp
	mkdir -p "`dirname $@`"
	cp -f $< $@

src/various/GrammarParser.cpp: src/GrammarParser.y src/GrammarToken.hpp
	etc/script.sh generate-parser "`pwd`/$<" "`pwd`/obj/$< $(filter %.hpp,$^)"
	cd src/various && $(YC) $(YF) -b src/various/ --output GrammarParser.cpp --defines=GrammarParser.tab.h ../../obj/$<


%/src/various/GrammarToken.h: src/various/GrammarToken.h
	mkdir -p "`dirname $@`"
	cp -f "$<" "$@"

src/various/GrammarToken.h: src/GrammarToken.hpp
	etc/script.sh generate-token "`pwd`/$<" "`pwd`/$@"


src/various/GrammarParser.output: src/various/GrammarParser.cpp
src/various/GrammarParser.dot:    src/various/GrammarParser.cpp
src/various/GrammarParser.xml:    src/various/GrammarParser.cpp

src/various/Grammar.org: src/various/GrammarParser.xml src/GrammarLexer.l
	@xsltproc $(CONFIG)/src/xsl/bison/xml2org.xsl $< > $@
	@sed -i "/ error/d" $@
	@sed -i "s/\"binary\"/\"`grep '// BINARY' src/GrammarLexer.l -B 1 | head -n 1 | sed 's/ {//g' | sed 's/\n//g' | sed 's/\r//g'`\"/g" $@
	@sed -i "s/\"hexadecimal\"/\"`grep '// HEXADECIMAL' src/GrammarLexer.l -B 1 | head -n 1 | sed 's/ {//g' | sed 's/\n//g' | sed 's/\r//g'`\"/g" $@
	@sed -i "s/\"integer\"/\"`grep '// INTEGER' src/GrammarLexer.l -B 1 | head -n 1 | sed 's/ {//g' | sed 's/\n//g' | sed 's/\r//g'`\"/g" $@
	@sed -i "s/\"identifier\"/\"([a-ZA-Z_]|UTF8){([a-zA-Z_0-9]|UTF8)}*\"/g" $@
	@sed -i "s/\"string\"/'\"'.*'\"'/g" $@
