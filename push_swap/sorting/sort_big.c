/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: about <about@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:50:40 by about             #+#    #+#             */
/*   Updated: 2023/03/29 20:17:29 by about            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	search(t_list **stack_a, int *arr, int start, int end)
{
	t_list	*tmp;
	int		i;

	tmp = (*stack_a);
	i = 0;
	while (tmp)
	{
		if (tmp->content >= arr[start] && tmp->content <= arr[end])
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	fillthis(t_list **stack_a, int *n, int *middle, int *offset)
{
	*middle = ft_lstsize(*stack_a) / 2;
	*n = checkn(stack_a);
	*offset = ft_lstsize(*stack_a) / *n;
}

int	checkn(t_list **stack_a)
{
	int	n;

	if (ft_lstsize(*stack_a) <= 10)
		n = 5;
	else if (ft_lstsize(*stack_a) <= 150)
		n = 8;
	else
		n = 18;
	return (n);
}

void	updatestartend(int *start, int *end, int middle, int offset)
{
	*start -= offset;
	*end += offset;
	if (*start < 0)
		*start = 0;
	if (*end > middle * 2 - 1)
		*end = middle * 2 - 1;
}

void	sortbig(t_list **stack_a, t_list **stack_b, int *arr)
{
	int		n;
	int		offset;
	int		start;
	int		end;
	t_data	data;

	fillthis(stack_a, &n, &data.middle, &offset);
	data.arr = arr;
	start = data.middle - offset;
	end = data.middle + offset;
	while (*stack_a)
	{
		laststack_a(stack_a, stack_b);
		while (*stack_a)
		{
			n = search(stack_a, data.arr, start, end);
			if (n == ft_lstsize(*stack_a))
			{
				updatestartend(&start, &end, data.middle, offset);
				break ;
			}
			condition(stack_a, stack_b, n, data);
		}
	}
	backtostack_a(stack_a, stack_b, data.arr);
}
