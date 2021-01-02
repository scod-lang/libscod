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

#include "Logger.h"

#include <libscod/Exception>

#include <libstdhl/String>

#include <unordered_set>

using namespace libscod;

static const auto fileNameNull = std::string();

static libstdhl::Log::Items to_location_items(
    const std::vector< libstdhl::SourceLocation >& locations )
{
    libstdhl::Log::Items items;
    for( const auto& location : locations )
    {
        const std::string* fileName = location.begin.fileName.get();

        if( not location.begin.fileName )
        {
            fileName = &fileNameNull;
        }

        items.add( libstdhl::Memory::make< libstdhl::Log::LocationItem >(
            *fileName,
            location.begin.line,
            location.begin.column,
            location.end.line,
            location.end.column ) );
    }
    return items;
}

void libscod::Logger::error(
    const std::vector< libstdhl::SourceLocation >& locations,
    const std::string& message  // ,
    // libscod::Code errorCode
)
{
    auto items = to_location_items( locations );
    items.add( libstdhl::Memory::make< libstdhl::Log::TextItem >( message ) );

    // if( errorCode != Code::Unspecified )
    // {
    //     std::unordered_set< std::string > usedErrorCodeStrings;

    //     for( const auto& location : locations )
    //     {
    //         const auto errorCodeString =
    //             libstdhl::String::format( "@%i{%04x}", location.begin.line, errorCode );

    //         const auto result = usedErrorCodeStrings.emplace( errorCodeString );
    //         if( not result.second )
    //         {
    //             continue;
    //         }

    //         items.add( libstdhl::Memory::make< libstdhl::Log::TextItem >( errorCodeString ) );
    //     }
    // }

    log< libstdhl::Log::Level::ID::ERROR >( items );

    // if( errorCode == Code::Unspecified )
    // {
    //     warning( locations, "unspecified error code" );
    // }
}

void libscod::Logger::error( const Exception& exception )
{
    error(
        exception.locations(), exception.what()  // , exception.errorCode()
    );
}

void libscod::Logger::warning(
    const std::vector< libstdhl::SourceLocation >& locations, const std::string& message )
{
    auto items = to_location_items( locations );
    items.add( libstdhl::Memory::make< libstdhl::Log::TextItem >( message ) );
    log< libstdhl::Log::Level::ID::WARNING >( items );
}

void libscod::Logger::info(
    const std::vector< libstdhl::SourceLocation >& locations, const std::string& message )
{
    auto items = to_location_items( locations );
    items.add( libstdhl::Memory::make< libstdhl::Log::TextItem >( message ) );
    log< libstdhl::Log::Level::ID::INFORMATIONAL >( items );
}

void libscod::Logger::hint(
    const std::vector< libstdhl::SourceLocation >& locations, const std::string& message )
{
    auto items = to_location_items( locations );
    items.add( libstdhl::Memory::make< libstdhl::Log::TextItem >( message ) );
    log< libstdhl::Log::Level::ID::NOTICE >( items );
}

void libscod::Logger::debug(
    const std::vector< libstdhl::SourceLocation >& locations, const std::string& message )
{
    auto items = to_location_items( locations );
    items.add( libstdhl::Memory::make< libstdhl::Log::TextItem >( message ) );
    log< libstdhl::Log::Level::ID::DEBUG >( items );
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
