#include "minishell.h"

int		chk_ctrl_red(char *str)
{
	int err;

	err = 0;
	if ((ft_strlen(str)) > 2)
		err = 1;
	else if ((ft_strlen(str))== 2 && ft_strncmp(str, ">>", 2))
		err = 1;
	return (err);
}

int	chk_backslash(char **str)
{
	if (**str == '\\')
	{
		(*str)++;
		if (!(**str))
			return(1);
	}
	return (0);
}

int	chk_name(char *str)
{
	int	quote;

	while (*str)
	{
		if (ft_strchr(SDQUOTES, *str))
		{
			quote = *str++;	
			while (*str && *str != quote)
			{
				if (chk_backslash(&str))
					return (1);
				str++;
			}
			if (!(*str))
				return (1);
			str++;
		}
		else if (chk_backslash(&str))
			return (1);
		else
			str++;
	}
	return (0);
}

int		chk_tokens(char **table)
{
	int err;
	int i;

	if (ft_strchr(METACHAR, table[0][0]))
		err = 1;
	err = 0;
	i = 0;
	while (table[i] && err == 0)
	{
		if (ft_strchr(CTRL_OP, table[i][0]) || ft_strchr(REDIR, table[i][0]))
			err = chk_ctrl_red(table[i]);
		else
			err = chk_name(table[i]);
		if (i > 0 && ft_strchr(METACHAR, table[i][0]) && ft_strchr(METACHAR, table[i - 1][0]))
			err = 1;
		i++;
	}
	if (err == 1)
	{
		free_array((void **)table);
		write(1, "Syntax error.\n", 15);
	}
	return (err);
}
