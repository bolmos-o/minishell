# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bolmos-o <bolmos-o@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/19 11:18:56 by bolmos-o          #+#    #+#              #
#    Updated: 2020/12/15 01:49:33 by bolmos-o         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS	=	./ctype/ft_isalpha.c \
			./ctype/ft_isdigit.c \
			./ctype/ft_isalnum.c \
			./ctype/ft_isascii.c \
			./ctype/ft_isprint.c \
			./ctype/ft_toupper.c \
			./ctype/ft_tolower.c \
			./string/ft_memset.c \
			./string/ft_bzero.c \
			./string/ft_memcpy.c \
			./string/ft_memccpy.c \
			./string/ft_memmove.c \
			./string/ft_memchr.c \
			./string/ft_memcmp.c \
			./string/ft_strlen.c \
			./string/ft_strlcpy.c \
			./string/ft_strlcat.c \
			./string/ft_strchr.c \
			./string/ft_strrchr.c \
			./string/ft_strncmp.c \
			./string/ft_strdup.c \
			./string/ft_strnstr.c \
			./string/ft_strspn.c \
			./string/ft_strcspn.c \
			./stdlib/ft_abs.c \
			./stdlib/ft_labs.c \
			./stdlib/ft_atoi.c \
			./stdlib/ft_calloc.c \
			./stdio/ft_printf.c \
			./stdio/ft_putchar.c \
			./ft_substr.c \
			./ft_strjoin.c \
			./ft_strtrim.c \
			./ft_split.c \
			./ft_itoa.c \
			./ft_putchar_fd.c \
			./ft_putstr_fd.c \
			./ft_putendl_fd.c \
			./ft_putnbr_fd.c \
			./ft_strmapi.c \
			./ft_lstnew.c \
			./ft_lstadd_front.c \
			./ft_lstsize.c \
			./ft_lstlast.c \
			./ft_lstadd_back.c \
			./ft_lstdelone.c \
			./ft_lstclear.c \
			./ft_lstiter.c \
			./ft_lstmap.c \
			./get_next_line.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	libft.a

CC	=	gcc

CFLAGS	=	-Wall -Werror -Wextra -I.

.c.o	:
		$(CC) $(CFLAGS) -c $< -o $@
			
all	:	$(NAME)

${NAME}	:	$(OBJS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

clean	:
		rm -f $(OBJS)	

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all
