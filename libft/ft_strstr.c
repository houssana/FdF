/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 15:34:37 by houssana          #+#    #+#             */
/*   Updated: 2017/04/17 15:45:43 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;
	char	*b;

	i = 0;
	b = (char *)big;
	if (*little == '\0')
		return (b);
	while (b[i])
	{
		j = 0;
		while (b[i++] == little[j++])
			if (!little[j])
				return (b + i - j);
		i += (1 - j);
	}
	return (NULL);
}
