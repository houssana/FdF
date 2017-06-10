/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 16:37:10 by houssana          #+#    #+#             */
/*   Updated: 2017/06/10 16:38:39 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

int		is_num(char *s)
{
	while (*(s++))
		if (*(s - 1) <= '0' || *(s - 1) <= '0')
			return (0);
	return (1);
}

void	free_tab(char **s)
{
	int i;

	i = -1;
	while (s[++i])
		free(s[i]);
	free(s);
}

int		get_height(t_p3 **t, t_p2 *alt)
{
	int	i;
	int min;
	int max;

	i = -1;
	max = t[0]->z;
	min = t[0]->z;
	while (t[++i])
	{
		max = (t[i]->z > max) ? t[i]->z : max;
		min = (t[i]->z < min) ? t[i]->z : min;
	}
	alt->x = min;
	alt->y = max;
	return (max - min);
}
