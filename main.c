/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 13:52:16 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/04/23 08:07:05 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pushswap.h"
#include <stdio.h>

void	print(t_list *stack, int s)
{
	if (s == 1)
		write(1, "stack a\n", 8);
	else if (s == 2)
		write(1, "stack b\n", 8);
	write(1, "==\n", 3);
	while (stack != NULL)
	{
		ft_putnbr(stack->content);
		write(1, "\n", 1);
		stack = stack->next;
	}
	return ;
}

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
		write(1, "pa\n", 3);
	else if (o == 2)
		write(1, "pb\n", 3);
	if (isempty(*source))
		return ;
	ft_lstadd_back(destination, ft_lstnew((*source)->content));
	delete_first(source);
	return ;
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	//int		*arr;
	//int		size;
	//int		i = 0;

	stack_a = NULL;
	stack_b = NULL;
	//size = lst_size(stack_a);
	if (argc > 2)
	{
		fill_stack(&stack_a, argv);
		print(stack_a, 1);
		//if (lst_size(stack_a) == 3)
		//	sort_three(&stack_a, &stack_b);
		//print(stack_a, 1);
		create_array(stack_a);
		//sort_arr(stack_a);
		/*while (arr[i])
		{
			printf("arr %d\n", arr[i]);
			i++;
		}*/
		//reverse_rotate(&stack_a, 1);
		//print(stack_a, 1);
		//printf("dup : %d\n",duplicate(stack_a));
	}
	else
		write(1, "error", 5);
	return 0;
}
