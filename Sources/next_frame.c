/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:06:12 by hdougoud          #+#    #+#             */
/*   Updated: 2025/01/14 10:15:45 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	delayed_enemy_move(t_minilx *mlx)
{
	find_enemy(mlx, 1);
	if (mlx->map->map_enemy[mlx->player_pos_y][mlx->player_pos_x] == 'B')
		mlx->sprites->player->life -= 1;
	mlx->sprites->enemy->delayed_frame = 0;
}

static void	chest_animation(t_minilx *mlx)
{
	int	chest_x;
	int	chest_y;

	chest_x = mlx->sprites->chest->posx;
	chest_y = mlx->sprites->chest->posy;
	ft_put_floor(mlx, chest_x, chest_y);
	ft_put_image(mlx, mlx->sprites->chest->frames
	[mlx->sprites->chest->current_frame], chest_x, chest_y);
	if (mlx->map->map_enemy[chest_y][chest_x] == 'B')
		ft_put_image(mlx, mlx->sprites->enemy->frames
		[mlx->sprites->enemy->current_frame], chest_x, chest_y);
	if (mlx->map->map_enemy[chest_y][chest_x] == 'D')
		ft_put_image(mlx, mlx->sprites->enemy->dth_frames[5], chest_x, chest_y);
	if (mlx->sprites->chest->current_frame >= 3)
	{
		mlx->sprites->chest->current_frame = 0;
		mlx->sprites->chest->is_animating = 0;
		put_previous_layer(mlx, chest_x, chest_y);
	}
	mlx->sprites->chest->current_frame++;
}

void	next_enemy_frame(t_minilx *mlx, int x, int y)
{
	int	frame;

	frame = mlx->sprites->enemy->current_frame;
	put_previous_layer(mlx, x, y);
	ft_put_image(mlx, mlx->sprites->enemy->frames[frame], x, y);
}

void	put_previous_layer(t_minilx *mlx, int x, int y)
{
	ft_put_floor(mlx, x, y);
	if (mlx->map->map_tab[y][x] == 'C')
		ft_put_image(mlx, mlx->sprites->chest->frames[0], x, y);
	if (mlx->sprites->chest->is_animating == 0)
	{
		if (mlx->map->map_tab[y][x] == 'O')
			ft_put_image(mlx, mlx->sprites->chest->frames[3], x, y);
	}
	else if (mlx->sprites->chest->is_animating == 1)
	{
		ft_put_image(mlx, mlx->sprites->chest->frames
		[mlx->sprites->chest->current_frame],
			mlx->sprites->chest->posx, mlx->sprites->chest->posy);
	}
	if (mlx->map->map_tab[y][x] == 'E')
	{
		if (mlx->sprites->portal->is_open == 1)
			ft_put_image(mlx, mlx->sprites->portal->frames
			[mlx->sprites->portal->current_frame], x, y);
	}
	if (mlx->map->map_enemy[y][x] == 'D')
		ft_put_image(mlx, mlx->sprites->enemy->dth_frames[5], x, y);
}

int	next_frame(t_minilx *mlx)
{
	mlx->frame_count++;
	if (mlx->frame_count >= mlx->frames_rates)
	{
		check_player_life(mlx);
		put_previous_layer(mlx, mlx->player_pos_x, mlx->player_pos_y);
		if (mlx->map->collectable_nb == 0)
			open_portal(mlx);
		find_enemy(mlx, 2);
		if (mlx->sprites->enemy->delayed_frame >= 8
			&& mlx->sprites->player->dash == 0)
			delayed_enemy_move(mlx);
		if (mlx->sprites->chest->is_animating == 1)
			chest_animation(mlx);
		if (mlx->sprites->player->life <= 0)
			player_death(mlx);
		else if (mlx->sprites->player->dash == 1)
			player_dash(mlx);
		else
			player_idle(mlx);
		mlx->sprites->enemy->delayed_frame++;
		mlx->delayed_frame++;
		mlx->frame_count = 0;
	}
	return (0);
}
