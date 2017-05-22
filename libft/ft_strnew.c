/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 19:46:38 by houssana          #+#    #+#             */
/*   Updated: 2017/04/16 18:20:58 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*c;

	if (!(c = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	c[size] = '\0';
	while (size--)
		c[size] = '\0';
	return (c);
}
