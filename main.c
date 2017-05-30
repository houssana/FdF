/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 13:52:42 by houssana          #+#    #+#             */
/*   Updated: 2017/05/30 18:43:50 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft/libft.h"
#include "libft/get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int my_key_funct(int keycode, void *param)
{
	printf("key event %d\n", keycode);
	//	mlx_pixel_put(mlx, win, 300, 300, 0xFF0FF00);
	return (0);
}

char		*ft_strjoin_free(char *s1, char *s2, int w)
{
	char	*s;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	s = (char *)malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	s[i] = '\0';
	j = -1;
	while (s1[++j])
		*(s++) = s1[j];
	j = -1;
	while (s2[++j])
		*(s++) = s2[j];
	if (w == 0 || w == 1)
		free(s1);
	if (w == 0 || w == 2)
		free(s2);
	return (s - i);
}

int		**parse(char *str)
{
	int		**r;
	char	**s;
	char	**tmp;
	int		i;
	int		j;
	
	i = 0;
	s = ft_strsplit(str, '\n');
	while (s[i])
		i++;
	r = (int **)malloc(sizeof(int *) * (i + 1));
	i = -1;
	while (s[++i])
	{
		j = 0;
		tmp = ft_strsplit(s[i], ' ');
		while (tmp[j])
			j++;
		r[i] = (int *)malloc(sizeof(int) * (j + 1));
		j = -1;
		while (tmp[++j])
			r[i][j] = atoi(tmp[j]);
		r[i][j] = -1;
	}
	r[i] = NULL;
	return (r);
}

char	*to_str(char *f)
{
	int		fd;
	char	*line;
	char	*r;

	fd = open(f, O_RDONLY);
	r = ft_strnew(1);
	while (get_next_line(fd, &line) > 0)
	{
		line = ft_strjoin_free(line, "\n", 1);
		r = ft_strjoin_free(r, line, 2);
	}
	close(fd);
	return (r);
}

int		main(int argc, char **argv)
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
	int		**k;
	int		i;
	int		j;

	if (argc != 2)
	{
		return (0);
	}
	k = parse(to_str(argv[1]));
	i = -1;
	while (k[++i]) 
	{
		j = -1;
		while (k[i][++j] >= 0)
			ft_putnbr(k[i][j]);
		ft_putchar('\n');
	}
/*	k = -1;
	bits_per_pixel = malloc(sizeof(int));
	size_line = malloc(sizeof(int));
	endian = malloc(sizeof(int));
	img_addr = malloc(sizeof(char));
	mlx = mlx_init();
	x = 0;
	win = mlx_new_window(mlx, 10 * i, 10 * j, "mlx 42");
	//	mlx_pixel_put(mlx, win, 200, 200, 0x00FFFFFF);
	img = mlx_new_image(mlx, 10 * i, 10 * j);
	img_addr = mlx_get_data_addr(img, bits_per_pixel, size_line, endian);
	while (i)
	{
		k = j;
		while (k--)
		{		
			*(img_addr + 0 + 1*(k * 10 * *size_line + i**bits_per_pixel)) = 255;
			*(img_addr + 1+ 1*(k * 10 * *size_line + i**bits_per_pixel)) = 255;
			*(img_addr + 2+ 1*(k * 10 * *size_line + i**bits_per_pixel)) = 255;
		}
		i--;
	}
	printf("bits_per_pixel : %d\nsize_line : %d\nendian : %d\nimg : %s\n", *bits_per_pixel, *size_line, *endian, (img_addr));
	mlx_put_image_to_window(mlx, win, img, 50, 50);
	//	mlx_key_hook(win, my_key_funct, 0);
	mlx_loop(mlx);
*/	return (0);
}

//int main(int argc, char **argv)
//{
//	char	*line;
//	int	i;
//	int	j;
//	int	k;
//	int	fd;
//
//	if (argc != 2)
//	{
//		return (0);
//	}
//	i = 0;
//	j = 0;
//	k = 0;
//	fd = open(argv[1], O_RDONLY);
//	while (get_next_line(fd, &line) > 0)
//	{
//		j++;
//		while (line[k] != '\0')
//		{
//			i++;
//			while (line[k] == ' ')
//				k++;
//			k += ft_intlen_base(ft_atoi(line), 10);	
//		}
//		free(line);
//	}
//	return (0);
//}
