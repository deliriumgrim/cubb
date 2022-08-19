#include "../../includes/cub3d.h"

int	check_color_valid(t_cub3d *this, char *path)
{
	int color;
	int i;
	char **tmp;

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
		color+= ft_atoi(tmp[i]);
		i++;
	}
	ft_freex2arr(tmp);
	return color;
}

void	write_params(t_cub3d *this)
{
	int i;
	int len;

	i = 0;
	while (this->gameinfo->game_settings[i])
	{
		len = ft_strlen(this->gameinfo->game_settings[i]);
		if (!ft_strncmp("SO ", this->gameinfo->game_settings[i], 3))
			this->mlx_info->path_SO = ft_substr(this->gameinfo->game_settings[i], 3, len - 4);
		else if (!ft_strncmp("NO ", this->gameinfo->game_settings[i], 3))
			this->mlx_info->path_NO = ft_substr(this->gameinfo->game_settings[i], 3, len - 4);
		else if (!ft_strncmp("WE ", this->gameinfo->game_settings[i], 3))
			this->mlx_info->path_WE = ft_substr(this->gameinfo->game_settings[i], 3, len - 4);
		else if (!ft_strncmp("EA ", this->gameinfo->game_settings[i], 3))
			this->mlx_info->path_EA = ft_substr(this->gameinfo->game_settings[i], 3, len - 4);
		else if (!ft_strncmp("F ", this->gameinfo->game_settings[i], 2))
			this->mlx_info->path_F = ft_substr(this->gameinfo->game_settings[i], 2, len - 3);
		else if (!ft_strncmp("C ", this->gameinfo->game_settings[i], 2))
			this->mlx_info->path_C = ft_substr(this->gameinfo->game_settings[i], 2, len - 3);
		i++;
	}
	this->gameinfo->color_f = check_color_valid(this, this->mlx_info->path_F);
	this->gameinfo->color_c = check_color_valid(this, this->mlx_info->path_C);
}