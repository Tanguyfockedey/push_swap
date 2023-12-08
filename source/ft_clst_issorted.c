/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clst_issorted.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:34:17 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/08 18:01:21 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_clst_issorted(t_clst **lst)
{
	t_clst	*tmp;
	char	flag;

	if ((*lst)->next == *lst)
		return (1);
	flag = 1;
	tmp = *lst;
	while (tmp != (*lst)->prev || flag)
	{
		if (tmp->nbr > tmp->next->nbr)
			return (0);
		flag = 0;
		tmp = tmp->next;
	}
	return (1);
}
