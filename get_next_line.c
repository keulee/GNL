/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 20:09:16 by keulee            #+#    #+#             */
/*   Updated: 2020/02/08 21:57:36 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/*char		**ft_line(char *str, char **line)
{
	unsigned int	i;
	//char			*saveline;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
    if (i == 0)
        (*line) = ft_strdup("");
    /*if ()
   else
    {
        *line = ft_substr(str, 0, i);
        str = &str[i + 1];
    }
    printf("static str : %s\n", str);
    if (*line == NULL)
		*line = ft_strdup(saveline);
	else
		*line = ft_strjoin(tmp, saveline);
    
	return (line);
}*/

char		*ft_save_the_rest(char *str, char *tmp)
{
	unsigned int		i;
	unsigned int		j;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	j = ft_strlen(&str[i]);
	tmp = ft_substr(str, i + 1, j);
	return (tmp);
}

char        *ft_read_the_line(char *str, int fd)
{
    int     ret;
    char    buf[BUFFER_SIZE+1];
    char    *tmp;

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
        if(ft_strchr(buf, '\n') == 1)
            break;
    }
    return (str);
}

int			get_next_line(int fd, char **line)
{
	char				*str;
	static char         *tmp;

    str = NULL;
	if (fd < 0 || line == NULL || BUFFER_SIZE == 0)
		return (-1);
    str = ft_read_the_line(str, fd);

	line = ft_line(str, line);
	tmp = ft_save_the_rest(str, tmp);
	return (1);
	/*if (ret == 0)
	{
		printf("EOF");
		return (0);
	}*/
}
