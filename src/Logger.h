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

#ifndef _LIBSCOD_LOGGER_H_
#define _LIBSCOD_LOGGER_H_

#include <libpass/PassLogger>

#include <libstdhl/SourceLocation>

#include <string>
#include <vector>

namespace libscod
{
    class Exception;

    class Logger : public libpass::PassLogger
    {
      public:
        using libpass::PassLogger::PassLogger;

        using libpass::PassLogger::error;
        void error(
            const std::vector< libstdhl::SourceLocation >& locations,
            const std::string& message  // ,
            // Code errorCode = Code::Unspecified
        );
        void error( const Exception& exception );

        using libpass::PassLogger::warning;
        void warning(
            const std::vector< libstdhl::SourceLocation >& locations, const std::string& message );

        using libpass::PassLogger::info;
        void info(
            const std::vector< libstdhl::SourceLocation >& locations, const std::string& message );

        using libpass::PassLogger::hint;
        void hint(
            const std::vector< libstdhl::SourceLocation >& locations, const std::string& message );

        using libpass::PassLogger::debug;
        void debug(
            const std::vector< libstdhl::SourceLocation >& locations, const std::string& message );
    };
}

#endif  // _LIBSCOD_LOGGER_H_

//
//  Local variables:
//  mode: c++
//  indent-tabs-mode: nil
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//
