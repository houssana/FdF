/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 19:02:12 by houssana          #+#    #+#             */
/*   Updated: 2017/04/18 15:52:08 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	unsigned char	*s;

	if (!(s = (unsigned char *)malloc(size)))
		return (NULL);
	while (size--)
		s[size] = 0;
	return (s);
}
