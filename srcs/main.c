/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 13:52:42 by houssana          #+#    #+#             */
/*   Updated: 2017/06/09 17:19:05 by houssana         ###   ########.fr       */
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
	t_ptr	*p;
	p = (t_ptr*)param;
	printf("key event %d\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_image(p->m, p->i->i);
		mlx_clear_window(p->m, p->w);
		mlx_destroy_window(p->m, p->w);
		free(p->i->bpp);
		free(p->i->sl);
		free(p->i->e);
		free(p->i);
		free(p);
		exit(1);
	}
	return (0);
}

int		expose(void *param)
{
	ft_putstr("exposed");
	return (0);
}

void	init_ptr(t_ptr *p, char **argv)
{
	p->r = new_p2(0, 0);
	if (!(p->t = parse(to_str(argv[1]), p->r)))
	{
		free(p->r);
		free(p);
		ft_putstr("invalid file\n");
		exit(0);
	}
	p->i = ft_memalloc(sizeof(t_img));
	p->i->bpp = malloc(sizeof(int));
	p->i->sl = malloc(sizeof(int));
	p->i->e = malloc(sizeof(int));
	p->m = mlx_init();
	p->i->scl = 25;
	p->sr = proj_iso(p->t, p->i->scl);
	p->w = mlx_new_window(p->m, p->sr->x*1.2, p->sr->y*1.2, "mlx 42");
	p->i->i = mlx_new_image(p->m, p->sr->x, p->sr->y);
	p->i->i_a = mlx_get_data_addr(p->i->i, p->i->bpp, p->i->sl, p->i->e);
}

int		main(int argc, char **argv)
{
	int		i;
	t_ptr	*p;
	float		s;

	if (argc != 2)
		return (0);
	s = 0.1;
	p = (t_ptr*)malloc(sizeof(t_ptr));
	init_ptr(p, argv);
	draw_img(p);
//	//printf("bits_per_pixel : %d\nsize_line : %d\nendian : %d\nimg : %s\n", *(img->bpp), *(img->sl), *(img->e), (img->img_addr));
	mlx_put_image_to_window(p->m, p->w, p->i->i, s * p->sr->x, s * p->sr->y);
	free(p->sr);
	free(p->r);
	i = -1;
	while (p->t[++i])
		free(p->t[i]);
	free(p->t);
	mlx_key_hook(p->w, my_key_funct, p);
	mlx_expose_hook(p->w, my_key_funct, p);
	mlx_loop(p->m);
	return (0);
}
