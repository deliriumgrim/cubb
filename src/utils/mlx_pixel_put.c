#include "../../includes/cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	int		*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8)) / 4;
	*(unsigned int*)dst = color;
}
