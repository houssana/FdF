/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 15:29:09 by houssana          #+#    #+#             */
/*   Updated: 2017/04/17 16:08:58 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char	cc;
	char	*ss;
	char	*r;

	r = NULL;
	cc = c;
	ss = (char *)s;
	while (*ss)
	{
		if (cc == *ss)
			r = ss;
		ss++;
	}
	return ((cc == '\0') ? ss : r);
}
