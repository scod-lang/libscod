//
//  Copyright (C) 2019-2021 SCOD Organization <https://scod-lang.org>
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

#include "SourceToCstPass.h"

#include <libscod/Logger>
// #include <libscod/Namespace>
#include <libscod/Specification>
// #include <libscod/TypeInfo>
// #include <libscod/analyze/ProjectResolverPass>

#include <libpass/PassRegistry>
#include <libpass/analyze/LoadFilePass>

#include <libstdhl/std/rfc3986>

#include "../Lexer.h"
#include "../various/GrammarParser.tab.h"
#include "../various/GrammarToken.h"

using namespace libscod;

char SourceToCstPass::id = 0;

static libpass::PassRegistration< SourceToCstPass > PASS(
    "Source Parsing Pass", "parse the source code and generates an CST", "src2cst", 0 );

//
//
// SourceToCstPass
//

void SourceToCstPass::usage( libpass::PassUsage& pu )
{
    // pu.require< ProjectResolverPass >();
    pu.require< libpass::LoadFilePass >();
}

u1 SourceToCstPass::run( libpass::PassResult& pr )
{
    libscod::Logger log( &id, stream() );

    const auto data = pr.output< libpass::LoadFilePass >();
    // const auto project = data->project();
    // const auto specificationFile = project->specification();
    const auto specificationFileName = data->filename();
    auto& specificationFileStream = data->stream();

    Lexer lexer( log, specificationFileStream, std::cout );
    lexer.setFileName( specificationFileName );

    const auto specification = std::make_shared< Specification >();
    specification->setLocation( std::make_shared< libstdhl::Standard::RFC3986::URI >(
        "file", "/", specificationFileName, "", "" ) );

    Parser parser( log, lexer, *specification );
    parser.set_debug_level( m_debug );

    if( ( parser.parse() != 0 ) or not specification or ( log.errors() > 0 ) )
    {
        log.error( "could not parse '" + specification->location()->toString() + "'" );
        return false;
    }

    // if( specification->name() == "SCOD" )
    // {
    //     log.debug( "module 'SCOD' found" );
    // }
    // else
    // {
    //     const auto& sourceLocation = specification->cst()->header()->sourceLocation();
    //     const auto scodImport = CST::make< ImportDefinition >(
    //         sourceLocation,
    //         Token::unresolved(),
    //         IdentifierPath::fromIdentifier( CST::make< Identifier >( sourceLocation, "SCOD" ) )
    //         );
    //     specification->cst()->definitions()->add( scodImport );

    //     const auto scodUsing = CST::make< UsingPathDefinition >(
    //         sourceLocation,
    //         Token::unresolved(),
    //         IdentifierPath::fromIdentifier( CST::make< Identifier >( sourceLocation, "SCOD" ) ),
    //         std::make_shared< Token >( Grammar::Token::DOUBLECOLON ),
    //         std::make_shared< Token >( Grammar::Token::ASTERIX ) );
    //     specification->cst()->definitions()->add( scodUsing );
    // }

    pr.setOutput< SourceToCstPass >( specification );
    return true;
}

void SourceToCstPass::setDebug( u1 enable )
{
    m_debug = enable;
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
