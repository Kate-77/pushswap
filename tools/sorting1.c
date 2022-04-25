/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 04:38:27 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/04/23 05:49:57 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"
#include <stdio.h>

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

int	find_max(t_list *stack)
{
	int	max;

	max = stack->content;
	while (stack->next != NULL)
	{
		if (max < stack->next->content)
			max = stack->next->content;
		stack = stack->next;
	}
	return (max);
}

void	sort_three(t_list **stack_a, t_list **stack_b)
{
	int	max;

	max = find_max(*stack_a);
	if ((*stack_a)->content == max)
		rotate(stack_a, 1);
	else if ((*stack_a)->next->content == max)
	{
		swap(stack_a, stack_b, 1);
		rotate(stack_a, 1);
	}
	if ((*stack_a)->content > (*stack_a)->next->content)
		swap(stack_a, stack_b, 1);
	return ;
}
