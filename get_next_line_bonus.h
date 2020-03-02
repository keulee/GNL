/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 22:20:13 by keulee            #+#    #+#             */
/*   Updated: 2020/02/24 16:47:26 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# define FD_MAX 256

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *src);
char	*ft_strjoin(const char *s1, const char *s2);
int		ft_strchr(const char *s, int c);
char	*ft_substr(const char *str, unsigned int start, size_t len);

#endif
