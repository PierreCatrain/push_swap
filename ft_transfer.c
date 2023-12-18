/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transfer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:50:05 by picatrai          #+#    #+#             */
/*   Updated: 2023/12/15 11:17:40 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_transfer_rota(t_list *pile_a, t_list *pile_b, int pick, int j)
{
	if (ft_index_max(pile_b) - pick >= ft_index_max(pile_a) - j)
	{
		ft_double_up(pile_a, pile_b, j);
		ft_up_b(pile_b, pick + ft_index_max(pile_a) - j);
	}
	else
	{
		ft_double_up(pile_b, pile_a, pick);
		ft_up_a(pile_a, j + ft_index_max(pile_b) - pick);
	}
}

void	ft_transfer_rev_rota(t_list *pile_a, t_list *pile_b, int pick, int j)
{
	if (pick + 1 >= j + 1)
	{
		ft_double_down(pile_a, pile_b, j);
		ft_down_b(pile_b, pick - (j + 1));
	}
	else
	{
		ft_double_down(pile_a, pile_b, pick);
		ft_down_a(pile_a, j - (pick + 1));
	}
}

void	ft_transfer_sep(t_list *pile_a, t_list *pile_b, int pick, int j)
{
	if (ft_index_max(pile_b) - pick <= pick + 1)
		ft_up_b(pile_b, pick);
	else
		ft_down_b(pile_b, pick);
	if (ft_index_max(pile_a) - j <= j + 1)
		ft_up_a(pile_a, j);
	else
		ft_down_a(pile_a, j);
}

void	ft_transfer(t_list *pile_a, t_list *pile_b)
{
	int	pick;
	int	j;

	while (ft_index_max(pile_b) != -1)
	{
		ft_calcul_cout(pile_a, pile_b);
		pick = ft_choix_opti(pile_b);
		j = ft_place(pile_a, pile_b, pick);
		if (c_rota(pile_a, pile_b, pick, j) <= c_sep(pile_a, pile_b, pick, j) \
		&& c_rota(pile_a, pile_b, pick, j) <= c_rev_rota(pick, j))
			ft_transfer_rota(pile_a, pile_b, pick, j);
		else if (c_rev_rota(pick, j) <= c_sep(pile_a, pile_b, pick, j) \
		&& c_rev_rota(pick, j) <= c_rota(pile_a, pile_b, pick, j))
			ft_transfer_rev_rota(pile_a, pile_b, pick, j);
		else
			ft_transfer_sep(pile_a, pile_b, pick, j);
		ft_pa(pile_a, pile_b, 1);
	}
}
