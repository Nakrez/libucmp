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

#include <ucmp/ir/binary-inst.hh>

using namespace ucmp;
using namespace ir;

BinaryInst::BinaryInst(BinOp op, sType type, Value* op1, Value* op2)
    : Instruction(type, BINOP)
    , op_(op)
    , op1_(op1)
    , op2_(op2)
{}

BinaryInst::~BinaryInst()
{}

Value* BinaryInst::operand_get(int index) const
{
    if (!index)
        return op1_;
    else if (index == 1)
        return op2_;
    else
        return nullptr;
}

std::string BinaryInst::type_to_str() const
{
    switch (op_)
    {
        case ADD:
            return "add";
        case SUB:
            return "sub";
        case MUL:
            return "mul";
        case DIV:
            return "div";
        case MOD:
            return "mod";
        case XOR:
            return "xor";
    }

    return "";
}
