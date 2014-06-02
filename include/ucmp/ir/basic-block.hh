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

#ifndef UCMP_IR_BASIC_BLOCK_HH
# define UCMP_IR_BASIC_BLOCK_HH

# include <list>
# include <ostream>

# include <ucmp/ir/value.hh>
# include <ucmp/ir/instruction.hh>

namespace ucmp
{
    namespace ir
    {
        class Context;
        class Function;

        /// Represent a basic block
        class BasicBlock : public Value
        {
            typedef typename std::list<Instruction*> i_list;

            public:
                typedef typename i_list::iterator iterator;
                typedef typename i_list::const_iterator const_iterator;

            public:
                BasicBlock(Context& c, Function* parent = nullptr,
                           const misc::Symbol& name = "");
                virtual ~BasicBlock();

                iterator begin()          { return ins_.begin(); }
                iterator end()            { return ins_.end(); }
                const_iterator begin() const   { return ins_.begin(); }
                const_iterator end() const     { return ins_.end(); }
                const_iterator cbegin() const  { return ins_.cbegin(); }
                const_iterator cend() const    { return ins_.cend(); }

                Instruction* front() { return ins_.front(); }
                Instruction* back() { return ins_.back(); }

                i_list& instr_list_get()                { return ins_; }
                const i_list& instr_list_get() const    { return ins_; }

                Function* parent_get()          { return parent_; }
                void parent_set(Function* f)    { parent_ = f; }

            protected:
                std::list<Instruction*> ins_;
                Function* parent_;
        };
    } // namespace ir
} // namespace ucmp

#endif /* !UCMP_IR_BASIC_BLOCK_HH */
