/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 04:17:17 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/04/19 04:51:25 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	manage(t_list **stack_a, t_list **stack_b, ops_list *operations)
{
	if (operations->sa == 1)
	{
		write(1, "sa\n", 3);
		swap(stack_a);
	}
	else if (operations->sb == 1)
	{
		write(1, "sb\n", 3);
		swap(stack_b);
	}
	else if (operations->ss == 1)
	{
		write(1, "ss\n", 3);
		ss(stack_a, stack_b);
	}
	else if (operations->ra == 1)
	{
		write(1, "ra\n", 3);
		rotate(stack_a);
	}
	else if (operations->rb == 1)
	{
		write(1, "rb\n", 3);
		rotate(stack_b);
	}
	else if (operations->rr == 1)
	{
		write(1, "rr\n", 3);
		rr(stack_a, stack_b);
	}
	else if (operations->pa == 1)
	{
		write(1, "pa\n", 3);
		push(stack_b, stack_a);
	}
	else if (operations->pb == 1)
	{
		write(1, "pb\n", 3);
		push(stack_a, stack_b);
	}
	else if (operations->rra == 1)
	{
		write(1, "rra\n", 4);
		reverse_rotate(stack_a);
	}
	else if (operations->rrb == 1)
	{
		write(1, "rrb\n", 4);
		reverse_rotate(stack_b);
	}
	else if (operations->rrr == 1)
	{
		write(1, "rrr\n", 4);
		rrr(stack_a, stack_b);
	}
	return ;
}
