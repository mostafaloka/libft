/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelgham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:41:01 by moelgham          #+#    #+#             */
/*   Updated: 2024/11/06 11:47:18 by moelgham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*ft_char(char *s, unsigned int number, long int len)
{
	while (number > 0)
	{
		s[len--] = 48 + (number % 10);
		number = number / 10;
	}
	return (s);
}

static long int	ft_lng(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char				*s;
	long int			lng;
	unsigned int		numb;
	int					sin;

	sin = 1;
	lng = ft_lng(n);
	s = (char *)malloc(sizeof(char) * (lng + 1));
	if (!(s))
		return (NULL);
	s[lng--] = '\0';
	if (n == 0)
		s[0] = '0';
	if (n < 0)
	{
		sin *= -1;
		numb = n * -1;
		s[0] = '-';
	}
	else
		numb = n;
	s = ft_char(s, numb, lng);
	return (s);
}
