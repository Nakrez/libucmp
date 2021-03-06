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

#ifndef UCMP_IR_FUNCTION_TYPE_HH
# define UCMP_IR_FUNCTION_TYPE_HH

# include <list>

# include <ucmp/ir/type.hh>

namespace ucmp
{
    namespace ir
    {
        class FunctionType : public Type
        {
            typedef typename std::list<sType>::iterator arg_iterator;
            typedef typename std::list<sType>::const_iterator arg_citerator;

            public:
                FunctionType(sType ret_type);
                FunctionType(sType ret_type, const std::list<sType>& args);
                virtual ~FunctionType() = default;

                arg_iterator begin()            { return args_.begin(); }
                arg_iterator end()              { return args_.end(); }
                arg_citerator cbegin() const    { return args_.cbegin(); }
                arg_citerator cend() const      { return args_.cend(); }

                const std::list<sType>& args_get() const { return args_; }
                void arg_add(sType t) { args_.push_back(t); }

                sType ret_type_get() const { return ret_type_; }

            protected:
                sType ret_type_;
                std::list<sType> args_;
        };
    } // namespace ir
} // namespace ucmp

#endif /* !UCMP_IR_FUNCTION_TYPE_HH */
