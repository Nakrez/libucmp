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

#ifndef UCMP_IR_IR_GENERATOR_HH
# define UCMP_IR_IR_GENERATOR_HH

# include <vector>

# include <ucmp/ir/context.hh>
# include <ucmp/ir/unit.hh>
# include <ucmp/ir/function.hh>
# include <ucmp/ir/function-type.hh>

namespace ucmp
{
    namespace ir
    {
        /// Helper class to generate intermediate representation
        class IrGenerator
        {
            public:
                IrGenerator(Context& c);
                virtual ~IrGenerator() = default;

                BasicBlock* insert_block_get()  { return bb_; }
                BasicBlock::iterator& insert_pt_get() { return insert_pt_; }

                void insert_pt_set(BasicBlock* bb)
                {
                    bb_ = bb;
                    insert_pt_ = bb->end();
                }

                void insert_pt_set(BasicBlock* bb, BasicBlock::iterator it)
                {
                    bb_ = bb;
                    insert_pt_ = it;
                }

                Value* create_add(Value* l,
                                  Value* r, const misc::Symbol& n = "");
                Value* create_sub(Value* l,
                                  Value* r, const misc::Symbol& n = "");
                Value* create_mul(Value* l,
                                  Value* r, const misc::Symbol& n = "");
                Value* create_div(Value* l,
                                  Value* r, const misc::Symbol& n = "");
                Value* create_mod(Value* l,
                                  Value* r, const misc::Symbol& n = "");
                Value* create_xor(Value* l,
                                  Value* r, const misc::Symbol& n = "");

                Value* create_gt(Value* l,
                                 Value* r, const misc::Symbol& n = "");
                Value* create_ge(Value* l,
                                 Value* r, const misc::Symbol& n = "");
                Value* create_le(Value* l,
                                 Value* r, const misc::Symbol& n = "");
                Value* create_lt(Value* l,
                                 Value* r, const misc::Symbol& n = "");
                Value* create_eq(Value* l,
                                 Value* r, const misc::Symbol& n = "");
                Value* create_ne(Value* l,
                                 Value* r, const misc::Symbol& n = "");

                Value* create_stack_alloc(sType t, const misc::Symbol& n = "");
                Value* create_store(Value* val, Value* mem);
                Value* create_load(Value* mem, const misc::Symbol& n = "");

                Value* create_ret();
                Value* create_ret(Value* val);

                Value* create_jump(BasicBlock* bb);
                Value* create_cjump(Value* cond, BasicBlock* t, BasicBlock *f);

                Value* create_call(Function* f);
                Value* create_call(Function* f, const misc::Symbol& n);
                Value* create_call(Function* f, const std::vector<Value*> arg);
                Value* create_call(Function* f, const std::vector<Value*> arg,
                                   const misc::Symbol& n);

                void insert(Instruction* instr, const misc::Symbol& name)
                {
                    bb_->instr_list_get().insert(insert_pt_, instr);
                    instr->parent_set(bb_);
                    instr->name_set(name);
                }

                void insert(Instruction* instr)
                {
                    bb_->instr_list_get().insert(insert_pt_, instr);
                    instr->parent_set(bb_);
                }

                void remove(Instruction* i)
                {
                    bb_->instr_list_get().remove(i);
                }

            protected:
                Context& c_;
                BasicBlock* bb_;
                BasicBlock::iterator insert_pt_;
        };
    } // namespace ir
} // namespace ucmp

#endif /* !UCMP_IR_IR_GENERATOR_HH */
