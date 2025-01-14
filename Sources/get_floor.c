/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_floor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:22:18 by hdougoud          #+#    #+#             */
/*   Updated: 2025/01/13 16:06:08 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	malloc_map_line(t_minilx *mlx, int y)
{
	mlx->map->map_floor[y] = malloc(sizeof(char) * (mlx->map->width + 1));
	if (!mlx->map->map_floor[y])
	{
		clear_map(mlx->map->map_floor, y);
		show_error(mlx, MALLOC_ERROR);
	}
}

void	create_floor_map(t_minilx *mlx)
{
	int	y;
	int	x;
	int	random;

	y = 0;
	srand(time(NULL));
	mlx->map->map_floor = malloc(sizeof(char *) * (mlx->map->height + 1));
	if (mlx->map->map_floor)
	{
		while (y < mlx->map->height)
		{
			malloc_map_line(mlx, y);
			x = 0;
			while (x < mlx->map->width)
			{
				random = rand() % (mlx->map->max_map_frames + 1);
				mlx->map->map_floor[y][x] = (random + 65);
				x++;
			}
			mlx->map->map_floor[y][x] = '\0';
			y++;
		}
	}
	mlx->map->map_floor[y] = NULL;
}

void	ft_put_floor(t_minilx *mlx, int x, int y)
{
	if (mlx->map->map_floor[y][x] == 'A')
		ft_put_image(mlx, mlx->sprites->grass->frames[0], x, y);
	if (mlx->map->map_floor[y][x] == 'B')
		ft_put_image(mlx, mlx->sprites->grass->frames[1], x, y);
	if (mlx->map->map_floor[y][x] == 'C')
		ft_put_image(mlx, mlx->sprites->grass->frames[2], x, y);
	if (mlx->map->map_floor[y][x] == 'D')
		ft_put_image(mlx, mlx->sprites->grass->frames[3], x, y);
	if (mlx->map->map_floor[y][x] == 'E')
		ft_put_image(mlx, mlx->sprites->grass->frames[4], x, y);
	if (mlx->map->map_floor[y][x] == 'F')
		ft_put_image(mlx, mlx->sprites->grass->frames[5], x, y);
	if (mlx->map->map_floor[y][x] == 'G')
		ft_put_image(mlx, mlx->sprites->grass->frames[6], x, y);
	if (mlx->map->map_floor[y][x] == 'H')
		ft_put_image(mlx, mlx->sprites->grass->frames[7], x, y);
	if (mlx->map->map_floor[y][x] == 'I')
		ft_put_image(mlx, mlx->sprites->grass->frames[8], x, y);
	if (mlx->map->map_floor[y][x] == 'J')
		ft_put_image(mlx, mlx->sprites->grass->frames[9], x, y);
}
