NAME	=	so_long.out

SRCS	=	main.c				map_read.c		utils.c\
			validate.c			game_init.c		events_handle.c\
			game_init_utils.c	animate.c		clear_exit.c\
			map_read_utils.c\

SRCS_b	=	main.c				map_read.c		utils.c\
			validate_bonus.c	game_init.c		events_handle_bonus.c\
			game_init_utils.c	animate_bonus.c	clear_exit.c\
			map_read_utils.c\

HEADER	=	so_long.h

HEADER	=	so_long_bonus.h

OBJS	=	$(SRCS:%.c=%.o)

OBJS_b	=	$(SRCS_b:%.c=%.o)

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

all: $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus: $(OBJS_b) $(HEADER_b)
	$(CC) $(CFLAGS) $(OBJS_b) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(OBJS) $(OBJS_b) $(NAME)

re : clean fclean all

.PHONY : all clean fclean bonus re