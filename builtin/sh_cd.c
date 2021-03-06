
#include "minishell.h"

// void	ft_print_error(int err, char *str)
// {
// 	if (err == 2)
// 		perror(str);
// 	if (err == 20)
// 		printf("minishell: cd: %s: Not a directory\n", str);
// 	if (err == 13)
// 		printf("minishell: cd: %s: Permission denied\n", str);
// }

int	sh_cd(char **args)
{
	int		i;
	char	*pwd;
	char 	*buf;
	extern char **environ;

	if (chdir(args[1]) == -1)
		printf("minishell: cd: %s: %s\n", args[1], strerror(errno));
	buf = NULL;
	pwd = getcwd(buf, 0);
	free(buf);
	pwd = ft_strjoin_free(ft_strdup("PWD="), pwd);
	i = 0;
	while (environ[i])
	{
		if (!ft_strncmp(ft_env_name2(environ[i]), "PWD=", 4))
			ft_update_env(pwd, i);
		i++;
	}
	return (errno);
}