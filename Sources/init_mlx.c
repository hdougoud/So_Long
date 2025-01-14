/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:29:12 by hdougoud          #+#    #+#             */
/*   Updated: 2025/01/13 18:07:50 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_values(t_minilx *mlx)
{
	mlx->movement = 0;
	mlx->frame_count = 0;
	mlx->map->exit_nb = 0;
	mlx->delayed_frame = 0;
	mlx->map->player_nb = 0;
	mlx->frames_rates = 1500;
	mlx->map->collectable_nb = 0;
	mlx->sprites->player->life = 3;
	mlx->sprites->player->dash = 0;
	mlx->sprites->portal->is_open = 0;
	mlx->sprites->chest->is_animating = 0;
	mlx->sprites->enemy->current_frame = 0;
	mlx->sprites->chest->current_frame = 0;
	mlx->sprites->enemy->delayed_frame = 0;
	mlx->sprites->player->current_frame = 0;
	mlx->sprites->portal->current_frame = 0;
	mlx->sprites->enemy->dth_current_frame = 0;
	mlx->sprites->portal->opn_current_frame = 0;
	mlx->sprites->player->dth_current_frame = 0;
	mlx->sprites->player->dsh_current_frame = 0;
}

void	init_minilx(t_minilx *mlx)
{
	mlx->mlx = NULL;
	mlx->win = NULL;
	mlx->map = NULL;
	mlx->sprites = NULL;
	allocate_struct(mlx);
	mlx->map->map_tab = NULL;
	mlx->map->map_enemy = NULL;
	mlx->map->map_enemy_copy = NULL;
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		show_error(mlx, SERVER_X);
	init_values(mlx);
	file_to_image(mlx);
	mlx->screen_size_x = SCREEN_SIZE_X;
	mlx->screen_size_y = SCREEN_SIZE_Y;
}
