#include "minishell.h"

char	*get_end(char *line)
{
	int		quote;

	if (ft_strchr(CTRL_OP, *line))
		return (line + ft_strspn(line, CTRL_OP));
	else if (ft_strchr(REDIR, *line))
		return (line + ft_strspn(line, REDIR));
	while (*line && !ft_strchr(METACHAR, *line))
	{
		if (*line == '\'' || *line == '\"')
		{
			quote = *line++;
			while (*line && *line != quote)
			{
				if (quote == '\"' && *line == '\\')
					line++;
				if (*line)
					line++;
			}
		}
		if (*line)
			line++;
	}
	return(line);
}

int	count_tokens(char *line)
{
	int tokens;

	tokens = 0;
	while (*line)
	{
		if (ft_strchr(BLANK, *line))
			line++;
		else
		{
			tokens++;
			line = get_end(line);
		}
	}
	return (tokens);
}

char	**get_tokens(char *line)
{
	int		i;
	char	*end;
	char	**table;
	char	*tmp;

	if (!(*line) || !(table = (char **)ft_calloc
			((count_tokens(line) + 1), sizeof(char *))))
		return (NULL);
	i = 0;
	tmp = line;
	while (*line)
	{
		if (ft_strchr(BLANK, *line))
			line++;
		else
		{
			end = get_end(line);
			table[i++] = ft_substr(line, 0, end - line);
			line = end;
		}
	}
	free(tmp);
	if (chk_tokens(table))
		return (NULL);
	return (table);
}