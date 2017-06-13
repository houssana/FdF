/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 15:15:52 by houssana          #+#    #+#             */
/*   Updated: 2017/06/13 15:55:36 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <stdlib.h>
#include <stdio.h>

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
	free(p->alt);
	while (p->t[++i])
		free(p->t[i]);
	i = -1;
	while (p->col[++i])
		free(p->col[i]);
	free(p->col);
	free(p);
}

int		my_key_funct(int keycode, void *param)
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
