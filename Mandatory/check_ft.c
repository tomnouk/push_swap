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

int	is_int(long int n)
{
	if (n > 2147483647 || n < -2147483648)
		return (0);
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

void	exit_error(t_stack *s1, t_stack *s2)
{
	write(2, "Error\n", 6);
	if (s1) {
		free(s1->buffer);
		free(s1);
	}
	if (s2) {
		free(s2->buffer);
		free(s2);
	}
	exit(EXIT_FAILURE);
}

void	free_if(char ***argv, t_stack *a)
{
	int	i;

	if (a->expanded)
	{
		i = 0;
		while ((*argv)[i])
		{
			free((*argv)[i]);
			i++;
		}
		free(*argv);
	}
}
