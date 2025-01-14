/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:33:10 by hdougoud          #+#    #+#             */
/*   Updated: 2025/01/13 20:54:30 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	show_warning_2(int error_nb)
{
	if (error_nb == WRONG_MAP_PATERN)
		ft_putendl_fd(COLOR_YELLOW
			"Wrong map patern, the map must be surrounded by walls, "
			"the exit and all collectibles must"
			" be accessible to the player", 2);
	else if (error_nb == WINDOWS_TOO_BIG)
		ft_putendl_fd(COLOR_YELLOW "Map too big for this resolution", 2);
	else if (error_nb == EXIT_NOT_REACH)
		ft_putendl_fd(COLOR_YELLOW "The exit is not reachable", 2);
	else if (error_nb == C_NOT_REACH)
		ft_putendl_fd(COLOR_YELLOW "all collectable is not reachable", 2);
}

static void	show_warning(int error_nb)
{
	if (error_nb == WRONG_ARGUMENTS)
		ft_putendl_fd(COLOR_YELLOW
			"wrong number of agrument, please selecte one map", 2);
	else if (error_nb == WRONG_EXT)
		ft_putendl_fd(COLOR_YELLOW
			"wrong extension : this program can only read .ber files", 2);
	else if (error_nb == WRONG_MAP_SIZE)
		ft_putendl_fd(COLOR_YELLOW
			"wrong map size : map need to be a rectangle", 2);
	else if (error_nb == BAD_CHAR)
		ft_putendl_fd(COLOR_YELLOW
			"invalid map: character not recognized on the map file", 2);
	else if (error_nb == TOO_MUCH_EXIT)
		ft_putendl_fd(COLOR_YELLOW
			"wrong number of exit, there can only be one exit on the map", 2);
	else if (error_nb == TOO_MUCH_PLAYER)
		ft_putendl_fd(COLOR_YELLOW
			"wrong number of player, "
			"ther can only be one player on the map", 2);
	else if (error_nb == UNDER_COLLECIBLE)
		ft_putendl_fd(COLOR_YELLOW
			"Not enough collectives, there must be at least one on the map", 2);
	else
		show_warning_2(error_nb);
}

void	show_error(t_minilx *mlx, int error_nb)
{
	ft_putendl_fd(COLOR_RED "Error", 2);
	if (error_nb == MALLOC_ERROR)
		perror(COLOR_RED "Malloc failed");
	else if (error_nb == CANNOT_OPEN_FILE)
		perror(COLOR_YELLOW "Can't open file");
	else if (error_nb == SERVER_X)
		perror(COLOR_RED "can't link to X server");
	else if (error_nb == WINDOW_ERROR)
		perror(COLOR_RED "can't create windows");
	else
		show_warning(error_nb);
	ft_printf(COLOR_RESET);
	quit_properly(mlx, EXIT_FAILURE);
}
