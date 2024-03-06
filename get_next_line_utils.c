/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:51:49 by mring             #+#    #+#             */
/*   Updated: 2024/03/06 16:59:42 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*string;
	int		i; // s1 counter
	int		j; // s2 counter

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	string = malloc(ft_strlen(s1) + ft_strlen(s2) + 1); // malloc s1+s1+1 (\0)
	if (string == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		string[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0' && i + j < ft_strlen(s1) + ft_strlen(s2) + 1)
	{
		string[j + i] = s2[j];
		j++;
	}
	string[i + j] = '\0';
	return (string);
}

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*ft_strchr(const char *next_str, int c)
{
	int		i; // counter, has to be unsigned int?
	char	cc;

	cc = (char) c;
	i = 0;
	while (next_str[i]) // loop over string
	{
		if (next_str[i] == cc) // if char is found in string
			return ((char *) &next_str[i]); // return position
		i++;
	}
	if (next_str[i] == cc) // if char is found in str and above loop failed
		return ((char *) &next_str[i]); // return position
	return (NULL); // else return NULL
}