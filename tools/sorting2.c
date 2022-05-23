/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 06:51:05 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/05/21 01:27:43 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

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
