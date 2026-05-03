/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelgham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:57:48 by moelgham          #+#    #+#             */
/*   Updated: 2024/11/08 09:52:15 by moelgham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	sze;
	char	*dst;

	sze = ft_strlen(s1);
	dst = (char *)malloc(sze * sizeof(char) + 1);
	if (dst == NULL)
		return (0);
	ft_memcpy(dst, s1, sze);
	dst[sze] = '\0';
	return (dst);
}
