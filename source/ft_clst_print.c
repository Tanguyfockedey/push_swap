/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clst_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:31:21 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/13 17:39:17 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_clst_print(t_clst **lst)
{
	t_clst	*tmp;

	if (!lst || !(*lst))
		return ;
	tmp = *lst;
	ft_printf("%d  ", tmp->nbr);
	while (tmp->next != *lst)
	{
		tmp = tmp->next;
		ft_printf("%d  ", tmp->nbr);
	}
}

void	ft_clst_print_ab(t_clst **a, t_clst **b)
{
	ft_printf("A: ");
	ft_clst_print(a);
	ft_printf("\nB: ");
	ft_clst_print(b);
	ft_printf("\n\n");
}
