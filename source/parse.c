/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 19:26:17 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/04 18:26:35 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(t_clst **a)
{
	ft_clst_free(a);
	ft_putstr_fd("Error\n", 2);
	return (0);
}

int	ft_valid(char *str, int *nbr)
{
	*nbr = ft_atoi(str);
	return (1);
}

int	parse(int argc, char **argv, t_clst **a)
{
	int	i;
	int nbr;
	t_clst	*new;

	i = 0;
	if (argc == 1)
		return (0);
	while (++i < argc)
	{
		if (ft_valid(argv[argc], &nbr))
		{
			new = ft_clst_new(nbr);
			if (!new)
			{
				ft_error(a);
				return (0);
			}
			ft_clst_add(a, new);
		}
		else
		{
			ft_error(a);
			return (0);
		}
	}
	return (1);
}