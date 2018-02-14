/*
** EPITECH PROJECT, 2018
** nm
** File description:
** main
*/

#include "nm/nm.h"

int	main(int argc, char **argv) {
	int	i;

	if (argc <= 1)
		return (my_nm("a.out"));
	for (i = 0; i < argc; i++) {
		my_nm(argv[i]);
	}
	return (0);
}