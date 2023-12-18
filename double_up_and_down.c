/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_up_and_down.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:31:43 by picatrai          #+#    #+#             */
/*   Updated: 2023/12/15 11:20:10 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_double_up(t_list *pile_1, t_list *pile_2, int n)
{
	while (n < ft_index_max(pile_1))
	{
		ft_rr(pile_1, pile_2, 1);
		n++;
	}
}

void	ft_double_down(t_list *pile_a, t_list *pile_b, int n)
{
	while (n >= 0)
	{
		ft_rrr(pile_a, pile_b, 1);
		n--;
	}
}
