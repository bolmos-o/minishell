/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strmapi.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bolmos-o <bolmos-o@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/11/20 17:27:48 by bolmos-o		  #+#	#+#			 */
/*   Updated: 2020/11/20 17:42:04 by bolmos-o		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*it;
	unsigned int		i;

	i = 0;
	if (!(it = (char *)malloc((ft_strlen(s) + 1) * sizeof(char))))
		return (NULL);
	while (*(s + i))
	{
		*(it + i) = (*f)(i, *(s + i));
		i++;
	}
	*(it + i) = '\0';
	return (it);
}
