/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukmournard <anoukmournard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 22:28:47 by anoukmourna       #+#    #+#             */
/*   Updated: 2024/06/06 10:53:22 by anoukmourna      ###   ########.fr       */
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

void	check_double(t_stack *s)
{
	t_stack	*tmp;

	while (s)
	{
		tmp = s->next;
		while (tmp)
		{
			if (tmp->nbr == s->nbr)
				exit_error(NULL, NULL);
			tmp = tmp->next;
		}
		s = s->next;
	}
}

t_stack	*parse_args3(int nb)
{
	t_stack	*s;

	s = ft_calloc(1, sizeof(t_stack));
	s->nbr = nb;
	s->next = NULL;
	return (s);
}

t_stack	*parse_args2(char **argv, int *nb)
{
	t_stack	*s;

	if (!*argv)
		return (NULL);
	if (!argv[0])
		exit_error(NULL, NULL);
	*nb += 1;
	s = parse_args3(ft_atoi(*argv));
	s->next = parse_args2(argv + 1, nb);
	free(argv[0]);
	return (s);
}

t_stack	*parse_args(char **argv, int *nb)
{
	t_stack	*s;
	t_stack	*next;
	char	**split;

	if (!*argv)
		return (NULL);
	if (!argv[0][0])
		exit_error(NULL, NULL);
	split = ft_split(*argv, ' ');
	s = parse_args2(split, nb);
	free(split);
	next = lstlast(s);
	next->next = parse_args(argv + 1, nb);
	check_double(s);
	return (s);
}