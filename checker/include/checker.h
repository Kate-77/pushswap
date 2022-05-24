/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 03:46:08 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/05/24 05:07:05 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
int		ft_check_newline(char *str);
char	*get_line(char *text);
char	*get_afternewline_line(char *text);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		check_test(int test, char *buff);
char	*ft_substr(char *s, int start, int len);
char	*ft_strdup(char *s1);
void	fill_stack(t_list **stack, char **argv);
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new_l);
void	ft_lstadd_front(t_list **lst, t_list *new_l);
//void	ft_putnbr(int n);
int		ft_atoi(const char *str);
void	swap(t_list **stack, t_list **not_tobeused, int o);
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
void	check_error(t_list *stack);
int		check_args(int argc, char **argv);

#endif
