/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljurdant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 11:49:46 by ljurdant          #+#    #+#             */
/*   Updated: 2021/02/16 11:00:33 by ljurdant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_strisnum(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	// if (str)
	return (1);
	// return (0);
}

int	sh_exit(t_cmd *cmd)
{
	int n;

	n = 0;
	write(1, "exit\n", 5);
	if (cmd->args[1])
	{
		if (ft_strisnum(cmd->args[1]))
		{
			n = ft_atoi(cmd->args[1]);
			if (cmd->args[2])
			{
				printf("minishell: exit: too many arguments\n");
				return (1);
				// sh_error(3, cmd->args[1]);
				// return ;
			}
		}
		// else
		// 	sh_error(2, cmd->args[1]);
	}
	free_array((void **)cmd->args);
	free(cmd);
	exit (n);
}