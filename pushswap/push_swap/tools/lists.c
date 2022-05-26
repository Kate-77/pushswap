/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:30:25 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/05/26 04:52:19 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new_elmnt;

	new_elmnt = (t_list *)malloc(sizeof(t_list));
	if (!new_elmnt)
		return (new_elmnt);
	new_elmnt -> content = content;
	new_elmnt -> next = NULL;
	return (new_elmnt);
}

void	ft_lstadd_front(t_list **lst, t_list *new_l)
{
	new_l -> next = *lst;
	*lst = new_l;
}

void	ft_lstadd_back(t_list **lst, t_list *new_l)
{
	t_list	*head;

	if (*lst == NULL)
		*lst = new_l;
	else
	{
		head = *lst;
		while (head -> next != NULL)
			head = head -> next;
		head -> next = new_l;
	}
	return ;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

int	lst_size(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
