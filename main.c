/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 13:52:42 by houssana          #+#    #+#             */
/*   Updated: 2017/05/22 13:43:06 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

int my_key_funct(int keycode, void *param)
{
	printf("key event %d\n", keycode);
//	mlx_pixel_put(mlx, win, 300, 300, 0xFF0FF00);
	return (0);
}

int main(void)
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	void	*img;
	int		*bits_per_pixel;
	int		*size_line;
	char	*img_addr;
	int		*endian;
	int		i;

	i = -1;
	bits_per_pixel = malloc(sizeof(int));
	size_line = malloc(sizeof(int));
	endian = malloc(sizeof(int));
	img_addr = malloc(sizeof(char));
	mlx = mlx_init();
	x = 0;
	win = mlx_new_window(mlx, 400, 400, "mlx 42");
//	mlx_pixel_put(mlx, win, 200, 200, 0x00FFFFFF);
	img = mlx_new_image(mlx, 100, 100);
	img_addr = mlx_get_data_addr(img, bits_per_pixel, size_line, endian);
	*(img_addr + 0) = 255;
	*(img_addr + 1) = 0;
	*(img_addr + 2) = 0;
//	while (++i <= 0)
//	{
//		*(img_addr + i) = 255;
		//printf("img : %s\n", img_addr);
//	}
	printf("bits_per_pixel : %d\nsize_line : %d\nendian : %d\nimg : %s\n", *bits_per_pixel, *size_line, *endian, (img_addr));
	mlx_put_image_to_window(mlx, win, img, 250, 250);
	while (++x < 200)
	{
		y = 0;
		while (++y <= 200)
		{
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
		}
	}
	mlx_key_hook(win, my_key_funct, 0);
	mlx_loop(mlx);
	return (0);
}
