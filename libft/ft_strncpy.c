/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 13:56:58 by houssana          #+#    #+#             */
/*   Updated: 2017/04/20 11:42:21 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while (src[i] && len)
	{
		len--;
		dst[i] = src[i];
		i++;
	}
	while (len)
	{
		dst[i] = '\0';
		i++;
		len--;
	}
	return (dst);
}
