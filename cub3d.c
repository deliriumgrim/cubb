#include "includes/cub3d.h"

void draw(t_cub3d *this)
{
	int x;
	int y;
	y = 0;
	while (y < 480)
	{
		x = 0;
		while (x < 640)
		{
			this->img->addr[y * 640 + x] = this->raycast->buff[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(this->mlx_info->mlx, this->mlx_info->mlx_win, this->img->img, 0, 0);
	y = 0;
	while(y < 480)
	{
		x = 0;
		while(x < 640)
		{
			this->raycast->buff[y][x] = this->img_clear->addr[y * 640 + x];
			x++;
		}
		y++;
	}
}

int raycast(t_cub3d *this)
{
	int x;

	x = 0;
	while (x < this->raycast->width)
	{
		this->raycast->cameraX = 2 * x
				/ (double)this->raycast->width - 1;
		this->raycast->rayDirX = this->raycast->dirX
				+ this->raycast->planeX * this->raycast->cameraX;
		this->raycast->rayDirY = this->raycast->dirY
				+ this->raycast->planeY * this->raycast->cameraX;
		this->raycast->mapX = (int)this->raycast->posX;
		this->raycast->mapY = (int)this->raycast->posY;
		this->raycast->deltaDistX = fabs(1 / this->raycast->rayDirX);
		this->raycast->deltaDistY = fabs(1 / this->raycast->rayDirY);
		//this
		if (this->raycast->rayDirX < 0)
		{
			this->raycast->stepX = -1;
			this->raycast->sideDistX = (this->raycast->posX - this->raycast->mapX)
					* this->raycast->deltaDistX;
		}
		else
		{
			this->raycast->stepX = 1;
			this->raycast->sideDistX = (this->raycast->mapX + 1.0 - this->raycast->posX)
					* this->raycast->deltaDistX;
		}
		if (this->raycast->rayDirY < 0)
		{
			this->raycast->stepY = -1;
			this->raycast->sideDistY = (this->raycast->posY - this->raycast->mapY)
									   * this->raycast->deltaDistY;
		}
		else
		{
			this->raycast->stepY = 1;
			this->raycast->sideDistY = (this->raycast->mapY + 1.0 - this->raycast->posY)
									   * this->raycast->deltaDistY;
		}
		this->raycast->hit = 0;
		while (this->raycast->hit == 0)
		{
			if (this->raycast->sideDistX < this->raycast->sideDistY)
			{
				this->raycast->sideDistX += this->raycast->deltaDistX;
				this->raycast->mapX += this->raycast->stepX;
				this->raycast->side = 0;
			}
			else
			{
				this->raycast->sideDistY += this->raycast->deltaDistY;
				this->raycast->mapY += this->raycast->stepY;
				this->raycast->side = 1;
			}
			if (this->gameinfo->map[this->raycast->mapY][this->raycast->mapX] != '0'
			&& this->gameinfo->map[this->raycast->mapY][this->raycast->mapX] != 'N'
			&& this->gameinfo->map[this->raycast->mapY][this->raycast->mapX] != 'W'
			&& this->gameinfo->map[this->raycast->mapY][this->raycast->mapX] != 'E'
			&& this->gameinfo->map[this->raycast->mapY][this->raycast->mapX] != 'S')
				this->raycast->hit = 1;
		}
		if (this->raycast->side == 0)
			this->raycast->perpWallDist = (this->raycast->mapX - this->raycast->posX
					+ (1 - this->raycast->stepX)/2)/this->raycast->rayDirX;
		else
			this->raycast->perpWallDist = (this->raycast->mapY - this->raycast->posY
					+ (1 - this->raycast->stepY)/2)/this->raycast->rayDirY;
		this->raycast->lineHeight = (int)(this->raycast->height / this->raycast->perpWallDist);
		this->raycast->drawStart = -this->raycast->lineHeight / 2 + this->raycast->height / 2;
		if (this->raycast->drawStart < 0)
			this->raycast->drawStart = 0;
		this->raycast->drawEnd = this->raycast->lineHeight / 2 + this->raycast->height / 2;
		if (this->raycast->drawEnd >= this->raycast->height)
			this->raycast->drawEnd = this->raycast->height - 1;
		this->raycast->texNum = this->gameinfo->map[this->raycast->mapY][this->raycast->mapX];
		if (this->raycast->side == 0)
			this->raycast->wallX = this->raycast->posY + this->raycast->perpWallDist
					*this->raycast->rayDirY;
		else
			this->raycast->wallX = this->raycast->posX + this->raycast->perpWallDist
					*this->raycast->rayDirX;
		this->raycast->wallX -= floor(this->raycast->wallX);
		this->raycast->texX = (int)(this->raycast->wallX * (double)64);
		if (this->raycast->side == 0 && this->raycast->rayDirX > 0)
			this->raycast->texX = 64 - this->raycast->texX - 1;
		if (this->raycast->side == 1 && this->raycast->rayDirY < 0)
			this->raycast->texX = 64 - this->raycast->texX - 1;
		this->raycast->step = 1.0 * 64 / this->raycast->lineHeight;
		this->raycast->texPos = (this->raycast->drawStart - 480 / 2 + this->raycast->lineHeight / 2)
				* this->raycast->step;
		if ((this->raycast->rayDirX < 0 && this->raycast->rayDirY <0 && this->raycast->side == 1)
			|| (this->raycast->rayDirX > 0 && this->raycast->rayDirY <0 && this->raycast->side == 1))
			this->raycast->texNum = 0;
		if ((this->raycast->rayDirX < 0 && this->raycast->rayDirY >0 && this->raycast->side == 1)
			|| (this->raycast->rayDirX > 0 && this->raycast->rayDirY > 0 && this->raycast->side == 1))
			this->raycast->texNum = 1;
		if ((this->raycast->rayDirX < 0 && this->raycast->rayDirY >0 && this->raycast->side == 0)
			|| (this->raycast->rayDirX < 0 && this->raycast->rayDirY < 0 && this->raycast->side == 0))
			this->raycast->texNum = 2;
		int y;
		y = this->raycast->drawStart;
		while (y < this->raycast->drawEnd)
		{
			this->raycast->texY = (int)this->raycast->texPos & (64 - 1);
			this->raycast->texPos += this->raycast->step;
			if (this->raycast->texNum == 49)
				this->raycast->texNum = 3;
			this->raycast->color = this->raycast->texture[this->raycast->texNum][this->raycast->texY * 64 + this->raycast->texX];
			this->raycast->buff[y][x]=this->raycast->color;
			y++;
		}
		x++;
	}
	return (0);
}

int loop(t_cub3d *this)
{
	raycast(this);
	draw(this);
	return (0);
}

void	write_dir_info(t_cub3d *this)
{
	if (this->gameinfo->dir_player == 1)
	{
		this->raycast->dirX = 0.01;
		this->raycast->dirY = 0.999;
		this->raycast->planeX = 0.659;
		this->raycast->planeY = -0.006;
	}
	else if (this->gameinfo->dir_player == 2)
	{
		this->raycast->dirX = 1;
		this->raycast->dirY = 0;
		this->raycast->planeX = 0;
		this->raycast->planeY = -0.66;
	}
	else if (this->gameinfo->dir_player == 3)
	{
		this->raycast->dirX = -0.01;
		this->raycast->dirY = -0.999;
		this->raycast->planeX = -0.659;
		this->raycast->planeY = 0.006;
	}
	else if (this->gameinfo->dir_player == 4)
	{
		this->raycast->dirX = -0.999;
		this->raycast->dirY = 0.01;
		this->raycast->planeX = 0.006;
		this->raycast->planeY = 0.659;
	}
}

void write_info(t_cub3d *this)
{
	this->raycast->posX = this->gameinfo->x_pos + 0.5;
	this->raycast->posY = this->gameinfo->y_pos + 0.5;
	this->raycast->width = 640;
	this->raycast->height = 480;
	write_dir_info(this);
	this->raycast->moveSpeed = 0.05;
	this->raycast->rotSpeed = 0.05;
}

void	put_floor_celling(t_cub3d *this)
{
	int x;
	int y;
	int color;

	color = this->gameinfo->color_c;
	y = 0;
	while (y < 480)
	{
		x = 0;
		if (y > 240)
			color = this->gameinfo->color_f;
		while (x < 640)
		{
			my_mlx_pixel_put(this->img_clear, x, y, color);
			x++;
		}
		y++;
	}
}

int main(int argc, char **argv)
{
	t_cub3d this;

	if(argc != 2)
		return (1);
	cub3d_init(&this);
	check_filename(argv[1]);
	game_init(&this, argv[1], 1);
	game_init(&this, argv[1], 2);
	params_valid(&this);
	map_valid(&this);
	write_params(&this);
	init_mlx(&this);
	write_info(&this);
	put_floor_celling(&this);
	mlx_hook(this.mlx_info->mlx_win, 2, 1L << 0, &player_control, &this);
	mlx_hook(this.mlx_info->mlx_win, 17, 0, ft_exit, &this);
	mlx_loop_hook(this.mlx_info->mlx, &loop, &this);
	mlx_loop(this.mlx_info->mlx);
	ft_exit(&this);
}