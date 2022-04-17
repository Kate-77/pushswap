/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:11:11 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/04/17 02:59:44 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"
#include <stdio.h>

void    delete_last(t_list **stack)
{
    t_list  *head;

    head = *stack;
    while ((*stack)->next->next != NULL)
        *stack = (*stack)->next;
    (*stack)->next = NULL;
    (*stack) = head;
    return ;
}

void	delete_first(t_list **stack)
{
	*stack = (*stack)->next;
	return ;
}

void	sa(t_list **stack_a)
{
	int	tmp;

	printf("sa");
	tmp = (*stack_a)->content;
	(*stack_a)->content = (*stack_a)->next->content;
	(*stack_a)->next->content = tmp;
	return ;
}

void	sb(t_list **stack_b)
{
	int	tmp;

	tmp = (*stack_b)->content;
	(*stack_b)->content = (*stack_b)->next->content;
	(*stack_b)->next->content = tmp;
	return ;
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	return ;
}

void	ra(t_list **stack_a)
{
	t_list	*head;
	t_list	*tail;

	head = *stack_a;
	tail = ft_lstlast(*stack_a);
	tail->next = ft_lstnew((*stack_a)->content);
	delete_first(stack_a);
	return ;
}
/*
void	rb(t_list *stack_b)
{
	t_list	*head;
	t_list	*tail;

	head = stack_b;
	while (stack_b != NULL)
		stack_b = stack_b->next;
	stack_b->next->content = head->content;
	return ;
}*/
/*
void	rr(t_list *stack_a, t_list *stack_b)
{
	ra(stack_a);
	rb(stack_b);
	return ;
}*/

void	rra(t_list	**stack_a)
{
    t_list  *tail;

	printf("rra");
    tail = ft_lstlast(*stack_a);
    ft_lstadd_front(stack_a, ft_lstnew(tail->content));
    delete_last(stack_a);
    return ;
}
/*
void	rrb()
{

}

void	rrr()
{

}
*/
void push_a(t_list **lst, int val)
{
	t_list	*new_node;
	t_list	*head;

	head = *lst;
	new_node = malloc(sizeof(t_list *));
	new_node->content = val;
	new_node->next = head;
	head = new_node;
}

void push_b(t_list *lst, int val)
{
	t_list	*new_node;
	t_list	*head;

	head = lst;
	new_node = malloc(sizeof(t_list *));
	new_node->content = val;
	new_node->next = head;
	head = new_node;
}
