/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 14:10:39 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/04/19 04:29:18 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int content;
	struct s_list	*next;
	int				stack;
}	t_list;

typedef struct o_list
{
	int pa;
	int	pb;
	int	sa;
	int	sb;
	int	ss;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	ops_list;

t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_putnbr(int n);
int		ft_atoi(const char *str);
void	swap(t_list **stack);
void	ss(t_list **stack_a, t_list **stack_b);
void	rotate(t_list **stack);
void	rr(t_list **stack_a, t_list **stack_b);
void	reverse_rotate(t_list **stack);
void	rrr(t_list **stack_a, t_list **stack_b);
void	fill_stack(t_list **stack, char **argv);
void	delete_last(t_list **stack);
void	delete_first(t_list **stack);
int		isempty(t_list *stack);
void	push(t_list **stack_a, t_list **stack_b);

#endif
