/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bseven <bseven@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 01:02:30 by bseven            #+#    #+#             */
/*   Updated: 2020/11/18 16:54:30 by bseven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *n)
{
	int		s;
	long	r;

	s = 1;
	r = 0;
	while (*n == 32 || (*n >= 9 && *n <= 13))
		n++;
	if (*n == '-')
		s = s * -1;
	if (*n == '-' || *n == '+')
		n++;
	while (*n >= '0' && *n <= '9')
	{
		r = r * 10 + (*n - '0');
		n++;
		if ((r * s) > 2147483647)
			return (-1);
		if ((r * s) < -2147483648)
			return (0);
	}
	return (r * s);
}