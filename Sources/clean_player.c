/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:23:55 by hdougoud          #+#    #+#             */
/*   Updated: 2025/01/13 13:58:34 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	clean_player_dash(t_minilx *mlx)
{
	if (mlx->sprites->player->dsh_frames[0])
		mlx_destroy_image(mlx->mlx, mlx->sprites->player->dsh_frames[0]);
	if (mlx->sprites->player->dsh_frames[1])
		mlx_destroy_image(mlx->mlx, mlx->sprites->player->dsh_frames[1]);
	if (mlx->sprites->player->dsh_frames[2])
		mlx_destroy_image(mlx->mlx, mlx->sprites->player->dsh_frames[2]);
	if (mlx->sprites->player->dsh_frames[3])
		mlx_destroy_image(mlx->mlx, mlx->sprites->player->dsh_frames[3]);
	if (mlx->sprites->player->dsh_frames[4])
		mlx_destroy_image(mlx->mlx, mlx->sprites->player->dsh_frames[4]);
	if (mlx->sprites->player->dsh_frames[5])
		mlx_destroy_image(mlx->mlx, mlx->sprites->player->dsh_frames[5]);
	if (mlx->sprites->player->dsh_frames[6])
		mlx_destroy_image(mlx->mlx, mlx->sprites->player->dsh_frames[6]);
	if (mlx->sprites->player->dsh_frames[7])
		mlx_destroy_image(mlx->mlx, mlx->sprites->player->dsh_frames[7]);
}

static void	clean_player_death(t_minilx *mlx)
{
	if (mlx->sprites->player->dth_frames[0])
		mlx_destroy_image(mlx->mlx, mlx->sprites->player->dth_frames[0]);
	if (mlx->sprites->player->dth_frames[1])
		mlx_destroy_image(mlx->mlx, mlx->sprites->player->dth_frames[1]);
	if (mlx->sprites->player->dth_frames[2])
		mlx_destroy_image(mlx->mlx, mlx->sprites->player->dth_frames[2]);
	if (mlx->sprites->player->dth_frames[3])
		mlx_destroy_image(mlx->mlx, mlx->sprites->player->dth_frames[3]);
	if (mlx->sprites->player->dth_frames[4])
		mlx_destroy_image(mlx->mlx, mlx->sprites->player->dth_frames[4]);
	if (mlx->sprites->player->dth_frames[5])
		mlx_destroy_image(mlx->mlx, mlx->sprites->player->dth_frames[5]);
	if (mlx->sprites->player->dth_frames[6])
		mlx_destroy_image(mlx->mlx, mlx->sprites->player->dth_frames[6]);
	if (mlx->sprites->player->dth_frames[7])
		mlx_destroy_image(mlx->mlx, mlx->sprites->player->dth_frames[7]);
}

static void	clean_player_idle(t_minilx *mlx)
{
	if (mlx->sprites->player->frames[0])
		mlx_destroy_image(mlx->mlx, mlx->sprites->player->frames[0]);
	if (mlx->sprites->player->frames[1])
		mlx_destroy_image(mlx->mlx, mlx->sprites->player->frames[1]);
	if (mlx->sprites->player->frames[2])
		mlx_destroy_image(mlx->mlx, mlx->sprites->player->frames[2]);
	if (mlx->sprites->player->frames[3])
		mlx_destroy_image(mlx->mlx, mlx->sprites->player->frames[3]);
	if (mlx->sprites->player->frames[4])
		mlx_destroy_image(mlx->mlx, mlx->sprites->player->frames[4]);
	if (mlx->sprites->player->frames[5])
		mlx_destroy_image(mlx->mlx, mlx->sprites->player->frames[5]);
	if (mlx->sprites->player->frames[6])
		mlx_destroy_image(mlx->mlx, mlx->sprites->player->frames[6]);
	if (mlx->sprites->player->frames[7])
		mlx_destroy_image(mlx->mlx, mlx->sprites->player->frames[7]);
}

void	clean_player_img(t_minilx *mlx)
{
	clean_player_idle(mlx);
	clean_player_death(mlx);
	clean_player_dash(mlx);
}
