/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:49:54 by mjodge            #+#    #+#             */
/*   Updated: 2021/12/04 21:38:55 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_enemy1(t_vars *vars, char *sprite, int sign)
{
	get_pos(vars, 'B');
	vars->enemy.relative_path = sprite;
	vars->enemy.img = mlx_xpm_file_to_image(vars->mlx, \
	vars->enemy.relative_path, &vars->enemy.width, &vars->enemy.height);
	if (vars->map[vars->curr_py][vars->curr_px + sign] != '1' \
	&& vars->map[vars->curr_py][vars->curr_px + sign] != 'E')
	{
		if (vars->map[vars->curr_py][vars->curr_px + sign] == 'P')
			vars->flag_loose = 1;
		else
			vars->map[vars->curr_py][vars->curr_px] = '0';
		vars->map[vars->curr_py][vars->curr_px + sign] = 'B';
	}
}

void	draw_door1(t_vars *vars, char *sprite)
{
	char		*steps;

	steps = ft_itoa(vars->count);
	vars->exit.relative_path = sprite;
	vars->exit.img = mlx_xpm_file_to_image(vars->mlx, \
	vars->exit.relative_path, &vars->exit.width, &vars->exit.height);
	map_render(vars, vars->map);
	mlx_string_put(vars->mlx, vars->win, 0, 0, 0x0066FF33, steps);
	free(steps);
}

void	draw_door(t_vars *vars)
{
	static int	c = 0;

	if (c == 0)
		draw_door1(vars, "./sprites/door_1.xpm");
	if (c == 20)
		draw_door1(vars, "./sprites/door_2.xpm");
	if (c == 40)
		draw_door1(vars, "./sprites/door_3.xpm");
	if (c == 60)
	{
		draw_door1(vars, "./sprites/door_4.xpm");
		vars->flag_open = 1;
	}
	c++;
}

void	draw_enemy(t_vars *vars)
{
	static int	acc = -60;
	char		*steps;

	steps = ft_itoa(vars->count);
	if (acc == -90)
		draw_enemy1(vars, "./sprites/enemy_r1.xpm", 1);
	if (acc == -60)
		draw_enemy1(vars, "./sprites/enemy_r2.xpm", 1);
	if (acc == -30)
		draw_enemy1(vars, "./sprites/enemy_r3.xpm", 1);
	if (acc == 0)
		draw_enemy1(vars, "./sprites/enemy_l1.xpm", -1);
	if (acc == 30)
		draw_enemy1(vars, "./sprites/enemy_l2.xpm", -1);
	if (acc == 60)
		draw_enemy1(vars, "./sprites/enemy_l3.xpm", -1);
	acc++;
	if (acc > 90)
		acc = -90;
	map_render(vars, vars->map);
	mlx_string_put(vars->mlx, vars->win, 0, 0, 0x0066FF33, steps);
	free(steps);
}

int	render_enemy(t_vars *vars)
{
	char		*steps;

	if (!vars->flag_loose)
	{
		draw_enemy(vars);
		if (!vars->flag_open && !vars->flag_loose && check_no_coins(vars))
			draw_door(vars);
	}
	else
	{
		steps = ft_itoa(vars->count);
		mlx_clear_window(vars->mlx, vars->win);
		mlx_string_put(vars->mlx, vars->win, \
		vars->width / 2 - 32, vars->height / 2 - 32, 0x0066FF33, "you loose");
		mlx_string_put(vars->mlx, vars->win, 0, 0, 0x0066FF33, steps);
		if (!vars->print)
		{
			ft_putnbr_fd(vars->count, 1);
			ft_putchar_fd('\n', 1);
			vars->print = 1;
		}
		free(steps);
	}
	return (1);
}
