/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:15:00 by anomourn          #+#    #+#             */
/*   Updated: 2023/10/17 12:35:27 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*b;
	char	*l;
	size_t	i;
	size_t	k;

	b = (char *)big;
	l = (char *)little;
	i = 0;
	if (l[i] == '\0')
		return (b);
	while (b[i] != '\0')
	{
		k = 0;
		while (b[i + k] == l[k] && i + k < len)
		{
			if (b[i + k] == '\0' || l[k++] == '\0')
				break ;
		}
		if (l[k++] == '\0')
			return (&b[i]);
		i++;
	}
	return (0);
}
