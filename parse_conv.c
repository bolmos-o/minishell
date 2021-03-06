#include "minishell.h"

char	*conv_dollar(char *name, int exit_status)
{
	char *value;
	int size;
	extern char **environ;

	value = NULL;
	if (*name == '?')
		return (ft_itoa(exit_status));
	size = ft_strspn(name, ENVNAME);
	while(*environ && !value)
	{
		if (!ft_strncmp(*environ, name, size) && (*environ)[size] == '=')
			value = ft_substr(*environ, size + 1, ft_strlen(*environ) - (size + 1));
		environ++;
	}
	return (value);
}

int conv_squotes(char *str, char **dst)
{
	char	*s;
	int	 offset;

	s = NULL;
	offset = 1;
	while (*str != '\'')
	{
		s = ft_addchar(s, *str);
		str++;
		offset++;
	}
	*dst = ft_strjoin_free(*dst, s);
	return(offset);
}

int conv_dquotes(char *str, char **dst, int exit_status)
{
	char	*s;
	int	 offset;

	s = NULL;
	offset = 1;
	while (*(str + offset) != '\"')
	{
		if (*(str + offset) == '$' && ft_strchr(DOLCHAR, *(str + offset + 1)))
		{
			offset++;
			s = ft_strjoin_free(s, conv_dollar((str + offset), exit_status));
			if (*(str + offset) != '?')
				offset += ft_strspn(str + offset, ENVNAME);
			else
				offset++;
		}
		else 
		{
			if (*(str + offset) == '\\')
				offset++;
			s = ft_addchar(s, *(str + offset++));
		}
	}
	*dst = ft_strjoin_free(*dst, s);
	return(offset);
}

char	*convert(char *str, int exit_status)
{
	int i;
	char *conv;

	i = 0;
	conv = NULL;
	while (str[i])
	{
		if (str[i] == '\'')
			i += conv_squotes(str + i, &conv);
		else if (str[i] == '\"')
			i += conv_dquotes(str + i, &conv, exit_status);
		else if (str[i] == '\\')
			conv = ft_addchar(conv, str[++i]);
		else if (str[i] == '$' && ft_strchr(DOLCHAR, str[i + 1]))
		{
			conv = ft_strjoin_free(conv, conv_dollar(str + (++i), exit_status));
			if (!(str[i] == '?'))
				 i += ft_strspn(str + i, ENVNAME);
		}
		else
			conv = ft_addchar(conv, str[i]);
		i++;
	}
	return(conv);
}