//
// Created by Tile Tyuuki on 21.06.2022.
//

#include "../../includes/cub3d.h"

void	check_filename(char *filename)
{
	char	*check;

	check = ft_strrchr(filename, '.');
	if(!check)
		ft_error(NULL, E_FN);
	if(ft_strncmp(check, ".cub", 5))
		ft_error(NULL, E_FN);
}