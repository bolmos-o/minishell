/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_isprint.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bolmos-o <bolmos-o@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/11/19 14:52:12 by bolmos-o		  #+#	#+#			 */
/*   Updated: 2020/11/19 14:56:14 by bolmos-o		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

int ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (c);
	return (0);
}
