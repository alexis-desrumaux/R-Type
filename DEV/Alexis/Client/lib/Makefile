##
## EPITECH PROJECT, 2019
## ALEXIS DESRUMAUX
## File description:
## Makefile
##

NAME	= libmy.so

RM	= rm -f

SRCS_LIB_PARSER = $(shell find ./Parser/src/ -name "*.cpp")

OBJS_LIB_PARSER = $(SRCS_LIB_PARSER:.cpp=.o)

SRCS_LIB_GAMECORE = $(shell find ./GameCore/src/ -name "*.cpp")

OBJS_LIB_GAMECORE = $(SRCS_LIB_GAMECORE:.cpp=.o)

SRCS_LIB_GRAPHICAL = $(shell find ./graphical/sfml/src/ -name "*.cpp")

OBJS_LIB_GRAPHICAL = $(SRCS_LIB_GRAPHICAL:.cpp=.o)

CPPFLAGS += -I ./include/ -fPIC

LIB = -lsfml-audio -lsfml-window -lsfml-graphics -lsfml-system -logg

all: $(NAME)

$(NAME): $(OBJS_LIB_GAMECORE) $(OBJS_LIB_GRAPHICAL) $(OBJS_LIB_PARSER)
	g++ -fPIC -shared $(CPPFLAGS) $(OBJS_LIB_GAMECORE) $(OBJS_LIB_GRAPHICAL) $(OBJS_LIB_PARSER) -o $(NAME) $(LIB)

clean:
	$(RM) $(shell find ./ -name "*.o")

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
