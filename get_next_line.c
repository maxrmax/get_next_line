/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:51:38 by mring             #+#    #+#             */
/*   Updated: 2024/04/08 05:36:08 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	buf[OPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	char		*next_line;
	int			amountread;
	int			to_copy;

	// Check if file descriptor is valid and buffer size is positive
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	
	// Duplicate content of buf[fd] into line
	line = ft_strdup(buf[fd]);
	if (!line)
		return (NULL); // Return NULL if memory allocation fails

	amountread = 1;
	while (!(ft_strchr(line, '\n')) && amountread > 0)
	{
		// Read from file descriptor into buf[fd]
		amountread = read(fd, buf[fd], BUFFER_SIZE);
		if (amountread < 0)
		{
			free(line); // Free allocated memory before returning NULL
			return (NULL); // Return NULL if read fails
		}
		// Join current line with newly read data
		line = ft_strjoin(line, buf[fd], amountread);
		if (!line)
		{
			free(line); // Free allocated memory before returning NULL
			return (NULL); // Return NULL if memory allocation fails
		}
		if (ft_strlen(line) == 0)
		{
			free(line); // Free allocated memory before returning NULL
			return (NULL); // Return NULL if line is empty
		}
	}

	// Find next newline character in line
	next_line = ft_strchr(line, '\n');
	// Determine number of characters to copy and handle buffer accordingly
	to_copy = err_check(next_line, line, buf[fd]);
	if (!next_line && amountread == 0)
		free(line); // Free allocated memory before returning NULL in case of EOF
	return (line[to_copy] = '\0', line);
}

int	err_check(char *next_line, char *line, char *buf)
{
	int	to_copy;

	if (next_line != NULL)
	{
		// Calculate number of characters to copy until next newline character
		to_copy = next_line - line + 1;
		// Copy remaining characters into buf
		ft_strlcpy(buf, next_line + 1, BUFFER_SIZE + 1);
	}
	else
	{
		// If no newline character found, copy entire line and reset buf
		to_copy = ft_strlen(line);
		buf[0] = '\0';
	}
	return (to_copy);
}
