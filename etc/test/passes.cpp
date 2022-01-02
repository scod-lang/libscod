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

#include "main.h"

#include <libpass/PassManager>
#include <libpass/PassResult>
#include <libpass/analyze/LoadFilePass>

using namespace libscod;
using namespace CST;

static const auto source = R"***(
SCOD

using Word = Binary'32

memory MEM : Binary'32 -> Word

register PC : Binary'27

register GPR : Binary'5 -> Binary'16

enumeration Flags = 
{ Signal
}

register CSR : Flags -> Boolean

field opcode : Binary'6
field source : Binary'5
field target : Binary'5
field value  : Binary'16

format F : Binary'32 =
{ 26 -> opcode
, 21 -> source
, 16 -> target
,  0 -> value
}

buffer AdjustedValue : F -> Binary'32 =
[ value(15).repeat(18), value([14..2]) ]

[ description "Addition" ]
instruction add : F = {
    let lhs = GPR(source) in
    let rhs = AdjustedValue in
    let res = lhs (+) rhs in {
        GPR(target) := res
        PC := PC + 4
        if res.carry then
            CSR(Signal) := true
    }
}
decoding = { 
  opcode : 0b00'1100
}
syntax = 
{ :: mnemonic target "," source "," value ;
}

instruction jmp : F = {
    let lhs = GPR(source)
      , rhs = GPR(target)
      , res = lhs + rhs in {
        GPR(target) := res
        PC := PC + 4
    }
}

@jmp decoding = 
{ opcode : 0b10'1010
}

@jmp syntax = 
{ :: mnemonic value ;
}


[ pseudo ]
instruction mov : F = abstract
syntax =
{ :: mnemonic target "," source ;
}
expansion = 
{ :: @add target "," source "," 0 ;
}


register instr : Word

microprocessor machine : PC = {
    PC := 0xdeadbeef
    GPR(0) := 0
    instr := 0
}
stage fetch = {
    instr := MEM( PC )
}
stage decode = {
    decoding( instr, { @instruction } )
}
stage execute = {
    instruction( opcode, { @instruction } )
}


cache CMEM : Word -> Word =
{ MEM -> machine
}

[ instruction ]
cache IMEM : Word -> Word =
{ CMEM -> L2
}

[ data ]
cache DMEM : Word -> Word =
{ CMEM -> L2
}

cache L2 : Word -> Word =
{ IMEM -> DRAM
, DMEM -> DRAM
}

[ physical ]
memory DRAM : Binary'24 -> Word

interconnect BUS : Address -> Word =
{ L2 -> DRAM
}

)***";

#define SOURCE( PASS, CONTENT, STATUS, CONFIG )                                                   \
    {                                                                                             \
        libpass::PassManager pm;                                                                  \
        pm.setDefaultPass< PASS >();                                                              \
        pm.set< libscod::PASS >( [ & ]( libscod::PASS& pass ) { CONFIG } );                       \
                                                                                                  \
        libstdhl::Logger log( pm.stream() );                                                      \
        log.setSource( libstdhl::Memory::make< libstdhl::Log::Source >( TEST_NAME, TEST_NAME ) ); \
                                                                                                  \
        auto flush = [ &pm ]() {                                                                  \
            libstdhl::Log::ApplicationFormatter f( TEST_NAME );                                   \
            libstdhl::Log::OutputStreamSink c( std::cerr, f );                                    \
            pm.stream().flush( c );                                                               \
        };                                                                                        \
                                                                                                  \
        const std::string filename = TEST_NAME + Specification::fileExtension();                  \
        auto file = libstdhl::File::open( filename, std::fstream::out );                          \
        file << CONTENT;                                                                          \
        file.close();                                                                             \
                                                                                                  \
        libpass::PassResult pr;                                                                   \
        pr.setInput< libpass::LoadFilePass >( filename );                                         \
        pm.setDefaultResult( pr );                                                                \
                                                                                                  \
        EXPECT_EQ( pm.run( flush ), STATUS );                                                     \
                                                                                                  \
        pm.result().output< libpass::LoadFilePass >()->close();                                   \
        libstdhl::File::remove( filename );                                                       \
        EXPECT_EQ( libstdhl::File::exists( filename ), false );                                   \
    }

#define SOURCE_TEST( SCOPE, PASS, CONTENT, STATUS, DESCRIPTION, CONFIG ) \
    TEST( libscod_passes, SCOPE##_##PASS##DESCRIPTION )                  \
    {                                                                    \
        SOURCE( PASS, CONTENT, STATUS, CONFIG );                         \
    }

SOURCE_TEST( transform, SourceToCstPass, source, true, , { pass.setDebug( false ); } );

SOURCE_TEST( transform, CstDumpPass, source, true, , );

SOURCE_TEST( transform, CstEmitPass, source, true, , );

SOURCE_TEST( transform, CstToAstPass, source, true, , );

SOURCE_TEST( transform, AstDumpPass, source, true, , );

SOURCE_TEST( transform, AstToCasmPass, source, true, , );

//
//  Local variables:
//  mode: c++
//  indent-tabs-mode: nil
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//
