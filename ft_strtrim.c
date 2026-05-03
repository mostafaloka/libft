/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelgham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:14:23 by moelgham          #+#    #+#             */
/*   Updated: 2024/11/08 15:19:04 by moelgham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_check(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	siz;
	char	*new;

	if (!s1 || !set)
		return (NULL);
	while (s1)
	{
		if (ft_check(((char)*s1), set) == 1)
			s1++;
		else
			break ;
	}
	siz = ft_strlen(s1);
	while (siz != 0)
	{
		if (ft_check(s1[siz - 1], set) == 1)
			siz--;
		else
			break ;
	}
	new = (char *)malloc(siz * sizeof(char) + 1);
	if (!new)
		return (NULL);
	ft_strlcpy(new, (char *)s1, siz + 1);
	return (new);
}
