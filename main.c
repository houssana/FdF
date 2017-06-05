/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 13:52:42 by houssana          #+#    #+#             */
/*   Updated: 2017/06/03 17:20:42 by houssana         ###   ########.fr       */
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
	printf("key event %d\n", keycode);
	//	mlx_pixel_put(mlx, win, 300, 300, 0xFF0FF00);
	return (0);
}

t_p2	*new_p2(int x, int y)
{
	t_p2	*p;

	p = (t_p2 *)malloc(sizeof(t_p2));
	p->x = x;
	p->y = y;
	return (p);
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
		k[i]->y = -sqrt(2.0 / 3.0) * +10*k[i]->z + 1.0 / sqrt(6) * scale * (tmp + k[i]->y);	
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
			paint_pixel(img->img_addr + a_sc->y * *(img->size_line) + a_sc->x * *(img->bits_per_pixel) / 8, 255, 255, 255);
	}
}

void	init_image(t_img *img)
{
	img->bits_per_pixel = malloc(sizeof(int));
	img->size_line = malloc(sizeof(int));
	img->img_addr = malloc(sizeof(char));
	img->endian = malloc(sizeof(int));
}

int		main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	t_img	*img;
	t_p3		**k;
	int		i;
	int		j;
	t_p2	*res;

	if (argc != 2)
		return (0);
	res = new_p2(0, 0);
	k = parse(to_str(argv[1]), res);
	i = -1;
	mlx = mlx_init();
	img = ft_memalloc(sizeof(t_img));
	img->scale = 50;
	res = proj_iso(k, img->scale);
	win = mlx_new_window(mlx, res->x*1.2, res->y*1.2, "mlx 42");
	img->img = mlx_new_image(mlx, res->x, res->y);
	init_image(img);
	img->img_addr = mlx_get_data_addr(img->img, img->bits_per_pixel, img->size_line, img->endian);
	while (k[++i])
	{
		if (k[i]->z > 0)
			paint_pixel(img->img_addr + 1 * (k[i]->y * *(img->size_line) + k[i]->x * *(img->bits_per_pixel) / 8), 0, 0, 255);
		else
			paint_pixel(img->img_addr + 1 * (k[i]->y * *(img->size_line) + k[i]->x * *(img->bits_per_pixel) / 8), 255, 255, 255);
	}
j = -1;
while (++j < 11)
{
i = -1;
	while ( ++i < 19)
	{
		if (i < 18)
			link_pixels(k[i + 19*j], k[i+19*j+1], img);
		if (j < 10)
			link_pixels(k[i + 19*j], k[i+19*j + 19], img);
//		link_pixels(k[i], k[i+19], img);
	}
}
printf("bits_per_pixel : %d\nsize_line : %d\nendian : %d\nimg : %s\n", *(img->bits_per_pixel), *(img->size_line), *(img->endian), (img->img_addr));
mlx_put_image_to_window(mlx, win, img->img, 0.1*res->x, 0.1*res->y);
//	mlx_key_hook(win, my_key_funct, 0);
mlx_loop(mlx);
return (0);
}
