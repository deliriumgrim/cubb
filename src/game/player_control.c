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

void	ft_look_right(t_cub3d *this, int keycode)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = this->raycast->dir_x;
	old_plane_x = this->raycast->plane_x;
	(void)keycode;
	this->raycast->dir_x = this->raycast->dir_x * cos(this->raycast->rot_speed) \
	- this->raycast->dir_y * sin(this->raycast->rot_speed);
	this->raycast->dir_y = old_dir_x * sin(this->raycast->rot_speed) \
	+ this->raycast->dir_y * cos(this->raycast->rot_speed);
	this->raycast->plane_x = this->raycast->plane_x \
	* cos(this->raycast->rot_speed) \
	- this->raycast->plane_y * sin(this->raycast->rot_speed);
	this->raycast->plane_y = old_plane_x * sin(this->raycast->rot_speed) \
	+ this->raycast->plane_y * cos(this->raycast->rot_speed);
}

void	ft_look_left(t_cub3d *this, int keycode)
{
	double	old_dir_x;
	double	old_plane_x;

	(void)keycode;
	old_dir_x = this->raycast->dir_x;
	old_plane_x = this->raycast->plane_x;
	this->raycast->dir_x = this->raycast->dir_x \
	* cos(-this->raycast->rot_speed) \
			- this->raycast->dir_y * sin(-this->raycast->rot_speed);
	this->raycast->dir_y = old_dir_x * sin(-this->raycast->rot_speed) \
			+ this->raycast->dir_y \
			* cos(-this->raycast->rot_speed);
	this->raycast->plane_x = this->raycast->plane_x \
	* cos(-this->raycast->rot_speed) \
			- this->raycast->plane_y * sin(-this->raycast->rot_speed);
	this->raycast->plane_y = old_plane_x * sin(-this->raycast->rot_speed) \
			+ this->raycast->plane_y * cos(-this->raycast->rot_speed);
}

int	player_control(int keycode, t_cub3d *this)
{
	if (keycode == 97)
		ft_walk_a(this, keycode);
	if (keycode == 65361)
		ft_look_right(this, keycode);
	if (keycode == 65363)
		ft_look_left(this, keycode);
	if (keycode == 119)
		ft_walk_w(this, keycode);
	if (keycode == 115)
		ft_walk_s(this, keycode);
	if (keycode == 100)
		ft_walk_d(this, keycode);
	if (keycode == 65307)
		ft_exit(this);
	return (0);
}
