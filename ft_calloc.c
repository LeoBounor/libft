/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbounor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:32:04 by lbounor           #+#    #+#             */
/*   Updated: 2021/11/10 14:48:45 by lbounor          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*chaine;

	chaine = (void *)malloc(count * size);
	if (!chaine)
		return (NULL);
	ft_bzero(chaine, count * size);
	return (chaine);
}
