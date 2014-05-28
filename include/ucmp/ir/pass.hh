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

#ifndef UCMP_IR_PASS_HH
# define UCMP_IR_PASS_HH

# include <ucmp/ir/unit.hh>
# include <ucmp/ir/function.hh>

namespace ucmp
{
    namespace ir
    {
        class Pass
        {
            public:
                Pass() = default;
                virtual ~Pass() = default;
        };

        class UnitPass : public Pass
        {
            public:
                UnitPass() = default;
                virtual ~UnitPass() = default;

                virtual void init(Unit&) {}

                virtual void run_on_unit(Unit&) = 0;

                virtual void end(Unit&) {}
        };

        class FunctionPass : public Pass
        {
            public:
                FunctionPass() = default;
                virtual ~FunctionPass() = default;

                virtual void init(Function&) {}

                virtual void run_on_function(Function&) = 0;

                virtual void end(Function&) {}
        };
    };
} // namespace ucmp

#endif /* !UCMP_IR_PASS_HH */
