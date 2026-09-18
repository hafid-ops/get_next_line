/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherif <hcherif@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 13:45:46 by hcherif           #+#    #+#             */
/*   Updated: 2026/08/12 16:04:41 by hcherif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_char(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char	*join(char *s1, char *s2)
{
	char	*result;
	int		i;
	int		j;
	int		len1;

	len1 = find_char(s1, '\0');
	result = malloc(len1 + find_char(s2, '\0') + 1);
	if (!result)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	while (i < len1)
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		result[i++] = s2[j++];
	result[i] = '\0';
	free(s1);
	return (result);
}

char	*extract_line(char *result)
{
	int		i;
	int		j;
	char	*line;

	if (!result || !result[0])
		return (NULL);
	i = find_char(result, '\n');
	if (result[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = result[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*save_leftover(char *result)
{
	int		i;
	int		j;
	char	*leftover;

	if (!result)
		return (NULL);
	i = find_char(result, '\n');
	if (!result[i])
		return (NULL);
	i++;
	j = find_char(result + i, '\0');
	if (j == 0)
		return (NULL);
	leftover = malloc(j + 1);
	if (!leftover)
		return (NULL);
	j = 0;
	while (result[i])
		leftover[j++] = result[i++];
	leftover[j] = '\0';
	return (leftover);
}

char	*read_until_line(int fd, char *result, char *buffer)
{
	int	bytes_read;

	bytes_read = 1;
	while (bytes_read > 0 && (!result
			|| result[find_char(result, '\n')] != '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(result);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		result = join(result, buffer);
		if (!result)
			return (NULL);
	}
	return (result);
}
