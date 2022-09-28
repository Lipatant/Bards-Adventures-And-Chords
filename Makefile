##
## BARDS - VIRGILE (LIPATANT) BERRIER, 2022
## Makefile
## File description:
## Makefile de Bard: Adventures and Chors
##

SRC	=	../main.c

BUILDDIR = build

OBJ = $(patsubst %.c, $(BUILDDIR)/%.o, $(SRC))

$(BUILDDIR)/%.o: 	src/%.c
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

NAME	=	bards

LDFLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio \
			-L./lib/my -lmy

IDIR	=	include

CPPFLAGS	=	$(LCSFML) -I$(IDIR) -I./include

CFLAGS	=	-W -Wextra

GCCFLAG	=	gcc -o

FDEBUG	=	-g3

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C lib/my/
	$(GCCFLAG) $(NAME) $(OBJ) $(LDFLAGS)

debug:	$(OBJ)
	$(MAKE) -C lib/my/
	$(GCCFLAG) $(NAME) $(OBJ) $(LDFLAGS) $(FDEBUG)

debug_play:	fclean debug
	clear
	valgrind --track-origins=yes ./$(NAME)

clean:
	$(MAKE) clean -C lib/my/
	$(RM) -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C lib/my/
	$(RM) -f $(NAME)

play:	$(NAME)
	./$(NAME)

re:	fclean all

.PHONY: all debug debug_play fclean clean play re
