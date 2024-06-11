/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 09:57:20 by anomourn          #+#    #+#             */
/*   Updated: 2024/06/11 09:57:22 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*compare le premier "n" nbr de bytes entre 2 str et
return 0 si les deux sont egaux, ou alors la difference
entre les caracteres ascii du premier caractere different
s'ils ne sont pas egaux.*/
int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && n > i + 1)
		i += 1;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
