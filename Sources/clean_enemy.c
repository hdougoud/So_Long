/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:29:33 by hdougoud          #+#    #+#             */
/*   Updated: 2025/01/13 13:49:55 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_enemy_img(t_minilx *mlx)
{
	if (mlx->sprites->enemy->frames[0])
		mlx_destroy_image(mlx->mlx, mlx->sprites->enemy->frames[0]);
	if (mlx->sprites->enemy->frames[1])
		mlx_destroy_image(mlx->mlx, mlx->sprites->enemy->frames[1]);
	if (mlx->sprites->enemy->frames[2])
		mlx_destroy_image(mlx->mlx, mlx->sprites->enemy->frames[2]);
	if (mlx->sprites->enemy->frames[3])
		mlx_destroy_image(mlx->mlx, mlx->sprites->enemy->frames[3]);
	if (mlx->sprites->enemy->frames[4])
		mlx_destroy_image(mlx->mlx, mlx->sprites->enemy->frames[4]);
	if (mlx->sprites->enemy->dth_frames[0])
		mlx_destroy_image(mlx->mlx, mlx->sprites->enemy->dth_frames[0]);
	if (mlx->sprites->enemy->dth_frames[1])
		mlx_destroy_image(mlx->mlx, mlx->sprites->enemy->dth_frames[1]);
	if (mlx->sprites->enemy->dth_frames[2])
		mlx_destroy_image(mlx->mlx, mlx->sprites->enemy->dth_frames[2]);
	if (mlx->sprites->enemy->dth_frames[3])
		mlx_destroy_image(mlx->mlx, mlx->sprites->enemy->dth_frames[3]);
	if (mlx->sprites->enemy->dth_frames[4])
		mlx_destroy_image(mlx->mlx, mlx->sprites->enemy->dth_frames[4]);
	if (mlx->sprites->enemy->dth_frames[5])
		mlx_destroy_image(mlx->mlx, mlx->sprites->enemy->dth_frames[5]);
}
