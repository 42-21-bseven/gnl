/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 20:48:15 by hcherrie          #+#    #+#             */
/*   Updated: 2021/01/20 20:48:16 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_memcpy(char *dest, char *src, size_t n)
{
	char		*d;
	char		*s;

	d = dest;
	s = src;
	if (d == 0 && s == 0)
		return (NULL);
	while (n--)
		*d++ = *s++;
	return (dest);
}

char	*ft_strdup(char *s)
{
	char		*cpy;
	size_t		l;

	l = ft_strlen(s) + 1;
	cpy = malloc(l * sizeof(char));
	if (!cpy)
		return (NULL);
	ft_memcpy(cpy, s, l);
	return ((char *)cpy);
}

size_t	ft_strlen(char *s)
{
	const char *str;

	str = s;
	while (*str)
		str++;
	return (str - s);
}

int		freshka(t_struct *gnl, char *res, int retka)
{
	if (gnl->guf)
		free(gnl->guf);
	if (res)
		free(res);
	gnl->power = OFF;
	return (retka);
}
