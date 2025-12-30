/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_image_level_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:58:15 by hdougoud          #+#    #+#             */
/*   Updated: 2025/12/30 03:28:11 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_grass_2(t_minilx *mlx)
{
	mlx->sprites->grass->frames[5] = mlx_xpm_file_to_image(mlx->mlx,
			"assets/sprites/Grass/Grass_06.xpm",
			&mlx->sprites->grass->x, &mlx->sprites->grass->y);
	if (!mlx->sprites->grass->frames[5])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->grass->frames[6] = mlx_xpm_file_to_image(mlx->mlx,
			"assets/sprites/Grass/Grass_07.xpm",
			&mlx->sprites->grass->x, &mlx->sprites->grass->y);
	if (!mlx->sprites->grass->frames[6])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->grass->frames[7] = mlx_xpm_file_to_image(mlx->mlx,
			"assets/sprites/Grass/Grass_08.xpm",
			&mlx->sprites->grass->x, &mlx->sprites->grass->y);
	if (!mlx->sprites->grass->frames[7])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->grass->frames[8] = mlx_xpm_file_to_image(mlx->mlx,
			"assets/sprites/Grass/Grass_09.xpm",
			&mlx->sprites->grass->x, &mlx->sprites->grass->y);
	if (!mlx->sprites->grass->frames[8])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->grass->frames[9] = mlx_xpm_file_to_image(mlx->mlx,
			"assets/sprites/Grass/Grass_10.xpm",
			&mlx->sprites->grass->x, &mlx->sprites->grass->y);
	if (!mlx->sprites->grass->frames[9])
		show_error(mlx, CANNOT_OPEN_FILE);
}

static void	load_grass_1(t_minilx *mlx)
{
	mlx->sprites->grass->frames[0] = mlx_xpm_file_to_image(mlx->mlx,
			"assets/sprites/Grass/Grass_01.xpm",
			&mlx->sprites->grass->x, &mlx->sprites->grass->y);
	if (!mlx->sprites->grass->frames[0])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->grass->frames[1] = mlx_xpm_file_to_image(mlx->mlx,
			"assets/sprites/Grass/Grass_02.xpm",
			&mlx->sprites->grass->x, &mlx->sprites->grass->y);
	if (!mlx->sprites->grass->frames[1])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->grass->frames[2] = mlx_xpm_file_to_image(mlx->mlx,
			"assets/sprites/Grass/Grass_03.xpm",
			&mlx->sprites->grass->x, &mlx->sprites->grass->y);
	if (!mlx->sprites->grass->frames[2])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->grass->frames[3] = mlx_xpm_file_to_image(mlx->mlx,
			"assets/sprites/Grass/Grass_04.xpm",
			&mlx->sprites->grass->x, &mlx->sprites->grass->y);
	if (!mlx->sprites->grass->frames[3])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->grass->frames[4] = mlx_xpm_file_to_image(mlx->mlx,
			"assets/sprites/Grass/Grass_05.xpm",
			&mlx->sprites->grass->x, &mlx->sprites->grass->y);
	if (!mlx->sprites->grass->frames[4])
		show_error(mlx, CANNOT_OPEN_FILE);
}

void	load_level1_images(t_minilx *mlx)
{
	load_grass_1(mlx);
	load_grass_2(mlx);
	mlx->sprites->wall->name = mlx_xpm_file_to_image(mlx->mlx,
			"assets/sprites/Tree.xpm",
			&mlx->sprites->wall->x, &mlx->sprites->wall->y);
	if (!mlx->sprites->wall->name)
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->map->max_map_frames = 9;
}
