/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelgham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:01:26 by moelgham          #+#    #+#             */
/*   Updated: 2024/11/05 16:04:48 by moelgham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*cs;
	unsigned char	*cd;

	if (!dst || !src)
		return (NULL);
	cs = (unsigned char *)src;
	cd = (unsigned char *)dst;
	if (dst > src)
	{
		while (len-- > 0)
			cd[len] = cs[len];
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
