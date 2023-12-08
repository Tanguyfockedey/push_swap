/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 19:26:17 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/08 15:41:28 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_tab_free(char **argv)
{
	int	i;

	i = -1;
	while (argv[++i])
		free(argv[i]);
	free(argv);
}

int	ft_error(t_clst **a, int argc, char **argv)
{
	if (argc == 2)
		ft_tab_free(argv);
	ft_clst_free(a);
	ft_putstr_fd("Error\n", 2);
	return (0);
}

char	**ft_tab(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv)
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
	}
	else
		argv = &argv[1];
	return (argv);
}

int	ft_valid(char *str, int *nbr)
{
	*nbr = ft_atoi(str);
	return (1);
}

int ft_fill_a(char **argv, t_clst **a)
{
	int		i;
	int		nbr;
	t_clst	*new;

	i = -1;
	while (argv[++i])
	{
		if (ft_int_arg(argv[i], &nbr))
		{
			new = ft_clst_new(nbr);
			if (!new)
				return (0);
			ft_clst_add(a, new);
		}
		else
			return (0);
	}
	return (1);
}

int	ft_check_dup(t_clst **a)
{
	t_clst	*tmp_i;
	t_clst	*tmp_j;
	char	flag;

	if ((*a)->next == *a)
		return (1);
	flag = 1;
	tmp_i = *a;
	while (tmp_i != *a || flag)
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

int	ft_parse(int argc, char **argv, t_clst **a)
{
	argv = ft_tab(argc, argv);
	if (!argv)
		return (0);
	if (!ft_fill_a(argv, a))
	{
		ft_error(a, argc, argv);
		return (0);
	}
	if (!ft_check_dup(a))
	{
		ft_error(a, argc, argv);
		return (0);
	}
	if (argc == 2)
		ft_tab_free(argv);
	return (1);
}
