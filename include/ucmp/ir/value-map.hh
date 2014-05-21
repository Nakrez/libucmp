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

#ifndef UCMP_IR_VALUE_MAP_HH
# define UCMP_IR_VALUE_MAP_HH

# include <map>

# include <ucmp/misc/symbol.hh>

namespace ucmp
{
    namespace ir
    {
        class Value;

        class ValueMap
        {
            public:
                ValueMap();
                ~ValueMap();

                void insert_name(Value* v, const misc::Symbol& name);

                Value* get(const misc::Symbol& name);

                template <class T>
                T* get_as(const misc::Symbol& name)
                {
                    return dynamic_cast<T*> (get(name));
                }

            protected:
                std::map<misc::Symbol, Value*> map_;
                int counter_;
        };
    } // namespace ir
} // namespace ucmp

#endif /* !UCMP_IR_VALUE_MAP_HH */
