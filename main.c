/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luprevos <luprevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:23:52 by luprevos          #+#    #+#             */
/*   Updated: 2025/03/26 11:44:13 by luprevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	mlx_init();
	if (argc != 2)
	{
		printf("ERROR : nombre d'arg invalide\n");
		return(0);	
	}
	else
	{
		if(check_ber(argv[1]) == 0)
			return(0);
	}

	int		fd;
	t_long *data = malloc(sizeof(t_long));
	data->C = 0;
	fd = open(argv[1], O_RDONLY);
	 if (count_lines(fd, data) != 1)
	 	return(0);
	close(fd);
	ft_mapcopy(data, argv, fd);
	if (perfect_parsing(data) == 0)
		return(0);
	//fd = open(argv[1], O_RDONLY);
	// while (i < data->line_number)
	// {
	//  	line = get_next_line(fd);
	//  	printf("%s", line);
	//  	free(line);
	//  	i++;
	// }
	close(fd);
	return(0);
}
