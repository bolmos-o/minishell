/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strlcpy.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bolmos-o <bolmos-o@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/11/19 16:25:29 by bolmos-o		  #+#	#+#			 */
/*   Updated: 2020/11/19 21:59:03 by bolmos-o		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t len;

	len = ft_strlen(src);
	if (dstsize > len)
		dstsize = len + 1;
	if (dstsize > 1)
		ft_memcpy(dst, src, dstsize - 1);
	if (dstsize >= 1)
		dst[dstsize - 1] = '\0';
	return (len);
}
