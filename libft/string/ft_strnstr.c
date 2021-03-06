/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strnstr.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bolmos-o <bolmos-o@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/11/20 18:03:50 by bolmos-o		  #+#	#+#			 */
/*   Updated: 2020/11/20 18:41:16 by bolmos-o		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t needle_len;

	i = 0;
	needle_len = ft_strlen(needle);
	if (!needle)
		return ((char *)haystack);
	if (len > ft_strlen(haystack))
		len = ft_strlen(haystack);
	while (i + needle_len <= len)
	{
		if (!(ft_strncmp(haystack + i, needle, needle_len)))
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
