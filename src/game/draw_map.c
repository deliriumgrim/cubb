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

void	draw_clear(t_cub3d *this)
{
	int	x;
	int	y;

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
	draw_clear(this);
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
