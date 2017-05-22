/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 17:25:43 by houssana          #+#    #+#             */
/*   Updated: 2017/04/18 14:28:52 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	uc;
	unsigned char	*s;
	unsigned char	*d;
	int				i;

	uc = c;
	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	i = 0;
	while (n--)
	{
		d[i] = s[i];
		if (s[i] == uc)
			return (d + i + 1);
		i++;
	}
	return (NULL);
}
