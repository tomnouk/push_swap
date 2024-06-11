/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 21:41:30 by anomourn          #+#    #+#             */
/*   Updated: 2024/06/03 21:41:30 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_s(t_stack *s)
{
	swap(s);
	if (s->name == 'a')
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}

void	push_s(t_stack *s1, t_stack *s2)
{
	push(s1, s2);
	if (s1->name == 'a')
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}

void	push_b(t_data *s, int must_print)
{
	t_stack	*tmp;

	if (s->a)
	{
		if (must_print)
			write(1, "pb\n", 3);
		s->size_a--;
		s->size_b++;
		tmp = s->a;
		s->a = s->a->next;
		tmp->next = s->b;
		s->b = tmp;
	}
}

void	rotate_spec(t_stack *s)
{
	rotate(s);
	if (s->name == 'a')
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void	reverse_rotate_spec(t_stack *s)
{
	reverse_rotate(s);
	if (s->name == 'a')
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}
