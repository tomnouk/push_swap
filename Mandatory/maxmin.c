/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxmin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:02:45 by anomourn          #+#    #+#             */
/*   Updated: 2024/06/11 12:37:03 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_int(long int n)
{
	if (n > 2147483647 || n < -2147483648)
		return (0);
	return (1);
}

t_stack	*get_min(t_stack *lst)
{
	t_stack	*min;

	min = lst;
	while (lst)
	{
		if (lst->nbr < min->nbr)
			min = lst;
		lst = lst->next;
	}
	return (min);
}

t_stack	*get_max(t_stack *lst)
{
	t_stack	*max;

	max = lst;
	while (lst)
	{
		if (lst->nbr > max->nbr)
			max = lst;
		lst = lst->next;
	}
	return (max);
}
