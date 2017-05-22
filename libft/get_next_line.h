/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 15:11:54 by houssana          #+#    #+#             */
/*   Updated: 2017/05/10 10:53:50 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32

int						get_next_line(const int fd, char **line);
typedef struct s_file	t_file;
struct					s_file
{
	int		fd;
	char	*str;
	t_file	*next;
};
#endif
