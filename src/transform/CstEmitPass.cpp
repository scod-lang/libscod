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

#include "CstEmitPass.h"

#include "../various/GrammarToken.h"

#include <libscod/Logger>
// #include <libscod/Namespace>
// #include <libscod/Specification>
// #include <libscod/cst/Literal>
#include <libscod/cst/Visitor>
#include <libscod/transform/SourceToCstPass>

#include <libpass/PassRegistry>
#include <libpass/PassResult>
#include <libpass/PassUsage>

#include <iostream>

using namespace libscod;
using namespace CST;

char CstEmitPass::id = 0;

static libpass::PassRegistration< CstEmitPass > PASS(
    "CstEmitPass",
    "emits the SCOD specification based on the parsed CST and writes it to a specified output path",
    "cst-emit",
    0 );

namespace libscod
{
    namespace CST
    {
        class CSTDumpSourceVisitor final : public RecursiveVisitor
        {
          public:
            explicit CSTDumpSourceVisitor( std::ostream& stream );

            void visit( UnresolvedOption& node ) override;

            void visit( ValueLiteral& node ) override;

            void visit( UnresolvedType& node ) override;

            void visit( Identifier& node ) override;
            void visit( Token& node ) override;
            void visit( Span& node ) override;

          private:
            std::ostream& m_stream;
        };
    }
}

CSTDumpSourceVisitor::CSTDumpSourceVisitor( std::ostream& stream )
: m_stream( stream )
{
}

void CSTDumpSourceVisitor::visit( ValueLiteral& node )
{
    RecursiveVisitor::visit( node );
    m_stream << node.toString();
}

void CSTDumpSourceVisitor::visit( UnresolvedOption& node )
{
}

void CSTDumpSourceVisitor::visit( UnresolvedType& node )
{
}

void CSTDumpSourceVisitor::visit( Identifier& node )
{
    RecursiveVisitor::visit( node );
    m_stream << node.name();
}

void CSTDumpSourceVisitor::visit( Token& node )
{
    if( node.token() == Grammar::Token::UNRESOLVED )
    {
        return;
    }

    RecursiveVisitor::visit( node );
    m_stream << node.tokenString();
}

void CSTDumpSourceVisitor::visit( Span& node )
{
    RecursiveVisitor::visit( node );
    m_stream << node.toString();
}

//
//
// CstEmitPass
//

void CstEmitPass::usage( libpass::PassUsage& pu )
{
    pu.require< SourceToCstPass >();
    // pu.scheduleAfter< ... >();
}

u1 CstEmitPass::run( libpass::PassResult& pr )
{
    Logger log( &id, stream() );

    const auto& data = pr.output< SourceToCstPass >();
    const auto& specification = data->specification();

    auto& outputStream = std::cout;

    CSTDumpSourceVisitor visitor{ outputStream };
    specification->cst()->accept( visitor );

    return true;
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
