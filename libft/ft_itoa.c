/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 18:33:13 by houssana          #+#    #+#             */
/*   Updated: 2017/04/16 19:05:06 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static long int		power(int n, int l)
{
	if (l == 0)
		return (1);
	return (n * power(n, l - 1));
}

char				*ft_itoa(int n)
{
	int			l;
	long int	nb;
	char		*r;
	int			sign;

	nb = n;
	l = 1;
	sign = (nb < 0) ? 1 : 0;
	nb = (nb < 0) ? -nb : nb;
	while (nb / power(10, l))
		l++;
	if (!(r = (char *)malloc(sizeof(char) * (l + sign + 1))))
		return (NULL);
	r[l + sign] = '\0';
	while (l--)
	{
		r[l + sign] = nb % 10 + '0';
		nb = nb / 10;
	}
	if (sign)
		r[0] = '-';
	return (r);
}
