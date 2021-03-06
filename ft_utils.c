
#include "minishell.h"

char	**ft_arrayncpy(char **src, char **dest, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dest[i] = ft_strdup(src[i]);
		i++;
	}
	return (dest);
}

char	*ft_strjoin_free(char const *s1, char const *s2)
{
	char *str;

	if (!s1)
		s1 = ft_strdup("");
	if (!s2)
		s2 = ft_strdup ("");
	str = ft_strjoin(s1, s2);
	free((void *)s1);
	free((void *)s2);
	return (str);
}

char	*ft_addchar(char *str, char c)
{
	int		size;
	char	*tmp;
	
	if (!str)
		str = ft_strdup("");
	size = ft_strlen(str);
	if (!(tmp = malloc(sizeof(char) * (size + 2))))
		return (NULL);
	ft_strlcpy(tmp, str, size + 1);
	tmp[size] = c;
	tmp[size + 1] = '\0';
	free(str);
	return (tmp);
}

void free_array(void **array)
{
	int	a;

	a = 0;
	while (array[a])
	{
		free(array[a]);
		a++;
	}
	free(array);
}