/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 14:10:39 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/05/20 05:31:10 by kmoutaou         ###   ########.fr       */
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
}	t_list;

typedef	struct array
{
	int	*arr;
	int	size;
} t_array;

typedef struct coors
{
	int	size_a;
	int	size_b;
	int	middle;
	int	end;
	int	start;
	int	offset;
	int	range;
} t_coors;

t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_putnbr(int n);
int		ft_atoi(const char *str);
void	swap(t_list **stack, t_list **not_tobeused, int o);
void	ss(t_list **stack_a, t_list **stack_b);
void	rotate(t_list **stack, int o);
void	rr(t_list **stack_a, t_list **stack_b);
void	reverse_rotate(t_list **stack, int o);
void	rrr(t_list **stack_a, t_list **stack_b);
void	fill_stack(t_list **stack, char **argv);
void	delete_last(t_list **stack);
void	delete_first(t_list **stack);
int		isempty(t_list *stack);
void	push(t_list **source, t_list **destination, int o);
int		lst_size(t_list *lst);
int		duplicate(t_list *stack);
int		find_max(t_list *stack);
int		find_min(t_list *stack);
void	sort_three(t_list **stack_a, t_list **stack_b);
void	sort_four(t_list **stack_a, t_list **stack_b);
void	sort_five(t_list **stack_a, t_list **stack_b);
//int		array_size(int *arr);
void	sort_arr(t_array *array);
void	swap_arr(t_array *array, int i, int j);
void	create(t_array *array, t_list *stack);
void    sort(t_array *array, t_list **stack_a, t_list **stack_b);
void	print(t_list *stack, int s);
int		check_b(t_array *array, t_list *stack_b, int i);
int		findmax_arr(t_array *array);
int		get_maxindex(t_list *stack, int max);

#endif
