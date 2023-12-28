/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:14:38 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/28 20:38:17 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*ab;
	t_stacks	obj;

	ab = &obj;
	ft_init(ab);
	ft_parse(argc, argv, ab);
//	ft_clst_print_stacks(ab);//
	if (!ft_clst_issorted(ab->a))
		ft_sort_big(ab);
//	ft_clst_print_stacks(ab);//
	ft_clst_free(ab->a);
	return (0);
}
