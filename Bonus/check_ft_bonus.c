/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ft_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <sdell-er@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:15:32 by sdell-er          #+#    #+#             */
/*   Updated: 2024/01/24 11:49:00 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

int	is_present(t_stack *s, int value)
{
	int	i;

	i = s->head;
	while (i != s->tail)
	{
		if (s->buffer[i] == value)
			return (1);
		i = (i + 1) % s->size;
	}
	return (0);
}

int	is_int(long int n)
{
	if (n > 2147483647 || n < -2147483648)
		return (0);
	return (1);
}

int	is_sorted(t_stack *s)
{
	int	i;

	i = s->head;
	while (i != s->tail && (i + 1) % s->size != s->tail)
	{
		if (s->buffer[i] > s->buffer[(i + 1) % s->size])
			return (0);
		i = (i + 1) % s->size;
	}
	return (1);
}
