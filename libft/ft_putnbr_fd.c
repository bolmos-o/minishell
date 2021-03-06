/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolmos-o <bolmos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 16:59:15 by bolmos-o          #+#    #+#             */
/*   Updated: 2020/11/20 17:27:20 by bolmos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd ('-', fd);
	if (n > 99 || n < -99)
		ft_putnbr_fd(ft_abs(n / 10), fd);
	else if (n > 9 || n < -9 )
		ft_putchar_fd(ft_abs(n / 10) + '0', fd);
	ft_putchar_fd(ft_abs(n % 10) + '0', fd);
}
