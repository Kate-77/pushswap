/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:03:00 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/05/26 05:15:40 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

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

void	push(t_list **source, t_list **destination, int o)
{
	if (o == 1)
		write(1, "pb\n", 3);
	else if (o == 2)
		write(1, "pa\n", 3);
	if (isempty(*source))
		return ;
	ft_lstadd_front(destination, ft_lstnew((*source)->content));
	delete_first(source);
	return ;
}

int	duplicate(t_list *stack)
{
	t_list	*head;

	while (stack != NULL)
	{
		head = stack->next;
		while (head != NULL)
		{
			if (stack->content == head->content)
				return (0);
			head = head->next;
		}
		stack = stack->next;
	}
	return (1);
}

int	check_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc && argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!((argv[i][j] >= '0' && argv[i][j] <= '9')
						|| argv[i][j] == '-'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	find_max(t_list *stack)
{
	int	max;

	max = stack->content;
	while (stack->next != NULL)
	{
		if (max < stack->next->content)
			max = stack->next->content;
		stack = stack->next;
	}
	return (max);
}
