/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarvalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 17:15:00 by jcarvalh          #+#    #+#             */
/*   Updated: 2020/02/11 18:27:56 by jcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*resp;
	int		i;

	i = 0;
	if (!(resp = malloc((len + 1) * sizeof(char))))
		return (NULL);
	resp[len] = '\0';
	while (len > 0 && s[start + i] != '\0')
	{
		resp[i] = s[start + i];
		i++;
		len--;
	}
	return (resp);
}

int		ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*resp;
	int		i;
	int		j;

	if (!(resp = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(s1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i] != '\0')
	{
		resp[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2 && s2[i] != '\0')
	{
		resp[j] = s2[i];
		i++;
		j++;
	}
	resp[j] = '\0';
	return (resp);
}

char	*ft_strdup(const char *s1)
{
	char	*new;
	int		i;

	new = malloc((ft_strlen(s1) + 1) * sizeof(s1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return ((char*)new);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
		{
			return (char*)s;
		}
		s++;
	}
	if (c == '\0')
		return (char*)s;
	return (0);
}
