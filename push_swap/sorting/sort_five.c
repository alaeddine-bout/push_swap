/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: about <about@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 02:35:20 by about             #+#    #+#             */
/*   Updated: 2023/03/30 17:27:53 by about            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	putup(t_list **stack_a, t_list **stack_b, int size, int content)
{
	int	mid;
	int	index;

	mid = size / 2;
	index = indexstack(*stack_a, content);
	while ((*stack_a)->content != content)
	{
		if (index < mid)
			ra(stack_a);
		else
			rra(stack_a);
	}
	pb(stack_a, stack_b);
}

void	sort5(t_list **stack_a, t_list **stack_b, int size, int *arr)
{
	int	i;

	i = 0;
	while (ft_lstsize(*stack_a) != 3)
	{
		putup(stack_a, stack_b, size, arr[i]);
		i++;
		size--;
	}
	if (size == 3)
		sort3(stack_a);
	while (*stack_b)
		pa(stack_b, stack_a);
}
