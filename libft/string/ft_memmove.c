/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolmos-o <bolmos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:51:57 by bolmos-o          #+#    #+#             */
/*   Updated: 2020/11/19 21:43:20 by bolmos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dst, const void *src, size_t len)
{
	if (!dst && !src)
		return(NULL);
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
		while (len--)
			*((unsigned char *)dst + len) = *((unsigned char *)src + len);
	return (dst);
}
