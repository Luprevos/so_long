/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luprevos <luprevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 00:08:11 by luprevos          #+#    #+#             */
/*   Updated: 2025/03/29 03:34:19 by luprevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void print_exitopen(t_long *data)
{
	void *img;
	int *i;
	int a;

	a = IMAGEWEIGTH;
	i = &a;
	img = mlx_xpm_file_to_image(data->mlx, "image/exitopen.xpm", i, i);
	mlx_put_image_to_window(data->mlx, data->mlx_win, img, data->x*IMAGEWEIGTH, data->y*IMAGEWEIGTH);	
}

void replace_texture(t_long *data)
{
	if(data->map[data->playery][data->playerx] == PLAYER)
		data->map[data->playery][data->playerx] = VIDE;
	else if (data->map[data->playery][data->playerx] == ITEM)
	{
		data->item--;
		data->map[data->playery][data->playerx] = VIDE;
	}
}
void print_playeronexit(t_long *data)
{
	void *img;
	int *i;
	int a;

	a = IMAGEWEIGTH;
	i = &a;
	img = mlx_xpm_file_to_image(data->mlx, "image/playeronexit.xpm", i, i);
	mlx_put_image_to_window(data->mlx, data->mlx_win, img, data->playerx*IMAGEWEIGTH, data->playery*IMAGEWEIGTH);	
}