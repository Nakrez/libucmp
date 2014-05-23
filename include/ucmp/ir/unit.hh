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

#ifndef UCMP_IR_UNIT_HH
# define UCMP_IR_UNIT_HH

# include <list>
# include <ostream>

# include <ucmp/ir/value-map.hh>

namespace ucmp
{
    namespace ir
    {
        class Function;
        class GlobalVariable;
        class Context;

        /// Contains a hole ir file
        class Unit
        {
            typedef typename std::list<Function*> f_list;
            typedef typename std::list<GlobalVariable*> gv_list;

            typedef typename f_list::iterator f_iterator;
            typedef typename f_list::const_iterator f_citerator;

            typedef typename gv_list::iterator gv_iterator;
            typedef typename gv_list::const_iterator gv_citerator;

            public:
                Unit(Context& c);
                virtual ~Unit();

                gv_iterator var_begin()          { return vars_.begin(); }
                gv_iterator var_end()            { return vars_.end(); }
                gv_citerator var_cbegin() const  { return vars_.cbegin(); }
                gv_citerator var_cend() const    { return vars_.cend(); }

                f_iterator fun_begin()          { return funs_.begin(); }
                f_iterator fun_end()            { return funs_.end(); }
                f_citerator fun_cbegin() const  { return funs_.cbegin(); }
                f_citerator fun_cend() const    { return funs_.cend(); }

                ValueMap& value_map_get()       { return vmap_; }

                Context& context_get()          { return c_; }

                const f_list& functions_get() const { return funs_; }
                f_list& functions_get()             { return funs_; }

                const gv_list& globals_get() const  { return vars_; }
                gv_list& globals_get()              { return vars_; }

                std::ostream& dump(std::ostream& o) const;

            private:
                Context& c_;
                std::list<Function*> funs_;
                std::list<GlobalVariable*> vars_;
                ValueMap vmap_;
        };
    } // namespace ir
} // namespace ucmp

#endif /* !UCMP_IR_UNIT_HH */
