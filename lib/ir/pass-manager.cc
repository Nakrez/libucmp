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

#include <ucmp/ir/pass-manager.hh>

using namespace ucmp;
using namespace ir;

void UnitPassManager::run(Unit& u)
{
    auto it = passes_.begin();
    auto end = passes_.end();

    for (; it != end; ++it)
        (*it)->run_on_unit(u);
}

void FunctionPassManager::run(Function& f)
{
    auto it = passes_.begin();
    auto end = passes_.end();

    for (; it != end; ++it)
        (*it)->run_on_function(f);
}
