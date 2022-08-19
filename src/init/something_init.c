//
// Created by Tile Tyuuki on 20.06.2022.
//

#include "../../includes/cub3d.h"

void	write_map(t_cub3d *this, char *line, int fd)
{
	char	*s_join;
	char	*for_free;

	s_join = line;
	for_free = s_join;
	while(1)
	{
		line = get_next_line(fd);
		if(!line)
			break ;
		s_join = ft_strjoin(s_join, line);
		free(line);
		free(for_free);
		for_free = s_join;
	}
	this->gameinfo->map = ft_split(s_join, '\n');
	free(s_join);
}

void	check_conditions(char *line, t_cub3d *this, int *i)
{
	int	j;

	j = 0;
	if (*i == 7)
	{
		ft_putstr_fd("Error:\n", 2);
		ft_putstr_fd(E_VP, 2);
		ft_putchar_fd('\n', 2);
		exit(1);
	}
	if (!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2) \
	|| !ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2) \
	|| !ft_strncmp(line, "F", 1) || !ft_strncmp(line, "C", 1))
	{
		this->gameinfo->game_settings[*i] = ft_strdup(line);
		(*i)++;
	}
	else
	{
		while (line[j] && ft_isspace(line[j]))
			j++;
		if (line[j] != '\n' && line[j] != '1')
			ft_error(this, E_VP);
	}
}

void	game_init_flag_one(t_cub3d *this, char *line, int fd)
{
	int	i;
	i = 0;
	this->gameinfo->game_settings = (char **)malloc(sizeof (char *) * 7);

	while(1)
	{
		line = get_next_line(fd);
		if(!line)
			break ;
		check_conditions(line, this, &i);
		free(line);
	}
	if (i != 6)
		ft_error(NULL, E_VP);
	this->gameinfo->game_settings[i] = NULL;
}

void	game_init_flag_two(t_cub3d *this, char *line, int fd)
{
	int	i;

	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		while (line[i] && ft_isspace(line[i]))
			i++;
		if (line[i] && line[i] == '1')
			break ;
		free(line);
	}
	if (!line)
		ft_error(this, E_VE);
	write_map(this, line, fd);
}

int game_init(t_cub3d *this, char *file, int flag)
{
	char	*line;
	int 	fd;

	fd = open(file, O_RDONLY);
	if(fd == -1)
		ft_error(this, E_OF);
	line = NULL;
	if (flag == 1)
		game_init_flag_one(this, line, fd);
	else
		game_init_flag_two(this, line, fd);
	close(fd);
	return (0);
}