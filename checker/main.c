/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 23:11:00 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/05/24 06:10:03 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/checker.h"
#include <stdio.h>
#include <string.h>

void	apply_ins(char **instructions, t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = 0;
	while (instructions[i])
	{
		if (strcmp(instructions[i],"pa"))
			push(stack_b, stack_a, 2);
		else if (strcmp(instructions[i], "pb"))
			push(stack_a, stack_b, 1);
		else if (strcmp(instructions[i], "ra"))
			rotate(stack_a, 1);
		else if (strcmp(instructions[i], "rb"))
			rotate(stack_b, 2);
		else if (strcmp(instructions[i], "rra"))
			reverse_rotate(stack_a, 1);
		else if (strcmp(instructions[i], "rrb"))
			reverse_rotate(stack_b, 2);
		else if (strcmp(instructions[i], "sa"))
			swap(stack_a, stack_b, 1);
		else if (strcmp(instructions[i], "sb"))
			swap(stack_b, stack_a, 2);
		else if (strcmp(instructions[i], "rr"))
			rr(stack_a, stack_b);
		else if (strcmp(instructions[i], "rrr"))
			rrr(stack_a, stack_b);
	}
	return ;
}

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

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**instructions;
	int		i;
	int		j;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	j = 0;
	instructions = (char **)malloc(sizeof(char *) * argc - 1);
	if (argc > 2)
	{
		fill_stack(&stack_a, argv);
		//check_error(stack);
		printf("linex : %s\n", get_next_line(0));
		while (i < argc && argv[i])
		{
			instructions[j] = get_next_line(0);
			printf("line : %s\n", get_next_line(0));
			i++;
			j++;
		}
		apply_ins(instructions, &stack_a, &stack_b);
		if (!stack_sorted(stack_a) && isempty(stack_b))
			write(1, "KO\n", 3);
		else
			write(1, "OK\n", 3);
	}
	else
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	return (0);
}
