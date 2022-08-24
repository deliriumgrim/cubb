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

void	ray_init_help(t_cub3d *this)
{
	int	x;
	int	y;

	x = 0;
	while (x < 4)
	{
		this->raycast->texture[x] = (int *)malloc(sizeof(int) * (64 * 64));
		x++;
	}
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 64 * 64)
		{
			this->raycast->texture[y][x] = 0;
			x++;
		}
		y++;
	}
}

void	ray_init(t_cub3d *this)
{
	int	y;
	int	x;

	y = 0;
	while (y < 480)
	{
		x = 0;
		while (x < 640)
		{
			this->raycast->buff[y][x] = 0;
			x++;
		}
		y++;
	}
	this->raycast->texture = (int **)malloc(sizeof(int *) * 4);
	ray_init_help(this);
}

void	cub3d_init(t_cub3d *this)
{
	this->gameinfo = (t_gameinfo *) malloc(sizeof(t_gameinfo));
	this->mlx_info = (t_mlx *) malloc(sizeof(t_mlx));
	this->img = (t_img *) malloc(sizeof(t_img));
	this->img_clear = (t_img *) malloc(sizeof(t_img));
	this->raycast = (t_raycast *) malloc(sizeof(t_raycast));
	this->gameinfo->nb_players = 0;
	this->gameinfo->size_texute = 64;
	this->gameinfo->map = NULL;
	this->gameinfo->game_settings = NULL;
	this->mlx_info->path_ea = NULL;
	this->mlx_info->path_we = NULL;
	this->mlx_info->path_no = NULL;
	this->mlx_info->path_so = NULL;
	this->mlx_info->path_f = NULL;
	this->mlx_info->path_c = NULL;
	this->mlx_info->mlx = NULL;
	this->mlx_info->mlx_win = NULL;
	this->mlx_info->ea_texture = NULL;
	this->mlx_info->we_texture = NULL;
	this->mlx_info->no_texture = NULL;
	this->mlx_info->so_texture = NULL;
	ray_init(this);
}
