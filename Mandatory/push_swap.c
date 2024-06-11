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

t_data	*push_swap(char **argv, t_data *s, int argc)
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

static void	sort_and_free(t_data *s)
{
	if (s->a->size - 1 <= 3 && !is_sorted_spec(s->a, 0))
		sort_3(s->a, NULL);
	else if (s->a->size - 1 <= 5 && !is_sorted_spec(s->a, 0))
		sort_5(s->a);
	free(s->a->buffer);
	free(s->a);
}

void free_matrice(char **mat)
{
	int i;

	i = 0;
	while (mat[i])
	{
		free(mat[i]);
		i++;
	}
	free(mat);
}

int	main(int argc, char **argv)
{
	t_data	s;

	s = (t_data){0};
	//write(1, "coucou\n", 7);
	if (argc == 2)
	{
		if (!argv[1] || argv[1][0] == ' ' || argv[1][ft_strlen(argv[1]) - 1] == ' ' || ft_strnstr(argv[1], "  ", ft_strlen(argv[1])))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		char **split = ft_split(argv[1], ' ');
		s.a = parse_args(split, &s.size_a, 2);
		if (s.size_a <= 5)
		{
			s.a->size = s.size_a + 1;
			sort_and_free(&s);
		}
		else
		{
			push_swap(split, &s, 2);
			free_stack(s.a);
		}
		free_matrice(split);
		return (0);
	}
	else if (argc <= 6)
	{
		process_args(&s, &argv, &argc);
		sort_and_free(&s);
		return (0);
	}
	else
		push_swap(argv + 1, &s, argc);
	free_stack(s.a);
	return (0);
}
