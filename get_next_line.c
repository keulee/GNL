/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 20:09:16 by keulee            #+#    #+#             */
/*   Updated: 2020/02/19 17:46:36 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		ft_line(char *str, char **line)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str && str[i] != '\0')
	{
		*line = ft_substr(str, 0, i);
		return (1);
	}
	return (0);
}

int		ft_eof(char *str, int ret, char **line)
{
	int i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (ret == 0 && (!str))
	{
		*line = ft_strdup("");
	}
	if (ret == 0 && str[i] == '\0')
	{
		*line = ft_strdup(str);
		free(str);
	}
	return(0);
}

char	*ft_rest(char *str)
{
	int		str_n;
	int		str_len;

	str_n = 0;
	str_len = ft_strlen(str);
	while (str[str_n] != '\0' && str[str_n] != '\n')
		str_n++;
	if (str[str_n] == '\n' && str[str_n] != '\0')
		str = ft_substr(str, str_n + 1, str_len);
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
		buf[ret] = '\0';
		if (str == NULL)
			str = ft_strdup(buf);
		else
		{
			tmp = str;
			str = ft_strjoin(str, buf);
			free(tmp);
		}
		if (ft_strchr(str, '\n') == 1)
			break;
	}
	if(ft_line(str, line) == 1)
	{
		str = ft_rest(str);
		return (1);
	}
	if (ft_eof(str, ret, line) == 0)
	{
		str = NULL;
		return (0);
	}
	return (1);
}
