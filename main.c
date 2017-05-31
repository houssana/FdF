/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 13:52:42 by houssana          #+#    #+#             */
/*   Updated: 2017/05/31 14:55:58 by houssana         ###   ########.fr       */
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

void	link_pixels(int i, int j, int **k)
{
	
}

int		main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	void	*img;
	int		*bits_per_pixel;
	int		*size_line;
	char	*img_addr;
	int		*endian;
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
	bits_per_pixel = malloc(sizeof(int));
	size_line = malloc(sizeof(int));
	endian = malloc(sizeof(int));
	img_addr = malloc(sizeof(char));
	mlx = mlx_init();
	win = mlx_new_window(mlx, 100 * j, 100 * i, "mlx 42");
	//	mlx_pixel_put(mlx, win, 200, 200, 0x00FFFFFF);
	img = mlx_new_image(mlx, 100 * j, 100 * i);
	img_addr = mlx_get_data_addr(img, bits_per_pixel, size_line, endian);
	while (i--)
	{
		w = j;
		while (w--)
		{
			if (k[i][w] == 0)
				paint_pixel(img_addr + 100 * (i * (*size_line) + w * (*bits_per_pixel)), 255, 255, 255);
			else
				paint_pixel(img_addr + 100 * (i * (*size_line) + w * (*bits_per_pixel)) - k[i][w] * (*size_line), 0, 0, 255);
		}
	}
	printf("bits_per_pixel : %d\nsize_line : %d\nendian : %d\nimg : %s\n", *bits_per_pixel, *size_line, *endian, (img_addr));
	mlx_put_image_to_window(mlx, win, img, 50, 50);
	//	mlx_key_hook(win, my_key_funct, 0);
	mlx_loop(mlx);
	return (0);
}
