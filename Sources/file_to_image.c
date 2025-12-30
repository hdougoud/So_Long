/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:15:22 by hdougoud          #+#    #+#             */
/*   Updated: 2025/12/30 03:27:08 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_heart_image(t_minilx *mlx)
{
	mlx->sprites->heart->frames[0] = mlx_xpm_file_to_image(mlx->mlx,
			"assets/sprites/Heart/Heart_1.xpm",
			&mlx->sprites->heart->x, &mlx->sprites->heart->y);
	if (!mlx->sprites->heart->frames[0])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->heart->frames[1] = mlx_xpm_file_to_image(mlx->mlx,
			"assets/sprites/Heart/Heart_2.xpm",
			&mlx->sprites->heart->x, &mlx->sprites->heart->y);
	if (!mlx->sprites->heart->frames[1])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->heart->frames[2] = mlx_xpm_file_to_image(mlx->mlx,
			"assets/sprites/Heart/Heart_3.xpm",
			&mlx->sprites->heart->x, &mlx->sprites->heart->y);
	if (!mlx->sprites->heart->frames[2])
		show_error(mlx, CANNOT_OPEN_FILE);
}

static void	load_collectable_image(t_minilx *mlx)
{
	mlx->sprites->chest->frames[0] = mlx_xpm_file_to_image(mlx->mlx,
			"assets/sprites/Chest/Chest_1.xpm",
			&mlx->sprites->chest->x, &mlx->sprites->chest->y);
	if (!mlx->sprites->chest->frames[0])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->chest->frames[1] = mlx_xpm_file_to_image(mlx->mlx,
			"assets/sprites/Chest/Chest_2.xpm",
			&mlx->sprites->chest->x, &mlx->sprites->chest->y);
	if (!mlx->sprites->chest->frames[1])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->chest->frames[2] = mlx_xpm_file_to_image(mlx->mlx,
			"assets/sprites/Chest/Chest_3.xpm",
			&mlx->sprites->chest->x, &mlx->sprites->chest->y);
	if (!mlx->sprites->chest->frames[2])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->chest->frames[3] = mlx_xpm_file_to_image(mlx->mlx,
			"assets/sprites/Chest/Chest_4.xpm",
			&mlx->sprites->chest->x, &mlx->sprites->chest->y);
	if (!mlx->sprites->chest->frames[3])
		show_error(mlx, CANNOT_OPEN_FILE);
}

void	file_to_image(t_minilx *mlx)
{
	int	random;

	srand(time(NULL));
	random = rand() % (MAX_LEVEL + 1);
	if (random == 0)
	{
		load_level1_images(mlx);
	}
	else if (random == 1)
	{
		load_level2_images(mlx);
	}
	load_player_image(mlx);
	load_collectable_image(mlx);
	load_enemy_image(mlx);
	load_heart_image(mlx);
	load_portal_img(mlx);
}
