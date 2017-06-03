/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 13:52:42 by houssana          #+#    #+#             */
/*   Updated: 2017/06/03 12:59:56 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

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
	
	p.x = x;
	p.y = y;
	return (p);
}

void	link_pixels(t_p2 a, t_p2 b, int **k, t_img *img)
{
	t_p2 *a_sc;
	t_p2 *b_sc;

	a_sc = new_p2(a.x * img->scale, a.y * img->scale);
	b_sc = new_p2(b.x * img->scale, b.y * img->scale);
		
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
	ft_putnbr(i);
	ft_putnbr(j);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 100 * j, 100 * i, "mlx 42");
	//	mlx_pixel_put(mlx, win, 200, 200, 0x00FFFFFF);
	img = ft_memalloc(sizeof(t_img));
	img->scale = 100;
	img->img = mlx_new_image(mlx, img->scale * j, img->scale * i);
	init_image(img);
	img->img_addr = mlx_get_data_addr(img->img, img->bits_per_pixel, img->size_line, img->endian);
	while (i--)
	{
		w = j;
		while (w--)
		{
			if (k[i][w] == 0)
				paint_pixel(img->img_addr + img->scale * (i * *(img->size_line) + w * *(img->bits_per_pixel)), 255, 255, 255);
			else
				paint_pixel(img->img_addr + img->scale * (i * *(img->size_line) + w * *(img->bits_per_pixel)) - k[i][w] * *(img->size_line), 0, 0, 255);
		}
	}
	printf("bits_per_pixel : %d\nsize_line : %d\nendian : %d\nimg : %s\n", *(img->bits_per_pixel), *(img->size_line), *(img->endian), (img->img_addr));
	mlx_put_image_to_window(mlx, win, img->img, 50, 50);
	//	mlx_key_hook(win, my_key_funct, 0);
	mlx_loop(mlx);
	return (0);
}
