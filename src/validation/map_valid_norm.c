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

size_t	search_max_len(char **map)
{
	int		i;
	size_t	max_len;

	i = 0;
	max_len = 0;
	while (map[i])
	{
		if (max_len < ft_strlen(map[i]))
			max_len = ft_strlen(map[i]);
		i++;
	}
	return (max_len);
}

void	set_newline(char **map, size_t max_len)
{
	char	*f_join;
	char	*f_free;
	size_t	len;

	len = ft_strlen(*map);
	f_join = ft_strdup(*map);
	f_free = f_join;
	while (len < max_len)
	{
		f_join = ft_strjoin(f_join, " ");
		free(f_free);
		f_free = f_join;
		len++;
	}
	ft_realloc(map, f_join);
	free(f_join);
}
