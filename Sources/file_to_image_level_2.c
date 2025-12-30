/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_image_level_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:28:29 by hdougoud          #+#    #+#             */
/*   Updated: 2025/12/30 03:27:08 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_floor_2(t_minilx *mlx)
{
	mlx->sprites->grass->frames[4] = mlx_xpm_file_to_image(mlx->mlx,
			"assets/sprites/Rock/Rock_5.xpm",
			&mlx->sprites->grass->x, &mlx->sprites->grass->y);
	if (!mlx->sprites->grass->frames[4])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->grass->frames[5] = mlx_xpm_file_to_image(mlx->mlx,
			"assets/sprites/Rock/Rock_6.xpm",
			&mlx->sprites->grass->x, &mlx->sprites->grass->y);
	if (!mlx->sprites->grass->frames[5])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->grass->frames[6] = mlx_xpm_file_to_image(mlx->mlx,
			"assets/sprites/Rock/Rock_7.xpm",
			&mlx->sprites->grass->x, &mlx->sprites->grass->y);
	if (!mlx->sprites->grass->frames[6])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->grass->frames[7] = mlx_xpm_file_to_image(mlx->mlx,
			"assets/sprites/Rock/Rock_8.xpm",
			&mlx->sprites->grass->x, &mlx->sprites->grass->y);
	if (!mlx->sprites->grass->frames[7])
		show_error(mlx, CANNOT_OPEN_FILE);
}

static void	load_floor_1(t_minilx *mlx)
{
	mlx->sprites->grass->frames[0] = mlx_xpm_file_to_image(mlx->mlx,
			"assets/sprites/Rock/Rock_1.xpm",
			&mlx->sprites->grass->x, &mlx->sprites->grass->y);
	if (!mlx->sprites->grass->frames[0])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->grass->frames[1] = mlx_xpm_file_to_image(mlx->mlx,
			"assets/sprites/Rock/Rock_2.xpm",
			&mlx->sprites->grass->x, &mlx->sprites->grass->y);
	if (!mlx->sprites->grass->frames[1])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->grass->frames[2] = mlx_xpm_file_to_image(mlx->mlx,
			"assets/sprites/Rock/Rock_3.xpm",
			&mlx->sprites->grass->x, &mlx->sprites->grass->y);
	if (!mlx->sprites->grass->frames[2])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->grass->frames[3] = mlx_xpm_file_to_image(mlx->mlx,
			"assets/sprites/Rock/Rock_4.xpm",
			&mlx->sprites->grass->x, &mlx->sprites->grass->y);
	if (!mlx->sprites->grass->frames[3])
		show_error(mlx, CANNOT_OPEN_FILE);
}

void	load_level2_images(t_minilx *mlx)
{
	load_floor_1(mlx);
	load_floor_2(mlx);
	mlx->sprites->wall->name = mlx_xpm_file_to_image(mlx->mlx,
			"assets/sprites/Brick.xpm",
			&mlx->sprites->wall->x, &mlx->sprites->wall->y);
	if (!mlx->sprites->wall->name)
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->map->max_map_frames = 7;
}
