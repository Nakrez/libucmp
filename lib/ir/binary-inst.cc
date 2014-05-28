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
    : Instruction(type, op)
    , op1_(op1)
    , op2_(op2)
{}

BinaryInst::~BinaryInst()
{}

void BinaryInst::dump(std::ostream& o) const
{
    o << name_get().data_get() << " = ";

    switch (i_type_)
    {
        case ADD:
            o << "add";
            break;
        case SUB:
            o << "sub";
            break;
        case MUL:
            o << "mul";
            break;
        case DIV:
            o << "div";
            break;
        case MOD:
            o << "mod";
            break;
        default:
            break;
    }

    o << " " << *op1_ << ", " << *op2_;
}
