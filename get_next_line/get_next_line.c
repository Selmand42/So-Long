/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhademi <muhademi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:26:28 by muhademi          #+#    #+#             */
/*   Updated: 2023/12/07 15:15:05 by muhademi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*return_free(char *buffer, char *hold_line)
{
	free(buffer);
	free(hold_line);
	return (0);
}

char	*read_line(char *buffer, int fd)
{
	int		read_len;
	char	*hold_line;

	hold_line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!hold_line)
		return (0);
	read_len = 1;
	while (!ft_strchr(buffer, '\n') && read_len != 0)
	{
		read_len = read(fd, hold_line, BUFFER_SIZE);
		if (read_len == -1)
			return (return_free(buffer, hold_line));
		hold_line[read_len] = 0;
		buffer = join(buffer, hold_line);
	}
	free(hold_line);
	return (buffer);
}

char	*get_line_from_buffer(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (0);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = 0;
	return (line);
}

char	*clean_buffer(char *buffer)
{
	char	*new_buffer;
	int		i;
	int		a;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	if (buffer[i] == '\n')
		i++;
	a = 0;
	new_buffer = malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!new_buffer)
		return (NULL);
	while (buffer[i])
		new_buffer[a++] = buffer[i++];
	new_buffer[a] = 0;
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = read_line(buffer, fd);
	if (!buffer)
		return (NULL);
	line = get_line_from_buffer(buffer);
	buffer = clean_buffer(buffer);
	return (line);
}
