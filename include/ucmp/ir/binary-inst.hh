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

#ifndef UCMP_IR_BINARY_INST_HH
# define UCMP_IR_BINARY_INST_HH

# include <ucmp/ir/instruction.hh>
# include <ucmp/ir/use.hh>

namespace ucmp
{
    namespace ir
    {
        class BinaryInst : public Instruction
        {
            public:
                enum BinOp
                {
                    ADD,
                    SUB,
                    MUL,
                    DIV,
                    MOD,
                    XOR,
                    OR,
                    AND,
                    LSH,
                    RSH,
                    ALSH,
                    ARSH
                };

            public:
                BinaryInst(BinOp op, sType type, Value* op1, Value* op2);
                virtual ~BinaryInst();

                BinOp binop_type_get() const { return op_; }

                virtual unsigned operand_size() const override { return 2; }
                virtual Value* operand_get(unsigned index) const override;

                virtual std::string type_to_str() const override;

            private:
                BinOp op_;
                Use op1_;
                Use op2_;
        };
    } // namespace ir
} // namespace ucmp

#endif /* !UCMP_IR_BINARY_INST_HH */
