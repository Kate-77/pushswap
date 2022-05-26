/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:11:11 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/05/25 03:00:48 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	swap_c(t_list **stack, t_list **not_tobeused)
{
	int	tmp;

	(void)not_tobeused;
	if (isempty(*stack))
		return ;
	tmp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = tmp;
	return ;
}

void	ss_c(t_list **stack_a, t_list **stack_b)
{
	swap_c(stack_a, stack_b);
	swap_c(stack_b, stack_a);
	return ;
}

void	rotate_c(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (isempty(*stack))
		return ;
	head = *stack;
	tail = ft_lstlast(*stack);
	tail->next = ft_lstnew((*stack)->content);
	delete_first(stack);
	return ;
}

void	rr_c(t_list **stack_a, t_list **stack_b)
{
	rotate_c(stack_a);
	rotate_c(stack_b);
	return ;
}

void	reverse_rotate_c(t_list **stack)
{
	t_list	*tail;

	if (isempty(*stack))
		return ;
	tail = ft_lstlast(*stack);
	ft_lstadd_front(stack, ft_lstnew(tail->content));
	delete_last(stack);
	return ;
}
