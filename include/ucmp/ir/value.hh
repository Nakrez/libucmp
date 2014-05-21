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

#ifndef UCMP_IR_VALUE_HH
# define UCMP_IR_VALUE_HH

# include <ucmp/misc/symbol.hh>

# include <ucmp/ir/type.hh>
# include <ucmp/ir/value-map.hh>

namespace ucmp
{
    namespace ir
    {
        class Value
        {
            friend class ValueMap;
            public:
                Value(sType t);
                virtual ~Value() = default;

                sType type_get() const
                {
                    return type_;
                }

                const misc::Symbol name_get() const
                {
                    return name_;
                }

                void name_set(const misc::Symbol& n);

                virtual void dump(std::ostream& o) const
                {
                    o << *type_ << " " << name_;
                }

            protected:
                ValueMap* get_value_map();

            protected:
                sType type_;
                misc::Symbol name_;
        };
    } // namespace ir
} // namespace ucmp

inline std::ostream& operator<<(std::ostream& o, const ucmp::ir::Value& v)
{
    v.dump(o);

    return o;
}

#endif /* !UCMP_IR_VALUE_HH */
