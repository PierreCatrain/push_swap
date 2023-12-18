/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcul_cout.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:01:03 by picatrai          #+#    #+#             */
/*   Updated: 2023/11/25 14:26:56 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	c_sep(t_list *pile_a, t_list *pile_b, int i, int j)
{
	int	cout_b;
	int	cout_a;

	if (ft_index_max(pile_b) - i <= i + 1)
		cout_b = ft_index_max(pile_b) - i;
	else
		cout_b = i + 1;
	if (ft_index_max(pile_a) - j <= j + 1)
		cout_a = ft_index_max(pile_a) - j;
	else
		cout_a = j + 1;
	return (cout_b + cout_a + 1);
}

int	c_rota(t_list *pile_a, t_list *pile_b, int i, int j)
{
	int	cout;

	cout = 0;
	if (ft_index_max(pile_b) - i >= ft_index_max(pile_a) - j)
		cout = ft_index_max(pile_b) - i + 1;
	else
		cout = ft_index_max(pile_a) - j + 1;
	return (cout);
}

int	c_rev_rota(int i, int j)
{
	int	cout;

	cout = 0;
	if (i + 1 >= j + 1)
		cout = i + 2;
	else
		cout = j + 2;
	return (cout);
}

int	ft_cout(int sep, int rota, int rev_rota)
{
	if (sep <= rota && sep <= rev_rota)
		return (sep);
	else if (rota <= sep && rota <= rev_rota)
		return (rota);
	else
		return (rev_rota);
}

void	ft_calcul_cout(t_list *pile_a, t_list *pile_b)
{
	int	i;
	int	j;

	i = 0;
	while (i <= ft_index_max(pile_b))
	{
		j = ft_place(pile_a, pile_b, i);
		pile_b[i].cost = ft_cout(c_sep(pile_a, pile_b, i, j), \
		c_rota(pile_a, pile_b, i, j), c_rev_rota(i, j));
		i++;
	}
}
