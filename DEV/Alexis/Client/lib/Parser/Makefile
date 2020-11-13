##
## EPITECH PROJECT, 2019
## ALEXIS DESRUMAUX
## File description:
## Makefile
##

NAME	= libmy_parser.a

RM	= rm -f

SRC_LIB	= $(shell find ./src -name "*.cpp")

OBJ_LIB	= $(SRC_LIB:.cpp=.o)

CPPFLAGS += -I ./include/ -fPIC

all: $(NAME)

$(NAME): $(OBJ_LIB)

clean:
	$(RM) $(OBJ_LIB)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
