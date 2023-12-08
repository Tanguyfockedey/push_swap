/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:27:56 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/08 17:54:06 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_overflow(char *str)
{
	int	i;
	int	overflow;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] == '0')
		i++;
	overflow = ft_strlen(&str[i]);
	if (overflow < 10)
		return (0);
	if (overflow > 10)
		return (1);
	if (str[i] > '2' || str[i + 1] > '1' || str[i + 2] > '4'
		|| str[i + 3] > '7' || str[i + 4] > '4' || str[i + 5] > '8'
		|| str[i + 6] > '3' || str[i + 7] > '6' || str[i + 8] > '4'
		|| (str[0] != '-' && str[i + 9] > '7')
		|| (str[0] == '-' && str[i + 9] > '8'))
		return (1);
	return (0);
}

int	ft_int_arg(char *str, int *nbr)
{
	int	i;

	i = -1;
	if (!ft_isdigit(str[0]) && str[0] != '+' && str[0] != '-')
		return (0);
	if (str[0] == '+' || str[0] == '-')
	{
		i++;
		if (!str[1])
			return (0);
	}
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	if (ft_overflow(str))
		return (0);
	*nbr = ft_atoi(str);
	return (1);
}
