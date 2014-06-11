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

#include <ucmp/ir/value.hh>
#include <ucmp/ir/function.hh>
#include <ucmp/ir/unit.hh>
#include <ucmp/ir/basic-block.hh>
#include <ucmp/ir/instruction.hh>

using namespace ucmp;
using namespace ir;

Value::Value(sType t)
    : type_(t)
    , name_("")
{}

void Value::name_set(const misc::Symbol& n)
{
    ValueMap* vmap = get_value_map();

    if (!vmap)
        return;

    vmap->insert_name(this, n);
}

ValueMap* Value::get_value_map()
{
    if (Instruction* i = dynamic_cast<Instruction*> (this))
    {
        if (BasicBlock* bb = i->parent_get())
        {
            if (Function* f = bb->parent_get())
                return &f->value_map_get();
        }
    }
    else if (Function* f = dynamic_cast<Function*> (this))
    {
        if (Unit* u = f->parent_get())
            return &u->value_map_get();
    }
    else if (Argument* a = dynamic_cast<Argument*> (this))
    {
        if (Function* f = a->parent_get())
            return &f->value_map_get();
    }

    return nullptr;
}
