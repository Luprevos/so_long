/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windowparams.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luprevos <luprevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:36:04 by luprevos          #+#    #+#             */
/*   Updated: 2025/03/27 15:53:19 by luprevos         ###   ########.fr       */
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
	
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, (data->line_len - 1) * 64,
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
void print_grass(t_long *data)
{
	void *img;
	int *i;
	int a;

	a = IMAGEWEIGTH;
	i = &a;
	//new_window_mlx(data);
	img = mlx_xpm_file_to_image(data->mlx, "image/grass.xpm", i, i);
	mlx_put_image_to_window(data->mlx, data->mlx_win, img, data->x*IMAGEWEIGTH, data->y*IMAGEWEIGTH);
}
void print_map(t_long *data)
{
	char **map;
	
	//printf("prout\n");
	data->x = 0;
	data->y = 0;
	map = data->map;
	new_window_mlx(data);
	while(map[data->y][data->x] != '\0')
	{
		if(map[data->y][data->x] == '\n')
		{
			printf("%s", map[data->y]);
			data->y++;
		}
		else if(map[data->y][data->x] == WALL)
		{
			//printf("prout\n");
			print_grass(data);
			data->x++;
		}
		data->x++;
	}
	mlx_loop(data->mlx);
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