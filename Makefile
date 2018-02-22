##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

SRCNM	=	src/nm/main.c	\
		src/nm/nm.c

SRCOBJ	=	src/objdump/main.c		\
		src/objdump/objdump.c		\
		src/objdump/print_section.c	\
		src/objdump/print_header.c

OBJNM	=	$(SRCNM:.c=.o)

OBJOBJ	=	$(SRCOBJ:.c=.o)

CFLAGS  =	-W -Wall -Wextra -Iinclude -g3

NAMENM	=	my_nm

NAMEOBJ	=	my_objdump


all:	objdump nm

nm:	$(OBJNM)
	gcc $(CFLAGS) $(OBJNM) -o $(NAMENM)

objdump:	$(OBJOBJ)
	gcc $(CFLAGS) $(OBJOBJ) -o $(NAMEOBJ)

clean:
	rm -f $(OBJNM)
	rm -f $(OBJOBJ)

fclean:	clean
	rm -f $(NAMENM)
	rm -f $(NAMEOBJ)

re:	fclean all