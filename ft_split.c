/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo <Leo@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 14:28:50 by Leo               #+#    #+#             */
/*   Updated: 2021/11/08 13:11:13 by Leo              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countwords(char *s, char c)
{
	size_t	i;
	size_t	cpt;

	i = 0;
	cpt = 0;
	while (s[i])
	{
		if (s[i + 1] == c && s[i] != c)
			cpt++;
		i++;
	}
	return (cpt);
}

void	ft_cpysplit(char *s, char **split, char c)
{
	size_t	i;
	size_t	j;
	size_t	a;
	size_t	cpt;

	i = 0;
	cpt = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			j = 0;
			while (s[i + j] != c)
				j++;
			split[cpt] = (char *)malloc(sizeof(char) * (j + 1));
			a = 0;
			while (s[i + a] != c)
			{
				split[cpt][a] = s[i + a];
				a++;
			}
			split[cpt][a] = '\0';
			i += j;
			cpt++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	cpt;

	cpt = ft_countwords((char *)s, c);
	split = (char **)malloc(sizeof(char *) * cpt + 1);
	if (!split)
		return (NULL);
	split[cpt] = '\0';
	ft_cpysplit((char *)s, split, c);
	return (split);
}