//
// Created by Tile Tyuuki on 21.06.2022.
//

#include "../../includes/cub3d.h"

void	ft_error(t_cub3d *this, char *message)
{
	ft_putstr_fd("Error:\n", 2);
	ft_putstr_fd(message, 2);
	ft_putchar_fd('\n', 2);
	ft_exit(this);
}