/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:45:31 by hdougoud          #+#    #+#             */
/*   Updated: 2025/01/14 11:23:00 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_image(t_minilx *mlx)
{
	if (mlx->sprites->chest->frames[0])
		mlx_destroy_image(mlx->mlx, mlx->sprites->chest->frames[0]);
	if (mlx->sprites->chest->frames[1])
		mlx_destroy_image(mlx->mlx, mlx->sprites->chest->frames[1]);
	if (mlx->sprites->chest->frames[2])
		mlx_destroy_image(mlx->mlx, mlx->sprites->chest->frames[2]);
	if (mlx->sprites->chest->frames[3])
		mlx_destroy_image(mlx->mlx, mlx->sprites->chest->frames[3]);
	if (mlx->sprites->heart->frames[0])
		mlx_destroy_image(mlx->mlx, mlx->sprites->heart->frames[0]);
	if (mlx->sprites->heart->frames[1])
		mlx_destroy_image(mlx->mlx, mlx->sprites->heart->frames[1]);
	if (mlx->sprites->heart->frames[2])
		mlx_destroy_image(mlx->mlx, mlx->sprites->heart->frames[2]);
	if (mlx->sprites->wall->name)
		mlx_destroy_image(mlx->mlx, mlx->sprites->wall->name);
	clean_enemy_img(mlx);
	clean_player_img(mlx);
	clean_portal_img(mlx);
	clean_floor(mlx);
}

static void	free_struct(t_minilx *mlx)
{
	if (mlx->sprites)
	{
		if (mlx->sprites->chest)
			free(mlx->sprites->chest);
		if (mlx->sprites->player)
			free(mlx->sprites->player);
		if (mlx->sprites->wall)
			free(mlx->sprites->wall);
		if (mlx->sprites->enemy)
			free(mlx->sprites->enemy);
		if (mlx->sprites->heart)
			free(mlx->sprites->heart);
		if (mlx->sprites->grass)
			free(mlx->sprites->grass);
		if (mlx->sprites->portal)
			free(mlx->sprites->portal);
		free(mlx->sprites);
	}
	if (mlx->map)
		free(mlx->map);
}

void	quit_properly(t_minilx *mlx, int exit_status)
{
	int	i;

	if (mlx->mlx && mlx->sprites)
	{
		destroy_image(mlx);
	}
	if (mlx->map && mlx->map->map_tab)
	{
		i = 0;
		while (mlx->map->map_tab[i])
			free(mlx->map->map_tab[i++]);
		free(mlx->map->map_tab);
	}
	if (mlx->map && mlx->map->map_enemy)
		clear_map(mlx->map->map_enemy, mlx->map->height);
	if (mlx->map && mlx->map->map_floor)
		clear_map(mlx->map->map_floor, mlx->map->height);
	free_struct(mlx);
	if (mlx->mlx && mlx->win)
	{
		mlx_clear_window(mlx->mlx, mlx->win);
		mlx_destroy_window(mlx->mlx, mlx->win);
	}
	exit(exit_status);
}
