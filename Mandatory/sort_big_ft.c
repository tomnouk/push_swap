/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 21:42:01 by anomourn          #+#    #+#             */
/*   Updated: 2024/06/03 21:42:01 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_n_bis(t_data *s)
{
	t_way					way;
	unsigned int			i;

	while (s->size_b)
	{
		way = find_way(s);
		i = 0;
		if (way.direction == 'U')
			while (i++ < way.move)
				reverse_rotate_b(s, 1);
		else if (way.direction == 'D')
			while (i++ < way.move)
				rotate_b(s, 1);
		push_a(s, 1);
	}
}

void	rotate_and_push(t_data *s, int *move, int group)
{
	if (*move == 1)
		rotate_b(s, 1);
	push_b(s, 1);
	if (group == 0)
		*move = 1;
	else
		*move = 0;
}

void	sort_moins_250(t_data *s)
{
	int	i;
	int	move;

	i = 0;
	move = 0;
	while (i++ < s->size_a + s->size_b)
	{
		if (s->a->group == 0 || s->a->group == 1)
			rotate_and_push(s, &move, s->a->group);
		else
		{
			if (move == 1)
				rotate_both(s, 1);
			else
				rotate_a(s, 1);
			move = 0;
		}
	}
	if (move == 1)
		rotate_b(s, 1);
	while (s->size_a)
		push_b(s, 1);
	sort_n_bis(s);
}

void	sort_plus_250(t_data *s)
{
	int	i;
	int	j;

	j = 0;
	while (!is_sorted(s->a))
	{
		i = 0;
		while (i++ < s->size_a + s->size_b)
		{
			if (s->a->place >> j & 1)
				rotate_a(s, 1);
			else
				push_b(s, 1);
		}
		while (s->size_b)
			push_a(s, 1);
		j++;
	}
	i = get_min(s->a)->nbr;
	while (s->a->nbr > i)
		rotate_a(s, 1);
}
