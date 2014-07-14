/*
Copyright (C) 2014 Baptiste Covolato <b.covolato@gmail.com>

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#ifndef UCMP_LINK_IMPORTER_HH
# define UCMP_LINK_IMPORTER_HH

# include <ucmp/link/core/link-context.hh>

namespace ucmp
{
    namespace link
    {
        class Importer
        {
            public:
                Importer() = default;
                virtual ~Importer() = default;

                virtual bool parse_file(LinkContext& lc,
                                        const std::string& path) = 0;
        };
    } // namespace link
} // namespace ucmp

#endif /* !UCMP_LINK_IMPORTER_HH */
