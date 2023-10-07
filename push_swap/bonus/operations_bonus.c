/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: about <about@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:47:47 by about             #+#    #+#             */
/*   Updated: 2023/03/31 21:42:31 by about            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa(t_list **stack_a)
{
	t_list	*temp;

	if (!*stack_a || (*stack_a)->next == NULL)
		return ;
	if (*stack_a && (*stack_a)->next)
	{
		temp = (*stack_a)->next;
		(*stack_a)->next = temp->next;
		temp->next = *stack_a;
		*stack_a = temp;
	}
}

void	pa(t_list **stack_b, t_list **stack_a)
{
	t_list	*temp;

	if (!*stack_b)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	add_front(stack_a, temp);
}

void	ra(t_list **stack_a)
{
	t_list	*temp;

	if (!*stack_a || (*stack_a)->next == NULL)
		return ;
	temp = *stack_a;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next->next = NULL;
}

void	rra(t_list **stack_a)
{
	t_list	*temp;

	if (!*stack_a || (*stack_a)->next == NULL)
		return ;
	temp = *stack_a;
	while (temp->next->next != NULL)
		temp = temp->next;
	temp->next->next = *stack_a;
	*stack_a = temp->next;
	temp->next = NULL;
}
