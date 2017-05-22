/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 18:11:26 by houssana          #+#    #+#             */
/*   Updated: 2017/04/18 15:14:21 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*t;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	if (!(t = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	t[i] = '\0';
	while (i--)
		t[i] = s1[i];
	return (t);
}
