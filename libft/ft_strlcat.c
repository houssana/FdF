/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 14:32:19 by houssana          #+#    #+#             */
/*   Updated: 2017/04/20 15:10:18 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (*dst && size)
	{
		size--;
		dst++;
		i++;
	}
	while (*(dst++))
		if (size)
			i++;
	dst--;
	while (*src && size-- > 1)
	{
		j++;
		*(dst++) = *src;
		src++;
	}
	while (*(src++))
		j++;
	*dst = '\0';
	return (i + j);
}
