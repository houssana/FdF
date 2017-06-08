#include "fdf.h"
#include "libft.h"
#include <stdlib.h>
#include <math.h>

void	paint_pixel(t_img *img, t_p3 *a, char b, char g, char r)
{
	char	*addr;

	addr = img->i_a + a->y * *(img->sl) + a->x * *(img->bpp) / 8;
	*(addr + 0) = b;
	*(addr + 1) = g - 20 * a->z;
	*(addr + 2) = r - 20 * a->z;
}

void	interpolate(t_p3 *c, t_p3 *d, float p, int t, float z)
{
	static float	i = 0;
	static float	alt = 0;

	i = (fabs(i) >= 0.5) ? i + p - round(i) : i + p;
	alt = (alt >= 0.5) ? alt + z - round(alt) : alt + z;
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

void	link_pix(t_p3 *a, t_p3 *b, t_img *img)
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
		interpolate(c, d, p, t, fabs(z));
		paint_pixel(img, c, 255, 255, 255);
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
		while ( ++i < p->r->x)
		{
			if (i < r->x - 1)
				link_pix(t[i + r->x * j], t[i + r->x * j + 1], p->i);
			if (j < r->y - 1)
				link_pix(t[i + r->x * j], t[i + r->x * j + r->x], p->i);
		}
	}
	free(r);
}
