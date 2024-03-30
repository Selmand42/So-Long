/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhademi <muhademi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 11:10:56 by muhademi          #+#    #+#             */
/*   Updated: 2024/03/30 13:00:59 by muhademi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_images(t_game *game)
{
	int	i;
	int	j;

	game->floor = mlx_xpm_file_to_image(game->mlxpointer,
			"game_images/floor.xpm", &i, &j);
	game->barrier = mlx_xpm_file_to_image(game->mlxpointer,
			"game_images/wall.xpm", &i, &j);
	game->player = mlx_xpm_file_to_image(game->mlxpointer,
			"game_images/player.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlxpointer,
			"game_images/exit.xpm", &i, &j);
	game->collectable = mlx_xpm_file_to_image(game->mlxpointer,
			"game_images/item.xpm", &i, &j);
}

void	add_images(t_game *game)
{
	int	i;
	int	y;

	i = -1;
	while (i++ < ft_strlen(game -> map))
	{
		y = i / game -> width;
		if (game->map[i] == '1')
			mlx_put_image_to_window(game->mlxpointer, game->winpointer,
				game->barrier, (i % game -> width) * 40, y * 40);
		if (game->map[i] == 'C')
			mlx_put_image_to_window(game->mlxpointer, game->winpointer,
				game->collectable, (i % game -> width) * 40, y * 40);
		if (game->map[i] == 'P')
			mlx_put_image_to_window(game->mlxpointer, game->winpointer,
				game->player, (i % game -> width) * 40, y * 40);
		if (game->map[i] == 'E')
			mlx_put_image_to_window(game->mlxpointer, game->winpointer,
				game->exit, (i % game -> width) * 40, y * 40);
		if (game->map[i] == '0')
			mlx_put_image_to_window(game->mlxpointer, game->winpointer,
				game->floor, (i % game -> width) * 40, y * 40);
	}
}

int	exit_game(t_game *game)
{
	mlx_destroy_window(game -> mlxpointer, game -> winpointer);
	free(game -> mlxpointer);
	free(game -> map);
	exit(0);
}

int	move(int direct, t_game *game)
{
	if ((game -> start) + direct < 0
		|| (game -> start) + direct >= ft_strlen(game -> map))
		return (0);
	if ((game -> map)[(game -> start) + direct] != '1')
	{
		game -> start += direct;
		if ((game -> map)[(game -> start)] == 'C')
			game -> coin -= 1;
		(game -> map)[game -> start] = 'P';
		if ((game -> start) - direct == game -> end)
			(game -> map)[(game -> start) - direct] = 'E';
		else
			(game -> map)[(game -> start) - direct] = '0';
	}
	else
		return (0);
	game -> counter += 1;
	ft_printf("Number of Movements: %d\n", game -> counter);
	return (1);
}

int	keys(int command, t_game *game)
{
	if (command == 53)
		exit_game(game);
	else if (command == 0 || command == 123)
		move(-1, game);
	else if (command == 2 || command == 124)
		move(1, game);
	else if (command == 13 || command == 126)
		move(-1 * (game -> width), game);
	else if (command == 1 || command == 125)
		move(game -> width, game);
	if (game -> start == game -> end && game -> coin == 0)
	{
		ft_printf("Congrats!\n");
		exit_game(game);
	}
	add_images(game);
	return (1);
}
