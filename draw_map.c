/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:49:51 by mjodge            #+#    #+#             */
/*   Updated: 2021/12/04 21:37:25 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_render_helper(t_vars *vars, char c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(vars->mlx, \
		vars->win, vars->wall.img, x * 32, y * 32);
	if (c == '0' || c == 'E' || c == 'P' || c == 'C' || c == 'B')
		mlx_put_image_to_window(vars->mlx, \
		vars->win, vars->floor.img, x * 32, y * 32);
	if (c == 'E')
		mlx_put_image_to_window(vars->mlx, \
		vars->win, vars->exit.img, x * 32, y * 32);
	if (c == 'P')
		mlx_put_image_to_window(vars->mlx, \
		vars->win, vars->santa.img, x * 32, y * 32);
	if (c == 'C')
		mlx_put_image_to_window(vars->mlx, \
		vars->win, vars->coin.img, x * 32, y * 32);
	if (c == 'B')
		mlx_put_image_to_window(vars->mlx, \
		vars->win, vars->enemy.img, x * 32, y * 32);
}

void	map_render(t_vars *vars, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y] && !vars->flag_win && !vars->flag_loose)
	{
		x = 0;
		while (map[y][x])
		{
			map_render_helper(vars, map[y][x], x, y);
			x++;
		}
		y++;
	}
}

void	draw_win(t_vars *vars)
{
	char	*steps;

	steps = ft_itoa(vars->count);
	mlx_string_put(vars->mlx, vars->win, \
	vars->width / 2 - 32, vars->height / 2 - 32, 0x0066FF33, "you win");
	mlx_string_put(vars->mlx, vars->win, 0, 0, 0x0066FF33, steps);
	if (!vars->print)
	{
		ft_putnbr_fd(vars->count, 1);
		ft_putchar_fd('\n', 1);
		vars->print = 1;
	}
	free(steps);
}

int	move(int key, t_vars *vars)
{
	if (!vars->flag_loose && !vars->flag_win)
	{
		if (key == 2)
			move_d(vars);
		if (key == 0)
			move_a(vars);
		if (key == 13)
			move_w(vars);
		if (key == 1)
			move_s(vars);
	}
	else if ((vars->flag_win || vars->flag_loose) && key == 36)
	{
		vars->flag_win = 0;
		vars->flag_loose = 0;
		ft_free(vars->map);
	}
	if (vars->flag_win)
		draw_win(vars);
	if (key == 53)
		ft_free(vars->map);
	return (1);
}
