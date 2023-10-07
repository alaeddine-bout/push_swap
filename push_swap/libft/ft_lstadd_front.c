/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: about <about@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 00:40:15 by about             #+#    #+#             */
/*   Updated: 2023/03/30 17:45:34 by about            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	add_front(t_list **head, t_list *ptr)
{
	if (!ptr)
		return ;
	if (!head)
	{
		*head = ptr;
		return ;
	}
	ptr->next = *head;
	*head = ptr;
}
