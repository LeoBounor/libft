/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbounor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:53:58 by lbounor           #+#    #+#             */
/*   Updated: 2021/11/10 13:10:45 by lbounor          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_isspace(char str)
{
	return (str == '\t' || str == '\n' || str == '\v'
		|| str == '\f' || str == '\r' || str == ' ');
}

int	ft_atoi(const char *str)
{
	char	signe;
	int		nombre;

	signe = 1;
	nombre = 0;
	while (ft_isspace(*str))
		str++;
	if (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			signe *= -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		nombre = (nombre * 10) + (*str - '0');
		str++;
	}
	return (nombre * signe);
}
