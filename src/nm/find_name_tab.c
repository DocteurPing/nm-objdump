/*
** EPITECH PROJECT, 2018
** nm
** File description:
** find_name_tab
*/

#include "nm/nm.h"

char *find_name_tab64(Elf64_Shdr *shdr, Elf64_Ehdr *elf, char *strTab,
		uint8_t *data)
{
	int i;
	char *name;

	for (i = 1; i < elf->e_shnum; i++) {
		if (strcmp(&strTab[shdr[i].sh_name], ".strtab") == 0) {
			name = (char *)(data + (shdr + i)->sh_offset);
			break;
		}
	}
	return (name);
}

char *find_name_tab32(Elf32_Shdr *shdr, Elf32_Ehdr *elf, char *strTab,
		uint8_t *data)
{
	int i;
	char *name;

	for (i = 1; i < elf->e_shnum; i++) {
		if (strcmp(&strTab[shdr[i].sh_name], ".strtab") == 0) {
			name = (char *)(data + (shdr + i)->sh_offset);
			break;
		}
	}
	return (name);
}