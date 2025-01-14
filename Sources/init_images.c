/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:35:08 by hdougoud          #+#    #+#             */
/*   Updated: 2025/01/13 19:50:49 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	secure_portal_img(t_minilx *mlx)
{
	mlx->sprites->portal->frames[0] = NULL;
	mlx->sprites->portal->frames[1] = NULL;
	mlx->sprites->portal->frames[2] = NULL;
	mlx->sprites->portal->frames[3] = NULL;
	mlx->sprites->portal->frames[4] = NULL;
	mlx->sprites->portal->frames[5] = NULL;
	mlx->sprites->portal->frames[6] = NULL;
	mlx->sprites->portal->opn_frames[0] = NULL;
	mlx->sprites->portal->opn_frames[1] = NULL;
	mlx->sprites->portal->opn_frames[2] = NULL;
	mlx->sprites->portal->opn_frames[3] = NULL;
	mlx->sprites->portal->opn_frames[4] = NULL;
}

static void	secure_floor_img(t_minilx *mlx)
{
	mlx->sprites->grass->frames[0] = NULL;
	mlx->sprites->grass->frames[1] = NULL;
	mlx->sprites->grass->frames[2] = NULL;
	mlx->sprites->grass->frames[3] = NULL;
	mlx->sprites->grass->frames[4] = NULL;
	mlx->sprites->grass->frames[5] = NULL;
	mlx->sprites->grass->frames[6] = NULL;
	mlx->sprites->grass->frames[7] = NULL;
	mlx->sprites->grass->frames[8] = NULL;
	mlx->sprites->grass->frames[9] = NULL;
}

static void	secure_enemy_img(t_minilx *mlx)
{
	mlx->sprites->enemy->frames[0] = NULL;
	mlx->sprites->enemy->frames[1] = NULL;
	mlx->sprites->enemy->frames[2] = NULL;
	mlx->sprites->enemy->frames[3] = NULL;
	mlx->sprites->enemy->frames[4] = NULL;
	mlx->sprites->enemy->dth_frames[0] = NULL;
	mlx->sprites->enemy->dth_frames[1] = NULL;
	mlx->sprites->enemy->dth_frames[2] = NULL;
	mlx->sprites->enemy->dth_frames[3] = NULL;
	mlx->sprites->enemy->dth_frames[4] = NULL;
	mlx->sprites->enemy->dth_frames[5] = NULL;
}

static void	secure_player_img(t_minilx *mlx)
{
	mlx->sprites->player->frames[0] = NULL;
	mlx->sprites->player->frames[1] = NULL;
	mlx->sprites->player->frames[2] = NULL;
	mlx->sprites->player->frames[3] = NULL;
	mlx->sprites->player->frames[4] = NULL;
	mlx->sprites->player->frames[5] = NULL;
	mlx->sprites->player->frames[6] = NULL;
	mlx->sprites->player->frames[7] = NULL;
	mlx->sprites->player->dsh_frames[0] = NULL;
	mlx->sprites->player->dsh_frames[1] = NULL;
	mlx->sprites->player->dsh_frames[2] = NULL;
	mlx->sprites->player->dsh_frames[3] = NULL;
	mlx->sprites->player->dsh_frames[4] = NULL;
	mlx->sprites->player->dsh_frames[5] = NULL;
	mlx->sprites->player->dsh_frames[6] = NULL;
	mlx->sprites->player->dsh_frames[7] = NULL;
	mlx->sprites->player->dth_frames[0] = NULL;
	mlx->sprites->player->dth_frames[1] = NULL;
	mlx->sprites->player->dth_frames[2] = NULL;
	mlx->sprites->player->dth_frames[3] = NULL;
	mlx->sprites->player->dth_frames[4] = NULL;
	mlx->sprites->player->dth_frames[5] = NULL;
	mlx->sprites->player->dth_frames[6] = NULL;
	mlx->sprites->player->dth_frames[7] = NULL;
}

void	secure_all_img(t_minilx *mlx)
{
	mlx->sprites->chest->frames[0] = NULL;
	mlx->sprites->chest->frames[1] = NULL;
	mlx->sprites->chest->frames[2] = NULL;
	mlx->sprites->chest->frames[3] = NULL;
	mlx->sprites->heart->frames[0] = NULL;
	mlx->sprites->heart->frames[1] = NULL;
	mlx->sprites->heart->frames[2] = NULL;
	mlx->sprites->wall->name = NULL;
	secure_floor_img(mlx);
	secure_enemy_img(mlx);
	secure_player_img(mlx);
	secure_portal_img(mlx);
}
