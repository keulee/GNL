/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 20:09:58 by keulee            #+#    #+#             */
/*   Updated: 2020/01/25 16:47:36 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned int	ft_end_of_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (1);
	else
		return (0);
}

size_t		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char		*ft_strdup(const char *src)
{
	char	*copy;
	int		i;
	int		len;

	i = 0;
	copy = NULL;
	len = ft_strlen(src);
	if (!(copy = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	new_str_len;
	unsigned int	i;
	unsigned int	j;
	char			*new;

	i = 0;
	j = 0;
	new_str_len = ft_strlen(s1) + ft_strlen(s2);
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(new = (char *)malloc(sizeof(char) * (new_str_len + 1))))
		return (NULL);
	while (s1[i] != '\0')
		new[i++] = (char)s1[j++];
	j = 0;
	while (s2[j] != '\0')
		new[i++] = (char)s2[j++];
	new[i] = '\0';
	return (new);
}

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	char	needle;
	int		i;

	needle = c;
	ptr = (char *)s;
	i = 0;
	while (ptr[i] != '\0')
	{
		if (ptr[i] == c)
			return (ptr + i);
		i++;
	}
	if (ptr[i] == c)
		return (ptr + i);
	return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	unsigned int	i;

	i = 0;
	ptr = (unsigned char *)s;
	if (n == 0)
		return ;
	while (i != n)
	{
		ptr[i] = 0;
		i++;
	}
}
