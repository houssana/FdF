/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:34:05 by houssana          #+#    #+#             */
/*   Updated: 2017/06/06 16:09:49 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

char			*ft_strjoin_free(char *s1, char *s2, int w);
char			*to_str(char *f);
typedef struct	s_point2
{
	int x;
	int y;
}				t_p2;
typedef struct	s_point3
{
	int x;
	int y;
	int z;
}				t_p3;
typedef struct	s_img
{
	void	*img;
	char	*img_addr;
	int		*bpp;
	int		*sl;
	int		*e;
	int		scl;
	t_p2	*res;
	t_p2	*s_res;
}				t_img;
typedef struct	s_pointeur
{
	void	*mlx;
	void	*win;
	t_img	*img;
	t_p3	**tab;
}				t_ptr;
t_p3			**parse(char *str, t_p2 *res);
t_p2	*new_p2(int x, int y);
t_p3	*new_p3(int x, int y, int z);
void	init_image(t_img *img);	
void	draw_img(t_ptr *ptr);	
#endif
