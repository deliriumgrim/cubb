//
// Created by Tile Tyuuki on 21.06.2022.
//

#include "../../includes/cub3d.h"

void	set_flags(t_cub3d *this, int i, int **flag)
{
	if (!ft_strncmp("NO ", this->gameinfo->game_settings[i], 3))
		(*flag)[0] += 1;
	else if (!ft_strncmp("SO ", this->gameinfo->game_settings[i], 3))
		(*flag)[1] += 1;
	else if (!ft_strncmp("EA ", this->gameinfo->game_settings[i], 3))
		(*flag)[2] += 1;
	else if (!ft_strncmp("WE ", this->gameinfo->game_settings[i], 3))
		(*flag)[3] += 1;
	else if (!ft_strncmp("F ", this->gameinfo->game_settings[i], 2))
		(*flag)[4] += 1;
	else if (!ft_strncmp("C ", this->gameinfo->game_settings[i], 2))
		(*flag)[5] += 1;
}

void	params_valid(t_cub3d *this)
{
	int	i;
	int j;
	int	*flag;

	j = 0;
	i = 0;
	flag = (int *) malloc(sizeof (int) * 6);
	while (j < 6)
		flag[j++] = 0;
	while (this->gameinfo->game_settings[i])
		set_flags(this, i++, &flag);
	if (flag[0] != 1 || flag[1] != 1 || flag[2] != 1 \
	|| flag[3] != 1 || flag[4] != 1 || flag[5] != 1)
	{
		free(flag);
		ft_error(this, E_VP);
	}
	free(flag);
}
