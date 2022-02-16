/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:49:44 by mjodge            #+#    #+#             */
/*   Updated: 2022/02/16 13:06:07 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_format(char *file, char *format)
{
	int	len;
	int	index;
	int	i;

	len = ft_strlen(file);
	index = len - ft_strlen(format);
	i = 0;
	while (format[i])
	{
		if (file[index++] != format[i])
			return (0);
		i++;
	}
	return (1);
}

int	check_map_simb(char **map)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			if (map[y][x] != '1' && map[y][x] != '0' && map[y][x] \
			!= 'E' && map[y][x] != 'C' && map[y][x] != 'P' && map[y][x] != 'B')
				return (0);
	}
	return (1);
}

int	check_map_string(char **map)
{
	int		y;
	size_t	len;

	y = -1;
	len = ft_strlen(map[0]);
	while (map[++y])
		if (ft_strlen(map[y]) != len)
			return (0);
	return (1);
}

int	check_map_wall(char **map)
{
	int	x;
	int	y;
	int	p;

	y = 0;
	p = 0;
	x = -1;
	while (map[0][++x])
		if (map[y][x] != '1')
			return (0);
	y = -1;
	while (map[++y])
		if (map[y][ft_strlen(map[y]) - 1] != '1' || map[y][0] != '1')
			return (0);
	x = -1;
	while (map[y - 1][++x])
		if (map[y - 1][x] != '1')
			return (0);
	return (1);
}

int	check_map_p_ex_en_c(char **map, char c)
{
	int	x;
	int	y;
	int	p;

	y = -1;
	p = 0;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			if (map[y][x] == c)
				p++;
	}
	if (c == 'C' || c == 'E' || c == 'B')
		return (p != 0);
	return (p == 1);
}
