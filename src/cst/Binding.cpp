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

#include "Binding.h"

#include <libscod/cst/Definition>

using namespace libscod;
using namespace CST;

//
//
// Binding
//

Binding::Binding( const Node::ID id )
: Node( id )
, m_delimiterToken( Token::unresolved() )
{
}

void Binding::setDelimiterToken( const Token::Ptr& delimiterToken )
{
    m_delimiterToken = delimiterToken;
}

const Token::Ptr& Binding::delimiterToken( void ) const
{
    return m_delimiterToken;
}

//
//
// VariableBinding
//

VariableBinding::VariableBinding(
    const VariableDefinition::Ptr& variable,
    const Token::Ptr& equalToken,
    const Expression::Ptr& expression )
: Binding( Node::ID::VARIABLE_DEFINITION )
, m_variable( variable )
, m_expression( expression )
, m_equalToken( equalToken )
{
}

const VariableDefinition::Ptr& VariableBinding::variable( void ) const
{
    return m_variable;
}

const Expression::Ptr& VariableBinding::expression( void ) const
{
    return m_expression;
}

const Token::Ptr& VariableBinding::equalToken( void ) const
{
    return m_equalToken;
}

void VariableBinding::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//  Local variables:
//  mode: c++
//  indent-tabs-mode: nil
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//
