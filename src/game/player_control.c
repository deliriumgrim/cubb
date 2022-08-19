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
	printf("planeX - %f planeY - %f \n dirX - %f dirY - %f\n\n", this->raycast->planeX, this->raycast->planeY, this->raycast->dirX, this->raycast->dirY);
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
	printf("planeX - %f planeY - %f \n dirX - %f dirY - %f\n\n", this->raycast->planeX, this->raycast->planeY, this->raycast->dirX, this->raycast->dirY);
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
	if (keycode == 0)
		ft_walk_a(this, keycode);
	if (keycode == 123)
		ft_look_right(this, keycode);
	if (keycode == 124)
		ft_look_left(this, keycode);
	if (keycode == 13)
		ft_walk_w(this, keycode);
	if (keycode == 1)
		ft_walk_s(this, keycode);
	if (keycode == 2)
		ft_walk_d(this, keycode);
	if(keycode == 53)
		exit(0);
	return (0);
}