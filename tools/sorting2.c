/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 06:51:05 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/04/25 04:24:03 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"
#include <stdio.h>

int	*create_array(t_list *stack, int **arr)
{
	(void)arr;
	int	arr1[lst_size(stack)];
	int	i = 0;

	while (stack != NULL)
	{
		arr1[i] = stack->content;
		printf("here %d\n", arr1[i]);
		stack = stack->next;
		i++;
	}
	*arr = arr1;
	return (*arr);
}

void	swap_arr(int **arr, int i, int j)
{
	int	tmp;

	tmp = *arr[i];
	*arr[i] = *arr[j];
	*arr[j] = *arr[i];
	return ;
}

int	*sort_arr(int *arr, t_list *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < lst_size(stack))
	{
		j = i + 1;
		while (j < lst_size(stack))
		{
			if (arr[i] > arr[j])
				swap_arr(&arr, i, j);
			printf("arri : %d arrj : %d\n", arr[i], arr[j]);
			j++;
		}
		i++;
	}
	return (arr);
}

