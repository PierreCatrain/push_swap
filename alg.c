/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:17:42 by picatrai          #+#    #+#             */
/*   Updated: 2023/12/16 16:50:13 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_mini_tri(t_list *pile_a)
{
	if (ft_index_max(pile_a) == 1)
		return (ft_ra(pile_a, 1));
	else if (pile_a[1].value > pile_a[0].value \
			&& pile_a[0].value > pile_a[2].value)
		return (ft_rra(pile_a, 1), ft_sa(pile_a, 1));
	else if (pile_a[1].value > pile_a[2].value \
			&& pile_a[2].value > pile_a[0].value)
		return (ft_rra(pile_a, 1));
	else if (pile_a[0].value > pile_a[2].value \
			&& pile_a[2].value > pile_a[1].value)
		return (ft_sa(pile_a, 1));
	else if (pile_a[2].value > pile_a[0].value \
			&& pile_a[0].value > pile_a[1].value)
		return (ft_ra(pile_a, 1));
	else if (pile_a[2].value > pile_a[1].value \
			&& pile_a[1].value > pile_a[0].value)
		return (ft_sa(pile_a, 1), ft_rra(pile_a, 1));
}

void	ft_split_b_2(t_list *pile_a, t_list *pile_b, int i, int index)
{
	int	border_min;
	int	min;
	int	max;

	min = ft_min(pile_a);
	max = ft_max(pile_a);
	border_min = min;
	while (i >= 0)
	{
		if (pile_a[index].value != max && pile_a[index].value != min \
		&& pile_a[index].value < border_min)
		{
			ft_pb(pile_b, pile_a, 1);
			index--;
		}
		else
		{
			border_min = pile_a[index].value;
			ft_ra(pile_a, 1);
		}
		i--;
	}
}

void	ft_split_b(t_list *pile_a, t_list *pile_b)
{
	int	i;
	int	index;
	int	min;
	int	max;

	min = ft_min(pile_a);
	max = ft_max(pile_a);
	index = ft_index_max(pile_a);
	i = index;
	while (i >= 0 && pile_a[index].value != min)
	{
		if (pile_a[index].value != max && pile_a[index].value != min)
		{
			ft_pb(pile_b, pile_a, 1);
			index--;
		}
		else
			ft_ra(pile_a, 1);
		i--;
	}
	ft_split_b_2(pile_a, pile_b, i, index);
}

void	ft_decalage(t_list *pile_a)
{
	int	min;
	int	index;
	int	i;

	min = ft_min(pile_a);
	i = 0;
	while (i <= ft_index_max(pile_a))
	{
		if (pile_a[i].value == min)
			index = i;
		i++;
	}
	if (ft_index_max(pile_a) - index <= index + 1)
		ft_up_a(pile_a, index);
	else
		ft_down_a(pile_a, index);
}

void	ft_alg(t_list *pile_a, t_list *pile_b)
{
	if (ft_index_max(pile_a) <= 2)
		return (ft_mini_tri(pile_a));
	else if (ft_index_max(pile_a) <= 4)
	{
		ft_pb(pile_b, pile_a, 1);
		ft_pb(pile_b, pile_a, 1);
		ft_mini_tri(pile_a);
	}
	else
		ft_split_b(pile_a, pile_b);
	ft_transfer(pile_a, pile_b);
	ft_decalage(pile_a);
}
