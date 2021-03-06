#include "minishell.h"

// char	**ft_get_argv(char **cmds)
// {
// 	char	**argv;
// 	int		size;

// 	size = 0;
// 	while (cmds[size])
// 		size++;
// 	if (!(argv = malloc(sizeof(char *) * (size + 1))))
// 		return (NULL);
// 	size = 0;
// 	while (cmds[size])
// 	{
// 		argv[size] = cmds[size];
// 		size++;
// 	}
// 	argv[size] = NULL;
// 	return (argv);
// }

int		sh_exec_bash(char **argv, char *cmd)
{
	int		i;
	int		e;
	char	*path_env;
	char	*path;
	char	**dirs;
	extern char **environ;

	path_env = conv_dollar("PATH", 0);
	dirs = ft_split(path_env , ':');
	free(path_env);
	i = 0;
	e = -1;
	while (e < 0 && dirs[i])
	{
		dirs[i] = ft_addchar(dirs[i], '/');
		path = ft_strjoin(dirs[i], cmd);
		e = execve(path, argv, environ);
		i++;
		free(path);
	}
	if (e < 0)
		sh_error(0, cmd);
	free(dirs);
	return (e);
}

int	sh_exec(t_cmd *cmd)
{
	pid_t	pid;
	int		e;
	int		status;
	extern char	**environ;

	signal (SIGINT, inthandler2);
	pid = fork();
	if (pid == 0)
	{
		signal (SIGQUIT, SIG_DFL);
		if (cmd->input != -2)
			dup2(cmd->input, 0);
		else if (cmd->output != 0)
			dup2(cmd->output, STDOUT_FILENO);
		if (!(ft_strchr(*(cmd->args), '/')))
			e = sh_exec_bash(cmd->args, cmd->args[0]);
		else
		{
			e = execve(cmd->args[0], cmd->args, environ);
			if (e < 0)
				sh_error(1, cmd->args[0]);
		}
		if (e < 0)
			exit(errno);
		if (cmd->input != -2)
			cmd->input = -2;
		exit(0);
	}
	wait(&status);
	return(WEXITSTATUS(status));
}