/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luprevos <luprevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:24:26 by luprevos          #+#    #+#             */
/*   Updated: 2025/04/01 17:42:19 by luprevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdbool.h>
# include "./minilibx-linux/mlx.h"
# include "get_next_line/get_next_line.h"

# define WALL '1'
# define PLAYER 'P'
# define ITEM 'C'
# define EXIT 'E'
# define VIDE '0'
# define EXITCLOSE '2'
# define IMAGEWEIGTH 64

typedef struct s_long
{
	char	**map;
	int		line_number;
	int		line_len;
	int		x;
	int		y;
	bool	player;
	bool	exit;
	int		item;
	int		c;
	int		playerx;
	int		playery;
	int		z;
	int		move;
	int		j;

	void	*mlx;
	void	*wall_img;
	void	*exitclose_img;
	void	*exitopen_img;
	void	*item_img;
	void	*player_img;
	void	*vide_img;
	void	*playeronexit_img;
	void	*mlx_win;

}		t_long;

//utils
int		ft_strcmp(char *s1, char *s2);
int		count_lines(int fd, t_long *data);
int		ft_strlenn(char *str);
char	*ft_strdupmap(char *s2, t_long *data);
void	ft_mapcopy(t_long *data, char **argv, int fd);

//parsing
int		check_ber(char *filename);
void	check_first_last_characters(t_long *data);
void	check_first_last_line(t_long *data);
void	check_map_format(t_long *data);
char	**ft_mapdup(t_long *data);

//parsingmap
void	get_player(t_long *data);
void	check_exit(t_long *data);
void	check_item(t_long *data);
void	check_over(t_long *data);
void	map_is_map(t_long *data);

//flood_fill
void	flood_fill(t_long *data, int i, int j, char **temp);
int		perfect_parsing(t_long *data);
void	free_map(char **map);

//mlx
int		new_window_mlx(t_long *data);
int		close_window(int keycode, void *param);
int		close_window_for_x(void *param);
int		print_map(t_long *data);
void	print_exit(t_long *data, char **map);

//texture
void	print_void(t_long *data);
void	print_wall(t_long *data);
void	print_item(t_long *data);
void	print_player(t_long *data);
void	print_exitclose(t_long *data);

//texture2
void	print_exitopen(t_long *data);
void	replace_texture(t_long *data);
void	print_playeronexit(t_long *data);
int		mlx_destroy_so_long(t_long *data, bool freeMlx);

//player
int		player_key(int keycode, t_long *data);
int		finish(t_long *data);
void	free_and_exit(char *s, t_long *data, bool freemlx);

#endif