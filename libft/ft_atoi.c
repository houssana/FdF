/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 16:55:16 by houssana          #+#    #+#             */
/*   Updated: 2017/04/17 18:18:37 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_blank(char c)
{
	int a;
	int b;

	a = (c == ' ' || c == '\t' || c == '\n');
	b = (c == '\r' || c == '\v' || c == '\f');
	return (a || b);
}

int			ft_atoi(const char *s)
{
	int i;
	int sign;
	int r;

	r = 0;
	i = 0;
	sign = 1;
	while (is_blank(s[i]))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		r = r * 10 + s[i] - '0';
		i++;
	}
	return (sign * r);
}
