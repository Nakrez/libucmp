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

#include <cassert>

#include <ucmp/ir/store.hh>

#include <iostream>
using namespace ucmp;
using namespace ir;

Store::Store(sType t, Value* v, Value* mem)
    : Instruction(t, STORE)
    , val_(v)
    , mem_(mem)
{
    assert(mem->type_get()->type_get() == Type::PtrTy &&
           "Memory operand of store MUST have a pointer type");
}

Value* Store::operand_get(int index) const
{
    if (!index)
        return val_;

    if (index == 1)
        return mem_;

    return nullptr;
}
