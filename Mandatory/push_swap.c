/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 21:41:48 by anomourn          #+#    #+#             */
/*   Updated: 2024/06/03 21:41:48 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long int	ft_atoi2(const char *str)
{
	int			i;
	int			n;
	long int	res;

	n = 0;
	i = 1;
	res = 0;
	if (str[n] == '-' || str[n] == '+')
	{
		if (str[n] == '-')
			i *= -1;
		n += 1;
	}
	while (str[n] >= '0' && str[n] <= '9')
		res = res * 10 + (str[n++] - '0');
	return (res * i);
}

void	init(t_stack *s, int size, char name, t_stack *s_tofree)
{
	s->buffer = malloc(size * sizeof(int));
	if (!s->buffer)
		exit_error(s_tofree, NULL);
	s->size = size;
	s->head = 0;
	s->tail = 0;
	s->name = name;
}

void free_stack(t_stack *s)
{
    t_stack *tmp;
    while (s)
    {
        tmp = s;
        s = s->next;
        free(tmp);
    }
}

t_data	push_swap(char **argv)
{
	t_data	s;

	s.size_a = 0;
	s.size_b = 0;
	s.a = parse_args(argv, &s.size_a);
	s.b = NULL;
	set_groups(s.a, s.size_a);
	if (is_sorted(s.a))
		return (s);
	else if (s.size_a <= 250)
		sort_moins_250(&s);
	else
		sort_plus_250(&s);
	return (s);
}

int main(int argc, char **argv)
{
    t_data s;

    if (argc <= 6)
    {
        s.a = malloc(sizeof(t_stack));
        if (!s.a)
            exit_error(NULL, NULL);
        s.b = NULL;
        expand_argv(s.a, &argv, &argc);
        while (argc > 0)
        {
            if (index_n(s.a, ft_atoi2(argv[argc - 1]))
                || !is_digit(argv[argc - 1]) || !is_int(ft_atoi2(argv[argc - 1])))
            {
				//free_if(&argv, s.a);
				exit_error(s.a, NULL);
            }
            s.a->head = (s.a->head - 1 + s.a->size) % s.a->size;
            s.a->buffer[s.a->head] = ft_atoi2(argv[argc-- - 1]);
        }
        free_if(&argv, s.a);
        if (s.a->size - 1 <= 3 && !is_sorted_spec(s.a, 0))
            sort_3(s.a, NULL);
        else if (s.a->size - 1 <= 5 && !is_sorted_spec(s.a, 0))
            sort_5(s.a);
        free(s.a->buffer);
        free(s.a);
        //free(s.b);
    }
    else if (argc > 6)
    {
        s = push_swap(argv + 1);
        free_stack(s.a);
        //free_stack(s.b);
    }
    return (0);
}
