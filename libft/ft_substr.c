/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolmos-o <bolmos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 10:51:59 by bolmos-o          #+#    #+#             */
/*   Updated: 2020/11/20 11:31:58 by bolmos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;

	if (!(subs = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	if (start < ft_strlen(s))
		ft_strlcpy(subs, s + start, len + 1);
	return (subs);
}
