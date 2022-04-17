/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 13:52:16 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/04/17 02:51:52 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pushswap.h"
#include <stdio.h>

void	print(t_list *stack)
{
	while (stack != NULL)
	{
		ft_putnbr(stack->content);
		write(1, "\n", 1);
		stack = stack->next;
	}
	return ;
}

void	push(t_list **stack, char **argv)
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

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 2)
	{
		push(&stack_a, argv);
		//print(stack_a);
		//sa(&stack_a);
		//print(stack_a);
		//rra(&stack_a);
		//print(stack_a);
		ra(&stack_a);
		print(stack_a);
	}
	else
		write(1, "error", 5);
	return 0;
}
