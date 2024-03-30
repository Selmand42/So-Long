/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhademi <muhademi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 10:34:32 by muhademi          #+#    #+#             */
/*   Updated: 2024/03/30 11:44:18 by muhademi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "get_next_line/get_next_line.h"
# include "minilibx/mlx.h"
# include "ft_printf/ft_printf.h"

typedef struct s_game
{
	char	*map;
	int		width;
	int		height;
	int		coin;
	int		start;
	int		end;
	void	*floor;
	void	*barrier;
	void	*player;
	void	*exit;
	void	*collectable;
	void	*mlxpointer;
	void	*winpointer;
	int		counter;
}	t_game;

void	ft_error(int num);
int		map(t_game *game, char *arg);
int		check_map(t_game *game);
int		counter(char *str, char c);
int		check_counts(t_game *game);
void	start_exit(t_game *game);
int		dfs_e(t_game *game, int i, char *visited);
int		dfs_c(t_game *game, int i, char *visited);
int		read_map(t_game *game, char *path);
int		call_dfs_e(t_game *game);
int		call_dfs_c(t_game *game);
void	place_images(t_game *game);
void	add_images(t_game *game);
int		exit_game(t_game *game);
int		move(int direct, t_game *game);
int		keys(int command, t_game *game);
int		get_fd(char *path);

#endif
