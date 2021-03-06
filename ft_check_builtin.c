
#include "minishell.h"

int		ft_check_builtin(char *cmd)
{

	if (!ft_strncmp(cmd, "echo\0", 5) || !ft_strncmp(cmd, "exit\0", 5) ||
			!ft_strncmp(cmd, "env\0", 4) || !ft_strncmp(cmd, "export\0", 7)
			|| !ft_strncmp(cmd, "cd\0", 3) || !ft_strncmp(cmd, "pwd\0", 4)
			|| !ft_strncmp(cmd, "unset\0", 5))
		return (1);
	return (0);
}
