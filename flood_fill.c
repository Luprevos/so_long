/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luprevos <luprevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:34:41 by luprevos          #+#    #+#             */
/*   Updated: 2025/03/31 19:56:32 by luprevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_long *data, int i, int j, char **temp)
{
	if (temp[i][j] == WALL)
		return ;
	else if (temp[i][j] == VIDE)
		temp[i][j] = WALL;
	else if (temp[i][j] == ITEM)
	{
		data->C++;
		temp[i][j] = WALL;
	}
	else if (temp[i][j] == EXIT)
	{
		data->exit = true;
		temp[i][j] = WALL;
	}
	flood_fill(data, i - 1, j, temp);
	flood_fill(data, i, j + 1, temp);
	flood_fill(data, i, j - 1, temp);
	flood_fill(data, i + 1, j, temp);
}

int	perfect_parsing(t_long *data)
{
	char	**temp;
	int		i;
	int		j;

	check_first_last_characters(data);
	check_first_last_line(data);
	check_map_format(data);
	check_exit(data);
	check_item(data);
	check_over(data);
	map_is_map(data);
	get_player(data);
	temp = ft_mapdup(data);
	i = data->y;
	j = data->x;
	data->exit = false;
	flood_fill(data, i, j, temp);
	if (data->item != data->C || data->exit == false)
	{
		printf("ERROR : Item bloquer || Sortie bloquer\n");
		free_map(temp, data);
		return (0);
	}
	free_map(temp, data);
	return (1);
}

void	free_map(char **map, t_long *data)
{
	(void)data;
	int	i;

	i = 0;
	while (map && map[i])
	{
		free(map[i]);
		i++;
	}
	if (map)
		free(map);
}
