/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 14:50:02 by houssana          #+#    #+#             */
/*   Updated: 2017/04/20 14:38:09 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		j;
	char	*r;

	i = 0;
	j = -1;
	if (!s)
		return (NULL);
	while (s[i])
		i++;
	if (!(r = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	r[i] = '\0';
	while (++j < i)
		r[j] = f(j, s[j]);
	return (r);
}
