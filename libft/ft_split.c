/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_split.c										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bolmos-o <bolmos-o@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/11/20 11:52:37 by bolmos-o		  #+#	#+#			 */
/*   Updated: 2020/11/20 16:19:34 by bolmos-o		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	word_count(char const *s, char c)
{
	int	words;

	words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
		{
			words++;
			while (*s && *s != c)
				s++;
		}
	}
	return (words);
}

static void	clear(char **ar, int w)
{
	while (--w >= 0)
		free (ar[w]);
	free (ar);
}

char		**ft_split(char const *s, char c)
{
	char	**array;
	char	*tmp;
	int		words;

	if (!(array = (char **)malloc((word_count(s, c) + 1) * sizeof(char *))))
		return (NULL);
	words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
		{
			if (!(tmp = ft_strchr(s, c)))
				tmp = ft_strchr(s, '\0');
			if(!(array[words++] = ft_substr(s, 0, tmp - s)))
				clear(array, words);
		}
		if (*s)
			s = tmp;
	}
	array[words] = NULL;
	return (array);
}
