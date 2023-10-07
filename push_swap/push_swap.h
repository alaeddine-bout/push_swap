/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: about <about@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:39:09 by about             #+#    #+#             */
/*   Updated: 2023/04/01 00:13:00 by about            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct s_data
{
	int	middle;
	int	*arr;
}	t_data;

void	ft_error(void);
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
void	sort2(t_list **stack_a);
void	sort3(t_list **stack_a);
void	sort5(t_list **stack_a, t_list **stack_b, int size, int *arr);
void	sortbig(t_list **stack_a, t_list **stack_b, int *arr);
int		*full_arr(t_list *stack_a, int size);
int		indexstack(t_list *stack_x, int content);
void	putup(t_list **stack_a, t_list **stack_b, int size, int content);
void	backtostack_a(t_list **stack_a, t_list **stack_b, int *arr);
int		checkn(t_list **stack_a);
void	updatestartend(int *start, int *end, int middle, int offset);
void	fillthis(t_list **stack_a, int *n, int *middle, int *offset);
int		search(t_list **stack_a, int *arr, int start, int end);
void	ifup(t_list **stack_a, t_list **stack_b, int *arr, int i);
void	ifdown(t_list **stack_a, t_list **stack_b, int *arr, int i);
void	laststack_a(t_list **stack_a, t_list **stack_b);
void	condition(t_list **stack_a, t_list **stack_b, int content, t_data data);
void	condition1(t_list **stack_a, int content);
void	condition2(t_list **stack_a, int content);
int		checking(t_list *stack_a);
void	lstfree(t_list **stack);
void	ft_free(char **str);
void	check_digi(char *num, t_list *stack_a, char **str);
void	checkdup(int size, int *arr);
t_list	*initialisation(int size, char **number, t_list **stack_a);

#endif