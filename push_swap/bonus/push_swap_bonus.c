/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: about <about@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 20:43:15 by about             #+#    #+#             */
/*   Updated: 2023/04/04 20:18:11 by about            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap_bonus.h"

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

void	checkdup(t_list *stack_a)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = stack_a;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->content == tmp2->content)
				ft_error();
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((unsigned char)s1[i] && (unsigned char)s2[i]
		&& (unsigned char)s1[i] == (unsigned char)s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	conditions(char *arr, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(arr, "sa\n") == 0)
		sa(stack_a);
	else if (ft_strcmp(arr, "ra\n") == 0)
		ra(stack_a);
	else if (ft_strcmp(arr, "rra\n") == 0)
		rra(stack_a);
	else if (ft_strcmp(arr, "pa\n") == 0)
		pa(stack_b, stack_a);
	else if (ft_strcmp(arr, "sb\n") == 0)
		sb(stack_b);
	else if (ft_strcmp(arr, "rb\n") == 0)
		rb(stack_b);
	else if (ft_strcmp(arr, "rrb\n") == 0)
		rrb(stack_b);
	else if (ft_strcmp(arr, "pb\n") == 0)
		pb(stack_a, stack_b);
	else if (ft_strcmp(arr, "ss\n") == 0)
		ss(stack_a, stack_b);
	else if (ft_strcmp(arr, "rr\n") == 0)
		rr(stack_a, stack_b);
	else if (ft_strcmp(arr, "rrr\n") == 0)
		rrr(stack_a, stack_b);
	else
		ft_error();
	free(arr);
}

int	main(int ac, char **av)
{
	char	*arr;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
	stack_a = NULL;
	initialisation2(ac, av, &stack_a);
	checkdup(stack_a);
	if (ac == 1)
		return (0);
	arr = get_next_line(0);
	while (arr)
	{
		conditions(arr, &stack_a, &stack_b);
		arr = get_next_line(0);
	}
	if (checking(stack_a) == 0 && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
