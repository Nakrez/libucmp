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

                BasicBlock* insert_pt_get()         { return insert_pt_; }
                void insert_pt_set(BasicBlock* bb)  { insert_pt_ = bb; }

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

                void insert(Instruction* instr, const misc::Symbol& name = "")
                {
                    insert_pt_->instr_list_get().push_back(instr);
                    instr->parent_set(insert_pt_);
                    instr->name_set(name);
                }

            protected:
                Context& c_;
                BasicBlock* insert_pt_;
        };
    } // namespace ir
} // namespace ucmp

#endif /* !UCMP_IR_IR_GENERATOR_HH */
