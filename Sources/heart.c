/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heart.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:27:45 by hdougoud          #+#    #+#             */
/*   Updated: 2025/01/13 20:48:20 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	no_heart(t_minilx *mlx)
{
	int	x;

	if (mlx->map->width < 4)
		x = 1;
	else
		x = 2;
	ft_put_image(mlx, mlx->sprites->heart->frames[2], mlx->map->width - x, 0);
	x++;
	ft_put_image(mlx, mlx->sprites->heart->frames[2], mlx->map->width - x, 0);
	x++;
	ft_put_image(mlx, mlx->sprites->heart->frames[2], mlx->map->width - x, 0);
}

static void	one_heart(t_minilx *mlx)
{
	int	x;

	if (mlx->map->width < 4)
		x = 1;
	else
		x = 2;
	ft_put_image(mlx, mlx->sprites->heart->frames[0], mlx->map->width - x, 0);
	x++;
	ft_put_image(mlx, mlx->sprites->heart->frames[2], mlx->map->width - x, 0);
	x++;
	ft_put_image(mlx, mlx->sprites->heart->frames[2], mlx->map->width - x, 0);
}

static void	two_heart(t_minilx *mlx)
{
	int	x;

	if (mlx->map->width < 4)
		x = 1;
	else
		x = 2;
	ft_put_image(mlx, mlx->sprites->heart->frames[0], mlx->map->width - x, 0);
	x++;
	ft_put_image(mlx, mlx->sprites->heart->frames[0], mlx->map->width - x, 0);
	x++;
	ft_put_image(mlx, mlx->sprites->heart->frames[2], mlx->map->width - x, 0);
}

static void	three_heart(t_minilx *mlx)
{
	int	x;

	if (mlx->map->width < 4)
		x = 1;
	else
		x = 2;
	ft_put_image(mlx, mlx->sprites->heart->frames[0], mlx->map->width - x, 0);
	x++;
	ft_put_image(mlx, mlx->sprites->heart->frames[0], mlx->map->width - x, 0);
	x++;
	ft_put_image(mlx, mlx->sprites->heart->frames[0], mlx->map->width - x, 0);
}

void	check_player_life(t_minilx *mlx)
{
	int	x;

	if (mlx->map->width < 4)
		x = 1;
	else
		x = 2;
	ft_put_floor(mlx, mlx->map->width - x, 0);
	ft_put_image(mlx, mlx->sprites->wall->name, mlx->map->width - x, 0);
	x++;
	ft_put_floor(mlx, mlx->map->width - x, 0);
	ft_put_image(mlx, mlx->sprites->wall->name, mlx->map->width - x, 0);
	x++;
	ft_put_floor(mlx, mlx->map->width - x, 0);
	ft_put_image(mlx, mlx->sprites->wall->name, mlx->map->width - x, 0);
	if (mlx->sprites->player->life == 3)
		three_heart(mlx);
	if (mlx->sprites->player->life == 2)
		two_heart(mlx);
	if (mlx->sprites->player->life == 1)
		one_heart(mlx);
	if (mlx->sprites->player->life <= 0)
		no_heart(mlx);
}
