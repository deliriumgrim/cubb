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

void	ft_exit_utils2(t_cub3d *this)
{
	if (this->mlx_info->mlx_win)
		mlx_destroy_window(this->mlx_info->mlx, this->mlx_info->mlx_win);
	if (this->mlx_info->ea_texture)
		mlx_destroy_image(this->mlx_info->mlx, this->mlx_info->ea_texture);
	if (this->mlx_info->so_texture)
		mlx_destroy_image(this->mlx_info->mlx, this->mlx_info->so_texture);
	if (this->mlx_info->we_texture)
		mlx_destroy_image(this->mlx_info->mlx, this->mlx_info->we_texture);
	if (this->mlx_info->no_texture)
		mlx_destroy_image(this->mlx_info->mlx, this->mlx_info->no_texture);
}

void	ft_exit_utils(t_cub3d *this)
{
	ft_exit_utils2(this);
	if (this->mlx_info->path_no)
		free(this->mlx_info->path_no);
	if (this->mlx_info->path_so)
		free(this->mlx_info->path_so);
	if (this->mlx_info->path_we)
		free(this->mlx_info->path_we);
	if (this->mlx_info->path_ea)
		free(this->mlx_info->path_ea);
	if (this->mlx_info->path_f)
		free(this->mlx_info->path_f);
	if (this->mlx_info->path_c)
		free(this->mlx_info->path_c);
	if (this->mlx_info->mlx)
		free(this->mlx_info->mlx);
	free(this->mlx_info);
}

int	ft_exit(t_cub3d *this)
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
	return (0);
}
