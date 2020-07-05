/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarvalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 13:21:34 by jcarvalh          #+#    #+#             */
/*   Updated: 2020/02/13 18:06:05 by jcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	int		len;
	int		i;

	i = 0;
	p = (char *)malloc(count * size);
	len = count * size;
	if (!p)
		return (NULL);
	while (len)
	{
		*(p + i) = 0;
		i++;
		len--;
	}
	return (p);
}

void	ft_delstr(char **c)
{
	if (c != NULL)
	{
		free(*c);
		*c = NULL;
	}
}

int		copy(char **line, char **s, int fd)
{
	int		i;
	char	*aux;

	i = 0;
	while (s[fd][i] != '\n' && s[fd][i] != '\0')
		i++;
	if (s[fd][i] == '\n')
	{
		*line = ft_substr(s[fd], 0, i);
		aux = ft_strdup(&s[fd][i + 1]);
		free(s[fd]);
		s[fd] = aux;
		if (s[fd][0] == '\0')
			ft_delstr(&s[fd]);
	}
	else
	{
		*line = ft_strdup(s[fd]);
		ft_delstr(&s[fd]);
		return (0);
	}
	return (1);
}

int		check(int ret, char **line, char **s, int fd)
{
	if (ret < 0)
		return (-1);
	if (ret == 0 && s[fd] == NULL)
	{
		*line = ft_calloc(1, 1);
		return (0);
	}
	return (copy(line, s, fd));
}

int		get_next_line(int fd, char **line)
{
	char		*buff;
	static char	*s[OPEN_MAX];
	char		*aux;
	int			resp;

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0)
		return (-1);
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(*buff));
	while ((resp = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[resp] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strdup(buff);
		else
		{
			aux = ft_strjoin(s[fd], buff);
			free(s[fd]);
			s[fd] = aux;
		}
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	ft_delstr(&buff);
	return (check(resp, line, s, fd));
}
