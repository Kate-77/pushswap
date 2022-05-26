/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 13:52:16 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/05/26 05:12:59 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pushswap.h"

void	sorting(t_list **stack_a, t_list **stack_b, t_array *array)
{
	if (lst_size(*stack_a) == 3)
		sort_three(stack_a, stack_b);
	else if (lst_size(*stack_a) == 4)
		sort_four(stack_a, stack_b);
	else if (lst_size(*stack_a) == 5)
		sort_five(stack_a, stack_b);
	else
	{
		sort_arr(array);
		sort(array, stack_a, stack_b);
	}
	return ;
}

void	check_error(t_list *stack)
{
	if (!(duplicate(stack)))
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	return ;
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_array	*array;

	stack_a = NULL;
	stack_b = NULL;
	array = (t_array *)malloc(sizeof(t_array));
	if (argc > 2 && check_args(argc, argv) == 1)
	{
		fill_stack(&stack_a, argv);
		check_error(stack_a);
		array->size = lst_size(stack_a);
		array->arr = (int *)malloc(sizeof(int) * array->size);
		create(array, stack_a);
		sorting(&stack_a, &stack_b, array);
		free(array->arr);
	}
	else
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	free(array);
	return (0);
}
