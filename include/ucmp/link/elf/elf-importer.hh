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

#ifndef UCMP_LINK_ELF_IMPORTER_HH
# define UCMP_LINK_ELF_IMPORTER_HH

# include <iostream>

# include <ucmp/link/core/importer.hh>
# include <ucmp/misc/memory-buffer.hh>
# include <ucmp/misc/elf.hh>

namespace ucmp
{
    namespace link
    {
        class ElfImporter : public Importer
        {
            public:
                virtual bool parse_file(LinkContext& lc,
                                        const std::string& path) override;
            protected:
                template <LinkContext::Class>
                struct ElfTraits
                {
                };

                template <LinkContext::Class Elf>
                class ElfInnerImporter
                {
                    typedef typename ElfTraits<Elf>::Ehdr Ehdr;
                    typedef typename ElfTraits<Elf>::Shdr Shdr;

                    public:
                        File* parse_file(misc::MemoryBuffer& buf);

                    private:
                        void parse_section(File* f, misc::MemoryBuffer& buf,
                                           const Shdr* section);
                        void parse_symtab(File* f, misc::MemoryBuffer& buf,
                                          const Shdr* section);
                        void set_frag_flags(Fragment* f, const Shdr* section);
                        void locate_shstr(misc::MemoryBuffer& buf,
                                          const Ehdr* elf);
                        std::string shname_get(int index);

                    private:
                        const char *shstrtab_;
                };

                typedef ElfInnerImporter<LinkContext::BITS32>
                        Elf32InnerImporter;
                typedef ElfInnerImporter<LinkContext::BITS64>
                        Elf64InnerImporter;
        };
    } // namespace link
} // namespace ucmp

# include <ucmp/link/elf/elf-importer.hxx>

#endif /* !UCMP_LINK_ELF_IMPORTER_HH */
