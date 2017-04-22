SRC=	sapin.c \

NAME=	MonBeauSapin

CC=	cc

OBJ=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)
