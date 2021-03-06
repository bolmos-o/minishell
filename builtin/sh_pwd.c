
#include "minishell.h"

void	sh_pwd(t_cmd *cmd)
{
	char	*buf;
	char	*pwd;

	buf = NULL;
	pwd = getcwd(buf, 0);
	ft_putendl_fd(pwd, cmd->output);
}