/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 19:19:20 by houssana          #+#    #+#             */
/*   Updated: 2017/04/20 11:47:22 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*l;
	t_list	*r;
	t_list	*d;

	l = NULL;
	r = NULL;
	d = NULL;
	while (lst)
	{
		if (!(r = (t_list*)malloc(sizeof(t_list))))
			return (NULL);
		r = f(lst);
		if (!d)
			d = r;
		if (l)
			l->next = r;
		l = r;
		lst = lst->next;
	}
	return (d);
}
