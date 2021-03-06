/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolmos-o <bolmos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 16:20:43 by bolmos-o          #+#    #+#             */
/*   Updated: 2020/11/20 16:52:01 by bolmos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"
char *ft_itoa(int n)
{
	char *num;
	int	odd;
	int	tmp;
	int	dig;

	odd = (n < 0) ? 1 : 0;
	tmp = n;
	dig = 1;
	while ((tmp /= 10))
		dig++;
	if (!(num = (char *)malloc((dig + odd + 1) * sizeof(char))))
		return (NULL);
	if (odd)
		*num = '-';
	*(num + dig + odd) = '\0';
	while (dig)
	{
		*(num + dig-- + odd - 1) = ft_abs(n % 10) + '0';
		n = n / 10;
	}
	return (num);
}
