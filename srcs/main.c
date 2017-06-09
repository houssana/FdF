/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 13:52:42 by houssana          #+#    #+#             */
/*   Updated: 2017/06/09 18:14:03 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void	free_ptr(t_ptr *p)
{
	int		i;

	i = -1;
	free(p->i->bpp);
	free(p->i->sl);
	free(p->i->e);
	free(p->i);
	free(p->sr);
	free(p->r);
	while (p->t[++i])
			free(p->t[i]);
	free(p->t);
	free(p);
}

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
		free_ptr(p);
		exit(1);
	}
	return (0);
}

int		expose_hook(t_ptr *p)
{
	float	s;

	s = (p->ws - 1) / 2;
	draw_img(p);
	mlx_put_image_to_window(p->m, p->w, p->i->i, s * p->sr->x, s * p->sr->y);
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
	p->ws = 1.2; 
	p->w = mlx_new_window(p->m, p->sr->x * p->ws, p->sr->y * p->ws, "mlx 42");
	p->i->i = mlx_new_image(p->m, p->sr->x, p->sr->y);
	p->i->i_a = mlx_get_data_addr(p->i->i, p->i->bpp, p->i->sl, p->i->e);
}

int		main(int argc, char **argv)
{
	t_ptr	*p;

	if (argc != 2)
		return (0);
	p = (t_ptr*)malloc(sizeof(t_ptr));
	init_ptr(p, argv);
	mlx_key_hook(p->w, my_key_funct, p);
	mlx_expose_hook(p->w, expose_hook, p);
	mlx_loop(p->m);
	return (0);
}
