#include <stdio.h>
#include <stdlib.h>
#include <elf.h>

int main(int argc, char *argv[]) {
  FILE *fp;
  Elf32_Ehdr elf_hdr;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s elf_file\n", argv[0]);
    exit(1);
  }

  fp = fopen(argv[1], "rb");
  if (fp == NULL) {
    fprintf(stderr, "Could not open file %s\n", argv[1]);
    exit(1);
  }

  if (fread(&elf_hdr, sizeof(elf_hdr), 1, fp) != 1) {
    fprintf(stderr, "Could not read ELF header from file %s\n", argv[1]);
    exit(1);
  }

  /* Print out the ELF header information. */
  printf("ELF Header:\n");
  printf("  Magic:      0x%08x\n", elf_hdr.e_ident[EI_MAG0]);
  printf("  Class:      %d\n", elf_hdr.e_ident[EI_CLASS]);
  printf("  Data:       %d\n", elf_hdr.e_ident[EI_DATA]);
  printf("  Version:    %d\n", elf_hdr.e_ident[EI_VERSION]);
  printf("  OS/ABI:      %d\n", elf_hdr.e_ident[EI_OSABI]);
  printf("  ABI Version: %d\n", elf_hdr.e_version);
  printf("  Type:       %d\n", elf_hdr.e_type);
  printf("  Entry point: 0x%08x\n", elf_hdr.e_entry);

  fclose(fp);

  return 0;
}
