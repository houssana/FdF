/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 16:41:12 by houssana          #+#    #+#             */
/*   Updated: 2017/04/20 15:39:59 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		get_strlen(char const *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char		*get_strsub(char const *s, unsigned int start, size_t len)
{
	char *r;

	r = (char *)malloc(sizeof(char) * (len + 1));
	if (!r)
		return (NULL);
	r[len] = '\0';
	while (len--)
		r[len] = s[start + len];
	return (r);
}

static int		is_blank(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char			*ft_strtrim(char const *s)
{
	char	*r;
	int		first;
	int		last;
	int		len;

	if (!s)
		return (NULL);
	len = get_strlen(s);
	first = 0;
	last = len - 1;
	while (s[first] && is_blank(s[first]))
		first++;
	if (!s[first])
		return ("");
	while (last >= first && is_blank(s[last]))
		last--;
	r = get_strsub(s, first, (last - first + 1));
	return (r);
}
