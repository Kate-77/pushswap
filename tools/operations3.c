/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:03:00 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/05/17 11:05:49 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int	duplicate(t_list *stack)
{
	t_list	*head;

	while (stack != NULL)
	{
		head = stack->next;
		while (head != NULL)
		{
			if (stack->content == head->content)
				return (1);
			head = head->next;
		}
		stack = stack->next;
	}
	return (0);
}
