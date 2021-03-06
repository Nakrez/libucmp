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

#ifndef UCMP_IR_STRUCT_TYPE_HH
# define UCMP_IR_STRUCT_TYPE_HH

# include <list>

# include <ucmp/misc/symbol.hh>
# include <ucmp/ir/type.hh>

namespace ucmp
{
    namespace ir
    {
        class Context;

        class StructType : public Type
        {
            public:
                StructType(Context& c,
                           const misc::Symbol& name,
                           const std::list<sType>& types,
                           bool is_struct = true);
                StructType(Context& c,
                           const misc::Symbol& name,
                           bool is_struct = true);
                virtual ~StructType() = default;

                bool is_struct() const { return is_struct_; }
                bool is_union() const { return !is_struct_; }

                void add_member(sType t)    { types_.push_back(t); }

                virtual void dump(std::ostream& o) const override;
                void full_dump(std::ostream& o) const;

            protected:
                misc::Symbol name_;
                std::list<sType> types_;
                bool is_struct_;
        };

        typedef std::shared_ptr<StructType> sStructType;
    } // namespace ir
} // namespace ucmp

#endif /* !UCMP_IR_STRUCT_TYPE_HH */
