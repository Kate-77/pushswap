/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 13:52:16 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/05/24 04:55:22 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pushswap.h"

void	print(t_list *stack, int s)
{
	if (s == 1)
		write(1, "stack a\n", 8);
	else if (s == 2)
		write(1, "stack b\n", 8);
	write(1, "==\n", 3);
	while (stack != NULL)
	{
		ft_putnbr(stack->content);
		write(1, "\n", 1);
		stack = stack->next;
	}
	return ;
}

void	fill_stack(t_list **stack, char **argv)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		ft_lstadd_back(stack, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	return ;
}

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
	}
	else
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	free(array);
	return (0);
}
