/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_portal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:56:15 by hdougoud          #+#    #+#             */
/*   Updated: 2025/01/14 11:30:36 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	clean_portal_open(t_minilx *mlx)
{
	if (mlx->sprites->portal->opn_frames[0])
		mlx_destroy_image(mlx->mlx, mlx->sprites->portal->opn_frames[0]);
	if (mlx->sprites->portal->opn_frames[1])
		mlx_destroy_image(mlx->mlx, mlx->sprites->portal->opn_frames[1]);
	if (mlx->sprites->portal->opn_frames[2])
		mlx_destroy_image(mlx->mlx, mlx->sprites->portal->opn_frames[2]);
	if (mlx->sprites->portal->opn_frames[3])
		mlx_destroy_image(mlx->mlx, mlx->sprites->portal->opn_frames[3]);
	if (mlx->sprites->portal->opn_frames[4])
		mlx_destroy_image(mlx->mlx, mlx->sprites->portal->opn_frames[4]);
}

void	clean_portal_img(t_minilx *mlx)
{
	if (mlx->sprites->portal->frames[0])
		mlx_destroy_image(mlx->mlx, mlx->sprites->portal->frames[0]);
	if (mlx->sprites->portal->frames[1])
		mlx_destroy_image(mlx->mlx, mlx->sprites->portal->frames[1]);
	if (mlx->sprites->portal->frames[2])
		mlx_destroy_image(mlx->mlx, mlx->sprites->portal->frames[2]);
	if (mlx->sprites->portal->frames[3])
		mlx_destroy_image(mlx->mlx, mlx->sprites->portal->frames[3]);
	if (mlx->sprites->portal->frames[4])
		mlx_destroy_image(mlx->mlx, mlx->sprites->portal->frames[4]);
	if (mlx->sprites->portal->frames[5])
		mlx_destroy_image(mlx->mlx, mlx->sprites->portal->frames[5]);
	if (mlx->sprites->portal->frames[6])
		mlx_destroy_image(mlx->mlx, mlx->sprites->portal->frames[6]);
	clean_portal_open(mlx);
}
