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

#include <ucmp/ir/ir-generator.hh>

#include <ucmp/ir/binary-inst.hh>
using namespace ucmp;
using namespace ir;

IrGenerator::IrGenerator(Context& c)
    : c_(c)
    , insert_pt_(nullptr)
{}

Value* IrGenerator::create_add(Value* l, Value* r, const misc::Symbol& n)
{
    BinaryInst* bi = new BinaryInst(Instruction::ADD, l->type_get(), l, r);

    insert(bi, n);

    return bi;
}

Value* IrGenerator::create_sub(Value* l, Value* r, const misc::Symbol& n)
{
    BinaryInst* bi = new BinaryInst(Instruction::SUB, l->type_get(), l, r);

    insert(bi, n);

    return bi;
}

Value* IrGenerator::create_mul(Value* l, Value* r, const misc::Symbol& n)
{
    BinaryInst* bi = new BinaryInst(Instruction::MUL, l->type_get(), l, r);

    insert(bi, n);

    return bi;
}
