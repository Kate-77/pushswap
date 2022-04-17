/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 14:10:39 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/04/17 01:44:21 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *items;
}	t_stack;


typedef struct s_list
{
	int content;
	struct s_list	*next;
}	t_list;

int		ft_atoi(const char *str);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
//void	rb(t_list *stack_b);
//void	rr(t_list *stack_a, t_list *stack_b);
void	push_a(t_list **lst, int val);
void	push_b(t_list *lst, int val);
t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_putnbr(int n);
void	push(t_list **stack, char **argv);
void	rra(t_list **stack);
t_list	*ft_lstlast(t_list *lst);

#endif
