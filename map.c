/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhademi <muhademi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 05:49:46 by muhademi          #+#    #+#             */
/*   Updated: 2024/03/30 11:44:28 by muhademi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	read_map(t_game *game, char *path)
{
	int		fd;
	char	*line;
	int		height;

	height = 0;
	fd = get_fd(path);
	line = get_next_line(fd);
	game -> map = 0;
	game -> width = ft_strlen(line);
	while (line)
	{
		if (ft_strlen(line) != game -> width)
			ft_error(1);
		game -> map = join(game -> map, line);
		height += 1;
		free(line);
		line = get_next_line(fd);
		if (line && line[ft_strlen(line) - 1] != '\n')
			line = join(line, "\n");
	}
	game -> height = height;
	close(fd);
	free(line);
	return (0);
}

int	check_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game -> height)
	{
		if ((game -> map)[j] != '1'
			|| (game -> map)[j + game -> width - 2] != '1')
			ft_error(2);
		i += 1;
		j += game -> width;
	}
	i = 0;
	while (i < game -> width - 1)
	{
		if ((game -> map)[i] != '1'
			|| (game -> map)[i + (game -> width) * (game -> height - 1)] != '1')
			ft_error(2);
		i += 1;
	}
	return (1);
}

int	counter(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count += 1;
		i += 1;
	}
	return (count);
}

int	check_counts(t_game *game)
{
	if (counter(game -> map, 'C') < 1)
		ft_error(3);
	if (counter(game -> map, 'E') != 1)
		ft_error(4);
	if (counter(game -> map, 'P') != 1)
		ft_error(5);
	if (counter(game -> map, 'C') + counter(game -> map, 'E')
		+ counter(game -> map, 'P') + counter(game -> map, '1')
		+ counter(game -> map, '0') != (game -> width - 1) * (game -> height))
		ft_error(6);
	game -> coin = counter(game -> map, 'C');
	return (1);
}

void	start_exit(t_game *game)
{
	int	i;

	i = 0;
	while ((game -> map)[i])
	{
		if ((game -> map)[i] == 'P')
		{
			game -> start = i ;
			game -> counter = 0;
		}
		else if ((game -> map)[i] == 'E')
			game -> end = i;
		i += 1;
	}
}
