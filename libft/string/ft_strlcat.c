/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strlcat.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bolmos-o <bolmos-o@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/11/19 16:50:06 by bolmos-o		  #+#	#+#			 */
/*   Updated: 2020/11/20 00:58:04 by bolmos-o		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t dstlen;

	dstlen = ft_strlen(dst);
	if (dstsize >= dstlen)
		return (ft_strlcpy(dst + dstlen, src, dstsize - dstlen) + dstlen);
	return (ft_strlen(src) + dstsize);
}
