##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## makefile
##

SRC1	=	server/src/main.cpp		\
			server/src/server.cpp	\

SRC2	=	client/src/main.cpp		\
			client/src/client.cpp	\

OBJ1	=	$(SRC1:.cpp=.o)

OBJ2	=	$(SRC2:.cpp=.o)

NAME1	=	rtype_server

NAME2	=	rtype_client

all: server client

server: $(OBJ1)
	g++ -o $(NAME1) $(OBJ1) -lboost_system -lpthread

client: $(OBJ2)
	g++ -o $(NAME2) $(OBJ2) -lboost_system -lpthread

clean:
	rm -f $(OBJ1)
	rm -f $(OBJ2)
fclean: clean
	rm -f $(NAME1)
	rm -f $(NAME2)

re:	fclean all
