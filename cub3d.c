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

void	draw(t_cub3d *this)
{
	int	x;
	int	y;

	y = 0;
	while (y < 480)
	{
		x = 0;
		while (x < 640)
		{
			this->img->addr[y * 640 + x] = this->raycast->buff[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(this->mlx_info->mlx, \
	this->mlx_info->mlx_win, this->img->img, 0, 0);
	y = 0;
	while (y < 480)
	{
		x = 0;
		while (x < 640)
		{
			this->raycast->buff[y][x] = this->img_clear->addr[y * 640 + x];
			x++;
		}
		y++;
	}
}

int	raycast(t_cub3d *this)
{
	int	x;
	int	y;

	x = 0;
	while (x < this->raycast->width)
	{
		this->raycast->camera_x = 2 * x \
		(double)this->raycast->width - 1;
		this->raycast->ray_dir_x = this->raycast->dir_x \
		+ this->raycast->plane_x * this->raycast->camera_x;
		this->raycast->ray_dir_y = this->raycast->dir_y \
		+ this->raycast->plane_y * this->raycast->camera_x;
		this->raycast->map_x = (int)this->raycast->pos_x;
		this->raycast->map_y = (int)this->raycast->pos_y;
		this->raycast->delta_dist_x = fabs(1 / this->raycast->ray_dir_x);
		this->raycast->delta_dist_y = fabs(1 / this->raycast->ray_dir_y);
		if (this->raycast->ray_dir_x < 0)
		{
			this->raycast->step_x = -1;
			this->raycast->side_dist_x \
			= (this->raycast->pos_x - this->raycast->map_x)
					* this->raycast->delta_dist_x;
		}
		else
		{
			this->raycast->step_x = 1;
			this->raycast->side_dist_x \
			= (this->raycast->map_x + 1.0 - this->raycast->pos_x)
					* this->raycast->delta_dist_x;
		}
		if (this->raycast->ray_dir_y < 0)
		{
			this->raycast->step_y = -1;
			this->raycast->side_dist_y \
			= (this->raycast->pos_y - this->raycast->map_y) \
			* this->raycast->delta_dist_y;
		}
		else
		{
			this->raycast->step_y = 1;
			this->raycast->side_dist_y \
			= (this->raycast->map_y + 1.0 - this->raycast->pos_y) \
			* this->raycast->delta_dist_y;
		}
		this->raycast->hit = 0;
		while (this->raycast->hit == 0)
		{
			if (this->raycast->side_dist_x < this->raycast->side_dist_y)
			{
				this->raycast->side_dist_x += this->raycast->delta_dist_x;
				this->raycast->map_x += this->raycast->step_x;
				this->raycast->side = 0;
			}
			else
			{
				this->raycast->side_dist_y += this->raycast->delta_dist_y;
				this->raycast->map_y += this->raycast->step_y;
				this->raycast->side = 1;
			}
			if (this->gameinfo->map[this->raycast->map_y] \
			[this->raycast->map_x] != '0' \
			&& this->gameinfo->map[this->raycast->map_y] \
			[this->raycast->map_x] != 'N' \
			&& this->gameinfo->map[this->raycast->map_y] \
			[this->raycast->map_x] != 'W' \
			&& this->gameinfo->map[this->raycast->map_y] \
			[this->raycast->map_x] != 'E' \
			&& this->gameinfo->map[this->raycast->map_y] \
			[this->raycast->map_x] != 'S')
				this->raycast->hit = 1;
		}
		if (this->raycast->side == 0)
			this->raycast->perp_wall_dist \
			= (this->raycast->map_x - this->raycast->pos_x \
			+ (1 - this->raycast->step_x) / 2) / this->raycast->ray_dir_x;
		else
			this->raycast->perp_wall_dist \
			= (this->raycast->map_y - this->raycast->pos_y \
			+ (1 - this->raycast->step_y) / 2) / this->raycast->ray_dir_y;
		this->raycast->line_height \
		= (int)(this->raycast->height / this->raycast->perp_wall_dist);
		this->raycast->draw_start \
		= -this->raycast->line_height / 2 + this->raycast->height / 2;
		if (this->raycast->draw_start < 0)
			this->raycast->draw_start = 0;
		this->raycast->draw_end \
		= this->raycast->line_height / 2 + this->raycast->height / 2;
		if (this->raycast->draw_end >= this->raycast->height)
			this->raycast->draw_end = this->raycast->height - 1;
		this->raycast->tex_num \
		= this->gameinfo->map[this->raycast->map_y][this->raycast->map_x];
		if (this->raycast->side == 0)
			this->raycast->wall_x \
			= this->raycast->pos_y + this->raycast->perp_wall_dist \
			* this->raycast->ray_dir_y;
		else
			this->raycast->wall_x \
			= this->raycast->pos_x + this->raycast->perp_wall_dist \
			* this->raycast->ray_dir_x;
		this->raycast->wall_x -= floor(this->raycast->wall_x);
		this->raycast->tex_x = (int)(this->raycast->wall_x * (double)64);
		if (this->raycast->side == 0 && this->raycast->ray_dir_x > 0)
			this->raycast->tex_x = 64 - this->raycast->tex_x - 1;
		if (this->raycast->side == 1 && this->raycast->ray_dir_y < 0)
			this->raycast->tex_x = 64 - this->raycast->tex_x - 1;
		this->raycast->step = 1.0 * 64 / this->raycast->line_height;
		this->raycast->tex_pos \
		= (this->raycast->draw_start - 480 / 2 \
		+ this->raycast->line_height / 2) \
		* this->raycast->step;
		if ((this->raycast->ray_dir_x < 0 \
			&& this->raycast->ray_dir_y < 0 \
			&& this->raycast->side == 1)
			|| (this->raycast->ray_dir_x > 0 && this->raycast->ray_dir_y < 0 \
			&& this->raycast->side == 1))
			this->raycast->tex_num = 0;
		if ((this->raycast->ray_dir_x < 0 && this->raycast->ray_dir_y > 0 \
		&& this->raycast->side == 1)
			|| (this->raycast->ray_dir_x > 0 \
			&& this->raycast->ray_dir_y > 0 \
			&& this->raycast->side == 1))
			this->raycast->tex_num = 1;
		if ((this->raycast->ray_dir_x < 0 && this->raycast->ray_dir_y > 0 \
		&& this->raycast->side == 0)
			|| (this->raycast->ray_dir_x < 0 && this->raycast->ray_dir_y < 0 \
			&& this->raycast->side == 0))
			this->raycast->tex_num = 2;
		y = this->raycast->draw_start;
		while (y < this->raycast->draw_end)
		{
			this->raycast->tex_y = (int)this->raycast->tex_pos & (64 - 1);
			this->raycast->tex_pos += this->raycast->step;
			if (this->raycast->tex_num == 49)
				this->raycast->tex_num = 3;
			this->raycast->color \
			= this->raycast->texture[this->raycast->tex_num] \
			[this->raycast->tex_y * 64 + this->raycast->tex_x];
			this->raycast->buff[y][x] = this->raycast->color;
			y++;
		}
		x++;
	}
	return (0);
}

int	loop(t_cub3d *this)
{
	raycast(this);
	draw(this);
	return (0);
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
	else if (this->gameinfo->dir_player == 3)
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

void	put_floor_celling(t_cub3d *this)
{
	int	x;
	int	y;
	int	color;

	color = this->gameinfo->color_c;
	y = 0;
	while (y < 480)
	{
		x = 0;
		if (y > 240)
			color = this->gameinfo->color_f;
		while (x < 640)
		{
			my_mlx_pixel_put(this->img_clear, x, y, color);
			x++;
		}
		y++;
	}
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
