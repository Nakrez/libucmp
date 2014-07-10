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

#include <ucmp/ir/instruction.hh>

using namespace ucmp;
using namespace ir;

Instruction::Instruction(sType t, InstType i_type)
    : Value(t)
    , i_type_(i_type)
    , parent_(nullptr)
{}

std::string Instruction::type_to_str() const
{
    switch (i_type_)
    {
        case STACK_ALLOC:
            return "stackalloc";
        case STORE:
            return "store";
        case LOAD:
            return "load";
        case RET:
            return "ret";
        case JUMP:
            return "jump";
        case CJUMP:
            return "cjump";
        case CALL:
            return "call";
        case PHI:
            return "phi";
        case PROMOT:
            return "promot";
        case DEMOT:
            return "demot";
        case CAST:
            return "cast";
        case DATA_PTR:
            return "dataptr";
        default:
            return "";
    }
}
