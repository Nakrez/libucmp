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

#ifndef UCMP_IR_CONTEXT_HH
# define UCMP_IR_CONTEXT_HH

# include <list>
# include <map>
# include <cassert>

# include <ucmp/ir/type.hh>
# include <ucmp/ir/struct-type.hh>
# include <ucmp/ir/int-constant.hh>

namespace ucmp
{
    namespace ir
    {
        class Unit;

        class Context
        {
            typedef typename std::list<Unit*>::iterator u_iterator;
            typedef typename std::list<Unit*>::const_iterator cu_iterator;
            typedef typename std::map<misc::Symbol,
                                      sStructType>::iterator s_iterator;
            typedef typename std::map<misc::Symbol,
                                      sStructType>::const_iterator cs_iterator;

            public:
                Context();
                virtual ~Context();

                void add_unit(Unit* u)
                {
                    units_.push_back(u);
                }

                void register_struct(const misc::Symbol& s, sStructType t)
                {
                    structs_[s] = t;
                }

                sStructType struct_get(const misc::Symbol& s)
                {
                    auto it = structs_.find(s);

                    assert(it != structs_.end());

                    return it->second;
                }

                bool struct_exists(const misc::Symbol& s) const
                {
                    return structs_.find(s) != structs_.end();
                }

                IntConstant* iconstant_get(int c);

                u_iterator begin()          { return units_.begin(); }
                u_iterator end()            { return units_.end(); }
                cu_iterator cbegin() const  { return units_.cbegin(); }
                cu_iterator cend() const    { return units_.cend(); }

                s_iterator s_begin()            { return structs_.begin(); }
                cs_iterator s_begin() const     { return structs_.begin(); }
                s_iterator s_end()              { return structs_.end(); }
                cs_iterator s_end() const       { return structs_.end(); }
                cs_iterator s_cbegin() const    { return structs_.cbegin(); }
                cs_iterator s_cend() const      { return structs_.cend(); }

                sType void_ty_get()     { return void_; }
                sType float_ty_get()    { return float_; }
                sType double_ty_get()   { return double_; }
                sType label_ty_get()    { return label_; }

                sType i1_ty_get()       { return i1_; }
                sType i8_ty_get()       { return i8_; }
                sType i16_ty_get()      { return i16_; }
                sType i32_ty_get()      { return i32_; }
                sType i64_ty_get()      { return i64_; }

            protected:
                sType void_;
                sType float_;
                sType double_;
                sType label_;

                sType i1_;
                sType i8_;
                sType i16_;
                sType i32_;
                sType i64_;

                std::list<Unit*> units_;
                std::map<misc::Symbol, sStructType> structs_;
                std::map<int, IntConstant*> i_constants_;
        };
    } // namespace ir
} // namespace ucmp

#endif /* !UCMP_IR_CONTEXT_HH */
