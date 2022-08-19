/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karimvaliev <karimvaliev@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:31:37 by tyuuki            #+#    #+#             */
/*   Updated: 2021/10/20 15:05:39 by karimvaliev      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	arr_len(const char *str, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != sep)
		{
			if (str[i + 1] == sep || str[i + 1] == '\0')
				count++;
		}
		i++;
	}
	return (count);
}

static void	free_mass(char **mass, int i)
{
	int	k;

	k = 0;
	while (k < i)
	{
		free(mass[k]);
		k++;
	}
}

static	int	strlen_split(const char *str, int index, const char sep)
{
	int	i;

	i = 0;
	while (str[index] != sep && str[index] != '\0')
	{
		i++;
		index++;
	}
	return (i);
}

static	char	*malloc_str(const char *str, int *index, char sep)
{
	char	*arr;
	int		i;

	i = 0;
	while (str[*index] == sep)
		(*index)++;
	arr = (char *) malloc(strlen_split(str, *index, sep) + 1);
	if (arr == NULL)
		return (NULL);
	while (str[*index] != sep && str[*index] != '\0')
	{
		arr[i] = str[*index];
		(*index)++;
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**mass;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	mass = (char **) malloc(sizeof(char *) * (arr_len(s, c) + 1));
	if (mass == NULL)
		return (NULL);
	while (k < arr_len(s, c))
	{
		mass[k] = malloc_str(s, &i, c);
		if (!mass[k])
			break ;
		k++;
	}
	if (k < arr_len(s, c))
	{
		free_mass(mass, k);
		return (NULL);
	}
	mass[k] = NULL;
	return (mass);
}
