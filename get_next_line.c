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

int		ft_line(char *str, char **line, int ret)
{
	int		i;

	i = 0;
    if (str != NULL)
    {
        while (str[i] != '\0' && str[i] != '\n')
            i++;
    }
	if (str != NULL && str[i] == '\n')
    {
		*line = ft_substr(str, 0, i);
        return (1);
    }
    if (ret == 0 && str == NULL)
    {
        *line = ft_strdup("");
        return (0);
    }
    if (ret == 0 && str[i] == '\0')
    {
        *line = ft_strdup(str);
        return (0);
    }
    return (1);
}

char	*ft_rest(char *str)
{
	int		i;
	int		str_len;;
    char    *tmp;

	i = 0;
	str_len = ft_strlen(str);
    if (str != NULL)
    {
        while (str[i] != '\0' && str[i] != '\n')
            i++;
    }
    if (str[i] == '\n')
    {
        if ((str_len - i - 1 == 0) && str != NULL) 
        {
            free(str);
            str = NULL;
        }
        else
        {
            tmp = str;
            str = ft_substr(str, i + 1, str_len - i - 1);
            free(tmp);
        }
    }
	return (str);
}

char    *ft_read_line(char *str, int fd)
{
    int ret;
    char buf[BUFFER_SIZE + 1];
    char *tmp;

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
    return (str);
}

int		get_next_line(int fd, char **line)
{
	int			len;
	//char		buf[BUFFER_SIZE + 1];
	static char	*str;
	//char		*tmp;
    int         value;

	if (fd < 0 || line == NULL || BUFFER_SIZE == 0)
		return (-1);
    str = ft_read_line(str, fd);
    len = ft_strlen(str);
	/*while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
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
	}*/
    value = ft_line(str, line, len);
    if (value == 1)
    {
		str = ft_rest(str);
        return (1);
    }
    if (value == 0)
    {
        str = NULL;
        return (0);
    }
	return (1);
}
