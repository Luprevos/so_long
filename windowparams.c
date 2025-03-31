/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windowparams.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luprevos <luprevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:36:04 by luprevos          #+#    #+#             */
/*   Updated: 2025/03/31 19:17:38 by luprevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int new_window_mlx(t_long *data)
{
	int trash;
	
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, (data->line_len) * 64,
	 (data->line_number) *64, "so_long");
	data->wall_img = mlx_xpm_file_to_image(data->mlx, "image/wall.xpm", &trash, &trash);
	data->vide_img = mlx_xpm_file_to_image(data->mlx, "image/vide.xpm", &trash, &trash);
	data->item_img = mlx_xpm_file_to_image(data->mlx, "image/item.xpm", &trash, &trash);
	data->player_img = mlx_xpm_file_to_image(data->mlx, "image/player.xpm",&trash, &trash);
	data->exitclose_img = mlx_xpm_file_to_image(data->mlx, "image/exitclose.xpm",&trash, &trash);
	data->exitopen_img = mlx_xpm_file_to_image(data->mlx, "image/exitopen.xpm",&trash, &trash);
	data->playeronexit_img = mlx_xpm_file_to_image(data->mlx, "image/playeronexit.xpm",&trash, &trash);
	mlx_hook(data->mlx_win, 2, 1L << 0, close_window, data->mlx);
	mlx_hook(data->mlx_win, 17, 0, close_window_for_x, data->mlx);
	mlx_key_hook(data->mlx_win, player_key, data);
	mlx_loop_hook(data->mlx, print_map, data);
	return(0);
}

int print_map(t_long *data)
{
	data->x = 0;
	data->y = 0;
	while(data->map[data->y][data->x])
	{
		replace_texture(data);
		if(data->map[data->y][data->x] == '\n')
		{
			data->y++;
			data->x = 0;
		}
		if(data->map[data->y][data->x] == WALL)
		 	print_wall(data);
		if(data->map[data->y][data->x] == data->map[data->playery][data->playerx])
			print_player(data);
		if(data->map[data->y][data->x] == VIDE)
			print_void(data);
		if(data->map[data->y][data->x] == ITEM)
			print_item(data);
		print_exit(data, data->map);
		data->x++;
	}
	return 0;
}
void print_exit(t_long *data, char **map)
{
	data->z = 1;
	if (map[data->y][data->x] == EXIT)
	{
		if (data->item == 0)
			print_exitopen(data);
		else
			print_exitclose(data);
	}
	if (data->map[data->playery][data->playerx] == EXIT && data->item > 0)
		print_playeronexit(data);
		
}

int	close_window(int keycode, void *param)
{
	if (keycode == 65307)
	{
		mlx_loop_end(param);
	}
	return (0);
}
int close_window_for_x(void *param)
{
	mlx_loop_end(param);
	return(0);
}