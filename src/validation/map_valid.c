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

int	set_spaces(char ***map)
{
	size_t	max_len;
	int		i;

	i = 0;
	max_len = search_max_len(*map);
	while ((*map)[i])
	{
		if (ft_strlen((*map)[i]) < max_len)
			set_newline(&(*map)[i], max_len);
		i++;
	}
	return (i);
}

void	check_space(char **str, int i, int j, t_cub3d *this)
{
	if (i == 0 || i == this->gameinfo->y_map - 1 \
		|| j == 0 || j == (int)ft_strlen(str[i]) - 1)
		ft_error(this, E_VE);
	if (str[i + 1][j] == ' ' \
		|| str[i - 1][j] == ' ' \
		|| str[i][j + 1] == ' ' \
		|| str[i][j - 1] == ' ')
	{
		ft_error(this, E_VE);
	}
}

void	write_dir_player(t_cub3d *this, char player)
{
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
	if (str[i][j] == 'N' || str[i][j] == 'S' \
		|| str[i][j] == 'E' || str[i][j] == 'W')
	{
		this->gameinfo->x_pos = j;
		this->gameinfo->y_pos = i;
		if (this->gameinfo->nb_players > 0)
			ft_error(this, E_VE);
		write_dir_player(this, str[i][j]);
		check_space(str, i, j, this);
		this->gameinfo->nb_players++;
		return ;
	}
	else if (str[i][j] == '0')
		check_space(str, i, j, this);
	else if (str[i][j] == '1')
		return ;
	else if (str[i][j] != ' ')
		ft_error(this, E_VE);
}

void	map_valid(t_cub3d *this)
{
	int	i;
	int	j;

	i = 0;
	this->gameinfo->y_map = set_spaces(&this->gameinfo->map);
	while (this->gameinfo->map[i])
	{
		j = 0;
		while (this->gameinfo->map[i][j])
		{
			check_synt(this->gameinfo->map, j, i, this);
			j++;
		}
		i++;
	}
	if (this->gameinfo->nb_players != 1)
		ft_error(this, E_VP);
}
