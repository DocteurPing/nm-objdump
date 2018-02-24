/*
** EPITECH PROJECT, 2018
** obj
** File description:
** main
*/

#include "objdump/objdump.h"

int	main(int argc, char **argv) {
	int	i;

	if (argc <= 1)
		return (my_objdump("a.out", argv[0]));
	for (i = 1; i < argc; i++) {
		my_objdump(argv[i], argv[0]);
	}
	return (0);
}