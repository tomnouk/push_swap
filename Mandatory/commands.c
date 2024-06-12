/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:21:43 by anomourn          #+#    #+#             */
/*   Updated: 2024/06/12 21:41:58 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_data *s, int must_print)
{
	t_stack	*tmp;

	if (s->b)
	{
		if (must_print)
			write(1, "pa\n", 3);
		s->size_b--;
		s->size_a++;
		tmp = s->b;
		s->b = s->b->next;
		tmp->next = s->a;
		s->a = tmp;
	}
}

void	rotate_a(t_data *s, int must_print)
{
	t_stack	*rotate;

	if (s->size_a > 1)
	{
		if (must_print)
			write(1, "ra\n", 3);
		rotate = s->a;
		s->a = s->a->next;
		rotate->next = NULL;
		lstadd_back(&s->a, rotate);
	}
	else
		return ;
}

void	rotate_b(t_data *s, int must_print)
{
	t_stack	*rotate;

	if (s->size_b > 1)
	{
		if (must_print)
			write(1, "rb\n", 3);
		rotate = s->b;
		s->b = s->b->next;
		rotate->next = NULL;
		lstadd_back(&s->b, rotate);
	}
	else
		return ;
}

void	reverse_rotate_b(t_data *s, int must_print)
{
	t_stack	*tmp;
	t_stack	*beforelast;

	if (s->size_b > 1)
	{
		if (must_print)
			write(1, "rrb\n", 4);
		beforelast = lst_before_last(s->b);
		tmp = lstlast(s->b);
		tmp->next = s->b;
		s->b = tmp;
		beforelast->next = NULL;
	}
	else
		return ;
}

void	reverse_rotate_a(t_data *s, int must_print)
{
	t_stack	*tmp;
	t_stack	*beforelast;

	if (s->size_a > 1)
	{
		if (must_print)
			write(1, "rra\n", 4);
		beforelast = lst_before_last(s->a);
		tmp = lstlast(s->a);
		tmp->next = s->a;
		s->a = tmp;
		beforelast->next = NULL;
	}
	else
		return ;
}
