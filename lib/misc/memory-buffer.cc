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

#include <ucmp/misc/memory-buffer.hh>

using namespace ucmp;
using namespace misc;

MemoryBuffer::MemoryBuffer()
    : buff_(nullptr)
    , size_(0)
{}

MemoryBuffer::~MemoryBuffer()
{
    if (buff_)
        delete[] buff_;
}

int MemoryBuffer::open_file(const std::string& path)
{
    // If a file as already been open we remove it

    if (buff_)
    {
        delete[] buff_;
        size_ = 0;
    }

    std::ifstream file(path);

    if (!file.is_open())
        return -1;

    size_ = file_size_get(file);

    buff_ = new char[size_];

    file.read(buff_, size_);

    file.close();

    return 0;
}

unsigned MemoryBuffer::file_size_get(std::ifstream& s) const
{
    unsigned size;

    s.seekg(0, s.end);
    size = s.tellg();
    s.seekg(0, s.beg);

    return size;
}
