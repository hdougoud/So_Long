/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:35:40 by hdougoud          #+#    #+#             */
/*   Updated: 2025/01/13 20:50:07 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**copy_map(char **map, char **copyed_map, int i, int j)
{
	if (map[j][i] == '1')
		copyed_map[j][i] = '1';
	else if (map[j][i] == 'B')
		copyed_map[j][i] = 'B';
	else if (map[j][i] == 'D')
		copyed_map[j][i] = 'D';
	else if (map[j][i] == 'I')
		copyed_map[j][i] = 'I';
	else
		copyed_map[j][i] = '0';
	return (copyed_map);
}

char	**create_enemy_map(t_minilx *mlx, char **map)
{
	int		i;
	int		j;
	char	**copyed_map;

	j = 0;
	copyed_map = malloc(sizeof(char *) * (mlx->map->height + 1));
	if (!copyed_map)
		show_error(mlx, MALLOC_ERROR);
	while (map[j])
	{
		i = -1;
		copyed_map[j] = malloc(sizeof(char) * (mlx->map->width + 1));
		if (!copyed_map[j])
		{
			clear_map(copyed_map, j);
			show_error(mlx, MALLOC_ERROR);
		}
		while (map[j][++i])
			copyed_map = copy_map(map, copyed_map, i, j);
		copyed_map[j][i] = '\0';
		j++;
	}
	copyed_map[j] = NULL;
	return (copyed_map);
}

static int	check_enemy_next_move(t_minilx *mlx, int *x, int *y, int random)
{
	int	enemy_x;
	int	enemy_y;

	enemy_x = *x;
	enemy_y = *y;
	if (random == 0 && (mlx->map->map_enemy_copy[*y][*x + 1] != '1'
		&& mlx->map->map_enemy_copy[*y][*x + 1] != 'B'))
		enemy_x += 1;
	else if (random == 1 && (mlx->map->map_enemy_copy[*y][*x - 1] != '1'
		&& mlx->map->map_enemy_copy[*y][*x - 1] != 'B'))
		enemy_x -= 1;
	else if (random == 2 && (mlx->map->map_enemy_copy[*y + 1][*x] != '1'
		&& mlx->map->map_enemy_copy[*y + 1][*x] != 'B'))
		enemy_y += 1;
	else if (random == 3 && (mlx->map->map_enemy_copy[*y - 1][*x] != '1'
		&& mlx->map->map_enemy_copy[*y - 1][*x] != 'B'))
		enemy_y -= 1;
	else
		return (1);
	mlx->map->map_enemy_copy[*y][*x] = '0';
	put_previous_layer(mlx, *x, *y);
	*x = enemy_x;
	*y = enemy_y;
	return (0);
}

static void	move_enemy(t_minilx *mlx, int x, int y)
{
	int	random;

	random = rand() % (MAX_MOVE + 1);
	if (check_enemy_next_move(mlx, &x, &y, random))
		return ;
	mlx->map->map_enemy_copy[y][x] = 'B';
	put_previous_layer(mlx, x, y);
	ft_put_image(mlx, mlx->sprites->enemy->frames[0], x, y);
}

void	find_enemy(t_minilx *mlx, int param)
{
	int	height;
	int	width;

	height = -1;
	mlx->map->map_enemy_copy = create_enemy_map(mlx, mlx->map->map_enemy);
	while (mlx->map->map_enemy[++height])
	{
		width = -1;
		while (mlx->map->map_enemy[height][++width])
		{
			if (mlx->map->map_enemy[height][width] == 'B' && param == 1)
				move_enemy(mlx, width, height);
			else if (mlx->map->map_enemy[height][width] == 'B' && param == 2)
				next_enemy_frame(mlx, width, height);
		}
	}
	if (param == 2)
	{
		if (mlx->sprites->enemy->current_frame++ >= 4)
			mlx->sprites->enemy->current_frame = 0;
		mlx->sprites->enemy->current_frame++;
	}
	clear_map(mlx->map->map_enemy, mlx->map->height);
	mlx->map->map_enemy = mlx->map->map_enemy_copy;
	mlx->map->map_enemy_copy = NULL;
}
