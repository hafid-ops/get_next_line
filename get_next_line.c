/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherif <hcherif@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 13:18:38 by hcherif           #+#    #+#             */
/*   Updated: 2026/08/12 15:22:19 by hcherif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*buffer;
	char			*result;
	char			*line;
	static char		*leftover;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	result = leftover;
	leftover = NULL;
	result = read_until_line(fd, result, buffer);
	if (!result)
	{
		free(buffer);
		return (NULL);
	}
	line = extract_line(result);
	leftover = save_leftover(result);
	free(result);
	free(buffer);
	return (line);
}
