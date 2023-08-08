#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define EI_NIDENT 16
#define ELFCLASSNONE 0
#define ELFCLASS32 1
#define ELFCLASS64 2
#define ELFDATANONE 0
#define ELFDATA2LSB 1
#define ELFDATA2MSB 2
#define EI_CLASS 4
#define EI_DATA 5
#define EI_VERSION 6
#define EI_OSABI 7
#define EI_ABIVERSION 8

typedef struct {
    unsigned char e_ident[EI_NIDENT];
    unsigned short e_type;
    unsigned short e_machine;
    unsigned long e_version;
    unsigned long e_entry;
    unsigned long e_phoff;
    unsigned long e_shoff;
    unsigned long e_flags;
    unsigned short e_ehsize;
    unsigned short e_phentsize;
    unsigned short e_phnum;
    unsigned short e_shentsize;
    unsigned short e_shnum;
    unsigned short e_shstrndx;
} Elf64_Ehdr;

void print_elf_header(const char *filename);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <elf-file>\n", argv[0]);
        return 1;
    }

    print_elf_header(argv[1]);

    return 0;
}

void print_elf_header(const char *filename) {
    int fd, i;
    ssize_t bytes_read;
    Elf64_Ehdr header;

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        exit(1);
    }

    bytes_read = read(fd, &header, sizeof(header));
    if (bytes_read != sizeof(header)) {
        perror("Error reading file");
        close(fd);
        exit(1);
    }

    /* Print ELF header information */
    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (i = 0; i < EI_NIDENT; i++) {
        printf("%02x ", header.e_ident[i]);
    }
    printf("\n");

    printf("  Class:                             ");
    switch (header.e_ident[EI_CLASS]) {
        case ELFCLASSNONE: printf("none\n"); break;
        case ELFCLASS32:   printf("ELF32\n"); break;
        case ELFCLASS64:   printf("ELF64\n"); break;
        default:           printf("<unknown: %x>\n", header.e_ident[EI_CLASS]);
    }

    printf("  Data:                              ");
    switch (header.e_ident[EI_DATA]) {
        case ELFDATANONE: printf("none\n"); break;
        case ELFDATA2LSB: printf("2's complement, little endian\n"); break;
        case ELFDATA2MSB: printf("2's complement, big endian\n"); break;
        default:          printf("<unknown: %x>\n", header.e_ident[EI_DATA]);
    }

    printf("  Version:                           %d\n", header.e_ident[EI_VERSION]);

    printf("  OS/ABI:                            ");
    switch (header.e_ident[EI_OSABI]) {
        /* ... (other cases for OS/ABI) */
    }

    printf("  ABI Version:                       %d\n", header.e_ident[EI_ABIVERSION]);

    /* ... (similar print functions for other fields) */

    close(fd);
}
