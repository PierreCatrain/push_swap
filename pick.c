/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:32:34 by picatrai          #+#    #+#             */
/*   Updated: 2023/11/25 14:09:22 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min(t_list *pile_a)
{
	int	i;
	int	min;

	i = 0;
	min = pile_a[i].value;
	while (i <= ft_index_max(pile_a))
	{
		if (pile_a[i].value < min)
		min = pile_a[i].value;
		i++;
	}
	return (min);
}

int	ft_max(t_list *pile_a)
{
	int	i;
	int	max;

	i = 0;
	max = pile_a[i].value;
	while (i <= ft_index_max(pile_a))
	{
		if (pile_a[i].value > max)
		max = pile_a[i].value;
		i++;
	}
	return (max);
}

int	ft_place(t_list *pile_a, t_list *pile_b, int i)
{
	int	j;
	int	max;
	int	index_max;

	j = ft_index_max(pile_a);
	max = ft_max(pile_a);
	while (j >= 0)
	{
		if (pile_a[j].value > pile_b[i].value && pile_a[j].value <= max)
		{
			max = pile_a[j].value;
			index_max = j;
		}
		j--;
	}
	return (index_max);
}

int	ft_choix_opti(t_list *pile_b)
{
	int	i;
	int	choix;

	i = 0;
	choix = 0;
	while (i <= ft_index_max(pile_b))
	{
		if (pile_b[i].cost < pile_b[choix].cost)
			choix = i;
		i++;
	}
	return (choix);
}
