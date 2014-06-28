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

#include <ucmp/ir/ir-writer.hh>
#include <ucmp/ir/int-constant.hh>
#include <ucmp/ir/stack-alloc.hh>
#include <ucmp/ir/call.hh>
#include <ucmp/ir/phi-node.hh>

#include <ucmp/misc/indent.hh>

using namespace ucmp;
using namespace ir;

IrWriter::IrWriter(std::ostream& ostr)
    : ostr_(ostr)
{}

void IrWriter::write_unit(Unit* u)
{
    auto s_it = u->context_get().s_cbegin();
    auto s_end = u->context_get().s_cend();

    for (; s_it != s_end; ++s_it)
    {
        s_it->second->full_dump(ostr_);
        ostr_ << misc::iendl;
    }

    auto f_it = u->fun_cbegin();
    auto f_end = u->fun_cend();

    for (; f_it != f_end; ++f_it)
        write_function(*f_it);
}

void IrWriter::write_function(Function* f)
{
    ostr_ << "function " << *f->return_type_get() << " " << f->name_get();
    ostr_ << "(";

    for (auto it = f->a_cbegin(), begin = it, end = f->a_cend();
         it != end; ++it)
    {
        if (it != begin)
            ostr_ << ", ";

        ostr_ << *(*it)->type_get() << " " << (*it)->name_get();
    }

    ostr_ << ")";

    ostr_ << misc::iendl << "{" << misc::incendl;

    for (auto it = f->f_cbegin(), begin = it; it != f->f_cend(); ++it)
    {
        if (it != begin)
            ostr_ << misc::iendl;

        write_basic_block(*it);
    }

    ostr_ << misc::decendl << "}" << misc::iendl;
}

void IrWriter::write_basic_block(BasicBlock* bb)
{
    ostr_ << bb->name_get() << ":" << misc::incendl;

    for (auto it = bb->begin(), begin = it; it != bb->end(); ++it)
    {
        if (it != begin)
            ostr_ << misc::iendl;

        write_instruction(*it);
    }

    ostr_ << misc::decindent;
}

void IrWriter::write_instruction(Instruction* i)
{

    if (i->name_get() != "")
        ostr_ << i->name_get() << " = ";

    ostr_ << i->type_to_str();

    if (i->itype_get() == Instruction::STACK_ALLOC)
    {
        StackAlloc *sa = dynamic_cast<StackAlloc*> (i);

        ostr_ << " " << *sa->alloc_type_get();

        return;
    }

    if (i->itype_get() == Instruction::CALL)
    {
        Call* c = dynamic_cast<Call*> (i);
        Function* f = c->callee_get();

        ostr_ << " " << f->name_get() << " " << *f->return_type_get()
              << " (";

        for (unsigned j = 1; j < i->operand_size(); ++j)
        {
            if (j != 1)
                ostr_ << ", ";

            write_value(i->operand_get(j));
        }

        ostr_ << ")";

        return;
    }

    if (i->itype_get() == Instruction::PHI)
    {
        PhiNode* pn = dynamic_cast<PhiNode*> (i);

        ostr_ << " " << *pn->type_get();

        for (unsigned j = 0; j < pn->size(); ++j)
        {
            if (j != 0)
                ostr_ << ", ";
            else
                ostr_ << " ";

            ostr_ << "[";
            write_value(pn->value_get(j));
            ostr_ << ", ";
            write_value(pn->bb_get(j));
            ostr_ << " ]";
        }

        return;
    }

    if (i->itype_get() >= Instruction::PROMOT &&
        i->itype_get() <= Instruction::CAST)
    {
        ostr_ << " ";
        write_value(i->operand_get(0));
        ostr_ << " to " << *i->type_get();

        return;
    }

    for (unsigned j = 0; j < i->operand_size(); ++j)
    {
        if (j != 0)
            ostr_ << ", ";
        else
            ostr_ << " ";

        write_value(i->operand_get(j));
    }
}

void IrWriter::write_value(Value* v)
{
    if (IntConstant* ic = dynamic_cast<IntConstant*> (v))
        ostr_ << ic->value_get();
    else
    {
        if (v->type_get()->type_get() != Type::LabelTy)
            ostr_ << *v->type_get() << " ";
        ostr_ << v->name_get();
    }
}
