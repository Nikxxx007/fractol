# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rogaynel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 18:57:48 by rogaynel          #+#    #+#              #
#    Updated: 2022/02/16 18:57:49 by rogaynel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
NAME	= libft.a
SRCS	= ft_memset.c \
          ft_bzero.c \
          ft_memcpy.c \
          ft_memccpy.c \
          ft_memmove.c \
          ft_memchr.c \
          ft_memcmp.c \
          ft_strlen.c \
          ft_strlcpy.c \
          ft_strlcat.c \
          ft_strchr.c \
          ft_strrchr.c \
          ft_strnstr.c \
          ft_strncmp.c \
          ft_atoi.c \
          ft_isalpha.c \
          ft_isdigit.c \
          ft_isalnum.c \
          ft_isascii.c \
          ft_isprint.c \
          ft_toupper.c \
          ft_tolower.c \
          ft_calloc.c \
          ft_strdup.c \
          ft_substr.c \
          ft_strjoin.c \
          ft_strmapi.c \
          ft_putchar_fd.c \
          ft_putstr_fd.c \
          ft_putendl_fd.c \
          ft_putnbr_fd.c \
          ft_strtrim.c \
          ft_split.c \
          ft_itoa.c


OBJS		= $(SRCS:.c=.o)

SRCS_BONUS	=	ft_lstnew_bonus.c \
				ft_lstadd_front_bonus.c \
				ft_lstsize_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstadd_back_bonus.c \
				ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c \
				ft_lstiter_bonus.c \
				ft_lstmap_bonus.c

OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

FLAGS	= -Wall -Werror -Wextra
LIBC	= ar rc
LIBR	= ranlib
RM		= rm -f
INCL	= ./

.c.o:
	$(CC) $(FLAGS) -I $(INCL) -c $< -o $(<:.c=.o)

$(NAME): 	$(OBJS)
	$(LIBC) $(NAME) $(OBJS)
	$(LIBR) $(NAME)

all:	$(NAME)
bonus:	$(NAME) $(OBJS_BONUS)
	$(LIBC) $(NAME) $(OBJS) $(OBJS_BONUS)
	$(LIBR) $(NAME)
clean:
		$(RM) $(OBJS) $(OBJS_BONUS)
fclean:	clean
		$(RM) $(NAME)
		
re:		fclean all

.PHONY:	fclean clean re bonus
