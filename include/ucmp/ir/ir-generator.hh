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

                void init();

                Function* declared_function_get() { return fun_; }
                BasicBlock* insert_pt_get() { return insert_pt_; }

                void current_unit_set(Unit* u)
                {
                    c_.add_unit(u);

                    unit_ = u;
                }

                void start_function(const misc::Symbol& name, sType ret_type)
                {
                    fun_ = new Function(name, new FunctionType(ret_type));
                }

                void end_function()
                {
                    unit_->add_function(fun_);
                    fun_ = nullptr;
                }

                void insert_pt_set(BasicBlock* bb)
                {
                    insert_pt_ = bb;
                }

            protected:
                Context& c_;
                Unit* unit_;
                Function* fun_;
                BasicBlock* insert_pt_;
        };
    } // namespace ir
} // namespace ucmp

#endif /* !UCMP_IR_IR_GENERATOR_HH */