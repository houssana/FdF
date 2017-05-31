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

int		**parse(char *str)
{
	int		**r;
	char	**s;
	char	**tmp;
	int		i;
	int		j;
	
	i = 0;
	s = ft_strsplit(str, '\n');
	while (s[i])
		i++;
	r = (int **)malloc(sizeof(int *) * (i + 1));
	i = -1;
	while (s[++i])
	{
		j = 0;
		tmp = ft_strsplit(s[i], ' ');
		while (tmp[j])
			j++;
		r[i] = (int *)malloc(sizeof(int) * (j + 1));
		j = -1;
		while (tmp[++j])
			r[i][j] = atoi(tmp[j]);
		r[i][j] = -1;
	}
	r[i] = NULL;
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


