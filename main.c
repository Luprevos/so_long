/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luprevos <luprevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:23:52 by luprevos          #+#    #+#             */
/*   Updated: 2025/04/01 17:31:27 by luprevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_long	*data;

	if (argc != 2)
		return (printf("ERROR : nombre d'arg invalide\n"));
	if (check_ber(argv[1]) == 0)
		return (1);
	data = malloc(sizeof(t_long));
	bzero(data, sizeof(t_long));
	fd = open(argv[1], O_RDONLY);
	if (count_lines(fd, data))
		return (mlx_destroy_so_long(data, false));
	close(fd);
	ft_mapcopy(data, argv, fd);
	if (perfect_parsing(data) == 0)
	{
		mlx_destroy_so_long(data, false);
		return (0);
	}
	new_window_mlx(data);
	mlx_loop(data->mlx);
	mlx_destroy_so_long(data, true);
	return (0);
}
