/*
** EPITECH PROJECT, 2018
** nm
** File description:
** include
*/

#ifndef NM_H_
# define NM_H_

# include <sys/stat.h>
# include <sys/mman.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <elf.h>
# include <string.h>

typedef struct	symbol
{
	char		*name;
	Elf64_Addr	addr;
	char		flag;
	char		end;
}		symbol;

typedef struct	sym_tab64
{
	Elf64_Sym	*sym;
	int		size;
}		sym_tab64;

typedef struct	sym_tab32
{
	Elf32_Sym	*sym;
	int		size;
}		sym_tab32;

int	my_nm(char *);
void	section64(void *file, char *filename);
void	section32(void *file, char *filename);
sym_tab64	find_sym_tab64(Elf64_Shdr *shdr, Elf64_Ehdr *elf, char *strTab,
			uint8_t *data);
sym_tab32	find_sym_tab32(Elf32_Shdr *shdr, Elf32_Ehdr *elf, char *strTab,
			uint8_t *data);
char	*find_name_tab64(Elf64_Shdr *shdr, Elf64_Ehdr *elf, char *strTab,
			uint8_t *data);
char	*find_name_tab32(Elf32_Shdr *shdr, Elf32_Ehdr *elf, char *strTab,
			uint8_t *data);

#endif