/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:23:51 by mring             #+#    #+#             */
/*   Updated: 2024/12/05 11:29:10 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*readline(int fd, char *buffer, char *line)
{
	int		amountread;
	char	*buff;

	amountread = BUFFER_SIZE;
	while (amountread == BUFFER_SIZE && !(ft_strchr(line, '\n')))
	{
		amountread = read(fd, buffer, BUFFER_SIZE);
		if (amountread < 0)
		{
			free(line);
			buffer[0] = '\0';
			return (NULL);
		}
		buffer[amountread] = '\0';
		buff = ft_strjoin(line, buffer);
		if (!buff)
			return (free(line), NULL);
		free(line);
		line = buff;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*nextline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strdup(buffer);
	if (!line)
		return (NULL);
	line = readline(fd, buffer, line);
	if (!line)
		return (NULL);
	nextline = ft_strchr(line, '\n');
	if (nextline != NULL)
		return (ft_strlcpy(buffer, nextline + 1, BUFFER_SIZE + 1),
			nextline = ft_substr(line, 0, nextline - line + 1), free(line),
			nextline);
	else
	{
		if (!ft_strlen(line))
			return (free(line), NULL);
		line[ft_strlen(line)] = '\0';
		buffer[0] = '\0';
	}
	return (line);
}

// int	main(void)
// {
// 	char *line;
// 	int fd;
// 	printf("$");

// 	fd = open("testfile.txt", O_RDONLY);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	printf("$");
// 	close(fd);
// }