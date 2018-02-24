/*
** EPITECH PROJECT, 2018
** nm
** File description:
** find_type
*/

#include "nm/nm.h"

char	check_other_flags64(Elf64_Sym sym, Elf64_Shdr *shdr)
{
	if (shdr[sym.st_shndx].sh_type == SHT_NOBITS
		&& shdr[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE))
		return ('B');
	else if (shdr[sym.st_shndx].sh_type == SHT_PROGBITS
		&& (shdr[sym.st_shndx].sh_flags == SHF_ALLOC
		|| shdr[sym.st_shndx].sh_flags == (SHF_MERGE | SHF_ALLOC)))
		return ('R');
	else if ((shdr[sym.st_shndx].sh_type == SHT_PROGBITS
		&& shdr[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE))
		|| shdr[sym.st_shndx].sh_type == SHT_DYNAMIC)
		return ('D');
	else if ((shdr[sym.st_shndx].sh_type == SHT_PROGBITS
		&& shdr[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_EXECINSTR))
		|| shdr[sym.st_shndx].sh_type == SHT_INIT_ARRAY
		|| shdr[sym.st_shndx].sh_type == SHT_FINI_ARRAY)
		return ('T');
	return (0);
}

char	find_type64(Elf64_Sym sym, Elf64_Shdr *shdr, char *name)
{
	if (strncmp("wm4.", name, 4) == 0)
		return ('n');
	if (sym.st_shndx == SHN_UNDEF)
		return ('U');
	else if (sym.st_shndx == SHN_ABS)
		return ('A');
	else if (sym.st_shndx == SHN_COMMON)
		return ('C');
	if (ELF64_ST_BIND(sym.st_info) == STB_WEAK) {
		if (ELF64_ST_TYPE(sym.st_info) == STT_OBJECT)
			return (sym.st_shndx == SHN_UNDEF ? 'v' : 'V');
		return (sym.st_shndx == SHN_UNDEF ? 'w' : 'W');
	}
	if (ELF64_ST_BIND(sym.st_info) == STB_GNU_UNIQUE)
		return ('u');
	return (check_other_flags64(sym, shdr));
	
}