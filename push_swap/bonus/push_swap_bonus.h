/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: about <about@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 20:39:02 by about             #+#    #+#             */
/*   Updated: 2023/04/01 00:12:44 by about            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdio.h>
# include "../libft/libft.h"
# include "get_next_line.h"

typedef struct s_data
{
	int	middle;
	int	*arr;
}	t_data;

void	ft_error(void);
t_list	*initialisation2(int size, char **number, t_list **stack_a);
void	sa(t_list **stack_a);
void	pa(t_list **stack_b, t_list **stack_a);
void	ra(t_list **stack_a);
void	rra(t_list **stack_a);
void	sb(t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	rb(t_list **stack_b);
void	rrb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

#endif