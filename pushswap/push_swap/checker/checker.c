/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 23:11:00 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/05/26 05:12:49 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/checker.h"

int	stack_sorted(t_list *stack)
{
	while (stack->next != NULL)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	result(t_list *stack_a, t_list *stack_b)
{
	if (!stack_sorted(stack_a) || !(isempty(stack_b)))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
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
	char	*instruction;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 2 && check_args(argc, argv) == 1)
	{
		fill_stack(&stack_a, argv);
		check_error(stack_a);
		instruction = get_next_line(0);
		while (instruction)
		{
			r(instruction, &stack_a, &stack_b);
			free(instruction);
			instruction = get_next_line(0);
		}
		result(stack_a, stack_b);
	}
	else
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	return (0);
}
