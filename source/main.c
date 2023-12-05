/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:14:38 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/05 17:24:29 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int	main(int argc, char **argv)
{
	t_clst	**a;
	t_clst	*b;
//	t_clst	*c;


	b = 0;
	a = &b;
//	c = ft_clst_new(10);
//	ft_clst_add(a, c);
//	c = ft_clst_new(20);
//	ft_clst_add(a, c);
//	c = ft_clst_new(30);
//	ft_clst_add(a, c);

	if (!ft_parse(argc, argv, a))
		return (1);

	ft_clst_print(a);
	ft_printf("clist size = %d\n", ft_clst_size(a));
	ft_clst_free(a);
	return (0);
}
