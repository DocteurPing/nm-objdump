/*
** EPITECH PROJECT, 2018
** obj
** File description:
** header
*/

#include "objdump/objdump.h"

void	print_header32(void *file, char *filename)
{
	Elf32_Ehdr *elf;
	Elf32_Shdr *shdr;
	char *strTab;

	elf = (Elf32_Ehdr *) file;
	shdr = (Elf32_Shdr *) (file + elf->e_shoff);
	strTab = (char *)(file + shdr[elf->e_shstrndx].sh_offset);
	printf("\n%s:     file format %s\n", filename, "elf32-i386");
	printf("architecture: %s, flags 0x%08x:\n", "i386", 0);
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
	printf("architecture: %s, flags 0x%08x:\n", "i386:x86-64", 0);
	printf("start address 0x%016lx\n\n", elf->e_entry);
	print_section64(shdr, elf, file, strTab);
}