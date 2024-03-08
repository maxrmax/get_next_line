/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:51:38 by mring             #+#    #+#             */
/*   Updated: 2024/03/08 14:42:41 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strjoin(char *s1, char const *s2, size_t length)
{
	char	*string;
	int		s1_len;
	int		s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = length;
	string = (char *)malloc(s1_len + s2_len + 1 * sizeof(char));
	if (!string)
		return (NULL);
	//cpystr(string, s1, s1_len + 1);
	cpystr((string + s1_len), s2, s2_len +1);
	free(s1);
	return (string);
}

char	cpystr(char *dst, const char *src, size_t dstsize)
{
	size_t	src_length;
	size_t	i;

	src_length = ft_strlen(src);
	i = 0;
	if (dstsize > 0)
	{
		while (i < src_length & i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_length);
}

int	ft_strlen(const char *src)
{
	int	count;

	count = 0;
	while (src[count] != 0)
		count++;
	return (count);
}

char	*ft_strdup(const char *src)
{
	char	*dst;
	int		length;
	size_t	i;

	length = ft_strlen(src) + 1;
	i = 0;
	dst = malloc(length);
	if (!dst)
		return (NULL);
	cpystr(dst, src, length);
	return (dst);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	// char		*next_line;
	int			amountread;
	// int			leftover;

	line = ft_strdup(buf);
	amountread = read(fd, buf, BUFFER_SIZE);
	line = ft_strjoin(line, buf, amountread);
	printf("%d\n", fd);
	printf("buf:\n%s\n", buf);
	printf("\nline:\n%s\n", line);
	return (line);
}

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