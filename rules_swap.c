/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:47:26 by picatrai          #+#    #+#             */
/*   Updated: 2023/12/16 16:39:21 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list *pile, int index_max)
{
	int	tempo;

	if (index_max <= 0)
		return ;
	tempo = pile[index_max].value;
	pile[index_max].value = pile[index_max - 1].value;
	pile[index_max - 1].value = tempo;
}

void	ft_sa(t_list *pile, int write)
{
	ft_swap(pile, ft_index_max(pile));
	if (write)
		ft_putstr("sa\n");
}

void	ft_sb(t_list *pile, int write)
{
	ft_swap(pile, ft_index_max(pile));
	if (write)
		ft_putstr("sb\n");
}

void	ft_ss(t_list *pile_1, t_list *pile_2, int write)
{
	ft_swap(pile_1, ft_index_max(pile_1));
	ft_swap(pile_2, ft_index_max(pile_2));
	if (write)
		ft_putstr("ss\n");
}
