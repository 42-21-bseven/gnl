//
// Created by aleksandr on 17.01.2021.
//

#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = dest;
	s = src;
	if (d == 0 && s == 0)
		return (NULL);
	while (n--)
	{
		*d++ = *s++;
	}
	return (dest);
}

char	*ft_strdup(const char *s)
{
	const char	*cpy;
	size_t		l;

	l = ft_strlen(s) + 1;
	cpy = malloc(l * sizeof(char));
	if (!cpy)
		return (NULL);
	ft_memcpy((void *)cpy, s, l);
	return ((char *)cpy);
}

size_t	ft_strlen(const char *s)
{
	const char *str;

	str = s;
	while (*str)
		str++;
	return (str - s);
}
