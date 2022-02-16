/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:49:48 by mjodge            #+#    #+#             */
/*   Updated: 2021/12/04 20:49:49 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_coins(t_vars *vars, int pos_y, int pos_x)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x] && vars->map[y][x] != 'C')
			x++;
		if (vars->map[y][x])
			return (1);
		y++;
	}
	if (vars->map[pos_y][pos_x] == 'E')
	{
		vars->flag_win = 1;
		++vars->count;
		mlx_clear_window(vars->mlx, vars->win);
		return (0);
	}
	return (1);
}

int	check_all(char **map)
{
	if (!check_map_simb(map) || !check_map_string(map) || !check_map_wall(map) \
	|| !check_map_p_ex_en_c(map, 'P') || !check_map_p_ex_en_c(map, 'E') \
	|| !check_map_p_ex_en_c(map, 'B') || !check_map_p_ex_en_c(map, 'C'))
		return (0);
	return (1);
}

int	check_no_coins(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x] && vars->map[y][x] != 'C')
			x++;
		if (vars->map[y][x])
			return (0);
		y++;
	}
	return (1);
}
