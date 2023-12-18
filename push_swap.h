/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:33:49 by picatrai          #+#    #+#             */
/*   Updated: 2023/12/16 16:28:04 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	long	value;
	int		cost;
	int		last;
}	t_list;

int		ft_index_max(t_list *pile);
void	ft_putstr(char *str);
int		ft_strlen_2d(char **str);

void	ft_sa(t_list *pile, int write);
void	ft_sb(t_list *pile, int write);
void	ft_ss(t_list *pile_1, t_list *pile_2, int write);

void	ft_pa(t_list *pile_1, t_list *pile_2, int write);
void	ft_pb(t_list *pile_1, t_list *pile_2, int write);

void	ft_ra(t_list *pile, int write);
void	ft_rb(t_list *pile, int write);
void	ft_rr(t_list *pile_1, t_list *pile_2, int write);

void	ft_rra(t_list *pile, int write);
void	ft_rrb(t_list *pile, int write);
void	ft_rrr(t_list *pile_1, t_list *pile_2, int write);

void	ft_up_b(t_list *pile_b, int pick);
void	ft_down_b(t_list *pile_b, int pick);
void	ft_up_a(t_list *pile_a, int j);
void	ft_down_a(t_list *pile_a, int j);
void	ft_double_up(t_list *pile_a, t_list *pile_b, int n);
void	ft_double_down(t_list *pile_a, t_list *pile_b, int n);

int		ft_min(t_list *pile_a);
int		ft_max(t_list *pile_a);
int		ft_place(t_list *pile_a, t_list *pile_b, int i);
int		ft_choix_opti(t_list *pile_b);
void	ft_transfer(t_list *pile_a, t_list *pile_b);

void	ft_calcul_cout(t_list *pile_a, t_list *pile_b);
int		c_sep(t_list *pile_a, t_list *pile_b, int i, int j);
int		c_rota(t_list *pile_a, t_list *pile_b, int i, int j);
int		c_rev_rota(int i, int j);

int		ordre(t_list *pile_a);
t_list	*ft_parsing(char **arg, int limit);
int		ft_check_double(t_list *pile_a);
char	**ft_split(char *str, char c);

void	ft_alg(t_list *pile_a, t_list *pile_b);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
int		ft_check_line(char *stockage);
char	*ft_clean(char *stockage, int i, int j);
char	*ft_cut(char *stockage);
int		is_sort(t_list *pile_a);

#endif
