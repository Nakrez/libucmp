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

            header_ = reinterpret_cast<const Ehdr*> (buf.buffer_get());

            if (header_->e_type == ELF::ET_DYN)
                f = new File(File::DynLib);
            else
                f = new File(File::Object);

            return f;
        }
    } // namespace link
} // namespace ucmp

#endif /* !UCMP_LINK_ELF_IMPORTER_HXX */
