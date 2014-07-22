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

#include <ucmp/link/core/symbol.hh>

using namespace ucmp;
using namespace link;

Symbol::Symbol(const misc::Symbol& name,
               uint64_t value,
               uint64_t size,
               const misc::Symbol& frag_name,
               Type type,
               Binding binding)
    : name_(name)
    , frag_name_(frag_name)
    , value_(value)
    , size_(size)
    , type_(type)
    , binding_(binding)
    , undef_(false)
{}

bool Symbol::merge_symbol(const Symbol& sym)
{
    if (sym.binding_get() == B_WEAK)
        return true;

    if (binding_ != B_WEAK)
        return false;

    frag_name_ = sym.frag_name_get();
    value_ = sym.value_get();
    size_ = sym.size_get();
    type_ = sym.type_get();
    binding_ = sym.binding_get();

    return true;
}
