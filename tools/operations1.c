/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:11:11 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/04/19 04:52:56 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"
#include <stdio.h>

void	swap(t_list **stack, t_list **not_tobeused)
{
	int	tmp;
	(void)not_tobeused;

	if (isempty(*stack))
		return ;
	if ((*stack)->stack == 1)
		write(1, "sa\n", 3);
	else if ((*stack)->stack == 2)
		write(1, "sb\n", 3);
	tmp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = tmp;
	return ;
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	if (isempty(*stack_a) || isempty(*stack_b))
		return ;
	(*stack_a)->stack = 1;
	swap(stack_a);
	(*stack_b)->stack = 2;
	swap(stack_b);
	return ;
}

void	rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (isempty(*stack))
		return ;
	if ((*stack)->stack == 1)
		write(1, "sa\n", 3);
	else if ((*stack)->stack == 2)
		write(1, "sb\n", 3);
	head = *stack;
	tail = ft_lstlast(*stack);
	tail->next = ft_lstnew((*stack)->content);
	delete_first(stack);
	return ;
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	if (isempty(*stack_a) || isempty(*stack_b))
		return ;
	(*stack_a)->stack = 1;
	rotate(stack_a);
	(*stack_b)->stack = 2;
	rotate(stack_b);
	return ;
}

void	reverse_rotate(t_list	**stack)
{
    t_list  *tail;

	if (isempty(*stack))
		return ;
	if ((*stack)->stack == 1)
		write(1, "sa\n", 3);
	else if ((*stack)->stack == 2)
		write(1, "sb\n", 3);
    tail = ft_lstlast(*stack);
    ft_lstadd_front(stack, ft_lstnew(tail->content));
    delete_last(stack);
    return ;
}
