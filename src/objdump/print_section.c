/*
** EPITECH PROJECT, 2018
** obj
** File description:
** print_section
*/

#include "objdump/objdump.h"

void    print_section64(Elf64_Shdr *shdr, Elf64_Ehdr *elf,
		uint8_t *data, char *strTab)
{
	int   i;
	size_t k;

	for (i = 1; i < elf->e_shnum &&
		(strcmp(&strTab[shdr[i].sh_name], ".symtab") != 0); i++) {
		if (strcmp(&strTab[shdr[i].sh_name], ".bss") == 0 ||
		strcmp(&strTab[shdr[i].sh_name], ".shstrtab") == 0 ||
		strcmp(&strTab[shdr[i].sh_name], ".eh_frame") == 0)
			continue;
		printf("Contents of section %s:\n", &strTab[shdr[i].sh_name]);
		for (k = shdr[i].sh_offset;
			k < shdr[i].sh_offset + shdr[i].sh_size; k += 16) {
			printf(" %04x ",
			(int)(shdr[i].sh_addr + k - shdr[i].sh_offset));
			print_all(data + k,
				shdr[i].sh_offset + shdr[i].sh_size - k);
		}
	}
}

void    print_section32(Elf32_Shdr *shdr, Elf32_Ehdr *elf,
		uint8_t *data, char *strTab)
{
	int   i;
	size_t k;
	
	for (i = 1; i < elf->e_shnum &&
		(strcmp(&strTab[shdr[i].sh_name], ".symtab") != 0); i++) {
		if (strcmp(&strTab[shdr[i].sh_name], ".bss") == 0 ||
		strcmp(&strTab[shdr[i].sh_name], ".shstrtab") == 0 ||
		strcmp(&strTab[shdr[i].sh_name], ".eh_frame") == 0)
			continue;
		printf("Contents of section %s:\n", &strTab[shdr[i].sh_name]);
		for (k = shdr[i].sh_offset;
			k < shdr[i].sh_offset + shdr[i].sh_size; k += 16) {
			printf(" %04x ",
			(int)(shdr[i].sh_addr + k - shdr[i].sh_offset));
			print_all(data + k,
				shdr[i].sh_offset + shdr[i].sh_size - k);
		}
	}
}