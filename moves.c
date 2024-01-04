/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofaisal <mofaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:22:49 by mofaisal          #+#    #+#             */
/*   Updated: 2023/04/24 17:54:08 by mofaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_up(t_solong *vars, t_var *v)
{
	while (vars->map[v->i] != NULL)
	{
		v->j = 0;
		while (vars->map[v->i][v->j])
		{
			if (check_collectibles(vars) == 1 && check_exit_up(vars) == 1
				&& vars->map[v->i][v->j] == 'E')
				exit_game(vars);
			if (vars->map[v->i][v->j] == 'P' && vars->map[v->i - 1][v->j] != '1'
				&& vars->map[v->i - 1][v->j] != 'E')
			{
				ft_printf("Moves Count :: %d\n", vars->move_count++);
				vars->map[v->i][v->j] = '0';
				vars->map[v->i - 1][v->j] = 'P';
				mlx_clear_window(vars->mlx, vars->window);
				map_draw(vars);
				return ;
			}
			v->j++;
		}
		v->i++;
	}
}

static void	move_down(t_solong *vars, t_var *v)
{
	while (vars->map[v->i] != NULL)
	{
		v->j = 0;
		while (vars->map[v->i][v->j])
		{
			if (check_collectibles(vars) == 1 && check_exit_d(vars) == 1
				&& vars->map[v->i][v->j] == 'E')
				exit_game(vars);
			if (vars->map[v->i][v->j] == 'P' && vars->map[v->i + 1][v->j] != '1'
				&& vars->map[v->i + 1][v->j] != 'E')
			{
				ft_printf("Moves Count :: %d\n", vars->move_count++);
				vars->map[v->i][v->j] = '0';
				vars->map[v->i + 1][v->j] = 'P';
				mlx_clear_window(vars->mlx, vars->window);
				map_draw(vars);
				return ;
			}
			v->j++;
		}
		v->i++;
	}
}

static void	move_left(t_solong *vars, t_var *v)
{
	while (vars->map[v->i] != NULL)
	{
		v->j = 0;
		while (vars->map[v->i][v->j])
		{			
			if (check_collectibles(vars) == 1 && check_exit_l(vars) == 1
				&& vars->map[v->i][v->j] == 'E')
				exit_game(vars);
			if (vars->map[v->i][v->j] == 'P' && vars->map[v->i][v->j - 1] != '1'
				&& vars->map[v->i][v->j - 1] != 'E')
			{
				vars->map[v->i][v->j] = '0';
				vars->map[v->i][v->j - 1] = 'P';
				mlx_clear_window(vars->mlx, vars->window);
				map_draw(vars);
				ft_printf("Moves Count :: %d\n", vars->move_count++);
				return ;
			}
			v->j++;
		}
		v->i++;
	}
}

static void	move_right(t_solong *vars, t_var *v)
{
	while (vars->map[v->i] != NULL)
	{
		v->j = 0;
		while (vars->map[v->i][v->j])
		{
			if (check_collectibles(vars) == 1 && check_exit_r(vars) == 1
				&& vars->map[v->i][v->j] == 'E')
				exit_game(vars);
			if (vars->map[v->i][v->j] == 'P' && vars->map[v->i][v->j + 1] != '1'
				&& vars->map[v->i][v->j + 1] != 'E')
			{
				vars->map[v->i][v->j] = '0';
				vars->map[v->i][v->j + 1] = 'P';
				mlx_clear_window(vars->mlx, vars->window);
				map_draw(vars);
				ft_printf("Moves Count :: %d\n", vars->move_count++);
				return ;
			}
			v->j++;
		}
		v->i++;
	}
}

int	moves(int key, t_solong *vars)
{
	t_var	v;

	v.i = 0;
	v.j = 0;
	if (key == 13 || key == 126)
		return (move_up(vars, &v), 0);
	else if (key == 1 || key == 125)
		return (move_down(vars, &v), 0);
	else if (key == 0 || key == 123)
		return (move_left(vars, &v), 0);
	else if (key == 2 || key == 124)
		return (move_right(vars, &v), 0);
	else if (key == 53)
		return (exit_game(vars), 0);
	return (0);
}
