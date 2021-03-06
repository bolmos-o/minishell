NAME =			minishell

FLAGS =	-Wall -Wextra -Werror -I.

SRCS =		main.c\
			builtin/sh_echo.c\
			builtin/sh_exit.c\
			builtin/sh_env.c\
			builtin/sh_export.c\
			builtin/sh_cd.c\
			builtin/sh_pwd.c\
			builtin/sh_unset.c\
			ft_check_builtin.c\
			ft_utils.c\
			parse.c\
			parse_chk.c\
			parse_cmds.c\
			parse_conv.c\
			sh_exec.c\
			sh_error.c\
			exec.c\
			signal.c

OBJS =		${SRCS:.c=.o}

LIBS = libft/libft.a

all : 			$(NAME)

%.o: %.c 
	gcc $(FLAGS) -c $< -o $@

$(NAME) :		$(OBJS)
				$(MAKE) -C ./libft
				gcc $(OBJS) $(LIBS) -o $(NAME)

clean	: 
				rm -f $(OBJS)
				$(MAKE) -C ./libft/. clean

fclean  :
				$(MAKE) -C ./libft/. fclean
				rm -f $(OBJS)
				rm -f $(NAME)

re      : 		fclean all

.PHONY  : 		all fclean re
