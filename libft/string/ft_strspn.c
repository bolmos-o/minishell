/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolmos-o <bolmos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 18:04:47 by bolmos-o          #+#    #+#             */
/*   Updated: 2020/11/19 18:38:43 by bolmos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strspn(const char *s, const char *accept)
{
	size_t	index;
	size_t	i;

	index = 0;
	while (s[index])
	{
		i = 0;
		while (accept[i] && s[index] != accept[i])
			i++;
		if (i == ft_strlen(accept))
			return (index);
		index++;
	}		
	return (index);
}
