/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: about <about@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 02:15:24 by about             #+#    #+#             */
/*   Updated: 2023/03/29 21:08:24 by about            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_arr(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	*full_arr(t_list *stack_a, int size)
{
	int	i;
	int	*arr;

	i = 0;
	arr = malloc(size * sizeof(int));
	if (!arr)
		return (0);
	while (stack_a)
	{
		arr[i] = stack_a->content;
		stack_a = stack_a->next;
		i++;
	}
	sort_arr(arr, size);
	return (arr);
}

int	indexstack(t_list *stack_x, int content)
{
	int	i;

	i = 0;
	while (stack_x && stack_x->content != content)
	{
		stack_x = stack_x->next;
		i++;
	}
	return (i);
}
