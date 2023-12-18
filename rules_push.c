/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:55:53 by picatrai          #+#    #+#             */
/*   Updated: 2023/12/16 16:37:41 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_list *pile_1, int index_max_1, t_list *pile_2, \
int index_max_2)
{
	if (index_max_2 == -1)
		return ;
	pile_1[index_max_1 + 1].value = pile_2[index_max_2].value;
	if (index_max_1 != -1)
		pile_1[index_max_1].last = 0;
	pile_1[index_max_1 + 1].last = 1;
	pile_2[index_max_2].last = 0;
	if (index_max_2 >= 1)
		pile_2[index_max_2 - 1].last = 1;
	else if (index_max_2 == 0)
		pile_2[index_max_2].last = 2;
}

void	ft_pa(t_list *pile_1, t_list *pile_2, int write)
{
	ft_push(pile_1, ft_index_max(pile_1), pile_2, ft_index_max(pile_2));
	if (write)
		ft_putstr("pa\n");
}

void	ft_pb(t_list *pile_1, t_list *pile_2, int write)
{
	ft_push(pile_1, ft_index_max(pile_1), pile_2, ft_index_max(pile_2));
	if (write)
		ft_putstr("pb\n");
}
