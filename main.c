/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 13:52:42 by houssana          #+#    #+#             */
/*   Updated: 2017/06/06 15:14:18 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int 	my_key_funct(int keycode, void *param)
{
	t_ptr	*ptr;
	ptr = (t_ptr*)param;
	printf("key event %d\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_image(ptr->mlx, ptr->img->img);
		mlx_clear_window(ptr->mlx, ptr->win);
		mlx_destroy_window(ptr->mlx, ptr->win);
		free(ptr->img->bpp);
		free(ptr->img->sl);
		free(ptr->img->e);
//		free(ptr->img->img_addr);
		free(ptr->img);
		free(ptr);
		while (1)
			continue;
		exit(1);
	}
	return (0);
}

int		expose(void *param)
{
	ft_putstr("exposed");
	return (0);
}

t_p2	*proj_iso(t_p3	**k, int scale)
{
	int	tmp;
	int	i;
	t_p2	*min;
	t_p2	*max;

	min = new_p2(0, 0);
	max = new_p2(0, 0);
	i = -1;
	while (k[++i])
	{
		tmp = k[i]->x;
		k[i]->x = sqrt(2) / 2.0 * scale * (k[i]->x - k[i]->y);
		k[i]->y = -sqrt(2.0 / 3.0) * +scale*k[i]->z + 1.0 / sqrt(6) * scale * (tmp + k[i]->y);	
		min->x = (min->x > k[i]->x) ? k[i]->x : min->x;
		min->y = (min->y > k[i]->y) ? k[i]->y : min->y;
		max->x = (max->x < k[i]->x) ? k[i]->x : max->x;
		max->y = (max->y < k[i]->y) ? k[i]->y : max->y;
	}
	while (i--)
	{
		k[i]->x += -min->x;
		k[i]->y += -min->y;
	}
	max->x = max->x - min->x + 1;
	max->y = max->y - min->y + 1;
	return (max);
}

void	paint_pixel(char *addr, char b, char g, char r)
{
	*addr = b;
	*(addr + 1) = g;
	*(addr + 2) = r;
}

void	link_pixels(t_p3 *a, t_p3 *b, t_img *img)
{
	t_p2	*a_sc;
	t_p2	*b_sc;
	float	p;
	double	i;
	int		t;

	if (a->x == b->x && a->y == b->y)
		return;
	a_sc = new_p2(a->x, a->y);
	b_sc = new_p2(b->x, b->y);
	t = abs(b_sc->y - a_sc->y) >= abs(b_sc->x - a_sc->x);
	p = (t) ? (double)(b_sc->x - a_sc->x)/(double)(b_sc->y - a_sc->y) :(double)(b_sc->y - a_sc->y)/(double)(b_sc->x - a_sc->x);
	i = 0;
	while (a_sc->x != b_sc->x || a_sc->y != b_sc->y)
	{
		i += p;
		if (!t && a_sc->x != b_sc->x)
			a_sc->x += ((b_sc->x - a_sc->x) / abs(b_sc->x - a_sc->x));
		else
			a_sc->x += (a_sc->x < b_sc->x) ? (int)fabs(round(i)) : -(int)fabs(round(i));
		if (t && a_sc->y != b_sc->y)
			a_sc->y += ((b_sc->y - a_sc->y) / abs(b_sc->y - a_sc->y));
		else
			a_sc->y += (a_sc->y < b_sc->y) ? (int)fabs(round(i)) : -(int)fabs(round(i));
		if (i >= 0.5)
			i -= 1;
		else if (i <= -0.5)
			i += 1;
		if (a_sc->x != b_sc->x || a_sc->y != b_sc->y)
			paint_pixel(img->img_addr + a_sc->y * *(img->sl) + a_sc->x * *(img->bpp) / 8, 255, 255, 255);
	}
	free(a_sc);
	free(b_sc);
}

void	init_image(t_img *img)
{
	img->bpp = malloc(sizeof(int));
	img->sl = malloc(sizeof(int));
//	img->img_addr = malloc(sizeof(char));
	img->e = malloc(sizeof(int));
}

int		main(int argc, char **argv)
{
	t_ptr	*ptr;
	t_p3		**k;
	int		i;
	int		j;
	t_p2	*res;
	t_p2	*res2;

	if (argc != 2)
		return (0);
	ptr = (t_ptr*)malloc(sizeof(t_ptr));
	res = new_p2(0, 0);
	res2 = new_p2(0, 0);
	k = parse(to_str(argv[1]), res2);
	i = -1;
	ptr->mlx = mlx_init();
	ptr->img = ft_memalloc(sizeof(t_img));
	ptr->img->scl = 50;
	res = proj_iso(k, ptr->img->scl);
	ptr->win = mlx_new_window(ptr->mlx, res->x*1.2, res->y*1.2, "mlx 42");
	ptr->img->img = mlx_new_image(ptr->mlx, res->x, res->y);
	init_image(ptr->img);
	ptr->img->img_addr = mlx_get_data_addr(ptr->img->img, ptr->img->bpp, ptr->img->sl, ptr->img->e);
	while (k[++i])
	{
		if (k[i]->z > 0)
			paint_pixel(ptr->img->img_addr + 1 * (k[i]->y * *(ptr->img->sl) + k[i]->x * *(ptr->img->bpp) / 8), 0, 0, 255);
		else
			paint_pixel(ptr->img->img_addr + 1 * (k[i]->y * *(ptr->img->sl) + k[i]->x * *(ptr->img->bpp) / 8), 255, 255, 255);
	}
j = -1;
while (++j < res2->y)
{
i = -1;
	while ( ++i < res2->x)
	{
		if (i < res2->x - 1)
			link_pixels(k[i + res2->x*j], k[i+res2->x*j+1], ptr->img);
		if (j < res2->y - 1)
			link_pixels(k[i + res2->x*j], k[i+res2->x*j + res2->x], ptr->img);
	}
}
//printf("bits_per_pixel : %d\nsize_line : %d\nendian : %d\nimg : %s\n", *(img->bpp), *(img->sl), *(img->e), (img->img_addr));
mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img->img, 0.1*res->x, 0.1*res->y);
free(res);
free(res2);
i = -1;
while (k[++i])
	free(k[i]);
free(k);
	mlx_key_hook(ptr->win, my_key_funct, ptr);
	mlx_expose_hook(ptr->win, my_key_funct, ptr);
mlx_loop(ptr->mlx);
return (0);
		free(ptr->img->img_addr);
}
