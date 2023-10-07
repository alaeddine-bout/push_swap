/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: about <about@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:48:40 by about             #+#    #+#             */
/*   Updated: 2023/03/30 17:46:06 by about            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sb(t_list **stack_b)
{
	t_list	*temp;

	if (!*stack_b || (*stack_b)->next == NULL)
		return ;
	if (*stack_b && (*stack_b)->next)
	{
		temp = (*stack_b)->next;
		(*stack_b)->next = temp->next;
		temp->next = *stack_b;
		*stack_b = temp;
	}
	write(1, "sb\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (!*stack_a)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	add_front(stack_b, temp);
	write(1, "pb\n", 3);
}

void	rb(t_list **stack_b)
{
	t_list	*temp;

	if (!*stack_b || (*stack_b)->next == NULL)
		return ;
	temp = *stack_b;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next->next = NULL;
	write(1, "rb\n", 3);
}

void	rrb(t_list **stack_b)
{
	t_list	*temp;

	if (!*stack_b || (*stack_b)->next == NULL)
		return ;
	temp = *stack_b;
	while (temp->next->next != NULL)
		temp = temp->next;
	temp->next->next = *stack_b;
	*stack_b = temp->next;
	temp->next = NULL;
	write(1, "rrb\n", 4);
}
