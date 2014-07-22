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

#ifndef UCMP_LINK_SYMBOL_HH
# define UCMP_LINK_SYMBOL_HH

# include <cstdint>

# include <ucmp/misc/symbol.hh>

namespace ucmp
{
    namespace link
    {
        class Symbol
        {
            public:
                enum Type
                {
                    T_NONE,
                    T_OBJ,
                    T_CODE,
                    T_FRAG,
                };

                enum Binding
                {
                    B_NONE,
                    B_GLOBAL,
                    B_LOCAL,
                    B_WEAK,
                };

            public:
                Symbol(const misc::Symbol& name,
                       uint64_t value,
                       uint64_t size,
                       const misc::Symbol& frag_name,
                       Type type,
                       Binding binding);
                ~Symbol() = default;

                const misc::Symbol& name_get() const { return name_; }
                const misc::Symbol& frag_name_get() const
                {
                    return frag_name_;
                }

                uint64_t value_get() const { return value_; }
                uint64_t size_get() const { return size_; }

                Type type_get() const { return type_; }
                Binding binding_get() const { return binding_; }

                bool merge_symbol(const Symbol& sym);

            private:
                misc::Symbol name_;
                misc::Symbol frag_name_;

                // Both stored with 64bits but will be truncated for 32bits
                // by exporter if needed
                uint64_t value_;
                uint64_t size_;

                Type type_;
                Binding binding_;
        };
    } // namespace link
} // namespace ucmp

#endif /* !UCMP_LINK_SYMBOL_HH */
