/*
** EPITECH PROJECT, 2018
** nm
** File description:
** sort_symbol_tab
*/

#include "nm/nm.h"

int my_tablen(symbol *tab)
{
	int i = 0;

	for (; tab[i].is_the_last == FALSE; i++);
	return (i);
}

int my_sort(const void *p1, const void *p2)
{
	symbol *s1 = (symbol *)p1;
	symbol *s2 = (symbol *)p2;
	return (strcoll(s1->name, s2->name));
}

void sort_symbol_tab(symbol *tab)
{
	qsort(tab, my_tablen(tab), sizeof(symbol), my_sort);
}