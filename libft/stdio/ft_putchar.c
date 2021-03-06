/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_putchar.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bolmos-o <bolmos-o@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/12/15 01:48:04 by bolmos-o		  #+#	#+#			 */
/*   Updated: 2020/12/15 01:49:12 by bolmos-o		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (c);
}
