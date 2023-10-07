/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: about <about@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:15:04 by about             #+#    #+#             */
/*   Updated: 2023/04/02 02:11:32 by about            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ifup(t_list **stack_a, t_list **stack_b, int *arr, int i)
{
	if (indexstack(*stack_b, arr[i]) < (i + 1) / 2)
	{
		while ((*stack_b)->content != arr[i])
		{
			if (i >= 1 && (*stack_b)->content == arr[i - 1])
				pa(stack_b, stack_a);
			else
				rb(stack_b);
		}
	}
}

void	ifdown(t_list **stack_a, t_list **stack_b, int *arr, int i)
{
	if (indexstack(*stack_b, arr[i]) >= (i + 1) / 2)
	{
		while ((*stack_b)->content != arr[i])
		{
			if (i > 1 && (*stack_b)->content == arr[i - 1])
				pa(stack_b, stack_a);
			else
				rrb(stack_b);
		}
	}
}

void	laststack_a(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 1)
		pb(stack_a, stack_b);
}

void	backtostack_a(t_list **stack_a, t_list **stack_b, int *arr)
{
	int	i;

	i = ft_lstsize(*stack_b) - 1;
	while (*stack_b)
	{
		ifup(stack_a, stack_b, arr, i);
		ifdown(stack_a, stack_b, arr, i);
		pa(stack_b, stack_a);
		if ((*stack_a)->next
			&& (*stack_a)->content > (*stack_a)->next->content)
		{
			sa(stack_a);
			i--;
		}
		i--;
	}
}
