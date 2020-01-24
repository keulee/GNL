/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 12:57:34 by keulee            #+#    #+#             */
/*   Updated: 2020/01/24 18:19:40 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

//#define BUFFER_SIZE 1024

int		main(void)
{
	int		fd;
	char	buf[BUFFER_SIZE];
	int		ret;
	int		i;
	//char	*line;

	fd = open("test2.txt", O_RDONLY);
	if (fd == -1)
		printf("fd error\n");
	else
		printf("fd success, fd is %d\n", fd);
	//get_next_line(fd, &line);
	//initialize buf with 0
	memset(buf, 0x00, BUFFER_SIZE);
	i = 0;
	printf("BUFFER SIZE : %d\n", BUFFER_SIZE);
	while((ret = read(fd, buf, BUFFER_SIZE-1)) > 0)
	{
		buf[ret] = '\0';
		printf("ret is : %d\n", ret);
		printf("%s\n", buf);
		while (i > ret)
		{
			if (buf[i] == '\n')
				break;
			i++;
		}
	}
	close(fd);
	return (0);
}
