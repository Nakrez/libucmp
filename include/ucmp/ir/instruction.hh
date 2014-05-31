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
# include <string>

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
                enum InstType
                {
                    BINOP,
                    CMP,
                    STACK_ALLOC,
                    STORE,
                    LOAD,
                    RET,
                };

            public:
                Instruction(sType t, InstType i_type);
                virtual ~Instruction() = default;

                BasicBlock* parent_get()        { return parent_; }
                void parent_set(BasicBlock* bb) { parent_ = bb; }

                /// Return the number of operand the instruction has
                virtual unsigned operand_size() const = 0;

                /// Get the ith operand (start at 0)
                virtual Value* operand_get(int index) const = 0;

                /// Return the instruction type
                InstType itype_get() const  { return i_type_; }

                virtual std::string type_to_str() const;

            protected:
                InstType i_type_;
                BasicBlock* parent_;
        };
    } // namespace ir
} // namespace ucmp

#endif /* !UCMP_IR_INSTRUCTION_HH */
