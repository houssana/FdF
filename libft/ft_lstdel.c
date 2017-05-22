/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 18:57:24 by houssana          #+#    #+#             */
/*   Updated: 2017/04/18 16:29:06 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

void				ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*n;
	t_list	*a;

	if (!alst)
		return ;
	a = (*alst);
	while (a)
	{
		del(a->content, a->content_size);
		n = a->next;
		free(a);
		a = n;
	}
	*alst = NULL;
}
