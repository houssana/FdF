/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 14:30:23 by houssana          #+#    #+#             */
/*   Updated: 2017/04/18 16:07:37 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*r;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
		i++;
	if (!(r = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	r[i] = '\0';
	while (i--)
		r[i] = f(s[i]);
	return (r);
}
