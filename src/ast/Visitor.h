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

#ifndef _LIBSCOD_AST_VISITOR_H_
#define _LIBSCOD_AST_VISITOR_H_

namespace libscod
{
    namespace AST
    {
        class Root;

        class MemoryDefinition;
        class RegisterDefinition;
        class FieldDefinition;
        class FormatDefinition;
        class BufferDefinition;
        class InstructionDefinition;
        class MicroProcessorDefinition;
        class CacheDefinition;
        class InterconnectDefinition;
        class OptionDefinition;
        class EnumerationDefinition;
        class UsingDefinition;
        class VariableDefinition;

        class UnresolvedOption;
        class DecodingOption;
        class SyntaxOption;
        class ExpansionOption;
        class StageOption;

        class SkipStatement;
        class BlockStatement;
        class CallStatement;
        class LetStatement;
        class AssignmentStatement;
        class ConditionalStatement;

        class NamedExpression;
        class MappedExpression;
        class LetExpression;
        class ConditionalExpression;
        class DirectCallExpression;
        class MethodCallExpression;
        class UnaryExpression;
        class BinaryExpression;

        class ValueLiteral;
        class SetLiteral;
        class ListLiteral;
        class RangeLiteral;
        class RecordLiteral;
        class MappingLiteral;
        class ReferenceLiteral;
        class GrammarLiteral;

        class UnresolvedType;
        class BasicType;
        class PropertyType;
        class MappingType;

        class VariableBinding;
        class Identifier;
        class IdentifierPath;

        /**
         * @extends Scod
         */
        class Visitor
        {
          public:
            virtual ~Visitor( void ) = default;

            virtual void visit( Root& node ) = 0;

            virtual void visit( MemoryDefinition& node ) = 0;
            virtual void visit( RegisterDefinition& node ) = 0;
            virtual void visit( FieldDefinition& node ) = 0;
            virtual void visit( FormatDefinition& node ) = 0;
            virtual void visit( BufferDefinition& node ) = 0;
            virtual void visit( InstructionDefinition& node ) = 0;
            virtual void visit( MicroProcessorDefinition& node ) = 0;
            virtual void visit( CacheDefinition& node ) = 0;
            virtual void visit( InterconnectDefinition& node ) = 0;
            virtual void visit( OptionDefinition& node ) = 0;
            virtual void visit( EnumerationDefinition& node ) = 0;
            virtual void visit( UsingDefinition& node ) = 0;
            virtual void visit( VariableDefinition& node ) = 0;

            virtual void visit( UnresolvedOption& node ) = 0;
            virtual void visit( DecodingOption& node ) = 0;
            virtual void visit( SyntaxOption& node ) = 0;
            virtual void visit( ExpansionOption& node ) = 0;
            virtual void visit( StageOption& node ) = 0;

            virtual void visit( SkipStatement& node ) = 0;
            virtual void visit( BlockStatement& node ) = 0;
            virtual void visit( CallStatement& node ) = 0;
            virtual void visit( LetStatement& node ) = 0;
            virtual void visit( AssignmentStatement& node ) = 0;
            virtual void visit( ConditionalStatement& node ) = 0;

            virtual void visit( NamedExpression& node ) = 0;
            virtual void visit( MappedExpression& node ) = 0;
            virtual void visit( LetExpression& node ) = 0;
            virtual void visit( ConditionalExpression& node ) = 0;
            virtual void visit( DirectCallExpression& node ) = 0;
            virtual void visit( MethodCallExpression& node ) = 0;
            virtual void visit( UnaryExpression& node ) = 0;
            virtual void visit( BinaryExpression& node ) = 0;

            virtual void visit( ValueLiteral& node ) = 0;
            virtual void visit( SetLiteral& node ) = 0;
            virtual void visit( ListLiteral& node ) = 0;
            virtual void visit( RangeLiteral& node ) = 0;
            virtual void visit( RecordLiteral& node ) = 0;
            virtual void visit( MappingLiteral& node ) = 0;
            virtual void visit( ReferenceLiteral& node ) = 0;
            virtual void visit( GrammarLiteral& node ) = 0;

            virtual void visit( UnresolvedType& node ) = 0;
            virtual void visit( BasicType& node ) = 0;
            virtual void visit( PropertyType& node ) = 0;
            virtual void visit( MappingType& node ) = 0;

            virtual void visit( VariableBinding& node ) = 0;
            virtual void visit( Identifier& node ) = 0;
            virtual void visit( IdentifierPath& node ) = 0;
        };

        class RecursiveVisitor : public Visitor
        {
          public:
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
        };

        class EmptyVisitor : public Visitor
        {
          public:
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
        };
    }
}

#endif  // _LIBSCOD_AST_VISITOR_H_

//
//  Local variables:
//  mode: c++
//  indent-tabs-mode: nil
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//
