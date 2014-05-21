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

#ifndef UCMP_IR_INSTRUCTION_HH
# define UCMP_IR_INSTRUCTION_HH

# include <ostream>
# include <ucmp/ir/value.hh>

namespace ucmp
{
    namespace ir
    {
        class BasicBlock;

        /// Base class for all IR instruction
        class Instruction : public Value
        {
            public:
                enum BinOp
                {
                    ADD,
                    SUB,
                    MUL,
                    DIV,
                    MOD,
                };
            public:
                Instruction(sType t, unsigned i_type);
                virtual ~Instruction() = default;

                virtual void dump(std::ostream& o) const = 0;

                BasicBlock* parent_get()        { return parent_; }
                void parent_set(BasicBlock* bb) { parent_ = bb; }
            protected:
                unsigned i_type_;
                BasicBlock* parent_;
        };
    } // namespace ir
} // namespace ucmp

#endif /* !UCMP_IR_INSTRUCTION_HH */
