/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:08:43 by picatrai          #+#    #+#             */
/*   Updated: 2023/12/16 16:38:54 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_list *pile, int index_max)
{
	int	tempo;

	tempo = pile[index_max].value;
	while (index_max - 1 >= 0)
	{
		pile[index_max].value = pile[index_max - 1].value;
		index_max--;
	}
	pile[0].value = tempo;
}

void	ft_ra(t_list *pile, int write)
{
	ft_rotate(pile, ft_index_max(pile));
	if (write)
		ft_putstr("ra\n");
}

void	ft_rb(t_list *pile, int write)
{
	ft_rotate(pile, ft_index_max(pile));
	if (write)
		ft_putstr("rb\n");
}

void	ft_rr(t_list *pile_1, t_list *pile_2, int write)
{
	ft_rotate(pile_1, ft_index_max(pile_1));
	ft_rotate(pile_2, ft_index_max(pile_2));
	if (write)
		ft_putstr("rr\n");
}
