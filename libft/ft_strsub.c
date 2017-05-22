/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 16:07:47 by houssana          #+#    #+#             */
/*   Updated: 2017/04/18 16:11:09 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *r;

	r = (char *)malloc(sizeof(char) * (len + 1));
	if (!r)
		return (NULL);
	r[len] = '\0';
	if (s)
		while (len--)
			r[len] = s[start + len];
	return (r);
}
