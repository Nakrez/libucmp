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
#include <ucmp/ir/stack-alloc.hh>
#include <ucmp/ir/store.hh>
#include <ucmp/ir/load.hh>
#include <ucmp/ir/cmp.hh>

using namespace ucmp;
using namespace ir;

IrGenerator::IrGenerator(Context& c)
    : c_(c)
    , bb_(nullptr)
{}

Value* IrGenerator::create_add(Value* l, Value* r, const misc::Symbol& n)
{
    BinaryInst* bi = new BinaryInst(BinaryInst::ADD, l->type_get(), l, r);

    insert(bi, n);

    return bi;
}

Value* IrGenerator::create_sub(Value* l, Value* r, const misc::Symbol& n)
{
    BinaryInst* bi = new BinaryInst(BinaryInst::SUB, l->type_get(), l, r);

    insert(bi, n);

    return bi;
}

Value* IrGenerator::create_mul(Value* l, Value* r, const misc::Symbol& n)
{
    BinaryInst* bi = new BinaryInst(BinaryInst::MUL, l->type_get(), l, r);

    insert(bi, n);

    return bi;
}

Value* IrGenerator::create_div(Value* l, Value* r, const misc::Symbol& n)
{
    BinaryInst* bi = new BinaryInst(BinaryInst::DIV, l->type_get(), l, r);

    insert(bi, n);

    return bi;
}

Value* IrGenerator::create_mod(Value* l, Value* r, const misc::Symbol& n)
{
    BinaryInst* bi = new BinaryInst(BinaryInst::MOD, l->type_get(), l, r);

    insert(bi, n);

    return bi;
}

Value* IrGenerator::create_gt(Value* l, Value* r, const misc::Symbol& n)
{
    Cmp* c = new Cmp(Cmp::GT, c_.i1_ty_get(), l, r);

    insert(c, n);

    return c;
}

Value* IrGenerator::create_ge(Value* l, Value* r, const misc::Symbol& n)
{
    Cmp* c = new Cmp(Cmp::GE, c_.i1_ty_get(), l, r);

    insert(c, n);

    return c;
}

Value* IrGenerator::create_le(Value* l, Value* r, const misc::Symbol& n)
{
    Cmp* c = new Cmp(Cmp::LE, c_.i1_ty_get(), l, r);

    insert(c, n);

    return c;
}

Value* IrGenerator::create_lt(Value* l, Value* r, const misc::Symbol& n)
{
    Cmp* c = new Cmp(Cmp::LT, c_.i1_ty_get(), l, r);

    insert(c, n);

    return c;
}

Value* IrGenerator::create_eq(Value* l, Value* r, const misc::Symbol& n)
{
    Cmp* c = new Cmp(Cmp::EQ, c_.i1_ty_get(), l, r);

    insert(c, n);

    return c;
}

Value* IrGenerator::create_ne(Value* l, Value* r, const misc::Symbol& n)
{
    Cmp* c = new Cmp(Cmp::NE, c_.i1_ty_get(), l, r);

    insert(c, n);

    return c;
}

Value* IrGenerator::create_stack_alloc(sType t, const misc::Symbol& n)
{
    StackAlloc* sa = new StackAlloc(t);

    insert(sa, n);

    return sa;
}

Value* IrGenerator::create_store(Value* val, Value* mem)
{
    Store* s = new Store(c_.void_ty_get(), val, mem);

    insert(s);

    return s;
}

Value* IrGenerator::create_load(Value* mem, const misc::Symbol& n)
{
    Load* l = new Load(mem);

    insert(l, n);

    return l;
}
