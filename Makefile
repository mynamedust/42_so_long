NAME	=	so_long.out

SRCS	=	main.c	map_read.c	utils.c\
			validate.c\

HEADER	=	so_long.h

OBJS	=	$(SRCS:%.c=%.o)

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

all: $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(OBJS) $(NAME)

re : clean fclean all

.PHONY : all clean fclean re