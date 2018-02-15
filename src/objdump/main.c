/*
** EPITECH PROJECT, 2018
** nm
** File description:
** main
*/

#include "objdump/objdump.h"

int	main(int argc, char **argv) {
	int	i;

	if (argc <= 1)
		return (my_objdump("a.out"));
	for (i = 0; i < argc; i++) {
		my_objdump(argv[i]);
	}
	return (0);
}