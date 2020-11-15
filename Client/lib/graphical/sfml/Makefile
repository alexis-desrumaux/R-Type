##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

#	@$(CC) -fPIC -shared $(CPPFLAGS) $(OBJS) -o $(NAME) -Wl,--whole-archive ../../Parser/libmy_parser.a -lsfml-audio -lsfml-window -lsfml-graphics -lsfml-system -logg && \


ECHO    =       /bin/echo -e

DEFAULT =       "\033[00m"
GREEN   =       "\033[0;32m"
TEAL    =       "\033[1;36m"
RED     =       "\033[5;31m"

NAME	= ../lib_sfml.so

CC	= g++

RM	= rm -f

SRCS	= ./src/Sfml.cpp \
	  ./src/Components.cpp \
	  ./src/Sfml_c.cpp \
	  ../../Parser/src/Parser.cpp \


OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./include/ -fPIC

all: $(NAME)

$(NAME): $(OBJS)
	g++ $(CPPFLAGS) -o $(OBJS) -lsfml-audio -lsfml-window -lsfml-graphics -lsfml-system -logg

clean:
	#@$(RM) $(OBJS) && \
        $(ECHO) $(TEAL)"  CLEAN : $(OBJS)" $(DEFAULT)
fclean: clean
	#$(RM) $(NAME)

re: fclean all

debug: CPPFLAGS += -g
debug:	re

.PHONY: all clean fclean re
