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
