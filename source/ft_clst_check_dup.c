/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clst_check_dup.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:26:38 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/08 17:37:05 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_clst_check_dup(t_clst **lst)
{
	t_clst	*tmp_i;
	t_clst	*tmp_j;
	char	flag;

	if ((*lst)->next == *lst)
		return (1);
	flag = 1;
	tmp_i = *lst;
	while (tmp_i != *lst || flag)
	{
		tmp_j = tmp_i->next;
		while (tmp_j != tmp_i->prev)
		{
			if (tmp_i->nbr == tmp_j->nbr)
				return (0);
			tmp_j = tmp_j->next;
		}
		if (tmp_i->nbr == tmp_j->nbr)
			return (0);
		tmp_i = tmp_i->next;
		flag = 0;
	}
	return (1);
}
