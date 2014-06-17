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

#ifndef UCMP_IR_PHI_NODE_HH
# define UCMP_IR_PHI_NODE_HH

# include <vector>

# include <ucmp/ir/instruction.hh>

namespace ucmp
{
    namespace ir
    {
        class PhiNode : public Instruction
        {
            public:
                PhiNode(sType t);
                virtual ~PhiNode() = default;

                void incoming_add(BasicBlock* bb, Value* v)
                {
                    values_.push_back(v);
                    bbs_.push_back(bb);
                }

                BasicBlock* bb_get(unsigned i) { return bbs_.at(i); }
                Value* value_get(unsigned i) { return values_.at(i); }
                unsigned size() { return bbs_.size(); }

                virtual unsigned operand_size() const override
                {
                    return values_.size() + bbs_.size();
                }

                virtual Value* operand_get(unsigned index) const override;

            protected:
                std::vector<Value*> values_;
                std::vector<BasicBlock*> bbs_;
        };
    } // namespace ir
} // namespace ucmp

#endif /* !UCMP_IR_PHI_NODE_HH */
