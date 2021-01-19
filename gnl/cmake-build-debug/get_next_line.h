//
// Created by aleksandr on 17.01.2021.
//

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define NO -1
# define BKL 777
# define NULL_TERMINATOR 2

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

int		get_next_line(char **line, int fd);
void 	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);

typedef struct	s_struct
{
	char		*guf;
	char 		buf[BUFFER_SIZE + 1];
	int			len;
	int			n;
	int 		j;
	int			flag;
	int 		ret;
	int			eof;
}				t_struct;

#endif