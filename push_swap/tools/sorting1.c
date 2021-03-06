/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 04:38:27 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/05/25 05:26:46 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int	find_min(t_list *stack)
{
	int	min;

	min = stack->content;
	while (stack->next != NULL)
	{
		if (min > stack->next->content)
			min = stack->next->content;
		stack = stack->next;
	}
	return (min);
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

int	ins(int min, t_list **stack_a, t_list **stack_b)
{
	if (min == (*stack_a)->content)
	{
		push(stack_a, stack_b, 1);
		return (1);
	}
	else if (min == (*stack_a)->next->content)
	{
		swap(stack_a, stack_b, 1);
		push(stack_a, stack_b, 1);
		return (1);
	}
	else if (min == (*stack_a)->next->next->content)
	{
		rotate(stack_a, 1);
		rotate(stack_a, 1);
		push(stack_a, stack_b, 1);
		return (1);
	}
	return (0);
}

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	int	min;

	min = find_min(*stack_a);
	while (lst_size(*stack_a) > 3)
	{
		if (ins(min, stack_a, stack_b))
			break ;
		else
		{
			reverse_rotate(stack_a, 1);
			push(stack_a, stack_b, 1);
		}
	}
	sort_three(stack_a, stack_b);
	push(stack_b, stack_a, 2);
	return ;
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int	min;

	min = find_min(*stack_a);
	while (lst_size(*stack_a) > 4)
	{
		if (ins(min, stack_a, stack_b))
			break ;
		else if (min == (*stack_a)->next->next->next->content)
		{
			reverse_rotate(stack_a, 1);
			reverse_rotate(stack_a, 1);
			push(stack_a, stack_b, 1);
		}
		else
		{
			reverse_rotate(stack_a, 1);
			push(stack_a, stack_b, 1);
		}
	}
	sort_four(stack_a, stack_b);
	push(stack_b, stack_a, 2);
	return ;
}
