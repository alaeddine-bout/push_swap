/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: about <about@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:01:46 by about             #+#    #+#             */
/*   Updated: 2023/03/31 23:29:01 by about            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include"../push_swap.h"

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\f' || c == '\r' || c == '\v');
}

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned long	result;

	result = 0;
	sign = 1;
	i = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i++] - 48);
		if (result > 2147483647 && sign == 1)
			ft_error();
		if (result > 2147483648 && sign == -1)
			ft_error();
	}
	return (result * sign);
}
