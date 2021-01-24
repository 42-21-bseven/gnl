//
// Created by aleksandr on 17.01.2021.
//

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		n;
	char	*line;

//	fd = open("/Users/bseven/GNL/Gnl_Mac/get_next_lines/jdlkasdsd", O_RDONLY);
//	fd = open(argv[1], O_RDONLY);
	while ((n = get_next_line(1, &line)) > 0)
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
