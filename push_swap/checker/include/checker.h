/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 03:46:08 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/05/25 05:02:09 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../../include/pushswap.h"

char	*get_next_line(int fd);
int		ft_check_newline(char *str);
char	*get_line(char *text);
char	*get_afternewline_line(char *text);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		check_test(int test, char *buff);
char	*ft_substr(char *s, int start, int len);
char	*ft_strdup(char *s1);
int		ft_strcmp(const char *s1, const char *s2);
void	swap_c(t_list **stack, t_list **not_tobeused);
void	ss_c(t_list **stack_a, t_list **stack_b);
void	rotate_c(t_list **stack);
void	rr_c(t_list **stack_a, t_list **stack_b);
void	reverse_rotate_c(t_list **stack);
void	rrr_c(t_list **stack_a, t_list **stack_b);
void	push_c(t_list **source, t_list **destination);
void	s(char *instruction, t_list **stack_a, t_list **stack_b);
void	p(char *instruction, t_list **stack_a, t_list **stack_b);
void	r(char *instruction, t_list **stack_a, t_list **stack_b);

#endif
