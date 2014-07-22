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

#ifndef UCMP_LINK_FILE_HH
# define UCMP_LINK_FILE_HH

# include <string>
# include <map>
# include <memory>

# include <ucmp/link/core/fragment.hh>
# include <ucmp/link/core/symbol-table.hh>

namespace ucmp
{
    namespace link
    {
        class File
        {
            public:
                enum FileKind
                {
                    Object,
                    StaticLib,
                    DynLib,
                };

            public:
                File(FileKind fk);
                ~File() = default;

                FileKind kind_get() const { return kind_; }

                const SymbolTable& sym_tab_get() const { return st_; }
                SymbolTable& sym_tab_get() { return st_; }

                void add_frag(Fragment* f)
                {
                    frags_[f->name_get()] = std::unique_ptr<Fragment> (f);
                }

            protected:
                FileKind kind_;
                std::map<misc::Symbol, std::unique_ptr<Fragment>> frags_;
                SymbolTable st_;
        };
    } // namespace link
} // namespace ucmp

#endif /* !FILE_HH */
