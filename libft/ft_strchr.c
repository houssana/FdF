/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 15:14:53 by houssana          #+#    #+#             */
/*   Updated: 2017/04/17 15:25:14 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	char	cc;
	char	*ss;

	cc = c;
	ss = (char *)s;
	while (*ss)
	{
		if (cc == *ss)
			return (ss);
		ss++;
	}
	return ((cc == '\0') ? ss : NULL);
}
