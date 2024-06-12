/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 22:28:47 by anoukmourna       #+#    #+#             */
/*   Updated: 2024/06/12 12:53:12 by anomourn         ###   ########.fr       */
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

int	check_double(t_stack *s)
{
	t_stack	*tmp;

	while (s)
	{
		tmp = s->next;
		while (tmp)
		{
			if (tmp->nbr == s->nbr)
				return (0);
			tmp = tmp->next;
		}
		s = s->next;
	}
	return (1);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int check_digital(char *s)
{
	int i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == '-' || s[i] == '+')
		{
			if (s[i + 1] && !ft_isdigit(s[i + 1]))
				return (0);
		}
		else if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
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

t_stack	*parse_args(char **argv, int *nb, int argc)
{
	t_stack	*s;
	t_stack	*next;

	s = NULL;
	if (!*argv)
		return (NULL);
	if (!argv[0][0])
		exit_error(NULL, NULL);
	if (check_digital(*argv) == 0)
	{
		if (argc == 2)
			free_matrice(argv);
		exit_error(s, NULL);
	}
	s = parse_args3(ft_atoi(*argv));
	if (check_double(s) == 0)
	{
		if (argc == 2)
			free_matrice(argv);
		exit_error(s, NULL);
	}
	*nb += 1;
	next = lstlast(s);
	next->next = parse_args(argv + 1, nb, argc);
	return (s);
}
