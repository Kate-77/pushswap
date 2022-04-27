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

void	create(t_array *array, t_list *stack)
{
	int	i;

	i = 0;
	while (i < array->size)
	{
		array->arr[i] = stack->content;
		i++;
		stack = stack->next;
	}
	return ;
}

void	swap_arr(t_array *array, int i, int j)
{
	int	tmp;

	tmp = array->arr[i];
	array->arr[i] = array->arr[j];
	array->arr[j] = tmp;
	return ;
}

void	sort_arr(t_array *array)
{
	int	i;
	int	j;

	i = 0;
	while (i < array->size)
	{
		j = i + 1;
		while (j < array->size)
		{
			if (array->arr[j] < array->arr[i])
				swap_arr(array, i, j);
			j++;
		}
		i++;
	}
	return ;
}

/*
void	create_array(t_list *stack, t_array *array)
{
	int	i;
	t_list *s;

	i = 0;
	s = stack;
	while (i < array->size)
	{
		printf("here %d\n", stack->content);
		array->arr[i] = s->content;
		printf("also here %d\n", array->arr[i]);
		s = s->next;
		i++;
	}
	return ;
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
	while (arr[i] != '\0')
		i++;
	return (i);
}

void	sort_arr(int *arr, t_list *stack, int size)
{
	int	i;
	int	j;
	(void)stack;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[j] < arr[i])
				swap_arr(arr, i, j);
			j++;
		}
		i++;
	}
	return ;
}*/
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
