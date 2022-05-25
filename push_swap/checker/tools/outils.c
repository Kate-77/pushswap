/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 04:14:51 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/05/25 05:08:02 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned const char	*s1_temp;
	unsigned const char	*s2_temp;
	unsigned int		i;

	s1_temp = (unsigned const char *)s1;
	s2_temp = (unsigned const char *)s2;
	i = 0;
	if (!s1 && !s2)
		return (0);
	if ((ft_strlen((char *)s1) == 0) || (ft_strlen((char *)s2) == 0))
		return (s1_temp[i] - s2_temp[i]);
	while (s2_temp[i] && s1_temp[i])
	{
		if (s1_temp[i] != s2_temp[i])
			return (s1_temp[i] - s2_temp[i]);
		i++;
	}
	return (s1_temp[i] - s2_temp[i]);
}

void	s(char *instruction, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(instruction, "sa\n") == 0)
		swap_c(stack_a, stack_b);
	else if (ft_strcmp(instruction, "sb\n") == 0)
		swap_c(stack_b, stack_a);
	else
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	return ;
}

void	p(char *instruction, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(instruction, "pa\n") == 0)
		push_c(stack_b, stack_a);
	else if (ft_strcmp(instruction, "pb\n") == 0)
		push_c(stack_a, stack_b);
	else
		s(instruction, stack_a, stack_b);
	return ;
}

void	r(char *instruction, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(instruction, "ra\n") == 0)
		rotate_c(stack_a);
	else if (ft_strcmp(instruction, "rb\n") == 0)
		rotate_c(stack_b);
	else if (ft_strcmp(instruction, "rra\n") == 0)
		reverse_rotate_c(stack_a);
	else if (ft_strcmp(instruction, "rrb\n") == 0)
		reverse_rotate_c(stack_b);
	else if (ft_strcmp(instruction, "rr\n") == 0)
		rr_c(stack_a, stack_b);
	else if (ft_strcmp(instruction, "rrr\n") == 0)
		rrr_c(stack_a, stack_b);
	else
		p(instruction, stack_a, stack_b);
	return ;
}
