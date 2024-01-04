/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofaisal <mofaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:41:13 by mofaisal          #+#    #+#             */
/*   Updated: 2023/04/18 21:09:26 by mofaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	array_initialize(t_solong *array, int j, char *argv)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(argv, O_RDONLY);
	array->map = malloc(sizeof(char *) * (j + 1));
	array->dup_map = malloc(sizeof(char *) * (j + 1));
	line = get_next_line(fd);
	while (line)
	{
		array->map[i] = ft_strtrim(line, "\n");
		array->dup_map[i] = ft_strdup(array->map[i]);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	array->map[i] = NULL;
	array->dup_map[i] = NULL;
}

int	map_len(t_solong *sl, int fd, char *argv)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	if (line)
		free(line);
	close(fd);
	array_initialize(sl, i, argv);
	return (i);
}

static int	abdulsamad(t_solong *vars, t_var *v)
{
	if (vars->map[v->i][v->j] == 'P' && vars->map[v->i + 1][v->j] == '1'
		&& vars->map[v->i - 1][v->j] == '1'
			&& vars->map[v->i][v->j + 1] == '1'
			&& vars->map[v->i][v->j - 1] == '1')
		return (1);
	else if (vars->map[v->i][v->j] == 'E' && vars->map[v->i + 1][v->j] == '1'
			&& vars->map[v->i - 1][v->j] == '1'
			&& vars->map[v->i][v->j + 1] == '1'
			&& vars->map[v->i][v->j - 1] == '1')
		return (1);
	else if (vars->map[v->i][v->j] == 'C' && vars->map[v->i + 1][v->j] == '1'
			&& vars->map[v->i - 1][v->j] == '1'
			&& vars->map[v->i][v->j + 1] == '1'
			&& vars->map[v->i][v->j - 1] == '1')
		return (1);
	return (0);
}

int	check_valid_path(t_solong *vars)
{
	t_var	v;

	v.i = 0;
	v.j = 0;
	while (vars->map[v.i] != NULL)
	{
		v.j = 0;
		while (vars->map[v.i][v.j])
		{
			if (abdulsamad(vars, &v))
				return (exit_game(vars), 1);
			v.j++;
		}
		v.i++;
	}
	return (0);
}

void	invalid(t_solong *tmp, int i, int j)
{
	if (tmp->dup_map[i][j] == 'X' || tmp->dup_map[i][j] == '1')
		return ;
	if (tmp->dup_map[i][j] == 'E')
	{
		tmp->dup_map[i][j] = 'X';
		return ;
	}
	tmp->dup_map[i][j] = 'X';
	invalid(tmp, i, j + 1);
	invalid(tmp, i, j - 1);
	invalid(tmp, i + 1, j);
	invalid(tmp, i - 1, j);
}
