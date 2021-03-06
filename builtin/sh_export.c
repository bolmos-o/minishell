
#include "minishell.h"

void	ft_update_env(char *new, int p)
{
	int		j;
	int		size;
	char	**env;
	extern char **environ;

	size = 0;
	while (environ[size])
		size++;
	env = malloc(sizeof(char *) * (size + 1));
	j = 0;
	while (j < size)
	{
		if (j == p)
			env[j] = new;
		else
			env[j] = ft_strdup(environ[j]);
		j++;
	}
	env[size] = NULL;
	environ = env;
}

void	ft_add_env(char *new, char *name)
{
	char	**env;
	int		i;
	int		size;
	char	*env_name;
	extern char **environ;

	size = 0;
	while (environ[size])
	{
		env_name = ft_env_name2(environ[size]);
		if (ft_strlen(name) == ft_strlen(env_name) &&
				!ft_strncmp(env_name, name, ft_strlen(env_name)))
			ft_update_env(new, size);
		free(env_name);
		size++;
	}
	env = malloc(sizeof(char *) * (size + 2));
	i = 0;
	while (environ[i])
	{
		env[i] = ft_strdup(environ[i]);
		i++;
	}
	env[i] = ft_strdup(new);
	env[i + 1] = NULL;
	environ = env;
}

char	*ft_get_value(int *i, char *sub)
{
	int		size;
	int		j;
	int		q;
	char	*name;
	char	*tmp;

	size = 1;
	q = 0;
	if (sub[*i] == '\"' || sub[*i] == '\'')
	{
		if (sub[*i] == '\'') 
			q = 1;
		if (sub[*i] == '\"')
			q = 2;
		(*i)++;
	}
	while (sub[*i] && sub[*i] != ' ' && !(sub[*i] == '\'' && q == 1) && !(sub[*i] == '\"' && q == 2))
	{
		if(!(tmp = malloc(sizeof(char) * (size + 1))))
			return (NULL);
		j = 0;
		while (name && name[j])
		{
			tmp[j] = name[j];
			j++;
		}
		tmp[size - 1] = sub[*i];
		tmp[size] = '\0';
		name = ft_strdup(tmp);
		free(tmp);
		size++;
		(*i)++;
	}
	return (name);
}

char	*ft_get_name(int *i, char *sub)
{
	int		size;
	int		j;
	char	*name;
	char	*tmp;

	size = 1;
	name = NULL;
	while (sub[*i] && sub[*i] != '=')
	{
		if(!(tmp = malloc(sizeof(char) * (size + 1))))
			return (NULL);
		j = 0;
		while (name && name[j])
		{
			tmp[j] = name[j];
			j++;
		}
		tmp[size - 1] = sub[*i];
		tmp[size] = '\0';
		name = ft_strdup(tmp);
		free(tmp);
		size++;
		(*i)++;
	}
	return (name);
}

void	sh_export(char **cmds)
{
	int		i;
	char	*name;
	char	*value;
	char	*new;

	if (!ft_strncmp(cmds[0], "export", 6))
	{
		i = 0;
		name = ft_get_name(&i, cmds[1]);
		i++;
		value = ft_get_value(&i, cmds[1]);
		new = ft_strjoin(ft_strjoin(name, "="),value);
		ft_add_env(new, name);
	}
}
