/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:14:38 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/13 17:33:23 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int	main(int argc, char **argv)
{
	t_clst	**a;
	t_clst	**b;
	t_clst	*first1;
	t_clst	*first2;
//	t_clst	*c;


	first1 = 0;
	first2 = 0;
	a = &first1;
	b = &first2;
//	c = ft_clst_new(10);
//	ft_clst_add(a, c);
//	c = ft_clst_new(20);
//	ft_clst_add(a, c);
//	c = ft_clst_new(30);
//	ft_clst_add(a, c);

	if (!ft_parse(argc, argv, a))
		return (1);
	
	ft_clst_print_ab(a, b);
	ft_push(a, b);
	ft_push(a, b);
	ft_clst_print_ab(a, b);

	ft_rr(a, b);
	ft_clst_print_ab(a, b);

	ft_ss(a, b);
	ft_clst_print_ab(a, b);
	
	ft_rrotate(a);
	ft_clst_print_ab(a, b);

	ft_push(b, a);
	ft_clst_print_ab(a, b);

	ft_rrotate(a);
	ft_clst_print_ab(a, b);

	ft_push(b, a);
	ft_clst_print_ab(a, b);
	
	ft_rrotate(a);
	ft_clst_print_ab(a, b);

//	ft_printf("clist size = %d\n", ft_clst_size(a));
//	if (ft_clst_issorted(a))
//		ft_printf("list is sorted\n");
//	else
//		ft_printf("list is NOT sorted\n");

	ft_clst_free(a);
	return (0);
}
