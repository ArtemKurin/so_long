/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:50:03 by mjodge            #+#    #+#             */
/*   Updated: 2021/12/04 21:29:21 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *str)
{
	if (str)
		free(str);
	ft_putstr_fd("Error.\n", 1);
	exit(1);
}

int	ft_exit(char *str)
{
	if (!str)
		exit(1);
	return (1);
}

void	ft_free(char **res)
{
	int	i;

	i = -1;
	while (res[++i])
		free(res[i]);
	free(res);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		error(NULL);
	if (!check_map_format(argv[argc - 1], ".ber"))
		error(NULL);
	vars.map = get_map(argv[argc - 1]);
	if (!check_all(vars.map))
		error(NULL);
	get_size(&vars, vars.map);
	vars.count = 0;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.width, vars.height, "so_long");
	distribution(&vars);
	map_render(&vars, vars.map);
	mlx_hook(vars.win, 17, 0, ft_exit, NULL);
	mlx_hook(vars.win, 2, 1L << 0, move, &vars);
	mlx_loop_hook(vars.mlx, render_enemy, &vars);
	mlx_loop(vars.mlx);
}
