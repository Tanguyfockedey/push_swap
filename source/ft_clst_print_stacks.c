/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clst_print_stacks.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:31:21 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/26 15:35:31 by tafocked         ###   ########.fr       */
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

void	ft_clst_print_stacks(t_stacks *ab)
{
	ft_printf("A (%d) : ", ab->size_a);
	ft_clst_print(ab->a);
	ft_printf("\nB (%d) : ", ab->size_b);
	ft_clst_print(ab->b);
	ft_printf("\n\n");
}
