#include "fdf.h"
#include "libft.h"
#include <stdlib.h>
#include <math.h>

void	init_image(t_img *img)
{
	img->bpp = malloc(sizeof(int));
	img->sl = malloc(sizeof(int));
	img->e = malloc(sizeof(int));
}

void	paint_pixel(t_img *img, t_p2 *a, char b, char g, char r)
{
	char	*addr;

	addr = img->img_addr + a->y * *(img->sl) + a->x * *(img->bpp) / 8;
	*(addr + 0) = b;
	*(addr + 1) = g;
	*(addr + 2) = r;
}

void	link_pixels(t_p3 *a, t_p3 *b, t_img *img)
{
	t_p2	*a_sc;
	t_p2	*b_sc;
	float	p;
	float	i;
	int		t;

	a_sc = new_p2(a->x, a->y);
	b_sc = new_p2(b->x, b->y);
	t = abs(b_sc->y - a_sc->y) >= abs(b_sc->x - a_sc->x);
	p = (t) ? (double)(b_sc->x - a_sc->x)/(double)(b_sc->y - a_sc->y) : (double)(b_sc->y - a_sc->y)/(double)(b_sc->x - a_sc->x);
	i = 0;
	while (a_sc->x != b_sc->x || a_sc->y != b_sc->y)
	{
		i += p;
		if (!t)
			a_sc->x += ((b_sc->x - a_sc->x) / abs(b_sc->x - a_sc->x));
		else
			a_sc->x += (a_sc->x < b_sc->x) ? (int)fabs(round(i)) : -(int)fabs(round(i));
		if (t)
			a_sc->y += ((b_sc->y - a_sc->y) / abs(b_sc->y - a_sc->y));
		else
			a_sc->y += (a_sc->y < b_sc->y) ? (int)fabs(round(i)) : -(int)fabs(round(i));
		i = (fabs(i) >= 0.5) ? i - round(i) : i;
		paint_pixel(img, a_sc, 255, 255, 255);
	}
	free(a_sc);
	free(b_sc);
}

void	draw_img(t_ptr *ptr)
{
	int		i;
	int		j;

	j = -1;
	while (++j < ptr->img->res->y)
	{
		i = -1;
		while ( ++i < ptr->img->res->x)
		{
			if (i < ptr->img->res->x - 1)
				link_pixels(ptr->tab[i + (int)ptr->img->res->x*j], ptr->tab[i+(int)ptr->img->res->x*j+1], ptr->img);
			if (j < ptr->img->res->y - 1)
				link_pixels(ptr->tab[i + (int)ptr->img->res->x*j], ptr->tab[i+(int)ptr->img->res->x*j + (int)ptr->img->res->x], ptr->img);
		}
	}
}
