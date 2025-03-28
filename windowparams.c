/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windowparams.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luprevos <luprevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:36:04 by luprevos          #+#    #+#             */
/*   Updated: 2025/03/29 00:29:49 by luprevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int new_window_mlx(t_long *data)
{
	// void *mlx;
	// void *mlx_win;
	// void *img;
	// int a = IMAGEWEIGTH;
	// int *i = &a;
	// printf("%d\n" , data->line_len);
	// printf("%d\n", data->line_number);
	
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, (data->line_len) * 64,
	 (data->line_number) *64, "so_long");
	mlx_hook(data->mlx_win, 2, 1L << 0, close_window, data->mlx);
	mlx_hook(data->mlx_win, 17, 0, close_window_for_x, data->mlx);
	// img = mlx_xpm_file_to_image(mlx, "image/grass.xpm", i, i);
	// if (img == NULL)
	// 	printf("IMAGE\n");
	// mlx_put_image_to_window(mlx, mlx_win, img, 0*IMAGEWEIGTH, 0*IMAGEWEIGTH);
	//mlx_loop(data->mlx);
	return(0);
}

void print_map(t_long *data)
{
	char **map;
	
	map = data->map;
	data->x = 0;
	data->y = 0;
	new_window_mlx(data);
	while(map[data->y][data->x])
	{
		if(map[data->y][data->x] == '\n')
		{
			data->y++;
			data->x = 0;
		}
		if(map[data->y][data->x] == WALL)
		 	print_grass(data);
		else if(map[data->y][data->x] == VIDE)
			print_void(data);
		else if(map[data->y][data->x] == ITEM)
			print_item(data);
		else if(map[data->y][data->x] == PLAYER)
			print_player(data);
		print_exit(data, map);
		data->x++;
	}
	mlx_loop(data->mlx);
}
void print_exit(t_long *data, char **map)
{
	if(map[data->y][data->x] == EXIT)
	{
		if (data->item == 0)
			print_exitopen(data);
		else
			print_exitclose(data);
	}
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