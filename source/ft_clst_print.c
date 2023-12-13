/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clst_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:31:21 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/13 16:13:35 by tafocked         ###   ########.fr       */
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
//	ft_printf("index = %d\n", tmp->index);
//	ft_printf("addr = %p\n", tmp);
//	ft_printf("next = %p\n", tmp->next);
//	ft_printf("prev = %p\n\n", tmp->prev);
	while (tmp->next != *lst)
	{
		tmp = tmp->next;
		ft_printf("%d  ", tmp->nbr);
//		ft_printf("index = %d\n", tmp->index);
//		ft_printf("addr = %p\n", tmp);
//		ft_printf("next = %p\n", tmp->next);
//		ft_printf("prev = %p\n\n", tmp->prev);
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
