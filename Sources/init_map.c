/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:01:26 by hdougoud          #+#    #+#             */
/*   Updated: 2025/01/14 10:54:28 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	show_map(t_minilx *mlx)
{
	int	height;
	int	width;

	height = 0;
	if (mlx->map->width * TEXTURE_SIZE > mlx->screen_size_x
		|| mlx->map->height * TEXTURE_SIZE > mlx->screen_size_y)
		show_error(mlx, WINDOWS_TOO_BIG);
	mlx->win = mlx_new_window(mlx->mlx, (mlx->map->width * TEXTURE_SIZE),
			(mlx->map->height * TEXTURE_SIZE), "so_long");
	if (!mlx->win)
		show_error(mlx, WINDOW_ERROR);
	create_floor_map(mlx);
	while (mlx->map->map_tab[height])
	{
		width = 0;
		while (mlx->map->map_tab[height][width])
		{
			xpm_to_map(mlx, width, height);
			width++;
		}
		height++;
	}
}

static void	validate_map_char(t_minilx *mlx, int height)
{
	int	width;

	width = 0;
	while (mlx->map->map_tab[height][width])
	{
		if ((mlx->map->map_tab[height][width] != '0')
				&& (mlx->map->map_tab[height][width] != '1')
				&& (mlx->map->map_tab[height][width] != 'E')
				&& (mlx->map->map_tab[height][width] != 'C')
				&& (mlx->map->map_tab[height][width] != 'P')
				&& (mlx->map->map_tab[height][width] != 'B'))
			show_error(mlx, BAD_CHAR);
		if (mlx->map->map_tab[height][width] == 'C')
			mlx->map->collectable_nb++;
		else if (mlx->map->map_tab[height][width] == 'P')
		{
			mlx->player_pos_x = width;
			mlx->player_pos_y = height;
			mlx->map->player_nb++;
		}
		else if (mlx->map->map_tab[height][width] == 'E')
			mlx->map->exit_nb++;
		width++;
	}
}

static void	validate_map_size(t_minilx *mlx)
{
	int		height;
	size_t	map_line_len;

	height = 0;
	map_line_len = ft_strlen(mlx->map->map_tab[0]);
	while (mlx->map->map_tab[height])
	{
		validate_map_char(mlx, height);
		if (map_line_len != ft_strlen(mlx->map->map_tab[height]))
			show_error(mlx, WRONG_MAP_SIZE);
		height++;
	}
	mlx->map->width = map_line_len;
	mlx->map->height = height;
	if (mlx->map->collectable_nb < MIN_COLLECTABLE)
		show_error(mlx, UNDER_COLLECIBLE);
	if (mlx->map->exit_nb != MAX_EXIT)
		show_error(mlx, TOO_MUCH_EXIT);
	if (mlx->map->player_nb != MAX_PLAYER)
		show_error(mlx, TOO_MUCH_PLAYER);
}

static void	convert_map_tab(t_minilx *mlx, char *map_name, int map_height)
{
	int		fd;
	int		height;
	char	*map_line;

	height = 0;
	mlx->map->map_tab = malloc(sizeof(char *) * (map_height + 1));
	if (!mlx->map->map_tab)
		show_error(mlx, MALLOC_ERROR);
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		show_error(mlx, CANNOT_OPEN_FILE);
	while (1)
	{
		map_line = get_next_line(fd);
		if (map_line == NULL)
			break ;
		mlx->map->map_tab[height] = strdup_map_line(mlx, map_line);
		height++;
		free(map_line);
	}
	mlx->map->map_tab[height] = NULL;
	close(fd);
}

void	init_map(t_minilx *mlx, char *map_name)
{
	int		fd;
	char	*ext;
	char	buff[1];
	int		map_height;

	map_height = 1;
	ext = ft_strnstr(map_name, ".ber", ft_strlen(map_name));
	if (ext == NULL)
		show_error(mlx, WRONG_EXT);
	if (ft_strncmp(ext, ".ber", 5) != 0)
		show_error(mlx, WRONG_EXT);
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		show_error(mlx, CANNOT_OPEN_FILE);
	while (read(fd, buff, 1) == 1)
	{
		if (buff[0] == '\n')
			map_height++;
	}
	convert_map_tab(mlx, map_name, map_height);
	close (fd);
	validate_map_size(mlx);
	show_map(mlx);
}
