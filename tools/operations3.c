/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:03:00 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/05/23 02:32:35 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

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
