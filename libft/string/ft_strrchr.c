/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strrchr.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bolmos-o <bolmos-o@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/11/19 18:11:48 by bolmos-o		  #+#	#+#			 */
/*   Updated: 2020/11/19 18:38:23 by bolmos-o		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
	char *tmp;

	tmp = (char *)s + ft_strlen(s);
	while (*tmp != c && tmp != s)
		tmp--;
	if (*tmp == c)
		return (tmp);
	return (NULL);
}
