##
## EPITECH PROJECT, 2020
## Perso
## File description:
## Makefile
##

##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

ECHO    =       /bin/echo -e

DEFAULT =       "\033[00m"
GREEN   =       "\033[0;32m"
TEAL    =       "\033[1;36m"
RED     =       "\033[5;31m"

NAME	= rtype

CC	= g++

RM	= rm -f

SRCS	=	./src/main.cpp  \
			./src/Core.cpp \
			./src/GameState/Menu/Menu.cpp \

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ../include/
CPPFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	make re -C ./lib/ && \
	$(CC) $(OBJS) -o $(NAME) ./lib/libmy.so -ldl && \
    $(ECHO) $(GREEN) "[OK]"$(TEAL)"  BUILD : rtype" $(DEFAULT)  || \
    $(ECHO) $(RED) "[ERROR]" $(TEAL) arcade $(DEFAULT)
clean:
	@$(RM) $(OBJS) && \
        $(ECHO) $(TEAL)"  CLEAN : $(OBJS)" $(DEFAULT)
fclean: clean
	make fclean -C ./lib/ && \
	$(RM) $(NAME)

re: fclean all

debug: CPPFLAGS += -g
debug:	re

.PHONY: all clean fclean re