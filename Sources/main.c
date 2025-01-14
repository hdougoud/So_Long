/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:34:51 by hdougoud          #+#    #+#             */
/*   Updated: 2025/01/13 15:49:42 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_minilx	mlx;

	init_minilx(&mlx);
	if (argc != 2)
		show_error(&mlx, WRONG_ARGUMENTS);
	init_map(&mlx, argv[1]);
	check_path_map(&mlx);
	mlx.map->map_enemy = create_enemy_map(&mlx, mlx.map->map_tab);
	mlx_key_hook(mlx.win, hook_keyboard, &mlx);
	mlx_hook(mlx.win, 17, 0, windows_closed, &mlx);
	mlx_loop_hook(mlx.mlx, next_frame, &mlx);
	mlx_loop(mlx.mlx);
}
