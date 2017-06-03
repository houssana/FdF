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

void	paint_pixel(char *addr, char b, char g, char r)
{
	*addr = b;
	*(addr + 1) = g;
	*(addr + 2) = r;
}

t_p2	*new_p2(int x, int y)
{
	t_p2	*p;
	
	p = (t_p2 *)malloc(sizeof(t_p2));
	p->x = x;
	p->y = y;
	return (p);
}

void	link_pixels(t_p2 *a, t_p2 *b, int **k, t_img *img)
{
	t_p2	*a_sc;
	t_p2	*b_sc;
	double	p;
	double	i;
	int		t;

	if (a->x == b->x && a->y == b->y)
		return;
	a_sc = new_p2(a->x * img->scale + 0*k[a->y][a->x], a->y * img->scale - 1 * k[a->y][a->x]);
	b_sc = new_p2(b->x * img->scale + 0*k[b->y][b->x], b->y * img->scale - 1 *k[b->y][b->x]);
	t = (b_sc->y - a_sc->y) >= (b_sc->x - a_sc->x);
	p = fmin(b_sc->y - a_sc->y, b_sc->x - a_sc->x)/fmax(b_sc->y - a_sc->y, b_sc->x - a_sc->x);
	i = 0;
	while (a_sc->x != b_sc->x || a_sc->y != b_sc->y)
	{
		i += p;
		if (!t && a_sc->x != b_sc->x)
			a_sc->x += ((b_sc->x - a_sc->x) / abs(b_sc->x - a_sc->x));
		else
			a_sc->x += (p >= 0) ? (int)floor(i) : (int)ceil(i);
		if (t && a_sc->y != b_sc->y)
			a_sc->y += ((b_sc->y - a_sc->y) / abs(b_sc->y - a_sc->y));
		else
			a_sc->y += (p >= 0) ? (int)floor(i) : (int)ceil(i);
		if (i >= 1 || i <= -1)
			i = 0;
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
	int		**k;
	int		i;
	int		j;
	int		w;
	t_p2	*a;
	t_p2	*b;

	if (argc != 2)
	{
		return (0);
	}
	k = parse(to_str(argv[1]));
	i = 0;
	j = 0;
	while (k[i]) 
		i++;
	while (k[0][j] >= 0) 
		j++;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 50 * j, 50 * i, "mlx 42");
	img = ft_memalloc(sizeof(t_img));
	img->scale = 50;
	img->img = mlx_new_image(mlx, img->scale * j, img->scale * i);
	init_image(img);
	img->img_addr = mlx_get_data_addr(img->img, img->bits_per_pixel, img->size_line, img->endian);
	while (i--)
	{
		w = j;
		while (w--)
		{
			if (k[i][w] == 0)
				paint_pixel(img->img_addr + img->scale * (i * *(img->size_line) + w * *(img->bits_per_pixel) / 8), 0, 0, 255);
			else
				paint_pixel(img->img_addr + img->scale * (i * *(img->size_line) + w * *(img->bits_per_pixel) / 8) - k[i][w] * *(img->size_line), 255, 0, 255);
		}
	}
	a = new_p2(0, 0);
	b = new_p2(0, 0);
	while (a->x < 19)
	{
		a->y = 0;
		while (a->y < 11)
		{
			b->x = a->x;
			b->y = a->y + 1;
			if (a->y < 10)
				link_pixels(a, b, k, img);
			b->x = a->x + 1;
			b->y = a->y;
			if (a->x < 18)
				link_pixels(a, b, k, img);
			a->y = a->y + 1;
		}
		a->x = a->x + 1;
	}
//	link_pixels(a, b, img);
	printf("bits_per_pixel : %d\nsize_line : %d\nendian : %d\nimg : %s\n", *(img->bits_per_pixel), *(img->size_line), *(img->endian), (img->img_addr));
	mlx_put_image_to_window(mlx, win, img->img, 25, 25);
	//	mlx_key_hook(win, my_key_funct, 0);
	mlx_loop(mlx);
	return (0);
}
