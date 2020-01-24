/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 20:09:16 by keulee            #+#    #+#             */
/*   Updated: 2020/01/23 16:57:17 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

int		get_next_line(int fd, char **line)
{
	int		ret;
	void	*buf;
	char	buff;
	/*
	** error : -1
	*/
	if (fd < 0 || line == NULL)
		return (-1);

	/*
	** file read : 1
	*/
	buff = (char *)buf;
	else if
		while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
		{
			buff[ret] = '\0';
			printf("ret = %d\n", ret);
			printf("phrase = %s\n", buff);
			if (ft_end_of_line(buff) == 1)
				break;
		}
		return (1);

	/*
	** file EOF : 0
	*/
	else if (ret = read(fd, buff, BUFFER_SIZE) == 0)
		return (0);

}
