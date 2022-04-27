/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 06:51:05 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/04/27 02:11:28 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"
#include <stdio.h>

int	*create_array(t_list *stack, int *arr)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		arr[i] = stack->content;
		stack = stack->next;
		i++;
	}
	return (arr);
}

void	swap_arr(int *arr, int i, int j)
{
	int	tmp;

	tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
	return ;
}

int	array_size(int *arr)
{
	int	i;

	i = 1;
	while (arr[i])
		i++;
	return (i);
}

void	sort_arr(int *arr, t_list *stack)
{
	int	i;
	int	j;
	(void)stack;

	i = 0;
	while (stack != NULL)
	{
		j = i + 1;
		while (stack !=NULL)
		{
			if (arr[j] < arr[i])
				swap_arr(arr, i, j);
			j++;
		}
		i++;
	}
	return ;
}
/*
int	find_min(t_list *stack)
{
	int	min;
	int	i;

	min = stack->content;
	while (stack->next != NULL)
	{
		if (min > stack->next->content)
			min = stack->next->content;
		stack = stack->next;
	}
	i = 0;
	while (stack != NULL)
	{
		if (stack->content == min)
			return (i);
		i++;
		stack = stack->next;
	}
	return (i);
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int	min_index;
	int	min_fixed;

	min_fixed = find_min(*stack_a);
	while ((*stack_a)->content != min_fixed)
	{
		min_index = find_min(*stack_a);
		if (i == 0)
		{
			(*stack_a) = (*stack_a)->next;
			push(stack_a, stack_b, 1);
		}
		else if (i == 1)
		{
			(*stack_a) = (*stack_a)->next;
			swap(stack_a, stack_b, 1);
			push(stack_a, stack_b, 1);
		}
		else if (i == 2)
		{
			(*stack_a) = (*stack_a)->next;
			rotate(stack_a, 1);
			swap(stack_a, stack_b, 1);
			push(stack_a, stack_b, 1);
		}
		else if (i == 3)
		{
			(*stack_a) = (*stack_a)->next;
			reverse_rotate(stack_a, 1);
			reverse_rotate(stack_a, 1);
			push(stack_a, stack_b, 1);
		}
		else if (i == 4)
		{
			(*stack_a) = (*stack_a)->next;
			reverse_rotate(stack_a, 1);
			push(stack_a, stack_b, 1);
		}
	}
	while ((*stack_b) != NULL)
		push(stack_b, stack_a, 2);
	return ;
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int	min_fixed;

	min_fixed = find_min()
}*/
