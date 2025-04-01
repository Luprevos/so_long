/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luprevos <luprevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 23:28:14 by luprevos          #+#    #+#             */
/*   Updated: 2025/04/01 17:49:16 by luprevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_wall(t_long *data)
{
	mlx_put_image_to_window (data->mlx, data->mlx_win,
		data->wall_img, data->x * IMAGEWEIGTH, data->y * IMAGEWEIGTH);
}

void	print_void(t_long *data)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->vide_img, data->x * IMAGEWEIGTH, data->y * IMAGEWEIGTH);
}

void	print_item(t_long *data)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->item_img, data->x * IMAGEWEIGTH, data->y * IMAGEWEIGTH);
}

void	print_player(t_long *data)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->player_img, data->playerx * IMAGEWEIGTH,
		data->playery * IMAGEWEIGTH);
}

void	print_exitclose(t_long *data)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->exitclose_img, data->x * IMAGEWEIGTH, data->y * IMAGEWEIGTH);
}
