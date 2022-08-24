/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esc_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:42:13 by tyuuki            #+#    #+#             */
/*   Updated: 2022/01/18 15:01:45 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	void	*no_texture;
	void	*so_texture;
	void	*we_texture;
	void	*ea_texture;
	char	*path_no;
	char	*path_so;
	char	*path_ea;
	char	*path_we;
	char	*path_f;
	char	*path_c;
	int		size_x;
	int		size_y;
}			t_mlx;

typedef struct s_gameinfo
{
	char	**game_settings;
	char	**map;
	int		nb_players;
	int		y_map;
	int		x_pos;
	int		y_pos;
	int		dir_player;
	int		color_c;
	int		color_f;
	int		size_texute;
}			t_gameinfo;

typedef struct s_raycast
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	int		width;
	double	height;
	double	plane_x;
	double	plane_y;
	double	move_speed;
	double	rot_speed;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_y;
	int		map_x;
	double	side_dist_y;
	double	side_dist_x;
	double	delta_dist_y;
	double	delta_dist_x;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		color;
	int		buff[480][640];
	int		**texture;
	int		tex_num;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;
}			t_raycast;

typedef struct s_cub3d
{
	t_gameinfo	*gameinfo;
	t_mlx		*mlx_info;
	t_raycast	*raycast;
	t_img		*img;
	t_img		*img_clear;
}				t_cub3d;

#endif