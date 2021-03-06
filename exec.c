#include "minishell.h"

int simple_cmd(t_cmd *cmd)
{
	int 	exit_status;

	if (cmd->input == -1)
		return (1);
	exit_status = 0;
	if (!ft_strncmp(cmd->args[0], "exit\0", 5))
		sh_exit(cmd);
	else if (!ft_strncmp(cmd->args[0], "echo\0", 5))
		sh_echo(cmd);
	else if (!ft_strncmp(cmd->args[0], "env\0", 4))
		sh_env(cmd);
	else if (!ft_strncmp(cmd->args[0], "cd\0", 3))
		exit_status = sh_cd(cmd->args);
	else if (!ft_strncmp(cmd->args[0], "export\0", 7))
		sh_export(cmd->args);
	else if (!ft_strncmp(cmd->args[0], "pwd\0", 4))
		sh_pwd(cmd);
	else if (!ft_strncmp(cmd->args[0], "unset\0", 6))
		sh_unset(cmd->args);
	else
		exit_status = sh_exec(cmd);
	return (exit_status);
}

int	pipeline(char ***tokens, t_cmd *first_cmd)
{
	pid_t	pid;
	int		filedes[2];
	t_cmd	*pipecmd;
	int 	exit_status;

	pipe(filedes);
	first_cmd->output = filedes[1];
	exit_status = simple_cmd(first_cmd);
	pid = fork();
	if (pid == 0)
	{
		close(filedes[1]);
		pipecmd = get_cmds(tokens, exit_status);
		dup2(filedes[0], STDIN_FILENO);
		if (pipecmd->pipe == NO)
			exit_status = simple_cmd(pipecmd);
		else
			exit_status = pipeline(tokens, pipecmd);
		exit(0);
	}
	close(filedes[1]);
	wait(NULL);
	while (first_cmd->pipe != NO)
		first_cmd = get_cmds(tokens, exit_status);
	return (exit_status);
}
