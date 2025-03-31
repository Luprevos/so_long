/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luprevos <luprevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 00:08:11 by luprevos          #+#    #+#             */
/*   Updated: 2025/03/31 19:54:19 by luprevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void print_exitopen(t_long *data)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->exitopen_img, data->x*IMAGEWEIGTH, data->y*IMAGEWEIGTH);	
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
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->playeronexit_img, data->playerx*IMAGEWEIGTH, data->playery*IMAGEWEIGTH);	
}

void mlx_destroy_so_long(t_long *data, bool freeMlx)
{
	if (freeMlx)
	{
		mlx_destroy_image(data->mlx, data->exitclose_img);
		mlx_destroy_image(data->mlx, data->exitopen_img);
		mlx_destroy_image(data->mlx, data->vide_img);
		mlx_destroy_image(data->mlx, data->item_img);
		mlx_destroy_image(data->mlx, data->player_img);
		mlx_destroy_image(data->mlx, data->playeronexit_img);
		mlx_destroy_image(data->mlx, data->wall_img);
		mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_display(data->mlx);
	}
	if (data->map)
		free_map(data->map, data);
	if (data)
		free(data);
}
