#include "get_next_line.h"
#include <stdio.h>

char		**ft_line(char *str, char **line, char *tmp)
{
	unsigned int	i;
	char					*saveline;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	saveline = ft_substr(str, 0, i);
	if (*line == NULL)
		*line = ft_strdup(saveline);
	else
	{
		*line = ft_strjoin(tmp, saveline);
		free(saveline);
		//free(tmp);
	}
	return (line);
}

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

int			get_next_line(int fd, char **line)
{
	int					ret;
	char				buf[BUFFER_SIZE+1];
	char				*str;
	static char *tmp;
	char				*tmp_line;

	str = NULL;
	if (fd < 0 || line == NULL || (read(fd, buf, 0)) < 0)
	{
		printf("fd Open Error\n");
		return (-1);
	}
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (str == NULL)
			str = ft_strdup(buf);
		else
		{
			tmp_line = str;
			str = ft_strjoin(str, buf);
			free(tmp_line);
		}
		if (ft_strchr(buf, '\n') == 1)
			break;
	}
	line = ft_line(str, line, tmp);
	tmp = ft_save_the_rest(str, tmp);
	return (1);
	if (ret == 0)
	{
		*line = ft_strdup("");
		printf("EOF");
		return (0);
	}
}
