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

#include <ucmp/link/core/fragment.hh>
#include <iostream>

using namespace ucmp;
using namespace link;

static const char *flag_name[] =
{
    "WRITE",
    "ALLOC",
    "EXEC",
    "MERGE",
    "STRINGS",
    "LINK_ORDER",
    "TLS",
};

Fragment::Fragment(const misc::Symbol& name, const char* data, unsigned size)
    : name_(name)
    , data_()
    , flags_(NONE)
{
    data_.assign(data, data + size);
}

Fragment::~Fragment()
{}

void Fragment::dump(std::ostream& o) const
{
    o << name_ << ":";

    if (!flags_)
    {
        o << " NO FLAGS";
        return ;
    }

    for (unsigned i = WRITE, index = 0, count = 0; i <= TLS; i <<= 1, ++index)
    {
        if (flags_ & i)
        {
            if (count)
                o << " | ";
            else
                o << " ";

            o << flag_name[index];
            ++count;
        }
    }
}
