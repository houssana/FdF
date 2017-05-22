/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 17:09:55 by houssana          #+#    #+#             */
/*   Updated: 2017/04/20 11:44:45 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		count_words(char const *s, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (s[i])
	{
		j = i;
		while (s[j] == c)
			j++;
		i = j;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
			k++;
	}
	return (k);
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

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	i = 0;
	if (!s)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1))))
		return (NULL);
	k = 0;
	while (s[i])
	{
		j = i;
		while (s[j] == c)
			j++;
		if (!s[j])
			break ;
		i = j;
		while (s[i] && s[i] != c)
			i++;
		tab[k++] = get_strsub(s, j, i - j);
	}
	tab[k] = NULL;
	return (tab);
}
