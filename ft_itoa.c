/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo <Leo@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:32:45 by Leo               #+#    #+#             */
/*   Updated: 2021/11/08 17:29:26 by Leo              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nblen(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	int		i;
	char	*strconvert;
	size_t	long_n;

	long_n = n;
	len = ft_nblen(long_n);
	i = 0;
	strconvert = (char *)malloc(sizeof(char) * len + 1);
	strconvert[len--] = '\0';
	if (!strconvert)
		return (NULL);
	if (long_n < 0)
	{
		long_n = long_n * -1;
		strconvert[0] = "-";
	}
	while (long_n > 0)
	{
		strconvert[len] = 48 + (long_n % 10);
		long_n = long_n / 10;
		len--;
	}
	return (strconvert);
}