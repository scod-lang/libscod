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

#include "Specification.h"

#include <cassert>

using namespace libscod;

//
//
// Specification
//

const std::string& Specification::fileExtension( void )
{
    static const std::string fileExtensionString = ".scod";
    return fileExtensionString;
}

Specification::Specification( void )
: m_name()
, m_location()
, m_cst()
, m_ast()
// , m_symboltable( std::make_shared< Namespace >() )
{
}

void Specification::setLocation( const libstdhl::Standard::RFC3986::URI::Ptr& location )
{
    m_location = location;

    if( m_location->scheme() != "file" )
    {
        throw std::invalid_argument(
            "unsupported scheme '" + m_location->scheme() + "' scheme found" );
    }

    //
    // <spec-path> ::= [ <file-path> / ] <file-name> [ .<file-extension> ]
    //

    const auto fileName = m_location->path();
    auto lastSlashPos = fileName.find_last_of( '/' );
    auto lastPointPos = fileName.rfind( "." );

    // if <file-path> has no slash set to start position, otherwise increment by one
    lastSlashPos = ( lastSlashPos == std::string::npos ) ? 0 : lastSlashPos + 1;

    // if <spec-path> has no point set to end position, otherwise decrement by one
    lastPointPos = ( lastPointPos == std::string::npos ) ? fileName.size() - 1 : lastPointPos - 1;

    // extract sub-string with start position and length (delta) characters and set member
    m_name = fileName.substr( lastSlashPos, lastPointPos - lastSlashPos + 1 );
}

const libstdhl::Standard::RFC3986::URI::Ptr& Specification::location( void ) const
{
    return m_location;
}

const std::string& Specification::name( void ) const
{
    return m_name;
}

void Specification::setCst( const CST::Root::Ptr& cst )
{
    m_cst = cst;
}

const CST::Root::Ptr& Specification::cst( void ) const
{
    assert( m_cst and " inconsistent state " );
    return m_cst;
}

void Specification::setAst( const AST::Root::Ptr& ast )
{
    m_ast = ast;
}

const AST::Root::Ptr& Specification::ast( void ) const
{
    assert( m_ast and " inconsistent state " );
    return m_ast;
}

// void Specification::setSymboltable( const Namespace::Ptr& symboltable )
// {
//     m_symboltable = symboltable;
// }

// const Namespace::Ptr& Specification::symboltable( void ) const
// {
//     return m_symboltable;
// }

//
//  Local variables:
//  mode: c++
//  indent-tabs-mode: nil
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//
