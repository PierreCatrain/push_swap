/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:46:45 by picatrai          #+#    #+#             */
/*   Updated: 2023/12/16 19:07:34 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sort(t_list *pile_a)
{
	int	i;

	i = ft_index_max(pile_a);
	while (i > 0)
	{
		if (pile_a[i].value > pile_a[i - 1].value)
			return (0);
		i--;
	}
	return (1);
}

int	ft_strcomp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i] && (str1[i] == str2[i]))
		i++;
	return (str1[i] - str2[i]);
}

void	ft_comp(char *rules, t_list *pile_a, t_list *pile_b)
{
	if (ft_strcomp(rules, "sa\n") == 0)
		ft_sa(pile_a, 0);
	else if (ft_strcomp(rules, "sb\n") == 0)
		ft_sb(pile_b, 0);
	else if (ft_strcomp(rules, "ss\n") == 0)
		ft_ss(pile_a, pile_b, 0);
	else if (ft_strcomp(rules, "pa\n") == 0)
		ft_pa(pile_a, pile_b, 0);
	else if (ft_strcomp(rules, "pb\n") == 0)
		ft_pb(pile_b, pile_a, 0);
	else if (ft_strcomp(rules, "ra\n") == 0)
		ft_ra(pile_a, 0);
	else if (ft_strcomp(rules, "rb\n") == 0)
		ft_rb(pile_b, 0);
	else if (ft_strcomp(rules, "rr\n") == 0)
		ft_rr(pile_a, pile_b, 0);
	else if (ft_strcomp(rules, "rra\n") == 0)
		ft_rra(pile_a, 0);
	else if (ft_strcomp(rules, "rrb\n") == 0)
		ft_rrb(pile_b, 0);
	else if (ft_strcomp(rules, "rrr\n") == 0)
		ft_rrr(pile_a, pile_b, 0);
}

void	ft_get_rules(t_list *pile_a, t_list *pile_b)
{
	char	*rules;

	while (1)
	{
		rules = get_next_line(0);
		if (rules == NULL)
			return ;
		ft_comp(rules, pile_a, pile_b);
		free(rules);
	}
}

int	main(int argc, char **argv)
{
	t_list	*pile_a;
	t_list	*pile_b;

	if (argc < 2)
		return (0);
	else if (argc == 2)
		pile_a = ft_parsing(ft_split(argv[1], ' '), 0);
	else
		pile_a = ft_parsing(argv, 1);
	if (pile_a == NULL)
		return (0);
	pile_b = malloc((ft_index_max(pile_a) + 1) * sizeof(t_list));
	if (pile_b == NULL)
		return (free(pile_a), 0);
	pile_b[0].last = 2;
	if (ft_check_double(pile_a) == 0)
		return (write(2, "Error\n", 6), free(pile_a), free(pile_b), 0);
	ft_get_rules(pile_a, pile_b);
	if (is_sort(pile_a) == 1)
		write(1, "OK\n", 3);
	else if (is_sort(pile_a) == 0)
		write(1, "KO\n", 3);
	free(pile_b);
	free(pile_a);
	return (0);
}
