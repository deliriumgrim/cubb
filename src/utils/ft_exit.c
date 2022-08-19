#include "../../includes/cub3d.h"

void ft_exit_utils2(t_cub3d *this)
{
	if (this->mlx_info->mlx_win)
		mlx_destroy_window(this->mlx_info->mlx, this->mlx_info->mlx_win);
	if(this->mlx_info->EA_texture)
		mlx_destroy_image(this->mlx_info->mlx, this->mlx_info->EA_texture);
	if(this->mlx_info->SO_texture)
		mlx_destroy_image(this->mlx_info->mlx, this->mlx_info->SO_texture);
	if(this->mlx_info->WE_texture)
		mlx_destroy_image(this->mlx_info->mlx, this->mlx_info->WE_texture);
	if(this->mlx_info->NO_texture)
		mlx_destroy_image(this->mlx_info->mlx, this->mlx_info->NO_texture);
}

void ft_exit_utils(t_cub3d *this)
{
	ft_exit_utils2(this);
	if (this->mlx_info->path_NO)
		free(this->mlx_info->path_NO);
	if (this->mlx_info->path_SO)
		free(this->mlx_info->path_SO);
	if (this->mlx_info->path_WE)
		free(this->mlx_info->path_WE);
	if (this->mlx_info->path_EA)
		free(this->mlx_info->path_EA);
	if (this->mlx_info->path_F)
		free(this->mlx_info->path_F);
	if (this->mlx_info->path_C)
		free(this->mlx_info->path_C);
	if (this->mlx_info->mlx)
		free(this->mlx_info->mlx);
	free(this->mlx_info);
}

void	ft_exit(t_cub3d *this)
{
	if (this)
	{
		if (this->gameinfo->game_settings)
			ft_freex2arr(this->gameinfo->game_settings);
		if (this->gameinfo->map)
			ft_freex2arr(this->gameinfo->map);
		ft_exit_utils(this);
	}
	exit(0);
}