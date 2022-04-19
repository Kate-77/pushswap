/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 13:52:16 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/04/19 04:52:59 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pushswap.h"
#include "ft_printf/ft_printf.h"
#include <stdio.h>

void	print(t_list *stack)
{
	while (stack != NULL)
	{
		ft_printf("%d", stack->content);
		//ft_putnbr(stack->content);
		//ft_putnbr(stack_b->content);
		write(1, "\n", 1);
		stack = stack->next;
		//stack_b = stack_b->next;
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

void	push(t_list **source, t_list **destination)
{
	if (isempty(*source))
		return ;
	ft_lstadd_back(destination, ft_lstnew((*source)->content));
	delete_first(source);
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
		fill_stack(&stack_a, argv);
		print(stack_a);
		//stack_a->stack = 1;
		push(&stack_a, &stack_b);
		print(stack_b);
	}
	else
		write(1, "error", 5);
	return 0;
}
