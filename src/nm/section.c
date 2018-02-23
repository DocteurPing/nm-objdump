/*
** EPITECH PROJECT, 2018
** nm
** File description:
** section
*/

#include "nm/nm.h"

void section64(void *file)
{
	Elf64_Ehdr	*elf;
	Elf64_Shdr	*shdr;
	char		*strTab;
	sym_tab64	symtab;
	char		*nametab;
	symbol		*symboltab;

	elf = (Elf64_Ehdr *) file;
	shdr = (Elf64_Shdr *) (file + elf->e_shoff);
	strTab = (char *)(file + shdr[elf->e_shstrndx].sh_offset);
	symtab = find_sym_tab64(shdr, elf, strTab, file);
	nametab = find_name_tab64(shdr, elf, strTab, file);
	symboltab = fill_symbol_tab64(symtab, nametab, shdr);
	/* symboltab = sort_symbol_tab64();
	print_all(); */
}

void section32(void *file)
{
	Elf32_Ehdr	*elf;
	Elf32_Shdr	*shdr;
	char		*strTab;
	sym_tab32	symtab;
	char		*nametab;
	symbol		*symboltab;

	elf = (Elf32_Ehdr *) file;
	shdr = (Elf32_Shdr *) (file + elf->e_shoff);
	strTab = (char *)(file + shdr[elf->e_shstrndx].sh_offset);
	symtab = find_sym_tab32(shdr, elf, strTab, file);
	nametab = find_name_tab32(shdr, elf, strTab, file);
	/* symboltab = fill_symbol_tab32();
	symboltab = sort_symbol_tab32();
	print_all(); */
}