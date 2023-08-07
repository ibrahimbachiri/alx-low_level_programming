#include <stdio.h>
#include <elf.h>

/**
 * print_error - Print an error message.
 * @msg: The error message to be printed.
 */
void print_error(char *msg)
{
	printf("Error: %s\n", msg);
}

/**
 * print_elf_header_info - Print information from the ELF header.
 * @ehdr: Pointer to the ELF header structure.
 */
void print_elf_header_info(Elf64_Ehdr *ehdr)
{
	int i;

	printf("ELF Header:\n");

	printf("  Magic:  ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%2.2x ", ehdr->e_ident[i]);
	printf("\n");

	printf("  Class:                             %s\n", (ehdr->e_ident[EI_CLASS] == ELFCLASS64) ? "ELF64" : "Invalid class");

	printf("  Data:                              %s\n", (ehdr->e_ident[EI_DATA] == ELFDATA2LSB) ? "2's complement, little endian" : "Invalid data encoding");

	printf("  Version:                           %d\n", ehdr->e_ident[EI_VERSION]);

	printf("  OS/ABI:                            ");
	switch (ehdr->e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV: printf("UNIX - System V\n"); break;
		case ELFOSABI_HPUX: printf("UNIX - HP-UX\n"); break;
		case ELFOSABI_NETBSD: printf("UNIX - NetBSD\n"); break;
		case ELFOSABI_LINUX: printf("UNIX - Linux\n"); break;
		case ELFOSABI_SOLARIS: printf("UNIX - Solaris\n"); break;
		case ELFOSABI_IRIX: printf("UNIX - IRIX\n"); break;
		case ELFOSABI_FREEBSD: printf("UNIX - FreeBSD\n"); break;
		case ELFOSABI_TRU64: printf("UNIX - TRU64\n"); break;
		case ELFOSABI_ARM: printf("UNIX - ARM architecture\n"); break;
		default: printf("Unknown OS/ABI\n"); break;
	}

	printf("  ABI Version:                       %d\n", ehdr->e_ident[EI_ABIVERSION]);

	printf("  Type:                              ");
	switch (ehdr->e_type)
	{
		case ET_NONE: printf("Unknown\n"); break;
		case ET_REL: printf("Relocatable\n"); break;
		case ET_EXEC: printf("Executable\n"); break;
		case ET_DYN: printf("Shared Object\n"); break;
		case ET_CORE: printf("Core File\n"); break;
		default: printf("Unknown Type\n"); break;
	}

	printf("  Entry point address:               0x%lx\n", (unsigned long)ehdr->e_entry);

	printf("  Start of program headers:          %lu (bytes into file)\n", (unsigned long)ehdr->e_phoff);

	printf("  Start of section headers:          %lu (bytes into file)\n", (unsigned long)ehdr->e_shoff);

	printf("  Flags:                             0x%x\n", ehdr->e_flags);

	printf("  Size of this header:               %lu (bytes)\n", (unsigned long)ehdr->e_ehsize);

	printf("  Size of program headers:           %lu (bytes)\n", (unsigned long)ehdr->e_phentsize);

	printf("  Number of program headers:         %lu\n", (unsigned long)ehdr->e_phnum);

	printf("  Size of section headers:           %lu (bytes)\n", (unsigned long)ehdr->e_shentsize);

	printf("  Number of section headers:         %lu\n", (unsigned long)ehdr->e_shnum);

	printf("  Section header string table index: %lu\n", (unsigned long)ehdr->e_shstrndx);
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of pointers to command-line arguments.
 * Return: 0 on success, 1 on failure.
 */
int main(int argc, char *argv[])
{
	FILE *file;
	Elf64_Ehdr ehdr;

	if (argc < 2)
	{
		print_error("Missing file argument.");
		return (1);
	}

	file = fopen(argv[1], "rb");
	if (file == NULL)
	{
		print_error("Cannot open file.");
		return (1);
	}

	if (fread(&ehdr, sizeof(ehdr), 1, file) != 1)
	{
		print_error("Failed to read ELF header.");
		fclose(file);
		return (1);
	}

	if (ehdr.e_ident[EI_MAG0] != ELFMAG0 || ehdr.e_ident[EI_MAG1] != ELFMAG1 || ehdr.e_ident[EI_MAG2] != ELFMAG2 || ehdr.e_ident[EI_MAG3] != ELFMAG3)
	{
		print_error("Not an ELF file.");
		fclose(file);
		return (1);
	}

	print_elf_header_info(&ehdr);

	fclose(file);
	return (0);
}
