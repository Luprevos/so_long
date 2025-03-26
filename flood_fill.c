/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luprevos <luprevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:34:41 by luprevos          #+#    #+#             */
/*   Updated: 2025/03/26 11:45:57 by luprevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void flood_fill(t_long *data, int i, int j)
{
	
	if (data->map[i][j] == WALL)
		return ;
	else if (data->map[i][j] == VIDE)
		data->map[i][j] = WALL;
	else if (data->map[i][j] == ITEM)
	{
		data->C++;
		data->map[i][j] = WALL;
	}
	else if (data->map[i][j] == EXIT)
	{
		data->exit = true;
		data->map[i][j] = WALL;
	}
	//printf("%s", data->map[i]);
	flood_fill(data, i - 1, j);
	flood_fill(data, i, j + 1);
	flood_fill(data, i, j - 1);
	flood_fill(data, i + 1, j);
}
int perfect_parsing(t_long *data)
{
	check_first_last_characters(data);
	check_first_last_line(data);
	check_map_format(data);
	check_exit(data);
	check_item(data);
	check_over(data);
	map_is_map(data);
	get_player(data);
	int i;
	i = data->y;
	int j;
	j = data->x;
	data->exit = false;
	flood_fill(data, i, j);
	if(data->item != data->C)
	{
		printf("ERROR : Item bloquer\n");
		return(0);
	}
	if (data->exit == false)
	{
		printf("ERROR : Sortie bloquer\n");
		return(0);
	}
	return(1);
}
