//
// Created by Tile Tyuuki on 21.06.2022.
//

#include "../../includes/cub3d.h"

int	ft_isspace(char c)
{
	if (c == ' ' \
		|| c == '\t' \
		|| c == '\f'
		|| c == '\v'
		|| c == '\r')
		return (1);
	return (0);
}