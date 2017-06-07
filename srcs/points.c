/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 13:44:49 by houssana          #+#    #+#             */
/*   Updated: 2017/06/06 15:49:18 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "fdf.h"

t_p2	*new_p2(int x, int y)
{
	t_p2	*p;

	p = (t_p2 *)malloc(sizeof(t_p2));
	p->x = x;
	p->y = y;
	return (p);
}

t_p3	*new_p3(int x, int y, int z)
{
	t_p3	*p;

	p = (t_p3*)malloc(sizeof(t_p3));
	p->x = x;
	p->y = y;
	p->z = z;
	return (p);
}

float	diff(t_p2 *a, t_p2 *b, int d)
{
	return ((d) ? b->y - a->y : b->x - a->x);
}

t_p2	*offset_tab(t_p3 **t)
{
	int	x;
	int	i;
	t_p2	*min;
	t_p2	*max;

	min = new_p2(0, 0);
	max = new_p2(0, 0);
	i = -1;
	while (t[++i])
	{
		min->x = (min->x > t[i]->x) ? t[i]->x : min->x;
		min->y = (min->y > t[i]->y) ? t[i]->y : min->y;
		max->x = (max->x < t[i]->x) ? t[i]->x : max->x;
		max->y = (max->y < t[i]->y) ? t[i]->y : max->y;
	}
	while (i--)
	{
		t[i]->x += -min->x;
		t[i]->y += -min->y;
	}
	max->x = max->x - min->x + 1;
	max->y = max->y - min->y + 1;
	free(min);
	return (max);
}

t_p2	*proj_iso(t_p3	**t, int s)
{
	int	x;
	int	i;

	i = -1;
	while (t[++i])
	{
		x = t[i]->x;
		t[i]->x = sqrt(2) / 2.0 * s * (t[i]->x - t[i]->y);
		t[i]->y = -sqrt(2.0 / 3) * + \
			s * t[i]->z + 1 / sqrt(6) * s *(x + t[i]->y);
	}
	return (offset_tab(t));
}
