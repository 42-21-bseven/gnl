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
//		if (gnl->flag != BKL)
//			gnl->guf = res;
//		if (!gnl->ret || !gnl->flag)
//			return ((char *) res);
	}
//	if (!s1 || !s2)
//		return (NULL);
	res = gnl->guf;
	i = (gnl->len + (gnl->n == -1 ? gnl->j : -(gnl->n + 1))) + 1;
//	printf("i:%d\n", i);
//	printf("j:%d\n", gnl->j);
//	printf("n:%d\n", gnl->n);
//	printf("len:%d\n", gnl->len);
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
//	printf("DDD:%s\n", gnl->guf);
	gnl->guf[i] = '\0';
	free(res);
	return (1);
}

//static char	*ft_strdup(const char *s)
//{
//	const char	*cpy;
//	size_t		l;
//
//	l = ft_strlen(s) + 1;
//	cpy = malloc(l * sizeof(char));
//	if (!cpy)
//		return (NULL);
//	ft_memcpy((void *)cpy, s, l);
//	return ((char *)cpy);
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
//	printf("gnlFFF111:%d\n", gnl.flag);
	gnl_null(&gnl);
//	printf("gnlFFF222:%d\n", gnl.flag);
//	if (gnl->flag == 777)
//	{
//		strlen_gnl(gnl);
//		if (gnl->n != -1)
//		{
//			gnl->guf[gnl->n] = '\0';
//			*line = ft_strdup(gnl->guf);
//			gnl->eof = 1;
//			ft_strjoin(gnl);
//			return (1);
//		}
//	}
//	printf("%d\n", gnl.ret);
//	printf("%s\n", gnl.guf);
//	while(gnl.ret && (gnl.j = read(fd, gnl.buf, BUFFER_SIZE)))
	while(gnl.ret)
	{
		if (gnl.flag == BKL)
			strlen_gnl(&gnl);
		if (gnl.eof && (gnl.n == -1 || !gnl.flag))
		{
			gnl.j = read(fd, gnl.buf, BUFFER_SIZE);
			if (gnl.j == -1)
				return (-1);//(freeshka(gnl)); //зафришить если BKL
			gnl.buf[gnl.j] = '\0';
//			if (!(read(fd, gnl.test[0], 0)))
			if (gnl.j < BUFFER_SIZE)
				gnl.eof = 0;
		}
//		gnl.flag = (!gnl.flag && !gnl.j) ? 666 : gnl.flag;
//		printf("%d\n%d\n%d\n", gnl.n, gnl.len, gnl.flag);
//		gnl->len = gnl->flag != BKL ? gnl->j : gnl->len;
//		printf("str0:\n%s|\n", gnl.guf);
//		if (gnl.flag == BKL)
//			strlen_gnl(&gnl);
//		if ((gnl.n == -1 || !gnl.flag) && gnl.j > 0)
//		if (!gnl.flag || gnl.n < 0 || (!gnl.n && gnl.flag == BKL))
		if (!gnl.flag || (gnl.eof && gnl.n == -1) || !gnl.eof && gnl.j >=0)
			if (!ft_strjoin(&gnl))
				return (-1);//(freeshka(gnl));
//		printf("%d\n", gnl->ret);
//		printf("SUPPERstr0:\n%s|\n", gnl.guf);
		strlen_gnl(&gnl);
//		if (gnl.j < BUFFER_SIZE && gnl.n == -1)
		if (!gnl.eof && gnl.n == -1)
			gnl.ret = 0;
//		printf("n:%d\nlen:%d\neof:%d\n", gnl.n, gnl.len, gnl.eof);
		if (gnl.n != -1)
		{
			gnl.guf[gnl.n] = '\0';
			break ;
		}
//		if (!ft_strjoin(gnl))
//			return (freeshka(gnl));
	}
//	printf("str1:%s\n", gnl.guf);
	*line = ft_strdup(gnl.guf);
//	printf("btr:%s\n", gnl->buf);
//	printf("%d\n", gnl.ret);
	if (!gnl.ret) {
		gnl.flag = 666;
		free(gnl.guf);
	}
	else // поменять на ret;
		ft_strjoin(&gnl);
//	free(gnl);
//	printf("str2:%s\n", gnl.guf);
	return (gnl.ret);
}