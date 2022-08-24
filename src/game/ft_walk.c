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

void	ft_walk_w(t_cub3d *this, int keycode)
{
	(void)keycode;
	if (this->gameinfo->map[(int)this->raycast->pos_y] \
	[(int)(this->raycast->pos_x \
	+ this->raycast->dir_x * this->raycast->move_speed)] != '1')
		this->raycast->pos_x \
		+= this->raycast->dir_x * this->raycast->move_speed;
	if (this->gameinfo->map[(int)(this->raycast->pos_y \
	+ this->raycast->dir_y \
	* this->raycast->move_speed)][(int)this->raycast->pos_x] != '1')
		this->raycast->pos_y \
		+= this->raycast->dir_y * this->raycast->move_speed;
}

void	ft_walk_s(t_cub3d *this, int keycode)
{
	(void)keycode;
	if (this->gameinfo->map[(int)this->raycast->pos_y] \
	[(int)(this->raycast->pos_x \
	- this->raycast->dir_x * this->raycast->move_speed)] != '1')
		this->raycast->pos_x \
		-= this->raycast->dir_x * this->raycast->move_speed;
	if (this->gameinfo->map[(int)(this->raycast->pos_y \
	- this->raycast->dir_y * this->raycast->move_speed)] \
	[(int)this->raycast->pos_x] != '1')
		this->raycast->pos_y \
		-= this->raycast->dir_y * this->raycast->move_speed;
}

void	ft_walk_a(t_cub3d *this, int keycode)
{
	(void)keycode;
	if (this->gameinfo->map[(int)(this->raycast->pos_y \
	+ this->raycast->dir_x * this->raycast->move_speed)] \
	[(int)(this->raycast->pos_x)] != '1')
		this->raycast->pos_y += this->raycast->dir_x \
		* this->raycast->move_speed;
	if (this->gameinfo->map[(int)(this->raycast->pos_y)] \
	[(int)(this->raycast->pos_x - this->raycast->dir_y \
	* this->raycast->move_speed)] != '1')
		this->raycast->pos_x \
		-= this->raycast->dir_y * this->raycast->move_speed;
}

void	ft_walk_d(t_cub3d *this, int keycode)
{
	(void)keycode;
	if (this->gameinfo->map[(int)(this->raycast->pos_y \
	- this->raycast->dir_x * this->raycast->move_speed)] \
	[(int)(this->raycast->pos_x)] != '1')
		this->raycast->pos_y \
		-= this->raycast->dir_x * this->raycast->move_speed;
	if (this->gameinfo->map[(int)(this->raycast->pos_y)] \
	[(int)(this->raycast->pos_x + this->raycast->dir_y \
	* this->raycast->move_speed)] != '1')
		this->raycast->pos_x \
		+= this->raycast->dir_y * this->raycast->move_speed;
}
