/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luprevos <luprevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:00:16 by luprevos          #+#    #+#             */
/*   Updated: 2025/03/24 18:19:19 by luprevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_ber(char *filename)
{
	int len;
	
	len = strlen(filename);
	if (len < 4 || ft_strcmp(filename + len - 4, ".ber") != 0)
	{
		printf("ERROR : Le fichier n'est pas un .ber\n");
		return(0);
	}
	else
		return(1);
}

void check_first_last_characters(t_long *data)
{
	char **map;
	int i;
	int j;
	i = 0;
	j = 0;
	map = data->map;
	while(i != data->line_number)
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			if (map[i][0] != '1' || map[i][ft_strlenn(map[i]) - 1] != '1')
			{
				printf("ERROR : bordure de map mal definit\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void check_first_last_line(t_long *data)
{
	char **map;
	int i;
	int j;

	i = 0;
	j = 0;
	map = data->map;
	if(map[i][j])
	{
		while (map[0][j] == '1')
			j++;
		if(map[0][j] != '\n')
			printf("ERROR : Premiere ligne mal definit\n");
		j = 0;
		i = data->line_number - 1;
		while (map[i][j] == '1')
			j++;
		if (map[i][j] != '\n')
		{
			printf("ERROR : dermiere ligne mal definit\n");
			exit(1);
		}
	}
}

void check_map_format(t_long *data)
{
	char **map;
	int i;
	int j;

	i = 0;
	j = 0;
	map = data->map;
	while(i != data->line_number)
	{
		if ((ft_strlenn(map[i])) == data->line_number)
		{
			printf("ERROR : La map est un carre\n");
			exit(1);
		}
		i++;
	}
	
}
