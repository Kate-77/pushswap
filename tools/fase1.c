/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fase1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 02:45:07 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/05/19 05:53:07 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"
#include <stdio.h>

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

int	check_b(t_array *array, t_list *stack_b)
{
	int	max;

	max = findmax_arr(array);
	while (stack_b != NULL)
	{
		if (stack_b->content == max)
			return (1);
		stack_b = stack_b->next;
	}
	return (0);
}

void	sort2(t_array *array, t_list **stack_a, t_list **stack_b)
{
	int	indicator;
	int	i;

	indicator = 0;
	i = array->size - 1;
	while (lst_size(*stack_b) || indicator != 0)
	{
		if (check_b(array, *stack_b))
		{
			printf("one\n");
			if ((*stack_b)->content == array->arr[i])
			{
				printf("one 1\n");
				push(stack_b, stack_a, 2);
				i--;
			}
			else if (lst_size(*stack_a))
			{
				printf("one 2\n");
				if (indicator == 0 || (*stack_b)->content > ft_lstlast(*stack_a)->content)
				{
					push(stack_b, stack_a, 2);
					rotate(stack_a, 1);
					indicator++;
				}
			}
			else if (indicator == 0)
			{
				printf("one 3\n");
				push(stack_b, stack_a, 2);
				rotate(stack_a, 1);
				indicator++;
			}
			else
			{
				if (get_maxindex(*stack_b, array->arr[i]) < lst_size(*stack_b) / 2)
				{
					rotate(stack_b, 2);
					printf("one 4\n");
				}
				else
				{
					reverse_rotate(stack_b, 2);
					printf("one 5\n");
				}
			}
		}
		else if (indicator > 0 && lst_size(*stack_a) > 1)
		{
			printf("two\n");
			reverse_rotate(stack_a, 1);
			//indicator--;
			//i--;
		}
	}
	return ;
}

void    sort(t_array *array, t_list **stack_a, t_list **stack_b)
{
	t_coors *coors;

	coors = (t_coors *)malloc(sizeof(t_coors));
	initialize(&coors, stack_a, stack_b);
	while (lst_size(*stack_a))
	{
		while(lst_size(*stack_b) < coors->range  && lst_size(*stack_a))
		{
			if (((*stack_a)->content >= array->arr[coors->start])
					&& ((*stack_a)->content <= array->arr[coors->end - 1]))
			{
				push(stack_a, stack_b, 1);
				if ((*stack_b)->content > array->arr[coors->middle] && lst_size(*stack_b) > 1)
					rotate(stack_b, 2);
			}
			else
				rotate(stack_a, 1);
		}
		coors->start = coors->start - coors->offset;
		if (coors->start < 0)
			coors->start = 0;	
		coors->end = coors->end + coors->offset;
		if (coors->end > coors->size_a)
			coors->end = coors->size_a;
		coors->range = coors->end - coors->start;
	}
	sort2(array, stack_a, stack_b);
	return ;
}


