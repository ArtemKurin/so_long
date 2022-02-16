/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:50:01 by mjodge            #+#    #+#             */
/*   Updated: 2021/12/04 21:29:20 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_pos(t_vars *vars, char c, int nx, int ny)
{
	char		*steps;

	get_pos(vars, c);
	if (vars->map[ny][nx] != '1' && vars->map[ny][nx] != 'E')
	{
		if (vars->map[ny][nx] == 'B')
		{
			vars->flag_loose = 1;
			++vars->count;
			mlx_clear_window(vars->mlx, vars->win);
			return ;
		}
		vars->map[vars->curr_py][vars->curr_px] = '0';
		vars->map[ny][nx] = c;
		++vars->count;
	}
	if (check_coins(vars, ny, nx))
	{
		steps = ft_itoa(vars->count);
		map_render(vars, vars->map);
		mlx_string_put(vars->mlx, vars->win, 0, 0, 0x0066FF33, steps);
		ft_putnbr_fd(vars->count, 1);
		ft_putchar_fd('\n', 1);
		free(steps);
	}
}

void	move_w(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	vars->santa.relative_path = "./sprites/santa_w.xpm";
	vars->santa.img = mlx_xpm_file_to_image(vars->mlx, \
	vars->santa.relative_path, &vars->santa.width, &vars->santa.height);
	get_pos(vars, 'P');
	set_pos(vars, 'P', vars->curr_px, vars->curr_py - 1);
}

void	move_s(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	vars->santa.relative_path = "./sprites/santa_s.xpm";
	vars->santa.img = mlx_xpm_file_to_image(vars->mlx, \
	vars->santa.relative_path, &vars->santa.width, &vars->santa.height);
	get_pos(vars, 'P');
	set_pos(vars, 'P', vars->curr_px, vars->curr_py + 1);
}

void	move_d(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	vars->santa.relative_path = "./sprites/santa_d.xpm";
	vars->santa.img = mlx_xpm_file_to_image(vars->mlx, \
	vars->santa.relative_path, &vars->santa.width, &vars->santa.height);
	get_pos(vars, 'P');
	set_pos(vars, 'P', vars->curr_px + 1, vars->curr_py);
}

void	move_a(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	vars->santa.relative_path = "./sprites/santa_a.xpm";
	vars->santa.img = mlx_xpm_file_to_image(vars->mlx, \
	vars->santa.relative_path, &vars->santa.width, &vars->santa.height);
	get_pos(vars, 'P');
	set_pos(vars, 'P', vars->curr_px - 1, vars->curr_py);
}
