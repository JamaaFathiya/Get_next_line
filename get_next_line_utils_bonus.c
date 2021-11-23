/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:53:16 by fathjami          #+#    #+#             */
/*   Updated: 2021/11/23 13:54:01 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;
	unsigned int	j;

	if (!s)
		return (0);
	if (len >= ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	i = start;
	j = 0;
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (0);
	while (s[i] && j < len)
		res[j++] = s[i++];
	res[j] = '\0';
	return (res);
}

char	*ft_strjoin(char **s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	if (!(*s1) || !s2)
		return (0);
	i = 0;
	res = malloc((ft_strlen(*s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (0);
	j = 0;
	while ((*s1)[j])
		res[i++] = (*s1)[j++];
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	free (*s1);
	*s1 = NULL;
	return (res);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dest;

	i = 0;
	dest = 0;
	while (s1[i])
		i++;
	dest = (char *) malloc((i + 1) * sizeof(char));
	i = 0;
	if (dest != 0)
	{
		while (s1[i])
		{
			dest[i] = s1[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		*((unsigned char *) b + i++) = (unsigned char )c;
	return (b);
}

int	ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (c == '\0')
		return (ft_strlen(s));
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (-1);
}
