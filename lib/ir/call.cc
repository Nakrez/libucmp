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

#include <ucmp/ir/call.hh>

using namespace ucmp;
using namespace ir;

Call::Call(Function* f)
    : Instruction(f->return_type_get(), CALL)
    , fun_(f)
{}

Call::Call(Function* f, const std::vector<Value*>& args)
    : Instruction(f->return_type_get(), CALL)
    , fun_(f)
    , args_(args)
{}

Value* Call::operand_get(unsigned index) const
{
    if (!index)
        return fun_;

    if (index - 1 < args_.size())
        return args_.at(index - 1);

    return nullptr;
}
