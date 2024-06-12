/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_ab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 21:41:17 by anomourn          #+#    #+#             */
/*   Updated: 2024/06/03 21:41:17 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ab(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}

void	rotate_ab(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}

void	reverse_rotate_ab(t_stack *a, t_stack *b)
{
	reverse_rotate(b);
	reverse_rotate(a);
	write(1, "rrr\n", 4);
}

void	rotate_both(t_data *s, int must_print)
{
	if (must_print)
		write(1, "rr\n", 3);
	rotate_a(s, 0);
	rotate_b(s, 0);
}
