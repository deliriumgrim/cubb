//
// Created by Tile Tyuuki on 24.06.2022.
//

#include "../../includes/cub3d.h"
void	ft_look_right(t_cub3d *this, int keycode)
{
	(void)keycode;
	double oldDirX = this->raycast->dirX;
	this->raycast->dirX = this->raycast->dirX * cos(this->raycast->rotSpeed)
						  - this->raycast->dirY * sin(this->raycast->rotSpeed);
	this->raycast->dirY = oldDirX * sin(this->raycast->rotSpeed)
						  + this->raycast->dirY * cos(this->raycast->rotSpeed);
	double oldPlaneX = this->raycast->planeX;
	this->raycast->planeX = this->raycast->planeX * cos(this->raycast->rotSpeed)
							- this->raycast->planeY * sin(this->raycast->rotSpeed);
	this->raycast->planeY = oldPlaneX * sin(this->raycast->rotSpeed)
							+ this->raycast->planeY * cos(this->raycast->rotSpeed);
}

void	ft_walk_w(t_cub3d *this, int keycode)
{
	(void)keycode;
	if (this->gameinfo->map[(int)this->raycast->posY][(int)(this->raycast->posX + this->raycast->dirX * this->raycast->moveSpeed)] != '1')
		this->raycast->posX += this->raycast->dirX * this->raycast->moveSpeed;
	if (this->gameinfo->map[(int)(this->raycast->posY + this->raycast->dirY * this->raycast->moveSpeed)][(int)this->raycast->posX] != '1')
		this->raycast->posY += this->raycast->dirY * this->raycast->moveSpeed;
}

void	ft_walk_s(t_cub3d *this, int keycode)
{
	(void)keycode;
	if (this->gameinfo->map[(int)this->raycast->posY][(int)(this->raycast->posX - this->raycast->dirX * this->raycast->moveSpeed)] != '1')
		this->raycast->posX -= this->raycast->dirX * this->raycast->moveSpeed;
	if (this->gameinfo->map[(int)(this->raycast->posY - this->raycast->dirY * this->raycast->moveSpeed)][(int)this->raycast->posX] != '1')
		this->raycast->posY -= this->raycast->dirY * this->raycast->moveSpeed;
}

void	ft_look_left(t_cub3d *this, int keycode)
{
	(void)keycode;
	double oldDirX = this->raycast->dirX;
	this->raycast->dirX = this->raycast->dirX * cos(-this->raycast->rotSpeed)
			- this->raycast->dirY * sin(-this->raycast->rotSpeed);
	this->raycast->dirY = oldDirX * sin(-this->raycast->rotSpeed)
			+ this->raycast->dirY * cos(-this->raycast->rotSpeed);
	double oldPlaneX = this->raycast->planeX;
	this->raycast->planeX = this->raycast->planeX * cos(-this->raycast->rotSpeed)
			- this->raycast->planeY * sin(-this->raycast->rotSpeed);
	this->raycast->planeY = oldPlaneX * sin(-this->raycast->rotSpeed)
			+ this->raycast->planeY * cos(-this->raycast->rotSpeed);
}

void ft_walk_a(t_cub3d *this, int keycode)
{
	(void)keycode;
	if (this->gameinfo->map[(int)(this->raycast->posY + this->raycast->dirX * this->raycast->moveSpeed)][(int)(this->raycast->posX)] != '1')
		this->raycast->posY += this->raycast->dirX * this->raycast->moveSpeed;
	if (this->gameinfo->map[(int)(this->raycast->posY)][(int)(this->raycast->posX - this->raycast->dirY * this->raycast->moveSpeed)] != '1')
		this->raycast->posX -= this->raycast->dirY * this->raycast->moveSpeed;
}

void ft_walk_d(t_cub3d *this, int keycode)
{
	(void)keycode;
	if (this->gameinfo->map[(int)(this->raycast->posY - this->raycast->dirX * this->raycast->moveSpeed)][(int)(this->raycast->posX)] != '1')
		this->raycast->posY -= this->raycast->dirX * this->raycast->moveSpeed;
	if (this->gameinfo->map[(int)(this->raycast->posY)][(int)(this->raycast->posX + this->raycast->dirY * this->raycast->moveSpeed)] != '1')
		this->raycast->posX += this->raycast->dirY * this->raycast->moveSpeed;
}

int	player_control(int keycode, t_cub3d *this)
{
//	printf("1 posX %f posxY %f\n", this->raycast->posX, this->raycast->posY);
	if (keycode == 97)
		ft_walk_a(this, keycode);
	if (keycode == 65361)
		ft_look_right(this, keycode);
	if (keycode == 65363)
		ft_look_left(this, keycode);
	if (keycode == 119)
		ft_walk_w(this, keycode);
	if (keycode == 115)
		ft_walk_s(this, keycode);
	if (keycode == 100)
		ft_walk_d(this, keycode);
//	printf("plane X %f dirX %f plane Y %f dirY %f\n", this->raycast->planeX, this->raycast->dirX, this->raycast->planeX, this->raycast->dirX);
//	printf("2 posX %f posxY %f\n", this->raycast->posX, this->raycast->posY);
//	printf("\n");
	return (0);
}