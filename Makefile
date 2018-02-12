##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

SRCNM	=	src/nm/main.c

SRCOBJ	=	src/objdump/main.c

OBJNM	=	$(SRCNM:.c=.o)

OBJOBJ	=	$(SRCOBJ:.c=.o)

NAMENM	=	my_nm

NAMEOBJ	=	my_objdump


nm:	$(OBJNM)
	gcc -W -Wall -Wextra $(OBJNM) -o $(NAMENM)

obj:	$(OBJOBJ)
	gcc -W -Wall -Wextra $(OBJOBJ) -o $(NAMEOBJ)

all:	nm obj

clean:
	rm -f $(OBJNM)
	rm -f $(OBJOBJ)

fclean:	clean
	rm -f $(NAMENM)
	rm -f $(NAMEOBJ)

re:	fclean all