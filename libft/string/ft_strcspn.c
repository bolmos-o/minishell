/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolmos-o <bolmos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 18:04:47 by bolmos-o          #+#    #+#             */
/*   Updated: 2020/11/19 18:38:43 by bolmos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strcspn(const char *s, const char *reject)
{
	size_t	index;
	size_t	i;

	index = 0;
	while (s[index])
	{
		i = 0;
		while (reject[i] && s[index] != reject[i])
            i++;
		if (i != ft_strlen(reject))
			return (index);
		index++;
	}		
	return (index);
}