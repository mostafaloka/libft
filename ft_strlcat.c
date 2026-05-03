/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelgham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:46:08 by moelgham          #+#    #+#             */
/*   Updated: 2024/11/06 09:56:08 by moelgham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	d;
	size_t	s;

	s = ft_strlen(src);
	if (!dst && size == 0)
		return (s);
	j = ft_strlen(dst);
	d = j;
	if (size <= d)
		return (size + s);
	i = 0;
	while (src[i] && j + 1 < size)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = 0;
	return (d + s);
}
