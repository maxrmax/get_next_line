/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:51:38 by mring             #+#    #+#             */
/*   Updated: 2024/03/18 14:13:18 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	char		*next_line;
	int			amountread;
	int			to_copy;

	if (fd == -1)
		return (NULL);
	line = ft_strdup(buf);
	while (!(ft_strchr(line, '\n')) && (amountread = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[amountread] = '\0';
		line = ft_strjoin(line, buf, amountread);
	}
	if (ft_strlen(line) == 0 || amountread == -1)
	{
		ft_strlcpy(buf, "", BUFFER_SIZE + 1);
		return (free(line), NULL);
	}
	next_line = ft_strchr(line, '\n');
	if (next_line != NULL)
	{
		to_copy = next_line - line + 1;
		ft_strlcpy(buf, next_line + 1, BUFFER_SIZE + 1);
	}
	else
	{
		to_copy = ft_strlen(line);
		ft_strlcpy(buf, "", BUFFER_SIZE + 1);
	}
	line[to_copy] = '\0';
	return (line);
}
