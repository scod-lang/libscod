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

#include "Type.h"

#include "../various/GrammarToken.h"

// #include <libscod/cst/Definition>
// #include <libscod/cst/Token>
// #include <libscod/TypeInfo>
// #include <libscod/cst/Literal>

using namespace libscod;
using namespace CST;

static const auto unresolvedIdentifierPath =
    IdentifierPath::fromIdentifier( std::make_shared< Identifier >( "$unresolved$" ) );

//
//
// Type
//

Type::Type( const Node::ID id, const IdentifierPath::Ptr& name )
: Node( id )
, m_name( name )
// , m_typeDefinition()
, m_delimiterToken( Token::unresolved() )
{
}

const IdentifierPath::Ptr& Type::name( void ) const
{
    return m_name;
}

// void Type::setTypeDefinition( const TypeDefinition::Ptr& typeDefinition )
// {
//     m_typeDefinition = typeDefinition;
// }

// const TypeDefinition::Ptr& Type::typeDefinition( void ) const
// {
//     return m_typeDefinition;
// }

void Type::setDelimiterToken( const Token::Ptr& delimiterToken )
{
    assert( m_delimiterToken->token() == Grammar::Token::UNRESOLVED );
    m_delimiterToken = delimiterToken;
}

const Token::Ptr& Type::delimiterToken( void ) const
{
    return m_delimiterToken;
}

IdentifierPath::Ptr Type::signaturePath( void ) const
{
    const auto& typeSignatureIdentifier = CST::make< Identifier >( sourceLocation(), signature() );

    const auto path = IdentifierPath::fromIdentifier( name()->identifiers()->front() );
    for( std::size_t i = 1; i < name()->identifiers()->size(); i++ )
    {
        const auto identifier = ( *name()->identifiers() )[ i ];
        path->addIdentifier( identifier );
    }

    path->addIdentifier( typeSignatureIdentifier );
    return path;
}

//
//
// UnresolvedType
//

UnresolvedType::UnresolvedType( void )
: Type( Node::ID::UNRESOLVED_TYPE, unresolvedIdentifierPath )
{
}

std::string UnresolvedType::signature( void ) const
{
    return "?";
}

void UnresolvedType::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
//
// BasicType
//

BasicType::BasicType( const IdentifierPath::Ptr& name )
: Type( Node::ID::BASIC_TYPE, name )
{
}

std::string BasicType::signature( void ) const
{
    return name()->baseName();
}

void BasicType::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
//
// EmbracedType
//

EmbracedType::EmbracedType(
    const Node::ID id,
    const IdentifierPath::Ptr& name,
    const Token::Ptr& leftBraceToken,
    const Token::Ptr& rightBraceToken )
: Type( id, name )
, m_leftBraceToken( leftBraceToken )
, m_rightBraceToken( rightBraceToken )
{
}

const Token::Ptr& EmbracedType::leftBraceToken( void ) const
{
    return m_leftBraceToken;
}

const Token::Ptr& EmbracedType::rightBraceToken( void ) const
{
    return m_rightBraceToken;
}

// //
// //
// // TupleType
// //

// TupleType::TupleType(
//     const Token::Ptr& leftBraceToken,
//     const Types::Ptr& subTypes,
//     const Token::Ptr& rightBraceToken )
// : EmbracedType(
//       Node::ID::TUPLE_TYPE,
//       IdentifierPath::fromIdentifier(
//           CST::make< Identifier >( subTypes->sourceLocation(), TypeInfo::TYPE_NAME_TUPLE ) ),
//       leftBraceToken,
//       rightBraceToken )
// , m_subTypes( subTypes )
// {
// }

// const Types::Ptr& TupleType::subTypes( void ) const
// {
//     return m_subTypes;
// }

// std::string TupleType::signature( void ) const
// {
//     std::stringstream stream;
//     stream << "(";

//     for( const auto& subType : *subTypes() )
//     {
//         stream << " " << subType->signature() << ",";
//     }

//     stream.seekp( -1, stream.cur );
//     stream << " )";

//     return stream.str();
// }

// void TupleType::accept( Visitor& visitor )
// {
//     visitor.visit( *this );
// }

// Node::Ptr TupleType::clone( void ) const
// {
//     auto duplicate = std::make_shared< TupleType >(
//         leftBraceToken(), subTypes()->duplicate< Types >(), rightBraceToken() );

//     EmbracedType::clone( *duplicate );
//     return duplicate;
// }

// //
// //
// // RecordType
// //

// RecordType::RecordType(
//     const Token::Ptr& leftBraceToken,
//     const VariableDefinitions::Ptr& namedSubTypes,
//     const Token::Ptr& rightBraceToken )
// : EmbracedType(
//       Node::ID::RECORD_TYPE,
//       IdentifierPath::fromIdentifier(
//           CST::make< Identifier >( namedSubTypes->sourceLocation(), TypeInfo::TYPE_NAME_RECORD )
//           ),
//       leftBraceToken,
//       rightBraceToken )
// , m_namedSubTypes( namedSubTypes )
// {
// }

// const VariableDefinitions::Ptr& RecordType::namedSubTypes( void ) const
// {
//     return m_namedSubTypes;
// }

// std::string RecordType::signature( void ) const
// {
//     std::stringstream stream;
//     stream << "{";

//     for( const auto& subType : *namedSubTypes() )
//     {
//         stream << " " << subType->variableType()->signature() << ",";
//     }

//     stream.seekp( -1, stream.cur );
//     stream << " }";

//     return stream.str();
// }

// void RecordType::accept( Visitor& visitor )
// {
//     visitor.visit( *this );
// }

// Node::Ptr RecordType::clone( void ) const
// {
//     auto duplicate = std::make_shared< RecordType >(
//         leftBraceToken(), namedSubTypes()->duplicate< VariableDefinitions >(), rightBraceToken()
//         );

//     EmbracedType::clone( *duplicate );
//     return duplicate;
// }

// //
// //
// // TemplateType
// //

// TemplateType::TemplateType(
//     const IdentifierPath::Ptr& identifier,
//     const Token::Ptr& leftBraceToken,
//     const Types::Ptr& subTypes,
//     const Token::Ptr& rightBraceToken )
// : EmbracedType( Node::ID::TEMPLATE_TYPE, identifier, leftBraceToken, rightBraceToken )
// , m_subTypes( subTypes )
// {
// }

// const Types::Ptr& TemplateType::subTypes( void ) const
// {
//     return m_subTypes;
// }

// void TemplateType::setSubTypes( const Types::Ptr& subTypes )
// {
//     m_subTypes = subTypes;
// }

// std::string TemplateType::signature( void ) const
// {
//     std::stringstream stream;
//     stream << name()->baseName();
//     stream << "<";

//     for( const auto& subType : *subTypes() )
//     {
//         stream << " " << subType->signature() << ",";
//     }

//     stream.seekp( -1, stream.cur );
//     stream << " >";

//     return stream.str();
// }

// void TemplateType::accept( Visitor& visitor )
// {
//     visitor.visit( *this );
// }

// Node::Ptr TemplateType::clone( void ) const
// {
//     auto duplicate = std::make_shared< TemplateType >(
//         name()->duplicate< IdentifierPath >(),
//         leftBraceToken(),
//         subTypes()->duplicate< Types >(),
//         rightBraceToken() );

//     EmbracedType::clone( *duplicate );
//     return duplicate;
// }

// //
// //
// // RelationType
// //

// RelationType::RelationType(
//     const IdentifierPath::Ptr& identifier,
//     const Token::Ptr& leftBraceToken,
//     const Types::Ptr& argumentTypes,
//     const Token::Ptr& mapsToken,
//     const Type::Ptr& returnType,
//     const Token::Ptr& rightBraceToken )
// : EmbracedType( Node::ID::RELATION_TYPE, identifier, leftBraceToken, rightBraceToken )
// , m_argumentTypes( argumentTypes )
// , m_returnType( returnType )
// , m_mapsToken( mapsToken )
// {
// }

// const Types::Ptr& RelationType::argumentTypes( void ) const
// {
//     return m_argumentTypes;
// }

// const Type::Ptr& RelationType::returnType( void ) const
// {
//     return m_returnType;
// }

// const Token::Ptr& RelationType::mapsToken( void ) const
// {
//     return m_mapsToken;
// }

// std::string RelationType::signature( void ) const
// {
//     std::stringstream stream;
//     stream << name()->baseName();
//     stream << "< ";

//     for( const auto& subType : *argumentTypes() )
//     {
//         stream << subType->signature() << " * ";
//     }

//     if( argumentTypes()->size() > 0 )
//     {
//         stream.seekp( -2, stream.cur );
//     }

//     stream << "-> " << returnType()->signature() << " >";
//     return stream.str();
// }

// void RelationType::accept( Visitor& visitor )
// {
//     visitor.visit( *this );
// }

// Node::Ptr RelationType::clone( void ) const
// {
//     auto duplicate = std::make_shared< RelationType >(
//         name()->duplicate< IdentifierPath >(),
//         leftBraceToken(),
//         argumentTypes()->duplicate< Types >(),
//         mapsToken(),
//         returnType()->duplicate< Type >(),
//         rightBraceToken() );

//     EmbracedType::clone( *duplicate );
//     return duplicate;
// }

//
//
// PropertyType
//

PropertyType::PropertyType(
    const IdentifierPath::Ptr& name, const Token::Ptr& markToken, const ValueLiteral::Ptr& size )
: Type( Node::ID::PROPERTY_TYPE, name )
, m_size( size )
, m_markToken( markToken )
{
}

const ValueLiteral::Ptr& PropertyType::size( void ) const
{
    return m_size;
}

const Token::Ptr& PropertyType::markToken( void ) const
{
    return m_markToken;
}

std::string PropertyType::signature( void ) const
{
    std::stringstream stream;

    // const auto& property = *size();

    // if( not type() )
    // {
    //     stream << name()->baseName() << "'";

    //     if( property.id() == Node::ID::DIRECT_CALL_EXPRESSION )
    //     {
    //         const auto& directCallExpression =
    //             static_cast< const DirectCallExpression& >( property );
    //         stream << directCallExpression.identifier()->path();
    //     }
    //     else if( property.id() == Node::ID::VALUE_LITERAL and property.type()->isInteger() )
    //     {
    //         const auto& valueLiteral = static_cast< const ValueLiteral& >( property );
    //         stream << valueLiteral.toString();
    //     }
    //     else if( property.id() == Node::ID::RANGE_LITERAL )
    //     {
    //         const auto& rangeLiteral = static_cast< const RangeLiteral& >( property );
    //         stream << "[";

    //         auto lhs = rangeLiteral.left();
    //         if( lhs->id() == Node::ID::UNARY_EXPRESSION )
    //         {
    //             const auto& lhsUnaryExpression = static_cast< const UnaryExpression& >( *lhs );
    //             lhs = lhsUnaryExpression.expression();
    //             if( lhsUnaryExpression.operationToken()->token() == Grammar::Token::MINUS )
    //             {
    //                 stream << "-";
    //             }
    //         }
    //         if( lhs->id() == Node::ID::VALUE_LITERAL and lhs->type()->isInteger() )
    //         {
    //             const auto& valueLiteral = static_cast< const ValueLiteral& >( *lhs );
    //             stream << valueLiteral.toString();
    //         }
    //         else
    //         {
    //             stream << "?";
    //         }

    //         stream << "..";

    //         auto rhs = rangeLiteral.right();
    //         if( rhs->id() == Node::ID::UNARY_EXPRESSION )
    //         {
    //             const auto& rhsUnaryExpression = static_cast< const UnaryExpression& >( *rhs );
    //             rhs = rhsUnaryExpression.expression();
    //             if( rhsUnaryExpression.operationToken()->token() == Grammar::Token::MINUS )
    //             {
    //                 stream << "-";
    //             }
    //         }
    //         if( rhs->id() == Node::ID::VALUE_LITERAL and rhs->type()->isInteger() )
    //         {
    //             const auto& valueLiteral = static_cast< const ValueLiteral& >( *rhs );
    //             stream << valueLiteral.toString();
    //         }
    //         else
    //         {
    //             stream << "?";
    //         }

    //         stream << "]";
    //     }
    //     else
    //     {
    //         stream << "?";
    //     }
    // }
    // else
    // {
    //     stream << name()->baseDir();
    //     stream << type()->description();
    // }
    stream << "?TODO?";

    return stream.str();
}

void PropertyType::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
//
// MappingType
//

MappingType::MappingType(
    const Types::Ptr& argumentTypes, const Token::Ptr& mapsToken, const Type::Ptr& returnType )
: Type(
      Node::ID::MAPPING_TYPE,
      IdentifierPath::fromIdentifier(
          CST::make< CST::Identifier >( mapsToken->sourceLocation(), "" ) ) )
, m_argumentTypes( argumentTypes )
, m_returnType( returnType )
, m_mapsToken( mapsToken )
{
}

const Types::Ptr& MappingType::argumentTypes( void ) const
{
    return m_argumentTypes;
}

const Type::Ptr& MappingType::returnType( void ) const
{
    return m_returnType;
}

const Token::Ptr& MappingType::mapsToken( void ) const
{
    return m_mapsToken;
}

std::string MappingType::signature( void ) const
{
    std::stringstream stream;

    for( const auto& subType : *argumentTypes() )
    {
        stream << subType->signature() << " * ";
    }

    if( argumentTypes()->size() > 0 )
    {
        stream.seekp( -2, stream.cur );
    }

    stream << "-> " << returnType()->signature();
    return stream.str();
}

void MappingType::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

// //
// //
// // VaradicType
// //

// VaradicType::VaradicType( const Identifier::Ptr& identifier, const Token::Ptr& dotdotdotToken )
// : Type( Node::ID::VARADIC_TYPE, IdentifierPath::fromIdentifier( identifier ) )
// , m_dotdotdotToken( dotdotdotToken )
// {
// }

// const Token::Ptr& VaradicType::dotdotdotToken( void ) const
// {
//     return m_dotdotdotToken;
// }

// std::string VaradicType::signature( void ) const
// {
//     return name()->path() + "...";
// }

// void VaradicType::accept( Visitor& visitor )
// {
//     visitor.visit( *this );
// }

// Node::Ptr VaradicType::clone( void ) const
// {
//     auto duplicate = std::make_shared< VaradicType >(
//         name()->identifiers()->front()->duplicate< Identifier >(), dotdotdotToken() );

//     Type::clone( *duplicate );
//     return duplicate;
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
