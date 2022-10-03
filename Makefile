##
## BARDS - VIRGILE (LIPATANT) BERRIER, 2022
## Makefile
## File description:
## Makefile de Bard: Adventures and Chors
##

SRC	=	../main.c															\
	engine/input/initialize.c												\
	engine/loaded_map/create.c												\
	engine/loaded_map/display.c												\
	engine/loaded_map/display/level_editor.c								\
	engine/loaded_map/free.c												\
	engine/loaded_map/view_angle/rotate.c									\
	engine/map/create.c														\
	engine/map/free.c														\
	engine/scene/call.c														\
	engine/scene/create.c													\
	engine/scene/level_editor/create.c										\
	engine/scene/level_editor/free.c										\
	engine/scene/level_editor/tick.c										\
	engine/scene/free.c														\
	engine/sprite/create/from_file.c										\
	engine/sprite/destroy.c													\
	engine/tilemap/reset.c													\
	engine/window/create.c													\
	engine/window/destroy.c													\
	engine/window/destroy/all.c												\
	engine/window/layer/is_valid.c											\
	engine/window/update/view.c												\
	engine/window/view/set_center.c											\
	engine/window/view/set_center/vector.c									\
	start.c																	\

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

LOGSFILE	=	logs.txt

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C lib/my/ > $(LOGSFILE)
	$(GCCFLAG) $(NAME) $(OBJ) $(LDFLAGS) >> $(LOGSFILE)

debug:	$(OBJ)
	$(MAKE) -C lib/my/ > $(LOGSFILE)
	$(GCCFLAG) $(NAME) $(OBJ) $(LDFLAGS) $(FDEBUG) >> $(LOGSFILE)

debug_play:	fclean debug
	clear
	valgrind --track-origins=yes ./$(NAME)

clean:
	$(MAKE) clean -C lib/my/ > $(LOGSFILE)
	$(RM) -f $(OBJ) >> $(LOGSFILE)

fclean: clean
	$(MAKE) fclean -C lib/my/ >> $(LOGSFILE)
	$(RM) -f $(NAME) >> $(LOGSFILE)

play:	$(NAME)
	./$(NAME)

re:	fclean all

.PHONY: all debug debug_play fclean clean play re
