/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:27:22 by houssana          #+#    #+#             */
/*   Updated: 2017/06/06 15:18:18 by houssana         ###   ########.fr       */
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
	{
		j++;
		free(tmp[j]);
	}
	free(tmp);
	res->x = j;
	res->y = i;
	r = (t_p3**)malloc(sizeof(t_p3*) * (i * j + 1));
	i = -1;
	while (s[++i])
	{
		tmp = ft_strsplit(s[i], ' ');
		j = -1;
		while (tmp[++j])
		{
			r[k++] = new_p3(j, i, atoi(tmp[j]));
			free(tmp[j]);
		}
		free(tmp);
		free(s[i]);
	}
	r[k] = NULL;
	free(str);
	free(s);
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
		r = ft_strjoin_free(r, line, 0);
	}
	close(fd);
	return (r);
}
