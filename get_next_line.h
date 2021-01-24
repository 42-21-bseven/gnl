/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 20:48:09 by hcherrie          #+#    #+#             */
/*   Updated: 2021/01/21 02:11:43 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define NO -1
# define ON 777
# define OFF 666
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_struct
{
	char		*guf;
	char		buf[(BUFFER_SIZE > 2147483646 || BUFFER_SIZE <= 0) ?
	1 : (BUFFER_SIZE + 1)];
	int			len;
	int			n;
	int			j;
	int			power;
	int			ret;
}				t_struct;

int				get_next_line(int fd, char **line);
char			*ft_memcpy(char *dest, char *src, size_t n);
char			*ft_strdup(char *s);
size_t			ft_strlen(char *s);
int				freshka(t_struct *gnl, char *res, int retka);

#endif
