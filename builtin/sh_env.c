
#include "minishell.h"

void	sh_env(t_cmd *cmd)
{
	extern char **environ;

	int		i;

	i = 0;
	while (environ[i])
	{
		ft_putendl_fd(environ[i], cmd->output);
		i++;
	}
}