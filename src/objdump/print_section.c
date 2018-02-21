/*
** EPITECH PROJECT, 2018
** obj
** File description:
** print_section
*/

#include "objdump/objdump.h"

static int	get_max_width64(Elf64_Shdr *shdr, int i)
{
	char hex[10];
	int size = (int)shdr[i].sh_addr + shdr[i].sh_size;

	sprintf(hex, "%x", size);
	return (strlen(hex) > 4 ? strlen(hex) : 4);
}

static int	get_max_width32(Elf32_Shdr *shdr, int i)
{
	char hex[10];
	int size = (int)shdr[i].sh_addr + shdr[i].sh_size;

	sprintf(hex, "%x", size);
	return (strlen(hex) > 4 ? strlen(hex) : 4);
}

void    print_section64(Elf64_Shdr *shdr, Elf64_Ehdr *elf,
		uint8_t *data, char *strTab)
{
	int   i;
	size_t k;

	for (i = 1; i < elf->e_shnum; i++) {
		if (strcmp(&strTab[shdr[i].sh_name], ".bss") == 0 ||
		strcmp(&strTab[shdr[i].sh_name], ".shstrtab") == 0 ||
		strcmp(&strTab[shdr[i].sh_name], ".symtab") == 0)
			continue;
		printf("Contents of section %s:\n", &strTab[shdr[i].sh_name]);
		for (k = shdr[i].sh_offset;
			k < shdr[i].sh_offset + shdr[i].sh_size; k += 16) {
			printf(" %0*x ", get_max_width64(shdr, i),
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

	for (i = 1; i < elf->e_shnum; i++) {
		if (strcmp(&strTab[shdr[i].sh_name], ".bss") == 0 ||
		strcmp(&strTab[shdr[i].sh_name], ".shstrtab") == 0 ||
		strcmp(&strTab[shdr[i].sh_name], ".symtab") == 0)
			continue;
		printf("Contents of section %s:\n", &strTab[shdr[i].sh_name]);
		for (k = shdr[i].sh_offset;
			k < shdr[i].sh_offset + shdr[i].sh_size; k += 16) {
			printf(" %0*x ", get_max_width32(shdr, i),
			(int)(shdr[i].sh_addr + k - shdr[i].sh_offset));
			print_all(data + k,
				shdr[i].sh_offset + shdr[i].sh_size - k);
		}
	}
}