/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukmournard <anoukmournard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:27:00 by anomourn          #+#    #+#             */
/*   Updated: 2024/06/11 20:40:35 by anoukmourna      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>

struct s_ogg
{
	int		i;
	int		cont;
	int		indice;
	int		opz;
	int		ottenuto;
	int		poss;
	char	*str;
	char	charset;
};

void	*ft_memset(void *str, int c, size_t len);
void	*ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strnstr(const char *big, const char *little, size_t len);

int		ft_atoi(const char *nptr);
int		ft_strncmp(char *s1, char *s2, size_t n);
int		ft_strcmp(char *s1, char *s2);

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

char	**ft_split(char const *s, char c);
char	*get_next_line(int fd);

size_t	ft_strlen(const char *str);

#endif
