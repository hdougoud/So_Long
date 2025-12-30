/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_image_player.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:54:41 by hdougoud          #+#    #+#             */
/*   Updated: 2025/12/30 03:27:08 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_death_player_image2(t_minilx *mlx)
{
	mlx->sprites->player->dth_frames[4] = mlx_xpm_file_to_image(mlx->mlx,
			"assets/sprites/Player/Death/Death_5.xpm",
			&mlx->sprites->player->x, &mlx->sprites->player->y);
	if (!mlx->sprites->player->dth_frames[4])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->player->dth_frames[5] = mlx_xpm_file_to_image(mlx->mlx,
			"assets/sprites/Player/Death/Death_6.xpm",
			&mlx->sprites->player->x, &mlx->sprites->player->y);
	if (!mlx->sprites->player->dth_frames[5])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->player->dth_frames[6] = mlx_xpm_file_to_image(mlx->mlx,
			"assets/sprites/Player/Death/Death_7.xpm",
			&mlx->sprites->player->x, &mlx->sprites->player->y);
	if (!mlx->sprites->player->dth_frames[6])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->player->dth_frames[7] = mlx_xpm_file_to_image(mlx->mlx,
			"assets/sprites/Player/Death/Death_8.xpm",
			&mlx->sprites->player->x, &mlx->sprites->player->y);
	if (!mlx->sprites->player->dth_frames[7])
		show_error(mlx, CANNOT_OPEN_FILE);
	load_dash_player(mlx);
}

static void	load_death_player_image(t_minilx *mlx)
{
	mlx->sprites->player->dth_frames[0] = mlx_xpm_file_to_image(mlx->mlx,
			"assets/sprites/Player/Death/Death_1.xpm",
			&mlx->sprites->player->x, &mlx->sprites->player->y);
	if (!mlx->sprites->player->dth_frames[0])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->player->dth_frames[1] = mlx_xpm_file_to_image(mlx->mlx,
			"assets/sprites/Player/Death/Death_2.xpm",
			&mlx->sprites->player->x, &mlx->sprites->player->y);
	if (!mlx->sprites->player->dth_frames[1])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->player->dth_frames[2] = mlx_xpm_file_to_image(mlx->mlx,
			"assets/sprites/Player/Death/Death_3.xpm",
			&mlx->sprites->player->x, &mlx->sprites->player->y);
	if (!mlx->sprites->player->dth_frames[2])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->player->dth_frames[3] = mlx_xpm_file_to_image(mlx->mlx,
			"assets/sprites/Player/Death/Death_4.xpm",
			&mlx->sprites->player->x, &mlx->sprites->player->y);
	if (!mlx->sprites->player->dth_frames[3])
		show_error(mlx, CANNOT_OPEN_FILE);
	load_death_player_image2(mlx);
}

static void	load_player_image_2(t_minilx *mlx)
{
	mlx->sprites->player->frames[4] = mlx_xpm_file_to_image(mlx->mlx,
			"assets/sprites/Player/Idle/idle_5.xpm",
			&mlx->sprites->player->x, &mlx->sprites->player->y);
	if (!mlx->sprites->player->frames[4])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->player->frames[5] = mlx_xpm_file_to_image(mlx->mlx,
			"assets/sprites/Player/Idle/idle_6.xpm",
			&mlx->sprites->player->x, &mlx->sprites->player->y);
	if (!mlx->sprites->player->frames[5])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->player->frames[6] = mlx_xpm_file_to_image(mlx->mlx,
			"assets/sprites/Player/Idle/idle_7.xpm",
			&mlx->sprites->player->x, &mlx->sprites->player->y);
	if (!mlx->sprites->player->frames[6])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->player->frames[7] = mlx_xpm_file_to_image(mlx->mlx,
			"assets/sprites/Player/Idle/idle_8.xpm",
			&mlx->sprites->player->x, &mlx->sprites->player->y);
	if (!mlx->sprites->player->frames[7])
		show_error(mlx, CANNOT_OPEN_FILE);
	load_death_player_image(mlx);
}

void	load_player_image(t_minilx *mlx)
{
	mlx->sprites->player->frames[0] = mlx_xpm_file_to_image(mlx->mlx,
			"assets/sprites/Player/Idle/idle_1.xpm",
			&mlx->sprites->player->x, &mlx->sprites->player->y);
	if (!mlx->sprites->player->frames[0])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->player->frames[1] = mlx_xpm_file_to_image(mlx->mlx,
			"assets/sprites/Player/Idle/idle_2.xpm",
			&mlx->sprites->player->x, &mlx->sprites->player->y);
	if (!mlx->sprites->player->frames[1])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->player->frames[2] = mlx_xpm_file_to_image(mlx->mlx,
			"assets/sprites/Player/Idle/idle_3.xpm",
			&mlx->sprites->player->x, &mlx->sprites->player->y);
	if (!mlx->sprites->player->frames[2])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->player->frames[3] = mlx_xpm_file_to_image(mlx->mlx,
			"assets/sprites/Player/Idle/idle_4.xpm",
			&mlx->sprites->player->x, &mlx->sprites->player->y);
	if (!mlx->sprites->player->frames[3])
		show_error(mlx, CANNOT_OPEN_FILE);
	load_player_image_2(mlx);
}
