/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 13:52:16 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/04/16 01:11:37 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pushswap.h"
#include <stdio.h>

void	print(t_list **stack)
{
	while ((*stack) != NULL)
	{
		ft_putnbr((*stack)->content);
		*stack = (*stack)->next;
	}
	return ;
}

t_list	*push(t_list **stack, char **argv)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		ft_lstadd_back(stack, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	while ((*stack) != NULL)
	{
		printf("%d\n", (*stack)->content);
		*stack = (*stack)->next;
	}
	return (*stack);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 2)
	{
		stack_a = push(&stack_a, argv);
		printf("here : %d\n", stack_a->content);
		//print(&stack_a);
		//sa(&stack_a);
		//ra(&stack_a);
	}
	else
		write(1, "error", 5);
	return 0;
}
