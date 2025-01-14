/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_image_enemy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:24:00 by hdougoud          #+#    #+#             */
/*   Updated: 2025/01/12 15:37:12 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_enemy_idle(t_minilx *mlx)
{
	mlx->sprites->enemy->frames[0] = mlx_xpm_file_to_image(mlx->mlx,
			"Sprites/Slime/Idle/Slime_1.xpm",
			&mlx->sprites->enemy->x, &mlx->sprites->enemy->y);
	if (!mlx->sprites->enemy->frames[0])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->enemy->frames[1] = mlx_xpm_file_to_image(mlx->mlx,
			"Sprites/Slime/Idle/Slime_2.xpm",
			&mlx->sprites->enemy->x, &mlx->sprites->enemy->y);
	if (!mlx->sprites->enemy->frames[1])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->enemy->frames[2] = mlx_xpm_file_to_image(mlx->mlx,
			"Sprites/Slime/Idle/Slime_3.xpm",
			&mlx->sprites->enemy->x, &mlx->sprites->enemy->y);
	if (!mlx->sprites->enemy->frames[2])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->enemy->frames[3] = mlx_xpm_file_to_image(mlx->mlx,
			"Sprites/Slime/Idle/Slime_4.xpm",
			&mlx->sprites->enemy->x, &mlx->sprites->enemy->y);
	if (!mlx->sprites->enemy->frames[3])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->enemy->frames[4] = mlx_xpm_file_to_image(mlx->mlx,
			"Sprites/Slime/Idle/Slime_5.xpm",
			&mlx->sprites->enemy->x, &mlx->sprites->enemy->y);
	if (!mlx->sprites->enemy->frames[4])
		show_error(mlx, CANNOT_OPEN_FILE);
}

static void	load_enemy_death_2(t_minilx *mlx)
{
	mlx->sprites->enemy->dth_frames[3] = mlx_xpm_file_to_image(mlx->mlx,
			"Sprites/Slime/Death/death_4.xpm",
			&mlx->sprites->enemy->x, &mlx->sprites->enemy->y);
	if (!mlx->sprites->enemy->dth_frames[3])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->enemy->dth_frames[4] = mlx_xpm_file_to_image(mlx->mlx,
			"Sprites/Slime/Death/death_5.xpm",
			&mlx->sprites->enemy->x, &mlx->sprites->enemy->y);
	if (!mlx->sprites->enemy->dth_frames[4])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->enemy->dth_frames[5] = mlx_xpm_file_to_image(mlx->mlx,
			"Sprites/Slime/Death/death_6.xpm",
			&mlx->sprites->enemy->x, &mlx->sprites->enemy->y);
	if (!mlx->sprites->enemy->dth_frames[5])
		show_error(mlx, CANNOT_OPEN_FILE);
}

static void	load_enemy_death(t_minilx *mlx)
{
	mlx->sprites->enemy->dth_frames[0] = mlx_xpm_file_to_image(mlx->mlx,
			"Sprites/Slime/Death/death_1.xpm",
			&mlx->sprites->enemy->x, &mlx->sprites->enemy->y);
	if (!mlx->sprites->enemy->dth_frames[0])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->enemy->dth_frames[1] = mlx_xpm_file_to_image(mlx->mlx,
			"Sprites/Slime/Death/death_2.xpm",
			&mlx->sprites->enemy->x, &mlx->sprites->enemy->y);
	if (!mlx->sprites->enemy->dth_frames[1])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->enemy->dth_frames[2] = mlx_xpm_file_to_image(mlx->mlx,
			"Sprites/Slime/Death/death_3.xpm",
			&mlx->sprites->enemy->x, &mlx->sprites->enemy->y);
	if (!mlx->sprites->enemy->dth_frames[2])
		show_error(mlx, CANNOT_OPEN_FILE);
}

void	load_enemy_image(t_minilx *mlx)
{
	load_enemy_idle(mlx);
	load_enemy_death(mlx);
	load_enemy_death_2(mlx);
}
