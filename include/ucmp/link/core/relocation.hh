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

#ifndef UCMP_LINK_RELOCATION_HH
# define UCMP_LINK_RELOCATION_HH

# include <cstdint>

# include <ucmp/misc/symbol.hh>

namespace ucmp
{
    namespace link
    {
        class Relocation
        {
            public:
                Relocation(const misc::Symbol& name,
                           uint64_t offset,
                           uint32_t type,
                           int64_t addend = 0);
                ~Relocation() = default;

                const misc::Symbol& name_get() const { return name_; }
                uint64_t offset_get() const { return offset_; }
                uint32_t type_get() const { return type_; }
                int64_t addend_get() const { return addend_; }

            private:
                misc::Symbol name_;

                uint64_t offset_;
                uint32_t type_;
                int64_t addend_;
        };
    } // namespace link
} // namespace ucmp

#endif /* !UCMP_LINK_RELOCATION_HH */
