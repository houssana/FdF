/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 16:38:40 by houssana          #+#    #+#             */
/*   Updated: 2017/04/20 11:41:30 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				i;
	unsigned char	*s;
	unsigned char	*t;

	s = (unsigned char *)s1;
	t = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (s[i] == t[i] && s[i] && t[i] && --n)
		i++;
	return (s[i] - t[i]);
}
