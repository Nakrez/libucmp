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

#ifndef UCMP_LINK_FRAGMENT_HH
# define UCMP_LINK_FRAGMENT_HH

# include <ucmp/misc/symbol.hh>

namespace ucmp
{
    namespace link
    {
        class Fragment
        {
            public:
                Fragment(const misc::Symbol& name,
                         const char* data,
                         unsigned size);
                ~Fragment();

                const misc::Symbol& name_get() { return name_; }

                const char* data_get() const { return data_; }
                char* data_get() { return data_; }

                unsigned size_get() const { return size_; }

            private:
                misc::Symbol name_;
                char* data_;
                unsigned size_;
        };
    } // namespace link
} // namespace ucmp

#endif /* !UCMP_LINK_FRAGMENT_HH */
