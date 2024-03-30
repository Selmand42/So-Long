/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhademi <muhademi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 06:34:54 by muhademi          #+#    #+#             */
/*   Updated: 2024/03/30 12:52:30 by muhademi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	call_dfs_e(t_game *game)
{
	char	*visited;
	int		i;
	int		res;

	res = 0;
	visited = malloc(ft_strlen(game -> map));
	i = 0;
	while (i < ft_strlen(game -> map))
	{
		visited[i] = '0';
		i += 1;
	}
	if (dfs_e(game, game -> start, visited) == 1)
		res = 1;
	free(visited);
	return (res);
}

int	dfs_e(t_game *game, int i, char *visited)
{
	if (visited[i] == '1' || i < 0
		|| i > ft_strlen(game -> map)
		|| (game -> map)[i] == '1')
		return (0);
	visited[i] = '1';
	if ((game -> map)[i] == 'E')
		return (1);
	return (dfs_e(game, i + 1, visited)
		|| dfs_e(game, i - 1, visited)
		|| dfs_e(game, i + game -> width, visited)
		|| dfs_e(game, i - game -> width, visited));
}

int	call_dfs_c(t_game *game)
{
	char	*visited;
	int		i;
	int		res;

	res = 0;
	visited = malloc(ft_strlen(game -> map));
	i = 0;
	while (i < ft_strlen(game -> map))
	{
		visited[i] = '0';
		i += 1;
	}
	res = dfs_c(game, game -> start, visited);
	free(visited);
	return (res);
}

int	dfs_c(t_game *game, int i, char *visited)
{
	int	is_coin;

	is_coin = 0;
	if (visited[i] == '1' || i < 0
		|| i > ft_strlen(game -> map)
		|| (game -> map)[i] == '1')
		return (0);
	visited[i] = '1';
	if ((game -> map)[i] == 'C')
		is_coin = 1;
	return (dfs_c(game, i + 1, visited)
		+ dfs_c(game, i - 1, visited)
		+ dfs_c(game, i + game -> width, visited)
		+ dfs_c(game, i - game -> width, visited) + is_coin);
}

int	get_fd(char *path)
{
	int	fd;
	int	len;

	len = ft_strlen(path);
	if (len < 5 || path[len - 1] != 'r' || path[len - 2] != 'e'
		|| path[len - 3] != 'b' || path[len - 4] != '.')
		ft_error(10);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error(9);
	return (fd);
}
