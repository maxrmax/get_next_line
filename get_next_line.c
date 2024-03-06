/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:51:38 by mring             #+#    #+#             */
/*   Updated: 2024/03/06 17:09:06 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd) //1
{
	char		*line;
	static char	*next_str;

	if (fd < 0 || BUFFER_SIZE <= 0) // check that fd and BUFFER_SIZE are valid
		return (NULL);
	next_str = ft_read_str(fd, next_str); // read fd into next_str,
	if (!next_str)
		return (NULL);
	line = ft_get_line(next_str); // extract next_str until \n into line.
	next_str = ft_next_line_str(next_str); // next_str with top line removed.
	return (line);
}

char	*ft_read_str(int fd, char *next_str)
{
	char	*buf; // writeable string buffer.
	int		read_bytes; // size of read bytes

	// malloc buffer,
	// read fd into buffer,
	// assign buffer str to next_str,
	// free buffer
	// return next_str
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char)); //allocate buffer
	if (!buf)
		return (NULL);
	read_bytes = 1; // 1 to enter loop at least once
	while (!ft_strchr(next_str, '\n') && read_bytes != 0) // while not \n and rb not null
	{
		read_bytes = read(fd, buf, BUFFER_SIZE); // read fd into buffer of BS amount, then assign to rb.
		if (read_bytes == -1) // if failed free and return.
		{
			free(buf);
			return (NULL);
		}
		buf[read_bytes] = '\0'; // null terminate string
		next_str = ft_strjoin(next_str, buf); // join next_str and buf into next_str <next_strbuf>
	}
	free(buf); //free buff
	return (next_str); //return next_str
}

char	*ft_get_line(char *next_str) // assign from next_str to str, from start to \n to \n.
{
	char	*str;
	int		i;

	i = 0;
	if (!next_str[i]) // if position is not NULL
		return (NULL);
	while (next_str[i] && next_str[i] != '\n') // i++ while not \0 or \n
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2)); // malloc str with length of i + 2 (\n\0),
	if (!str) // if malloc failed.
		return (NULL);
	i = 0;
	while (next_str[i] && next_str[i] != '\n') // copy next_str until \n into str, i++
	{
		str[i] = next_str[i];
		i++;
	}
	if (next_str[i] && next_str[i] != '\n') // if \n copy it
	{
		str[i] = next_str[i];
		i++;
	}
	str[i] = '\0'; // put \0 at the end.
	return (str);
}

char	*ft_next_line_str(char *next_str) // remove top line to advance line by line
{
	char 	*str;
	int		i;
	int		j;

	i = 0;
	while (next_str[i] && next_str[i] != '\n')
		i++;
	if (!next_str[i])
	{
		free(next_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * ((long)ft_strlen(next_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (next_str[i])
		str[j++] = next_str[i++];
	str[j] = '\0';
	free(next_str);
	return (str);
}


//
// open, read, loop read, allocate read content until \n,
// create new string with the read content, clear allocation, repeat.
// Until end of file. don't forget to \0 end of string. Buffer size + 1

// -------
// open text file to value,
// give value into get_next_ine
// ---
// function get_next_line:
// static next_str
// check fd and buffer_size, 
// call function to assign read fd to next_str.
// - malloc, loop until \n,
// - ft_strjoin(next_str, buff),
// return (next_str)
// call get_line(next_str) to assign returned value to line
// - loop string until \n character,
// - str<string\n> = malloc(sizeof(char) * (i + 2)),
// - loop copy next_str into str until \n,
// - copy \n too,
// - null terminate,
// - return str.
// call next_line_str(next_str) and assign return value to next_str
// -
// return line
//