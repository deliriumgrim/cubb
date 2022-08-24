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

#include "includes/cub3d.h"

int	loop(t_cub3d *this)
{
	raycast(this);
	draw(this);
	return (0);
}

void	write_dir_info_help(t_cub3d *this)
{
	if (this->gameinfo->dir_player == 3)
	{
		this->raycast->dir_x = -0.01;
		this->raycast->dir_y = -0.999;
		this->raycast->plane_x = -0.659;
		this->raycast->plane_y = 0.006;
	}
	else if (this->gameinfo->dir_player == 4)
	{
		this->raycast->dir_x = -0.999;
		this->raycast->dir_y = 0.01;
		this->raycast->plane_x = 0.006;
		this->raycast->plane_y = 0.659;
	}
}

void	write_dir_info(t_cub3d *this)
{
	if (this->gameinfo->dir_player == 1)
	{
		this->raycast->dir_x = 0.01;
		this->raycast->dir_y = 0.999;
		this->raycast->plane_x = 0.659;
		this->raycast->plane_y = -0.006;
	}
	else if (this->gameinfo->dir_player == 2)
	{
		this->raycast->dir_x = 1;
		this->raycast->dir_y = 0;
		this->raycast->plane_x = 0;
		this->raycast->plane_y = -0.66;
	}
	write_dir_info_help(this);
}

void	write_info(t_cub3d *this)
{
	this->raycast->pos_x = this->gameinfo->x_pos + 0.5;
	this->raycast->pos_y = this->gameinfo->y_pos + 0.5;
	this->raycast->width = 640;
	this->raycast->height = 480;
	write_dir_info(this);
	this->raycast->move_speed = 0.05;
	this->raycast->rot_speed = 0.05;
}

int	main(int argc, char **argv)
{
	t_cub3d	this;

	if (argc != 2)
		return (1);
	cub3d_init(&this);
	check_filename(argv[1]);
	game_init(&this, argv[1], 1);
	game_init(&this, argv[1], 2);
	params_valid(&this);
	map_valid(&this);
	write_params(&this);
	init_mlx(&this);
	write_info(&this);
	put_floor_celling(&this);
	mlx_hook(this.mlx_info->mlx_win, 2, 1L << 0, &player_control, &this);
	mlx_hook(this.mlx_info->mlx_win, 17, 0, ft_exit, &this);
	mlx_loop_hook(this.mlx_info->mlx, &loop, &this);
	mlx_loop(this.mlx_info->mlx);
	ft_exit(&this);
}
