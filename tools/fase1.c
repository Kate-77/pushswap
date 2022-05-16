/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fase1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 02:45:07 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/05/16 02:32:43 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"
#include <stdio.h>

void	initialize(t_coors **coors, t_list **stack_a, t_list **stack_b)
{
	(*coors)->size_a = lst_size(*stack_a);
	(*coors)->size_b = lst_size(*stack_b);
	if ((*coors)->size_a <= 10)
		(*coors)->offset = 2;
	else if ((*coors)->size_a < 150)
		(*coors)->offset = 5;
	else if ((*coors)->size_a > 150)
		(*coors)->offset = 15;
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

void    sort(t_array *array, t_list **stack_a, t_list **stack_b)
{
	t_coors *coors;
	(void)array;

	coors = (t_coors *)malloc(sizeof(t_coors));
	initialize(&coors, stack_a, stack_b);
	while (lst_size(*stack_a))
	{
		while(lst_size(*stack_b) < coors->range  && lst_size(*stack_a))
		{
			printf("start %d\n array-start %d\n", coors->start, array->arr[coors->start]);
			printf("end %d\n array-end %d\n", coors->end, array->arr[coors->end]);
			printf("range %d\n", coors->range);
			printf("stack_a %d\n", (*stack_a)->content);
			if (((*stack_a)->content >= array->arr[coors->start])
					&& ((*stack_a)->content < array->arr[coors->end]))
			{
				push(stack_a, stack_b, 1);
				if (lst_size(*stack_b) > 1 && (*stack_b)->content > array->arr[coors->middle])
				{
					printf("HEEEEEEEEEEEERE");	
					rotate(stack_b, 2);
				}
			}
			else
				rotate(stack_a, 1);
		}
		exit(0);
		coors->start = coors->start - coors->offset;
		if (coors->start < 0)
			coors->start = 0;	
		coors->end = coors->end + coors->offset;
		if (coors->end > coors->size_a)
			coors->end = coors->size_a;
		if ((*stack_a)->next == NULL)
			push(stack_a, stack_b, 1);
	}
	printf("here");
	return ;
}
