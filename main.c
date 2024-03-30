/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhademi <muhademi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 05:13:21 by muhademi          #+#    #+#             */
/*   Updated: 2024/03/30 11:46:59 by muhademi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(int num)
{
	ft_printf("Error\n");
	if (num == 0)
		ft_printf("I just want one map!\n");
	else if (num == 1)
		ft_printf("Length of the walls are not good.\n");
	else if (num == 2)
		ft_printf("There is a gap between walls.\n");
	else if (num == 3)
		ft_printf("There is not enough coin.\n");
	else if (num == 4)
		ft_printf("The map contaion just and exactly one exit!\n");
	else if (num == 5)
		ft_printf("Where is the start position!\n");
	else if (num == 6)
		ft_printf("Why there is foreign things???\n");
	else if (num == 7)
		ft_printf("Do you think it is possible to arrive finish point???\n");
	else if (num == 8)
		ft_printf("Do you think all the coins are collectable???\n");
	else if (num == 9)
		ft_printf("There is not a map like that!\n");
	else if (num == 10)
		ft_printf("The extension of file is not .ber!\n");
	exit(0);
}

int	map(t_game *game, char *arg)
{
	read_map(game, arg);
	check_map(game);
	check_counts(game);
	start_exit(game);
	if (call_dfs_e(game) == 0)
		ft_error(7);
	if (call_dfs_c(game) != game -> coin)
		ft_error(8);
	return (1);
}

int	main(int arg, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (arg != 2)
		ft_error(0);
	map(game, argv[1]);
	game -> mlxpointer = mlx_init();
	game -> winpointer = mlx_new_window(game -> mlxpointer,
			((game -> width - 1) * 40), (game -> height * 40), "solong");
	place_images(game);
	add_images(game);
	mlx_key_hook(game -> winpointer, keys, game);
	mlx_hook(game -> winpointer, 17, 0, (void *)exit, 0);
	mlx_loop(game -> mlxpointer);
	return (0);
}
