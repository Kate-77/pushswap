/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 13:52:16 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/04/14 03:46:15 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pushswap.h"
#include <stdio.h>
int isempty(struct stack *s) 
{
   if(s->top == -1)
      return 1;
   else
      return 0;
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;
	int		j;

	i = 1;
	j = 0;
	stack_a = (t_list *)malloc(sizeof(t_list));
	stack_b = (t_list *)malloc(sizeof(t_list));
	if (argc > 2)
	{
		while (argv[i])
		{
			push_a(&stack_a, ft_atoi(argv[i]));
			i++;
		}
		while (stack_a->next != NULL)
		{
			printf("%d\n", stack_a->content);
			stack_a = stack_a->next;
		}
	}
	else
		write(1, "error", 5);
}
