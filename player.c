/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luprevos <luprevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 00:33:53 by luprevos          #+#    #+#             */
/*   Updated: 2025/03/29 03:36:43 by luprevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int player_key(int keycode, t_long *data)
{
	if (keycode == 97 && data->map[data->playery][data->playerx - 1] != WALL)
    { 
		data->playerx -= 1;
		data->move++;
	}
    else if (keycode == 100 && data->map[data->playery][data->playerx + 1] != WALL)
    {
		    data->playerx += 1;
			data->move++;
	}
    else if (keycode == 119 && data->map[data->playery - 1][data->playerx] != WALL)
    {
		    data->playery -= 1;
			data->move++;
	}
	else if (keycode == 115 && data->map[data->playery + 1][data->playerx] != WALL)
    {
		data->playery += 1;
		data->move++;
	}
	printf("TOTAL MOVEMENT COUNT: %d\n", data->move);
	if (finish(data) == 1)
		return (0);
	print_map(data);
	return (0);
}

int finish(t_long *data)
{
	if (data->map[data->playery][data->playerx] == EXIT && data->item == 0)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		printf("THANK U FOR PLAYING\n");
		mlx_loop_end(data->mlx);
		return (1);
	}
	return (0);
}
