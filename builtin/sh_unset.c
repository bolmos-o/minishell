
#include "minishell.h"

char	*ft_env_name2(char *env)
{
	int		i;
	int		size;
	char	*name;
	
	size = 0;
	while (env[size] && env[size] != '=')
		size++;
	if (!(name = malloc(sizeof(char) * size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		name[i] = env[i];
		i++;
	}
	name[size] = '\0';
	return (name);

}

void	ft_unset(int p)
{
	int		j;
	int		size;
	char	**new;
	extern char **environ;

	size = 0;
	while (environ[size])
		size++;
	new = malloc(sizeof(char *) * size);
	j = 0;
	while (j < size)
	{
		if (j == p)
			j++;
		else
		{
			new[j] = ft_strdup(environ[j]);
			j++;
		}
	}
	new[size - 1] = NULL;
	environ = new;
}

void	sh_unset(char **cmds)
{
	int		i;
	int		j;
	char	*name;
	extern char **environ;

	i = 1;
	while(cmds[i])
	{
		j = 0;
		while (environ[j])
		{
			name = ft_env_name2(environ[j]);
			if (ft_strlen(name) == ft_strlen(cmds[i]) &&
				!ft_strncmp(cmds[i], name, ft_strlen(cmds[i])))
			{
				ft_unset(j);
				break ;
			}
			j++;
		}
		i++;
	}
}
