//
// Created by Tile Tyuuki on 21.06.2022.
//

#include "../../includes/cub3d.h"

size_t search_max_len(char **map)
{
	int 	i;
	size_t	max_len;

	i = 0;
	max_len = 0;
	while(map[i])
	{
		if(max_len < ft_strlen(map[i]))
			max_len = ft_strlen(map[i]);
		i++;
	}
	return (max_len);
}

void	set_newline(char **map, size_t max_len)
{
	char	*f_join;
	char	*f_free;
	size_t 	len;

	len = ft_strlen(*map);
	f_join = ft_strdup(*map);
	f_free = f_join;
	while(len < max_len)
	{
		f_join = ft_strjoin(f_join, " ");
		free(f_free);
		f_free = f_join;
		len++;
	}
	ft_realloc(map, f_join);
	free(f_join);
}

int	set_spaces(char ***map)
{
	size_t	max_len;
	int 	i;

	i = 0;
	max_len = search_max_len(*map);
	while((*map)[i])
	{
		if(ft_strlen((*map)[i]) < max_len)
			set_newline(&(*map)[i], max_len);
		i++;
	}
	return (i);
}

void	check_space(char **str, int i, int j, t_cub3d *this)
{
	if(i == 0 || i == this->gameinfo->y_map - 1 \
		|| j == 0 || j == (int)ft_strlen(str[i]) - 1)
		ft_error(this, E_VE);
	if(str[i + 1][j] == ' ' \
		|| str[i - 1][j] == ' ' \
		|| str[i][j + 1] == ' ' \
		|| str[i][j - 1] == ' ')
	{
		ft_error(this, E_VE);
	}
}

void	write_dir_player(t_cub3d *this, char player) {
	if (player == 'N')
		this->gameinfo->dir_player = 1;
	else if (player == 'E')
		this->gameinfo->dir_player = 2;
	else if (player == 'S')
		this->gameinfo->dir_player = 3;
	else if (player == 'W')
		this->gameinfo->dir_player = 4;
}

void	check_synt(char **str, int j, int i, t_cub3d *this)
{
	if(str[i][j] == 'N' || str[i][j] == 'S' \
		|| str[i][j] == 'E' || str[i][j] == 'W')
	{
		this->gameinfo->x_pos = j;
		this->gameinfo->y_pos = i;
		if(this->gameinfo->nb_players > 0)
			ft_error(this, E_VE);
		write_dir_player(this, str[i][j]);
		check_space(str, i, j, this);
		this->gameinfo->nb_players++;
		return ;
	}
	else if(str[i][j] == '0')
		check_space(str, i, j, this);
	else if(str[i][j] == '1')
		return ;
	else if(str[i][j] != ' ')
		ft_error(this, E_VE);
}

void	map_valid(t_cub3d *this)
{
	int i;
	int j;

	i = 0;
	this->gameinfo->y_map = set_spaces(&this->gameinfo->map);
	while(this->gameinfo->map[i])
	{
		j = 0;
		while(this->gameinfo->map[i][j])
		{
			check_synt(this->gameinfo->map, j, i, this);
			j++;
		}
		i++;
	}
}
