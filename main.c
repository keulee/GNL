/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 12:57:34 by keulee            #+#    #+#             */
/*   Updated: 2020/02/08 21:59:32 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		main(void)
{
	int		fd;
	char	*line;
    int     ret;

	line = NULL;
	fd = open("test2.txt", O_RDONLY);
	while (ret == get_next_line(fd, &line) > 0)
	{
		printf("ret : %d | line : %s\n", ret, line);
	}
    if (ret == 0)
        printf("ret : %d | EOF", ret);
	close(fd);
	return (0);
}
