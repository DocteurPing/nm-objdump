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

int	my_objdump(char *);

#endif