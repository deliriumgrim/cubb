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

int	check_color_valid(t_cub3d *this, char *path)
{
	int		color;
	int		i;
	char	**tmp;

	color = 0;
	i = 0;
	tmp = ft_split(path, ',');
	while (tmp[i])
		i++;
	if (i != 3)
		ft_error(this, E_VP);
	i = 0;
	while (tmp[i])
	{
		if (ft_atoi(tmp[i]) == -1 || ft_atoi(tmp[i]) > 255)
			ft_error(this, E_VP);
		color = color << 8;
		color += ft_atoi(tmp[i]);
		i++;
	}
	ft_freex2arr(tmp);
	return (color);
}

void	write_params_help(t_cub3d *this, int *i, int *len)
{
	if (!ft_strncmp("SO ", this->gameinfo->game_settings[*i], 3))
		this->mlx_info->path_so \
				= ft_substr(this->gameinfo->game_settings[*i], 3, *len - 4);
	else if (!ft_strncmp("NO ", this->gameinfo->game_settings[*i], 3))
		this->mlx_info->path_no \
				= ft_substr(this->gameinfo->game_settings[*i], 3, *len - 4);
	else if (!ft_strncmp("WE ", this->gameinfo->game_settings[*i], 3))
		this->mlx_info->path_we \
				= ft_substr(this->gameinfo->game_settings[*i], 3, *len - 4);
	else if (!ft_strncmp("EA ", this->gameinfo->game_settings[*i], 3))
		this->mlx_info->path_ea \
				= ft_substr(this->gameinfo->game_settings[*i], 3, *len - 4);
	else if (!ft_strncmp("F ", this->gameinfo->game_settings[*i], 2))
		this->mlx_info->path_f \
				= ft_substr(this->gameinfo->game_settings[*i], 2, *len - 3);
	else if (!ft_strncmp("C ", this->gameinfo->game_settings[*i], 2))
		this->mlx_info->path_c \
				= ft_substr(this->gameinfo->game_settings[*i], 2, *len - 3);
}

void	write_params(t_cub3d *this)
{
	int	i;
	int	len;

	i = 0;
	while (this->gameinfo->game_settings[i])
	{
		len = ft_strlen(this->gameinfo->game_settings[i]);
		write_params_help(this, &i, &len);
		i++;
	}
	this->gameinfo->color_f = check_color_valid(this, this->mlx_info->path_f);
	this->gameinfo->color_c = check_color_valid(this, this->mlx_info->path_c);
}
