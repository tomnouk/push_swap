/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 21:40:40 by anomourn          #+#    #+#             */
/*   Updated: 2024/06/03 21:40:40 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	check_digital(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == '-' || s[i] == '+')
		{
			if (s[i + 1] && !ft_isdigit(s[i + 1]))
				return (0);
		}
		else if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_double(t_stack *s)
{
	t_stack	*tmp;

	while (s)
	{
		tmp = s->next;
		while (tmp)
		{
			if (tmp->nbr == s->nbr)
				return (0);
			tmp = tmp->next;
		}
		s = s->next;
	}
	return (1);
}

int	is_sorted_spec(t_stack *s, int ord)
{
	int	i;

	if (!s)
		return (0);
	i = s->head;
	while (i != s->tail && (i + 1) % s->size != s->tail)
	{
		if ((s->buffer[i] > s->buffer[(i + 1) % s->size] && ord == 0)
			|| (s->buffer[i] < s->buffer[(i + 1) % s->size] && ord == 1))
			return (0);
		i = (i + 1) % s->size;
	}
	return (1);
}

int	is_sorted(t_stack *s)
{
	t_stack	*tmp;

	tmp = s;
	while (tmp->next)
	{
		if (tmp->nbr > tmp->next->nbr)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
