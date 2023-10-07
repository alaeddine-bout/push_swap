/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: about <about@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:47:47 by about             #+#    #+#             */
/*   Updated: 2023/03/30 17:46:32 by about            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	write(1, "sa\n", 3);
}

void	pa(t_list **stack_b, t_list **stack_a)
{
	t_list	*temp;

	if (!*stack_b)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	add_front(stack_a, temp);
	write(1, "pa\n", 3);
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
	write(1, "ra\n", 3);
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
	write(1, "rra\n", 4);
}
