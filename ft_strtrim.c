/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo <Leo@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 18:51:36 by Leo               #+#    #+#             */
/*   Updated: 2021/11/06 14:28:10 by Leo              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;
	char	*new_str;

	i = 0;
	len = ft_strlen((char *)s1);
	while ((char *)s1[i] && ft_strchr(set, (char *)s1[i]))
		i++;
	while (len && ft_strchr(set, (char *)s1[len]))
		len--;
	new_str = ft_substr(s1[i], 0, len);
	return (new_str);
}