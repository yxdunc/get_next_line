/* *********************** */
/*                         */
/*  Robin Guignard-Perret  */
/*                   @42   */
/* *********************** */

/* test main */


#include "gnl.h"
#include <fcntl.h>
#include <stdlib.h>

int		main(int argc, char **argv)
{
	char	*line;
	int		fd;

	fd = (argc == 2) ? open(argv[1], O_RDONLY) : 0;
	while (get_next_line(fd, &line))
	{
		ft_putendl(line);
		free(line);	
	}
	if (argc != 1)
		close(fd);
	return (0);
}
