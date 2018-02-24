/*
** EPITECH PROJECT, 2018
** nm
** File description:
** include
*/

#ifndef OBJDUMP_H_
# define OBJDUMP_H_

# include <sys/stat.h>
# include <sys/mman.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <elf.h>
# include <string.h>
# include <ctype.h>

int	my_objdump(char *, char *);
void    print_section32(Elf32_Shdr *, Elf32_Ehdr *,
		uint8_t *, char *);
void    print_section64(Elf64_Shdr *, Elf64_Ehdr *,
		uint8_t *, char *);
void	print_all(uint8_t *, int);
void	print_header32(void *, char *);
void	print_header64(void *, char *);

#endif