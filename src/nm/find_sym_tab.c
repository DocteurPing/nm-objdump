/*
** EPITECH PROJECT, 2018
** nm
** File description:
** find_sym_tab
*/

#include "nm/nm.h"

sym_tab64 find_sym_tab64(Elf64_Shdr *shdr, Elf64_Ehdr *elf, char *strTab,
			uint8_t *data)
{
	int i;
	int size;
	sym_tab64 sym_tab;

	for (i = 1; i < elf->e_shnum; i++) {
		if (strcmp(&strTab[shdr[i].sh_name], ".symtab") == 0) {
			sym_tab.sym = (Elf64_Sym *)
				(data + (shdr + i)->sh_offset);
			sym_tab.size = (shdr + i)->sh_size / sizeof(Elf64_Sym);
			break;
		}
	}
	return (sym_tab);
}

sym_tab32 find_sym_tab32(Elf32_Shdr *shdr, Elf32_Ehdr *elf, char *strTab,
			uint8_t *data)
{
	int i;
	int size;
	sym_tab32 sym_tab;

	for (i = 1; i < elf->e_shnum; i++) {
		if (strcmp(&strTab[shdr[i].sh_name], ".symtab") == 0) {
			sym_tab.sym = (Elf32_Sym *)
				(data + (shdr + i)->sh_offset);
			sym_tab.size = (shdr + i)->sh_size / sizeof(Elf64_Sym);
			break;
		}
	}
	return (sym_tab);
}
