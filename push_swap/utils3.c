/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: about <about@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:05:43 by about             #+#    #+#             */
/*   Updated: 2023/04/04 20:02:59 by about            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	condition1(t_list **stack_a, int content)
{
	if (content <= ft_lstsize(*stack_a) / 2)
	{
		while (content > 0)
		{
			ra(stack_a);
			content--;
		}
	}
}

void	condition2(t_list **stack_a, int content)
{
	if (content > ft_lstsize(*stack_a) / 2)
	{
		while (content < ft_lstsize(*stack_a))
		{
			rra(stack_a);
			content++;
		}
	}
}

void	condition(t_list **stack_a, t_list **stack_b, int content, t_data data)
{
	condition1(stack_a, content);
	condition2(stack_a, content);
	pb(stack_a, stack_b);
	if ((*stack_b)->content < data.arr[data.middle])
		rb(stack_b);
}

int	checking(t_list *stack_a)
{
	t_list	*tmp;

	tmp = stack_a;
	while (tmp)
	{
		if (tmp->next && tmp->content > tmp->next->content)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
