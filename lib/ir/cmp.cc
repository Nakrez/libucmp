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

#include <ucmp/ir/cmp.hh>

using namespace ucmp;
using namespace ir;

Cmp::Cmp(CmpOp op, sType t, Value* lvalue, Value* rvalue)
    : Instruction(t, CMP)
    , op_(op)
    , lvalue_(lvalue)
    , rvalue_(rvalue)
{}

Value* Cmp::operand_get(unsigned index) const
{
    if (!index)
        return lvalue_;
    if (index == 1)
        return rvalue_;

    return nullptr;
}

std::string Cmp::type_to_str() const
{
    switch (op_)
    {
        case GT:
            return "cmp gt";
        case GE:
            return "cmp ge";
        case LT:
            return "cmp lt";
        case LE:
            return "cmp le";
        case EQ:
            return "cmp eq";
        case NE:
            return "cmp ne";
    }
}
