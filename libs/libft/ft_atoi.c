/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:28:38 by tyuuki            #+#    #+#             */
/*   Updated: 2021/10/19 14:15:43 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long int	output;
	int			result;

	result = 1;
	output = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-' || *str == '+')
		return (-1);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (-1);
		if (output * result > 2147483647)
			return (-1);
		if (output * result < -2147483648)
			return (-1);
		output = (output * 10) + (*str - 48);
		++str;
	}
	return (output * result);
}
