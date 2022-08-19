#ifndef STRUCTS_H
#  define STRUCTS_H

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} 			t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	void	*NO_texture;
	void	*SO_texture;
	void	*WE_texture;
	void	*EA_texture;
	char	*path_NO;
	char	*path_SO;
	char	*path_EA;
	char	*path_WE;
	char	*path_F;
	char	*path_C;
	int		sizeX;
	int		sizeY;
}				t_mlx;

typedef struct s_gameinfo
{
	char 	**game_settings;
	char	**map;
	int		nb_players;
	int		y_map;
	int		x_pos;
	int		y_pos;
	int		dir_player;
	int		color_c;
	int		color_f;
	int 	size_texute;
}			t_gameinfo;

typedef struct s_raycast
{
	double posX;
	double posY;
	double dirX;//вектор направления
	double dirY;
	int width;
	double height;
	double planeX;//вектор камеры
	double planeY;
	double moveSpeed;
	double rotSpeed;
	double cameraX; // -1 0 1 по ширине экрана
	double rayDirX;
	double rayDirY;
	int mapY;
	int mapX;
	double sideDistY;//длина луча от 1 позиции у до след позиции
	double sideDistX;
	double deltaDistY;//длина луча от 1 позиции у до след позиции
	double deltaDistX;
	double perpWallDist;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		color;
	int		buff[480][640];
	int		**texture;
	int		texNum;
	double	wallX;
	int		texX;
	int		texY;
	double 	step;
	double 	texPos;
}				t_raycast;

typedef struct s_cub3d
{
	t_gameinfo	*gameinfo;
	t_mlx		*mlx_info;
	t_raycast	*raycast;
	t_img 		*img;
	t_img		*img_clear;
}			t_cub3d;

#endif