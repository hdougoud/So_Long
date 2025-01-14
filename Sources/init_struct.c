/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:20:55 by hdougoud          #+#    #+#             */
/*   Updated: 2025/01/13 18:31:06 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	secure_all_struct(t_minilx *mlx)
{
	mlx->sprites->player = NULL;
	mlx->sprites->portal = NULL;
	mlx->sprites->chest = NULL;
	mlx->sprites->enemy = NULL;
	mlx->sprites->grass = NULL;
	mlx->sprites->heart = NULL;
	mlx->sprites->wall = NULL;
}

static void	allocate_img_struct(t_minilx *mlx)
{
	mlx->sprites->player = malloc(sizeof(t_player));
	if (!mlx->sprites->player)
		show_error(mlx, MALLOC_ERROR);
	mlx->sprites->chest = malloc(sizeof(t_chest));
	if (!mlx->sprites->chest)
		show_error(mlx, MALLOC_ERROR);
	mlx->sprites->wall = malloc(sizeof(t_img));
	if (!mlx->sprites->wall)
		show_error(mlx, MALLOC_ERROR);
	mlx->sprites->enemy = malloc(sizeof(t_enemy));
	if (!mlx->sprites->enemy)
		show_error(mlx, MALLOC_ERROR);
	mlx->sprites->heart = malloc(sizeof(t_heart));
	if (!mlx->sprites->heart)
		show_error(mlx, MALLOC_ERROR);
	mlx->sprites->grass = malloc(sizeof(t_grass));
	if (!mlx->sprites->grass)
		show_error(mlx, MALLOC_ERROR);
	mlx->sprites->portal = malloc(sizeof(t_portal));
	if (!mlx->sprites->portal)
		show_error(mlx, MALLOC_ERROR);
}

void	allocate_struct(t_minilx *mlx)
{
	mlx->sprites = malloc(sizeof(t_sprite));
	if (!mlx->sprites)
		show_error(mlx, MALLOC_ERROR);
	secure_all_struct(mlx);
	allocate_img_struct(mlx);
	secure_all_img(mlx);
	mlx->map = malloc(sizeof(t_map));
	if (!mlx->map)
		show_error(mlx, MALLOC_ERROR);
}
