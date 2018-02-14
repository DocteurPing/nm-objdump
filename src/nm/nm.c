/*
** EPITECH PROJECT, 2018
** nm
** File description:
** nm
*/

#include "nm/nm.h"

void    *checkfile(char *filename)
{
	int		fd;
	void		*file;

	fd = open(filename, O_RDONLY);
	if (fd == -1) {
		printf("nm: '%s': No such file\n", filename);
		return (NULL);
	}
	file = mmap(NULL, lseek(fd, 0, SEEK_END), PROT_READ, MAP_SHARED, fd, 0);
	if (file == MAP_FAILED)
		return (NULL);
	close(fd);
	return (file);
}

int	my_nm(char *filename)
{
	void *file = checkfile(filename);

	if (file == NULL)
		return (84);
	printf("%s", (char *)file);
	return (0);
}