/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 18:29:47 by houssana          #+#    #+#             */
/*   Updated: 2017/04/20 10:24:04 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdlib.h>

static void			*memalloc(size_t size)
{
	unsigned char	*s;

	if (!(s = (unsigned char *)malloc(size)))
		return (NULL);
	while (size--)
		s[size] = 0;
	return (s);
}

static void			*memcpy2(void *dst, const void *src, size_t n)
{
	char	*ds;
	char	*sr;

	ds = (char*)dst;
	sr = (char*)src;
	while (n--)
	{
		ds[n] = sr[n];
	}
	return (ds);
}

t_list				*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*t;
	void	*c;

	if (!(t = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	t->next = NULL;
	if (!content)
	{
		t->content_size = 0;
		t->content = NULL;
	}
	else
	{
		c = memalloc(content_size);
		memcpy2(c, content, content_size);
		t->content_size = content_size;
		t->content = c;
	}
	return (t);
}
