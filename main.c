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

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

//#define BUFFER_SIZE 1024

int		main(void)
{
	int		fd;
	char	buf[BUFFER_SIZE+1];
	char	*tmp;
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
	//memset(buf, 0x00, BUFFER_SIZE);
	ft_bzero(buf, 0);
	printf("BUFFER SIZE : %d\n", BUFFER_SIZE);
	tmp = NULL;
	while((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		i = 0;
		buf[ret] = '\0';
		printf("*******************************\n");
		printf("ret is : %d\n", ret);
		if (tmp == NULL)
			tmp = ft_strdup(buf);
		else
			tmp = ft_strjoin(tmp, buf);
		printf("==str is : %s\n", tmp);
		//printf("--buf is : %s\n", buf);
		printf("******************************\n");
		if (ft_strchr(buf, '\n'))
			break;
	}

	printf("**total line : %s\n", tmp);
	close(fd);
	return (0);
}
