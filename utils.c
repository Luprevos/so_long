/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luprevos <luprevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:10:43 by luprevos          #+#    #+#             */
/*   Updated: 2025/03/24 17:31:56 by luprevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_strcmp(char *s1, char *s2)
{
	while(*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return(*s1 - *s2);
}

int		count_lines(int fd, t_long *data) //need to fix for last line 
{
	int		lines;
	char	*str = get_next_line(fd);
	int c;
	
	c = 0;
	lines = 0;
	while (str != NULL)
	{
		if (c == 0)
		{
			data->line_len = ft_strlen(str);
			//printf(" zizi :%d\n", data->line_len);
			c++;
		}
		//printf("%d\n", ft_strlen(str));
		if (ft_strlen(str) != data->line_len)
		{
			printf("ERROR : tailles lignes");
			return(0);
		}
		lines++;
		free(str);
		str = get_next_line(fd);	
	}
	data->line_number = lines;
	return(1);
}

int	ft_strlenn(char *str)
{
	int		len;

	len = 0;
	while (str[len] != '\n')
		len++;
	return (len);
}

char *ft_strdupmap(char *s2, t_long *data)
{
	char *s1;
	int i = 0;
	s1 = malloc(sizeof(char) * (data->line_len + 1));
	if (!s1)
		return (NULL);
	while(s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return(s1);	
}

void ft_mapcopy(t_long *data, char **argv, int fd)
{
	int i;
	char *str;

	i = 0;
	data->map = malloc(sizeof(char*) * (data->line_number + 1));
	if (!data->map)
		printf("ERROR : imp de malloc la map");
	fd = open(argv[1], O_RDONLY);
	while (i != data->line_number)
	{
		str = get_next_line(fd);
		data->map[i] = ft_strdupmap(str, data);
		//printf("%s", data->map[i]);
		i++;
	}
	
}