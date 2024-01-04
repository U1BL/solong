/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofaisal <mofaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 20:28:03 by mofaisal          #+#    #+#             */
/*   Updated: 2023/04/24 18:42:01 by mofaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_collectibles(t_solong *vars)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (vars->map[i] != NULL)
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	if (count == 0)
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_solong	map;

	map.move_count = 1;
	if ((parse_check(argc, argv, &map)) != 0)
	{
		mlx(&map);
		free_strings(map.dup_map);
		free_strings(map.map);
	}
	return (0);
}

static void	m_d(t_solong *coordinate, int i, int j, int len)
{
	if (coordinate->map[i][j] == 'P')
	{
		check_valid_path(coordinate);
		mlx_put_image_to_window(coordinate->mlx, coordinate->window,
			coordinate->floor, j * len, i * len);
		mlx_put_image_to_window(coordinate->mlx, coordinate->window,
			coordinate->player, j * len, i * len);
	}
	if (coordinate->map[i][j] == 'E')
	{
		check_valid_path(coordinate);
		mlx_put_image_to_window(coordinate->mlx,
			coordinate->window, coordinate->floor, j * len, i * len);
		mlx_put_image_to_window(coordinate->mlx,
			coordinate->window, coordinate->exit, j * len, i * len);
	}
	if (coordinate->map[i][j] == 'C')
	{
		check_valid_path(coordinate);
		mlx_put_image_to_window(coordinate->mlx,
			coordinate->window, coordinate->floor, j * len, i * len);
		mlx_put_image_to_window(coordinate->mlx, coordinate->window,
			coordinate->collect, j * len, i * len);
	}
}

void	map_draw(t_solong *coord)
{
	t_var	v;

	v.i = 0;
	v.j = 0;
	v.len = 64;
	while (coord->map[v.i] != NULL)
	{
		v.j = 0;
		while (coord->map[v.i][v.j])
		{
			m_d(coord, v.i, v.j, v.len);
			if (coord->map[v.i][v.j] == '1')
			{
				mlx_put_image_to_window(coord->mlx,
					coord->window, coord->floor, v.j * v.len, v.i * v.len);
				mlx_put_image_to_window(coord->mlx,
					coord->window, coord->wall, v.j * v.len, v.i * v.len);
			}
			if (coord->map[v.i][v.j] == '0')
				mlx_put_image_to_window(coord->mlx, coord->window,
					coord->floor, v.j * v.len, v.i * v.len);
			v.j++;
		}
		v.i++;
	}
}

void	map_area(t_solong *coordinate)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	coordinate->exit_count = 0;
	coordinate->collectibles = 0;
	while (coordinate->map[i] != NULL)
	{
		j = 0;
		while (coordinate->map[i][j])
		{
			if (coordinate->map[i][j] == 'C')
				coordinate->collectibles++;
			else if (coordinate->map[i][j] == 'E')
				coordinate->exit_count++;
			j++;
		}
		i++;
	}
	coordinate->x = i;
	coordinate->y = j;
}
