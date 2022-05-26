/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 01:19:09 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/05/23 05:08:42 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	max_existent(t_array *array, t_list **stack_a, t_list **stack_b,
		int *indicators)
{
	if ((*stack_b)->content == array->arr[indicators[1]])
	{
		push(stack_b, stack_a, 2);
		indicators[1] = indicators[1] - 1;
	}
	else if (*stack_b && (indicators[0] == 0 || ((*stack_a)
				&& (*stack_b)->content
				> ft_lstlast(*stack_a)->content)))
	{
		push(stack_b, stack_a, 2);
		rotate(stack_a, 1);
		indicators[0] = indicators[0] + 1;
	}
	else
	{
		if (get_maxindex(*stack_b, array->arr[indicators[1]])
			< lst_size(*stack_b) / 2)
			rotate(stack_b, 2);
		else
			reverse_rotate(stack_b, 2);
	}
	return ;
}

void	sort2(t_array *array, t_list **stack_a, t_list **stack_b)
{
	int	indicators[2];

	indicators[0] = 0;
	indicators[1] = array->size - 1;
	while (lst_size(*stack_b) || indicators[0] != 0)
	{
		if (check_b(array, *stack_b, indicators[1]))
			max_existent(array, stack_a, stack_b, indicators);
		else if (indicators[0] > 0 && lst_size(*stack_a) > 1)
		{
			reverse_rotate(stack_a, 1);
			indicators[0]--;
			indicators[1]--;
		}
	}
	return ;
}

void	from_a_b(t_array *array, t_coors *coors, t_list **stack_a,
		t_list **stack_b)
{
	while (lst_size(*stack_b) < coors->range && lst_size(*stack_a))
	{
		if (((*stack_a)->content >= array->arr[coors->start])
			&& ((*stack_a)->content <= array->arr[coors->end - 1]))
		{
			push(stack_a, stack_b, 1);
			if ((*stack_b)->content > array->arr[coors->middle]
				&& lst_size(*stack_b) > 1)
				rotate(stack_b, 2);
		}
		else
			rotate(stack_a, 1);
	}
	return ;
}

void	sort(t_array *array, t_list **stack_a, t_list **stack_b)
{
	t_coors	*coors;

	coors = (t_coors *)malloc(sizeof(t_coors));
	initialize(&coors, stack_a, stack_b);
	while (lst_size(*stack_a))
	{
		from_a_b(array, coors, stack_a, stack_b);
		coors->start = coors->start - coors->offset;
		if (coors->start < 0)
			coors->start = 0;
		coors->end = coors->end + coors->offset;
		if (coors->end > coors->size_a)
			coors->end = coors->size_a;
		coors->range = coors->end - coors->start;
	}
	sort2(array, stack_a, stack_b);
	free(coors);
	return ;
}
