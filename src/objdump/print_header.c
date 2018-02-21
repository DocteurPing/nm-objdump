/*
** EPITECH PROJECT, 2018
** obj
** File description:
** header
*/

#include "objdump/objdump.h"

int	get_archi(int nbr)
{
	switch (nbr) {
		case ET_EXEC:
			return (112);
		case ET_DYN:
			return (150);
	}
	return (-1);
}

void	print_archi(int nbr)
{
	switch (nbr) {
		case ET_EXEC:
			printf("EXEC_P, HAS_SYMS, D_PAGED\n");
			break;
		case ET_DYN:
			printf("HAS_SYMS, DYNAMIC, D_PAGED\n");
			break;
	}
}

void	print_header32(void *file, char *filename)
{
	Elf32_Ehdr *elf;
	Elf32_Shdr *shdr;
	char *strTab;

	elf = (Elf32_Ehdr *) file;
	shdr = (Elf32_Shdr *) (file + elf->e_shoff);
	strTab = (char *)(file + shdr[elf->e_shstrndx].sh_offset);
	printf("\n%s:     file format %s\n", filename, "elf32-i386");
	printf("architecture: %s, flags 0x%08d:\n", "i386",
		get_archi(elf->e_type));
	print_archi(elf->e_type);
	printf("start address 0x%08x\n\n", elf->e_entry);
	print_section32(shdr, elf, file, strTab);
}

void	print_header64(void *file, char *filename)
{
	Elf64_Ehdr *elf;
	Elf64_Shdr *shdr;
	char *strTab;

	elf = (Elf64_Ehdr *) file;
	shdr = (Elf64_Shdr *) (file + elf->e_shoff);
	strTab = (char *)(file + shdr[elf->e_shstrndx].sh_offset);
	printf("\n%s:     file format %s\n", filename, "elf64-x86-64");
	printf("architecture: %s, flags 0x%08d:\n", "i386:x86-64",
		get_archi(elf->e_type));
	print_archi(elf->e_type);
	printf("start address 0x%016lx\n\n", elf->e_entry);
	print_section64(shdr, elf, file, strTab);
}