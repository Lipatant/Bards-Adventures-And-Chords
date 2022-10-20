##
## BARDS - VIRGILE (LIPATANT) BERRIER, 2022
## Makefile
## File description:
## Makefile de Bard: Adventures and Chors
##

SRC	=	./engine/ui/box.cpp													\
		./engine/ui/button.cpp												\
		./engine/window/layer.cpp											\
		./engine/window/layer/update.cpp									\
		./main.cpp															\
		./start.cpp															\
		./utility/generation/perlin_noise/2d.cpp							\

BUILDDIR = build

OBJ = $(patsubst %.cpp, $(BUILDDIR)/%.o, $(SRC))

$(BUILDDIR)/%.o: 	src/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

NAME	=	bards

LDFLAGS	=	-lsfml-graphics -lsfml-window -lsfml-system

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

play_re: re
	./$(NAME)

.PHONY: all debug debug_play fclean clean play re play_re
