/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:50:08 by mjodge            #+#    #+#             */
/*   Updated: 2021/12/04 21:29:22 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_read(char *file)
{
	int		fd;
	char	tmp[BUFFER_SIZE + 1];
	char	*curr;
	int		ret;

	fd = open(file, O_RDONLY);
	ret = 1;
	while (ret)
	{
		ret = read(fd, tmp, BUFFER_SIZE);
		if (ret < 0)
			error(curr);
		tmp[ret] = '\0';
		curr = ft_strjoin(curr, tmp);
		if (!curr)
			error(NULL);
	}
	return (curr);
}

char	**get_map(char *file)
{
	char	*line;
	char	**map;

	line = ft_read(file);
	map = ft_split(line, '\n');
	if (!map)
		error(line);
	if (line)
		free(line);
	return (map);
}
