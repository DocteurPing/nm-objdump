/*
** EPITECH PROJECT, 2018
** nm
** File description:
** nm
*/

#include "nm/nm.h"

void *checkfile(char *filename, char *argv0)
{
	int fd;
	void *file;
	const unsigned char magic1[4] = {0x7f, 0x45, 0x4c, 0x46};

	fd = open(filename, O_RDONLY);
	if (fd == -1) {
		printf("%s: '%s': No such file\n", argv0, filename);
		return (NULL);
	}
	file = mmap(NULL, lseek(fd, 0, SEEK_END), PROT_READ, MAP_SHARED, fd, 0);
	if (file == MAP_FAILED)
		return (NULL);
	close(fd);
	if (memcmp(file, magic1, sizeof(magic1)) != 0) {
		printf("%s: %s: File format not recognized\n", argv0, filename);
		return (NULL);
	}
	return (file);
}

int my_nm(char *filename, char *argv0)
{
	uint8_t *file = checkfile(filename, argv0);

	if (file == NULL)
		return (84);
	if (file[4] == 1)
		section32(file);
	else if (file[4] == 2)
		section64(file);
	else
		printf("%s: %s: File format not recognized\n", argv0, filename);
	return (0);
}