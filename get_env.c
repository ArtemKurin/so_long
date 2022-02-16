/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:49:58 by mjodge            #+#    #+#             */
/*   Updated: 2021/12/04 21:35:11 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	distribution(t_vars *vars)
{
	vars->santa.relative_path = "./sprites/santa_d.xpm";
	vars->wall.relative_path = "./sprites/wall.xpm";
	vars->coin.relative_path = "./sprites/coin.xpm";
	vars->exit.relative_path = "./sprites/door.xpm";
	vars->floor.relative_path = "./sprites/floor.xpm";
	vars->enemy.relative_path = "./sprites/enemy_r1.xpm";
	vars->flag_open = 0;
	vars->flag_loose = 0;
	vars->flag_win = 0;
	vars->print = 0;
	vars->enemy.img = mlx_xpm_file_to_image(vars->mlx, \
	vars->enemy.relative_path, &vars->enemy.width, &vars->enemy.height);
	vars->santa.img = mlx_xpm_file_to_image(vars->mlx, \
	vars->santa.relative_path, &vars->santa.width, &vars->santa.height);
	vars->wall.img = mlx_xpm_file_to_image(vars->mlx, \
	vars->wall.relative_path, &vars->wall.width, &vars->wall.height);
	vars->coin.img = mlx_xpm_file_to_image(vars->mlx, \
	vars->coin.relative_path, &vars->coin.width, &vars->coin.height);
	vars->exit.img = mlx_xpm_file_to_image(vars->mlx, \
	vars->exit.relative_path, &vars->exit.width, &vars->exit.height);
	vars->floor.img = mlx_xpm_file_to_image(vars->mlx, \
	vars->floor.relative_path, &vars->floor.width, &vars->floor.height);
}

void	get_size(t_vars *vars, char **map)
{
	int	width;
	int	height;

	height = 0;
	width = 0;
	while (map[height][width])
		width++;
	while (map[height])
		height++;
	vars->width = width * 32;
	vars->height = height * 32;
}

void	get_pos(t_vars *vars, char c)
{
	int	x;
	int	y;

	y = 0;
	while ((vars->map)[y])
	{
		x = 0;
		while (vars->map[y][x] && vars->map[y][x] != c)
			x++;
		if (vars->map[y][x])
			break ;
		y++;
	}
	vars->curr_px = x;
	vars->curr_py = y;
}
