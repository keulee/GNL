/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 20:09:16 by keulee            #+#    #+#             */
/*   Updated: 2020/01/31 23:25:57 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char		**ft_have_line(char *str, char **line)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	*line = ft_substr(str, 0, i);
	return (line);
}

int			get_next_line(int fd, char **line)
{
	int		ret;
	char	buf[BUFFER_SIZE+1];
	char	*str;

	str = NULL;
	if (fd < 0 || line == NULL)
	{
		printf("fd Open Error\n");
		return (-1);
	}
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		//printf("str = %s\n", str);
		//printf("ret = %d\n", ret);
		//printf("buf = %s\n", buf);
		if (str == NULL)
			str = ft_strdup(buf);
		else
			str = ft_strjoin(str, buf);
		//printf("str phrase = %s\n", str);
		if (ft_strchr(buf, '\n') == 1)
			break;
	}
	ft_have_line(str, line);
	//printf("line : %s\n", line);
	return (1);
	if (ret == 0)
	{
		printf("EOF");
		return (0);
	}
}
