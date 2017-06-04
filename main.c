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
		k[i]->y = sqrt(2 / 3) * k[i]->z - 1 / sqrt(6) * scale * (tmp + k[i]->y);	
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

void	link_pixels(t_p2 *a, t_p2 *b, int **k, t_img *img)
{
	t_p2	*a_sc;
	t_p2	*b_sc;
	double	p;
	double	i;
	int		t;

	if (a->x == b->x && a->y == b->y)
		return;
	//a_sc = new_p2(a->x * img->scale + 0*k[a->y][a->x], a->y * img->scale - 1 * k[a->y][a->x]);
	//b_sc = new_p2(b->x * img->scale + 0*k[b->y][b->x], b->y * img->scale - 1 *k[b->y][b->x]);
//	a_sc = proj_iso(a->x, a->y, k[a->y][a->x]);
//	b_sc = proj_iso(b->x, b->y, k[b->y][b->x]);
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
	t_p3		**k;
	int		i;
	int		j;
	int		w;
	t_p2	*a;
	t_p2	*b;
	t_p2	*proj;
	t_p2	*res;

	if (argc != 2)
		return (0);
	res = new_p2(0, 0);
	k = parse(to_str(argv[1]), res);
	i = -1;
	j = 0;
	mlx = mlx_init();
	img = ft_memalloc(sizeof(t_img));
	img->scale = 50;
			ft_putstr("euh\n");
			ft_putnbr(k[0]->x);
			ft_putnbr(k[0]->y);
			ft_putstr("euh\n");
	res = proj_iso(k, img->scale);
			ft_putstr("euh\n");
			ft_putnbr(k[0]->x);
			ft_putnbr(k[0]->y);
			ft_putstr("euh\n");
	win = mlx_new_window(mlx, res->x, res->y, "mlx 42");
	img->img = mlx_new_image(mlx, res->x, res->y);
	init_image(img);
	img->img_addr = mlx_get_data_addr(img->img, img->bits_per_pixel, img->size_line, img->endian);
		while (k[++i])
		{
//			proj = proj_iso(i, w, k[i][w]); 
			ft_putstr("euh\n");
			ft_putnbr(k[i]->x);
			ft_putnbr(k[i]->y);
			if (k[i]->z > 0)
				paint_pixel(img->img_addr + 1 * (k[i]->y * *(img->size_line) + k[i]->x * *(img->bits_per_pixel) / 8), 0, 0, 255);
			else
				paint_pixel(img->img_addr + 1 * (k[i]->y * *(img->size_line) + k[i]->x * *(img->bits_per_pixel) / 8), 255, 255, 255);
	//		free(proj);
		}
//	}
	a = new_p2(0, 0);
	b = new_p2(0, 0);
	while (0 && a->x < 19)
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
