/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofaisal <mofaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:07:28 by mofaisal          #+#    #+#             */
/*   Updated: 2023/04/24 19:32:59 by mofaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx(t_solong *map)
{
	t_var		v;

	v.len = 64;
	map->mlx = mlx_init();
	map_area(map);
	map->window = mlx_new_window(map->mlx, map->y * 64, map->x * 64, "so_long");
	map->player = mlx_xpm_file_to_image(map->mlx, "play.xpm", &v.len, &v.len);
	map->collect = mlx_xpm_file_to_image(map->mlx, "col.xpm", &v.len, &v.len);
	map->exit = mlx_xpm_file_to_image(map->mlx, "finish.xpm", &v.len, &v.len);
	map->wall = mlx_xpm_file_to_image(map->mlx, "def.xpm", &v.len, &v.len);
	map->floor = mlx_xpm_file_to_image(map->mlx, "floor.xpm", &v.len, &v.len);
	if (map->collect == NULL || map->exit == NULL
		|| map->floor == NULL || map->player == NULL || map->wall == NULL)
	{
		ft_putendl_fd("Error", 2);
		return ;
	}
	map_draw(map);
	mlx_hook(map->window, ARROWS, 0, moves, map);
	mlx_hook(map->window, ESC_KEY, 0, exit_game, map);
	mlx_loop(map->mlx);
}

void	free_strings(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	check_invalid_path(t_solong *tmp_map, int i, int j)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	invalid(tmp_map, i, j);
	while (tmp_map->dup_map[y] != NULL)
	{
		x = 0;
		while (tmp_map->dup_map[y][x])
		{
			if (tmp_map->dup_map[y][x] == 'E')
				return (ft_putendl_fd("Error: Couldn't reach Exit", 2), 0);
			if (tmp_map->dup_map[y][x] == 'C')
				return (ft_putendl_fd("Error: Couldn't reach Coin", 2), 0);
			x++;
		}
		y++;
	}
	return (1);
}
