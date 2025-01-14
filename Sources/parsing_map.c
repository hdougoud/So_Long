/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:13:02 by hdougoud          #+#    #+#             */
/*   Updated: 2025/01/13 14:07:02 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clear_map(char **map, int j)
{
	while (j >= 0)
	{
		free(map[j]);
		j--;
	}
	free(map);
}

static char	**copy_map(t_minilx *mlx)
{
	int		i;
	int		j;
	char	**map;

	j = 0;
	map = malloc(sizeof(char *) * (mlx->map->height + 1));
	if (!map)
		show_error(mlx, MALLOC_ERROR);
	while (mlx->map->map_tab[j])
	{
		i = -1;
		map[j] = malloc(sizeof(char) * (mlx->map->width + 1));
		if (!map)
		{
			clear_map(map, j);
			show_error(mlx, MALLOC_ERROR);
		}
		while (mlx->map->map_tab[j][++i])
			map[j][i] = mlx->map->map_tab[j][i];
		map[j][i] = '\0';
		j++;
	}
	map[j] = NULL;
	return (map);
}

static void	check_map_border(t_minilx *mlx)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (mlx->map->map_tab[y][x])
	{
		if (mlx->map->map_tab[y][x] != '1')
			show_error(mlx, WRONG_MAP_PATERN);
		x++;
	}
	while (++y < mlx->map->height - 2)
	{
		if ((mlx->map->map_tab[y][0] != '1')
				|| (mlx->map->map_tab[y][mlx->map->width - 1] != '1'))
			show_error(mlx, WRONG_MAP_PATERN);
	}
	x = 0;
	while (mlx->map->map_tab[mlx->map->height - 1][x])
	{
		if (mlx->map->map_tab[mlx->map->height - 1][x] != '1')
			show_error(mlx, WRONG_MAP_PATERN);
		x++;
	}
}

void	path_is_valide(t_minilx *mlx, t_parsing *parsing, int x, int y)
{
	if (x < 0 || y < 0 || y >= mlx->map->height || x >= mlx->map->width)
		return ;
	if (parsing->map[y][x] == '1' || parsing->map[y][x] == 'V')
		return ;
	if (parsing->map[y][x] == 'C')
		parsing->collectable++;
	if (parsing->map[y][x] == 'E')
		parsing->exit++;
	parsing->map[y][x] = 'V';
	path_is_valide(mlx, parsing, x + 1, y);
	path_is_valide(mlx, parsing, x, y + 1);
	path_is_valide(mlx, parsing, x - 1, y);
	path_is_valide(mlx, parsing, x, y - 1);
}

void	check_path_map(t_minilx *mlx)
{
	t_parsing	parsing;

	check_map_border(mlx);
	parsing.collectable = 0;
	parsing.exit = 0;
	parsing.map = copy_map(mlx);
	path_is_valide(mlx, &parsing, mlx->player_pos_x, mlx->player_pos_y);
	if (parsing.exit != mlx->map->exit_nb)
		show_error(mlx, EXIT_NOT_REACH);
	if (parsing.collectable != mlx->map->collectable_nb)
		show_error(mlx, C_NOT_REACH);
	clear_map(parsing.map, mlx->map->height);
}
