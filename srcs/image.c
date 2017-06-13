/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 15:27:24 by houssana          #+#    #+#             */
/*   Updated: 2017/06/13 16:03:03 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

void	paint_pixel(t_ptr *p, t_p3 *a)
{
	char	*addr;
	float	h;
	float	i;
	t_p3	*c1;
	t_p3	*c2;

	h = (float)(a->z - p->alt->x) / (float)(p->r->z) * (float)(p->nb_col - 1);
	c1 = p->col[(int)fmin(h, p->nb_col - 2) + 1];
	c2 = p->col[(int)fmin(h + 1, p->nb_col - 1) + 1];
	h = (int)fmin(h, p->nb_col - 2);
	i = ((a->z - h / (p->nb_col - 1) * p->r->z)) / (p->r->z / (p->nb_col - 1));
	addr = p->i->i_a + a->y * *(p->i->sl) + a->x * *(p->i->bpp) / 8;
	if (*addr || *(addr + 1) || *(addr + 2))
		if (abs(c2->x - *addr) < fabs(c1->x + (c2->x - c1->x) * i) \
		|| abs(c2->y - *(addr + 1)) < fabs(c1->y + (c2->y - c1->y) * i) \
		|| abs(c2->z - *(addr + 2)) < fabs(c1->z + (c2->z - c1->z) * i))
			return ;
	*(addr + 0) = c1->x + (c2->x - c1->x) * i;
	*(addr + 1) = c1->y + (c2->y - c1->y) * i;
	*(addr + 2) = c1->z + (c2->z - c1->z) * i;
}

void	interpolate(t_p3 *c, t_p3 *d, float p, float z)
{
	static float	i = 0;
	static float	alt = 0;
	int				t;

	i = (fabs(i) >= 0.5) ? i + p - round(i) : i + p;
	alt = (alt >= 0.5) ? alt + z - round(alt) : alt + z;
	t = abs(d->y - c->y) >= abs(d->x - c->x);
	if (!t)
		c->x += ((d->x - c->x) / abs(d->x - c->x));
	else
		c->x += (c->x < d->x) ? (int)fabs(round(i)) : -(int)fabs(round(i));
	if (t)
		c->y += ((d->y - c->y) / abs(d->y - c->y));
	else
		c->y += (c->y < d->y) ? (int)fabs(round(i)) : -(int)fabs(round(i));
	c->z += (c->z < d->z) ? (int)fabs(round(alt)) : -(int)fabs(round(alt));
	if (!diff(c, d, 0) && !diff(c, d, 1))
	{
		i = 0;
		alt = 0;
	}
}

void	link_pix(t_p3 *a, t_p3 *b, t_ptr *ptr)
{
	t_p3	*c;
	t_p3	*d;
	float	p;
	float	z;
	int		t;

	c = new_p3(a->x, a->y, a->z);
	d = new_p3(b->x, b->y, b->z);
	t = abs(d->y - c->y) >= abs(d->x - c->x);
	p = (t) ? (diff(c, d, 0) / diff(c, d, 1)) : (diff(c, d, 1) / diff(c, d, 0));
	z = (t) ? (diff(c, d, 2) / diff(c, d, 1)) : (diff(c, d, 2) / diff(c, d, 0));
	while (c->x != d->x || c->y != d->y)
	{
		interpolate(c, d, p, fabs(z));
		paint_pixel(ptr, c);
	}
	free(c);
	free(d);
}

void	draw_img(t_ptr *p)
{
	int		i;
	int		j;
	t_p2	*r;
	t_p3	**t;

	j = -1;
	r = new_p2(p->r->x, p->r->y);
	t = p->t;
	while (++j < p->r->y)
	{
		i = -1;
		while (++i < p->r->x)
		{
			if (i < r->x - 1)
				link_pix(t[i + r->x * j], t[i + r->x * j + 1], p);
			if (j < r->y - 1)
				link_pix(t[i + r->x * j], t[i + r->x * j + r->x], p);
		}
	}
	free(r);
}
