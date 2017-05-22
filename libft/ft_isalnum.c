/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 17:21:10 by houssana          #+#    #+#             */
/*   Updated: 2017/04/17 17:35:43 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		st_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

static int		st_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int				ft_isalnum(int c)
{
	return (st_isalpha(c) || st_isdigit(c));
}
