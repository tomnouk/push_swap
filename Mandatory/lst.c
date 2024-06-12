/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 21:41:30 by anomourn          #+#    #+#             */
/*   Updated: 2024/06/12 15:03:52 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = lstlast(*lst);
	temp->next = new;
}

t_stack	*lst_before_last(t_stack *lst)
{
	if (lst && lst->next)
		while (lst->next->next)
			lst = lst->next;
	return (lst);
}

t_stack	*lstlast(t_stack *lst)
{
	if (lst)
		while (lst->next)
			lst = lst->next;
	return (lst);
}

t_stack	*get_tail(t_stack *s)
{
	t_stack	*tmp;

	tmp = s;
	while (tmp && tmp->next)
		tmp = tmp->next;
	return (tmp);
}
