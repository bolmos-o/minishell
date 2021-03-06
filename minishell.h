#ifndef MINISHELL_H
# define MINISHELL_H

# define METACHAR ";|<> \n\0"
# define CTRL_OP ";|"
# define BLANK	" \n"
# define QUOTING "\\\'\""
# define SDQUOTES "\'\""
# define REDIR "><"
# define ENVNAME "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_"
# define DOLCHAR "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_?"
# define NO 0
# define OUT 1

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/errno.h>
# include "libft/libft.h"
# include <string.h>

typedef struct  s_cmd
{
    int     input;
    int     output;
    int     pipe;
    char    **args;
}               t_cmd;

char	**get_tokens(char *line);
int     count_tokens(char *line);
char	*get_end(char *line);
t_cmd   *get_cmds(char ***tokens, int exit_status);
int		ft_check_builtin(char *cmd);
int		chk_ctrl_red(char *str);
int     chk_name(char *str);
int		chk_tokens(char **table);
char	*conv_dollar(char *name, int exit_status);
int     conv_squotes(char *str, char **dst);
int     conv_dquotes(char *str, char **dst, int exit_status);
char    *convert(char *str, int exit_status);
void	sh_echo(t_cmd *s_cmd);
int 	sh_exit(t_cmd *cmd);
void	sh_pwd(t_cmd *cmd);
void	sh_env(t_cmd *cmd);
void	sh_export(char **cmds);
int 	sh_exec(t_cmd *cmd);
void	sh_error(int e, char *cmd);
int     sh_cd(char	**args);
void	sh_unset(char **cmds);
void	free_array(void **array);
char	**ft_arrayncpy(char **src, char **dest, int n);
char	*ft_strjoin_free(char const *s1, char const *s2);
char	*ft_env_name2(char *str);
char	*ft_addchar(char *str, char c);
void    ft_update_env(char *new, int p);
void	inthandler(int sig);
void	inthandler2(int sig);
int     simple_cmd(t_cmd *cmd);
int     pipeline(char ***tokens, t_cmd *first_cmd);

#endif