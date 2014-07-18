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

#ifndef UCMP_MISC_ELF_HH
# define UCMP_MISC_ELF_HH

# include <cstdint>
# include <cstring>

namespace ucmp
{
    namespace ELF
    {
        typedef uint16_t Elf32_Half;
        typedef uint32_t Elf32_Word;
        typedef int32_t  Elf32_Sword;
        typedef uint64_t Elf32_Xword;
        typedef int64_t  Elf32_Sxword;
        typedef uint32_t Elf32_Addr;
        typedef uint32_t Elf32_Off;
        typedef uint16_t Elf32_Section;
        typedef Elf32_Half Elf32_Versym;

        typedef uint16_t Elf64_Half;
        typedef uint32_t Elf64_Word;
        typedef int32_t  Elf64_Sword;
        typedef uint64_t Elf64_Xword;
        typedef int64_t  Elf64_Sxword;
        typedef uint64_t Elf64_Addr;
        typedef uint64_t Elf64_Off;
        typedef uint16_t Elf64_Section;
        typedef Elf64_Half Elf64_Versym;

        static const char ElfMag[] = { 0x7F, 'E', 'L', 'F' };

        // e_ident size and content indices
        enum
        {
            EI_MAG0 = 0, // File identification byte 0 index
            EI_MAG1 = 1, // File identification byte 1 index
            EI_MAG2 = 2, // File identification byte 2 index
            EI_MAG3 = 3, // File identification byte 3 index
            EI_CLASS = 4, // File class byte index
            EI_DATA = 5, // Data encoding byte index
            EI_VERSION = 6, // File version byte index
            EI_OSABI = 7, // OS ABI Identification
            EI_ABIVERSION = 8, // ABI Version
            EI_PAD = 9, // Byte index of padding bytes
            EI_NIDENT = 16 // Size of e_ident field
        };

        // File class
        enum
        {
            ELFCLASSNONE = 0, // Invalid class
            ELFCLASS32 = 1, // 32-bit objects
            ELFCLASS64 = 2, // 64-bit objects
        };

        // Data encoding
        enum
        {
            ELFDATANONE = 0, // Invalid data encoding
            ELFDATA2LSB = 1, // 2's complement, little endian
            ELFDATA2MSB = 2, // 2's complement, big endian
            ELFDATANUM = 3,
        };

        // OS ABI
        enum
        {
            ELFOSABI_NONE = 0, // UNIX System V ABI
            ELFOSABI_SYSV = 0, // Alias.
            ELFOSABI_HPUX = 1, // HP-UX
            ELFOSABI_NETBSD = 2, // NetBSD.
            ELFOSABI_GNU = 3, // Object uses GNU ELF extensions.
            ELFOSABI_LINUX = ELFOSABI_GNU, // Compatibility alias.
            ELFOSABI_SOLARIS = 6, // Sun Solaris.
            ELFOSABI_AIX = 7, // IBM AIX.
            ELFOSABI_IRIX = 8, // SGI Irix.
            ELFOSABI_FREEBSD = 9, // FreeBSD.
            ELFOSABI_TRU64 = 10, // Compaq TRU64 UNIX.
            ELFOSABI_MODESTO = 11, // Novell Modesto.
            ELFOSABI_OPENBSD = 12, // OpenBSD.
            ELFOSABI_ARM_AEABI = 64, // ARM EABI
            ELFOSABI_ARM = 97, // ARM
            ELFOSABI_STANDALONE = 255, // Standalone (embedded) application
        };

        // Elf header
        template <class Half, class Word, class Addr, class Off>
        struct Elf_Ehdr
        {
            unsigned char e_ident[EI_NIDENT]; // Magic number and other info
            Half e_type; // Object file type
            Half e_machine; // Architecture
            Word e_version; // Object file version
            Addr e_entry; // Entry point virtual address
            Off e_phoff; // Program header table file offset
            Off e_shoff; // Section header table file offset
            Word e_flags; // Processor-specific flags
            Half e_ehsize; // ELF header size in bytes
            Half e_phentsize; // Program header table entry size
            Half e_phnum; // Program header table entry count
            Half e_shentsize; // Section header table entry size
            Half e_shnum; // Section header table entry count
            Half e_shstrndx; // Section header string table index

            bool check_magic() const
            {
                return memcmp(e_ident, ElfMag, strlen(ElfMag)) == 0;
            }

            char class_get() const { return e_ident[EI_CLASS]; }
            char data_get() const { return e_ident[EI_DATA]; }
            char version_get() const { return e_ident[EI_VERSION]; }
            char osabi_get() const { return e_ident[EI_OSABI]; }
            char abi_version_get() const { return e_ident[EI_ABIVERSION]; }
        };

        // Elf 32 bits header
        typedef Elf_Ehdr<Elf32_Half, Elf32_Word, Elf32_Addr, Elf32_Off>
                Elf32_Ehdr;

        // Elf 64 bits header
        typedef Elf_Ehdr<Elf64_Half, Elf64_Word, Elf64_Addr, Elf64_Off>
                Elf64_Ehdr;

        // Legal values for e_type (Object file type)
        enum
        {
            ET_NONE = 0, // No file type
            ET_REL = 1, // Relocatable file
            ET_EXEC2 = 2, // Executable file
            ET_DYN = 3, // Shared object file
            ET_CORE = 4, // Core file
            ET_NUM = 5, // Number of defined types
            ET_LOOS = 0xfe00, // OS-specific range start
            ET_HIOS = 0xfeff, // OS-specific range end
            ET_LOPROC = 0xff00, // Processor-specific range start
            ET_HIPROC = 0xffff, // Processor-specific range end
        };

        // Legal values for e_machine (Architecture)

        enum
        {
            EM_NONE = 0, // No machine
            EM_M32 = 1, // AT&T WE 32100
            EM_SPARC = 2, // SUN SPARC
            EM_386 = 3, // Intel 80386
            EM_68K = 4, // Motorola m68k family
            EM_88K = 5, // Motorola m88k family
            EM_860 = 7, // Intel 80860
            EM_MIPS = 8, // MIPS R3000 big-endian
            EM_S370 = 9, // IBM System/370
            EM_MIPS_RS3_LE = 10, // MIPS R3000 little-endian
            EM_PARISC = 15, // HPPA
            EM_VPP500 = 17, // Fujitsu VPP500
            EM_SPARC32PLUS = 18, // Sun's "v8plus"
            EM_960 = 19, // Intel 80960
            EM_PPC = 20, // PowerPC
            EM_PPC64 = 21, // PowerPC 64-bit
            EM_S390 = 22, // IBM S390
            EM_V800 = 36, // NEC V800 series
            EM_FR20 = 37, // Fujitsu FR20
            EM_RH32 = 38, // TRW RH-32
            EM_RCE = 39, // Motorola RCE
            EM_ARM = 40, // ARM
            EM_FAKE_ALPHA = 41, // Digital Alpha
            EM_SH = 42, // Hitachi SH
            EM_SPARCV9 = 43, // SPARC v9 64-bit
            EM_TRICORE = 44, // Siemens Tricore
            EM_ARC = 45, // Argonaut RISC Core
            EM_H8_300 = 46, // Hitachi H8/300
            EM_H8_300H = 47, // Hitachi H8/300H
            EM_H8S = 48, // Hitachi H8S
            EM_H8_500 = 49, // Hitachi H8/500
            EM_IA_64 = 50, // Intel Merced
            EM_MIPS_X = 51, // Stanford MIPS-X
            EM_COLDFIRE = 52, // Motorola Coldfire
            EM_68HC12 = 53, // Motorola M68HC12
            EM_MMA = 54, // Fujitsu MMA Multimedia Accelerator
            EM_PCP = 55, // Siemens PCP
            EM_NCPU = 56, // Sony nCPU embeeded RISC
            EM_NDR1 = 57, // Denso NDR1 microprocessor
            EM_STARCORE = 58, // Motorola Start*Core processor
            EM_ME16 = 59, // Toyota ME16 processor
            EM_ST100 = 60, // STMicroelectronic ST100 processor
            EM_TINYJ = 61, // Advanced Logic Corp. Tinyj emb.fam
            EM_X86_64 = 62, // AMD x86-64 architecture
            EM_PDSP = 63, // Sony DSP Processor
            EM_FX66 = 66, // Siemens FX66 microcontroller
            EM_ST9PLUS = 67, // STMicroelectronics ST9+ 8/16 mc
            EM_ST7 = 68, // STmicroelectronics ST7 8 bit mc
            EM_68HC16 = 69, // Motorola MC68HC16 microcontroller
            EM_68HC11 = 70, // Motorola MC68HC11 microcontroller
            EM_68HC08 = 71, // Motorola MC68HC08 microcontroller
            EM_68HC05 = 72, // Motorola MC68HC05 microcontroller
            EM_SVX = 73, // Silicon Graphics SVx
            EM_ST19 = 74, // STMicroelectronics ST19 8 bit mc
            EM_VAX = 75, // Digital VAX
            EM_CRIS = 76, // Axis Communications 32-bit embedded processor
            EM_JAVELIN = 77, // Infineon Technologies 32-bit embedded processor
            EM_FIREPATH = 78, // Element 14 64-bit DSP Processor
            EM_ZSP = 79, // LSI Logic 16-bit DSP Processor
            EM_MMIX = 80, // Donald Knuth's educational 64-bit processor
            EM_HUANY = 81, // Harvard University machine-independent object files
            EM_PRISM = 82, // SiTera Prism
            EM_AVR = 83, // Atmel AVR 8-bit microcontroller
            EM_FR30 = 84, // Fujitsu FR30
            EM_D10V = 85, // Mitsubishi D10V
            EM_D30V = 86, // Mitsubishi D30V
            EM_V850 = 87, // NEC v850
            EM_M32R = 88, // Mitsubishi M32R
            EM_MN10300 = 89, // Matsushita MN10300
            EM_MN10200 = 90, // Matsushita MN10200
            EM_PJ = 91, // picoJava
            EM_OPENRISC = 92, // OpenRISC 32-bit embedded processor
            EM_ARC_A5 = 93, // ARC Cores Tangent-A5
            EM_XTENSA = 94, // Tensilica Xtensa Architecture
            EM_AARCH64 = 183, // ARM AARCH64
            EM_TILEPRO = 188, // Tilera TILEPro
            EM_MICROBLAZE = 189, // Xilinx MicroBlaze
            EM_TILEGX = 191, // Tilera TILE-Gx
            EM_NUM = 192,
        };

        // Legal values for e_version (Version)
        enum
        {
            EV_NONE = 0, // Invalid ELF version
            EV_CURRENT = 1, // Current version
            EV_NUM = 2,
        };

        // Elf section header
        template <class Word, class Xword, class Addr, class Off>
        struct Elf_Shdr
        {
            Word sh_name; // Section name (string tbl index)
            Word sh_type; // Section type
            Word sh_flags; // Section flags
            Addr sh_addr; // Section virtual addr at execution
            Off sh_offset; // Section file offset
            Xword sh_size; // Section size in bytes
            Word sh_link; // Link to another section
            Word sh_info; // Additional section information
            Xword sh_addralign; // Section alignment
            Xword sh_entsize; // Entry size if section holds table
        };

        typedef Elf_Shdr<Elf32_Word, Elf32_Xword, Elf32_Addr, Elf32_Off>
                Elf32_Shdr;
        typedef Elf_Shdr<Elf64_Word, Elf64_Xword, Elf64_Addr, Elf64_Off>
                Elf64_Shdr;

        // Legal values for sh_type (section type)
        enum
        {
            SHT_NULL = 0, // Section header table entry unused
            SHT_PROGBITS = 1, // Program data
            SHT_SYMTAB = 2, // Symbol table
            SHT_STRTAB = 3, // String table
            SHT_RELA = 4, // Relocation entries with addends
            SHT_HASH = 5, // Symbol hash table
            SHT_DYNAMIC = 6, // Dynamic linking information
            SHT_NOTE = 7, // Notes
            SHT_NOBITS = 8, // Program space with no data (bss)
            SHT_REL = 9, // Relocation entries, no addends
            SHT_SHLIB = 10, // Reserved
            SHT_DYNSYM = 11, // Dynamic linker symbol table
            SHT_INIT_ARRAY = 14, // Array of constructors
            SHT_FINI_ARRAY = 15, // Array of destructors
            SHT_PREINIT_ARRAY = 16, // Array of pre-constructors
            SHT_GROUP = 17, // Section group
            SHT_SYMTAB_SHNDX = 18, // Extended section indeces
            SHT_NUM = 19, // Number of defined types
            SHT_LOOS = 0x60000000, // Start OS-specific
            SHT_GNU_ATTRIBUTES = 0x6ffffff5, // Object attributes
            SHT_GNU_HASH = 0x6ffffff6, // GNU-style hash table
            SHT_GNU_LIBLIST = 0x6ffffff7, // Prelink library list
            SHT_CHECKSUM = 0x6ffffff8, // Checksum for DSO content
            SHT_LOSUNW = 0x6ffffffa, // Sun-specific low bound
            SHT_SUNW_move = 0x6ffffffa,
            SHT_SUNW_COMDAT = 0x6ffffffb,
            SHT_SUNW_syminfo = 0x6ffffffc,
            SHT_GNU_verdef = 0x6ffffffd, // Version definition section
            SHT_GNU_verneed = 0x6ffffffe, // Version needs section
            SHT_GNU_versym = 0x6fffffff, // Version symbol table
            SHT_HISUNW = 0x6fffffff, // Sun-specific high bound
            SHT_HIOS = 0x6fffffff, // End OS-specific type
            SHT_LOPROC = 0x70000000, // Start of processor-specific
            SHT_HIPROC = 0x7fffffff, // End of processor-specific
            SHT_LOUSER = 0x80000000, // Start of application-specific
            SHT_HIUSER = 0x8fffffff, // End of application-specific
        };

        // Legal values for sh_flags (Section flags)
        enum
        {
            SHF_WRITE = (1 << 0), // Writable
            SHF_ALLOC = (1 << 1), // Occupies memory during execution
            SHF_EXECINSTR = (1 << 2), // Executable
            SHF_MERGE = (1 << 4), // Might be merged
            SHF_STRINGS = (1 << 5), // Contains nul-terminated strings
            SHF_INFO_LINK = (1 << 6), // `sh_info' contains SHT index
            SHF_LINK_ORDER = (1 << 7), // Preserve order after combining
            SHF_OS_NONCONFORMING = (1 << 8), // Non-standard OS specific
                                             // handling required
            SHF_GROUP = (1 << 9), // Section is member of a group
            SHF_TLS = (1 << 10), // Section hold thread-local data
            SHF_MASKOS = 0x0ff00000, // OS-specific
            SHF_MASKPROC = 0xf0000000, // Processor-specific
            SHF_ORDERED = (1 << 30), // Special ordering requirement (Solaris)
            SHF_EXCLUDE = (1 << 31), // Section is excluded unless referenced
                                     // or allocated (Solaris)
        };

        // Symbol Table Entry
        template <class Word, class Xword, class Addr, class Section>
        struct Elf_Sym
        {
            Word st_name; // Symbol name (string tbl index)
            unsigned char st_info; // Symbol type and binding
            unsigned char st_other; // Symbol visibility
            Section st_shndx; // Section index
            Addr st_value; // Symbol value
            Xword st_size; // Symbol size

            unsigned char st_bind_get() const
            {
                return static_cast<unsigned char> (st_info) >> 4;
            }

            unsigned char st_type_get() const
            {
                return st_info & 0xF;
            }
        };

        typedef Elf_Sym <Elf32_Word, Elf32_Xword, Elf32_Addr, Elf32_Section>
                Elf32_Sym;

        typedef Elf_Sym <Elf64_Word, Elf64_Xword, Elf64_Addr, Elf64_Section>
                Elf64_Sym;

        // Possible values for si_boundto
        enum
        {
            SYMINFO_BT_SELF = 0xffff, // Symbol bound to self
            SYMINFO_BT_PARENT = 0xfffe, // Symbol bound to parent
            SYMINFO_BT_LOWRESERVE = 0xff00, // Beginning of reserved entries
        };

        // Possible bitmasks for si_flags
        enum
        {
            SYMINFO_FLG_DIRECT = 0x0001, // Direct bound symbol
            SYMINFO_FLG_PASSTHRU = 0x0002, // Pass-thru symbol for translator
            SYMINFO_FLG_COPY = 0x0004, // Symbol is a copy-reloc
            SYMINFO_FLG_LAZYLOAD = 0x0008, // Symbol bound to object to be lazy
                                           // loaded
        };

        // Syminfo version values
        enum
        {
            SYMINFO_NONE = 0,
            SYMINFO_CURRENT = 1,
            SYMINFO_NUM = 2,
        };

        // Legal values for ST_BIND subfield of st_info (symbol binding).  */
        enum
        {
            STB_LOCAL = 0, // Local symbol
            STB_GLOBAL = 1, // Global symbol
            STB_WEAK = 2, // Weak symbol
            STB_NUM = 3, // Number of defined types
            STB_LOOS = 10, // Start of OS-specific
            STB_GNU_UNIQUE = 10, // Unique symbol
            STB_HIOS = 12, // End of OS-specific
            STB_LOPROC = 13, // Start of processor-specific
            STB_HIPROC = 15, // End of processor-specific
        };

        // Legal values for ST_TYPE subfield of st_info (symbol type)
        enum
        {
            STT_NOTYPE = 0, // Symbol type is unspecified
            STT_OBJECT = 1, // Symbol is a data object
            STT_FUNC = 2, // Symbol is a code object
            STT_SECTION = 3, // Symbol associated with a section
            STT_FILE = 4, // Symbol's name is file name
            STT_COMMON = 5, // Symbol is a common data object
            STT_TLS = 6, // Symbol is thread-local data object
            STT_NUM = 7, // Number of defined types
            STT_LOOS = 1, // Start of OS-specific
            STT_GNU_IFUNC = 10, // Symbol is indirect code object
            STT_HIOS = 12, // End of OS-specific
            STT_LOPROC = 13, // Start of processor-specific
            STT_HIPROC = 15, // End of processor-specific
        };

        template <class Half>
        struct Elf_Syminfo
        {
            Half si_boundto; // Direct bindings, symbol bound to
            Half si_flags; // Per symbol flags
        };

        typedef Elf_Syminfo <Elf32_Half> Elf32_Syminfo;
        typedef Elf_Syminfo <Elf64_Half> Elf64_Syminfo;

    } // namespace elf
} // namespace ucmp

#endif /* !UCMP_MISC_ELF_HH */
