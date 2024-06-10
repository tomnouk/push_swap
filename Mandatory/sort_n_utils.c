/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_n_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukmournard <anoukmournard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 21:42:11 by anomourn          #+#    #+#             */
/*   Updated: 2024/06/08 19:04:42 by anoukmourna      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_n(t_stack *s, int value)
{
	int	i;

	i = s->head;
	while (i != s->tail)
	{
		if (s->buffer[i] == value)
			return ((i - s->head + s->size) % s->size + 1);
		i = (i + 1) % s->size;
	}
	return (0);
}

int	is_digit(char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
		{
			if (sign == 1)
				return (0);
			sign = 1;
		}
		else if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

t_way	test_way(t_data *s, unsigned char direction)
{
	int	start;
	int	move;
	int	max;

	max = get_max(s->b)->nbr;
	move = 0;
	start = s->b->nbr;
	while (s->b->nbr != max)
	{
		move++;
		if (direction == 'U')
			reverse_rotate_b(s, 0);
		else if (direction == 'D')
			rotate_b(s, 0);
	}
	while (s->b->nbr != start)
		rotate_b(s, 0);
	return ((t_way){.move = move, .direction = direction});
}

t_way	find_way(t_data *s)
{
	t_way	up;
	t_way	down;

	up = test_way(s, 'U');
	down = test_way(s, 'D');
	if (up.move > down.move)
		return (down);
	else
		return (up);
}
