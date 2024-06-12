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

// void	sort_moins_250(t_data *s)
// {
// 	int	i;

// 	i = 0;
// 	while (i++ < s->size_a + s->size_b)
// 	{
// 		if (s->a->group == 0)
// 		{
// 			push_b(s, 1);
// 			rotate_b(s, 1);
// 		}
// 		else if (s->a->group == 1)
// 			push_b(s, 1);
// 		else
// 			rotate_a(s, 1);
// 		//printf("size_a = %d\n", s->size_a);
// 	}
// 	while (s->size_a)
// 		push_b(s, 1);
// 	sort_n_bis(s);
// }

void	sort_moins_250(t_data *s)
{
	int	i;
	int move;

	i = 0;
	move = 0;
	while (i++ < s->size_a + s->size_b)
	{
		if (s->a->group == 0)
		{
			if (move == 1)
				rotate_b(s, 1);
			push_b(s, 1);
			// rotate_b(s, 1);
			move = 1;
		}
		else if (s->a->group == 1)
		{
			if (move == 1)
				rotate_b(s, 1);
			push_b(s, 1);
			move = 0;
		}
		else
		{
			if (move == 1)
				rotate_both(s, 1);
			else
				rotate_a(s, 1);
			move = 0;
		}
	}
	// if (move == 1)
	// 	rotate_b(s, 1);
	while (s->size_a)
		push_b(s, 1);
	sort_n_bis(s);
}

// void sort_moins_250(t_data *s)
// {
//     int i;

//     i = 0;
//     while (i++ < s->size_a + s->size_b)
//     {
//         if (s->a->group == 0)
//         {
//             if (s->a->next && s->a->next->group == 2)
//             {
//                 rotate_both(s, 1);
//             }
//             else
//             {
//                 push_b(s, 1);
//                 rotate_b(s, 1);
//             }
//         }
//         else if (s->a->group == 1)
//             push_b(s, 1);
//         else
//             rotate_a(s, 1);
//     }
//     while (s->size_a)
//         push_b(s, 1);
//     sort_n_bis(s);
//}


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
