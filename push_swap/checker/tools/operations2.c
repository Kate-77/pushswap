/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:11:15 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/05/25 03:06:25 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	rrr_c(t_list **stack_a, t_list **stack_b)
{
	write(1, "rrr\n", 4);
	reverse_rotate_c(stack_a);
	reverse_rotate_c(stack_b);
	return ;
}

int	isempty(t_list *stack)
{
	if (stack == NULL)
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
