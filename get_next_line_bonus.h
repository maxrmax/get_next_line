/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:23:54 by mring             #+#    #+#             */
/*   Updated: 2024/12/06 14:37:03 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
void	ft_strlcpy(char *dst, const char *src, size_t dstlen);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *str1, char const *str2);
char	*ft_substr(char const *s, size_t start, size_t len);
char	*readline(int fd, char *buffer, char *line);
char	*get_next_line(int fd);

#endif