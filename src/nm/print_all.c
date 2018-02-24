/*
** EPITECH PROJECT, 2018
** nm
** File description:
** print_all
*/

#include "nm/nm.h"

void	print_all(symbol *tab)
{
	int	i = 0;
	
	for(; tab[i].is_the_last == FALSE; i++) {
		if (tab[i].flag == 'U' || tab[i].flag == 'w')
			printf("                 %c %s\n", tab[i].flag,
				tab[i].name);
		else if (tab[i].addr != 0
	       || tab[i].flag == 't'
	       || tab[i].flag == 'n'
	       || tab[i].flag == 'T')
			printf("%016lx %c %s\n", tab[i].addr, tab[i].flag,
				tab[i].name);
    }
}