/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:02:03 by hdougoud          #+#    #+#             */
/*   Updated: 2025/01/13 19:49:40 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_death(t_minilx *mlx)
{
	int	x;
	int	y;

	x = mlx->player_pos_x;
	y = mlx->player_pos_y;
	if (mlx->sprites->player->dth_current_frame >= 7)
	{
		ft_put_image(mlx, mlx->sprites->player->dth_frames[7], x, y);
		return ;
	}
	ft_put_image(mlx, mlx->sprites->player->dth_frames
	[mlx->sprites->player->dth_current_frame], x, y);
	if (mlx->delayed_frame >= 2)
	{
		mlx->delayed_frame = 0;
		mlx->sprites->player->dth_current_frame++;
	}
}

static void	play_enemy_death_aniamtion(t_minilx *mlx, int x, int y)
{
	int	frame;

	frame = mlx->sprites->enemy->dth_current_frame;
	mlx->map->map_enemy[mlx->player_pos_y][mlx->player_pos_x + 1] = 'I';
	put_previous_layer(mlx, x, y);
	ft_put_image(mlx, mlx->sprites->enemy->dth_frames[frame], x, y);
	if (mlx->sprites->player->dsh_current_frame > 1)
	{
		mlx->sprites->enemy->dth_current_frame++;
		if (mlx->sprites->enemy->dth_current_frame >= 5)
		{
			mlx->sprites->enemy->dth_current_frame = 0;
			mlx->map->map_enemy[y][x] = 'D';
		}
	}
}

void	player_dash(t_minilx *mlx)
{
	int	img_x;

	img_x = mlx->sprites->player->dsh_current_frame + 1;
	if (mlx->sprites->player->dsh_current_frame >= 7)
	{
		mlx->player_pos_x += 1;
		mlx->sprites->player->dash = 0;
		mlx->sprites->player->dsh_current_frame = 0;
		return ;
	}
	if (mlx->map->map_tab[mlx->player_pos_y][mlx->player_pos_x + 1] == '1')
	{
		mlx->sprites->player->dash = 0;
		return ;
	}
	if (mlx->map->map_enemy[mlx->player_pos_y][mlx->player_pos_x + 1] == 'B'
		|| mlx->map->map_enemy[mlx->player_pos_y][mlx->player_pos_x + 1] == 'I')
		play_enemy_death_aniamtion(mlx,
			mlx->player_pos_x + 1, mlx->player_pos_y);
	mlx_put_image_to_window(mlx->mlx, mlx->win,
		mlx->sprites->player->dsh_frames[img_x - 1],
		(mlx->player_pos_x * TEXTURE_SIZE) + (img_x * 8),
		mlx->player_pos_y * TEXTURE_SIZE);
	mlx->sprites->player->dsh_current_frame++;
}

void	player_idle(t_minilx *mlx)
{
	ft_put_image(mlx, mlx->sprites->player->frames
	[mlx->sprites->player->current_frame],
		mlx->player_pos_x, mlx->player_pos_y);
	if (mlx->delayed_frame >= 2)
	{
		if (mlx->sprites->player->current_frame >= 7)
			mlx->sprites->player->current_frame = 0;
		mlx->sprites->player->current_frame++;
		mlx->delayed_frame = 0;
	}
}
