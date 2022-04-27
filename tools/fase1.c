/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fase1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 15:04:32 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/04/27 07:44:52 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"
#include <stdio.h>

void    sort(t_array *array, t_list **stack_a, t_list **stack_b)
{
	t_coors *coors;
	int     range;
	t_list	*head;
	int	i = 0;
	coors = (t_coors *)malloc(sizeof(t_coors));
	coors->size_a = lst_size(*stack_a);
	printf("sizeA : %d\n", coors->size_a);
	coors->size_b = lst_size(*stack_b);
	printf("sizeB : %d\n", coors->size_b);
	if (coors->size_a <= 10)
		coors->offset = 2;
	else if (coors->size_a < 150)
		coors->offset = 8;
	else if (coors->size_a > 150)
		coors->offset = 18;
	printf("offset : %d\n", coors->offset);
	coors->middle = coors->size_a / 2;
	printf("middle : %d\n", coors->middle);
	coors->end = coors->middle + coors->offset;
	if (coors->end > coors->size_a)
		coors->end = coors->size_a;
	printf("end : %d\n", coors->end);
	coors->start = coors->middle - coors->offset;
	if (coors->start < 0)
		coors->start = 0;	
	printf("start : %d\n", coors->start);
	range = coors->end - coors->start;
	while (lst_size(*stack_a) != 0)
	{
		while(lst_size(*stack_b) <= range)
		{
			head = *stack_a;
			if ((head->content <= array->arr[coors->end-1]) && (head->content >= array->arr[coors->start]))
				push(stack_a, stack_b, 1);
			else
				rotate(stack_a, 1);
			printf("sa : %d\n", head->content);
			printf("a start : %d\n", array->arr[coors->end-1]);
			printf("sfinal : %d\n", array->arr[coors->start]);
			printf("inside sizeB : %d\n", coors->size_b);
			i++;
		}
		coors->start = coors->start - coors->offset;
		if (coors->start < 0)
			coors->start = 0;	
		coors->end = coors->end + coors->offset;
		if (coors->end > coors->size_a)
			coors->end = coors->size_a;
	}
}
