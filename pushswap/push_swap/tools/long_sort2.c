/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 01:12:58 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/05/23 01:25:34 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	initialize(t_coors **coors, t_list **stack_a, t_list **stack_b)
{
	(*coors)->size_a = lst_size(*stack_a);
	(*coors)->size_b = lst_size(*stack_b);
	if ((*coors)->size_a <= 10)
		(*coors)->offset = (*coors)->size_a / 2;
	else if ((*coors)->size_a <= 150)
		(*coors)->offset = (*coors)->size_a / 5;
	else if ((*coors)->size_a > 150)
		(*coors)->offset = (*coors)->size_a / 18;
	(*coors)->middle = (*coors)->size_a / 2;
	(*coors)->end = (*coors)->middle + (*coors)->offset;
	if ((*coors)->end > (*coors)->size_a)
		(*coors)->end = (*coors)->size_a;
	(*coors)->start = (*coors)->middle - (*coors)->offset;
	if ((*coors)->start < 0)
		(*coors)->start = 0;
	(*coors)->range = (*coors)->end - (*coors)->start;
	return ;
}

int	get_maxindex(t_list *stack, int max)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		if (stack->content == max)
			return (i);
		stack = stack->next;
		i++;
	}
	return (i);
}

int	check_b(t_array *array, t_list *stack_b, int i)
{
	int	max;

	max = array->arr[i];
	while (stack_b != NULL)
	{
		if (stack_b->content == max)
			return (1);
		stack_b = stack_b->next;
	}
	return (0);
}
