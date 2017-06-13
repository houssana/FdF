/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:34:05 by houssana          #+#    #+#             */
/*   Updated: 2017/06/13 17:42:47 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define SCL 25
# define MIN_WIDTH 320
# define MIN_HEIGHT 240
# define MAX_WIDTH 1920
# define MAX_HEIGHT 1080

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
	void	*i;
	char	*i_a;
	int		*bpp;
	int		*sl;
	int		*e;
	int		scl;
}				t_img;
typedef struct	s_pointeur
{
	void	*m;
	void	*w;
	t_img	*i;
	t_p3	**t;
	t_p3	*r;
	t_p2	*alt;
	t_p2	*sr;
	float	ws;
	t_p3	**col;
	int		nb_col;
}				t_ptr;
t_p3			**parse(char *str, t_p3 *res);
t_p2			*new_p2(int x, int y);
t_p3			*new_p3(int x, int y, int z);
void			init_image(t_img *img);
void			draw_img(t_ptr *ptr);
float			diff(t_p3 *a, t_p3 *b, int d);
t_p2			*proj_iso(t_p3	**t, int s);
int				is_num(char *s);
void			free_tab(char **s);
int				get_height(t_p3 **t, t_p2 *alt);
int				my_key_funct(int keycode, void *param);
int				expose_hook(t_ptr *p);
void			free_ptr(t_ptr *p);
#endif
