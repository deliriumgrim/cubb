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
#include "../../includes/cub3d.h"

void	fourth_cond_raycast(t_cub3d *this)
{
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
}

void	fifth_cond_raycast(t_cub3d *this)
{
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
}

void	sixth_cond_raycast(t_cub3d *this, int *y)
{
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
	*y = this->raycast->draw_start;
}

void	seventh_cond_raycast(t_cub3d *this, int *y, int *x)
{
	while (*y < this->raycast->draw_end)
	{
		this->raycast->tex_y = (int)this->raycast->tex_pos & (64 - 1);
		this->raycast->tex_pos += this->raycast->step;
		if (this->raycast->tex_num == 49)
			this->raycast->tex_num = 3;
		this->raycast->color \
			= this->raycast->texture[this->raycast->tex_num] \
			[this->raycast->tex_y * 64 + this->raycast->tex_x];
		this->raycast->buff[*y][*x] = this->raycast->color;
		(*y)++;
	}
}
