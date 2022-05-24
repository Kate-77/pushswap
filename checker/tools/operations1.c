/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:11:11 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/05/24 05:05:32 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	swap(t_list **stack, t_list **not_tobeused, int o)
{
	int	tmp;

	(void)not_tobeused;
	if (isempty(*stack))
		return ;
	if (o == 1)
		write(1, "sa\n", 3);
	else if (o == 2)
		write(1, "sb\n", 3);
	tmp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = tmp;
	return ;
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	write(1, "ss\n", 3);
	swap(stack_a, stack_b, -1);
	swap(stack_b, stack_a, -1);
	return ;
}

void	rotate(t_list **stack, int o)
{
	t_list	*head;
	t_list	*tail;

	if (isempty(*stack))
		return ;
	if (o == 1)
		write(1, "ra\n", 3);
	else if (o == 2)
		write(1, "rb\n", 3);
	head = *stack;
	tail = ft_lstlast(*stack);
	tail->next = ft_lstnew((*stack)->content);
	delete_first(stack);
	return ;
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	write(1, "rr\n", 3);
	rotate(stack_a, -1);
	rotate(stack_b, -1);
	return ;
}

void	reverse_rotate(t_list **stack, int o)
{
	t_list	*tail;

	if (isempty(*stack))
		return ;
	if (o == 1)
		write(1, "rra\n", 4);
	else if (o == 2)
		write(1, "rrb\n", 4);
	tail = ft_lstlast(*stack);
	ft_lstadd_front(stack, ft_lstnew(tail->content));
	delete_last(stack);
	return ;
}
