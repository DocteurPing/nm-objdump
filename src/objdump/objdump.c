/*
** EPITECH PROJECT, 2018
** nm
** File description:
** nm
*/

#include "objdump/objdump.h"

void    print_section(Elf64_Shdr *shdr, char *strTab, int shNum, uint8_t *data)
{
	int   i;  

	for(i = 0; i < shNum && 
		(strcmp(&strTab[shdr[i].sh_name], ".symtab") != 0); i++) {
		size_t k;
		printf("Contents of section %s:\n", &strTab[shdr[i].sh_name]);
		for (k = shdr[i].sh_offset; 
			k < shdr[i].sh_offset + shdr[i].sh_size; k++) {
			printf("%04x", data[k]);
		}   
		printf(" ");
		for (k = shdr[i].sh_offset; 
			k < shdr[i].sh_offset + shdr[i].sh_size; k++) {
			printf("%c", isprint(data[k]) ? data[k] : '.');
		}   
		printf("\n");
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
	printf("flags: 0x%x\n", elf->e_flags);
	print_section(shdr, strtab, elf->e_shnum, file);
	return (0);
}