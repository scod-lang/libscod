//
//  Copyright (C) 2019 SCOD Organization <https://scod-lang.org>
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

#include "CstDumpPass.h"

#include "../various/GrammarToken.h"

#include <libscod/Logger>
#include <libscod/cst/Visitor>
#include <libscod/transform/SourceToCstPass>

#include <libpass/PassRegistry>
#include <libpass/PassResult>
#include <libpass/PassUsage>

#include <libstdhl/File>

#include <fstream>
#include <iostream>
#include <stack>

using namespace libscod;
using namespace CST;

char CstDumpPass::id = 0;

static libpass::PassRegistration< CstDumpPass > PASS(
    "CstDumpPass",
    "generates DOT graph of the CST and dumps to specified output path",
    "cst-dump",
    0 );

namespace libscod
{
    namespace CST
    {
        class CSTDumpDotVisitor final : public RecursiveVisitor
        {
          private:
            class DotLink
            {
              public:
                DotLink( CSTDumpDotVisitor* visitor, void* node )
                : m_visitor( visitor )
                {
                    if( not visitor->m_parentNodes.empty() )
                    {
                        auto parentNode = visitor->m_parentNodes.top();
                        visitor->dumpLink( parentNode, node );
                    }
                    visitor->m_parentNodes.push( node );
                }

                ~DotLink( void )
                {
                    m_visitor->m_parentNodes.pop();
                }

              private:
                CSTDumpDotVisitor* m_visitor;
            };

          public:
            CSTDumpDotVisitor(
                std::ostream& stream,
                const std::string& name,
                const std::string& location,
                const u1 dumpSpan );

            void setDumpNodeLocation( u1 dumpNodeLocation );

            void visit( Root& node ) override;

            void visit( HeaderDefinition& node ) override;
            void visit( MemoryDefinition& node ) override;
            void visit( RegisterDefinition& node ) override;
            void visit( FieldDefinition& node ) override;
            void visit( FormatDefinition& node ) override;
            void visit( BufferDefinition& node ) override;
            void visit( InstructionDefinition& node ) override;
            void visit( OptionDefinition& node ) override;
            void visit( EnumerationDefinition& node ) override;
            void visit( UsingDefinition& node ) override;
            void visit( VariableDefinition& node ) override;

            void visit( UnresolvedOption& node ) override;
            void visit( DecodingOption& node ) override;
            void visit( SyntaxOption& node ) override;
            void visit( ExpansionOption& node ) override;

            void visit( SkipStatement& node ) override;
            void visit( BlockStatement& node ) override;
            void visit( LetStatement& node ) override;
            void visit( AssignmentStatement& node ) override;
            void visit( ConditionalStatement& node ) override;

            void visit( EmbracedExpression& node ) override;
            void visit( NamedExpression& node ) override;
            void visit( MappedExpression& node ) override;
            void visit( DirectCallExpression& node ) override;
            void visit( UnaryExpression& node ) override;
            void visit( BinaryExpression& node ) override;

            void visit( ValueLiteral& node ) override;
            void visit( SetLiteral& node ) override;
            void visit( RecordLiteral& node ) override;
            void visit( MappingLiteral& node ) override;
            void visit( ReferenceLiteral& node ) override;
            void visit( GrammarLiteral& node ) override;

            void visit( UnresolvedType& node ) override;
            void visit( BasicType& node ) override;
            void visit( PropertyType& node ) override;
            void visit( MappingType& node ) override;

            void visit( BasicAttribute& node ) override;
            void visit( ExpressionAttribute& node ) override;

            void visit( VariableBinding& node ) override;
            void visit( Identifier& node ) override;
            void visit( IdentifierPath& node ) override;
            void visit( Token& node ) override;
            void visit( Span& node ) override;

          private:
            void dumpNode( const Node& node, const std::string& name = "" );
            void dumpLabel( const Node& node );
            void dumpLink( void* from, void* to );

          private:
            std::ostream& m_stream;
            const std::string m_name;
            const std::string m_location;
            const u1 m_dumpSpan;
            std::stack< void* > m_parentNodes; /**< holds the parent nodes of DotLink */
            u1 m_dumpNodeLocation = false;     /**< dump node source code location */
        };
    }
}

CSTDumpDotVisitor::CSTDumpDotVisitor(
    std::ostream& stream, const std::string& name, const std::string& location, const u1 dumpSpan )
: m_stream( stream )
, m_name( name )
, m_location( location )
, m_dumpSpan( dumpSpan )
, m_parentNodes()
, m_dumpNodeLocation( false )
{
}

void CSTDumpDotVisitor::setDumpNodeLocation( u1 dumpNodeLocation )
{
    m_dumpNodeLocation = dumpNodeLocation;
}

void CSTDumpDotVisitor::visit( Root& node )
{
    m_stream << "digraph \"CST\" {\n";
    m_stream << "subgraph \"" << m_name << "\" {\n"
             << "\"" << &node << "\" [label=\"Specification\n"
             << m_name << "\n"
             << m_location << "\"];\n";

    {
        DotLink link( this, &node );
        RecursiveVisitor::visit( node );
    }

    m_stream << "}\n";
    m_stream << "}\n";
}

void CSTDumpDotVisitor::visit( HeaderDefinition& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void CSTDumpDotVisitor::visit( MemoryDefinition& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void CSTDumpDotVisitor::visit( RegisterDefinition& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void CSTDumpDotVisitor::visit( FieldDefinition& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void CSTDumpDotVisitor::visit( FormatDefinition& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void CSTDumpDotVisitor::visit( BufferDefinition& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void CSTDumpDotVisitor::visit( InstructionDefinition& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void CSTDumpDotVisitor::visit( OptionDefinition& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void CSTDumpDotVisitor::visit( EnumerationDefinition& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void CSTDumpDotVisitor::visit( UsingDefinition& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void CSTDumpDotVisitor::visit( VariableDefinition& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void CSTDumpDotVisitor::visit( UnresolvedOption& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void CSTDumpDotVisitor::visit( DecodingOption& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void CSTDumpDotVisitor::visit( SyntaxOption& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void CSTDumpDotVisitor::visit( ExpansionOption& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void CSTDumpDotVisitor::visit( SkipStatement& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void CSTDumpDotVisitor::visit( BlockStatement& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void CSTDumpDotVisitor::visit( LetStatement& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void CSTDumpDotVisitor::visit( AssignmentStatement& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void CSTDumpDotVisitor::visit( ConditionalStatement& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void CSTDumpDotVisitor::visit( EmbracedExpression& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void CSTDumpDotVisitor::visit( NamedExpression& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void CSTDumpDotVisitor::visit( MappedExpression& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void CSTDumpDotVisitor::visit( DirectCallExpression& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void CSTDumpDotVisitor::visit( UnaryExpression& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void CSTDumpDotVisitor::visit( BinaryExpression& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void CSTDumpDotVisitor::visit( ValueLiteral& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void CSTDumpDotVisitor::visit( SetLiteral& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void CSTDumpDotVisitor::visit( RecordLiteral& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void CSTDumpDotVisitor::visit( MappingLiteral& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void CSTDumpDotVisitor::visit( ReferenceLiteral& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void CSTDumpDotVisitor::visit( GrammarLiteral& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void CSTDumpDotVisitor::visit( UnresolvedType& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void CSTDumpDotVisitor::visit( BasicType& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void CSTDumpDotVisitor::visit( PropertyType& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void CSTDumpDotVisitor::visit( MappingType& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void CSTDumpDotVisitor::visit( BasicAttribute& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void CSTDumpDotVisitor::visit( ExpressionAttribute& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void CSTDumpDotVisitor::visit( VariableBinding& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void CSTDumpDotVisitor::visit( Identifier& node )
{
    DotLink link( this, &node );
    dumpNode( node, "\n" + node.name() );
    RecursiveVisitor::visit( node );
}

void CSTDumpDotVisitor::visit( IdentifierPath& node )
{
    DotLink link( this, &node );
    dumpNode( node, "\n" + node.path() );
    RecursiveVisitor::visit( node );
}

void CSTDumpDotVisitor::visit( Token& node )
{
    if( node.token() != Grammar::Token::UNRESOLVED )
    {
        DotLink link( this, &node );
        dumpNode( node, "\n" + node.tokenString() );
        RecursiveVisitor::visit( node );
    }
}

void CSTDumpDotVisitor::visit( Span& node )
{
    if( m_dumpSpan )
    {
        DotLink link( this, &node );
        dumpNode( node, "\n" + node.kindName() + " " + std::to_string( node.length() ) );
        RecursiveVisitor::visit( node );
    }
}

void CSTDumpDotVisitor::dumpNode( const Node& node, const std::string& name )
{
    m_stream << "\"" << &node << "\" [label=\"";

    m_stream << node.description() << name;

    dumpLabel( node );

    m_stream << "\"";

    if( node.id() == Node::ID::TOKEN )
    {
        m_stream << " shape=box";
    }

    m_stream << "];\n";
}

void CSTDumpDotVisitor::dumpLabel( const Node& node )
{
    if( m_dumpNodeLocation )
    {
        m_stream << "\n" << node.sourceLocation();
    }
}

void CSTDumpDotVisitor::dumpLink( void* from, void* to )
{
    m_stream << "\"" << from << "\" -> \"" << to << "\";\n";
}

void CstDumpPass::usage( libpass::PassUsage& pu )
{
    pu.require< SourceToCstPass >();
}

u1 CstDumpPass::run( libpass::PassResult& pr )
{
    Logger log( &id, stream() );

    const auto& data = pr.output< SourceToCstPass >();
    const auto& specification = data->specification();

    const u1 dumpNodeLocation = true;  // TODO: add command-line switch

    const auto printDotGraph = [ & ]( std::ostream& out ) {
        CSTDumpDotVisitor visitor{
            out, specification->name(), specification->location()->toString(), dumpSpan()
        };
        visitor.setDumpNodeLocation( dumpNodeLocation );
        specification->cst()->accept( visitor );
    };

    if( outputPath() == "" )
    {
        log.debug( "writing dot graph to 'stdout'" );
        printDotGraph( std::cout );
    }
    else
    {
        const auto previousPass = libpass::PassRegistry::passInfo( pr.previousPass() );
        const std::string outputFile = specification->name() + "." + previousPass.name() + ".dot";

        if( not libstdhl::File::Path::exists( outputPath() ) )
        {
            try
            {
                libstdhl::File::Path::create( outputPath() );
            }
            catch( const std::domain_error& e )
            {
                log.error( e.what() );
            }
        }

        const auto outputFilePath = outputPath() + "/" + outputFile;

        std::ofstream dotFile( outputFilePath );
        if( not dotFile.is_open() )
        {
            log.error( "could not open '" + outputFilePath + "'" );
            return false;
        }

        log.debug( "writing dot graph to '" + outputFilePath + "'" );
        printDotGraph( dotFile );
    }

    return true;
}

void CstDumpPass::setOutputPath( const std::string& outputPath )
{
    m_outputPath = outputPath;
}

const std::string& CstDumpPass::outputPath( void ) const
{
    return m_outputPath;
}

void CstDumpPass::setDumpSpan( const u1 enable )
{
    m_dumpSpan = enable;
}

u1 CstDumpPass::dumpSpan( void ) const
{
    return m_dumpSpan;
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
