/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:51:44 by mring             #+#    #+#             */
/*   Updated: 2024/03/06 17:02:36 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_get_line(char *next_str);
char	*ft_next_line_str(char *next_str);
char	*ft_read_str(int fd, char *next_str);
char	*ft_strchr(const char *next_str, int c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);

#endif