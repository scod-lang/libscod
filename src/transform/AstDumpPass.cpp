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

#include "AstDumpPass.h"

#include <libscod/Logger>
#include <libscod/ast/Visitor>
#include <libscod/transform/CstToAstPass>

#include <libpass/PassRegistry>
#include <libpass/PassResult>
#include <libpass/PassUsage>

#include <libstdhl/File>

#include <fstream>
#include <iostream>
#include <stack>

using namespace libscod;
using namespace AST;

char AstDumpPass::id = 0;

static libpass::PassRegistration< AstDumpPass > PASS(
    "AstDumpPass",
    "generates DOT graph of the AST and dumps to specified output path",
    "ast-dump",
    0 );

namespace libscod
{
    namespace AST
    {
        class AstDumpVisitor final : public RecursiveVisitor
        {
          private:
            class DotLink
            {
              public:
                DotLink( AstDumpVisitor* visitor, void* node )
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
                AstDumpVisitor* m_visitor;
            };

          public:
            AstDumpVisitor(
                std::ostream& stream,
                const std::string& name,
                const std::string& location,
                const u1 dumpSpan );

            void setDumpNodeLocation( u1 dumpNodeLocation );

            void visit( Root& node ) override;

            void visit( MemoryDefinition& node ) override;
            void visit( RegisterDefinition& node ) override;
            void visit( FieldDefinition& node ) override;
            void visit( FormatDefinition& node ) override;
            void visit( BufferDefinition& node ) override;
            void visit( InstructionDefinition& node ) override;
            void visit( MicroProcessorDefinition& node ) override;
            void visit( CacheDefinition& node ) override;
            void visit( InterconnectDefinition& node ) override;
            void visit( OptionDefinition& node ) override;
            void visit( EnumerationDefinition& node ) override;
            void visit( UsingDefinition& node ) override;
            void visit( VariableDefinition& node ) override;

            void visit( UnresolvedOption& node ) override;
            void visit( DecodingOption& node ) override;
            void visit( SyntaxOption& node ) override;
            void visit( ExpansionOption& node ) override;
            void visit( StageOption& node ) override;

            void visit( SkipStatement& node ) override;
            void visit( BlockStatement& node ) override;
            void visit( CallStatement& node ) override;
            void visit( LetStatement& node ) override;
            void visit( AssignmentStatement& node ) override;
            void visit( ConditionalStatement& node ) override;

            void visit( NamedExpression& node ) override;
            void visit( MappedExpression& node ) override;
            void visit( LetExpression& node ) override;
            void visit( ConditionalExpression& node ) override;
            void visit( DirectCallExpression& node ) override;
            void visit( MethodCallExpression& node ) override;
            void visit( UnaryExpression& node ) override;
            void visit( BinaryExpression& node ) override;

            void visit( ValueLiteral& node ) override;
            void visit( SetLiteral& node ) override;
            void visit( ListLiteral& node ) override;
            void visit( RangeLiteral& node ) override;
            void visit( RecordLiteral& node ) override;
            void visit( MappingLiteral& node ) override;
            void visit( ReferenceLiteral& node ) override;
            void visit( GrammarLiteral& node ) override;

            void visit( UnresolvedType& node ) override;
            void visit( BasicType& node ) override;
            void visit( PropertyType& node ) override;
            void visit( MappingType& node ) override;

            void visit( VariableBinding& node ) override;
            void visit( Identifier& node ) override;
            void visit( IdentifierPath& node ) override;

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

AstDumpVisitor::AstDumpVisitor(
    std::ostream& stream, const std::string& name, const std::string& location, const u1 dumpSpan )
: m_stream( stream )
, m_name( name )
, m_location( location )
, m_dumpSpan( dumpSpan )
, m_parentNodes()
, m_dumpNodeLocation( false )
{
}

void AstDumpVisitor::setDumpNodeLocation( u1 dumpNodeLocation )
{
    m_dumpNodeLocation = dumpNodeLocation;
}

void AstDumpVisitor::visit( Root& node )
{
    m_stream << "digraph \"AST\" {\n";
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

void AstDumpVisitor::visit( MemoryDefinition& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void AstDumpVisitor::visit( RegisterDefinition& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void AstDumpVisitor::visit( FieldDefinition& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void AstDumpVisitor::visit( FormatDefinition& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void AstDumpVisitor::visit( BufferDefinition& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void AstDumpVisitor::visit( InstructionDefinition& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void AstDumpVisitor::visit( MicroProcessorDefinition& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void AstDumpVisitor::visit( CacheDefinition& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void AstDumpVisitor::visit( InterconnectDefinition& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void AstDumpVisitor::visit( OptionDefinition& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void AstDumpVisitor::visit( EnumerationDefinition& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void AstDumpVisitor::visit( UsingDefinition& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void AstDumpVisitor::visit( VariableDefinition& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void AstDumpVisitor::visit( UnresolvedOption& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void AstDumpVisitor::visit( DecodingOption& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void AstDumpVisitor::visit( SyntaxOption& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void AstDumpVisitor::visit( ExpansionOption& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void AstDumpVisitor::visit( StageOption& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void AstDumpVisitor::visit( SkipStatement& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void AstDumpVisitor::visit( BlockStatement& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void AstDumpVisitor::visit( CallStatement& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void AstDumpVisitor::visit( LetStatement& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void AstDumpVisitor::visit( AssignmentStatement& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void AstDumpVisitor::visit( ConditionalStatement& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void AstDumpVisitor::visit( NamedExpression& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void AstDumpVisitor::visit( MappedExpression& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void AstDumpVisitor::visit( LetExpression& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void AstDumpVisitor::visit( ConditionalExpression& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void AstDumpVisitor::visit( DirectCallExpression& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void AstDumpVisitor::visit( MethodCallExpression& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void AstDumpVisitor::visit( UnaryExpression& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void AstDumpVisitor::visit( BinaryExpression& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void AstDumpVisitor::visit( ValueLiteral& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void AstDumpVisitor::visit( SetLiteral& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void AstDumpVisitor::visit( ListLiteral& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void AstDumpVisitor::visit( RangeLiteral& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void AstDumpVisitor::visit( RecordLiteral& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void AstDumpVisitor::visit( MappingLiteral& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void AstDumpVisitor::visit( ReferenceLiteral& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void AstDumpVisitor::visit( GrammarLiteral& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void AstDumpVisitor::visit( UnresolvedType& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void AstDumpVisitor::visit( BasicType& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void AstDumpVisitor::visit( PropertyType& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void AstDumpVisitor::visit( MappingType& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void AstDumpVisitor::visit( VariableBinding& node )
{
    DotLink link( this, &node );
    dumpNode( node );
    RecursiveVisitor::visit( node );
}

void AstDumpVisitor::visit( Identifier& node )
{
    DotLink link( this, &node );
    dumpNode( node, "\n" + node.name() );
    RecursiveVisitor::visit( node );
}

void AstDumpVisitor::visit( IdentifierPath& node )
{
    DotLink link( this, &node );
    dumpNode( node, "\n" + node.path() );
    RecursiveVisitor::visit( node );
}

void AstDumpVisitor::dumpNode( const Node& node, const std::string& name )
{
    m_stream << "\"" << &node << "\" [label=\"";

    m_stream << node.description() << name;

    dumpLabel( node );

    m_stream << "\"";

    m_stream << "];\n";
}

void AstDumpVisitor::dumpLabel( const Node& node )
{
    if( m_dumpNodeLocation )
    {
        m_stream << "\n" << node.sourceLocation();
    }
}

void AstDumpVisitor::dumpLink( void* from, void* to )
{
    m_stream << "\"" << from << "\" -> \"" << to << "\";\n";
}

void AstDumpPass::usage( libpass::PassUsage& pu )
{
    pu.require< CstToAstPass >();
}

u1 AstDumpPass::run( libpass::PassResult& pr )
{
    Logger log( &id, stream() );

    const auto& data = pr.output< CstToAstPass >();
    const auto& specification = data->specification();

    const u1 dumpNodeLocation = true;  // TODO: add command-line switch

    const auto printDotGraph = [ & ]( std::ostream& out ) {
        AstDumpVisitor visitor{
            out, specification->name(), specification->location()->toString(), dumpSpan()
        };
        visitor.setDumpNodeLocation( dumpNodeLocation );
        specification->ast()->accept( visitor );
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

void AstDumpPass::setOutputPath( const std::string& outputPath )
{
    m_outputPath = outputPath;
}

const std::string& AstDumpPass::outputPath( void ) const
{
    return m_outputPath;
}

void AstDumpPass::setDumpSpan( const u1 enable )
{
    m_dumpSpan = enable;
}

u1 AstDumpPass::dumpSpan( void ) const
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
