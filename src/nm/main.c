/*
** EPITECH PROJECT, 2018
** nm
** File description:
** main
*/

#include "nm/nm.h"

int	main(int argc, char **argv) {
	int	i;

	setlocale(LC_MESSAGES, "");
	setlocale(LC_CTYPE, "");
	setlocale(LC_COLLATE, "");
	if (argc <= 1)
		return (my_nm("a.out", argv[0]));
	for (i = 1; i < argc; i++) {
		my_nm(argv[i], argv[0]);
	}
	return (0);
}