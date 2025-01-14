/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_floor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:35:39 by hdougoud          #+#    #+#             */
/*   Updated: 2025/01/13 13:58:38 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_floor(t_minilx *mlx)
{
	if (mlx->sprites->grass->frames[0])
		mlx_destroy_image(mlx->mlx, mlx->sprites->grass->frames[0]);
	if (mlx->sprites->grass->frames[1])
		mlx_destroy_image(mlx->mlx, mlx->sprites->grass->frames[1]);
	if (mlx->sprites->grass->frames[2])
		mlx_destroy_image(mlx->mlx, mlx->sprites->grass->frames[2]);
	if (mlx->sprites->grass->frames[3])
		mlx_destroy_image(mlx->mlx, mlx->sprites->grass->frames[3]);
	if (mlx->sprites->grass->frames[4])
		mlx_destroy_image(mlx->mlx, mlx->sprites->grass->frames[4]);
	if (mlx->sprites->grass->frames[5])
		mlx_destroy_image(mlx->mlx, mlx->sprites->grass->frames[5]);
	if (mlx->sprites->grass->frames[6])
		mlx_destroy_image(mlx->mlx, mlx->sprites->grass->frames[6]);
	if (mlx->sprites->grass->frames[7])
		mlx_destroy_image(mlx->mlx, mlx->sprites->grass->frames[7]);
	if (mlx->sprites->grass->frames[8])
		mlx_destroy_image(mlx->mlx, mlx->sprites->grass->frames[8]);
	if (mlx->sprites->grass->frames[9])
		mlx_destroy_image(mlx->mlx, mlx->sprites->grass->frames[9]);
}
