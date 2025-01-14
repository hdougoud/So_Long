/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_image_player_dash.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:02:09 by hdougoud          #+#    #+#             */
/*   Updated: 2025/01/13 16:11:42 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_dash_player_2(t_minilx *mlx)
{
	mlx->sprites->player->dsh_frames[4] = mlx_xpm_file_to_image(mlx->mlx,
			"Sprites/Player/Dash/Dash_5.xpm",
			&mlx->sprites->player->x, &mlx->sprites->player->y);
	if (!mlx->sprites->player->dsh_frames[4])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->player->dsh_frames[5] = mlx_xpm_file_to_image(mlx->mlx,
			"Sprites/Player/Dash/Dash_6.xpm",
			&mlx->sprites->player->x, &mlx->sprites->player->y);
	if (!mlx->sprites->player->dsh_frames[5])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->player->dsh_frames[6] = mlx_xpm_file_to_image(mlx->mlx,
			"Sprites/Player/Dash/Dash_7.xpm",
			&mlx->sprites->player->x, &mlx->sprites->player->y);
	if (!mlx->sprites->player->dsh_frames[6])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->player->dsh_frames[7] = mlx_xpm_file_to_image(mlx->mlx,
			"Sprites/Player/Dash/Dash_8.xpm",
			&mlx->sprites->player->x, &mlx->sprites->player->y);
	if (!mlx->sprites->player->dsh_frames[7])
		show_error(mlx, CANNOT_OPEN_FILE);
}

void	load_dash_player(t_minilx *mlx)
{
	mlx->sprites->player->dsh_frames[0] = mlx_xpm_file_to_image(mlx->mlx,
			"Sprites/Player/Dash/Dash_1.xpm",
			&mlx->sprites->player->x, &mlx->sprites->player->y);
	if (!mlx->sprites->player->dsh_frames[0])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->player->dsh_frames[1] = mlx_xpm_file_to_image(mlx->mlx,
			"Sprites/Player/Dash/Dash_2.xpm",
			&mlx->sprites->player->x, &mlx->sprites->player->y);
	if (!mlx->sprites->player->dsh_frames[1])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->player->dsh_frames[2] = mlx_xpm_file_to_image(mlx->mlx,
			"Sprites/Player/Dash/Dash_3.xpm",
			&mlx->sprites->player->x, &mlx->sprites->player->y);
	if (!mlx->sprites->player->dsh_frames[2])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->player->dsh_frames[3] = mlx_xpm_file_to_image(mlx->mlx,
			"Sprites/Player/Dash/Dash_4.xpm",
			&mlx->sprites->player->x, &mlx->sprites->player->y);
	if (!mlx->sprites->player->dsh_frames[3])
		show_error(mlx, CANNOT_OPEN_FILE);
	load_dash_player_2(mlx);
}
