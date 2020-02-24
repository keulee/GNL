/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 12:57:34 by keulee            #+#    #+#             */
/*   Updated: 2020/02/24 16:41:33 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		main(void)
{
	int		fd;
	char	*line;
	int		ret;
	int		i;

	i = 0;
	fd = open("test1.txt", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("*%d time | ret : %d | line : %s\n", i++, ret, line);
		free(line);
	}
	if (ret == -1)
		printf("open error");
	if (ret == 0)
	{
		printf("ret : %d | line : %s\n", ret, line);
		free(line);
	}
	close(fd);
	//while (1)
	//	;
	return (0);
}
