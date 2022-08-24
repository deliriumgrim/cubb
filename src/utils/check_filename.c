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

void	check_filename(char *filename)
{
	char	*check;

	check = ft_strrchr(filename, '.');
	if (!check)
		ft_error(NULL, E_FN);
	if (ft_strncmp(check, ".cub", 5))
		ft_error(NULL, E_FN);
}
