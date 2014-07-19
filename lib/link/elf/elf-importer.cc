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

#include <ucmp/link/elf/elf-importer.hh>

using namespace ucmp;
using namespace link;

template <>
struct ElfImporter::ElfTraits<LinkContext::BITS32>
{
    typedef ELF::Elf32_Ehdr Ehdr;
    typedef ELF::Elf32_Shdr Shdr;
    typedef ELF::Elf32_Sym Sym;
};

template <>
struct ElfImporter::ElfTraits<LinkContext::BITS64>
{
    typedef ELF::Elf64_Ehdr Ehdr;
    typedef ELF::Elf64_Shdr Shdr;
    typedef ELF::Elf64_Sym Sym;
};

bool ElfImporter::parse_file(LinkContext& lc, const std::string& path)
{
    misc::MemoryBuffer buf;
    File* f;

    if (buf.open_file(path) < 0)
        return false;

    const ELF::Elf64_Ehdr *elf_header;

    elf_header = reinterpret_cast<const ELF::Elf64_Ehdr*> (buf.buffer_get());

    // Not an ELF try static lib
    if (!elf_header->check_magic())
    {
        return false;
    }

    if (elf_header->class_get() == ELF::ELFCLASS32)
    {
        Elf32InnerImporter importer;

        f = importer.parse_file(buf);
    }
    else if (elf_header->class_get() == ELF::ELFCLASS64)
    {
        Elf64InnerImporter importer;

        f = importer.parse_file(buf);
    }
    else
        return false;

    switch (f->kind_get())
    {
        case File::Object:
            lc.add_object_file(std::unique_ptr<File>(f));
            break;
        case File::StaticLib:
            lc.add_static_lib(std::unique_ptr<File>(f));
            break;
        case File::DynLib:
            lc.add_dynamic_lib(std::unique_ptr<File>(f));
            break;
    }

    return true;
}
