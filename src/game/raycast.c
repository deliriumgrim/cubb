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

void	first_cond_raycast(t_cub3d *this, int *x)
{
	this->raycast->camera_x = 2 * (*x) \
		/ (double)this->raycast->width - 1;
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
}

void	second_cond_raycast(t_cub3d *this)
{
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
}

void	third_cond_raycast_help(t_cub3d *this)
{
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

void	third_cond_raycast(t_cub3d *this)
{
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
		third_cond_raycast_help(this);
	}
}

int	raycast(t_cub3d *this)
{
	int	x;
	int	y;

	x = 0;
	while (x < this->raycast->width)
	{
		first_cond_raycast(this, &x);
		second_cond_raycast(this);
		third_cond_raycast(this);
		fourth_cond_raycast(this);
		fifth_cond_raycast(this);
		sixth_cond_raycast(this, &y);
		seventh_cond_raycast(this, &y, &x);
		x++;
	}
	return (0);
}
