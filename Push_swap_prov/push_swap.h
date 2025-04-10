/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdier <jverdier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:02:46 by jverdier          #+#    #+#             */
/*   Updated: 2024/08/18 15:37:14 by jverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>

# include "ft_printf.h"
# include "libft.h"

# define INT_MAX "2147483647"
# define INT_MIN "-2147483648"

typedef struct s_lst
{
	int				content;
	int				push_cost;
	struct s_lst	*next;
	struct s_lst	*before;
}						t_lst;

/*main.c*/
int		*create_tab(t_lst **begin_list_a);
int		distribution(t_lst **begin_list_a, t_lst **begin_list_b);

/*parsing.c*/
int		is_valid(char *arg);
int		is_double(char **argv);
int		verif_param(char **argv);
int		is_sorted(t_lst *begin_list);

/*cleaning.c*/
int		ft_count(char const *s, char c);
int		finding_args(char **argv, char **args, int i, int l);
char	**cleaning(char **argv);
void	ft_free(char **array);

/*algorithm.c*/
int		is_swap(t_lst *begin_list_a, t_lst *min, t_lst *max);
void	small(t_lst **begin_list_a);
void	medium(t_lst **begin_list_a, t_lst **begin_list_b);
void	large(t_lst **begin_list_a, t_lst **begin_list_b, int *tab, int size);
void	end_sort(t_lst **begin_list_a, t_lst **begin_list_b);

/*search.c*/
t_lst	*search_min(t_lst *begin_list);
t_lst	*search_max(t_lst *begin_list);
t_lst	*srch_closest_bigger(t_lst *begin_list, t_lst *num);
t_lst	*srch_closest_smaller(t_lst *begin_list, t_lst *num);
t_lst	*who_put(t_lst *begin_list);

/*cost.c*/
int		cost(t_lst *begin_list, t_lst *post);
void	put_cost_a(t_lst **begin_list_a, t_lst *begin_list_b);
void	put_cost_b(t_lst *begin_list_a, t_lst **begin_list_b);

/*utils.c*/
int		pos(t_lst *begin_list, int content);
void	put_num_first_a(t_lst **begin_list, t_lst *num);
void	put_num_first_b(t_lst **begin_list, t_lst *num);
void	put_num_first(t_lst **b_a, t_lst **b_b, t_lst *numa, t_lst *numb);
void	bubble(int *tab, int size);

/*utils_list2.c*/
void	printlst(t_lst **begin_list_a);
t_lst	**create_list(char **argv);
void	lstclear(t_lst **lst);

/*utils_list.c*/
void	lstadd_front(t_lst **lst, t_lst *new);
void	lstadd_back(t_lst **lst, t_lst *new);
t_lst	*lstnew(int content);
int		lstsize(t_lst *lst);
t_lst	*lstlast(t_lst *lst);

/*s_.c*/
void	swap(int *a, int *b);
void	sa(t_lst **begin_list);
void	sb(t_lst **begin_list);
void	ss(t_lst **begin_list_a, t_lst **begin_list_b);

/*r_.c*/
void	ra(t_lst **begin_list);
void	rb(t_lst **begin_list);
void	rr(t_lst **begin_list_a, t_lst **begin_list_b);

/*rr_.c*/
void	rra(t_lst **begin_list);
void	rrb(t_lst **begin_list);
void	rrr(t_lst **begin_list_a, t_lst **begin_list_b);

/*p_.c*/
void	pa(t_lst **begin_list_a, t_lst **begin_list_b);
void	pb(t_lst **begin_list_a, t_lst **begin_list_b);

#endif
