/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luprevos <luprevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 23:28:14 by luprevos          #+#    #+#             */
/*   Updated: 2025/03/29 03:22:38 by luprevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void print_wall(t_long *data)
{
	void *img;
	int *i;
	int a;

	a = IMAGEWEIGTH;
	i = &a;
	//new_window_mlx(data);
	img = mlx_xpm_file_to_image(data->mlx, "image/wall.xpm", i, i);
	mlx_put_image_to_window(data->mlx, data->mlx_win, img, data->x*IMAGEWEIGTH, data->y*IMAGEWEIGTH);
}
void print_void(t_long *data)
{
	void *img;
	int *i;
	int a;

	a = IMAGEWEIGTH;
	i = &a;
	img = mlx_xpm_file_to_image(data->mlx, "image/vide.xpm", i, i);
	mlx_put_image_to_window(data->mlx, data->mlx_win, img, data->x*IMAGEWEIGTH, data->y*IMAGEWEIGTH);	
}

void print_item(t_long *data)
{
	void *img;
	int *i;
	int a;

	a = IMAGEWEIGTH;
	i = &a;
	img = mlx_xpm_file_to_image(data->mlx, "image/item.xpm", i, i);
	mlx_put_image_to_window(data->mlx, data->mlx_win, img, data->x*IMAGEWEIGTH, data->y*IMAGEWEIGTH);	
}

void print_player(t_long *data)
{
	void *img;
	int *i;
	int a;

	a = IMAGEWEIGTH;
	i = &a;
	img = mlx_xpm_file_to_image(data->mlx, "image/player.xpm", i, i);
	mlx_put_image_to_window(data->mlx, data->mlx_win, img, data->playerx*IMAGEWEIGTH, data->playery*IMAGEWEIGTH);	
}

void print_exitclose(t_long *data)
{
	void *img;
	int *i;
	int a;

	a = IMAGEWEIGTH;
	i = &a;
	img = mlx_xpm_file_to_image(data->mlx, "image/exitclose.xpm", i, i);
	mlx_put_image_to_window(data->mlx, data->mlx_win, img, data->x*IMAGEWEIGTH, data->y*IMAGEWEIGTH);	
}