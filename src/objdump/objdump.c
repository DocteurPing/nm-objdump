/*
** EPITECH PROJECT, 2018
** obj
** File description:
** obj
*/

#include "objdump/objdump.h"

void		print_all(uint8_t *data, int size)
{
	int	i = 0;

	for (; i < 16; i++)
	{
		if (i < size)
			printf("%02x", data[i]);
		else
			printf("  ");
		if (!((i + 1) % 4))
			printf(" ");
	}
	printf(" ");
	for (i = 0; i < 16; i++)
	{
		if (i < size)
			printf("%c", isprint(data[i]) ? data[i] : '.');
		else
			printf(" ");
	}
	printf("\n");
}

void *checkfile(char *filename)
{
	int fd;
	void *file;
	const unsigned char magic1[4] = {0x7f, 0x45, 0x4c, 0x46};

	fd = open(filename, O_RDONLY);
	if (fd == -1) {
		printf("objdump: '%s': No such file\n", filename);
		return (NULL);
	}
	file = mmap(NULL, lseek(fd, 0, SEEK_END), PROT_READ, MAP_SHARED, fd, 0);
	if (file == MAP_FAILED)
		return (NULL);
	close(fd);
	if (memcmp(file, magic1, sizeof(magic1)) != 0)
		return (NULL);
	return (file);
}

int my_objdump(char *filename)
{
	uint8_t *file = checkfile(filename);

	if (file == NULL)
		return (84);
	if (file[4] == 1)
		print_header32(file, filename);
	else if (file[4] == 2)
		print_header64(file, filename);
	else
		printf("objdump: %s: File format not recognized", filename);
	return (0);
}