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

#include <ucmp/ir/cjump.hh>
#include <ucmp/ir/basic-block.hh>

using namespace ucmp;
using namespace ir;

Cjump::Cjump(sType t, Value* v, BasicBlock* tr, BasicBlock* fa)
    : Instruction(t, CJUMP)
    , cond_(v)
    , true_(tr)
    , false_(fa)
{}

Value* Cjump::operand_get(unsigned index) const
{
    switch (index)
    {
        case 0:
            return cond_;
        case 1:
            return true_;
        case 2:
            return false_;
        default:
            return nullptr;
    }
}
