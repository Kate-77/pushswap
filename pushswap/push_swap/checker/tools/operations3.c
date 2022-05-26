/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:03:00 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/05/25 02:59:44 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

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

void	push_c(t_list **source, t_list **destination)
{
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
