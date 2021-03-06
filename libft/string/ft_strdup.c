/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strdup.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bolmos-o <bolmos-o@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/11/20 17:52:15 by bolmos-o		  #+#	#+#			 */
/*   Updated: 2020/11/20 17:57:35 by bolmos-o		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

char *ft_strdup(const char *s1)
{
	char	*str;

	if (!(str = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char))))
		return (NULL);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	return (str);
}
