#include "minishell.h"

int signum;

int main(void)
{
	char	*line;
	t_cmd	*cmd;
	int		exit_status;
	char	**tokens;
	int		ret;

	exit_status = 0;
	write(1, "minishell$ ", 11);
	signal(SIGINT, inthandler);
	signal(SIGQUIT, SIG_IGN);
	while ((ret = get_next_line(0, &line)) > 0)
	{
		signum = 0;
		tokens = get_tokens(line);
		while ((cmd = get_cmds(&tokens, exit_status)) && signum != SIGINT)
		{
			if (cmd->pipe == NO)
				exit_status = simple_cmd(cmd);
			else
				exit_status = pipeline(&tokens, cmd);
			free(cmd);
		}
		write(1, "minishell$ ", 11);
	}
	return (0);
}