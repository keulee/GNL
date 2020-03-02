/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 20:09:16 by keulee            #+#    #+#             */
/*   Updated: 2020/02/21 17:15:12 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//function that fill the line with substr(malloc), strdup(malloc)
//
int			ft_line(char *str, char **line, int ret)
{
	int		i;

	i = 0;
	if (str != NULL) // protect
	{
		while (str[i] != '\0' && str[i] != '\n')
			i++;
	}
	if (str != NULL && str[i] == '\n') // general case
		*line = ft_substr(str, 0, i);
	if (ret == 0 && str == NULL) // empty line after \n
	{
		*line = ft_strdup("");
		return (0);
	}
	if (ret == 0 && str[i] == '\0') // last line 
	{
		*line = ft_strdup(str);
		return (0);
	}
	return (1);
}

// function that put the string after \n in str
//
char		*ft_rest(char *str)
{
	int		i;
	int		str_len;
	char		*tmp;

	i = 0;
	str_len = ft_strlen(str);
	if (str != NULL)
	{
		while (str[i] != '\0' && str[i] != '\n')
			i++;
	}
	if (str[i] == '\n' && str != NULL)
	{
		tmp = str;
		str = ft_substr(str, i + 1, str_len - i - 1);
		free(tmp);
	}
	return (str);
}

// function with read.
// with this function fine the one whole line with \n.
//
char		*ft_read_line(char *str, int fd, int *ret)
{
	char	buf[BUFFER_SIZE + 1];
	char	*tmp;

	while ((*ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[*ret] = '\0';
		if (str == NULL)
			str = ft_strdup(buf);
		else
		{
			tmp = str;
			str = ft_strjoin(str, buf);
			free(tmp);
		}
		if (ft_strchr(str, '\n') == 1)
			break ;
	}
	return (str);
}

// function get_next_line.
//
int			get_next_line(int fd, char **line)
{
	int			ret;
	static char		*str;
	int			value;

	if (fd < 0 || line == NULL || BUFFER_SIZE == 0)
		return (-1);
	str = ft_read_line(str, fd, &ret);
	if (ret < 0)
		return (-1);
	value = ft_line(str, line, ret);
	if (value == 1)
		str = ft_rest(str);
	if (value == 0)
	{
		free(str);
		str = NULL;
		return (0);
	}
	return (1);
}
