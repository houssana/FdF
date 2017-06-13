/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 13:52:42 by houssana          #+#    #+#             */
/*   Updated: 2017/06/13 18:07:39 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int		scale(t_ptr *p)
{
	int		sc;

	sc = SCL;
	while (sc * p->r->x < MIN_WIDTH || sc * p->r->y < MIN_HEIGHT)
		sc++;
	while (sc * p->r->x > MAX_WIDTH || sc * p->r->y > MAX_HEIGHT)
		if (--sc == 1)
			break ;
	return (sc);
}

void	init_ptr(t_ptr *p, char **argv)
{
	p->alt = new_p2(0, 0);
	p->i = ft_memalloc(sizeof(t_img));
	p->i->bpp = malloc(sizeof(int));
	p->i->sl = malloc(sizeof(int));
	p->i->e = malloc(sizeof(int));
	p->m = mlx_init();
	p->r = new_p3(0, 0, 0);
	if (!(p->t = parse(to_str(argv[1]), p->r)))
	{
		ft_putstr("invalid file\n");
		free_ptr(p);
		exit(0);
	}
	p->r->z = get_height(p->t, p->alt);
	p->i->scl = scale(p);
	p->sr = proj_iso(p->t, p->i->scl);
	p->ws = 1.1;
	p->w = mlx_new_window(p->m, p->sr->x * p->ws, p->sr->y * p->ws, "mlx 42");
	p->i->i = mlx_new_image(p->m, p->sr->x, p->sr->y);
	p->i->i_a = mlx_get_data_addr(p->i->i, p->i->bpp, p->i->sl, p->i->e);
}

int		main(int argc, char **argv)
{
	t_ptr	*p;
	int		i;

	if (argc == 1 || fmod((argc - 2), 3) != 0)
		return (0);
	p = (t_ptr*)ft_memalloc(sizeof(t_ptr));
	p->nb_col = (argc - 2) / 3;
	p->col = ft_memalloc(sizeof(t_p3*) * (p->nb_col + 2));
	p->col[0] = new_p3(255, 255, 255);
	p->col[p->nb_col + 1] = NULL;
	i = 2;
	while (argv[i])
	{
		p->col[(i - 2) / 3 + 1] = new_p3(ft_atoi(argv[i]), \
				ft_atoi(argv[i + 1]), ft_atoi(argv[i + 2]));
		i += 3;
	}
	init_ptr(p, argv);
	mlx_key_hook(p->w, my_key_funct, p);
	mlx_expose_hook(p->w, expose_hook, p);
	mlx_loop(p->m);
	return (0);
}
