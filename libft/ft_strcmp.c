/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 16:36:15 by houssana          #+#    #+#             */
/*   Updated: 2017/04/18 15:24:33 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*s;
	unsigned char	*t;

	s = (unsigned char *)s1;
	t = (unsigned char *)s2;
	i = 0;
	while (s[i] == t[i] && s[i] && t[i])
		i++;
	return (s[i] - t[i]);
}
