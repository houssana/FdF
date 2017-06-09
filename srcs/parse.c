/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:27:22 by houssana          #+#    #+#             */
/*   Updated: 2017/06/09 17:18:46 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libft.h"
#include "get_next_line.h"
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

void	get_res(char **s, t_p2 *res)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	j = 0;
	while (s[i])
		i++;
	tmp = ft_strsplit(s[0], ' ');
	while (tmp[j])
		j++;
	free_tab(tmp);
	res->x = j;
	res->y = i;
}

t_p3	**parse(char *str, t_p2 *res)
{
	t_p3	**r;
	char	**s;
	char	**tmp;
	t_p3	*a;

	if (!str)
		return (NULL);
	a = new_p3(0, 0, 0);
	s = ft_strsplit(str, '\n');
	get_res(s, res);
	r = (t_p3**)ft_memalloc(sizeof(t_p3*) * (res->x * res->y + 1));
	a->x = -1;
	while (s[++(a->x)])
	{
		tmp = ft_strsplit(s[a->x], ' ');
		a->y = -1;
		while (tmp[++(a->y)])
				r[(a->z)++] = new_p3(a->y, a->x, atoi(tmp[a->y]));
		if (a->y != res->x)
			exit(0);
		free_tab(tmp);
	}
	free(str);
	free_tab(s);
	return (r);
}

char	*to_str(char *f)
{
	int		fd;
	char	*line;
	char	*r;

	if ((fd = open(f, O_RDONLY)) == -1)
		return (NULL);
	r = ft_strnew(1);
	while (get_next_line(fd, &line) > 0)
	{
		line = ft_strjoin_free(line, "\n", 1);
		r = ft_strjoin_free(r, line, 0);
	}
	close(fd);
	return (r);
}
