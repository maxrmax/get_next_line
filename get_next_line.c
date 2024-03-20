/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:51:38 by mring             #+#    #+#             */
/*   Updated: 2024/03/20 18:18:49 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[OPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	char		*next_line;
	int			amountread;
	int			to_copy;

	if (fd <= -1 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strdup(buf[fd]);
	// while \n is not found and read returns value above 0, loop buffer into line until read reaches 0 (end of file)
	amountread = 2;
	while (!(ft_strchr(line, '\n')) && amountread > 0)
	{
		amountread = read(fd, buf[fd], BUFFER_SIZE);
		if (amountread < 0)
			break ;
		buf[fd][amountread] = '\0';
		line = ft_strjoin(line, buf[fd], amountread); // line = linebuf ("" "content")
	}
	// if line is 0 or read failed, free line and return null
	if (amountread == -1 || ft_strlen(line) == 0)
		return (free(line), buf[fd][0] = '\0', NULL);
	// next line points to next \n location
	next_line = ft_strchr(line, '\n');
	// if next_line is not null assign length until \n to to_copy
	if (next_line != NULL)
	{
		to_copy = next_line - line + 1;
		ft_strlcpy(buf[fd], next_line + 1, BUFFER_SIZE + 1); // put next_line into buffer to keep current process
	}
	// else to_copy gets length of line and null terminate buf.
	else
	{
		to_copy = ft_strlen(line);
		buf[fd][0] = '\0';
	}
	// printf("%zu\n", next_line - line + 1);
	// null terminate line after \n
	return (line[to_copy] = '\0', line); // return line until \n
}
