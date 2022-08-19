#ifndef CUB3D_H
# define CUB3D_H

/*includes*/
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <limits.h>
# include "defines.h"
# include "structs.h"
# include "../libs/mlx/mlx.h"
# include "../libs/libft/libft.h"
# include "../libs/get_next_line/get_next_line.h"

/*init*/
void	cub3d_init(t_cub3d *this);
int 	game_init(t_cub3d *this, char *file, int flag);
void	write_params(t_cub3d *this);
void	init_mlx(t_cub3d *this);

/*game*/
void	clear_map(t_cub3d *this);
void	ft_walk_a(t_cub3d *this, int keycode);
void	ft_walk_w(t_cub3d *this, int keycode);
void	ft_walk_s(t_cub3d *this, int keycode);
void	ft_walk_d(t_cub3d *this, int keycode);
int		player_control(int keycode, t_cub3d *this);

/*validation*/
void	map_valid(t_cub3d *this);
void	params_valid(t_cub3d *this);

/*utils*/
void 	ft_error(t_cub3d *this, char *message);
void	check_filename(char *filename);
void	ft_realloc(char **str, char *new_str);
int		ft_isspace(char c);
void	ft_freex2arr(char **arr);
int		ft_exit(t_cub3d *this);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
#endif
