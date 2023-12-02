/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:12:47 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/02 21:05:34 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
 #define PUSH_SWAP_H

# include "../includes/libft_updated/libft/libft.h"
# include "../includes/libft_updated/printf/ft_printf.h"

typedef struct s_clst
{
	struct t_clst	*next;
	struct t_clst	*prev;
	long			nbr;
	long			index;
}	t_clst;

t_clst	*ft_clstnew(int nbr);
void	ft_clstadd(t_clst **a, t_clst *new);


#endif