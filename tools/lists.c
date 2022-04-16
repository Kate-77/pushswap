/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:30:25 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/04/16 00:09:00 by kmoutaou         ###   ########.fr       */
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

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new -> next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*head;

	if (*lst == NULL)
		*lst = new;
	else
	{
		head = *lst;
		while (head -> next != NULL)
			head = head -> next;
		head -> next = new;
	}
	return ;
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*surf;

	surf = lst;
	while (surf != NULL)
	{
		if (surf -> next == NULL)
			return (surf);
		surf = surf -> next;
	}
	return (surf);
}
