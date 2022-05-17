/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 13:52:16 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/05/17 09:33:56 by kmoutaou         ###   ########.fr       */
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
	{
		printf("empty\n");
		return ;
	}
	ft_lstadd_front(destination, ft_lstnew((*source)->content));
	delete_first(source);
	return ;
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_array	*array;
	//int		i;

	stack_a = NULL;
	stack_b = NULL;
	array = (t_array *)malloc(sizeof(t_array));
	if (argc > 2)
	{
		fill_stack(&stack_a, argv);
		print(stack_a, 1);
        array->size = lst_size(stack_a);
	    array->arr = (int *)malloc(sizeof(int) * array->size);
	    create(array, stack_a);
	    if (lst_size(stack_a) == 3)
			sort_three(&stack_a, &stack_b);
		else if (lst_size(stack_a) == 4)
			sort_four(&stack_a, &stack_b);
		else if (lst_size(stack_a) == 5)
			sort_five(&stack_a, &stack_b);
		/*push(&stack_a, &stack_b, 1);
		print(stack_b, 2);
		print(stack_a, 1);
		printf("AFTER\n");
		push(&stack_b, &stack_a, 2);
		print(stack_b, 2);
		print(stack_a, 1);*/
		sort_arr(array);
		sort(array, &stack_a, &stack_b);
		print(stack_a, 1);
		//print(stack_a, 1);
		//print(stack_b, 2);
		/*i = 0;
	    while (i < array->size)
	    {
		    printf("arr %d\n", array->arr[i]);
		    i++;
		}*/
    }
	else
	{
		write(1, "error", 5);
		exit(0);
	}
	return 0;
}
