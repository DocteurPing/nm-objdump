/*
** EPITECH PROJECT, 2018
** nm
** File description:
** nm
*/

#include "objdump/objdump.h"

void		print_all(uint8_t *data, int size)
{
	int	i = 0;

	for (; i < 16; i++)
	{
		if (i < size)
			printf("%02x", data[i]);
		else
			printf("  ");
		if (!((i + 1) % 4))
			printf(" ");
	}
	printf(" ");
	for (i = 0; i < 16; i++)
	{
		if (i < size)
			printf("%c", isprint(data[i]) ? data[i] : '.');
		else
			printf(" ");
	}
	printf("\n");
}

void    print_section(Elf64_Shdr *shdr, char *strTab, Elf64_Ehdr *elf,
		uint8_t *data)
{
	int   i;
	size_t k;

	for (i = 1; i < elf->e_shnum &&
		(strcmp(&strTab[shdr[i].sh_name], ".symtab") != 0); i++) {
		if (strcmp(&strTab[shdr[i].sh_name], ".bss") == 0 ||
		strcmp(&strTab[shdr[i].sh_name], ".shstrtab") == 0)
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

void *checkfile(char *filename)
{
	int fd;
	void *file;

	fd = open(filename, O_RDONLY);
	if (fd == -1) {
		printf("nm: '%s': No such file\n", filename);
		return (NULL);
	}
	file = mmap(NULL, lseek(fd, 0, SEEK_END), PROT_READ, MAP_SHARED, fd, 0);
	if (file == MAP_FAILED)
		return (NULL);
	close(fd);
	return (file);
}

int my_objdump(char *filename)
{
	void *file = checkfile(filename);
	Elf64_Ehdr *elf;
	Elf64_Shdr *shdr;
	char *strtab;

	if (file == NULL)
		return (84);
	elf = (Elf64_Ehdr *) file;
	shdr = (Elf64_Shdr *) (file + elf->e_shoff);
	strtab = (char *)(file + shdr[elf->e_shstrndx].sh_offset);
	printf("\n%s:     file format %s\n", filename, "elf64-x86-64");
	printf("architecture: %s, flags 0x%08x:\n", "test",
	elf->e_flags);
	printf("start address 0x%016lx\n\n", elf->e_entry);
	print_section(shdr, strtab, elf, file);
	return (0);
}