/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelgham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:50:29 by moelgham          #+#    #+#             */
/*   Updated: 2024/11/05 15:53:20 by moelgham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dst_cpy;
	const unsigned char	*src_cpy;
	size_t				i;

	if (!dst && !src)
		return (NULL);
	dst_cpy = (unsigned char *)dst;
	src_cpy = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dst_cpy[i] = src_cpy[i];
		i++;
	}
	return (dst);
}
