/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luprevos <luprevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 00:33:53 by luprevos          #+#    #+#             */
/*   Updated: 2025/04/01 17:33:04 by luprevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	player_key(int keycode, t_long *data)
{
	if (keycode == 97 && data->map[data->playery][data->playerx - 1] != WALL)
	{
		data->playerx -= 1;
		data->move++;
	}
	else if (keycode == 100
		&& data->map[data->playery][data->playerx + 1] != WALL)
	{
		data->playerx += 1;
		data->move++;
	}
	else if (keycode == 119
		&& data->map[data->playery - 1][data->playerx] != WALL)
	{
		data->playery -= 1;
		data->move++;
	}
	else if (keycode == 115
		&& data->map[data->playery + 1][data->playerx] != WALL)
	{
		data->playery += 1;
		data->move++;
	}
	finish(data);
	return (0);
}

int	finish(t_long *data)
{
	printf("TOTAL MOVEMENT COUNT: %d\n", data->move);
	if (data->map[data->playery][data->playerx] == EXIT && data->item == 0)
	{
		mlx_loop_end(data->mlx);
		printf("THANK U FOR PLAYING\n");
		return (1);
	}
	return (0);
}

void	free_and_exit(char *s, t_long *data, bool freemlx)
{
	printf("%s", s);
	mlx_destroy_so_long(data, freemlx);
	exit(1);
}
