/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 20:09:16 by keulee            #+#    #+#             */
/*   Updated: 2020/01/30 19:13:16 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		get_next_line(int fd, char **line)
{
	int		ret;
	char	buf[BUFFER_SIZE+1];
	char	*str;
	int		i;

	i = 1;
	str = NULL;
	//bzero(buf, BUFFER_SIZE);
	if (fd < 0 || line == NULL)
	{
		printf("fd Open Error\n");
		return (-1);
	}
	/*if ((ret = read(fd, buf, BUFFER_SIZE)) == 0)
	{
		printf("End Of File\n");
		return (0);
	}*/
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		printf("%d try\n", i++);
		printf("ret = %d\n", ret);
		printf("buf = %s\n", buf);
		if (str == NULL)
			str = ft_strdup(buf);
		else
			str = ft_strjoin(str, buf);
		printf("str phrase = %s\n", str);
		if (ft_strchr(buf, '\n') == 1)
			break;
	}
	if (ret == 0)
		return (0);
	return (1);
}
