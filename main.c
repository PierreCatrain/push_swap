/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:22:55 by picatrai          #+#    #+#             */
/*   Updated: 2023/12/16 17:04:19 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (ordre(pile_a) == 1)
		return (free(pile_a), free(pile_b), 0);
	ft_alg(pile_a, pile_b);
	free(pile_b);
	free(pile_a);
	return (0);
}
