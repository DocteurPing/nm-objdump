##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

SRCNM	=	src/nm/main.c	\
		src/nm/nm.c

SRCOBJ	=	src/objdump/main.c	\
		src/objdump/objdump.c

OBJNM	=	$(SRCNM:.c=.o)

OBJOBJ	=	$(SRCOBJ:.c=.o)

CFLAGS  =	-W -Wall -Wextra -Iinclude

NAMENM	=	my_nm

NAMEOBJ	=	my_objdump


all:	obj nm

nm:	$(OBJNM)
	gcc $(CFLAGS) $(OBJNM) -o $(NAMENM)

obj:	$(OBJOBJ)
	gcc $(CFLAGS) $(OBJOBJ) -o $(NAMEOBJ)

clean:
	rm -f $(OBJNM)
	rm -f $(OBJOBJ)

fclean:	clean
	rm -f $(NAMENM)
	rm -f $(NAMEOBJ)

re:	fclean all