/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_little_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:57:35 by anomourn          #+#    #+#             */
/*   Updated: 2024/06/12 21:57:45 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *a, t_stack *b)
{
	if (!is_sorted_spec(a, 0))
	{
		if (sorted_pos(a, s_len(a) - 1, b) == a->head)
		{
			if (!is_sorted_spec(b, 0))
				rotate_spec(a);
			else
				rotate_ab(a, b);
		}
		else if (sorted_pos(a, s_len(a) - 1, b)
			!= (a->tail - 1 + a->size) % a->size)
		{
			if (!is_sorted_spec(b, 0))
				reverse_rotate_spec(a);
			else
				reverse_rotate_ab(a, b);
		}
		if (sorted_pos(a, 0, b) != a->head)
		{
			if (!is_sorted_spec(b, 0))
				swap_s(a);
			else
				swap_ab(a, b);
		}
	}
}

void	sort_5(t_stack *a)
{
	t_stack		b;
	int			d_tail;
	int			i;

	i = sorted_pos(a, 1, NULL);
	if (dist_top(a, sorted_pos(a, 0, NULL), &d_tail)
		<= dist_top(a, sorted_pos(a, 1, NULL), &d_tail))
		i = sorted_pos(a, 0, NULL);
	i_at_top(a, i);
	if (!is_sorted_spec(a, 0))
	{
		init(&b, a->size, 'b', a);
		push_s(&b, a);
		i = sorted_pos(a, 0, &b);
		i_at_top(a, i);
		push_s(&b, a);
		sort_3(a, &b);
		if (is_sorted_spec(&b, 0))
			swap_s(&b);
		push_s(a, &b);
		push_s(a, &b);
	}
	free(b.buffer);
}
