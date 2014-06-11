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

#include <ucmp/misc/indent.hh>
#include <ucmp/ir/function.hh>
#include <ucmp/ir/unit.hh>

using namespace ucmp;
using namespace ir;

#include <iostream>
Function::Function(FunctionType* t, const misc::Symbol& name, Unit* u)
    : GlobalValue(sType(t))
    , f_type_(t)
    , args_()
    , blocks_()
    , vmap_()
    , parent_(u)
{
    if (u)
        u->functions_get().push_back(this);

    name_set(name);

    // Setup arguments for the function
    for (auto it = t->begin(); it != t->end(); ++it)
        arg_add(*it);
}

Function::~Function()
{
    for (auto b : blocks_)
        delete b;
}
