/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:02:08 by anomourn          #+#    #+#             */
/*   Updated: 2024/06/12 21:38:37 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(t_stack *s1, t_stack *s2)
{
	write(2, "Error\n", 6);
	if (s1)
	{
		free(s1->buffer);
		free(s1);
	}
	if (s2)
	{
		free(s2->buffer);
		free(s2);
	}
	exit(EXIT_FAILURE);
}

void	free_if(char ***argv, t_stack *a)
{
	int	i;

	if (a->expanded)
	{
		i = 0;
		while ((*argv)[i])
		{
			free((*argv)[i]);
			i++;
		}
		free(*argv);
	}
}

void	free_stack(t_stack *s)
{
	t_stack	*tmp;

	while (s)
	{
		tmp = s;
		s = s->next;
		free(tmp);
	}
}

void	free_matrice(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
	{
		free(mat[i]);
		i++;
	}
	free(mat);
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
