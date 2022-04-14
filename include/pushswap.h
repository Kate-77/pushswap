/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 14:10:39 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/04/14 03:46:46 by kmoutaou         ###   ########.fr       */
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

int			ft_isdigit(int c);
static int	ft_convert(const char *str, int i, int result, int sign);
int			ft_atoi(const char *str);
int isempty(struct stack *s);
void	sa(t_list *stack_a);
void	sb(t_list *stack_b);
void	ss(t_list *stack_a, t_list *lst1, t_list *stack_b, t_list *lst2);
void	ra(t_list *stack_a);
void	rb(t_list *stack_b);
void	rr(t_list *stack_a, t_list *lst1, t_list *stack_b, t_list *lst2);
void	push_a(t_list **lst, int val);
void	push_b(t_list *lst, int val);

#endif
