##
## EPITECH PROJECT, 2019
## ALEXIS DESRUMAUX
## File description:
## Makefile
##

NAME	= libmy_GameCore.a

RM	= rm -f

SRC_GAMECORE	= $(shell find ./src -name "*.cpp")

OBJ_GAMECORE	= $(SRC_GAMECORE:.cpp=.o)

CPPFLAGS = -I ./include/ -fPIC

all: $(NAME)

$(NAME): $(OBJ_GAMECORE)

clean:
	$(RM) $(OBJ_GAMECORE)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
