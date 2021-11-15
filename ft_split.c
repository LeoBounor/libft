/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbounor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 14:28:50 by Leo               #+#    #+#             */
/*   Updated: 2021/11/15 15:39:33 by lbounor          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_divlen(char *s, int c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
	{
		len++;
	}
	return (len);
}

static size_t	ft_splitsize(char *s, int c)
{
	size_t	i;
	size_t	len;
	size_t	size;

	i = 0;
	len = 0;
	size = 0;
	while (s[i])
	{
		len = ft_divlen(s + i, c);
		if (len > 0)
		{
			size++;
			i--;
		}
		i += len;
		i++;
	}
	return (size);
}

static void	ft_malloc(size_t size, const char *s, char c, char **split)
{
	size = ft_splitsize((char *)s, c);
	split = malloc((size + 1) * sizeof(char *));
}

static void	ft_free(char **split, size_t n)
{
	if (!split[n])
	{
		while (n >= 0)
		{
			free(split[n]);
			n--;
		}
		free(split);
	}
}

char	**ft_split(const char *s, char c)
{
	size_t		i;
	size_t		n;
	size_t		size;
	char		**split;

	i = 0;
	n = 0;
	if (!s)
		return (NULL);
	ft_malloc(size, s, c, split);
	if (!split)
		return (NULL);
	while (((char *)s)[i])
	{
		size = ft_divlen((char *)s + i, c);
		if (size > 0)
		{
			split[n++] = ft_substr(s, i--, size);
			ft_free(split, n);
		}
		i += size;
		i++;
	}
	split[n] = 0;
	return (split);
}
