/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 22:28:47 by anoukmourna       #+#    #+#             */
/*   Updated: 2024/06/12 21:40:32 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	expand_argv(t_stack *a, char ***argv, int *argc)
{
	if (*argc == 2)
	{
		*argv = ft_split((*argv)[1], ' ');
		if (!*argv)
			exit_error(NULL, NULL);
		*argc = 0;
		while ((*argv)[*argc])
			(*argc)++;
		a->expanded = 1;
	}
	else
	{
		*argv = &((*argv)[1]);
		a->expanded = 0;
		(*argc)--;
	}
	init(a, *argc + 1, 'a', NULL);
}

t_stack	*init_parse(int nb)
{
	t_stack	*s;

	s = ft_calloc(1, sizeof(t_stack));
	s->nbr = nb;
	s->next = NULL;
	return (s);
}

t_stack	*handle_error(char **argv, t_stack *res, int argc)
{
	if (argc == 2)
		free_matrice(argv);
	free_stack(res);
	exit_error(NULL, NULL);
	return (NULL);
}

void	add_elem_to_list(t_stack **res, int value, int *nb)
{
	t_stack	*s;

	s = init_parse(value);
	lstadd_back(res, s);
	*nb += 1;
}

t_stack	*parse_args(char **argv, int *nb, int argc)
{
	t_stack	*res;
	int		i;

	res = NULL;
	i = -1;
	while (argv && argv[++i])
	{
		if (check_digital(argv[i]) == 0)
			return (handle_error(argv, res, argc));
		add_elem_to_list(&res, ft_atoi(argv[i]), nb);
		if (check_double(res) == 0)
			return (handle_error(argv, res, argc));
	}
	return (res);
}
