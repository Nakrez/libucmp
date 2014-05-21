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

#include <ucmp/ir/value-map.hh>
#include <ucmp/ir/value.hh>

using namespace ucmp;
using namespace ir;

ValueMap::ValueMap()
    : map_()
    , counter_(0)
{}

ValueMap::~ValueMap()
{}

void ValueMap::insert_name(Value* v, const misc::Symbol& name)
{
    misc::Symbol n = name;

    if (n == "")
    {
        if (v->type_get()->type_get() == Type::LabelTy)
            n = "l";
        else
            n = "t";
    }
    else if (map_[n] == nullptr)
    {
        map_[n] = v;
        v->name_ = n;

        return;
    }

    std::string str;

    while (1)
    {
        str = n.data_get();

        str += std::to_string(counter_++);

        if (map_[str] == nullptr)
        {
            map_[str] = v;
            v->name_ = str;
            break;
        }
    }
}

Value* ValueMap::get(const misc::Symbol& name)
{
    auto it = map_.find(name);

    if (it == map_.end())
        return nullptr;

    return it->second;
}
