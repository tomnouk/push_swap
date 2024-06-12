/* ************************************************************************** */
/*	                                              		                      */
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

t_data	*big_sort(char **argv, t_data *s, int argc)
{
	if (argc != 2)
		s->a = parse_args(argv, &s->size_a, argc);
	s->b = NULL;
	set_groups(s->a, s->size_a);
	if (is_sorted(s->a))
		return (s);
	else if (s->size_a <= 250)
		sort_moins_250(s);
	else
		sort_plus_250(s);
	return (s);
}

void	process_args(t_data *s, char ***argv, int *argc)
{
	s->a = malloc(sizeof(t_stack));
	if (!s->a)
		exit_error(NULL, NULL);
	s->b = NULL;
	expand_argv(s->a, argv, argc);
	while (*argc > 0)
	{
		if (index_n(s->a, ft_atoi2((*argv)[*argc - 1]))
			|| !is_digit((*argv)[*argc - 1])
			|| !is_int(ft_atoi2((*argv)[*argc - 1])))
		{
			free_if(argv, s->a);
			exit_error(s->a, NULL);
		}
		s->a->head = (s->a->head - 1 + s->a->size) % s->a->size;
		s->a->buffer[s->a->head] = ft_atoi2((*argv)[(*argc)-- - 1]);
	}
	free_if(argv, s->a);
}

static void	little_sort(t_data *s)
{
	if (s->a->size - 1 <= 3 && !is_sorted_spec(s->a, 0))
		sort_3(s->a, NULL);
	else if (s->a->size - 1 <= 5 && !is_sorted_spec(s->a, 0))
		sort_5(s->a);
	free(s->a->buffer);
	free(s->a);
}

int	handle_argc_two(t_data *s, char **argv, int argc)
{
	char	**split;

	if (!argv[1][0] || argv[1][0] == ' '
		|| argv[1][ft_strlen(argv[1]) - 1] == ' '
		|| ft_strnstr(argv[1], "  ", ft_strlen(argv[1])))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	split = ft_split(argv[1], ' ');
	s->a = parse_args(split, &s->size_a, 2);
	if (s->size_a <= 5)
	{
		free_matrice(split);
		free_stack(s->a);
		s->a = NULL;
		process_args(s, &argv, &argc);
		little_sort(s);
		return (0);
	}
	big_sort(split, s, 2);
	free_matrice(split);
	free_stack(s->a);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	s;

	s = (t_data){0};
	if (argc == 2)
	{
		return (handle_argc_two(&s, argv, argc));
	}
	else if (argc <= 6)
	{
		process_args(&s, &argv, &argc);
		little_sort(&s);
		return (0);
	}
	else
		big_sort(argv + 1, &s, argc);
	free_stack(s.a);
	return (0);
}
