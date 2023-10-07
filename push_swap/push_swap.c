/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: about <about@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:38:56 by about             #+#    #+#             */
/*   Updated: 2023/04/04 20:17:30 by about            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	startsorting(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	*arr;

	size = ft_lstsize(*stack_a);
	arr = full_arr(*stack_a, size);
	checkdup(size, arr);
	if (checking(*stack_a) == 0)
		exit(0);
	if (size == 2)
		sort2(stack_a);
	else if (size == 3)
		sort3(stack_a);
	else if (size == 4 || size == 5)
		sort5(stack_a, stack_b, size, arr);
	else
		sortbig(stack_a, stack_b, arr);
	free(arr);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (ac == 1)
		return (0);
	stack_b = NULL;
	stack_a = NULL;
	initialisation(ac, av, &stack_a);
	startsorting(&stack_a, &stack_b);
}
