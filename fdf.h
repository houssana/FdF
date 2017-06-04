/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:34:05 by houssana          #+#    #+#             */
/*   Updated: 2017/06/03 12:25:44 by houssana         ###   ########.fr       */
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
	int		*bits_per_pixel;
	int		*size_line;
	int		*endian;
	int		scale;
}				t_img;
t_p3			**parse(char *str, t_p2 *res);
#endif
