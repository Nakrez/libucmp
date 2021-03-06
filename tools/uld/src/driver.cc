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

#include <driver.hh>
#include <ucmp/link/elf/elf-importer.hh>

Driver::Driver()
    : c_()
    , importer_()
    , files_()
{}

void Driver::parse_command(int argc, char **argv)
{
    // Parse command line
    for (int i = 1; i < argc; ++i)
        files_.push_back(std::string(argv[i]));

    // Determine specific binary format we need
    switch (c_.type_get())
    {
        case ucmp::link::LinkContext::ELF:
            importer_.reset(new ucmp::link::ElfImporter());
            break;
    }
}

void Driver::link()
{
    for (auto f : files_)
    {
        if (!importer_->parse_file(c_, f))
        {
            std::cerr << "Error: cannot import " << f << std::endl;;
            return;
        }
    }

    for (auto f = c_.object_cbegin(); f != c_.object_cend(); ++f)
    {
        std::cout << **f << std::endl;
    }
}
