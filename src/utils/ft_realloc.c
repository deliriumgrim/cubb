//
// Created by Tile Tyuuki on 21.06.2022.
//

#include "../../includes/cub3d.h"

void	ft_realloc(char **str, char *new_str)
{
	free(*str);
	*str = ft_strdup(new_str);
}