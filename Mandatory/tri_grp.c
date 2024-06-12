/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_grp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:25:29 by anomourn          #+#    #+#             */
/*   Updated: 2024/06/12 18:51:25 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*pre_tri(t_stack *s, int nb_arg)
{
	int			*tri;
	int			i;
	int			index;
	t_stack		*tmp;

	tri = ft_calloc(nb_arg, sizeof(int));
	tmp = s;
	i = get_min(s)->nbr;
	index = 0;
	while (index < nb_arg)
	{
		while (s)
		{
			if (s->nbr == i)
				tri[index++] = s->nbr;
			s = s->next;
		}
		s = tmp;
		i++;
	}
	return (tri);
}

void	set_place(t_stack *s, int nb_arg)
{
	t_stack		*tmp;
	int			*tri;
	int			place;
	int			i;

	i = 0;
	tmp = s;
	tri = pre_tri(s, nb_arg);
	place = -1;
	while (i++ < nb_arg)
	{
		place = -1;
		while (++place < nb_arg)
			if (tri[place] == s->nbr)
				break ;
		s->place = place;
		s = s->next;
	}
	free(tri);
	s = tmp;
}

void	set_groups(t_stack *s, int nb_arg)
{
	int		ind_piv1;
	int		ind_piv2;
	t_stack	*tmp;

	set_place(s, nb_arg);
	//printf("%d\n", nb_arg);
	ind_piv1 = nb_arg / 3;
	ind_piv2 = ind_piv1 * 2;
	tmp = s;
	while (s)
	{
		if (s->place <= ind_piv1)
			s->group = 0;
		else if (s->place > ind_piv1 && s->place < ind_piv2)
		{
			s->group = 1;
			//printf("%d\n", s->place);
		}
		else
			s->group = 2;
		s = s->next;
	}
	s = tmp;
}
