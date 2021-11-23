/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:43:11 by fathjami          #+#    #+#             */
/*   Updated: 2021/11/23 12:28:09 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_line(char **buff, int index)
{
	char	*temp;
	char	*arr;

	temp = ft_substr(*buff, 0, index + 1);
	arr = ft_substr(*buff, index + 1, ft_strlen(*buff) - (index + 1));
	free (*buff);
	*buff = arr;
	return (temp);
}

char	*rest(char **reminder, char *line)
{
	line = ft_strdup(*reminder);
	free(*reminder);
	*reminder = NULL;
	return (line);
}

char	*free_return(char **reminder)
{
	free(*reminder);
	*reminder = NULL;
	return (NULL);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*reminder;
	char		*line;
	int			res;
	int			index;

	line = NULL;
	if (reminder == NULL)
		reminder = ft_strdup("");
	res = read (fd, buff, BUFFER_SIZE);
	while (res >= 0)
	{
		buff[res] = '\0';
		reminder = ft_strjoin(&reminder, buff);
		index = ft_strchr(reminder, '\n');
		if (index != -1)
			return (get_line(&reminder, index));
		if (!res && !reminder[0])
			break ;
		if (!res && reminder)
			return (rest(&reminder, line));
		res = read(fd, buff, BUFFER_SIZE);
	}
	return (free_return(&reminder));
}
