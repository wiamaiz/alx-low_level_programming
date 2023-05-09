#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

#define BUFFER_SIZE 128

void print_error(char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(EXIT_FAILURE);
}

void print_elf_header(Elf64_Ehdr *hdr) {
    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++) {
        printf("%02x ", hdr->e_ident[i]);
    }
    printf("\n");
    printf("  Class:                             %s\n",
           hdr->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" :
           hdr->e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "Invalid class");
    printf("  Data:                              %s\n",
           hdr->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" :
           hdr->e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big endian" : "Invalid data encoding");
    printf("  Version:                           %d (current)\n", hdr->e_ident[EI_VERSION]);
    printf("  OS/ABI:                            ");
    switch (hdr->e_ident[EI_OSABI]) {
        case ELFOSABI_SYSV:
            printf("UNIX - System V\n");
            break;
        case ELFOSABI_LINUX:
            printf("UNIX - Linux\n");
            break;
        case ELFOSABI_NETBSD:
            printf("UNIX - NetBSD\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }
    printf("  ABI Version:                       %d\n", hdr->e_ident[EI_ABIVERSION]);
    printf("  Type:                              ");
    switch (hdr->e_type) {
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
        default:
            printf("Unknown\n");
            break;
    }
    printf("  Entry point address:               0x%lx\n", hdr->e_entry);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_error("Usage: elf_header elf_filename");
    }

    char *filename = argv[1];
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        print_error("Error opening file");
    }

    Elf64_Ehdr hdr;
    ssize_t n = read(fd, &hdr, sizeof(hdr));
    if (n != sizeof(hdr)) {
        print_error("Error reading ELF header");
    }

    if (hdr.e_ident[EI_MAG0] != ELFMAG0 ||
        hdr.e_ident[EI_MAG1] != ELFMAG1 ||
        hdr.e_ident[EI_MAG2] != ELFMAG2 ||
        hdr.e_ident[EI_MAG3] != ELFMAG3) {
        print_error("Invalid ELF magic number");
    }

    print_elf_header(&hdr);

    close(fd);
    exit(EXIT_SUCCESS);

