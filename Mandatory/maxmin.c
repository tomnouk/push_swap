#include "push_swap.h"

t_stack	*get_min(t_stack *lst)
{
	t_stack	*min;

	min = lst;
	while (lst)
	{
		if (lst->nbr < min->nbr)
			min = lst;
		lst = lst->next;
	}
	return (min);
}

t_stack *get_max(t_stack *lst)
{
	t_stack *max;

	max = lst;
	while (lst)
	{
		if (lst->nbr > max->nbr)
			max = lst;
		lst = lst->next;
	}
	return (max);
}
