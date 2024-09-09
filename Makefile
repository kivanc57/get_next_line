NAME	= get_next_line

SRCS	= ./src/get_next_line.c \
	   	./src/get_next_line_utils.c \
		./src/main.c

OBJS	= $(SRCS:.c=.o)

CC	= gcc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror -I./inc

all:	$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
