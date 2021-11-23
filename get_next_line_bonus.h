/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:55:06 by fathjami          #+#    #+#             */
/*   Updated: 2021/11/23 13:57:12 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include<unistd.h>
# include<stdlib.h>
# include<fcntl.h>

char	*get_next_line(int fd);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char **s1, char *s2);
char	*ft_strdup(const char *s1);
int		ft_strchr(char *s, int c);
int		ft_strlen(char *s);
void	*ft_memset(void *b, int c, size_t len);
char	*free_return(char **reminder);
char	*rest(char **reminder, char *line);
char	*get_line(char **buff, int index);

#endif
