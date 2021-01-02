#!/bin/bash
#
#   Copyright (C) 2019-2021 SCOD Organization <https://scod-lang.org>
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

APP=`basename $0`

function usage
{
    echo "usage: $APP <generate-token|generate-lexer|generate-parser>"
    exit -1
}

function generate_token
{
    local src=$1
    local dst=$2

    mkdir -p `dirname $src`
    cat `dirname $src`/../obj/notice.txt | sed 's/^/\/\/  /g' > $dst
    echo "" >> $dst
    echo "#ifndef _LIBSCOD_GRAMMAR_TOKEN_H_" >> $dst
    echo "#define _LIBSCOD_GRAMMAR_TOKEN_H_" >> $dst
    echo "" >> $dst
    echo "#include <libscod/Scod>" >> $dst
    echo "" >> $dst
    echo "#include <cassert>" >> $dst
    echo "" >> $dst
    echo "namespace libscod" >> $dst
    echo "{" >> $dst
    echo "    namespace Grammar" >> $dst
    echo "    {" >> $dst
    echo "        enum class Token : u8" >> $dst
    echo "        {" >> $dst
	echo "            /*  0 */ UNRESOLVED," >> $dst

    local tokens=`cat $src | grep '.*\"'`
    local mode=name
    declare -i uid=1
    for element in $tokens; do
        #printf "%2i -> %s\n" $uid $element
	if [ "$mode" = "name" ]; then
	    printf "            /* %2i */ $element,\n" $uid >> $dst
	    mode=token
	else
	    # mode token
	    mode=name
            uid+=1
	fi
    done

    echo "        };" >> $dst
    echo "        " >> $dst
    echo "        static std::string tokenAsString( const Token token )" >> $dst
    echo "        {" >> $dst
    echo "            switch( token )" >> $dst
    echo "            {" >> $dst
    echo "                case /*  0 */ Token::UNRESOLVED:" >> $dst
	echo "                {" >> $dst
	echo "                    return \"\$unresolved\$\";" >> $dst
	echo "                }" >> $dst

    mode=name
    uid=1
    for element in $tokens; do
	if [ "$mode" = "name" ]; then
	    printf "                case /* %2i */ Token::$element:\n" $uid >> $dst
	    mode=token
	else
	    # mode token
	    echo "                {" >> $dst
	    printf "                    return %s;\n" $element >> $dst
	    echo "                }" >> $dst
	    mode=name
            uid+=1
	fi
    done

    echo "            }" >> $dst
    echo "            assert( !\"internal error\" );" >> $dst
    echo "            return std::string();" >> $dst
    echo "        }" >> $dst
    echo "    };" >> $dst
    echo "}" >> $dst
    echo "" >> $dst
    echo "#endif  // _LIBSCOD_GRAMMAR_TOKEN_H_" >> $dst
    echo "" >> $dst
    echo "//" >> $dst
    echo "//  Local variables:" >> $dst
    echo "//  mode: c++" >> $dst
    echo "//  indent-tabs-mode: nil" >> $dst
    echo "//  c-basic-offset: 4" >> $dst
    echo "//  tab-width: 4" >> $dst
    echo "//  End:" >> $dst
    echo "//  vim:noexpandtab:sw=4:ts=4:" >> $dst
    echo "//" >> $dst

    exit 0
}

function generate_lexer
{
    local src=$1
    local dst=$2
    local grammartoken=$3

    mkdir -p `dirname $src`
	head -n +`grep -n "{{grammartoken}}" $src | grep -o "[0-9]*"` $src | cat  > $dst

    local tokens=`cat $grammartoken | grep '.*\"'`
    local mode=name
    local name=""
    declare -i uid=1
    for element in $tokens; do
        #printf "%2i -> %s\n" $uid $element
	    if [ "$mode" = "name" ]; then
	        mode=token
            name=$element
	    else
	        # mode token
	        mode=name
            uid+=1
	        printf "%-20s { YY_TOKEN_ACTION( %s ) }\n" $element $name >> $dst
	    fi
    done

    tail -n +`grep -n "{{grammartoken}}" $src | grep -o "[0-9]*"` $src | cat >> $dst
	sed -i "/^{{grammartoken}}/d" $dst

    exit 0
}

function generate_parser
{
    local src=$1
    local dst=$2
    local grammartoken=$3

    mkdir -p `dirname $src`
	head -n +`grep -n "{{grammartoken}}" $src | grep -o "[0-9]*"` $src | cat  > $dst

    local tokens=`cat $grammartoken | grep '.*\"'`
    local mode=name
    declare -i uid=1
    for element in $tokens; do
        #printf "%2i -> %s\n" $uid $element
	    if [ "$mode" = "name" ]; then
	        printf "%-20s " $element >> $dst
	        mode=token
	    else
	        # mode token
	        mode=name
            uid+=1
	        printf "%s\n" $element >> $dst
	    fi
    done

    mode=name
    uid=1
    for element in $tokens; do
        #printf "%2i -> %s\n" $uid $element
	    if [ "$mode" = "name" ]; then
	        echo "%type <CST::Token::Ptr> $element" >> $dst
	        mode=token
	    else
	        # mode token
	        mode=name
            uid+=1
	    fi
    done

	tail -n +`grep -n "{{grammartoken}}" $src | grep -o "[0-9]*"` $src | cat >> $dst
	sed -i "/^{{grammartoken}}/d" $dst

    exit 0
}

if [ -z "$1" ]; then
    usage
    exit -1
fi

if [ "$1" = "generate-token" ]; then
    generate_token $2 $3
elif [ "$1" = "generate-lexer" ]; then
    generate_lexer $2 $3 $4
elif [ "$1" = "generate-parser" ]; then
    generate_parser $2 $3 $4
else
    usage
fi
