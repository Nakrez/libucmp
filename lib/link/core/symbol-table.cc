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

#include <ucmp/link/core/symbol-table.hh>

using namespace ucmp;
using namespace link;

const Symbol* SymbolTable::symbol_get(const misc::Symbol& name) const
{
    try
    {
        return table_.at(name).get();
    }
    catch (std::out_of_range&)
    {
        return nullptr;
    }
}

bool SymbolTable::symbol_add(Symbol* sym)
{
    auto ret = table_.insert(std::make_pair(sym->name_get(),
                                            std::shared_ptr<Symbol> (sym)));

    if (ret.second)
        return true;

    bool merge = (*ret.first).second->merge_symbol(*sym);

    delete sym;

    return merge;
}
