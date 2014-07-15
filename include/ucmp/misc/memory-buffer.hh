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

#ifndef UCMP_MISC_MEMORY_BUFFER_HH
# define UCMP_MISC_MEMORY_BUFFER_HH

# include <string>
# include <fstream>

namespace ucmp
{
    namespace misc
    {
        class MemoryBuffer
        {
            public:
                MemoryBuffer();
                virtual ~MemoryBuffer();

                const char *buffer_get() const { return buff_; }
                unsigned size_get() const { return size_; }

                int open_file(const std::string& path);

            protected:
                unsigned file_size_get(std::ifstream& s) const;

            protected:
                char *buff_;
                unsigned size_;
        };
    } // namespace misc
} // namespace ucmp

#endif /* !UCMP_MISC_MEMORY_BUFFER_HH */
