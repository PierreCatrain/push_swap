/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:39:35 by picatrai          #+#    #+#             */
/*   Updated: 2023/12/16 18:44:28 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

int	ft_check_double(t_list *pile_a)
{
	int	i;
	int	j;
	int	max;

	max = ft_index_max(pile_a);
	i = 0;
	while (i < max)
	{
		j = i + 1;
		while (j <= max)
		{
			if (pile_a[i].value == pile_a[j].value)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static long	ft_atoi(char *str)
{
	long	resultat;
	int		i;
	int		signe;

	i = 0;
	resultat = 0;
	signe = 1;
	if (str[i] == '-')
	{
		signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		resultat *= 10;
		resultat += str[i] - '0';
		i++;
	}
	if (str[i] != '\0' || resultat > 2147483647 || resultat < -2147483648)
		return (3000000000);
	return (resultat * signe);
}

t_list	*ft_parsing(char **arg, int limit)
{
	t_list	*pile_a;
	int		index;
	int		i;

	index = ft_strlen_2d(arg) - 1;
	i = 0;
	pile_a = malloc((ft_strlen_2d(arg) - limit) * sizeof(t_list));
	if (pile_a == NULL)
		return (NULL);
	while (index >= limit)
	{
		pile_a[i].value = ft_atoi(arg[index--]);
		if (pile_a[i].value == 3000000000)
		{
			write(2, "Error\n", 6);
			if (limit == 0)
				ft_free(arg);
			return (free(pile_a), NULL);
		}
		pile_a[i].last = 0;
		i++;
	}
	if (limit == 0)
		ft_free(arg);
	return (pile_a[i - 1].last = 1, pile_a);
}

int	ordre(t_list *pile_a)
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
