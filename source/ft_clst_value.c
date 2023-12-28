/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clst_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:27:06 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/28 17:28:46 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_clst_value(t_clst *lst, int i)
{
	if (i >= 0)
	{
		while (--i)
			lst = lst->next;
		return (lst->nbr);
	}
	else
	{
		while (++i)
			lst = lst->prev;
		return (lst->nbr);
	}
}
