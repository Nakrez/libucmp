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

#ifndef DRIVER_HH
# define DRIVER_HH

# include <vector>
# include <memory>
# include <iostream>

# include <ucmp/link/core/link-context.hh>
# include <ucmp/link/core/importer.hh>

class Driver
{
    public:
        Driver();
        ~Driver() = default;

        void parse_command(int argc, char **argv);
        void link();

    protected:
        ucmp::link::LinkContext c_;
        std::unique_ptr<ucmp::link::Importer> importer_;
        std::vector<std::string> files_;
};

#endif /* !DRIVER_HH */
