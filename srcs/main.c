/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 13:52:42 by houssana          #+#    #+#             */
/*   Updated: 2017/06/06 17:00:01 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "libft.h"
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
		free(ptr->img);
		free(ptr);
		exit(1);
	}
	return (0);
}

int		expose(void *param)
{
	ft_putstr("exposed");
	return (0);
}

t_p2	*proj_iso(t_p3	**tab, int scale)
{
	int	tmp;
	int	i;
	t_p2	*min;
	t_p2	*max;

	min = new_p2(0, 0);
	max = new_p2(0, 0);
	i = -1;
	while (tab[++i])
	{
		tmp = tab[i]->x;
		tab[i]->x = sqrt(2) / 2.0 * scale * (tab[i]->x - tab[i]->y);
		tab[i]->y = -sqrt(2.0 / 3.0) * +scale*tab[i]->z + 1.0 / sqrt(6) * scale * (tmp + tab[i]->y);	
		min->x = (min->x > tab[i]->x) ? tab[i]->x : min->x;
		min->y = (min->y > tab[i]->y) ? tab[i]->y : min->y;
		max->x = (max->x < tab[i]->x) ? tab[i]->x : max->x;
		max->y = (max->y < tab[i]->y) ? tab[i]->y : max->y;
	}
	while (i--)
	{
		tab[i]->x += -min->x;
		tab[i]->y += -min->y;
	}
	max->x = max->x - min->x + 1;
	max->y = max->y - min->y + 1;
	free(min);
	return (max);
}

void	init_ptr(t_ptr *ptr, char **argv)
{
	ptr->img = ft_memalloc(sizeof(t_img));
	init_image(ptr->img);
	ptr->img->res = new_p2(0, 0);
	ptr->tab = parse(to_str(argv[1]), ptr->img->res);
	ptr->mlx = mlx_init();
	ptr->img->scl = 50;
	ptr->img->s_res = proj_iso(ptr->tab, ptr->img->scl);
	ptr->win = mlx_new_window(ptr->mlx, ptr->img->s_res->x*1.2, ptr->img->s_res->y*1.2, "mlx 42");
	ptr->img->img = mlx_new_image(ptr->mlx, ptr->img->s_res->x, ptr->img->s_res->y);
	ptr->img->img_addr = mlx_get_data_addr(ptr->img->img, ptr->img->bpp, ptr->img->sl, ptr->img->e);
	
}

int		main(int argc, char **argv)
{
	int		i;
	t_ptr	*ptr;

	if (argc != 2)
		return (0);
	ptr = (t_ptr*)malloc(sizeof(t_ptr));
	init_ptr(ptr, argv);
	draw_img(ptr);
//	//printf("bits_per_pixel : %d\nsize_line : %d\nendian : %d\nimg : %s\n", *(img->bpp), *(img->sl), *(img->e), (img->img_addr));
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img->img, 0.1*ptr->img->s_res->x, 0.1*ptr->img->s_res->y);
	free(ptr->img->s_res);
	free(ptr->img->res);
	i = -1;
	while (ptr->tab[++i])
		free(ptr->tab[i]);
	free(ptr->tab);
	mlx_key_hook(ptr->win, my_key_funct, ptr);
	mlx_expose_hook(ptr->win, my_key_funct, ptr);
	mlx_loop(ptr->mlx);
	return (0);
}
