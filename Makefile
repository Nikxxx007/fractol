CC		= gcc
NAME	= fractol
SRCS	= src/main.c

OBJS		= $(SRCS:.c=.o)

FLAGS	= -Wall -Wextra -Werror
LIBC	= ar rc
LIBR	= ranlib
RM		= rm -f
INCL	= ./

LIBFT	= libft/libft.a

all:	$(NAME)


$(NAME): 	$(OBJS)
	make bonus -C libft
	make -C libmlx
	$(CC) $(FLAGS) $(LIBFT) libmlx/libmlx.a -framework OpenGL -framework AppKit $(OBJS) -o $(NAME)
#

#   -lmlx


.c.o:
	$(CC) $(FLAGS) -I includes -c $< -o $(<:.c=.o)


clean:
		$(RM) $(OBJS)
		make clean -C libft
		make clean -C libmlx

fclean:	clean
		$(RM) $(NAME)
		make fclean -C libft
#make fclean -C libmlx

re:		fclean all

.PHONY:	fclean clean re bonus
