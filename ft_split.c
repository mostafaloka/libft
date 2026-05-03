/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelgham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:22:03 by moelgham          #+#    #+#             */
/*   Updated: 2024/11/08 15:23:52 by moelgham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	wordcount(char const *s, char c)
{
	size_t	cont;

	cont = 0;
	while (*s)
	{
		if (*s != c)
		{
			while (*s != c && *s)
				s++;
			cont++;
		}
		if (*s == '\0')
			break ;
		s++;
	}
	return (cont);
}

static char	*cutword(const char *s, char c)
{
	size_t	i;
	char	*str;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s, i + 1);
	return (str);
}

void	freestr(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	split = malloc(sizeof(char *) * (wordcount(s, c) + 1));
	if (!split)
		return (NULL);
	while (s[i] && j < wordcount(s, c))
	{
		while (s[i] == c && s[i])
			i++;
		split[j] = cutword(s + i, c);
		if (!split[j])
			freestr(split);
		i += ft_strlen(split[j]);
		j++;
	}
	split[j] = NULL;
	return (split);
}
