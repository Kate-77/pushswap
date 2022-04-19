/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:11:15 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/04/19 04:52:48 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	ft_putnbr(int n)
{
	char	nn;

	if (n == -2147483648)
	{
		write(1, "-", 1);
		write(1, "2147483648", 10);
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		ft_putnbr(n * -1);
	}
	else if (n >= 0 && n <= 9)
	{
		nn = n + '0';
		write(1, &nn, 1);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

int	isempty(t_list *stack)
{
	if (stack->next == NULL)
		return (1);
	else
		return (0);
}

void	delete_last(t_list **stack)
{
	t_list	*head;

	head = *stack;
	while ((*stack)->next->next != NULL)
		*stack = (*stack)->next;
	(*stack)->next = NULL;
	*stack = head;
	return ;
}

void	delete_first(t_list **stack)
{
	*stack = (*stack)->next;
	return ;
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	if (isempty(*stack_a) || isempty(*stack_a))
		return ;
	(*stack_a)->stack = 1;
	reverse_rotate(stack_a);
	(*stack_b)->stack = 2;
	reverse_rotate(stack_b);
	return ;
}
