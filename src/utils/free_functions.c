#include "../../includes/cub3d.h"

void	ft_freex2arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
