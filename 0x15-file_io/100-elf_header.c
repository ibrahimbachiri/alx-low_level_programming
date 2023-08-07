#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <elf.h>
#include <string.h>

/**
 * print_error - Prints an error message to stderr and exits with status code 98.
 * @message: The error message to print.
 */
void print_error(const char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(98);
}

/**
 * print_elf_header_info - Prints the information from the ELF header.
 * @header: A pointer to the ELF header structure.
 */
void print_elf_header_info(Elf64_Ehdr *header)
{
    char magic[16];
    memcpy(magic, header->e_ident, EI_NIDENT);

    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (int i = 0; i < 16; i++)
        printf("%02x ", (unsigned char)magic[i]);
    printf("\n");

    printf("  Class:                             ");
    switch (header->e_ident[EI_CLASS])
    {
    case ELFCLASS32:
        printf("ELF32\n");
        break;
    case ELFCLASS64:
        printf("ELF64\n");
        break;
    default:
        printf("<unknown>\n");
        break;
    }

    printf("  Data:                              ");
    switch (header->e_ident[EI_DATA])
    {
    case ELFDATA2LSB:
        printf("2's complement, little endian\n");
        break;
    case ELFDATA2MSB:
        printf("2's complement, big endian\n");
        break;
    default:
        printf("<unknown>\n");
        break;
    }

    printf("  Version:                           %d (current)\n", header->e_ident[EI_VERSION]);

    printf("  OS/ABI:                            ");
    switch (header->e_ident[EI_OSABI])
    {
    case ELFOSABI_SYSV:
        printf("UNIX - System V\n");
        break;
    case ELFOSABI_NETBSD:
        printf("UNIX - NetBSD\n");
        break;
    // Add other OS/ABI values as needed.
    default:
        printf("<unknown: %02x>\n", header->e_ident[EI_OSABI]);
        break;
    }

    printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);

    printf("  Type:                              ");
    switch (header->e_type)
    {
    case ET_NONE:
        printf("NONE (Unknown type)\n");
        break;
    case ET_REL:
        printf("REL (Relocatable file)\n");
        break;
    case ET_EXEC:
        printf("EXEC (Executable file)\n");
        break;
    case ET_DYN:
        printf("DYN (Shared object file)\n");
        break;
    case ET_CORE:
        printf("CORE (Core file)\n");
        break;
    // Add other e_type values as needed.
    default:
        printf("<unknown: %x>\n", header->e_type);
        break;
    }

    printf("  Entry point address:               0x%lx\n", header->e_entry);
}

/**
 * main - Program entry point.
 * @argc: The number of command-line arguments (including the program name).
 * @argv: An array of strings containing the command-line arguments.
 *
 * Return: 0 on success, or exit with status code 98 on error.
 */
int main(int argc, char *argv[])
{
    int fd;
    Elf64_Ehdr header;

    if (argc != 2)
        print_error("Usage: elf_header elf_filename");

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        print_error("Error: Unable to open the ELF file");

    if (read(fd, &header, sizeof(header)) != sizeof(header))
        print_error("Error: Unable to read ELF header");

    if (memcmp(header.e_ident, ELFMAG, SELFMAG) != 0)
        print_error("Error: Not an ELF file");

    print_elf_header_info(&header);

    close(fd);
    return 0;
}
