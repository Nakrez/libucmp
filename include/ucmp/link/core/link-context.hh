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

#ifndef UCMP_LINK_LINK_CONTEXT_HH
# define UCMP_LINK_LINK_CONTEXT_HH

# include <vector>
# include <string>
# include <memory>

# include <ucmp/link/core/file.hh>

namespace ucmp
{
    namespace link
    {
        class LinkContext
        {
            typedef std::vector<std::unique_ptr<File>>::const_iterator
                    cit_file;
            typedef std::vector<std::unique_ptr<File>>::iterator it_file;

            public:
                enum Class
                {
                    BITS32,
                    BITS64,
                };

                enum Type
                {
                    ELF,
                };

            public:
                LinkContext(Class c = BITS64, Type t = ELF)
                    : class_(c)
                    , type_(t)
                {}

                ~LinkContext() = default;

                Class class_get() const { return class_; }
                Type type_get() const { return type_; }

                void class_set(Class c) { class_ = c; }
                void type_set(Type t) { type_ = t; }

                it_file object_begin() { return object_files_.begin(); }
                cit_file object_begin() const { return object_files_.cbegin(); }
                it_file object_end() { return object_files_.end(); }
                cit_file object_end() const { return object_files_.cend(); }
                cit_file object_cbegin() const { return object_files_.cbegin(); }
                cit_file object_cend() const { return object_files_.cend(); }

                void add_object_file(std::unique_ptr<File> f)
                {
                    object_files_.push_back(std::move(f));
                }

                void add_static_lib(std::unique_ptr<File> f)
                {
                    static_libs_.push_back(std::move(f));
                }

                void add_dynamic_lib(std::unique_ptr<File> f)
                {
                    dynamic_libs_.push_back(std::move(f));
                }

            protected:
                Class class_;
                Type type_;
                std::vector<std::unique_ptr<File>> object_files_;
                std::vector<std::unique_ptr<File>> static_libs_;
                std::vector<std::unique_ptr<File>> dynamic_libs_;
        };
    } // namespace link
} // namespace ucmp

#endif /* !UCMP_LINK_LINK_CONTEXT_HH */
