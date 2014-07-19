#ifndef UCMP_LINK_ELF_IMPORTER_HXX
# define UCMP_LINK_ELF_IMPORTER_HXX

# include <ucmp/link/elf/elf-importer.hh>

namespace ucmp
{
    namespace link
    {
        template <LinkContext::Class Elf>
        File*
        ElfImporter::ElfInnerImporter<Elf>::parse_file(misc::MemoryBuffer& buf)
        {
            File* f = nullptr;

            const Ehdr *header;

            header = reinterpret_cast<const Ehdr*> (buf.buffer_get());

            if (header->e_type == ELF::ET_DYN)
                f = new File(File::DynLib);
            else
                f = new File(File::Object);

            locate_shstr(buf, header);
            locate_strtab(buf, header);

            const Shdr *section;

            section = reinterpret_cast<const Shdr*> (buf.buffer_get() +
                                                     header->e_shoff);

            for (int i = 0; i < header->e_shnum; ++i, ++section)
            {
                // Don't import shstrtab, it's useless
                if (i == header->e_shstrndx)
                    continue;

                parse_section(f, buf, section);
            }

            return f;
        }

        template <LinkContext::Class Elf>
        void
        ElfImporter::ElfInnerImporter<Elf>::parse_section(File* f,
                                                          misc::MemoryBuffer& buf,
                                                          const Shdr* section)
        {
            switch (section->sh_type)
            {
                // Don't import null section, useless because it will be
                // regenerated by writer
                case ELF::SHT_NULL:
                    break;
                case ELF::SHT_SYMTAB:
                    parse_symtab(f, buf, section);
                    break;
                case ELF::SHT_RELA:
                    break;
                default:
                    {
                        Fragment* frag;

                        frag = new Fragment(shname_get(section->sh_name),
                                                 buf.buffer_get() +
                                                 section->sh_offset,
                                                 section->sh_size);

                        set_frag_flags(frag, section);

                        f->add_frag(frag);
                    }
                    break;
            }
        }

        template <LinkContext::Class Elf>
        void
        ElfImporter::ElfInnerImporter<Elf>::parse_symtab(File* f,
                                                         misc::MemoryBuffer& buf,
                                                         const Shdr* section)
        {
            const char* sh_buffer = buf.buffer_get() + section->sh_offset;
            const char* sh_buffer_end = sh_buffer + section->sh_size;
            const Sym* s = reinterpret_cast<const Sym*> (sh_buffer);

            for (; reinterpret_cast<const char*>(s) < sh_buffer_end; ++s)
            {
            }
        }

        template <LinkContext::Class Elf>
        void
        ElfImporter::ElfInnerImporter<Elf>::set_frag_flags(Fragment* f,
                                                           const Shdr* section)
        {
            if (section->sh_flags & ELF::SHF_WRITE)
                f->set_flag(Fragment::WRITE);

            if (section->sh_flags & ELF::SHF_ALLOC)
                f->set_flag(Fragment::ALLOC);

            if (section->sh_flags & ELF::SHF_EXECINSTR)
                f->set_flag(Fragment::EXEC);

            if (section->sh_flags & ELF::SHF_MERGE)
                f->set_flag(Fragment::MERGE);

            if (section->sh_flags & ELF::SHF_STRINGS)
                f->set_flag(Fragment::STRINGS);

            if (section->sh_flags & ELF::SHF_LINK_ORDER)
                f->set_flag(Fragment::LINK_ORDER);

            if (section->sh_flags & ELF::SHF_TLS)
                f->set_flag(Fragment::TLS);
        }

        template <LinkContext::Class Elf>
        void
        ElfImporter::ElfInnerImporter<Elf>::locate_shstr(misc::MemoryBuffer& buf,
                                                         const Ehdr* elf)
        {
            const Shdr *shstr_section;

            shstr_section = reinterpret_cast<const Shdr*> (buf.buffer_get() +
                                                           elf->e_shoff +
                                                           elf->e_shstrndx *
                                                           sizeof (Shdr));

            shstrtab_ = buf.buffer_get() + shstr_section->sh_offset;
        }

        template <LinkContext::Class Elf>
        void
        ElfImporter::ElfInnerImporter<Elf>::locate_strtab(misc::MemoryBuffer& buf,
                                                          const Ehdr* elf)
        {
            const Shdr* strtab_section;
            misc::Symbol sh_name = ".strtab";

            strtab_section = reinterpret_cast<const Shdr*> (buf.buffer_get() +
                                                            elf->e_shoff);

            for (unsigned i = 0; i < elf->e_shnum; ++i, ++strtab_section)
            {
                if (shname_get(strtab_section->sh_name) == sh_name)
                {
                    strtab_ = buf.buffer_get() + strtab_section->sh_offset;
                    break;
                }
            }
        }

        template <LinkContext::Class Elf>
        misc::Symbol ElfImporter::ElfInnerImporter<Elf>::shname_get(int index)
        {
            return std::string(shstrtab_ + index);
        }

        template <LinkContext::Class Elf>
        misc::Symbol ElfImporter::ElfInnerImporter<Elf>::strname_get(int index)
        {
            return std::string(strtab_ + index);
        }
    } // namespace link
} // namespace ucmp

#endif /* !UCMP_LINK_ELF_IMPORTER_HXX */
