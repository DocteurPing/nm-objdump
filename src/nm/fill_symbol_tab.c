/*
** EPITECH PROJECT, 2018
** nm
** File description:
** fill_symbol_tab
*/

#include "nm/nm.h"

symbol	*fill_symbol_tab64(sym_tab64 symtab, char *nametab, Elf64_Shdr *shdr)
{
	symbol *tab;
	int	i = 0;
	int	j = 0;

	tab = malloc((sizeof(symbol) * symtab.size) + 1);
	if (tab == NULL)
		return (NULL);
	for (; i < symtab.size; i++) {
		if ((nametab + symtab.sym[i].st_name)[0] != '\0') {
			tab[j].name = nametab + symtab.sym[i].st_name;
			tab[j].addr = symtab.sym[i].st_value;
			tab[j].flag = find_type64(symtab.sym[i], shdr,
				tab[j].name);
			tab[j].is_the_last = FALSE;
			j++;
		}
	}
	tab[j].is_the_last = TRUE;
	return (tab);
}

symbol	*fill_symbol_tab32(sym_tab32 symtab, char *nametab, Elf32_Shdr *shdr)
{
	symbol *tab;
	int	i = 0;
	int	j = 0;

	tab = malloc((sizeof(symbol) * symtab.size) + 1);
	if (tab == NULL)
		return (NULL);
	for (; i < symtab.size; i++) {
		if ((nametab + symtab.sym[i].st_name)[0] != '\0') {
			tab[j].name = nametab + symtab.sym[i].st_name;
			tab[j].addr = symtab.sym[i].st_value;
			tab[j].flag = find_type32(symtab.sym[i], shdr,
				tab[j].name);
			tab[j].is_the_last = FALSE;
			j++;
		}
	}
	tab[j].is_the_last = TRUE;
	return (tab);
}