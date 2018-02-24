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
# include <stdlib.h>
# include <locale.h>

typedef enum
{
	FALSE,
	TRUE
} 	bool;

typedef struct	symbol
{
	char		*name;
	Elf64_Addr	addr;
	char		flag;
	bool		is_the_last;
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

int	my_nm(char *, char *);
void	section64(void *file);
void	section32(void *file);
sym_tab64	find_sym_tab64(Elf64_Shdr *shdr, Elf64_Ehdr *elf, char *strTab,
			uint8_t *data);
sym_tab32	find_sym_tab32(Elf32_Shdr *shdr, Elf32_Ehdr *elf, char *strTab,
			uint8_t *data);
char	*find_name_tab64(Elf64_Shdr *shdr, Elf64_Ehdr *elf, char *strTab,
			uint8_t *data);
char	*find_name_tab32(Elf32_Shdr *shdr, Elf32_Ehdr *elf, char *strTab,
			uint8_t *data);
char	find_type64(Elf64_Sym sym, Elf64_Shdr *shdr, char *name);
char	find_type32(Elf32_Sym sym, Elf32_Shdr *shdr, char *name);
symbol	*fill_symbol_tab64(sym_tab64 symtab, char *nametab, Elf64_Shdr *shdr);
symbol	*fill_symbol_tab32(sym_tab32 symtab, char *nametab, Elf32_Shdr *shdr);
void	print_all(symbol *tab);
void sort_symbol_tab(symbol *tab);

#endif