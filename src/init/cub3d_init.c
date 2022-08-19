//
// Created by Tile Tyuuki on 20.06.2022.
//

#include "../../includes/cub3d.h"

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
	this->mlx_info->path_EA = NULL;
	this->mlx_info->path_WE = NULL;
	this->mlx_info->path_NO = NULL;
	this->mlx_info->path_SO = NULL;
	this->mlx_info->path_F = NULL;
	this->mlx_info->path_C = NULL;
	this->mlx_info->mlx = NULL;
	this->mlx_info->mlx_win = NULL;
	this->mlx_info->EA_texture = NULL;
	this->mlx_info->WE_texture = NULL;
	this->mlx_info->NO_texture = NULL;
	this->mlx_info->SO_texture = NULL;
	int y = 0;
	int x;
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