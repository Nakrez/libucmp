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

#ifndef UCMP_IR_CONSTANT_HH
# define UCMP_IR_CONSTANT_HH

# include <ucmp/ir/value.hh>

namespace ucmp
{
    namespace ir
    {
        /// Represents a constant value
        class Constant : public Value
        {
            public:
                Constant(sType t)
                    : Value(t)
                {}

                virtual ~Constant() = default;
        };
    } // namespace ir
} // namespace ucmp

#endif /* !UCMP_IR_CONSTANT_HH */
