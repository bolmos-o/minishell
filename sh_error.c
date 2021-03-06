/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   sh_error.c										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ljurdant <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/02/15 09:13:38 by ljurdant		  #+#	#+#			 */
/*   Updated: 2021/02/15 09:34:43 by ljurdant		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */


#include "minishell.h"

void	sh_error(int e, char *cmd)
{
	if (e == 0)
		printf("minishell: %s: command not found\n", cmd);
	if (e == 1)
		printf("minishell: %s: No such file or directory\n", cmd);
	if (e == 2)
		printf("minishell: exit: %s: numeric argument required\n", cmd);
	if (e == 3)
		printf("minishell: exit: too many arguments\n");
}
