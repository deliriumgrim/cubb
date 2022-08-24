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

void	load_image(t_cub3d *this, t_img *img, char *path, int *texture)
{
	int	x;
	int	y;

	y = 0;
	img->img \
		= mlx_xpm_file_to_image(this->mlx_info->mlx, \
	path, &this->mlx_info->size_x, &this->mlx_info->size_x);
	if (img->img == NULL)
		ft_error(this, E_VP);
	img->addr = (int *)mlx_get_data_addr(img->img, \
	&img->bits_per_pixel, \
	&img->line_length, &img->endian);
	while (y < this->gameinfo->size_texute)
	{
		x = 0;
		while (x < this->gameinfo->size_texute)
		{
			texture[this->mlx_info->size_x * y + x] \
				= img->addr[this->mlx_info->size_x * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(this->mlx_info->mlx, img->img);
}

void	get_texture(t_cub3d *this)
{
	t_img	img;

	load_image(this, &img, this->mlx_info->path_so, this->raycast->texture[0]);
	load_image(this, &img, this->mlx_info->path_no, this->raycast->texture[1]);
	load_image(this, &img, this->mlx_info->path_we, this->raycast->texture[2]);
	load_image(this, &img, this->mlx_info->path_ea, this->raycast->texture[3]);
}

void	init_mlx(t_cub3d *this)
{
	this->mlx_info->size_x = 64;
	this->mlx_info->size_y = 64;
	this->mlx_info->mlx = mlx_init();
	this->mlx_info->mlx_win = mlx_new_window(this->mlx_info->mlx, \
	640, 480, "cub3d");
	if (!this->mlx_info->mlx)
		ft_error(this, E_MI);
	get_texture(this);
	this->img->img = mlx_new_image(this->mlx_info->mlx, 640, 480);
	if (!this->img->img)
		ft_error(this, E_MT);
	this->img->addr = (int *)mlx_get_data_addr(this->img->img, \
	&this->img->bits_per_pixel, \
	&this->img->line_length, &this->img->endian);
	this->img_clear->img = mlx_new_image(this->mlx_info->mlx, 640, 480);
	if (!this->img_clear->img)
		ft_error(this, E_MT);
	this->img_clear->addr = (int *)mlx_get_data_addr(this->img_clear->img, \
	&this->img_clear->bits_per_pixel, \
	&this->img_clear->line_length, &this->img_clear->endian);
}
