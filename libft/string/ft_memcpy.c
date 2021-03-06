/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolmos-o <bolmos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:11:35 by bolmos-o          #+#    #+#             */
/*   Updated: 2020/11/19 21:43:01 by bolmos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *tmp;

	tmp = dst;
	if (!dst && !src)
		return (NULL);
	while (n--)
		*tmp++ = *(unsigned char *)src++;
	return (dst);
}
