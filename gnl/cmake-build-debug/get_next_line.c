//
// Created by aleksandr on 17.01.2021.
//

#include "get_next_line.h"

static int	ft_strjoin(t_struct *gnl)
{
	int		i;
	int		j;
	char	*res;

	if (gnl->flag != BKL)
	{
		if (!(gnl->guf = malloc(gnl->j + 1 * sizeof(char))))
			return (0);
		ft_memcpy((void *)gnl->guf, gnl->buf, gnl->j + 1);
		return (1);
	}
	res = gnl->guf;
	i = (gnl->len + (gnl->n == -1 ? gnl->j : -(gnl->n + 1))) + 1;
	if (!(gnl->guf = malloc(i * sizeof(char))))
	{
		if (res)
			free(res);
		return (0);
	}
	i = 0;
	j = 0;
	while (gnl->n == -1 && res[i])
	{
		gnl->guf[i] = res[i];
		i++;
	}
	if (gnl->n == -1)
		while (gnl->buf[j])
			gnl->guf[i++] = gnl->buf[j++];
	else
		while (res[++gnl->n])
			gnl->guf[i++] = res[gnl->n];
	gnl->guf[i] = '\0';
	free(res);
	return (1);
}

//static char	*ft_strdup(const char *s)
//{
//}

static void	strlen_gnl(t_struct *gnl)
{
	int i;

//	if (!str)
//		return (0);
	i = 0;
	while (gnl->guf[i] && gnl->guf[i] != '\n')
		i++;
	gnl->n = gnl->guf[i] ? i : -1;
	while (gnl->guf[i])
		i++;
	gnl->len = i;
	gnl->flag = BKL;
//	if (spec == BSH_N)
//	{
//	}
//	else if (spec == NULL_TERMINATOR) {
//	}
}

static void gnl_null(t_struct *gnl)
{
	int i;

	i = 0;
	gnl->len = 0;
	gnl->j = -2;
	gnl->n = 0;
	if (gnl->flag != BKL)
	{
		gnl->eof = 1;
		gnl->ret = 1;
		gnl->flag = 0;
		gnl->guf = NULL;
	}
//	while (i < (BUFFER_SIZE + 1))
//		gnl->buf[i++] = '\0';
}

int	get_next_line(char **line, int fd)
{
	static t_struct gnl;

	if (BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647 || !fd || !line)
		return (-1);
	gnl_null(&gnl);
	while(gnl.ret)
	{
		gnl.flag == BKL ? strlen_gnl(&gnl) : 0;
		if (gnl.eof && (gnl.n == -1 || !gnl.flag))
		{
			gnl.j = read(fd, gnl.buf, BUFFER_SIZE);
			if (gnl.j == -1)
				return (-1);//(freeshka(gnl)); //зафришить если BKL
			gnl.buf[gnl.j] = '\0';
			if (gnl.j < BUFFER_SIZE)
				gnl.eof = 0;
		}
		if (!gnl.flag || (gnl.eof && gnl.n == -1) || !gnl.eof && gnl.j >=0)
			if (!ft_strjoin(&gnl))
				return (-1);//(freeshka(gnl));
		strlen_gnl(&gnl);
		if (!gnl.eof && gnl.n == -1)
			gnl.ret = 0;
		if (gnl.n != -1)
		{
			gnl.guf[gnl.n] = '\0';
			break ;
		}
	}
	*line = ft_strdup(gnl.guf);
	if (!gnl.ret && (gnl.flag = 666))
		free(gnl.guf);
	else // поменять на ret;
		ft_strjoin(&gnl);
	return (gnl.ret);
}