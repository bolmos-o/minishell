/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_atoi.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bolmos-o <bolmos-o@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/11/19 20:01:06 by bolmos-o		  #+#	#+#			 */
/*   Updated: 2020/11/20 01:05:36 by bolmos-o		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int num;
	int odd;

	odd = 1;
	num = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+')
		str++;
	if (*str == '-')
	{
		odd = -1;
		str++;
	}
	while (ft_isdigit(*str))
		num = (num * 10) + (*str++ - '0');
	return (odd * num);
}


