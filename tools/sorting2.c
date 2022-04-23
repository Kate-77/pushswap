/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 06:51:05 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/04/23 08:07:30 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"
#include <stdio.h>
void	create_array(t_list *stack)
{
	int	arr[lst_size(stack)];
	int	i = 0;

	while (stack != NULL)
	{
		arr[i++] = stack->content;
		stack = stack->next;
	}
	return ;
}

void	swap_arr(int *arr, int i, int j)
{
	int	tmp;

	tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = arr[i];
	return ;
}
/*
int	*sort_arr(t_list *stack)
{
	int	*arr;
	int	i;
	//int	j;

	i = 0;
	arr = create_array(stack);
	while (arr[i])
	{
		printf("arr : %d\n", arr[i]);
		i++;
	}
	while (arr[i])
	{
		j = i + 1;
		while (arr[j])
		{
			if (arr[i] > arr[j])
				swap_arr(arr, i, j);
			j++;
		}
		i++;
	}
	return (arr);
}
*/
