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

#ifndef UCMP_IR_INT_CONSTANT_HH
# define UCMP_IR_INT_CONSTANT_HH

# include <ucmp/ir/constant.hh>

namespace ucmp
{
    namespace ir
    {
        class Context;

        class IntConstant : public Constant
        {
            public:
                IntConstant(Context& c, int val);
                virtual ~IntConstant() = default;

                int value_get() const
                {
                    return val_;
                }

                virtual void dump(std::ostream& o) const override
                {
                    o << val_;
                }

            protected:
                int val_;
        };
    } // namespace ir
} // namespace ucmp

#endif /* !UCMP_IR_INT_CONSTANT_HH */
