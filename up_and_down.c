/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_and_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:18:54 by picatrai          #+#    #+#             */
/*   Updated: 2023/12/15 11:32:27 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_up_b(t_list *pile_b, int pick)
{
	while (pick < ft_index_max(pile_b))
	{
		ft_rb(pile_b, 1);
		pick++;
	}
}

void	ft_down_b(t_list *pile_b, int pick)
{
	while (pick >= 0)
	{
		ft_rrb(pile_b, 1);
		pick--;
	}
}

void	ft_up_a(t_list *pile_a, int j)
{
	while (j < ft_index_max(pile_a))
	{
		ft_ra(pile_a, 1);
		j++;
	}
}

void	ft_down_a(t_list *pile_a, int j)
{
	while (j >= 0)
	{
		ft_rra(pile_a, 1);
		j--;
	}
}
