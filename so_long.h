/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:49:35 by mjodge            #+#    #+#             */
/*   Updated: 2021/12/04 21:34:41 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx_opengl/mlx.h"
# include <fcntl.h>
# include "./libft/libft.h"
# include <stdio.h>

typedef struct s_img {
	void	*img;
	int		x;
	int		y;
	char	*relative_path;
	int		width;
	int		height;
}	t_img;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_img	santa;
	t_img	wall;
	t_img	coin;
	t_img	exit;
	t_img	floor;
	t_img	enemy;
	int		width;
	int		height;
	char	**map;
	int		count;
	int		flag_open;
	int		flag_loose;
	int		flag_win;
	int		px;
	int		py;
	int		curr_px;
	int		curr_py;
	int		print;
}				t_vars;

void	ft_free(char **res);
void	get_pos(t_vars *vars, char c);
void	set_pos(t_vars *vars, char c, int nx, int ny);
int		render_enemy(t_vars *vars);
void	set_pos(t_vars *vars, char c, int nx, int ny);
void	move_w(t_vars *vars);
void	move_s(t_vars *vars);
void	move_d(t_vars *vars);
void	move_a(t_vars *vars);
void	map_render_helper(t_vars *vars, char c, int x, int y);
void	map_render(t_vars *vars, char **map);
int		move(int key, t_vars *vars);
void	distribution(t_vars *vars);
void	get_size(t_vars *vars, char **map);
void	get_pos(t_vars *vars, char c);
char	*ft_read(char *file);
char	**get_map(char *file);
int		check_map_format(char *file, char *format);
int		check_map_simb(char **map);
int		check_map_string(char **map);
int		check_map_wall(char **map);
int		check_map_p_ex_en_c(char **map, char c);
int		check_coins(t_vars *vars, int pos_y, int pos_x);
int		check_all(char **map);
void	error(char *str);
int		ft_exit(char *str);
int		check_no_coins(t_vars *vars);

#endif