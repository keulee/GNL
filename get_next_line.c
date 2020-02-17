/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 20:09:16 by keulee            #+#    #+#             */
/*   Updated: 2020/02/16 04:03:23 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		ft_line(char *str, char **line, int ret)
{
	int		i;

	i = 0;
	if (str)
	{
		while (str[i] != '\0' && str[i] != '\n')
			i++;
	}
	if (str[i] == '\n' && str[i] != '\0')
	{
		*line = ft_substr(str, 0, i);
		return (1);
	}
	if (str[i] == '\n' && str[ret] == '\0')
	{
		*line = ft_strdup("");
		return (1);
	}
	return (0);
}

int		ft_eof(char *str, int ret, char **line)
{
	if (ret == 0 && (!str[ret] || str[0] == '\0'))
	{
		*line = ft_strdup("");
		return (0);
	}
	return(1);
}

char	*ft_rest(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(str);
	if (str)
	{
		while (str[i] != '\0' && str[i] != '\n')
		i++;
	}
	if (str[i] == '\n' && str[i] != '\0')
		str = ft_substr(str, i + 1, j);
//	printf("str in ft_rest : %s\n", str);
	return (str);
}

int		get_next_line(int fd, char **line)
{
	int			ret;
	char		buf[BUFFER_SIZE + 1];
	static char	*str;
	char		*tmp;

	if (fd < 0 || line == NULL || BUFFER_SIZE == 0)
		return (-1);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		//printf("ret: %d\n", ret);
		buf[ret] = '\0';
		//printf("buf : %s\n", buf);
		if (str == NULL)
			str = ft_strdup(buf);
		else
		{
			tmp = str;
			str = ft_strjoin(str, buf);
			free(tmp);
		}
		if (ft_strchr(buf, '\n') == 1)
			break;
	}
	//printf("str1 : %s\n", str);
	if(ft_line(str, line, ret) == 1)
	{
		str = ft_rest(str);
	//	printf("str2 : %s\n", str);
		return (1);
	}
	if (ft_eof(str, ret, line) == 0)
		return (0);
	return (1);
}
