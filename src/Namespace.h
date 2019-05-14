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

#ifndef _LIBSCOD_NAMESPACE_H_
#define _LIBSCOD_NAMESPACE_H_

// #include <libscod/ast/Definition>

#include <unordered_set>

namespace libscod
{
    /**
       @extends Scod
     */
    class Namespace
    {
      public:
        // using Ptr = std::shared_ptr< Namespace >;

        static const std::string& delimiter( void );

        //   enum class Visibility
        //   {
        //       Internal,
        //       External,
        //   };

        //   using Linkage = std::pair< Namespace::Ptr, Visibility >;

        //   using Symbol = std::pair< AST::Definition::Ptr, u1 >;

        // public:
        //   explicit Namespace( void );

        //   void registerSymbol( const std::string& name, const AST::Definition::Ptr& definition );

        //   void replaceSymbol( const std::string& name, const AST::Definition::Ptr& definition );

        //   void registerNamespace(
        //       const std::string& name,
        //       const Namespace::Ptr& _namespace,
        //       const Visibility visibility = Visibility::Internal );

        //   /**
        //    * Searches for a symbol with identifier @p path.
        //    *
        //    * @return The symbol consisting of definition pointer (nullptr if absent) and
        //    accessible
        //    * flag.
        //    */
        //   Symbol findSymbol( const AST::IdentifierPath& path ) const;

        //   /**
        //    * Searches for a symbol named @p name in the current namespace.
        //    *
        //    * @return The symbol or nullptr if absent.
        //    */
        //   AST::Definition::Ptr findSymbol( const std::string& name ) const;

        //   /**
        //    * Searches for a sub-namespace named @p name in the current namespace.
        //    *
        //    * @return The sub-namespace or nullptr if absent.
        //    */
        //   Namespace::Ptr findNamespace( const std::string& name ) const;

        //   Namespace::Ptr findNamespace( const AST::IdentifierPath& path ) const;

        //   const std::unordered_map< std::string, AST::Definition::Ptr >& symbols( void ) const;

        //   const std::unordered_map< std::string, Linkage >& namespaces( void ) const;

        //   u1 empty( void ) const;

        //   void registerTypeDefinition( AST::TypeDefinition& node );

        //   std::string dump( const std::string& indention = "" ) const;

        // private:
        //   Namespace::Symbol findSymbol(
        //       const std::string* path, const std::size_t size, const u1 externalImport ) const;

        //   std::string dump(
        //       const std::string& indention, std::unordered_set< const Namespace* >& stack )
        //       const;

        // private:
        //   std::unordered_map< std::string, AST::Definition::Ptr > m_symbols;

        //   std::unordered_map< std::string, Linkage > m_namespaces;
    };
}

#endif  // _LIBSCOD_NAMESPACE_H_

//
//  Local variables:
//  mode: c++
//  indent-tabs-mode: nil
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//
