/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 15:15:52 by houssana          #+#    #+#             */
/*   Updated: 2017/06/13 18:10:47 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void	free_if(void *ptr)
{
	if (ptr)
		free(ptr);
}
void	free_ptr(t_ptr *p)
{
	int		i;

	i = -1;
	if (p->i)
	{
		free_if(p->i->bpp);
		free_if(p->i->sl);
		free_if(p->i->e);
		free_if(p->i);
	}
	free_if(p->sr);
	free_if(p->r);
	free_if(p->alt);
	if (p->t)
		while (p->t[++i])
			free_if(p->t[i]);
	free_if(p->t);
	i = -1;
	if (p->col)
		while (p->col[++i])
			free_if(p->col[i]);
	free_if(p->col);
	free_if(p);
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
