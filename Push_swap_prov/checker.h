/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdier <jverdier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:02:46 by jverdier          #+#    #+#             */
/*   Updated: 2024/08/16 14:07:21 by jverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

# define BUFFER 42
# define SA "sa"
# define SB "sb"
# define SS "ss"
# define PA "pa"
# define PB "pb"
# define RA "ra"
# define RB "rb"
# define RR "rr"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"

/*parsing_inst.c*/
int		is_lowercase(int c);
int		is_good(char *inst);
int		is_real_inst(char **array);
char	**inst_renderring(char *inst);
char	**is_all_good(char **argv);

/*sorting.c*/
void	rotate(char	*array, t_lst **begin_list_a, t_lst **begin_list_b);
void	sorting(t_lst **begin_list_a, t_lst **begin_list_b, char **array);

/*reading.c*/
int		ft_len(char *str);
char	*ft_join(char *savings, char *buffer);
char	*ft_reading(int fd, char *savings);

/*utils_bonus.c*/
void	*ft_error(char *buffer, char *savings);

#endif