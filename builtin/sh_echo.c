/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   sh_echo.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ljurdant <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/02/10 11:49:38 by ljurdant		  #+#	#+#			 */
/*   Updated: 2021/02/23 12:20:36 by ljurdant		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */


#include "minishell.h"

void	sh_echo(t_cmd *cmd)
{
	int	i;

	i = 1;

	if (cmd->args[1] && !ft_strncmp(cmd->args[1], "-n", 2))
		i = 2;
	while (cmd->args[i])
	{
		ft_putstr_fd(cmd->args[i], cmd->output);
		if (cmd->args[i + 1])
			ft_putchar_fd(' ', cmd->output);
		i++;
	}
	if (!cmd->args[1] || ft_strncmp(cmd->args[1], "-n", 2))
		write(cmd->output, "\n", 1);
}
