/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 12:57:34 by keulee            #+#    #+#             */
/*   Updated: 2020/01/31 23:25:21 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		main(void)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open("test2.txt", O_RDONLY);
	while (fd > 0)
	{
		printf("ret : %d\n", get_next_line(fd, &line));
		printf("main line: %s\n", line);
	}
	close(fd);
	return (0);
}
