/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luprevos <luprevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:24:26 by luprevos          #+#    #+#             */
/*   Updated: 2025/03/26 11:36:32 by luprevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <stdbool.h>
#include "./minilibx-linux/mlx.h"
#include "get_next_line/get_next_line.h"

#define WALL '1'
#define PLAYER 'P'
#define ITEM 'C'
#define EXIT 'E'
#define VIDE '0'


typedef struct s_long
{
	char	**map;
	int 	line_number;
	int 	line_len;
	int 	x;
	int		y;
	bool	player;
	bool	exit;
	int		item;
	int		C;
	
}		t_long;


//utils
int ft_strcmp(char *s1, char *s2);
int	count_lines(int fd, t_long *data);
int	ft_strlenn(char *str);
char *ft_strdupmap(char *s2, t_long *data);
void ft_mapcopy(t_long *data, char **argv, int fd);


//parsing
int check_ber(char *filename);
void check_first_last_characters(t_long *data);
void check_first_last_line(t_long *data);
void check_map_format(t_long *data);

//parsingmap
void get_player(t_long *data);
void check_exit(t_long *data);
void check_item(t_long *data);
void check_over(t_long *data);
void map_is_map(t_long *data);

//flood_fill
void flood_fill(t_long *data, int i, int j);
int perfect_parsing(t_long *data);


#endif