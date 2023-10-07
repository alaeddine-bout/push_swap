/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: about <about@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 21:44:01 by about             #+#    #+#             */
/*   Updated: 2023/03/31 23:47:32 by about            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	lstfree(t_list **stack)
{
	t_list	*tmp;

	if (stack == NULL || *stack == NULL)
		return ;
	tmp = (*stack)->next;
	while (tmp != NULL && (*stack) != NULL)
	{
		free(*stack);
		(*stack) = tmp;
		tmp = (*stack)->next;
	}
}

void	check_digi(char *num, t_list *stack_a, char **str)
{
	int	i;

	i = 0;
	if (num[i] == '-' || num[i] == '+')
		i++;
	if (i && !num[i])
	{
		lstfree(&stack_a);
		ft_free(str);
		ft_error();
	}
	while (num[i])
	{
		if (ft_isdigit(num[i]) == 0)
		{
			lstfree(&stack_a);
			ft_free(str);
			ft_error();
		}
		i++;
	}
}

void	checkdup2(int size, int *arr)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] == arr[i + 1])
		{
			ft_error();
		}
		i++;
	}
}

t_list	*initialisation2(int size, char **number, t_list **stack_a)
{
	char	**str;
	int		i;

	i = 0;
	if (size >= 2)
	{
		while (size > 1)
		{
			str = ft_split(number[size - 1], ' ');
			while (str[i])
				i++;
			if (i == 0)
				ft_error();
			while (i > 0)
			{
				check_digi(str[i - 1], *stack_a, str);
				add_front(stack_a, ft_lstnew(ft_atoi(str[(i--) - 1])));
			}
			ft_free(str);
			size--;
		}
	}
	return (*stack_a);
}
