/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 21:41:53 by anomourn          #+#    #+#             */
/*   Updated: 2024/06/03 21:41:53 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	char			name;
	int				*buffer;
	int				size;
	int				nbr;
	int				head;
	int				tail;
	int				expanded;
	int				group;
	int				place;
	struct s_stack	*next;
}	t_stack;

typedef struct s_lst
{
	void			*value;
	struct s_lst	*next;
}	t_lst;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
	t_lst	op_a;
	t_lst	op_b;
	int		size_a;
	int		size_b;	
}	t_data;

typedef struct s_way
{
	unsigned int	move;
	unsigned char	direction;
}	t_way;

long int	ft_atoi2(const char *str);

void		init(t_stack *s, int size, char name, t_stack *s_tofree);

void		swap(t_stack *s);
void		push(t_stack *s1, t_stack *s2);
void		rotate(t_stack *s);
void		reverse_rotate(t_stack *s);
void		free_stack(t_stack *s);

int			is_digit(char *str);
int			is_int(long int n);
int			is_sorted(t_stack *s);
int			is_sorted_spec(t_stack *s, int ord);

void		sort_3(t_stack *a, t_stack *b);
void		sort_5(t_stack *a);
void		sort_moins_250(t_data *s);
void		sort_plus_250(t_data *s);
void		sort_n_bis(t_data *s);

int			sorted_pos(t_stack *s, int n, t_stack *s_to_free);
int			dist_top(t_stack *s, int i, int *d_tail);
int			s_len(t_stack *s);
int			index_n(t_stack *s, int value);
int			sorted_pos(t_stack *s, int n, t_stack *s_to_free);
int			check_digital(char *s);
int			check_double(t_stack *s);

void		exit_error(t_stack *s1, t_stack *s2);
void		i_at_top(t_stack *a, int i);
void		bubble_sort(int *arr, int dim);
void		swap_s(t_stack *s);
void		push_s(t_stack *s1, t_stack *s2);
void		push_a(t_data *s, int must_print);
void		push_b(t_data *s, int must_print);
void		rotate_a(t_data *s, int must_print);
void		rotate_b(t_data *s, int must_print);
void		reverse_rotate_b(t_data *s, int must_print);
void		reverse_rotate_a(t_data *s, int must_print);
void		reverse_rotate_spec(t_stack *s);
void		rotate_spec(t_stack *s);
void		swap_ab(t_stack *a, t_stack *b);
void		rotate_ab(t_stack *a, t_stack *b);
void		reverse_rotate_ab(t_stack *a, t_stack *b);
void		set_groups(t_stack *s, int nb_of_args);
void		lstadd_back(t_stack **lst, t_stack *new);
void		expand_argv(t_stack *a, char ***argv, int *argc);
void		free_if(char ***argv, t_stack *a);
void		free_matrice(char **mat);

t_way		test_way(t_data *s, unsigned char direction);
t_way		find_way(t_data *s);

t_stack		*get_max(t_stack *s);
t_stack		*get_min(t_stack *s);
t_stack		*parse_args(char **argv, int *nb, int argc);
t_stack		*lstlast(t_stack *lst);
t_stack		*lst_before_last(t_stack *lst);

#endif