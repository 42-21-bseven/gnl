//
// Created by aleksandr on 17.01.2021.
//

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		n;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	while ((n = get_next_line(&line, fd)) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	if (!n)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}