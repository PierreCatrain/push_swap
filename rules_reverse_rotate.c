/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 07:34:45 by picatrai          #+#    #+#             */
/*   Updated: 2023/12/16 16:38:25 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_list *pile, int index_max)
{
	int	tempo;
	int	i;

	i = 0;
	tempo = pile[0].value;
	while (i + 1 <= index_max)
	{
		pile[i].value = pile[i + 1].value;
		i++;
	}
	pile[index_max].value = tempo;
}

void	ft_rra(t_list *pile, int write)
{
	ft_reverse_rotate(pile, ft_index_max(pile));
	if (write)
		ft_putstr("rra\n");
}

void	ft_rrb(t_list *pile, int write)
{
	ft_reverse_rotate(pile, ft_index_max(pile));
	if (write)
		ft_putstr("rrb\n");
}

void	ft_rrr(t_list *pile_1, t_list *pile_2, int write)
{
	ft_reverse_rotate(pile_1, ft_index_max(pile_1));
	ft_reverse_rotate(pile_2, ft_index_max(pile_2));
	if (write)
		ft_putstr("rrr\n");
}
