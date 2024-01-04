/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofaisal <mofaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:12:16 by mofaisal          #+#    #+#             */
/*   Updated: 2023/04/24 18:49:03 by mofaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_file(char *file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	if (file[i - 1] == 'r' && file[i - 2] == 'e' && file[i - 3] == 'b'
		&& file[i - 4] == '.' && file[i] == '\0')
		return (1);
	return (0);
}

static int	check_map_helper(t_solong *map_line, int map_len, t_var *v)
{
	while (map_line->map[v->i] != NULL)
	{
		if (ft_strlen(map_line->map[v->i]) != ft_strlen(map_line->map[0]))
			return (ft_putendl_fd("Error: Map is not a rectangle", 2), 0);
		else if (map_line->map[v->i][0] != '1'
			|| map_line->map[v->i][ft_strlen(map_line->map[v->i]) - 1] != '1')
			return (ft_putendl_fd("Error: not surrounded by walls", 2), 0);
		else if (v->i == 0 || v->i == map_len - 1)
		{
			v->j = 0;
			while (map_line->map[v->i][v->j])
			{
				if (map_line->map[v->i][v->j] != '1')
					return (ft_putendl_fd("Error", 2), 0);
				v->j++;
			}
		}
		v->i++;
	}
	return (1);
}

static int	check_map_helper2(t_solong *map_line, t_var *v)
{
	while (map_line->map[v->i] != NULL)
	{
		v->j = 0;
		while (map_line->map[v->i][v->j])
		{
			if (map_line->map[v->i][v->j] == 'P')
			{
				map_line->py = v->i;
				map_line->px = v->j;
				v->p++;
			}
			else if (map_line->map[v->i][v->j] == 'E')
				v->e++;
			else if (map_line->map[v->i][v->j] == 'C')
				v->c++;
			else if (map_line->map[v->i][v->j] != '1'
				&& map_line->map[v->i][v->j] != '0')
				return (ft_putendl_fd("Error: invalid characters", 2), 0);
			v->j++;
		}
		v->i++;
	}
	return (1);
}

int	check_map(t_solong *map_line, int map_len)
{
	t_var	v;

	v.i = 0;
	if (!check_map_helper(map_line, map_len, &v))
		return (0);
	v.i = 0;
	v.p = 0;
	v.e = 0;
	v.c = 0;
	if (!check_map_helper2(map_line, &v))
		return (0);
	if (v.p != 1 || v.e != 1 || v.c == 0)
		return (ft_putendl_fd("Error", 2), 0);
	return (1);
}

int	parse_check(int argc, char *argv[], t_solong *map)
{
	t_var		v;
	int			fd;

	v.i = 0;
	if (argc < 2)
		return (ft_putendl_fd("Error: Few Arguments Entered", 2), 0);
	else if (argc > 2)
		return (ft_putendl_fd("Error: Too Many Arguments Entered", 2), 0);
	if (!check_file(argv[1]))
		return (ft_putendl_fd("Error: Wrong File Name", 2), 0);
	fd = open (argv[1], O_RDONLY);
	if ((fd <= -1))
		return (ft_putendl_fd("Error: While Opening The File", 2), 0);
	if (!check_map(map, map_len(map, fd, argv[1])))
		return (free_strings(map->dup_map), free_strings(map->map), 0);
	if (!check_invalid_path(map, map->py, map->px))
	{
		free_strings(map->dup_map);
		free_strings(map->map);
		return (0);
	}	
	return (1);
}
