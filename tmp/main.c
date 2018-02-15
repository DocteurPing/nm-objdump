#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>

int	filesize(int fd)
{
	return (lseek(fd, 0, SEEK_END));
}

void    print_section(Elf64_Shdr *shdr, char *strTab, int shNum)
{
	int   i = 1;

  	for(; i < shNum && (strcmp(&strTab[shdr[i].sh_name], ".symtab") != 0); i++)
		printf("%02d: %s\n", i, &strTab[shdr[i].sh_name]);
}

int 	main(int ac, char **av)
{
  	void		*data;
  	Elf64_Ehdr	*elf;
	Elf64_Shdr	*shdr;
  	int		fd;
  	char		*strtab;

  	fd = open(av[1], O_RDONLY);
  	data = mmap(NULL, filesize(fd), PROT_READ, MAP_SHARED, fd, 0);
  	elf = (Elf64_Ehdr *) data;
  	shdr = (Elf64_Shdr *) (data + elf->e_shoff);
  	strtab = (char *)(data + shdr[elf->e_shstrndx].sh_offset);
	printf("flags: 0x%x\n", elf->e_flags);
  	print_section(shdr, strtab, elf->e_shnum);
  	close(fd);
  	return 0;
}