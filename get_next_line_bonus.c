/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 22:12:09 by keulee            #+#    #+#             */
/*   Updated: 2020/02/24 17:06:37 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int			ft_line(char *str[FD_MAX], char **line, int ret, int fd)
{
	int		i;

	i = 0;
	if (str[fd] != NULL)
	{
		while (str[fd][i] != '\0' && str[fd][i] != '\n')
			i++;
	}
	if (str[fd] != NULL && str[fd][i] == '\n')
		*line = ft_substr(str[fd], 0, i);
	if (ret == 0 && str[fd] == NULL)
	{
		*line = ft_strdup("");
		return (0);
	}
	if (ret == 0 && str[fd][i] == '\0')
	{
		*line = ft_strdup(str[fd]);
		return (0);
	}
	return (1);
}

char		*ft_rest(char *str[FD_MAX], int fd)
{
	int		i;
	int		str_len;
	char	*tmp;

	i = 0;
	str_len = ft_strlen(str[fd]);
	if (str[fd] != NULL)
	{
		while (str[fd][i] != '\0' && str[fd][i] != '\n')
			i++;
	}
	if (str[fd][i] == '\n' && str[fd] != NULL)
	{
		tmp = str[fd];
		str[fd] = ft_substr(str[fd], i + 1, str_len - i - 1);
		free(tmp);
	}
	return (str[fd]);
}

char		*ft_read_line(char *str[FD_MAX], int fd, int *ret)
{
	char	buf[BUFFER_SIZE + 1];
	char	*tmp;

	while ((*ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[*ret] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strdup(buf);
		else
		{
			tmp = str[fd];
			str[fd] = ft_strjoin(str[fd], buf);
			free(tmp);
		}
		if (ft_strchr(str[fd], '\n') == 1)
			break ;
	}
	return (*str);
}

int			get_next_line(int fd, char **line)
{
	int				ret;
	static char		*str[FD_MAX];
	int				value;

	if (fd < 0 || line == NULL || BUFFER_SIZE == 0 || fd > FD_MAX)
		return (-1);
	str[fd] = ft_read_line(&str[fd], fd, &ret);
	if (ret < 0)
		return (-1);
	value = ft_line(&str[fd], line, ret, fd);
	if (value == 1)
		str[fd] = ft_rest(&str[fd], fd);
	if (value == 0)
	{
		free(str[fd]);
		str[fd] = NULL;
		return (0);
	}
	return (1);
}
