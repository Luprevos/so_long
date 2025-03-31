/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luprevos <luprevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:17:34 by luprevos          #+#    #+#             */
/*   Updated: 2025/03/31 16:58:18 by luprevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_player(t_long *data)
{
	int		i;
	char	**map;

	data->j = 0;
	i = 0;
	map = data->map;
	while (map[i][data->j] != 'P' && i < data->line_number - 1)
	{
		if (map[i][data->j] == '\n')
		{
			i++;
			data->j = 0;
		}
		data->j++;
	}
	if (i == data->line_number - 1 && data->j == 1)
		printf("ERROR : pas de player sur la map\n");
	else
	{
		data->x = data->j;
		data->y = i;
		data->playerx = data->j;
		data->playery = i;
		data->player = true;
	}
}

void	check_exit(t_long *data)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	j = 0;
	map = data->map;
	while (map[i][j] != 'E' && i < data->line_number - 1)
	{
		if (map[i][j] == '\n')
		{
			i++;
			j = 0;
		}	
		j++;
	}
	if (i == data->line_number - 1 && j == 1)
		printf("ERROR : pas de sortie sur la map\n");
	else
		data->exit = true;
}

void	check_item(t_long *data)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	j = 0;
	map = data->map;
	while (i < data->line_number - 1)
	{
		while (map[i][j] != '\n')
		{
			if (map[i][j] == 'C')
			{
				data->item++;
				j++;
			}
			else
				j++;
		}
		i++;
		j = 0;
	}
	if (data->item < 1)
		printf("ERROR : Nombre d'item insufisant\n");
}
void	check_over(t_long *data)
{
	int	i;
	int	j;
	int	item;

	item = 0;
	i = 0;
	j = 0;
	while (i < data->line_number - 1)
	{
		while (data->map[i][j] != '\n')
		{
			if (data->map[i][j] == 'E' || data->map[i][j] == 'P')
			{
				item++;
				j++;
			}
			else
				j++;
		}
		i++;
		j = 0;
	}
	if (item > 2)
		printf("ERROR : Nombre de sortie | entrer > 1\n");
}

void map_is_map(t_long *data)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while(i < data->line_number - 1)
	{
		if(data->map[i][j] == WALL \
			|| data->map[i][j] == VIDE \
			||data->map[i][j] == PLAYER \
			|| data->map[i][j] == ITEM \
			|| data->map[i][j] == EXIT)
			j++;
		else if(data->map[i][j] == '\n')
		{
			i++;
			j = 0;
		}
		else
		{
			printf("ERROR: map invalide from map_is_map\n");
			break;
		}	
	}
}


