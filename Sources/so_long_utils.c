/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 09:56:02 by hdougoud          #+#    #+#             */
/*   Updated: 2025/01/13 20:47:51 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	xpm_to_map(t_minilx *mlx, int width, int height)
{
	ft_put_floor(mlx, width, height);
	if (mlx->map->map_tab[height][width] == '1')
		ft_put_image(mlx, mlx->sprites->wall->name, width, height);
	else if (mlx->map->map_tab[height][width] == 'P')
		ft_put_image(mlx, mlx->sprites->player->frames[0], width, height);
	else if (mlx->map->map_tab[height][width] == 'E')
	{
		mlx->sprites->portal->pos_x = width;
		mlx->sprites->portal->pos_y = height;
	}
	else if (mlx->map->map_tab[height][width] == 'C')
		ft_put_image(mlx, mlx->sprites->chest->frames[0], width, height);
	else if (mlx->map->map_tab[height][width] == 'B')
		ft_put_image(mlx, mlx->sprites->enemy->frames[0], width, height);
}

void	open_chest(t_minilx *mlx)
{
	if (mlx->sprites->chest->is_animating == 1)
		return ;
	if (mlx->map->map_tab[mlx->player_pos_y][mlx->player_pos_x] == 'C')
	{
		mlx->map->map_tab[mlx->player_pos_y][mlx->player_pos_x] = 'O';
		mlx->sprites->chest->posx = mlx->player_pos_x;
		mlx->sprites->chest->posy = mlx->player_pos_y;
		mlx->sprites->chest->is_animating = 1;
		mlx->map->collectable_nb--;
	}
	else if (mlx->map->map_tab[mlx->player_pos_y][mlx->player_pos_x - 1] == 'C')
	{
		mlx->map->map_tab[mlx->player_pos_y][mlx->player_pos_x - 1] = 'O';
		mlx->sprites->chest->posx = mlx->player_pos_x -1;
		mlx->sprites->chest->posy = mlx->player_pos_y;
		mlx->sprites->chest->is_animating = 1;
		mlx->map->collectable_nb--;
	}
}

int	windows_closed(t_minilx *mlx)
{
	quit_properly(mlx, EXIT_SUCCESS);
	return (0);
}

void	ft_put_image(t_minilx *mlx, t_img *img, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, img,
		x * TEXTURE_SIZE, y * TEXTURE_SIZE);
}

char	*strdup_map_line(t_minilx *mlx, char *str)
{
	int		i;
	int		str_len;
	char	*ptr;

	i = 0;
	str_len = ft_strlen(str);
	if (str[str_len - 1] == '\n')
		str_len -= 1;
	ptr = malloc(sizeof(char) * (str_len) + 1);
	if (!ptr)
		show_error(mlx, MALLOC_ERROR);
	while (i < str_len)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
