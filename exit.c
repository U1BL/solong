/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofaisal <mofaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:58:43 by mofaisal          #+#    #+#             */
/*   Updated: 2023/04/24 17:58:22 by mofaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(t_solong *vars)
{
	mlx_destroy_window(vars->mlx, vars->window);
	exit(0);
	return (0);
}

int	check_exit_r(t_solong *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (vars->map[i] != NULL)
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == 'P' && vars->map[i][j + 1] == 'E')
				return (exit_game(vars), 1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_exit_l(t_solong *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (vars->map[i] != NULL)
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == 'P' && vars->map[i][j - 1] == 'E')
				return (exit_game(vars), 1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_exit_up(t_solong *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (vars->map[i] != NULL)
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == 'P' && vars->map[i - 1][j] == 'E')
				return (exit_game(vars), 1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_exit_d(t_solong *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (vars->map[i] != NULL)
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == 'P' && vars->map[i + 1][j] == 'E')
				return (exit_game(vars), 1);
			j++;
		}
		i++;
	}
	return (0);
}
