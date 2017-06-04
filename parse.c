/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:27:22 by houssana          #+#    #+#             */
/*   Updated: 2017/05/31 13:40:49 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "libft/get_next_line.h"
#include "libft/get_next_line.h"
#include "fdf.h"

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

t_p3	*new_p3(int x, int y, int z)
{
	t_p3	*p;

	p = (t_p3*)malloc(sizeof(t_p3));
	p->x = x;
	p->y = y;
	p->z = z;
	return (p);
}

t_p3	**parse(char *str, t_p2 *res)
{
	t_p3	**r;
	char	**s;
	char	**tmp;
	int		i;
	int		j;
	int		k;
	
	i = 0;
	j = 0;
	k = 0;
	s = ft_strsplit(str, '\n');
	while (s[i])
		i++;
	tmp = ft_strsplit(s[0], ' ');
	while (tmp[j])
		j++;
	res->x = j;
	res->y = i;
	r = (t_p3**)malloc(sizeof(t_p3*) * (i * j + 1));
	i = -1;
	while (s[++i])
	{
		ft_putstr("ok\n");
		tmp = ft_strsplit(s[i], ' ');
		j = -1;
		while (tmp[++j])
			r[k++] = new_p3(j, i, atoi(tmp[j]));
	}
	r[k] = NULL;
	free(str);
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
