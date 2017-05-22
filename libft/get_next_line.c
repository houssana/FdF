/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 15:13:58 by houssana          #+#    #+#             */
/*   Updated: 2017/05/22 14:44:17 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "get_next_line.h"
#include "libft.h"

int		add_to_list(t_file **list, const int fd, t_file *file)
{
	file->fd = fd;
	file->next = *list;
	if (!(file->str = ft_strnew(1)))
		return (0);
	*list = file;
	return (1);
}

void	remove_from_lst(const int fd, t_file **lst)
{
	t_file	*prev;
	t_file	*l;

	prev = 0;
	l = *lst;
	while (l && l->fd != fd)
	{
		prev = l;
		l = l->next;
	}
	if (prev)
		prev->next = l->next;
	else if (l->next)
		*lst = l->next;
	else
		*lst = 0;
	ft_strdel(&(l->str));
	ft_memdel((void **)&l);
}

int		check_last_line(int len, char **line, t_file *file, char **buffer)
{
	ft_strdel(buffer);
	if (len == -1)
		return (-1);
	if (ft_strlen(file->str) > 0)
	{
		*line = ft_strdup(file->str);
		ft_strdel(&(file->str));
		file->str = ft_strnew(1);
		return (1);
	}
	return (0);
}

int		next_line(const int fd, char **line, t_file *file)
{
	int		len;
	char	*buffer;
	char	*s;

	if (!(buffer = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	while (file && file->fd != fd)
		file = file->next;
	while (!(s = ft_strstr(file->str, "\n")))
	{
		if ((len = read(fd, buffer, BUFF_SIZE)) <= 0)
			return (check_last_line(len, line, file, &buffer));
		buffer[len] = '\0';
		s = ft_strjoin(file->str, buffer);
		ft_strdel(&(file->str));
		file->str = s;
	}
	ft_strdel(&buffer);
	len = (int)(s - file->str + 1);
	*line = ft_strsub(file->str, 0, len - 1);
	s = ft_strsub(file->str, len, ft_strlen(file->str) - len);
	ft_strdel(&(file->str));
	file->str = s;
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static	t_file	*file_lst = 0;
	t_file			*file;
	int				r;

	file = 0;
	if (!line || read(fd, file, 0) == -1)
		return (-1);
	file = file_lst;
	while (file)
	{
		if (file->fd == fd)
			break ;
		file = file->next;
	}
	if (!file)
	{
		if (!(file = (t_file *)malloc(sizeof(t_file))))
			return (-1);
		if (!(add_to_list(&file_lst, fd, file)))
			return (-1);
	}
	if (!(r = next_line(fd, line, file)))
		remove_from_lst(fd, &file_lst);
	return (r);
}
