/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 04:38:27 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/04/21 03:45:39 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int	duplicate(t_list *stack)
{
	t_list	*head;

	head = stack;
	while (stack != NULL)
	{
		head = stack;
		while (head != NULL)
		{
			if (head->content == head->next->content)
				return (1);
			head = head->next;
		}
		stack = stack->next;
	}
	return (0);
}
/*
int duplicated(t_list *head)
{
	t_list	*head;
 
    while (head->next != NULL)
	{
        t_list *ptr = head->next;
        while (ptr != NULL) 
		{
            if (head->data == ptr->data) 
			{
                count++;
                break;
            }
            ptr = ptr->next;
        }
        head = head->next;
    }
    return count;
}

void	sort_three(t_list **stack_a, t_list **stack_b)
{

}*/
