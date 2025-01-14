/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_image_portal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:09:02 by hdougoud          #+#    #+#             */
/*   Updated: 2025/01/13 19:47:49 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_portal_open(t_minilx *mlx)
{
	mlx->sprites->portal->opn_frames[0] = mlx_xpm_file_to_image(mlx->mlx,
			"Sprites/Portal/Open/Open_1.xpm",
			&mlx->sprites->portal->x, &mlx->sprites->portal->y);
	if (!mlx->sprites->portal->opn_frames[0])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->portal->opn_frames[1] = mlx_xpm_file_to_image(mlx->mlx,
			"Sprites/Portal/Open/Open_2.xpm",
			&mlx->sprites->portal->x, &mlx->sprites->portal->y);
	if (!mlx->sprites->portal->opn_frames[1])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->portal->opn_frames[2] = mlx_xpm_file_to_image(mlx->mlx,
			"Sprites/Portal/Open/Open_3.xpm",
			&mlx->sprites->portal->x, &mlx->sprites->portal->y);
	if (!mlx->sprites->portal->opn_frames[2])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->portal->opn_frames[3] = mlx_xpm_file_to_image(mlx->mlx,
			"Sprites/Portal/Open/Open_4.xpm",
			&mlx->sprites->portal->x, &mlx->sprites->portal->y);
	if (!mlx->sprites->portal->opn_frames[3])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->portal->opn_frames[4] = mlx_xpm_file_to_image(mlx->mlx,
			"Sprites/Portal/Open/Open_5.xpm",
			&mlx->sprites->portal->x, &mlx->sprites->portal->y);
	if (!mlx->sprites->portal->opn_frames[4])
		show_error(mlx, CANNOT_OPEN_FILE);
}

static void	load_portal_idle_2(t_minilx *mlx)
{
	mlx->sprites->portal->frames[4] = mlx_xpm_file_to_image(mlx->mlx,
			"Sprites/Portal/Idle/Portal_5.xpm",
			&mlx->sprites->portal->x, &mlx->sprites->portal->y);
	if (!mlx->sprites->portal->frames[4])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->portal->frames[5] = mlx_xpm_file_to_image(mlx->mlx,
			"Sprites/Portal/Idle/Portal_6.xpm",
			&mlx->sprites->portal->x, &mlx->sprites->portal->y);
	if (!mlx->sprites->portal->frames[5])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->portal->frames[6] = mlx_xpm_file_to_image(mlx->mlx,
			"Sprites/Portal/Idle/Portal_7.xpm",
			&mlx->sprites->portal->x, &mlx->sprites->portal->y);
	if (!mlx->sprites->portal->frames[6])
		show_error(mlx, CANNOT_OPEN_FILE);
}

static void	load_portal_idle(t_minilx *mlx)
{
	mlx->sprites->portal->frames[0] = mlx_xpm_file_to_image(mlx->mlx,
			"Sprites/Portal/Idle/Portal_1.xpm",
			&mlx->sprites->portal->x, &mlx->sprites->portal->y);
	if (!mlx->sprites->portal->frames[0])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->portal->frames[1] = mlx_xpm_file_to_image(mlx->mlx,
			"Sprites/Portal/Idle/Portal_2.xpm",
			&mlx->sprites->portal->x, &mlx->sprites->portal->y);
	if (!mlx->sprites->portal->frames[1])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->portal->frames[2] = mlx_xpm_file_to_image(mlx->mlx,
			"Sprites/Portal/Idle/Portal_3.xpm",
			&mlx->sprites->portal->x, &mlx->sprites->portal->y);
	if (!mlx->sprites->portal->frames[2])
		show_error(mlx, CANNOT_OPEN_FILE);
	mlx->sprites->portal->frames[3] = mlx_xpm_file_to_image(mlx->mlx,
			"Sprites/Portal/Idle/Portal_4.xpm",
			&mlx->sprites->portal->x, &mlx->sprites->portal->y);
	if (!mlx->sprites->portal->frames[3])
		show_error(mlx, CANNOT_OPEN_FILE);
}

void	load_portal_img(t_minilx *mlx)
{
	load_portal_idle(mlx);
	load_portal_idle_2(mlx);
	load_portal_open(mlx);
}
