#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

// leaks test
/*__attribute__ ((destructor)) void ft_quit(void)
{
	system("leaks a.out");
}*/

int		main(void)
{
	char *line;
	int ret;
	int fd1;
	int fd2;
	int fd3;

	ret = 0;
	fd1 = open("test1", O_RDONLY);
	fd2 = open("test2", O_RDONLY);
	fd3 = open("test3", O_RDONLY);
	while ((ret = get_next_line(fd1, &line)) > 0)
	{
		printf("%d %s\n", ret, line);
		free(line);
	}
	printf("%d %s\n", ret, line);
	free(line);
	close(fd1);

	while ((ret = get_next_line(fd2, &line)) > 0)
	{
		printf("%d %s\n", ret, line);
		free(line);
	}
	printf("%d %s\n", ret, line);
	free(line);
	close(fd2);

	while ((ret = get_next_line(fd3, &line)) > 0)
	{
		printf("%d %s\n", ret, line);
		free(line);
	}
	printf("%d %s\n", ret, line);
	free(line);
	close(fd3);

//leaks test
	system("leaks a.out");
	return (0);
}
