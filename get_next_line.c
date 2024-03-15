/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:51:38 by mring             #+#    #+#             */
/*   Updated: 2024/03/15 18:55:30 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	i;

	srclen = ft_strlen(src);
	i = 0;
	if (dstsize > 0)
	{
		while (i < srclen && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srclen);
}

char	*ft_strdup(const char *s)
{
	char	*dst;
	size_t	strlen;
	size_t	i;

	i = 0;
	strlen = ft_strlen(s) + 1;
	dst = malloc(strlen);
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s, strlen);
	return (dst);
}

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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	char		*next_line;
	int			amountread;
	int			to_copy;

	amountread = read(fd, buf, BUFFER_SIZE);
	line = ft_strdup(buf);
	printf("b:\n%s\n", buf);
	printf("\nl:\n%s\n", line);
	printf("\nar:%i\n", amountread);
	next_line = ft_strchr(line, '\n');
	printf("\nnl:%s\n", next_line);
	to_copy = next_line - line + 1;
	printf("\ntc:%i\n", to_copy);
	
	return (0);
}

// get_next_line
// char *get_next_line(int fd);
// get_next_line.c, get_next_line_utils.c, get_next_line.h
// fd: The file descriptor to read from
// Return value
// Read line: correct behavior
// NULL: there is nothing else to read, or an error occurred
// read, malloc, free
// Description:
// Write a function that returns a line read from a file descriptor

// get_next_line reads the file descriptor 
// until the buffer is full or end of file is reached.
// to get the content of the buffer create a new string until \n
// then remove the readline from buffer and continue until next \n
// can use newline - line + 1 for position of \0
// strchr
// strlen
// strlcpy
// strdup
// strjoin
// get_next_line