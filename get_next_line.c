/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:51:38 by mring             #+#    #+#             */
/*   Updated: 2024/02/19 16:15:19 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//	ssize_t	read(int fd, void buf[.count], size_t count)
char	*get_next_line(int fd)
{

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, "text.txt" ,0) < 0)
		return (NULL);
	
}

int	main(void)
{
	int 	fd;
	char 	*line;

	fd = open("test.txt", O_RDONLY);
	line = "";
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	fd = close(fd);
	return(0);
}

/*
open, read, loop read, allocate read content until \n,
create new string with the read content, clear allocation, repeat.
Until end of file. don't forget to \0 end of string. Buffer size + 1

*/