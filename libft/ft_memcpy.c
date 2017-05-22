/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 17:08:37 by houssana          #+#    #+#             */
/*   Updated: 2017/04/20 10:23:52 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*ds;
	char	*sr;

	ds = (char*)dst;
	sr = (char*)src;
	while (n--)
	{
		ds[n] = sr[n];
	}
	return (ds);
}
