/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:01:37 by hdougoud          #+#    #+#             */
/*   Updated: 2025/01/13 19:49:05 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	idle_portal(t_minilx *mlx, int x, int y)
{
	put_previous_layer(mlx, x, y);
	ft_put_image(mlx, mlx->sprites->portal->frames
	[mlx->sprites->portal->current_frame], x, y);
	if (mlx->sprites->portal->current_frame >= 6)
		mlx->sprites->portal->current_frame = 0;
	mlx->sprites->portal->current_frame++;
}

void	open_portal(t_minilx *mlx)
{
	int	x;
	int	y;

	x = mlx->sprites->portal->pos_x;
	y = mlx->sprites->portal->pos_y;
	if (mlx->sprites->portal->is_open == 1)
	{
		idle_portal(mlx, x, y);
		return ;
	}
	put_previous_layer(mlx, x, y);
	ft_put_image(mlx,
		mlx->sprites->portal->opn_frames
	[mlx->sprites->portal->opn_current_frame], x, y);
	if (mlx->sprites->portal->opn_current_frame >= 4)
		mlx->sprites->portal->is_open = 1;
	mlx->sprites->portal->opn_current_frame++;
}
