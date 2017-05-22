/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 17:48:56 by houssana          #+#    #+#             */
/*   Updated: 2017/04/18 15:02:01 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;
	size_t	i;

	i = 0;
	d = (char*)dst;
	s = (char*)src;
	if (d < s)
		while (i++ < len)
			d[i - 1] = s[i - 1];
	else
		while (len--)
			d[len] = s[len];
	return (dst);
}
