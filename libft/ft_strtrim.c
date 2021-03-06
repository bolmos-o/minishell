/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strtrim.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bolmos-o <bolmos-o@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/11/20 11:09:19 by bolmos-o		  #+#	#+#			 */
/*   Updated: 2020/11/20 11:49:45 by bolmos-o		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int end;

	start = 0;
	end = ft_strlen(s1) - 1;
	while (start <= end && ft_strchr(set, *(s1 + start)))
		start++;
	if (start > end)
		return ("");
	while (ft_strrchr(set, *(s1 + end)))
		end--;
	return (ft_substr(s1, start, end - start + 1)); 
}
