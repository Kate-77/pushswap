/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:11:11 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/04/14 03:46:28 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	sa(t_list *stack_a)
{
	int	tmp;

	tmp = stack_a->content;
	stack_a->content = stack_a->next->content;
	stack_a->content = tmp;
	return ;
}

void	sb(t_list *stack_b)
{
	int	tmp;

	tmp = stack_b->content;
	stack_b->content = stack_b->next->content;
	stack_b->content = tmp;
	return ;
}

void	ss(t_list *stack_a, t_list *lst1, t_list *stack_b, t_list *lst2)
{
	sa(stack_a);
	sb(stack_b);
	return ;
}

void	ra(t_list *stack_a)
{
	t_list	*head;
	t_list	*tail;

	head->content = stack_a->content;
	while (stack_a->next != NULL)
		stack_a = stack_a->next;
	tail->content = stack_a->next->content;
	stack_a->next->content = head->content;
	return ;
}

void	rb(t_list *stack_b)
{
	t_list	*head;
	t_list	*tail;

	head->content = stack_b->content;
	while (stack_b->next != NULL)
		stack_b = stack_b->next;
	tail->content = stack_b->next->content;
	stack_b->next->content = head->content;
	return ;
}

void	rr(t_list *stack_a, t_list *lst1, t_list *stack_b, t_list *lst2)
{
	ra(stack_a);
	rb(stack_b);
	return ;
}
/*
void	rra()
{

}

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
