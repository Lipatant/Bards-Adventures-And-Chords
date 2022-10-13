##
## BARDS - VIRGILE (LIPATANT) BERRIER, 2022
## Makefile
## File description:
## Makefile de Bard: Adventures and Chors
##

SRC	=	./main.cpp															\
		./start.cpp															\

BUILDDIR = build

OBJ = $(patsubst %.cpp, $(BUILDDIR)/%.o, $(SRC))

$(BUILDDIR)/%.o: 	src/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

NAME	=	bards

IDIR	=	include

CPPFLAGS	=	-I$(IDIR) -I./include

CFLAGS	=	-W -Wextra

GCCFLAG	=	g++ -o

FDEBUG	=	-g3

LOGSFILE	=	logs.txt

all:	$(NAME)

$(NAME):	$(OBJ)
	$(GCCFLAG) $(NAME) $(OBJ) $(LDFLAGS) > $(LOGSFILE)

debug:	$(OBJ)
	$(GCCFLAG) $(NAME) $(OBJ) $(LDFLAGS) $(FDEBUG) > $(LOGSFILE)

debug_play:	fclean debug
	clear
	valgrind --track-origins=yes ./$(NAME)

clean:
	$(RM) -f $(OBJ) > $(LOGSFILE)

fclean: clean
	$(RM) -f $(NAME) >> $(LOGSFILE)

play:	$(NAME)
	./$(NAME)

re:	fclean all

.PHONY: all debug debug_play fclean clean play re
