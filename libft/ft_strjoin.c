/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 16:23:04 by houssana          #+#    #+#             */
/*   Updated: 2017/04/18 16:14:58 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	get_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = get_strlen(s1) + get_strlen(s2);
	s = (char *)malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	s[i] = '\0';
	while (*(s1++))
		*(s++) = *(s1 - 1);
	while (*(s2++))
		*(s++) = *(s2 - 1);
	return (s - i);
}
