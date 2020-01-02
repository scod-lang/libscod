//
//  Copyright (C) 2019-2020 SCOD Organization <https://scod-lang.org>
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

#include "Identifier.h"

#include <libscod/Namespace>

#include <cassert>

using namespace libscod;
using namespace AST;

//
//
// Identifier
//

Identifier::Identifier( const std::string& name )
: Node( Node::ID::IDENTIFIER )
, m_name( name )
{
}

const std::string& Identifier::name( void ) const
{
    return m_name;
}

void Identifier::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
//
// IdentifierPath
//

IdentifierPath::IdentifierPath( const Identifier::Ptr& identifier )
: Node( Node::ID::IDENTIFIER_PATH )
, m_identifiers( AST::make< Identifiers >( identifier->sourceLocation() ) )
{
    m_identifiers->add( identifier );
}

IdentifierPath::IdentifierPath( const Identifiers::Ptr& identifiers )
: Node( Node::ID::IDENTIFIER_PATH )
, m_identifiers( identifiers )
{
    assert( not identifiers->empty() && "identifiers must not be empty" );
}

void IdentifierPath::addIdentifier( const Identifier::Ptr& identifier )
{
    m_identifiers->add( identifier );
}

Identifiers::Ptr IdentifierPath::identifiers( void ) const
{
    return m_identifiers;
}

const std::string& IdentifierPath::baseName( void ) const
{
    assert( not m_identifiers->empty() );  // see ctor precondition
    return m_identifiers->back()->name();
}

std::string IdentifierPath::baseDir( void ) const
{
    const auto& p = path();
    const size_t lastDotPos = p.find_last_of( Namespace::delimiter() );
    if( lastDotPos != std::string::npos )
    {
        return p.substr( 0, lastDotPos - Namespace::delimiter().size() + 1 );
    }
    else
    {
        return std::string();
    }
}

std::string IdentifierPath::path( void ) const
{
    std::string path;

    u1 isFirstElement = true;
    for( const auto& identifier : *m_identifiers )
    {
        if( not isFirstElement )
        {
            path += Namespace::delimiter();
        }
        path += identifier->name();
        isFirstElement = false;
    }

    return path;
}

void IdentifierPath::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

IdentifierPath::Ptr IdentifierPath::fromIdentifier( const Identifier::Ptr& identifier )
{
    const auto& location = identifier->sourceLocation();
    return AST::make< IdentifierPath >( location, identifier );
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
