NAME		= pipex
HPATH		= -Iincludes
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

SRC 		= ./src/pipex.c ./src/split.c ./src/utils.c ./src/put.c ./src/pipex2.c

# SRC_FILES 	= pipex.c split.c utils.c put.c

# SRC 		= $(addprefix $(SRC_PATH), $(SRC_FILES))

OBJS		= $(SRC:.c=.o)

RM			= rm -f

$(NAME):	$(OBJS)
			gcc $(CFLAGS) $(HPATH) $(SRC) -o $(NAME)

all: 		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re: 		fclean all