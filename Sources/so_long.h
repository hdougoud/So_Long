/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:40:14 by hdougoud          #+#    #+#             */
/*   Updated: 2025/12/30 03:36:00 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/libft/libft.h"
# include <errno.h>
# include <time.h>
# include <mlx.h>

# define TEXTURE_SIZE		64
# define MAX_EXIT			1
# define MAX_PLAYER			1
# define MIN_COLLECTABLE	1
# define SCREEN_SIZE_X		5120
# define SCREEN_SIZE_Y		2880
# define MAX_MOVE			3
# define MAX_LEVEL			1

/*----------------------------------Keycode----------------------------------*/

# define ESC				53
# define E					14
# define W					13
# define A					0
# define S					1
# define D					2
# define UP					126
# define LEFT				123
# define DOWN				125
# define RIGHT				124
# define SPACE				49

/*-----------------------------------Error-----------------------------------*/

# define MALLOC_ERROR		0
# define CANNOT_OPEN_FILE	1
# define WRONG_ARGUMENTS	2
# define WRONG_EXT			3
# define WRONG_MAP_SIZE		4
# define SERVER_X			5
# define WINDOW_ERROR		6
# define BAD_CHAR			7
# define TOO_MUCH_EXIT		8
# define TOO_MUCH_PLAYER	9
# define UNDER_COLLECIBLE	10
# define WRONG_MAP_PATERN	11
# define WINDOWS_TOO_BIG	12
# define EXIT_NOT_REACH		13
# define C_NOT_REACH		14

/*-----------------------------------Struct----------------------------------*/

typedef struct s_img
{
	void	*name;
	int		x;
	int		y;
}			t_img;

typedef struct s_parsing
{
	char	**map;
	int		collectable;
	int		exit;
}			t_parsing;

typedef struct s_chest
{
	void	*frames[4];
	int		current_frame;
	int		is_animating;
	int		posx;
	int		posy;
	int		x;
	int		y;
}			t_chest;

typedef struct s_player
{
	void	*frames[8];
	void	*dth_frames[8];
	void	*dsh_frames[8];
	int		current_frame;
	int		dth_current_frame;
	int		dsh_current_frame;
	int		life;
	int		dash;
	int		x;
	int		y;
}			t_player;

typedef struct s_enemy
{
	void	*frames[5];
	void	*dth_frames[6];
	int		current_frame;
	int		dth_current_frame;
	int		delayed_frame;
	int		x;
	int		y;
}			t_enemy;

typedef struct s_heart
{
	void	*frames[3];
	int		current_frame;
	int		x;
	int		y;
}			t_heart;

typedef struct s_grass
{
	void	*frames[10];
	int		current_frame;
	int		x;
	int		y;
}			t_grass;

typedef struct s_portal
{
	void	*frames[7];
	void	*opn_frames[5];
	int		current_frame;
	int		opn_current_frame;
	int		is_open;
	int		pos_x;
	int		pos_y;
	int		x;
	int		y;
}			t_portal;

typedef struct s_sprite
{
	t_img		*wall;
	t_chest		*chest;
	t_enemy		*enemy;
	t_heart		*heart;
	t_player	*player;
	t_grass		*grass;
	t_portal	*portal;
}				t_sprite;

typedef struct s_map
{
	char	**map_tab;
	char	**map_enemy;
	char	**map_enemy_copy;
	char	**map_floor;
	int		max_map_frames;
	int		height;
	int		width;
	int		exit_nb;
	int		player_nb;
	int		collectable_nb;
	int		level;
}			t_map;

typedef struct s_minilx
{
	void		*mlx;
	void		*win;
	t_sprite	*sprites;
	t_map		*map;
	int			player_pos_x;
	int			player_pos_y;
	int			screen_size_x;
	int			screen_size_y;
	int			movement;
	int			frame_count;
	int			frames_rates;
	int			delayed_frame;
}				t_minilx;

/*----------------------------------Functions--------------------------------*/

/*-------------INIT-STRUCT-------------*/

void	init_minilx(t_minilx *mlx);
void	file_to_image(t_minilx *mlx);
void	secure_all_img(t_minilx *mlx);
void	allocate_struct(t_minilx *mlx);
void	create_floor_map(t_minilx *mlx);
void	load_enemy_image(t_minilx *mlx);
void	load_portal_img(t_minilx *mlx);
void	load_dash_player(t_minilx *mlx);
void	load_player_image(t_minilx *mlx);
void	load_level1_images(t_minilx *mlx);
void	load_level2_images(t_minilx *mlx);
void	init_map(t_minilx *mlx, char *map_name);
void	ft_put_floor(t_minilx *mlx, int x, int y);

/*--------------GAMEPLAY---------------*/

void	open_chest(t_minilx *mlx);
void	open_portal(t_minilx *mlx);
void	player_idle(t_minilx *mlx);
void	player_dash(t_minilx *mlx);
void	player_death(t_minilx *mlx);
void	check_enemy_hits(t_minilx *mlx);
void	check_player_life(t_minilx *mlx);
void	check_player_life(t_minilx *mlx);
void	find_enemy(t_minilx *mlx, int param);

/*-------------CLEAR-STRUCT------------*/

void	clean_player_img(t_minilx *mlx);
void	clean_enemy_img(t_minilx *mlx);
void	clean_floor(t_minilx *mlx);
void	clean_portal_img(t_minilx *mlx);
void	clear_map(char **map, int j);
void	quit_properly(t_minilx *mlx, int exit_status);

/*----------------UTILS----------------*/

int		next_frame(t_minilx *mlx);
int		windows_closed(t_minilx *mlx);
int		hook_keyboard(int keycode, t_minilx *mlx);

void	check_path_map(t_minilx *mlx);
void	show_error(t_minilx *mlx, int error_nb);
void	next_enemy_frame(t_minilx *mlx, int x, int y);
void	put_previous_layer(t_minilx *mlx, int x, int y);
void	xpm_to_map(t_minilx *mlx, int width, int height);
void	ft_put_image(t_minilx *mlx, t_img *img, int width, int height);

char	*strdup_map_line(t_minilx *mlx, char *str);
char	**create_enemy_map(t_minilx *mlx, char **map);

#endif