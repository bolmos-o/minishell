#include "minishell.h"

int count_args(char **tokens)
{
	int i;

	i = 0;
	while (tokens[i])
	{
		if(ft_strchr(CTRL_OP, tokens[i][0]))
			return(i);
		i++;
	}
	return(i);
}

void	get_redir(char ***tokens, t_cmd **cmd)
{
	int i;

	i = 0;
	if ((*tokens)[i][0] == '<')
	{	
		free ((*tokens)[i++]);
		if (((*cmd)->input = open((*tokens)[i],O_RDWR)) == -1)
			printf("minishell: %s: %s\n", (*tokens)[i], strerror(errno));
	}
	else if ((*tokens)[i][0] == '>')
	{
		if ((*tokens)[i][1] == '>')
		{
			free(*tokens[i++]);
			(*cmd)->output = open((*tokens)[i], O_RDWR | O_APPEND | O_CREAT, 00777);
		}
		else
		{
			free(*tokens[i++]);
			(*cmd)->output = open((*tokens)[i],O_RDWR | O_TRUNC | O_CREAT, 00777);
		}
	}
	*tokens = &(*tokens)[++i]; 
}

t_cmd   *get_cmds(char ***tokens, int exit_status)
{
	t_cmd *cmd;
	int argnum;
	int a;

	if (!*tokens || !**tokens)
		return (NULL);
	cmd = (t_cmd *)ft_calloc(1, sizeof(t_cmd));
	argnum = count_args(*tokens);
	cmd->args = (char **)ft_calloc((argnum + 1), sizeof(char *));
	a = 0;
	cmd->input = -2;
	cmd->output = 1;
	while (a < argnum)
	{
		if (*(*tokens)[0] == '<' || *(*tokens)[0] == '>')
		{
			get_redir(tokens, &cmd);
			argnum -= 2;
		}
		else
		{
			cmd->args[a++] = convert(*(*tokens), exit_status);
			free (**tokens);
			(*tokens)++;
		}
	}
	if (**tokens)
	{
		if ((**tokens)[0] == '|')
			cmd->pipe += OUT;
		free(**tokens);
		(*tokens)++;
	}
	return (cmd);
}