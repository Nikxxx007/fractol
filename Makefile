#CC		= gcc
NAME	= pipex
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
	make -C minilibx
	$(CC) $(FLAGS) -L $(LIBFT) -o -framework OpenGL -framework AppKit -L libmlx $(NAME)


.c.o:
	$(CC) $(FLAGS) -I includes -c $< -o $(<:.c=.o)


clean:
		$(RM) $(OBJS)
		make clean -C libft
		make clean -C libmlx

fclean:	clean
		$(RM) $(NAME)
		make fclean -C libft
		make fclean -C libmlx

re:		fclean all

.PHONY:	fclean clean re bonus
