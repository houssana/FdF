/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 15:49:48 by houssana          #+#    #+#             */
/*   Updated: 2017/04/17 16:07:07 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		i;
	int		j;
	char	*b;

	i = 0;
	b = (char *)big;
	if (*little == '\0')
		return (b);
	while (b[i] && len)
	{
		j = 0;
		while (b[i++] == little[j++] && len--)
			if (!little[j])
				return (b + i - j);
		i += (1 - j);
		len += (j - 2);
	}
	return (NULL);
}
