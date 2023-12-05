/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:27:56 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/05 18:58:21 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_prestr(char *str, char *sign)
{
	size_t	i;

	*sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			*sign *= -1;
	}
	return (&str[i]);
}

int	ft_atoi(const char *string)
{
	char	sign;
	char	*str;
	int		i;
	size_t	unb;
	size_t	mult10;

	i = 0;
	unb = 0;
	mult10 = 1;
	str = ft_prestr((char *)string, &sign);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (i > 0)
	{
		i--;
		unb = unb + (str[i] - '0') * mult10;
		mult10 *= 10;
	}
	return (sign * unb);
}

int	ft_valid_arg(char *str, long *nbr)
{
	int i;
	
	if (!ft_isdigit(str[0]) || str[0] != '+' || str[0] != '-')
		return (0);
	while (str++)
		if (!ft_isdigit(*str))
			retrun (0);
	*nbr = ft_atoi(str);
	return (1);
}
