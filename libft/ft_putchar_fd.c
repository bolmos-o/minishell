/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_putchar_fd.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bolmos-o <bolmos-o@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/11/20 16:53:09 by bolmos-o		  #+#	#+#			 */
/*   Updated: 2020/11/20 16:54:42 by bolmos-o		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

void ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
